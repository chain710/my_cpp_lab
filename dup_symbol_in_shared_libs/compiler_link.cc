#include <stdlib.h>
#include <stdio.h>
#include "lib_a.h"
#include "lib_b.h"
int main(int argc, char **argv)
{
    foo();
    printf("------------------------\n");
    printf("above string content depend on lib link order\n");
    printf("------------------------\n");

    set_bar(8484);
    print_bar_a();
    print_bar_b();
    printf("------------------------\n");
    printf("above global int should be the same, local shall be different\n");
    printf("------------------------\n");

    set_bar(1212);
    print_bar_a();
    print_bar_b();
    printf("------------------------\n");
    printf("above global int should be the same, local shall be different\n");
    printf("------------------------\n");

    return 0;
}

