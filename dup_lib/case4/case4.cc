#include <my_string.h>
#include <dlfcn.h>
#include <errno.h>
#include <cstdio>

/*
 * ./case4.out ./libmy_string_b.so MAY coredump
 * global var in libmy_string_b.so has same address with var in libmy_string_a.so
 */

int main(int argc, char **argv)
{
  if (argc < 2) {
    printf("usage:\n%s libpath1 libpath2 ...\n", argv[0]);
    return -1;
  }

  for (int i = 1; i < argc; ++i) {
    void *dl_handler = dlopen(argv[i], RTLD_NOW);
    if (NULL == dl_handler) {
      printf("open lib (%s) failed. errno %d(%s)\n", argv[i], errno, dlerror());
      return -1;
    }

    int err = dlclose(dl_handler);
    if (err != 0) {
      printf("close lib (%s) failed. errno %d(%s)\n", argv[i], errno, dlerror());
      return -1;
    }
  }

  return 0;
}
