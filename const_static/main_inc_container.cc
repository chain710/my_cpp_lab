#include <midware.h>
#include <container.h>
#include <cstdio>

int main(int argc, char **argv)
{
  printf("begin!\n");
  print_my_string(&container_t::FLAG);
  printf("end\n");
  return 0;
}

