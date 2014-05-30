#ifndef _LIB_COMMON_H_
#define _LIB_COMMON_H_

#ifdef __cplusplus
extern "C" {
#endif
    int global_bar;
    void set_bar(int b);
    void foo();
#ifdef __cplusplus
}
#endif

#endif
