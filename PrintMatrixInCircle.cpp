#include<iostream>

void PrintMatrix(int **numbers,int columns,int rows,int start)
{
    int endx = columns-1-start;
    int endy = rows -1-start;
  for(int i =0; i <= endx; i++)
  {
      printf("%d\n",numbers[endx][i]);
  }
  if(start < endy)
  {
         for(int j = start+1; j <= endx; j++)
         {
           printf("%d\n",numbers[endy][j]);
         }
  }
  if(start < endy && start < endx)
  {
    for(int i = endx-1; i >= start; i--)
    {
      printf("%d\n",numbers[endy][i]);
    }

  }
  if(start < endx && start < endy-1)
  {
     for(int i = endy-1; i >= start+1; --i)
     {
       printf("%d\n",numbers[i][start]);
     }
  }

}
void PrintMatrixInCirle(int **numbers,int columns,int rows)
{
  if(numbers == NULL || columns <= 0 || rows <= 0)
  {
    return ;
  }
  
  int start = 0;
  while(columns > start *2 && rows > start *2)
  {
    PrintMatrix(numbers,columns,rows,start);
    ++start;
  }
 }
int main()
{
  
  return 0;
}

