#include <iostream>
#include <stdio.h>
using namespace std;
void Permutation(char *pStr,char *pBegin)
{
  if(*pBegin == '\0')
  {
    printf("%s\n",pStr);
  }
  else 
  {
     for(char * pCh = pBegin; *pCh != '\0';++pCh)
     {
          char temp = * pCh;
          *pCh = *pBegin;
          *pBegin = temp;
          Permutation(pStr,pBegin+1);
          temp = *pCh;
          *pCh = *pBegin;
          *pBegin = temp;
     }
  }
}
void Permutation1(char * pStr)
{
  if(pStr == NULL)
    return ;
  Permutation(pStr,pStr);
}
int main()
{
  char arr[] = "abc";
  Permutation1(arr);
  return 0;
}
