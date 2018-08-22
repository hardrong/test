#include"priority.h"

void PriorityQueueInit(PriorityQueue* q)
{
	int i = 0;
	assert(q);
	q->_size = 11;
	q->_a[0] = 10; 
	q->_a[1] = 11; 
	q->_a[2] = 13; 
	q->_a[3] = 12; 
	q->_a[4] = 16; 
	q->_a[5] = 18; 
	q->_a[6] = 15; 
	q->_a[7] = 17; 
	q->_a[8] = 14; 
	q->_a[9] = 19; 
	q->_a[10] = 0;

}
void AdjustDown(PriorityQueue* q, int n, int root) 
{
	int child =  (root*2+1);
	while( child < n )
	{
		
		 if( q->_a[child+1] > q->_a[child] && child+1 <n)
		 {
			 ++child;
		 }
       
		if(q->_a[root] < q->_a[child])
		{
			 int tmp = q->_a[child];
			q->_a[child] = q->_a[root];
			 q->_a[root] = tmp;
           root = child;
		   child =  (root*2+1);
		}
		else
			break;
		     
	}
}
void MakeHeap(PriorityQueue* q, int b,int n) 
{
	int parent = b;
	 int child = parent*2+1;

	 while(child < n)
	 {
		 if( q->_a[child+1] > q->_a[child] && child+1 <n)
		 {
			 ++child;
		 }
		 if( q->_a[parent] <q->_a[child])
		 {
			 int tmp = q->_a[parent];
			q->_a[parent] = q->_a[child];
			 q->_a[child] = tmp;
              parent = child;
		     child = parent*2+1;
		 }
		 else
			 break;
	 }
}
void AdjustUp(PriorityQueue* q, int n, int child) 
{
	int parent = 0;
	while( child > 0 )
	{
		parent =  (child-1)/2;
		
		 if( q->_a[child+1] > q->_a[child] && child+1 <n)
		 {
			 ++child;
		 }
		if(q->_a[child] > q->_a[parent])
		{
			 int tmp = q->_a[parent];
			q->_a[parent] = q->_a[child];
			 q->_a[child] = tmp;
             child = parent;
		}
		else
			break;
		     
	}
}
// topk 最大的前K 
void TopK(PriorityQueue* q, int n, size_t k) 
{
	size_t parent = n;
	int c = 10;
	int child = parent*2+1;
	int i = 0;
	for(i=k; i>0; i--)
	{
	 while(child < i)
	 {
		 if( q->_a[child+1] < q->_a[child] && child+1 <i)
		 {
			 ++child;
		 }
		 if( q->_a[parent] <q->_a[child])
		 {
			 int tmp = q->_a[parent];
			q->_a[parent] = q->_a[child];
			 q->_a[child] = tmp;
              parent = child;
		     child = parent*2+1;
		 }
		 else
			 break;
	 }
	}
	while(c--)
	{
	if(q->_a[k+1] > q->_a[0] )
	{
		PriorityQueuePush(q,q->_a[k+1]);
	}
	k++;
	}
	
}


void PriorityQueuePush(PriorityQueue* q, DataType x)
{
	int child = 0;
	int parent = 0;
	q->_a[q->_size-1] = x;
	

	child = q->_size-1;
	parent =  (child-1)/2;
	while( child > 0)
	{
		parent =  (child-1)/2;
		if(q->_a[child] > q->_a[parent])
		{
			 int tmp = q->_a[parent];
			q->_a[parent] = q->_a[child];
			 q->_a[child] = tmp;
             child = parent;
		}
		else
			break;
		     
	}
	
}
void PriorityQueuePop(PriorityQueue* q)
{
	int tmp = q->_a[0];
	q->_a[0] = q->_a[10] ;
	q->_a[10] = tmp;
	
	 AdjustDown(q,10,0);
}
DataType PriorityQueueTop(PriorityQueue* q); 
size_t PriorityQueueSize(PriorityQueue* q); 
size_t PriorityQueueEmpty(PriorityQueue* q); 
void HeapSort(PriorityQueue* q, int n)
{
	while(n >0)
	{
	 int root = 0;
	int child =  (root*2+1);
	 int tmp = q->_a[0];
	q->_a[0] = q->_a[n] ;
	q->_a[n] = tmp;
	n--;
	while( child < n )
	{
		
		 if( q->_a[child+1] > q->_a[child]  && child+1 <= n)
		 {
			 ++child;
		 }
       
		if(q->_a[root] < q->_a[child])
		{
			 int temp = q->_a[child];
			q->_a[child] = q->_a[root];
			 q->_a[root] = temp;
           root = child;
		   child =  (root*2+1);
		}
		else
			break;
		     
	}
	
	}

}
void TestPriorityQueue() 
{
	int i = 0; 
	int j = 0;
	PriorityQueue q;
	PriorityQueueInit(&q);
	 for( i=10; i>=0; i--)
	 {
		 MakeHeap(&q, i,10); 
	 }
	 //PriorityQueuePush(&q,20);
	// PriorityQueuePop(&q);
	//HeapSort(&q,10);
	 TopK(&q,0,3);
	 for(j = 0; j<11; j++)
	 {
	 printf("%d ",q._a[j]);
	 }
  
}
