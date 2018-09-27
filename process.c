#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
     int ret = fork();
	 if(ret == 0)
	 {
	  printf("iam a child %d %d\n",getpid(),ret);
	exit(0);
	  }
	 else if(ret>0)
	 {  
	  printf("i am a parent %d %d my parent: %d\n",getpid(),ret,getppid()); 
	 sleep(30);

	 }
   return 0;
}
