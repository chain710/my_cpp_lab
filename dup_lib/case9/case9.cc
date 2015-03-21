#include <midware.h>
#include <dlfcn.h>
#include <errno.h>
#include <cstdio>

/*
 * ./case9.out ./libmidware_plugin.so MAY coredump
 * binary recognizes 2 libmy_string as different lib
 */

int main(int argc, char **argv)
{
  if (argc < 2) {
    printf("usage:\n%s libpath1 libpath2 ...\n", argv[0]);
    return -1;
  }

  print_my_string(&container_t::FLAG);

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
