#include <stdio.h>
#include "bthread.hpp"
#include "scheduler.hpp"



//this is the structure of how we will run the bthreads
void thread1() { /*...*/ }
void thread2() { /*...*/ }

int main() {

    //1. create bthreads  (pass in function pointer which is used
    //to create a Bthread object inside of scheduler.cpps bthread_create
    //which is then added to the vector list.
    bthread_create(thread1);
    bthread_create(thread2);

    //run the scheduler
    bthread_run();  // starts the scheduler
    return 0;
}