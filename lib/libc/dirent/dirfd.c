#include <dirent.h>

int dirfd(DIR* dirp) {
  return dirp->fd;
}
