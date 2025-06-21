#include <stdio.h>

#define crBegin                                                                \
  static int state = 0;                                                        \
  switch (state) {                                                             \
  case 0:

#define crReturn(x)                                                            \
  do {                                                                         \
    state = __LINE__;                                                          \
    return x;                                                                  \
  case __LINE__:;                                                              \
  } while (0)

#define crFinish }

int co_function(void) {
  static int i;
  crBegin;
  for (i = 0; i < 10; i++)
    crReturn(i);
  crFinish;

  return -1;
}

int main(int argc, char *argv[]) {
  for (;;) {
    int i = co_function();
    if (i == -1) {
      break;
    }

    printf("%d ", i);
  }
  return 0;
}