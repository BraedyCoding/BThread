#include "bthread.hpp"
#include "scheduler.hpp"
#include <functional>

// Create thread (template must live in header normally,
// but we keep it here since it will be included where used)
template <typename Func, typename... Args>
void bthread_create(Func f, Args... args) {
    Scheduler::add_thread(std::bind(f, args...)); //right away we bind so we don't have to keep making everything templates 
}

void bthread_run() {
    Scheduler::run();
}

int bthread_self() {
    return Scheduler::self();
}
