#pragma once

#include <functional>
#include <csetjmp>

// User API
template<typename Func, typename... Args>
void bthread_create(Func f, Args... args);

void bthread_run();
int bthread_self();


// Thread Control Block
struct BThread {
    jmp_buf context;
    std::function<void()> entry;
    int id;

    enum State {
        READY,
        RUNNING,
        FINISHED
    } state;
};
