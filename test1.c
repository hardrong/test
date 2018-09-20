#include<stdio.h>
void quik(int array[],int sz)
{
     int *arr = array;
       int grep = sz;
       int start = 0;
	   int end = sz-1;
	   int i = 0;
	   while(grep > 3)
	   {
	   grep = grep/3;
	   for(start = 0; start<end; start+= grep)
	   {
	     
	        for(i=start; i>=0; i-= grep)
			{
			int tmp = 0;
			    if(arr[i+grep] < arr[i])
				 {
				    tmp = arr[i];
					arr[i] = arr[i+grep];
					arr[i+grep] = tmp;
					}
		   }
		}
             
	     grep = 1;
	   for(start = 0; start<end; start+= grep)
	   {
	     
	        for(i=start; i>=0; i-= grep)
			{
			int tmp = 0;
			    if(arr[i+grep] < arr[i])
				 {
				    tmp = arr[i];
					arr[i] = arr[i+grep];
					arr[i+grep] = tmp;
					}
		   }
		}
		}

}
int main()
{
      int i = 0;
     int array[10] = {3,5,2,18,6,2,9,0,11,14};
	 int sz = sizeof(array)/sizeof(array[0]);
	 quik(array,sz);
	 for(i=0; i<sz; i++)
	 {
	     printf("%d ",array[i]);
		 }
		 printf("\n");
       return 0;
}
