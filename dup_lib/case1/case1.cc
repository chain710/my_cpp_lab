#include <my_string.h>

/*
 * this case MAY coredump
 * because 2 global_my_string is inited in the same address
 * one in lib_my_string.so, another in case1 binary
 * call routine:
 *  _dl_start_users -> global str in so
 *  __libc_start_main -> global str in binary
 * cause double free
 * NOTE: use valgrind to see memory errors
 */

int main(int argc, char **argv)
{
  my_string_t tmp("hello, world");
  tmp.print();
  return 0;
}
