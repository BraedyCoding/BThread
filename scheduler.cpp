#include "scheduler.hpp"

// Static member definitions
std::vector<BThread> Scheduler::threads;
int Scheduler::cur_running_thread_id = -1;
jmp_buf Scheduler::scheduler_context;



void Scheduler::schedule() {
    // Move to the next READY thread
    int n = threads.size();
    for (int i = 1; i <= n; ++i) {
        int next_id = (cur_running_thread_id + i) % n;
        if (threads[next_id].state == BThread::READY || threads[next_id].state == BThread::RUNNING) {
            cur_running_thread_id = next_id;
            return;
        }
    }
    // If no thread is READY, stay on current
}

//So when we use std::bind, it allows us to call the function by doing f().
//std::function<void()> is a wrapper that can store any callable target (like functions, lambda expressions, bind expressions, or other function objects) that can be called with no arguments and returns void.
//and it is perfect for our use case here because we want to store functions that take no parameters and return nothing, which is exactly what our bthreads will be doing.
void Scheduler::add_thread(std::function<void()> f) {
    BThread t;
    t.entry = f;
    t.state = BThread::READY;
    t.id = threads.size();
    threads.push_back(t);
}


void Scheduler::yield(BThread& t) {
    if (setjmp(t.context) == 0) {
        schedule();  // pick the next thread
        BThread& next = threads[cur_running_thread_id];
        next.state = BThread::RUNNING;
        longjmp(next.context, 1);  // switch to the next thread
    }
}

void Scheduler::run() {
    if (threads.empty()) return;

    cur_running_thread_id = 0;
    BThread& t = threads[cur_running_thread_id];
    t.state = BThread::RUNNING;

    if (setjmp(scheduler_context) == 0) {
        longjmp(t.context, 1);  // jump into the first thread
    }
}


int Scheduler::self() {
    return cur_running_thread_id;
}
