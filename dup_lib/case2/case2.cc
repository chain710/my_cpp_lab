#include <my_string.h>

/*
 * this case will NOT coredump
 * because 2 global_my_strings are inited in the different address
 */

int main(int argc, char **argv)
{
  my_string_t *local_str = const_cast<my_string_t*>(&global_my_string);
  local_str->set("mydata");
  local_str->print();
  print_global_string();
  return 0;
}
