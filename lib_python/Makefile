MULATOR = ../simulator/

.SECONDEXPANSION:

all: $(wildcard *.c) 
	gcc -std=c99 -DM_PROFILE -I$(MULATOR) \
		$$( python2-config --includes ) \
		$(MULATOR)/cpu/misc.c \
		$(MULATOR)/core/opcodes.c \
		$(MULATOR)/core/isa/decode_helpers.c \
		$(MULATOR)/core/isa/decompile.c \
		$(wildcard $(MULATOR)/core/isa/arm-thumb/*.c) \
		$(wildcard $(MULATOR)/core/operations/*.c) \
		$^

