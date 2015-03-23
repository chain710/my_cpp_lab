#include <my_string.h>
#include <midware.h>
/*
 * this case MAY coredump
 * libmidware link against static lib
 * case3.out link against libmidware & libmy_string(dynamic)
 * init 2 global in same address
 */

int main(int argc, char **argv)
{
  my_string_t tmp("hello, world");
  print_my_string(&tmp);
  return 0;
}
