#include <stdio.h>

FILE __stdin = {
  ._file = 0
};

FILE __stdout = {
  ._file = 1
};

FILE __stderr = {
  ._file = 2
};

FILE* stdin = &__stdin;
FILE* stdout = &__stdout;
FILE* stderr = &__stderr;
