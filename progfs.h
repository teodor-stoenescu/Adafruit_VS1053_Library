#ifndef __PROG_FS__
#define __PROG_FS__

#include <Arduino.h>

struct ProgFsDescriptor {
	const uint16_t size;
	const uint8_t *buffer;
};

class ProgFile {
private :
	uint16_t size;
	uint16_t offset;

	const uint8_t *buffer;
public :
	ProgFile(uint16_t sz, const uint8_t *b);
	ProgFile();

	int read(void *buf, uint16_t nbyte);
	int read();

  	boolean seek(uint32_t pos);
  	void close();

  	operator bool();
};

class ProgFsClass {
public :
	ProgFile open(const ProgFsDescriptor *pfd);
};

extern ProgFsClass PFS;

#endif
