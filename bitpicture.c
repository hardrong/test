#include"bitpicture.h"
void bitmapinit(bitmap *bm)
{
    bm->array = (char *)malloc(sizeof(char)*4);
    memset(bm->array,0,sizeof(char));
    bm->number = 10;
}
void bitrset(bitmap *bm,int number)
{
    int index = number/8;
	int cur = number%8;
	int ret = 1;
	ret<<cur;
   (bm->array[index])&(~ret);
}
void bitset(bitmap *bm ,int number)
{
   int index =number/8;
   int cur = number%8;
   int ret = 1;
  ret<<=cur;
 bm->array[index] = (bm->array[index])|ret;
  
}
int bitmaptest(bitmap *bm)
{
  int array[] = {5,14,3,20,22,18,1,16,2,12};
  int i =0;
   int index =12/8;
   int cur = 12%8;
   int ret = 1;
  char tmp = 0;
  for(i=0; i<10; i++)
  {
      bitset(bm,array[i]);
	  
  }
  
   tmp = bm->array[index];
     if(((tmp>>cur)&1) == 1)
	 return 1;
  return 0;
  }




