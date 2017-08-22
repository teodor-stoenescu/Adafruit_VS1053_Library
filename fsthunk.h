#ifndef __FS_THUNK__
#define __FS_THUNK__

#ifdef USE_PROGFS
	#include "progfs.h"
	#define FILE ProgFile
	#define FS PFS
	#define FILEDESCRIPTOR ProgFsDescriptor *
#else
	#include <SD.h>
	#define FILE File
	#define FS SD
	#define FILEDESCRIPTOR char *
#endif

#endif