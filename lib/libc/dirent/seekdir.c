#include <dirent.h>
#include <stdio.h>
#include <unistd.h>

void seekdir(DIR* dirp, long loc) {
  lseek(dirp->fd, loc, SEEK_SET);
  dirp->filepos = loc;
}
