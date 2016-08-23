#include <stdio.h>
#include <string.h>
#include <unistd.h>

int vfprintf(FILE* stream, const char* fmt, va_list ap) {
  return write(stream->_file, (const void *) fmt, strlen(fmt));
}
