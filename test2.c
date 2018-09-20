#include<stdio.h>
void sort(int *arr,int sz)
{
      int i =0;
	  int j = 0;
	  for(i=0; i<sz; i++,sz--)
	  {
	  int min = i;
	  int max = sz-1;
	  int tmp = 0;
	  int ret = 0;
	      for(j=i; j<sz; j++)
		  {
		     if(arr[j] < arr[min])
			  {
                 min = j;
			  }
			  if(arr[j] > arr[max])
			  max = j;
		 }
		  tmp = arr[i];
		  ret = arr[sz-1];
             arr[i] = arr[min];
			 arr[min] = tmp;
			 arr[sz-1] = arr[max];
			 arr[max] = ret;

	}
		     
 }
int main()
{
    int array[] = {9,8,7,6,5,4,3,2,10,27};
	int sz = sizeof(array)/sizeof(array[0]);
    int i = 0;
	sort(array,sz);
	for(i=0; i<sz; i++)
	{
	    printf("%d ",array[i]);
	}
	 printf("\n");

	 return 0;
	 }
