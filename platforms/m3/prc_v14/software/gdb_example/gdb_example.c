//*******************************************************************
//Author: Gyouho Kim
//Description: Simple code that repeats sleep/wakeup
//			PRCv14, SNSv7, RADv9, PMUv2, HRVv5
//			Derived from 'Tstack_Ondemand_v1.12'
//*******************************************************************
#include "PRCv14.h"
#include "PRCv14_RF.h"
#include "mbus.h"

// uncomment this for debug mbus message
// #define DEBUG_MBUS_MSG
#define DEBUG_MBUS_MSG_1

// TStack order  PRC->RAD->SNS->HRV->PMU
#define HRV_ADDR 0x3
#define RAD_ADDR 0x4
#define SNS_ADDR 0x5
#define PMU_ADDR 0x6


// Temp Sensor parameters
#define	MBUS_DELAY 100 // Amount of delay between successive messages; 100: 6-7ms
#define TEMP_TIMEOUT_COUNT 2000
#define WAKEUP_PERIOD_RESET 2
#define WAKEUP_PERIOD_LDO 2
#define TEMP_CYCLE_INIT 5 

#define TIMERWD_VAL 0xFFFFF // 0xFFFFF about 13 sec with Y2 run default clock

//********************************************************************
// Global Variables
//********************************************************************
// "static" limits the variables to this file, giving compiler more freedom
// "volatile" should only be used for MMIO --> ensures memory storage
volatile uint32_t enumerated;
volatile uint32_t wakeup_data;
volatile uint32_t Tstack_state;
volatile uint32_t temp_timeout_flag;
volatile uint32_t exec_count;
volatile uint32_t meas_count;
volatile uint32_t exec_count_irq;
volatile uint32_t mbus_msg_flag;
volatile uint32_t WAKEUP_PERIOD_CONT; 

volatile prcv14_r0B_t prcv14_r0B = PRCv14_R0B_DEFAULT;

//*******************************************************************
// INTERRUPT HANDLERS
//*******************************************************************
void handler_ext_int_0(void)  __attribute__ ((interrupt ("IRQ")));
void handler_ext_int_1(void)  __attribute__ ((interrupt ("IRQ")));
void handler_ext_int_2(void)  __attribute__ ((interrupt ("IRQ")));
void handler_ext_int_3(void)  __attribute__ ((interrupt ("IRQ")));
void handler_ext_int_4(void)  __attribute__ ((interrupt ("IRQ")));
void handler_ext_int_5(void)  __attribute__ ((interrupt ("IRQ")));
void handler_ext_int_6(void)  __attribute__ ((interrupt ("IRQ")));
void handler_ext_int_7(void)  __attribute__ ((interrupt ("IRQ")));
void handler_ext_int_8(void)  __attribute__ ((interrupt ("IRQ")));
void handler_ext_int_9(void)  __attribute__ ((interrupt ("IRQ")));
void handler_ext_int_10(void) __attribute__ ((interrupt ("IRQ")));
void handler_ext_int_11(void) __attribute__ ((interrupt ("IRQ")));
void handler_ext_int_12(void) __attribute__ ((interrupt ("IRQ")));
void handler_ext_int_13(void) __attribute__ ((interrupt ("IRQ")));
void handler_ext_int_14(void) __attribute__ ((interrupt ("IRQ")));


