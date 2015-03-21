#include <midware.h>

#ifdef __cplusplus
extern "C" {
#endif

  void print_my_string(my_string_t *s)
  {
    s->print();
  }

#ifdef __cplusplus
}
#endif
