#include <dump_string.h>
#include <cstdio>
#ifdef __cplusplus
extern "C" {
#endif

  void dump_my_string(const my_string_t *s)
  {
    printf("dump_my_string (%p)\n", s);
    s->print();
  }

#ifdef __cplusplus
}
#endif
