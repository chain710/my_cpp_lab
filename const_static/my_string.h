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

#ifdef __cplusplus
extern "C" {
#endif

  my_string_t* create_my_string();

#ifdef __cplusplus
}
#endif

#endif
