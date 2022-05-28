//
// Created by Frank Lin on 11/04/2022.
//

#include<stdio.h>
static void find_stack_direction(void);
static int stack_dir;

int main(void) {
    find_stack_direction();
    if(stack_dir==1) puts("stack grew upward");
    else puts("stack grew downward");
    return 0;
}

static void find_stack_direction (void) {
    static char *addr = NULL;
    /* address of first `dummy', once known */
    auto char dummy;
    /* to get stack address */
    if (addr == NULL) {
        /* initial entry */
        addr = &dummy;
        find_stack_direction (); /* recurse once */
    } else /* second entry */if (&dummy > addr) stack_dir = 1; /* stack grew upward */
    else stack_dir = -1; /* stack grew downward */
}
