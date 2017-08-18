MULATOR = ../../../simulator/

.SECONDEXPANSION:

all: $(wildcard *.c) 
	gcc -Wall -O0 -g -std=c99 \
		-DM_PROFILE -DDEBUG1 -DDEBUG2 \
		-I$(MULATOR) \
		$(MULATOR)/cpu/misc.c \
		$(MULATOR)/core/opcodes.c \
		$(MULATOR)/core/isa/decode_helpers.c \
		$(MULATOR)/core/isa/decompile.c \
		$(wildcard $(MULATOR)/core/isa/arm-thumb/*.c) \
		$(wildcard $(MULATOR)/core/operations/*.c) \
		$^

