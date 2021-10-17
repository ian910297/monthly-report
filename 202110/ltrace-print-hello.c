#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shared-library.h"

void a() {
    printf("Hello, World!\n");
}

int main(int argc, char *argv[]) {
    printf("Hello, World!\n");

    char zeros[10];
    for (int i=0; i<10; i++) {
        //memset(zeros, '\0', sizeof(char) * 10);
    }

    a();

    //shared_a();
    return 0;
}
