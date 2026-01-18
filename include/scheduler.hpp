#pragma once
#include <vector>


class Scheduler {
public:
    static void add_thread(bthread_func func);
    static void yield();
    static void run();
    static int self();

private:
    struct BThread {       // now private to Scheduler class
        jmp_buf context; //this is the context for our thread
        //so when we switch back, we can restore it
        char* stack;
        bthread_func func;
        enum State { READY, RUNNING, FINISHED } state;
        int id;
    };

    static std::vector<BThread> threads; // private vector
    static int cur_running_thread_id;

    //this is our scheduler context to switch back to the scheduler
    static jmp_buf scheduler_context;
};

