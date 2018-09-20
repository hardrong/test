#include"addr.h"

record *is_full(record *p)
{
	int n = p->sz;
	if(n == 0||p->sz+3==p->capacity)
	{
		peoinfo *tmp = (peoinfo*)realloc(p->elem,sizeof(peoinfo)*p->capacity);
		if(tmp != NULL)
		{
		    p->elem = tmp;
			p->capacity += 3;
			n = 1;
		}
		else
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
	}
	return p;

}
record*initrecord()
{
	
	record *s;
	s = (record *)malloc(sizeof(record));
	if(s == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	  s->sz = 0;
	  s->capacity = 3;
	  s->elem = NULL;
	  loadcontact(s);
	return s;
}
void loadcontact(record * p)
{
	peoinfo tmp = {0};
	int count = 0;
	FILE *pfread = fopen(FILENAME,"r");
	if(pfread == NULL)
	{
		perror(" open file for read ");
		exit(EXIT_FAILURE);
	}
	   while(fread(&tmp,sizeof(peoinfo),1,pfread))
	   {
		   is_full(p);
		   p->elem[p->sz] = tmp;
		   p->sz++;
		 
	   }
	fclose(pfread);
	pfread = NULL;
}
void savecontact(record * p)
{
	int i = 0;
	FILE *pfwrite = fopen(FILENAME,"w");
	if(pfwrite == NULL)
	{
		perror("open file for write");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i<p->sz; i++)
	{
		fwrite(p->elem+i,sizeof(peoinfo),1,pfwrite);
	}
	fclose(pfwrite);
	pfwrite = NULL;
}
void add(record *p)
{
	assert(p!=NULL);
	is_full(p);
	printf("输入姓名:>");
	scanf("%s",&p->elem[p->sz].name);
	printf("输入年龄:>");
	scanf("%d",&p->elem[p->sz].age);
	printf("输入性别:>");
	scanf("%s",&p->elem[p->sz].sex);
	printf("输入地址:>");
	scanf("%s",&p->elem[p->sz].addr);
	p->sz++;
	printf("增加成功\n");
}
static int sea(record *p)
{
	int i = 0;
	char name[10] = {'\0'};
	assert(p!=NULL);

	printf("输入姓名:>");
	scanf("%s",&name);
	for(i=0; i<p->sz; i++)
	{
	if(strcmp(name,(p->elem[i].name))==0)
		return i;
	}
		return -1;
}
void search(record *p)
{
	int i = 0;
	i = sea(p);
	assert(p!=NULL);

	if(i != -1)
	{
		printf("找到了\n");
		printf("姓名:%s,年龄:%d,性别:%s,地址:%s\n",
			p->elem[i].name,
			p->elem[i].age,
			p->elem[i].sex,
			p->elem[i].addr);
	}
	else
		printf("没有找到\n");
}

void show(record *p)
{
	int j = 0;
	assert(p!=NULL);

	printf("姓名    年龄   性别   地址\n");
	for(j=0; j<p->sz; j++)
	{
		printf("%-6s %-6d %-6s %-6s\n",
			p->elem[j].name,
			p->elem[j].age,
			p->elem[j].sex,
			p->elem[j].addr);
	}
}
void empty(record *p)
{
	assert(p!=NULL);
	p->sz = 0;	
}
void del(record *p)
{
	int ret = 0;
	assert(p!=NULL);
	ret = sea(p);
	if(ret != -1||ret<=p->sz)
	{
		int i = 0;
		for(i=ret; i<p->sz-1; i++)
		{
			p->elem[i]=p->elem[i+1];
		}
		p->sz--;
	}
	else
		printf("没有找到联系人\n");

}
void sort(record *p)
{
	int i = 0;
	int j = 0;
	int flag = 0;
	assert(p!=NULL);
	if(p->sz == 0)
		return ;
	for(i=0; i<p->sz-1; i++)
	{
		for(j=0; j<p->sz-1-i; j++)
		{
	   if(strcmp(p->elem[j].name ,p->elem[j+1].name)>0)
	    {
		  peoinfo tmp = p->elem[j];
		  p->elem[j]=p->elem[j+1];
		  p->elem[j+1] = tmp;
		  flag = 1;
	    }
	   if(flag = 0)
		   break;
       }
		  
	}
	printf("排序成功\n");
}
void mod(record *p)
{
	int ret = 0;
	assert(p!=NULL);
	ret = sea(p);
	if(ret!=-1)
	{
		printf("输入要修改的姓名:");
		scanf("%s",&p->elem[ret].name );
		printf("输入要修改的年龄:");
		scanf("%d",&p->elem[ret].age );
		printf("输入要修改的性别:");
		scanf("%s",&p->elem[ret].sex );
		printf("输入要修改的地址:");
		scanf("%s",&p->elem[ret].addr );
		printf("修改成功\n");
	}
	else
		printf("没有找到联系人\n");
	
}
void destroycontact(record * p)
{
	 savecontact(p);
	free(p->elem);
		p->elem = NULL;
		free(p);
		p = NULL;
}