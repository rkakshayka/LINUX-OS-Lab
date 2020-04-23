#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main()
    {
      int n,off,fd;
      char Buff[100];
      printf("Write Somthing in the file\n",Buff);
      fd=open("Ak1File",O_CREAT|O_RDWR,0777);
      n=read(0,Buff,100);
       // parameters inside read(file descriptor, buffer for storing the input, max possible)
      write(fd,Buff,n); 
      read(n,Buff,8);//reading from file
      write(1,Buff,8);//writing into the file
      printf("\nFirst 8 character of the file has been read.\n");
    }

