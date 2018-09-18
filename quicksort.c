#include<stdio.h>
#include<time.h>
#include<stdlib.h>
  int oncesort(int *arr,int n,int start,int end)
{ 
     int i = 0;
     int index = rand()%10;
	 int small = start-1;
	 int tmp = 0;
	 int ret = 0;
	 while(index < start || index>end)
      index =rand()%10;
	 tmp = arr[index];
	 arr[index] = arr[end];
	 arr[end] = tmp;
	 for(i=start; i<end; i++)
	 {
	      if(arr[i] < arr[end])
		  {
		     ++small;
			 if(small != i)
			  {
			 int  temp = arr[small];
			   arr[small] = arr[i];
			   arr[i] = temp;
			   }
			   }
		}
		++small;
		ret = arr[small];
		arr[small] =arr[end];
		arr[end] = ret;

		return small;

  }  
void sort(int *arr,int sz,int start,int end)
{
int index = 0;
   if(start == end)
   return;
   index = oncesort(arr,sz,start,end);
    if(index>start)
	 sort(arr,sz,0,index-1);
	 if(index < end)
	 	   sort(arr,sz,index+1,end);
     
	}
int main()
{
    int array[] = {9,7,5,26,34,26,16,3,8,0};
     int sz = sizeof(array)/sizeof(array[0]);
   
   int i =0;
   srand((unsigned)time( NULL)); 
	 sort(array,sz,0,sz-1);
	 for(i=0; i<sz; i++)
	 {
	    printf("%d ",array[i]);
		}
		printf("\n");

	 system("pause");
	 return 0;
	 }
