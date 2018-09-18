#include<stdio.h>
#include<stdlib.h>
int oncesort(int *arr,int n,int start,int end)
{ 
     int i = 0;
     int index = 0;
	 int small =start -1;
	 int tmp = 0;
	 index = rand()%n;
     while(index < start || index>end)
   index =	rand()%n;
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
		tmp = arr[small];
		arr[small] =arr[end];
		arr[end] = tmp;

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

    return 0;
}
