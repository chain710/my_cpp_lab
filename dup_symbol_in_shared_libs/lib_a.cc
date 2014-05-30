#include "lib_a.h"
#include <stdio.h>
#ifdef __cplusplus
extern "C" {
#endif
    static int local_bar = 5555;
    int hidden_global_bar = 2222;
    void foo()
    {
        printf("foo in lib_a\n");
    }
    void set_bar(int b)
    {
        global_bar = b;
        local_bar = b;
        hidden_global_bar = b;
    }

    void print_bar_a()
    {
        printf("print global in lib_a %d\n", global_bar);
        printf("print local in lib_a %d\n", local_bar);
        printf("print hidden_global in lib_a %d\n", hidden_global_bar);
    }
#ifdef __cplusplus
}
#endif

