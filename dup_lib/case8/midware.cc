#include <midware.h>
#include <cstdio>

#ifdef __cplusplus
extern "C" {
#endif

  void print_my_string(const my_string_t *s)
  {
    printf("print_my_string (%p)\n", s);
    s->print();
  }

#ifdef __cplusplus
}
#endif
