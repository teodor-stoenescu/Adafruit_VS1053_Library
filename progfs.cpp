#include "progfs.h"

ProgFile::ProgFile(uint16_t sz, const uint8_t *b) : size(sz), buffer(b) {
	offset = 0;
}

ProgFile::ProgFile() : size(0), buffer(NULL) {
	offset = 0;
}

int ProgFile::read(void *buf, uint16_t nbyte) {
	char *t = (char *)buf;
	int bread = size - offset;
	if (bread > nbyte) {
		bread = nbyte;
	}
    //Serial.print("Reading bytes "); Serial.print(bread); Serial.print(" "); Serial.println(buffer[offset]);
    //Serial.print("Reading from "); Serial.print((uint32_t)buffer); Serial.print(" ");
    //Serial.print(buffer[offset]); Serial.print(" ");
    //Serial.print(buffer[offset + 1]); Serial.print(" ");
    //Serial.print(buffer[offset + 2]); Serial.print(" ");
    //Serial.println(buffer[offset + 3]); Serial.print(" ");

	for (int i = 0; i < bread; ++i) {
		t[i] = pgm_read_byte(&buffer[offset + i]);
	}

	offset += bread;
	return bread;
}

int ProgFile::read() {
	char t = buffer[offset];

	offset++;
	return t;
}

boolean ProgFile::seek(uint32_t pos) {
	if (pos > size) {
		return false;
	}

	offset = pos;
}

void ProgFile::close() {
}

ProgFile::operator bool() {
	return NULL != buffer;
} 

ProgFile ProgFsClass::open(const ProgFsDescriptor *pfd) {
	uint16_t sz = pfd->size;
	return ProgFile(sz, pfd->buffer);
}

ProgFsClass PFS;
