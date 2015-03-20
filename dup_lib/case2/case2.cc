#include <my_string.h>

/*
 * this case will NOT coredump
 * because 2 global_my_strings are inited in the different address
 */

int main(int argc, char **argv)
{
  my_string_t tmp("hello, world");
  tmp.print();
  return 0;
}
