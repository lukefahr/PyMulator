#include "dnn_parameters.h"
uint32_t PE_INSTS[2][4][6];

void set_dnn_insts() {
PE_INSTS[0][0][0] = 0b01010000000000110101100100000001;
PE_INSTS[0][0][1] = 0b00100000000101011000101000000000;
PE_INSTS[0][0][2] = 0b11000000000000011001011000000010;
PE_INSTS[0][0][3] = 0b00000000000000000010000001000010;
PE_INSTS[0][0][4] = 0b00000001001001001000011000001100;
PE_INSTS[0][0][5] = 0b00000000000000000000001000011000;
PE_INSTS[1][0][0] = 0b01010000000000100101100100101001;
PE_INSTS[1][0][1] = 0b01100000000000001100101100000001;
PE_INSTS[1][0][2] = 0b11000000000000010001011000000000;
PE_INSTS[1][0][3] = 0b00101100110000000101100010010010;
PE_INSTS[1][0][4] = 0b00000000110001001000000000010010;
PE_INSTS[1][0][5] = 0b00000000000000000000000000110000;
}