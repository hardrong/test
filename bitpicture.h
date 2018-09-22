#ifndef __BITPICTURE_H__
#define __BITPICTURE_H__
#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef struct bitmap
{
   char *array;
   int number;
}bitmap;

void bitmapinit(bitmap* bm);
void bitset(bitmap *bm,int number);
void bitrset(bitmap*bm,int number);
int bitmaptest(bitmap *bm);

#endif //_BITPICTURE_H__

