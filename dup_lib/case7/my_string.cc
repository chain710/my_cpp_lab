#include <my_string.h>
#include <cstdio>
using namespace std;

const my_string_t container_t::FLAG("flag");

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
  printf("%s\n", str_.c_str());
}

void my_string_t::set(const char *s)
{
  str_ = s;
}

const char* my_string_t::data() const
{
  return str_.c_str();
}

#ifdef __cplusplus
extern "C" {
#endif

  my_string_t* create_my_string()
  {
    return new my_string_t;
  }

#ifdef __cplusplus
}
#endif

