#include "shared-library.h"
#include <stdio.h>


void shared_a() {
    shared_b();
}

void shared_b() {
    printf("Hello, in shared b\n");
}
