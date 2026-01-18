#include "bthread.hpp"
#include "scheduler.hpp"

//entry point: call on the create function which adds
//the thread to the schedulers thread list
int bthread_create(bthread_func f) {
    Scheduler::add_thread(f);
    return Scheduler::self();
}

void bthread_yield() {
    Scheduler::yield();
}

//when all threads are added, call run to start the scheduler
void bthread_run() {
    Scheduler::run();
}

int bthread_self() {
    return Scheduler::self();
}
