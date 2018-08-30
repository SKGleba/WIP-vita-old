TARGET   = PSVSAFE
OBJS     = main.o

LIBS = -lvita2d -lSceDisplay_stub -lSceNet_stub -lSceLibKernel_stub -lSceGxm_stub -lSceIofilemgr_stub \
	-lSceSysmodule_stub -lSceCtrl_stub -lScePgf_stub -lScePvf_stub\
	-lSceCommonDialog_stub -lScePower_stub -lSceVshBridge_stub -lfreetype -lz -lm -lc \

PREFIX  = arm-vita-eabi
CC      = $(PREFIX)-gcc
CFLAGS  = -Wl,-q -Wall -fno-lto
ASFLAGS = $(CFLAGS)

all: eboot.bin

eboot.bin: $(TARGET).velf
	vita-make-fself -c $< $@

%.velf: %.elf
	vita-elf-create $< $@

$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

clean:
	@rm -rf $(TARGET).vpk $(TARGET).velf $(TARGET).elf $(OBJS) \
		eboot.bin param.sfo
