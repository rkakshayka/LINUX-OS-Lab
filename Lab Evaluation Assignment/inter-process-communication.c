#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<string.h> 
int main()

  {
       FILE *rd;
       char buffer[50];
       sprintf(buffer,"AKSHAY KAUSHIK");
       rd=popen("wc -c","w"); 
             // wc -c -> is the process which counts the number of characters passed.     
            // 2nd parameter is "w" which means pipe is opened in writing mode.
                                            
       fwrite(buffer,sizeof(char),strlen(buffer),rd); 
                 // to write the data into the pipe
        pclose(rd);
  }
