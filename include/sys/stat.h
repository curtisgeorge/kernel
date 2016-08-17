#pragma once

struct stat {
  int st_dev;
  int st_ino;
  int st_size;
  int st_mode;
};

int fstat(int, struct stat*);
