# philosophers

## External function allowed : 

- memset
    ```c
    void *memset(void *s, int c, size_t n);
    ```
    The memset()function  is commonly used for initializing arrays, structures, or blocks of memory to a specific value. It fills the first n bytes of the memory area pointed to by s with the constant byte c. The memset() function returns a pointer to the memory area s. 

- printf
    ```c
    int printf(const char *format, ...);
    ```

- malloc
    ```c
    void *malloc(size_t size);
    ```
- free
    ```c
    void free(void *ptr);
    ```

- write
    ```c
    ssize_t write(int fd, const void *buf, size_t count);
    ```

- usleep
    ```c
    int usleep(useconds_t usec);
    ```

    The usleep function in C is used to suspend the execution of the calling thread for a specified number of microseconds. It is part of the POSIX standard and is defined in the ```<unistd.h>``` header file. Here, ```usec``` is the number of microseconds to suspend the thread. The function returns 0 on success and -1 on error, with errno set to indicate the error.

    The usleep function is particularly useful for creating short delays in a program's execution. However, it's important to note that the actual suspension time may be slightly longer than requested due to system activity, the time spent processing the call, or the granularity of system timers. The maximum value for usec is one million microseconds (1 second), and setting usec to 0 makes the call ineffective.

- gettimeofday
    ```c
    int gettimeofday(struct timeval *tv, struct timezone *tz);
    ```

    The gettimeofday function in C is used to get the current time of day, expressed as seconds and microseconds. It is part of the POSIX standard and is defined in the ```<sys/time.h>``` header file. The function takes two arguments: a pointer to a timeval structure (tv) and a pointer to a timezone structure (tz). The timeval structure is defined as follows:

    ```c
    struct timeval {
        time_t      tv_sec;     /* seconds */
        suseconds_t tv_usec;    /* microseconds */
    };
    ```

    The gettimeofday function fills the timeval structure pointed to by tv with the current time of day. The timezone structure is obsolete and should be set to NULL. The function returns 0 on success and -1 on error, with errno set to indicate the error.

    Here's a simple example demonstrating the use of gettimeofday to print the current time:

    ```c
    #include <stdio.h>
    #include <sys/time.h>

    int main() {
        struct timeval tv;
        gettimeofday(&tv, NULL);
        printf("Current time: %ld.%06ld\n", tv.tv_sec, tv.tv_usec);
        return 0;
    }
    ```

- pthread_create

    The pthread_create function in C is used to create a new thread within a process. It is part of the POSIX thread (pthread) standard API for thread-related functions in Unix/Linux operating systems. The function is defined in the <pthread.h> header file.

    ```c
    int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
    ```
    ```
    -- thread: A pointer to an unsigned integer value where the thread ID of the created thread will be stored.

    -- attr: A pointer to a pthread_attr_t structure that defines thread attributes such as the detached state, 
            scheduling policy, stack address, etc. If set to NULL, default thread attributes are used.

    -- start_routine: A pointer to the function that the new thread will execute. The function must have a 
                    return type of void * and take a single void * argument. If multiple values need to be 
                    passed to the function, a struct must be used.

    -- arg: A pointer to void that contains the arguments to be passed to the start_routine function.
    ```

    Example:
    ```c
    #include <pthread.h>
    #include <stdio.h>
    #include <stdlib.h>

    // Function to be executed by the new thread
    void *print_message_function(void *ptr) {
        char *message;
        message = (char *) ptr;
        printf("%s \n", message);
        return NULL;
    }

    int main() {
        pthread_t thread1, thread2;
        char *message1 = "Thread 1";
        char *message2 = "Thread 2";

        // Create the first thread
        pthread_create(&thread1, NULL, print_message_function, (void*) message1);
        // Create the second thread
        pthread_create(&thread2, NULL, print_message_function, (void*) message2);

        // Wait for both threads to finish
        pthread_join(thread1, NULL);
        pthread_join(thread2, NULL);

        return 0;
    }
    ```

    In this example, two threads are created, each executing the print_message_function with different messages. The pthread_join function is used to wait for both threads to finish before the main thread exits. If you do not use ```pthread_join``` at the end of a program that creates threads, the main thread will terminate, and the child threads will continue running independently. This can lead to several issues, such as memory leaks or unexpected behavior.

