BThreads V1 – Minimal User-Level Threading Library
Overview

BThreads V1 is a minimal, educational, user-level threading library implemented in C++. This version demonstrates the basic principles of cooperative multitasking using setjmp and longjmp for context switching, without relying on OS-level threads or assembly.

This project is Version 1 (V1), focusing on a simple, safe, and fully functional cooperative threading model.

Features

User-level threads (green threads): Threads are scheduled cooperatively.

Function binding: Any callable function (including functions with arguments) can be used as a thread entry point using std::function and std::bind.

Round-robin scheduler (manual): Threads yield explicitly to the scheduler.

No assembly required: Fully implemented with standard C++ (setjmp/longjmp) and the standard library.

Static Scheduler: Global scheduler manages all threads, making it easy to create and run threads.

Limitations

Threads share the main program stack, so nested function calls across yields are unsafe.

Preemption is not supported: Threads must explicitly call yield() to switch.

Single OS thread: All BThreads run on the main thread; true parallelism is not possible.

Manual yield required: Threads in infinite loops must call Scheduler::yield() to allow other threads to run.