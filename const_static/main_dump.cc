#include <midware.h>
#include <dump_string.h>
#include <cstdio>

int main(int argc, char **argv)
{
  printf("begin!\n");
  my_string_t a("hello, world!");
  print_my_string(&a);
  printf("\n----------------\n");
  dump_my_string(&a);
  printf("end\n");
  return 0;
}

