#include <dirent.h>

long telldir(DIR* dirp) {
  return dirp->filepos;
}
