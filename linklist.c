#include"linklist.h"

void InitLinkList(pList* pplist)
{
	assert(pplist != NULL);
	*pplist = NULL;
}
pNode BuyNode(DataType d)
{
	pNode tmp = (pNode)malloc(sizeof(Node));
	tmp->data = d;
	tmp->next = NULL;
	return tmp;
}
void DestroyLinkList(pList* pplist)
{
	pNode del = NULL;
	assert(pplist != NULL);
	if((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	    return ;
	}
	else
	{
		while(*pplist != NULL)
		{
			del = *pplist;
			*pplist = (*pplist)->next;
			free(del);
			del = NULL;
		
		}
	}
	pplist = NULL;
}
void PrintLinkList(pList plist)
{
	while(plist)
	{
		printf("%d \n",plist->data);
		plist = plist->next;
	}

}

void PushBack(pList* pplist, DataType d)
{
	pNode buy = NULL;
	pNode cur = NULL;
	assert(pplist != NULL);
	 buy = BuyNode(d);
	 if(*pplist == NULL)
	 {
	 *pplist = buy;
	   return ;
	 }
	 else
	 {
		 cur = *pplist;
		 while(cur->next != NULL)
		 {
			 cur = cur->next;
		 }
		 cur->next = buy;
	 }

}
void PopBack(pList* pplist)
{
	pList cur = NULL;
	assert(pplist != NULL);
	if(*pplist == NULL)
	{
		return ;
	}
	else
	{
		cur = *pplist;
		while((cur->next->next) != NULL)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}

void PushFront(pList* pplist, DataType d)
{
	pNode buy = NULL;
	assert(pplist != NULL);
	 buy = BuyNode(d);
	if(*pplist == NULL)
	{
		*pplist = buy;
		return;
	}
	else
	{
		buy->next = *pplist;
		*pplist = buy;
	}
}
void PopFront(pList* pplist)
{
	pList cur = NULL;
	assert(pplist != NULL);
	cur = *pplist;
	if(*pplist == NULL)
	{
		return;
	}
	if(cur->next == NULL)
	{
		free(cur);
		cur = NULL;
		*pplist = NULL;
	}
	else
	{
		 *pplist = cur->next;
		 free(cur);
		 cur = NULL;
	}
}
pNode Find(pList* pplist, DataType d)
{
	pNode cur = NULL;
	assert(pplist != NULL);
	cur = *pplist;
		while(cur)
		{
			if((cur)->data == d)
			{
				return cur;
			}
			cur = cur->next;
		}
		return NULL;
}


void Insert(pList* pplist, pNode pos, DataType d)
{
	pNode buy = NULL;
	pNode cur = NULL;
	pNode rel = NULL;
	assert(pplist != NULL);
	if(*pplist == NULL)
	{
		return ;
	}
	else
	{
		cur = *pplist;
		while(cur && cur != pos )
		{
			rel = cur;
			cur = cur->next;
		}
		if(cur == NULL)
			return;
		else
		{
			buy = BuyNode(d);
			buy->next = pos;
			rel->next = buy;
		}

	}
}
void Erase(pList* pplist, pNode pos)
{
	pList del = NULL;
	pList cur = NULL;
	assert(pplist != NULL);

	if(*pplist == pos)
	{
		free(pos);
	    *pplist = NULL;
	}
	else
	{
		del = *pplist;
		while(del && del != pos)
		{ 
			cur = del;
           del = del->next;
		}
		if(del == NULL)
			return;
		if(del->next == NULL)
		{
			free(pos);
			pos = NULL;
			cur->next = NULL;
		}
		else
		{
			cur->next = cur->next->next;
			free(pos);
			pos = NULL;
			del = NULL;
		}
	}
}

void Remove(pList* pplist, DataType d)
{
	pNode pos = NULL;
	assert(pplist != NULL);

    pos = Find(pplist,d);
	  if(pos != NULL)
		  Erase(pplist,pos);

}

void RemoveAll(pList* pplist, DataType d)
{
	pNode pos = NULL;
	assert(pplist != NULL);

   while( pos = Find(pplist,d))
		  Erase(pplist,pos);

}
void EraseNotTailNode(pNode pos)
{
	pNode rel = NULL;
	assert(pos != NULL);
	
	pos->data = pos->next->data;
	pos->next = pos->next->next;
	rel = pos->next;
	free(rel);
    rel = NULL;
}
int GetListLength(pList plist)
{
	int count = 0;
	while(plist)
	{
		plist = plist->next;
		count++;
	}
	return count;
}
void PrintTailToHead(pList plist)
{
	pNode end = NULL;
	if(plist == NULL)
		return ;
	else
	{
		while(end != plist)
		{
	      pNode cur = plist;

		while(cur->next != end)
		{
			cur = cur->next;
		}
			end = cur;
			printf("%d ",end->data);
		}
			printf("\n");

	}
}
void EraseNotTail(pList pos)
{
	if(pos == NULL)
	{
		return ;
	}
	pos->data = pos->next->data;
	pos->next = pos->next->next;
    
	free(pos->next);

}
void InsertNode(pList pos,int d)
{
	pNode ret = NULL;
	if(pos == NULL)
		return;
	ret = BuyNode(pos->data);
	pos->data = d;
	ret->next = pos->next;
	pos->next = ret;

}
pNode JosephCycle(pList * pplist, int num)
{
	pNode cur = NULL;
	int count = 0;
	assert(pplist);
	if((*pplist) == NULL)
		return NULL;
	cur = *pplist;
	while(cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = *pplist;
	
	while(cur->next != cur)
	{
		pNode ret = NULL;
		cur = cur->next;
		count++;
		while(count == num)
		{
			  ret = cur->next;
			cur->data = ret->data;
			cur->next = ret->next;
			count = 1;
			free(ret);
		}
	}
	return cur;
}
void ReverseList(pList* pplist) 
{
	//3个指针，记录前一个，当前，后一个
	/*pList cur = *pplist;
	pList mid = NULL;
	pList end = NULL;
	assert(pplist != NULL);

	if(*pplist == NULL)
		return;
	mid = cur->next;
	cur->next =NULL;
	while(mid != NULL)
	{
		end = mid->next;
		mid->next = cur;
		cur = mid;
		mid = end;
		
	}
	*pplist = cur;*/
    //	头插法
	// 把每个节点都头插到新的链表上
	pList cur = (*pplist)->next;
	pList behind = NULL;
	assert(pplist);
	(*pplist)->next= *pplist;
	while(cur)
	{
		behind = cur;
		cur = cur->next;
		behind->next = (*pplist)->next;
		(*pplist)->next = behind; //每次更新第一个节点的next，继续头插
	}
	if((*pplist) != NULL)
	{
	(*pplist)->next = NULL;
	*pplist = behind;
	}
}
void BubbleSort(pList * pplist)
{
	pList start = *pplist;
	int d = 0;
	pList  end = NULL;
	assert(pplist);
	 while(start->next != NULL)
	 {
		 start = start->next;
	 }
	 end = start;
	 //末指针走到最前面
	 while(end != *pplist)
	 {
		 pList cur = *pplist;
		 pList ret = NULL;
		 while(cur != end)
		 {
			 if(cur->data > cur->next->data)
			 {
				 d = cur->data;
				 cur->data = cur->next->data;
				 cur->next->data = d;
			 }
			 ret = cur; 
			 cur = cur->next;
		 }
		 end = ret;
	 }
}
pNode Merge_R(pList list1, pList list2)
{
	//非递归，先找出一个较小的，利用尾插法排序
	pList cur = NULL;
	if(list1 == NULL)
		return list2;
	if(list2 == NULL);
	return list1;

	if(list1->data <list2->data)
	{
		cur = list1;
	}
	else
	{
		list1 = list2;
		list2 = cur;
	}
	while(cur)
	{
		pList ret = NULL;
		if(cur->next < list2 )
		{
			ret = list2->next;
			list2->next = cur->next;
			cur->next = list2;
			cur = list2;
			list2 = ret;
		}
		else
			cur = cur->next;
	}
	return list1;

}
pNode FindMidNode(pList head)
{
	pList behind = head;
	pList front = head;
	if(head == NULL)
		return NULL;
	while( behind && behind->next != NULL)
	{
		
		behind = behind->next->next;
		front = front->next;
	}
	return front;
}
pList FindLastKNode(pList *pplist, int k)
{
	pList front = NULL;
	pList behind = NULL;
	assert(pplist);
	assert(*pplist);
	front = *pplist;
	behind = *pplist;
	while(k--)
	{
		front = front->next;
		if(front == NULL)
			return NULL;
	}
	while(front != NULL)
	{
		front = front->next;
		behind = behind->next;
	}
	return behind;
}
pNode PPlist(pList plist,pList pos)
{
	pList cur = plist;
	pList front = NULL;
	pList behind = NULL;
	assert(plist);
	while(cur->next != NULL)
	{
		cur =cur->next;
	}
	cur->next = pos;
	/*front = plist;
	if(plist->next == NULL)
		return NULL;
	else
	behind = plist->next->next;
	while(behind != front)
	{
		behind = behind->next->next;
		front = front->next;
		if( behind && behind->next == NULL )
			return NULL;
	}*/
	return plist;


}
pNode CheckCycle(pList plist)
{
	pList behind = NULL;
	pList front = NULL;
	front = plist;
	if(plist->next == NULL)
		return NULL;
	else
	behind = plist->next->next;
	while(behind != front)
	{
		front = front->next;
		if(front == behind)
			return front;
		behind = behind->next->next;
		
		if( behind && behind->next == NULL )
			return NULL;
	}
	return behind;

}
int GetCircleLength(pNode meet)
{
	pList cur = meet->next;
	int count = 1;
	while(cur != meet)
	{
		++count;
		cur = cur->next;
	}
	
	return count;
}
pNode GetCycleEntryNode(pList list, pList meetNode)
{
	pList  cur = list;
	pList ret = meetNode;

	while(cur != ret)
	{
		cur = cur->next;
		ret = ret->next;
		if(ret == cur)
			return ret;
	}
	return cur;

}


