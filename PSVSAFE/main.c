#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <psp2/ctrl.h>
#include <psp2/io/fcntl.h>
#include <psp2/io/stat.h>
#include <psp2/io/dirent.h>
#include <psp2/shellutil.h>
#include <psp2/power.h>
#include <psp2/kernel/processmgr.h>
#include <vita2d.h>

#include "TIDUtils.h"

int main() {
int ifskip = exists("ur0:pwd/skipload");
int iffirst = exists("ur0:pwd/skgpwdchk");
int ifafterdgrade = exists("vs0:pwd/fl1");
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
	const char success[512] = "Finished";
	const char nobconfig[512] = "Press X to install skgpwdchk";
	const char MainMenuOpts[4][64] = {"Set pass", "Disable pass check", "Uninstall files", "Exit"};
	const char Main2MenuOpts[4][64] = {"Set pass", "Enable pass check", "Uninstall files", "Exit"};
	int UIScreen = 1;
    if (iffirst == 0) UIScreen = 0;
	int selected = 0;	

	while(1) {
		sceCtrlPeekBufferPositive(0, &pad, 1);
		keys_down = pad.buttons & ~old_pad.buttons;
		
		vita2d_start_drawing();
		vita2d_clear_screen();
		
		switch(UIScreen) {

			case 0: // Main Menu
		
		vita2d_pgf_draw_text(font, 215, 45, RGBA8(255,255,255,255), 1.5f, "SKG's pwdchk controller");
				vita2d_pgf_draw_text(font, 35, 100, RGBA8(255,255,255,255), 1.5f, nobconfig);
				vita2d_draw_rectangle(402, 425, 145, 70, RGBA8(92,226,92,255));
				vita2d_pgf_draw_text(font, 410, 470, RGBA8(0,0,0,255), 1.5f, "Install");
				break;
			case 1: // Main Menu
		
		vita2d_pgf_draw_text(font, 215, 45, RGBA8(255,255,255,255), 1.5f, "SKG's pwdchk controller");
				if (selected < 0) selected = 0;
				if (selected > 3) selected = 3;
				for (int i = 0; i < 4; i++) {
if (ifskip == 1) {
					if (i == selected) {
						vita2d_draw_rectangle(70, (80*i) + 85, 820, 70, RGBA8(92,226,92,255));
						vita2d_pgf_draw_text(font, 85, (80*i) + 130, RGBA8(0,0,0,255), 1.5f, Main2MenuOpts[i]);
					} else vita2d_pgf_draw_text(font, 85, (80*i) + 130, RGBA8(255,255,255,255), 1.5f, Main2MenuOpts[i]);
}
if (ifskip == 0) {
					if (i == selected) {
						vita2d_draw_rectangle(70, (80*i) + 85, 820, 70, RGBA8(92,226,92,255));
						vita2d_pgf_draw_text(font, 85, (80*i) + 130, RGBA8(0,0,0,255), 1.5f, MainMenuOpts[i]);
					} else vita2d_pgf_draw_text(font, 85, (80*i) + 130, RGBA8(255,255,255,255), 1.5f, MainMenuOpts[i]);
}
				}
				break;

			case 2: // Credits Menu
if (ifskip == 0){
filecopy("ur0:tai/config.txt", "ur0:pwd/skipload");}
if (ifskip == 1){
sceIoRemove("ur0:pwd/skipload");}
				  vita2d_pgf_draw_text(font, 35, 100, RGBA8(255,255,255,255), 1.5f, success);
				  vita2d_draw_rectangle(402, 425, 145, 70, RGBA8(92,226,92,255));
			   	  vita2d_pgf_draw_text(font, 410, 470, RGBA8(0,0,0,255), 1.5f, "Continue");

				break;


			case 33: // Install Confirmation
                  		vita2d_clear_screen();
		
		vita2d_pgf_draw_text(font, 215, 45, RGBA8(255,255,255,255), 1.5f, "1");
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
                  filecopy("ur0:tai/config.txt", bouf);
		vita2d_pgf_draw_text(font, 215, 45, RGBA8(255,255,255,255), 1.5f, "SKG's pwdchk controller");
				  vita2d_pgf_draw_text(font, 35, 100, RGBA8(255,255,255,255), 1.5f, success);
				  vita2d_draw_rectangle(402, 425, 145, 70, RGBA8(92,226,92,255));
			   	  vita2d_pgf_draw_text(font, 410, 470, RGBA8(0,0,0,255), 1.5f, "Continue");
                  break;
case 99:
                  sceIoMkdir("ur0:pwd", 0777);
filecopy("app0:files/self", "ur0:pwd/skgpwdchk");
				  vita2d_pgf_draw_text(font, 35, 100, RGBA8(255,255,255,255), 1.5f, success);
				  vita2d_draw_rectangle(402, 425, 145, 70, RGBA8(92,226,92,255));
			   	  vita2d_pgf_draw_text(font, 410, 470, RGBA8(0,0,0,255), 1.5f, "Continue");
break;

case 69:
sceIoRemove("ur0:pwd/skgpwdchk");
				  vita2d_pgf_draw_text(font, 35, 100, RGBA8(255,255,255,255), 1.5f, success);
				  vita2d_draw_rectangle(402, 425, 145, 70, RGBA8(92,226,92,255));
			   	  vita2d_pgf_draw_text(font, 410, 470, RGBA8(0,0,0,255), 1.5f, "Continue");
break;


		}
		
		if (keys_down & SCE_CTRL_CROSS) {
			switch(UIScreen) {
				case 0:
					UIScreen = 99;
					break;
				case 1:
					if (selected == 0) UIScreen = 33;
					if (selected == 1) UIScreen = 2;
					if (selected == 2) UIScreen = 69;
					if (selected == 3) sceKernelExitProcess(0);
					break;
				case 33:
                
					UIScreen = 3, one = 1;
					break;
				case 3:
                    
					UIScreen = 4, two = 1;
					break;
				case 4:
					UIScreen = 6, three = 1;
					break;
				case 5:
					UIScreen = 1;
					break;
				case 2:
					UIScreen = 1;
					break;
				case 99:
					UIScreen = 1;
					break;
				case 69:
					UIScreen = 1;
					break;
case 6:
UIScreen = 5, four = 1;
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
				case 1:
					selected -= 1;
					break;
				case 33:
					UIScreen = 3, one = 5;
					break;
				case 3:
					UIScreen = 4, two = 5;
					break;
				case 4:
					UIScreen = 6, three = 5;
					break;
				case 6666:
					selected -= 1;
					break;
case 6:
UIScreen = 5, four = 5;
break;
			}
		} if (keys_down & SCE_CTRL_DOWN) {
			switch(UIScreen) {
				case 1:
					selected += 1;
					break;
				case 33:
					UIScreen = 3, one = 6;
					break;
				case 3:
					UIScreen = 4, two = 6;
					break;
				case 4:
					UIScreen = 6, three = 6;
					break;
				case 6666:
					selected += 1;
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
