#include <dirent.h>

void rewinddir(DIR* dirp) {
  seekdir(dirp, (off_t) 0); 
}