- pthread_detach

    The pthread_detach function in C is used to mark a thread as detached, indicating that the system can automatically release the thread's resources when the thread terminates. This is an alternative to using pthread_join to wait for a thread to finish and collect its return value. The function is defined in the ```<pthread.h>``` header file and has the following syntax:

    ````c
    int pthread_detach(pthread_t thread);
    ````

    ```thread``` here is the id of the thread we want to detach. 

    The function returns 0 on success, indicating that the thread has been successfully marked as detached. If the thread is already detached or if tid does not identify a valid, undetached thread in the current process, the function returns an error number.

    Detaching a thread means that the system knows it can immediately free the resources associated with the thread once it terminates, without needing to wait for another thread to join with it. This is useful in scenarios where you want to start a thread and let it run independently, without needing to explicitly wait for it to finish. However, once a thread has been detached, it cannot be joined with pthread_join or made joinable again.

    It's important to note that detaching a thread does not prevent it from being terminated if the process terminates, either through calling exit or by the main thread returning. All threads in a process are terminated when the process ends, regardless of whether they are detached or joinable.

- pthread_join
    ```c
    int pthread_join(pthread_t thread, void **retval);
    ```

    The pthread_join function in C is used to wait for a specific thread to finish its execution before continuing with the rest of the program. It is part of the POSIX thread (pthread) standard API for thread-related functions in Unix/Linux operating systems. The function is defined in the <pthread.h> header file.


    - ```thread```: This is the thread ID of the thread for which the calling thread waits. It is the identifier returned by pthread_create when the thread was created.
    - ```retval```: This is a pointer to a location where the exit status of the thread specified by ```thread``` is stored. If the thread has not been joined before it terminates, the value pointed to by thread_return is set to the value returned by pthread_exit from the thread. If the thread has not been joined before it terminates, the value pointed to by thread_return is set to NULL.

    The pthread_join function blocks the calling thread until the specified thread terminates. If the thread has already terminated, pthread_join returns immediately. This function is particularly useful in scenarios where the result of a thread's execution is needed by another part of the program, or when you simply want to ensure that a thread has finished its work before continuing.

- pthread_mutex_init
    ```c
    int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
    ```

    The pthread_mutex_init function in C is used to initialize a mutex object with the default attributes or with the attributes specified in the pthread_mutexattr_t structure. It is part of the POSIX thread (pthread) standard API for thread-related functions in Unix/Linux operating systems. The function is defined in the ```<pthread.h>``` header file.

- pthread_mutex_destroy

    If a mutex has been previously initialized, the pthread_mutex_destroy function has to be used to destroy the mutex object and release any resources associated with it. The function is defined in the ```<pthread.h>``` header file and has the following syntax:

    ```c
    int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
    ```

- pthread_mutex_lock
    ```c
    int pthread_mutex_lock(pthread_mutex_t *mutex);
    ```

    The pthread_mutex_lock function in C is used to lock a mutex object, preventing other threads from accessing the shared resource protected by the mutex. It is part of the POSIX thread (pthread) standard API for thread-related functions in Unix/Linux operating systems. The function is defined in the ```<pthread.h>``` header file.

- pthread_mutex_unlock
    ```c
    int pthread_mutex_unlock(pthread_mutex_t *mutex);
    ```

    The pthread_mutex_unlock function in C is used to unlock a mutex object that was previously locked by the calling thread. (etc. same header)

## Additional info :

***Compilation option***

When compiling a program that uses pthreads, you need to link the pthread library using the ```-pthread``` flag. This option tells the compiler to link the program with the pthread library, which provides the necessary functions and data structures for working with threads.

