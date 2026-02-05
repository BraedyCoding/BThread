#pragma once

#include <vector>
#include <csetjmp>
#include <functional>
#include "bthread.hpp"

class Scheduler {
public:
    static void add_thread(std::function<void()> f);
    static void run();
    static void yield(BThread& t);
    static int self();
    static std::vector<BThread> threads;

private:
    static int cur_running_thread_id;
    static jmp_buf scheduler_context;

    static void schedule();
};
