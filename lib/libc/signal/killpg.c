#include <signal.h>

int killpg(int pgrp, int sig) {
  if(pgrp <= 1) {
    //TODO: set errno
    return -1;
  }
  return kill(-pgrp, sig);
}
