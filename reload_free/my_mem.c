#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

static void* (*real_malloc)(size_t)=NULL;
static void (*real_free)(void *)=NULL;

static void mtrace_init(void)
{
  real_malloc = dlsym(RTLD_NEXT, "malloc");
  real_free = dlsym(RTLD_NEXT, "free");
  if (NULL == real_malloc || NULL == real_free) {
    fprintf(stderr, "Error in `dlsym`: %s\n", dlerror());
    abort();
  }
}

void *malloc(size_t size)
{
  if(real_malloc==NULL) {
    mtrace_init();
  }
  void *p = real_malloc(size);
  printf("malloc %p size %d\n", p, (int)size);
  return p;
}

void free(void *ptr)
{
  if (real_free==NULL) {
    mtrace_init();
  }
  printf("free %p\n", ptr);
  return real_free(ptr);
}
