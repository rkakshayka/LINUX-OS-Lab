#include<pthread.h>
#include<stdio.h>
void *fun1();
void *fun2();
int shared = 1; //shared variable
int main()
{
pthread_t thread1, thread2;
pthread_create(&thread1, NULL, &fun1, NULL);
pthread_create(&thread2, NULL, &fun2, NULL);
printf("Before Thread Execution value of shared is %d \n",shared);

pthread_join(thread1, NULL);
pthread_join(thread2, NULL);
printf("After Thread Execution value of shared is %d That's final Value \n",shared); 
            //prints the last updated value of shared variable
}

void *fun1()
{
    int a;
    a=shared;//thread one reads value of shared variable
    a=a+1;  //thread one increments its value
    sleep(1);  //thread one is preempted by thread 2
    shared=a; //thread one updates the value of shared variable
}

void *fun2()
{
    int b;
    b=shared;//thread two reads value of shared variable
    b=b-1;  //thread two decrements its value
    sleep(2); //thread two is preempted by thread 1
    shared=b; //thread one updates the value of shared variable
}

