#pragma once

using bthread_func = void(*)();


//this is our bthread interface which will interact with the scheduler
int bthread_create(bthread_func f);
void bthread_yield();
void bthread_run();
int bthread_self();