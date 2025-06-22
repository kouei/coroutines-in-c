#include "coroutine.h"
#include <assert.h>

int co_function_src(void) {
  static int i;
  scrBegin;
  for (i = 0; i < 5; i++) {
    scrReturn(i);
  }
  scrFinish(-1);
}

int co_function_ccr(ccrContParam) {
  ccrBeginContext;
  int i;
  ccrEndContext();

  ccrBegin();
  for (ccrGetVar(i) = 0; ccrGetVar(i) < 5; ccrGetVar(i) += 1) {
    ccrReturn(ccrGetVar(i));
  }
  ccrFinish(-1);
}

int main(int argc, char *argv[]) {
  assert(co_function_src() == 0);
  assert(co_function_src() == 1);
  assert(co_function_src() == 2);
  assert(co_function_src() == 3);
  assert(co_function_src() == 4);
  assert(co_function_src() == -1);

  ccrContext ctx = NULL;
  assert(co_function_ccr(&ctx) == 0);
  assert(co_function_ccr(&ctx) == 1);
  assert(co_function_ccr(&ctx) == 2);
  assert(co_function_ccr(&ctx) == 3);
  assert(co_function_ccr(&ctx) == 4);
  assert(co_function_ccr(&ctx) == -1);

  return 0;
}