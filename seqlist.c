#include"seqlist.h"

void InitSeqList(PSeqList pSeq)
{
	assert(pSeq!=NULL);
	memset(pSeq->elem,0,sizeof(pSeq->elem));
	pSeq->sz = 0;
}
void PushBk(PSeqList pSeq, DataType data)
{
	assert(pSeq != NULL);
	if(pSeq->sz == MAXSIZE)
	{
		printf("顺序表已满\n");
		return ;
	}
	pSeq->elem[pSeq->sz] = data;
	pSeq->sz++;
}
void PopBack(PSeqList pSeq)
{
	assert(pSeq != NULL);
	if(pSeq->sz  == 0)
	{
		printf("顺序表已空\n");
		return ;
	}
	pSeq->sz--;
}

void PushFront(PSeqList pSeq, DataType data)
{
	int i = 0;
	assert(pSeq != NULL);
	if(pSeq->sz == MAXSIZE)
	{
		printf("顺序表已满\n");
		return ;
	}
	for(i=pSeq->sz; i>0; i--)
	{
		pSeq->elem[i] = pSeq->elem[i-1];
	}
	pSeq->elem[0] = data;
	pSeq->sz++;
}

void PopFront(PSeqList pSeq)
{
	int i = 0;
	assert( pSeq != NULL);
	if(pSeq->sz == 0)
	{
		printf("顺序表为空");
		return ;
	}
	for(i=0; i<pSeq->sz-1; i++)
	{
		pSeq->elem[i] = pSeq->elem[i+1];
	}
	pSeq->sz--;
}
int Find(PSeqList pSeq, DataType data)
{
	int i = 0;
	assert(pSeq != NULL);
	for(i=0; i<pSeq->sz; i++)
	{
		if(pSeq->elem[i] == data)
			return i;
	}
	return 0;
}
void Insert(PSeqList pSeq, int pos, DataType data)
{
	int i = 0;
	assert(pSeq != NULL);
     if(pos>pSeq->sz-1 || pos<0)
	 {
		 printf("插入位置错误\n");
		 return;
	 }
	 for(i=pSeq->sz-1; i>=pos ;i--)
	 {
		 pSeq->elem[i+1] = pSeq->elem[i];
	 }
	 pSeq->elem[pos] = data;
	 printf("插入成功\n");
}
void Erase(PSeqList pSeq, int pos)
{
	int i = 0;
	assert(pSeq != NULL);
	if(pos>=pSeq->sz || pos<0)
	{
		printf("位置错误\n");
		return;
	}
	for(i=pos; i<pSeq->sz-1; i++)
	{
		pSeq->elem[i] =pSeq->elem[i+1];
	}
	pSeq->sz--;
}
void Remove(PSeqList pSeq, DataType data)
{
	int i = 0;
	int ret = 0;
	assert(pSeq != NULL);
	ret = Find(pSeq,data);

	if(ret != 0)
		Erase(pSeq,ret);
	else
	  printf("没有该元素\n");
}

void RemoveAll(PSeqList pSeq, DataType data)
{
	int i = 0;
	int count = 0;
	assert(pSeq != NULL);
	for(i=0; i<pSeq->sz; i++)
	{
		if(pSeq->elem[i] == data)
		{
			i++;
			pSeq->sz--;
		}
		pSeq->elem[count] = pSeq->elem[i];
		count++;
	}
}

int Size(PSeqList pSeq)
{
	assert(pSeq != NULL);
	return pSeq->sz;
}
int Empty(PSeqList pSeq)
{
	
	if(pSeq->sz == 0)
		return 0;
	return 1;
}
static void swap(DataType *arr,DataType *src)
{
	DataType tmp = *arr;
	*arr = *src;
	*src = tmp;
}
void BubbleSort(PSeqList pSeq)
{
	int i = 0;
	int j = 0;
	assert( pSeq!= NULL);
	for(i=0; i<pSeq->sz-1; i++)
	{
		int flag = 0;
		for(j=0; j<pSeq->sz-1-i; j++)
		{
			if(pSeq->elem[j] > pSeq->elem[j+1])
				swap(pSeq->elem+j,pSeq->elem+j+1);
		     flag = 1;
		}
		if(flag == 0)
			return ;
	}
}

void SelectSort(PSeqList pSeq)
{
	int i = 0;
	int j = 0;
	assert( pSeq!=NULL);
	for(i=0; i<pSeq->sz-1; i++)
	{
		int max = 0;
		for(j=1; j<pSeq->sz-i; j++)
		{
			if(pSeq->elem[j]>pSeq->elem[max])
				max = j;
		}
		if(max != pSeq->sz-1-i)
		{
			swap(pSeq->elem+max,pSeq->elem+j-1);
		}
	}
}

    
void SelectSortOP(PSeqList pSeq)
{
	int start =0;
	int end = pSeq->sz-1;
	int i = 0;
	assert( pSeq != NULL);
	while(start<end)
	{
		int max = end;
		int min = start;
		for(i=start; i<=end; i++)
		{
			if(pSeq->elem[max] <pSeq->elem[i])
				max = i;
			if(pSeq->elem[min] >pSeq->elem[i])
			    min = i;
		}
		if(min != start)
			swap(pSeq->elem+min,pSeq->elem+start);
		if( pSeq->elem[max] == pSeq->elem[start])
			max = min;
		if(max != end)
			swap(pSeq->elem+max,pSeq->elem+end);
		start++;
		end--;
	}
}
int BinarySearch(PSeqList pSeq, DataType data)
{
	int left = 0;
	int right = pSeq->sz-1;
	assert(pSeq != NULL);
	 while(left<=right)
	 {
		 int mid = left+(right-left)/2;
		 if(pSeq->elem[mid] == data)
		 {
			 return 0;
		 }
		 if(pSeq->elem[mid]<data)
			 left = mid+1;
		 if(pSeq->elem[mid] >data)
			 right = mid-1;
	 }
	 return 1;
}

int BinarySearch_R(PSeqList pSeq, int left, int right, DataType d)
{
	int mid = 0;
	if(left>right)
		return 1;
	 mid = left+(right-left)/2;
	if(pSeq->elem[mid] == d)
		return  0;
	if(pSeq->elem[mid]>d)
		BinarySearch_R(pSeq,left,mid-1,d);
	if(pSeq->elem[mid]<d)
		BinarySearch_R(pSeq,mid+1,right,d);

}
void PrintSeqList(PSeqList pSeq)
{
	int i = 0;
	assert(pSeq != NULL);
	for(i=0; i<pSeq->sz; i++)
	{
		printf("%d",pSeq->elem[i]);
	}
	printf("\n");
}
