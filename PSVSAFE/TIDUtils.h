#ifndef __TIDUTILS_H_
#define __TIDUTILS_H_

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
#include <psp2/kernel/threadmgr.h>
#include <psp2/kernel/openpsid.h>
#include <vita2d.h>
#include <psp2/types.h>

int WriteFile(char *file, void *buf, int size);

int exists(const char *fname);
int hasEndSlash(const char *path);
int removePath(const char *path);

int filecopy(const char *path1, const char *path2);

#endif /* __TIDUTILS_H_ */
