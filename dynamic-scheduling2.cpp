#include <pthread.h>
#include <iostream>
#include <unistd.h>

using namespace std;
#define NUM_THREADS 1000

int sharedData = 0;

void* incrementData(void* arg)
{
sharedData++;
pthread_exit(NULL); 
}

int main()
{
pthread_t threadID[NUM_THREADS];

for (int counter=0; counter<NUM_THREADS;counter++) {
pthread_create(&threadID[counter], NULL, incrementData, NULL);

}
//waiting for all threads

for (int counter=0; counter<NUM_THREADS;counter++) {
pthread_join(threadID[counter], NULL);
}

cout << "ThreadCount:" << sharedData <<endl;
pthread_exit(NULL);
}