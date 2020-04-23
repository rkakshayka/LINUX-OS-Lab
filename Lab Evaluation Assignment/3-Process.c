#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()

{
    pid_t pid1, pid2, pid3;
    printf("Parent of all : %d\n", getpid());
    pid1 = fork();//creates duplicates process
    if (pid1 == 0)
     {
        printf("I'm Child having id: %d and my Parent id is : %d\n", getpid(), getppid());
        pid2 = fork();
        if (pid2 == 0)
         {
           printf("I'm Child having id: %d and my Parent id is : %d\n", getpid(), getppid());
         }
     }
  for (int i = 0; i < 3; i++)
    wait(NULL);
}
