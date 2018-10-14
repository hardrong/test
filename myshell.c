#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
char *argv[8];
int argc = 0;
void do_parse(char *buf)
{
  int i;
  int status = 0;
  for(argc=i=0;buf[i];i++)
  {
    if(!isspace(buf[i]) && status == 0)
    {
      argv[argc++] = buf+i;
      status = 1;
    }
    else if(isspace(buf[i]))
    {
      status = 0;
      buf[i] = 0;
    }
  }
  argv[argc] = NULL;
}
void do_execute(void)
{
  int st;
  pid_t pid =fork();
  if(pid == -1)
  {
    exit(EXIT_FAILURE);
    
  }
  else if(pid > 0)
  {
    wait(&st);
  }
  else if(pid == 0)
  {
    execvp(argv[0],argv);
  }
}
int main()
{
  while(1)
  {
    char buf[1024] = {};
    printf("[gxr@localhost code]#");
    scanf("%[^\n]%*c",buf);
    do_parse(buf);
    do_execute();
  }
  return 0;
}