void handler_ext_int_0(void)  { *NVIC_ICPR = (0x1 << 0);  }// TIMER32
void handler_ext_int_1(void)  { *NVIC_ICPR = (0x1 << 1);  } // TIMER16
void handler_ext_int_2(void)  { *NVIC_ICPR = (0x1 << 2); mbus_msg_flag = 0x10; } // REG0
void handler_ext_int_3(void)  { *NVIC_ICPR = (0x1 << 3); mbus_msg_flag = 0x11; } // REG1
void handler_ext_int_4(void)  { *NVIC_ICPR = (0x1 << 4); mbus_msg_flag = 0x12; } // REG2
void handler_ext_int_5(void)  { *NVIC_ICPR = (0x1 << 5); mbus_msg_flag = 0x13; } // REG3
void handler_ext_int_6(void)  { *NVIC_ICPR = (0x1 << 6); mbus_msg_flag = 0x14; } // REG4
void handler_ext_int_7(void)  { *NVIC_ICPR = (0x1 << 7); mbus_msg_flag = 0x15; } // REG5
void handler_ext_int_8(void)  { *NVIC_ICPR = (0x1 << 8); mbus_msg_flag = 0x16; } // REG6
void handler_ext_int_9(void)  { *NVIC_ICPR = (0x1 << 9); mbus_msg_flag = 0x17; } // REG7
void handler_ext_int_10(void) { *NVIC_ICPR = (0x1 << 10); } // MEM WR
void handler_ext_int_11(void) { *NVIC_ICPR = (0x1 << 11); } // MBUS_RX
void handler_ext_int_12(void) { *NVIC_ICPR = (0x1 << 12); } // MBUS_TX
void handler_ext_int_13(void) { *NVIC_ICPR = (0x1 << 13); } // MBUS_FWD
void handler_ext_int_14(void) { *NVIC_ICPR = (0x1 << 14); } // MBUS_FWD


//***************************************************
// End of Program Sleep Operation
//***************************************************
static void operation_sleep(void){

	// Reset IRQ14VEC
	*((volatile uint32_t *) IRQ14VEC) = 0;

    // Go to Sleep
    mbus_sleep_all();
    while(1);

}

static void operation_sleep_noirqreset(void){

    // Go to Sleep
    mbus_sleep_all();
    while(1);

}

static void operation_init(void){
  
	// Set CPU & Mbus Clock Speeds
    prcv14_r0B.DSLP_CLK_GEN_FAST_MODE = 0x1; // Default 0x0
    prcv14_r0B.CLK_GEN_RING = 0x1; // Default 0x1
    prcv14_r0B.CLK_GEN_DIV_MBC = 0x1; // Default 0x1
    prcv14_r0B.CLK_GEN_DIV_CORE = 0x3; // Default 0x3
	*((volatile uint32_t *) REG_CLKGEN_TUNE ) = prcv14_r0B.as_int;

  
    //Enumerate & Initialize Registers
    enumerated = 0xDEADBEEE;
    exec_count = 0;
    exec_count_irq = 0;
    mbus_msg_flag = 0;

    mbus_enumerate(0x2);
    mbus_enumerate(0x3);

    //Enumeration
	//delay(MBUS_DELAY);
    //mbus_enumerate(RAD_ADDR);
	//delay(MBUS_DELAY);
    //mbus_enumerate(SNS_ADDR);
	//delay(MBUS_DELAY);
    //mbus_enumerate(HRV_ADDR);
	//delay(MBUS_DELAY);
 	//mbus_enumerate(PMU_ADDR);
	//delay(MBUS_DELAY);

    // Initialize other global variables
    WAKEUP_PERIOD_CONT = 2;   // 1: 2-4 sec with PRCv9

    delay(MBUS_DELAY);

    // Go to sleep without timer
    #warning "ANDREW: FIXME"
	set_wakeup_timer(WAKEUP_PERIOD_CONT, 0x1, 0x1);
	//set_wakeup_timer(1, 0x1, 0x1);
    //operation_sleep();
}



//*********************************************************
//
//*********************************************************

extern volatile int32_t gdb_flag = 0;
extern volatile int32_t gdb_sp = 0;
void gdb_break(void) __attribute__ ((noinline));

//  - The Definitive Guide to ARM Cortex-M0 and Cortex-M0+ Processors Section 10.7.1

