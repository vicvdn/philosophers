# Notes

## Difference between threads and processes

- **A process** is an instance of a program that is being executed. It is an independent entity that can run independently of other processes. It has its own memory space, system resources, and state. A process can have multiple threads. Processes encompass the environment of threads.

- **A thread** is a lightweight process. It is a part of a process. Threads share the same memory space and system resources as the process that created them. All threads can access all the data and resources of the process. Threads are used to execute multiple tasks concurrently within a single process. They all have a common set of variables and resources in other words.

## Race conditions

A race condition occurs when two or more threads can access shared data and they try to change it at the same time. Because the thread scheduling algorithm can swap between threads at any time, you don't know the order in which the threads will attempt to access the shared data. Therefore, the result of the change in data is dependent on the thread scheduling algorithm, i.e. both threads are "racing" to access/change the data.

## Mutex - to solve race conditions

A mutex is a lock that you can set before using a shared resource and release after using it. It is used to protect shared data from being accessed by more than one thread at a time. A mutex is a mutual exclusion object. Only one thread can lock a mutex at any given time. If a second thread tries to lock a mutex that has already been locked, the second thread will be suspended until the mutex is unlocked.
Example:
```c
#include <stdio.h>
#include <pthread.h>

int mails = 0;
p_thread_mutex_t mutex;

void*	routine()
{
	int i;
	for (i = 0; i < 1000000; i++)
	{
		pthread_mutex_lock(&mutex); // locks the mutex for us
		mails++;
		pthread_mutex_unlock(&mutex); // unlocks the mutex for us
		lock = 0;
	}
	return (NULL);
}

int main()
{
	pthread_t t1, t2;

	pthread_mutex_init(&mutex, NULL);
	if (pthread_create(&t1, NULL, routine, NULL) != 0)
		return (1);
	if (pthread_create(&t2, NULL, routine, NULL) != 0)
		return (1);
	if (pthread_join(t1, NULL) != 0)
		return (1);
	if (pthread_join(t2, NULL) != 0)
		return (1);
	pthread_mutex_destroy(&mutex);
	printf("mails: %d\n", mails);
	return (0);
}
```