***The difference between detaching a thread and making it joinable lies in how the system manages the thread's resources and how you interact with the thread's termination status.***

**Detaching a Thread**

- Automatic Resource Release: When a thread is detached, the system automatically releases the thread's resources when the thread terminates. This means you don't need to explicitly wait for the thread to finish using pthread_join.
No Access to Termination Status: Once a thread is detached, you cannot retrieve its termination status using pthread_join. This is because the system has already released the thread's resources, and the thread's exit status is lost.

- Cannot Be Joined Again: A detached thread cannot be made joinable again. If you need to wait for a thread to finish or retrieve its termination status, you must do so before detaching the thread.

**Making a Thread Joinable**

- Manual Resource Management: Joinable threads require explicit management of their resources. You must use pthread_join to wait for the thread to finish and to retrieve its termination status.
Access to Termination Status: With joinable threads, you can use pthread_join to wait for the thread to finish and to retrieve its exit status. This is useful for synchronizing threads or for cleaning up resources based on the thread's completion status.
- Can Be Joined Multiple Times: A joinable thread can be joined multiple times, but only the first join operation will succeed. Subsequent attempts to join the same thread will fail.

**Choosing Between Detaching and Joining**

- Use Detaching when you don't need to wait for the thread to finish or retrieve its termination status. This is useful for background threads that perform tasks independently of the main thread.
- Use Joining when you need to synchronize threads, clean up resources based on thread completion, or retrieve the thread's exit status. Joinable threads give you more control over thread management but require explicit handling of thread resources.

***In summary, detaching a thread simplifies resource management by automatically releasing the thread's resources upon termination, at the cost of losing access to the thread's exit status. Making a thread joinable allows for more complex interactions with the thread, such as waiting for its completion or retrieving its exit status, but requires explicit management of the thread's resources***

**Valgrind flags**

The --tool=helgrind and --tool=drd flags in Valgrind are used to specify which tool should be used for analyzing multi-threaded programs. Both tools are designed to detect issues related to thread synchronization, such as race conditions and deadlocks, but they differ in their approach and output.

**Helgrind**: This tool is specifically designed to detect data races and deadlocks in multi-threaded programs. It operates by recording memory access ordering and thread locking information. Helgrind is particularly useful for detecting race conditions where multiple threads access shared data concurrently without proper synchronization. It requires explicit specification via the --tool=helgrind flag when running Valgrind. Helgrind is known for producing output that is easier to interpret, making it a preferred choice for many developers when dealing with thread-related issues 12.*

**DRD (Data Race Detector)**: Similar to Helgrind, DRD is designed to detect data races and deadlocks in multi-threaded applications. However, DRD tends to have better performance compared to Helgrind, making it a suitable choice for larger or more complex applications where performance is a concern. Like Helgrind, DRD also records memory access ordering and thread locking information to detect potential synchronization issues. The --tool=drd flag is used to specify DRD when running Valgrind. While both tools perform substantially the same work, the choice between them often comes down to the specific needs of the project, such as the preference for easier-to-read output (Helgrind) versus better performance (DRD) 2.

In summary, both Helgrind and DRD are powerful tools within Valgrind for diagnosing thread-related issues in multi-threaded applications. The choice between them depends on the developer's preference for output readability versus performance.

## Useful links

- [Playlist de Code Vault sur les threads](<https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2>)
- [Wikipedia au sujet du problème des Dining Philosophers](<https://en.wikipedia.org/wiki/Dining_philosophers_problem>)
- [Vidéo de Neso Academy pour le problème des Dining Philosophers](<https://www.youtube.com/watch?v=FYUi-u7UWgw>)
- [En cherchant, j'étais tombé sur un cours au sujet du problème et de ses résolutions](<https://web.eecs.utk.edu/~jplank/plank/classes/cs360/360/notes/Dphil/lecture.html>)
- [Multiples ressources about 42 in general](https://github.com/jotavare/42-resources?tab=readme-ov-file)