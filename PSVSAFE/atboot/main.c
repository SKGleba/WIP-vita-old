#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <psp2/ctrl.h>
#include <psp2/io/fcntl.h>
#include <psp2/io/stat.h>
#include <psp2/io/dirent.h>
#include <psp2/power.h>
#include <psp2/kernel/processmgr.h>
#include <vita2d.h>

void quifex(const char *filname) {
    FILE *file;
    if ((file = fopen(filname, "r")))
    {
        fclose(file);
        sceKernelExitProcess(0);
    }
}

int main() {
quifex("ur0:pwd/skipload");
    char bouf[100];
    int one, two, three, four;
	SceCtrlData pad, old_pad;
	unsigned int keys_down;
	old_pad.buttons = 0;
	
	vita2d_pgf *font;
	vita2d_init();
	vita2d_set_clear_color(RGBA8(0x00, 0x00, 0x00, 0xFF));
	font = vita2d_load_default_pgf();
	memset(&pad, 0, sizeof(pad));
	int UIScreen = 33;	

	while(1) {
		sceCtrlPeekBufferPositive(0, &pad, 1);
		keys_down = pad.buttons & ~old_pad.buttons;
		
		vita2d_start_drawing();
		vita2d_clear_screen();
		
		switch(UIScreen) {

			case 33: // Install Confirmation
                  		vita2d_clear_screen();
		
		vita2d_pgf_draw_text(font, 215, 45, RGBA8(255,255,255,255), 1.5f, "Enter password to continue: 1");
break;
case 3:
                  		vita2d_clear_screen();
		
		vita2d_pgf_draw_text(font, 215, 45, RGBA8(255,255,255,255), 1.5f, "2");
break;
case 4:
                  		vita2d_clear_screen();
		
		vita2d_pgf_draw_text(font, 215, 45, RGBA8(255,255,255,255), 1.5f, "3");
break;
case 6:
                  		vita2d_clear_screen();
		
		vita2d_pgf_draw_text(font, 215, 45, RGBA8(255,255,255,255), 1.5f, "4");
break;
case 5:

    sprintf(bouf, "ur0:pwd/%d%d%d%d", one, two, three, four);
quifex(bouf);
                  		vita2d_clear_screen();
		
		vita2d_pgf_draw_text(font, 215, 45, RGBA8(255,255,255,255), 1.5f, "BAD PWD! PRESS X");
                  break;


		}
		
		if (keys_down & SCE_CTRL_CROSS) {
			switch(UIScreen) {
				case 33:
                
					UIScreen = 3, one = 1;
					break;
				case 3:
                    
					UIScreen = 4, two = 1;
					break;
				case 4:
					UIScreen = 6, three = 1;
					break;
case 6:
UIScreen = 5, four = 1;
break;
case 5:
UIScreen = 33;
break;
			}
		}

		if (keys_down & SCE_CTRL_TRIANGLE) {
			switch(UIScreen) {
				case 33:
                
					UIScreen = 3, one = 2;
					break;
				case 3:
                    
					UIScreen = 4, two = 2;
					break;
				case 4:
					UIScreen = 6, three = 2;
					break;
case 6:
UIScreen = 5, four = 2;
break;
			}
		}

		if (keys_down & SCE_CTRL_CIRCLE) {
			switch(UIScreen) {
				case 33:
                
					UIScreen = 3, one = 3;
					break;
				case 3:
                    
					UIScreen = 4, two = 3;
					break;
				case 4:
					UIScreen = 6, three = 3;
					break;
case 6:
UIScreen = 5, four = 3;
break;
}
}

		if (keys_down & SCE_CTRL_SQUARE) {
			switch(UIScreen) {
				case 33:
                
					UIScreen = 3, one = 4;
					break;
				case 3:
                    
					UIScreen = 4, two = 4;
					break;
				case 4:
					UIScreen = 6, three = 4;
					break;
case 6:
UIScreen = 5, four = 4;
break;
			}
		}
		
		if (keys_down & SCE_CTRL_UP) {
			switch(UIScreen) {
				case 33:
					UIScreen = 3, one = 5;
					break;
				case 3:
					UIScreen = 4, two = 5;
					break;
				case 4:
					UIScreen = 6, three = 5;
					break;
case 6:
UIScreen = 5, four = 5;
break;
			}
		} if (keys_down & SCE_CTRL_DOWN) {
			switch(UIScreen) {
				case 33:
					UIScreen = 3, one = 6;
					break;
				case 3:
					UIScreen = 4, two = 6;
					break;
				case 4:
					UIScreen = 6, three = 6;
					break;
case 6:
UIScreen = 5, four = 6;
break;
			}
		} if (keys_down & SCE_CTRL_RIGHT) {
			switch(UIScreen) {
				case 33:
					UIScreen = 3, one = 7;
					break;
				case 3:
					UIScreen = 4, two = 7;
					break;
case 4:
UIScreen = 6, three = 7;
break;
case 6:
UIScreen = 5, four = 7;
break;
			}
		} if (keys_down & SCE_CTRL_LEFT) {
			switch(UIScreen) {
				case 33:
					UIScreen = 3, one = 8;
					break;
				case 3:
					UIScreen = 4, two = 8;
					break;
case 4:
UIScreen = 6, three = 8;
break;
case 6:
UIScreen = 5, four = 8;
break;
			}
		}
		
		old_pad = pad;
		
		vita2d_end_drawing();
		vita2d_swap_buffers();
	}
	vita2d_fini();
	vita2d_free_pgf(font);
	
	sceKernelExitProcess(0);
	return 0;
}
