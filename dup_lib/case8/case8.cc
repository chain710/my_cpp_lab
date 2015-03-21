#include <my_string.h>
#include <dlfcn.h>
#include <errno.h>
#include <cstdio>

/*
 * ./case8.out ./libmidware.so DONT coredump
 * static linked
 */

int main(int argc, char **argv)
{
  if (argc < 2) {
    printf("usage:\n%s libpath1 libpath2 ...\n", argv[0]);
    return -1;
  }

  printf("container_t::FLAG (%p) = %s\n", &container_t::FLAG, container_t::FLAG.data());

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
