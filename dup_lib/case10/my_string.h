#ifndef _MY_STRING_H_
#define _MY_STRING_H_

#include <string>

class my_string_t
{
 public:
  my_string_t(const char* s = "");
  ~my_string_t();

  void print() const;
  void set(const char* s);
 private:
  std::string str_;
};

const my_string_t global_my_string("__temp__");

class container_t
{
 public:
  static my_string_t FLAG;
};

#ifdef __cplusplus
extern "C" {
#endif

  my_string_t* create_my_string();

  void print_global_string();

#ifdef __cplusplus
}
#endif

#endif
