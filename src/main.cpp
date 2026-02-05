#include <stdio.h>
#include "bthread.hpp"
#include "scheduler.hpp"
#include <functional>



//this is the structure of how we will run the bthreads
void thread1() {  
    while(true) {
        printf("Thread 1 is running\n");
        fflush(stdout);
        Scheduler::yield(Scheduler::threads[Scheduler::self()]);
    }
}

void thread2() { 
    while(true) {
        printf("Thread 2 is running\n");
        fflush(stdout);
        Scheduler::yield(Scheduler::threads[Scheduler::self()]);
    }
}


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