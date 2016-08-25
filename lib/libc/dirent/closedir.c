#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>

int closedir(DIR* dirp) {
  int fd;
  if(dirp == NULL) {
    //TODO: Set errno
    return -1;
  }
  fd = dirp->fd;
  free((void*) dirp);
  return close(fd);
}
