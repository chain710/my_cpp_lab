#include <my_string.h>

/*
 * this case DONT coredump
 */

int main(int argc, char **argv)
{
  my_string_t tmp("hello, world");
  tmp.print();
  return 0;
}
