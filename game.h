
#ifndef _GAME_H_
#define _GAME_H_
typedef unsigned int uint;

enum OPTION
{
    EXIT,
	START
};
enum MINE_COUNT
{
	EASY_COUNT=10
};
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2

void InitBoard(char board[ROWS][COLS],int rows,int cols,char set);
void PrintBoard(char board[ROWS][COLS],int rows,int cols);
void SetMine(char board[ROWS][COLS],int row,int col,int x,int y);
int GetMineCount(char mine[ROWS][COLS],int x,int y);
void expend (char board[ROWS][COLS],char arr[ROWS][COLS],int row,int col,int x,int y);
#endif