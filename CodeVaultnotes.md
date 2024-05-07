# Notes

## Difference between threads and processes

- **A process** is an instance of a program that is being executed. It is an independent entity that can run independently of other processes. It has its own memory space, system resources, and state. A process can have multiple threads. Processes encompass the environment of threads.

- **A thread** is a lightweight process. It is a part of a process. Threads share the same memory space and system resources as the process that created them. All threads can access all the data and resources of the process. Threads are used to execute multiple tasks concurrently within a single process. They all have a common set of variables and resources in other words.

## Race conditions

