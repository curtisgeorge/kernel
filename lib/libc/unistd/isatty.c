#include <unistd.h>
#include <sys/stat.h>

int isatty(int fd) {
  struct stat buf;
  if(fstat(fd, &buf) < 0) {
    //TODO: set errno
    return 0;
  }
  if(S_ISCHR(fd)) {
    //TODO: set errno
    return 1;
  }
  return 0;
}
