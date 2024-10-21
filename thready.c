// #include <stdio.h>
// #include <math.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <sys/types.h>
// #include <pthread.h>

// void pattern1(int things);
// void pattern2(int things);
// void *threadPattern1(void *arg);
// void *threadPattern2(void *arg);

// int things = 0;
// int threadCount = 1;

// int main(int __argc, char *__argv[])
// {

//     int pattern = 0;

//     if (__argc == 3)
//     {
//         things = atoi(__argv[1]);
//         pattern = atoi(__argv[2]);

//         if (pattern == 1)
//         {
//             pattern1(things);
//         }
//         else if (pattern == 2)
//         {
//             pattern2(things);
//         }
//     }
//     return 0;
// }

// void pattern1(int things)
// {
//     fprintf(stdout, "Pattern 1: creating %d threads\n", things);
//     for (int ix = 1; ix <= things; ix++)
//     {
//         pthread_t thread_id;
//         pthread_create(&thread_id, NULL, threadPattern1, NULL);

//         pthread_join(thread_id, NULL);
//     }

//     fprintf(stdout, "Im at parent and now I am exiting\n");
// }

// void pattern2(int things)
// {
//     fprintf(stdout, "Pattern 1: creating %d threads\n", things);
//     for (int jx = 1; jx <= things; jx++)
//     {
//         pthread_t thread_id;
//         pthread_create(&thread_id, NULL, threadPattern2, NULL);

//         pthread_join(thread_id, NULL);
//     }
//     fprintf(stdout, "Im at parent and now I am exiting\n");
// }

// void *threadPattern1(void *arg)
// {

//     int Min = 1;
//     int Max = 8;
//     int sleepyTime = (rand() % (Max - Min + Min) + Min);
//     fprintf(stdout, "Parent created thread %d (TID %ld)\n", threadCount, pthread_self());
//     fprintf(stdout, "Thread %d (TID %ld) created: will sleep for %d seconds\n", threadCount, pthread_self(), sleepyTime);
//     sleep(sleepyTime);
//     threadCount++;

//     pthread_exit(NULL);
// }

// void *threadPattern2(void *arg)
// {

//     int Min = 1;
//     int Max = 8;
//     int sleepyTime = (rand() % (Max - Min + Min) + Min);
//     if (threadCount + 1 <= things)
//     {
//         fprintf(stdout, "Parent created thread %d (TID %ld)\n", threadCount, pthread_self());
//         fprintf(stdout, "Thread %d created thread %d with TID of %ld\n", threadCount, threadCount + 1, pthread_self());
//         fprintf(stdout, "Thread %d (TID %ld) created: will sleep for %d seconds\n", threadCount, pthread_self(), sleepyTime);

//         sleep(sleepyTime);
//         threadCount++;
//     }

//     pthread_exit(NULL);
// }

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

void pattern1(int things);
void pattern2(int things);
void *threadPattern1(void *arg);
void *threadPattern2(void *arg);

int things = 0;
int threadCount = 1;

int main(int __argc, char *__argv[])
{

    int pattern = 0;

    if (__argc == 3)
    {
        things = atoi(__argv[1]);
        pattern = atoi(__argv[2]);

        if (pattern == 1)
        {
            pattern1(things);
        }
        else if (pattern == 2)
        {
            pattern2(things);
        }
    }
    return 0;
}

void pattern1(int things)
{
    fprintf(stdout, "Pattern 1: creating %d threads\n", things);
    pthread_t thread_id;
    for (int ix = 1; ix <= things; ix++)
    {
        pthread_create(&thread_id, NULL, threadPattern1, NULL);

        pthread_join(thread_id, NULL);
    }

    fprintf(stdout, "Im at parent and now I am exiting\n");
}

void pattern2(int things)
{
    fprintf(stdout, "Pattern 2: creating %d threads\n", things);
    pthread_t thread_id;
    for (int jx = 1; jx <= things; jx++)
    {
        pthread_create(&thread_id, NULL, threadPattern2, NULL);
}
    for(int dx = 1; dx <= things; dx++){
        pthread_join(thread_id, NULL);
    }
    fprintf(stdout, "Im at parent and now I am exiting\n");
}

void *threadPattern1(void *arg)
{

    int Min = 1;
    int Max = 8;
    int sleepyTime = (rand() % (Max - Min + Min) + Min);
    fprintf(stdout, "Parent created thread %d (TID %ld)\n", threadCount, pthread_self());
    fprintf(stdout, "Thread %d (TID %ld) created: will sleep for %d seconds\n", threadCount, pthread_self(), sleepyTime);
    sleep(sleepyTime);
    threadCount++;

    pthread_exit(NULL);
}

void *threadPattern2(void *arg)
{

    int Min = 1;
    int Max = 8;
    int sleepyTime = (rand() % (Max - Min + Min) + Min);
    fprintf(stdout, "Parent created thread %d (TID %ld)\n", threadCount, pthread_self());
    
        fprintf(stdout, "Thread %d created thread %d with TID of %ld\n", threadCount, threadCount + 1, pthread_self());
        fprintf(stdout, "Thread %d (TID %ld) created: will sleep for %d seconds\n", threadCount, pthread_self(), sleepyTime);

        sleep(sleepyTime);
        threadCount++;
    

    pthread_exit(NULL);
}