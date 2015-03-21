#include <my_string.h>

/*
 * Not coredump
 * use extern, only has one copy of global var
 */

int main(int argc, char **argv)
{
  my_string_t tmp("hello, world");
  tmp.print();
  return 0;
}
