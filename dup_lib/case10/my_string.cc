#include <my_string.h>
#include <cstdio>
using namespace std;

my_string_t container_t::FLAG("flag");

my_string_t::my_string_t(const char* s)
  :str_(s)
{
  printf("my_string_t ctor(%p) (%s)\n", this, s);
}

my_string_t::~my_string_t()
{
  printf("my_string_t dtor(%p) (%s)\n", this, str_.c_str());
}

void my_string_t::print() const
{
  printf("str(%p) = %s\n", this, str_.c_str());
}

void my_string_t::set(const char *s)
{
  str_ = s;
}

#ifdef __cplusplus
extern "C" {
#endif

  my_string_t* create_my_string()
  {
    return new my_string_t;
  }

  void print_global_string()
  {
    global_my_string.print();
  }

#ifdef __cplusplus
}
#endif
