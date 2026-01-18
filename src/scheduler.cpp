#include "scheduler.hpp"
#include <csetjmp>
#include <cstdlib>
#include <iostream>

jmp_buf buf;

// ------------------------
// Static member definitions
// ------------------------
std::vector<Scheduler::BThread> Scheduler::threads;
int Scheduler::cur_running_thread_id = -1;
jmp_buf Scheduler::scheduler_context;

// ------------------------
// Scheduler methods
// ------------------------

// Internal schedule method (round-robin placeholder)
void Scheduler::schedule() {
    // TODO: implement context switching
}

// Add a new thread
void Scheduler::add_thread(bthread_func func) {
   
    BThread t;
    t.stack = nullptr;       // optional stack allocation
    t.func = func;
    t.state = BThread::READY;
    t.id = threads.size();
    threads.push_back(t);
}

//A thread will call yield to give up control and save state
void Scheduler::yield() {
    // TODO: save current context and switch threads
}

// Start the scheduler
void Scheduler::run() {
    if (threads.empty()) return;

    // Save scheduler context
    if (setjmp(scheduler_context) == 0) {
        // Start first thread
        cur_running_thread_id = 0;

        // Jump into first thread function
        BThread& t = threads[cur_running_thread_id];
        t.state = BThread::RUNNING;
        t.func(); // thread will eventually call yield()
    }

    // When all threads finished, run() returns here
}
// Return ID of current thread
int Scheduler::self() {
    return cur_running_thread_id;
}
