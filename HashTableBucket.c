#include "HashTableBucket.h"

void HTBInit(HTB* htb, size_t len)
{
	assert(htb);
	htb->_len = GetNextPrime(len);
	htb->_size = 0;
	htb->_tables = (HashNode**)malloc(sizeof(HashNode*)*htb->_len);

	memset(htb->_tables, 0, sizeof(HashNode*)*htb->_len);
}

void HTBDestory(HTB* htb)
{
	int i = 0;
	assert(htb);

	for (; i < htb->_len; ++i)
	{
		HashNode* cur = htb->_tables[i];
		while (cur)
		{
			HashNode* next = cur->_next;
			free(cur);

			cur = next;
		}

		htb->_tables[i] = NULL;
	}

	free(htb->_tables);
	htb->_tables = NULL;
	htb->_size = 0;
	htb->_len = 0;
}

size_t HTBHashFunc(HTBKeyType key, size_t len)
{
	//return StrHash(key) % len;
	return key % len;
}

HashNode* BuyHashNode(HTBKeyType key, HTBValueType value)
{
	HashNode* node = malloc(sizeof(HashNode));
	node->_key = key;
	node->_value = value;
	node->_next = NULL;

	return node;
}

void HTBCheckCapacity(HTB* htb)
{
	assert(htb);
	if (htb->_size == htb->_len)
	{
		int i;
		HTB newhtb;
		newhtb._len = GetNextPrime(htb->_len);
		HTBInit(&newhtb, newhtb._len);
		for (i = 0; i < htb->_len; ++i)
		{
			HashNode* cur = htb->_tables[i];
			while (cur)
			{
				HashNode* next = cur->_next;
				size_t index = HTBHashFunc(cur->_key, newhtb._len);

				cur->_next = newhtb._tables[index];
				newhtb._tables[index] = cur;

				cur = next;
			}

			htb->_tables[i] = NULL;
		}

		HTBDestory(htb);

		htb->_tables = newhtb._tables;
		htb->_size = newhtb._size;
		htb->_len = newhtb._len;
	}
}

int HTBInsert(HTB* htb, HTBKeyType key, HTBValueType value)
{
	size_t index;
	HashNode* cur, *newNode;

	HTBCheckCapacity(htb);

	assert(htb);
	index = HTBHashFunc(key, htb->_len);
	cur = htb->_tables[index];
	while (cur)
	{
		if (cur->_key == key)
			return -1;

		cur = cur->_next;
	}
	
	newNode = BuyHashNode(key, value);
	newNode->_next = htb->_tables[index];
	htb->_tables[index] = newNode;
	htb->_size++;

	return 0;
}

int HTBRemove(HTB* htb, HTBKeyType key)
{
	size_t index;
	HashNode* cur = NULL, *prev = NULL;
	assert(htb);

	index = HTBHashFunc(key, htb->_len);
	cur = htb->_tables[index];
	while (cur)
	{
		if (cur->_key == key)
		{
			if (prev == NULL)
				htb->_tables[index] = cur->_next;
			else
				prev->_next = cur->_next;

			free(cur);
			--htb->_size;
			return 0;
		}

		prev = cur;
		cur = cur->_next;
	}

	return -1;
}

HashNode* HTBFind(HTB* htb, HTBKeyType key)
{
	size_t index;
	HashNode* cur;
	assert(htb);
	
	index = HTBHashFunc(key, htb->_len);
	cur = htb->_tables[index];
	while (cur)
	{
		if (cur->_key == key)
		{
			return cur;
		}

		cur = cur->_next;
	}
	
	return NULL;
}

int HTBSize(HTB* htb);
int HTBEmpty(HTB* htb);

void HTBPrint(HTB* htb)
{
	int i = 0;
	assert(htb);
	for (; i < htb->_len; ++i)
	{
		int count = 0;
		HashNode* cur = htb->_tables[i];
		printf("table[%d]->", i);

		while (cur)
		{
			//printf("[%s:%s]->", cur->_key, cur->_value);
			++count;
			cur = cur->_next;
		}
		printf("%d\n", count);
		//printf("%d\n");
	}

	printf("\n");
}

void TestHashTableBucket()
{
	//size_t i;
	//HTB htb;
	//HTBInit(&htb, 10);
	//HTBInsert(&htb, 30, 0);
	//HTBInsert(&htb, 34, 0);
	//HTBInsert(&htb, 300, 0);
	//HTBInsert(&htb, 12, 0);
	//HTBInsert(&htb, 53, 0);
	//HTBInsert(&htb, 106, 0);

	////srand(time(0));
	////for (i = 0; i < 10000; ++i)
	////{
	////	HTBInsert(&htb, rand(), 0);
	////}

	//HTBPrint(&htb);
	//HTBRemove(&htb, 53);
	//HTBRemove(&htb, 106);
	//HTBPrint(&htb);

	size_t begin, end;
	size_t i;
	HTB htb;

	begin = clock();
	HTBInit(&htb, GetNextPrime(100000));
	//HTBInit(&htb, 10);
	srand(time(0));
	for (i = 0; i < GetNextPrime(100000); ++i)
	{
		HTBInsert(&htb, i+rand(), 0);
	}
	end = clock();

	printf("%d\n", end-begin);

	//HTBPrint(&htb);
}

//void TestHashTableBucket()
//{
//	HTB htb;
//	HTBInit(&htb, 10);
//
//	HTBInsert(&htb, "insert", "²åÈë");
//	HTBInsert(&htb, "delete", "É¾³ý");
//	HTBInsert(&htb, "hash", "¹þÏ£");
//	HTBInsert(&htb, "test", "²âÊÔ");
//
//	HTBPrint(&htb);
//}