TITLE_ID = SKGPWDCHK
TARGET   = DEV003
OBJS     = main.o TIDUtils.o

LIBS = -lvita2d -lSceDisplay_stub -lSceNet_stub -lSceLibKernel_stub -lSceGxm_stub -lSceIofilemgr_stub \
	-lSceSysmodule_stub -lSceCtrl_stub -lftpvita -lSceAppUtil_stub -lScePgf_stub -lSceRegMgrForDriver_stub -lScePvf_stub -lSceShellSvc_stub \
	-lSceCommonDialog_stub -lSceNetCtl_stub -lScePower_stub -lSceVshBridge_stub -lSceAppMgr_stub -lfreetype -lpng -ljpeg -lz -lm -lc

PREFIX  = arm-vita-eabi
CC      = $(PREFIX)-gcc
CFLAGS  = -Wl,-q -Wall -fno-lto
ASFLAGS = $(CFLAGS)

all: $(TARGET).vpk

%.vpk: eboot.bin
	vita-mksfoex -s TITLE_ID=$(TITLE_ID) "PSVSAFE [beta]" param.sfo
	vita-pack-vpk -s param.sfo -b eboot.bin \
	-a atboot/eboot.bin=files/self \$@

eboot.bin: $(TARGET).velf
	vita-make-fself -c $< $@

%.velf: %.elf
	vita-elf-create $< $@

$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

%.o: %.png
	$(PREFIX)-ld -r -b binary -o $@ $^

clean:
	@rm -rf $(TARGET).vpk $(TARGET).velf $(TARGET).elf $(OBJS) \
		eboot.bin param.sfo
