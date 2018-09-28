#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{

   int ret = fork();
   if(ret == 0)
   {
       printf("i am  a child :%d\n",getpid());
	   sleep(3);
	   exit(24);
	}
	else
	{
	     int status;
		if(ret == wait(&status))
		 printf("sucess\n");
		 
	     printf("i am a parent %d\n",getpid());
       }  
  return 0;

}