// SVC handler - main code to handle processing
// Input parameter is stack frame starting address
// obtained from assembly wrapper.
void handler_svcall_main (unsigned int * svc_args)
{
    // Stack frame contains:
    // r0, r1, r2, r3, r12, r14, the return address and xPSR 
    // - Stacked R0 = svc_args[0]
    // - Stacked R1 = svc_args[1]
    // - Stacked R2 = svc_args[2]
    // - Stacked R3 = svc_args[3]
    // - Stacked R12 = svc_args[4]
    // - Stacked LR = svc_args[5]
    // - Stacked PC = svc_args[6]
    // - Stacked xPSR= svc_args[7]
    unsigned int svc_number;
    svc_number = ((char *)svc_args[6])[-2];
    switch(svc_number)
    {
        case 0: gdb_break();
                break;
        //case 1: svc_args[0] = svc_args[0] - svc_args[1];
        //        break;
        //case 2: svc_args[0] = svc_args[0] + 1;
        //        break;
        default: // Unknown SVC request
                break;
    } return;
}


void gdb_break(void)
{
    asm volatile ("nop");
}

//    //mbus_write_message32(0x02<<4,0);
//    //for (uint32_t i = 0xF; i < 0xF; ++i){
//    //    mbus_write_message32(i<<4,0);
//    //}
//    //Disable MBUS interrupts
//	////*((volatile uint32_t *) MBCWD_RESET) = 1;
//
//    //while (gdb_flag == 0) {}
//    //mbus_write_message32(0xBB,0);
//    //gdb_flag = 0;
//    //asm volatile ( 
//    //                " gdb_flag = 0x1F00\n"
//    //                " gdb_sp = 0x1F04\n"
//    //                "\n"
//    //                "push {r0, r1, r2, r3, r4, r5, r6, r7}\n"
//    //                
//    //                "ldr r0, [pc, #16]\n" // CAUTION: pc-relative load
//    //                "ldr r1, [r0, #0]\n" // Load gdb_sp
//    //                "str r13, [r0, #0]\n" // Store current stack pointer to 
//
//    //                "ldr r0, [pc, #16]\n" // CAUTION: pc-relative load
//    //    "svcLoop:    ldr r1, [r0, #0]\n"
//    //                "cmp r1, #0\n"
//    //                "beq svcLoop\n"
//    //                "movs r1, #0\n"
//    //                "str r1, [r0, #0]\n"
//    //                "pop {r0,r1,r2,r3, r4, r5, r6, r7}\n"
//    //                "bx lr\n"
//    //                ".align 4\n"
//    //                ".word gdb_flag\n"
//    //                ".word gdb_sp\n"
//    //             );
//}

//extern volatile void gdb_call () 
//{
//    //save regs
//    asm ( "str r0, %[gdb_r0] " : [gdb_r0] "=m" (gdb_r0) );
//
//    while (gdb_flag == 0) {}
//    gdb_flag = 0;
//
//}


//********************************************************************
// MAIN function starts here             
//********************************************************************

int main() {

    const int emulator = 0;

    // Initialize Interrupts
    // Only enable register-related interrupts
	if (!emulator) enable_reg_irq();
  
    if (!emulator) {
        // Initialization sequence
        if (enumerated != 0xDEADBEEE){
            // Set up PMU/GOC register in PRC layer (every time)
            // Enumeration & RAD/SNS layer register configuration
            operation_init();
        }

        set_halt_until_mbus_tx();
        mbus_write_message32(0xAA,0xABCD1234);
        delay(MBUS_DELAY);
    }
    
    mbus_query_devices();
    for (;;){
        uint32_t count;
        for( count=0; count<1000; count++ ){
            mbus_write_message32(0xaa,count);
            __asm volatile ("svc #0"); //handler_svcall();
            delay(MBUS_DELAY);
            delay(MBUS_DELAY);
        }
        mbus_write_message32(0xfff,count);
    }

	if (!emulator) {
        set_wakeup_timer(WAKEUP_PERIOD_CONT, 0x1, 0x1);
        operation_sleep();
    }

    while(1);

}


