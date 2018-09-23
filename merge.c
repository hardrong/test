#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void merge(int*arr,int start1,int end1,int start2,int end2,int *tmp)
{
  int ret = start1;

    int index = start1;
   while(start1 <= end1 && start2 <= end2)
   {
       if(arr[start1] < arr[start2])
        {
		  tmp[index++] = arr[start1++];
		  }
		  else
		  tmp[index++] = arr[start2++];
	}

	 while(start1 <= end1)
	 {
	     tmp[index++] = arr[start1++];
     }
	  while(start2 <= end2)
	  {
	     tmp[index++] = arr[start2++];
	  }
   memcpy(arr+ret,tmp+ret,sizeof(int)*((end2-ret)+1));
}
void mergesort(int *arr,int start,int end,int *tmp)
{
  int mid = start+((end-start)>>1);
  
   if(start == end)
   return;
   mergesort(arr,start,mid,tmp);
   mergesort(arr,mid+1,end,tmp);
   merge(arr,start,mid,mid+1,end,tmp);
}
int main()
{
    int array[] = {9,7,5,26,34,26,16,3,8,0};
      int sz = sizeof(array)/sizeof(array[0]);
       int i =0; 
	   int *tmp = (int *)malloc(sizeof(int)*10);
	 mergesort(array,0,sz-1,tmp);
	 
	 for(i=0; i<sz; i++)
	 {
	    array[i] = tmp[i];
	    printf("%d ",array[i]);
	}
		printf("\n");
 free(tmp);
 tmp = NULL;
    return 0;
}
