# BThread
This repository will be deticated to my own custom C++ threading libary


example of how jmp_buf buf works:
#include <csetjmp>
#include <cstdio>

jmp_buf buf;

void second() {
    printf("second()\n");
    longjmp(buf, 42); // jump back to first
}

void first() {
    if (setjmp(buf) == 0) {
        printf("setjmp first time\n");
        second(); // call another function
    } else {
        printf("returned from longjmp!\n");
    }
}

int main() {
    first();
}