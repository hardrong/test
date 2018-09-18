#include"game.h"
void InitBoard(char board[ROWS][COLS],int rows,int cols,char set)
{
   int i = 0;
   int j = 0;
   for(i=0; i<rows; i++)
   {
	   for(j=0; j<cols; j++)
		   board[i][j] = set;
   }
}

void PrintBoard(char board[ROWS][COLS],int row,int col)
{
	int i = 0;
	int j = 0;
	printf("  ");
	for(i=1; i<col+1; i++)
	{
		printf(" %2d ",i);
	}
	printf("\n");

	
	for(i=1; i<=row; i++)
	{
		printf("%-2d",i);
		for(j=1; j<=col; j++)
		{
		printf(" %2c ",board[i][j]);
		}
		
		printf("\n");
	}
}


void SetMine(char board[ROWS][COLS],int rows,int cols,int x,int y)
{
	int ret1 = 0;
	int ret2 = 0;
	int count = 0;
	while(count<EASY_COUNT)
	{
	ret1 = rand()%(rows-3)+1;
	ret2 = rand()%(cols-3)+1;

	 if(board[ret1][ret2]=='0')
	 {
		 if(ret1!=x || ret2!=y)
		 {
		 
          board[ret1][ret2] = '1';
	      count++;
	      continue;
		 }
	 }
	}
}
int GetMineCount(char mine[ROWS][COLS],int x,int y)
{ 
	if(mine[x][y]=='1')
	{
		return -1;
	}
	else if(mine[x][y]=='0')
	{    

		return ((mine[x-1][y-1]+mine[x-1][y]+mine[x-1][y+1]+
		mine[x][y-1]+mine[x][y+1]+
		mine[x+1][y-1]+mine[x+1][y]+
		mine[x+1][y+1])-8*('0'));
	}
	return -2;
}

void expend (char board[ROWS][COLS],char arr[ROWS][COLS],int rows,int cols,int x,int y)
{
	int i = 0;
	int j = 0;
    int count = 0;
	if(arr[x][y]=='*')
	{
		count=GetMineCount(board,x,y);
		if(count!=0 )
		{
	     arr[x][y]=count+'0';
		}
		else
		{
			arr[x][y]='0';
	   for(i=-1; i<=1; i++)
	  {
		for(j=-1; j<=1; j++)
		{
			if( (x+i>=1) && (x+i<=ROWS) && (y+j>=-1) &&(y+j<=COLS))
			{
				if((i!=0)||(j!=0))
					expend(board,arr,ROWS,COLS,x+i,y+j);
				
			}
		}
		}
	  }
	}
}//Ò²¿ÉÓÃ memset(board,set,rols*cols*sizeof(board[0][0]
