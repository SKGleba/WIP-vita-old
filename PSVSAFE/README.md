# PSVSAFE / SKGpwdCHK
![ref0](https://github.com/SKGleba/WIP/raw/master/PSVSAFE/pics/IMG_20180123_121544.jpg)

Its a very early PoC of bios-like pwd protection for enso devices. It allows you to protect your vita with a key combination (currently 4 keys max).

Only the installer/manager + executable are included. 

Add a line under "umount_bootfs" in boot_config.txt: "- spawnwait ur0:pwd/skgpwdchk" and then start the installer.

Supported keys: UP, DOWN, LEFT, RIGHT, TRIANGLE, CIRCLE, SQUARE, CROSS.

I think i will get back to, and rewrite it.

ref pics:
![ref1](https://github.com/SKGleba/WIP/raw/master/PSVSAFE/pics/IMG_20180123_110527.jpg)
![ref2](https://github.com/SKGleba/WIP/raw/master/PSVSAFE/pics/IMG_20180123_121755.jpg)

