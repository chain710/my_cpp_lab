#include <stdio.h>
int main(int argc, char **argv) {
  char *a = new char[100];
  printf("bewteen new and delete\n");
  delete []a;
  return 0;
}
