#include "game.h"

void init_board(char board[ROW][COL],int row,int col)
{ 
	int i =0;
	int j =0;
	for(i=0;i<row; i++)
	{
		for(j=0; j<col; j++)
			board[i][j]=' ';
	}
}
void print_board(char board[ROW][COL],int row,int col)
{
	int i = 0;
	int j = 0;
	printf("____________\n");
	for(i=0; i<row; i++)
	{     
		for(j=0; j<col; j++)
		{
			printf("| %c ",board[i][j]);
				
		}
		printf("|\n");
		printf("|___|___|___|");
		printf("\n");
	}
}

void player_move(char board[ROW][COL],int row,int col)
{
	int x = 0;
	int y = 0;

	
	while(1)
	{
		printf("请输入您下棋的位置（用坐标表示）：");
    	scanf("%d %d",&x,&y);
	if((x>0 && x<=row) && (y>0 && y<=col) && (board[x-1][y-1]==' '))
	{
		board[x-1][y-1]='*';
		break;
	}
	else
		printf("输入位置错误\n");
	}
}

void computer_move(char board[ROW][COL],int row,int col)
{
	int ret1 = 0;
	int ret2 = 0;
	
	while(1)
	{
		ret1 = rand()%3;
	   ret2 = rand()%3;
		if( board[ret1][ret2]==' ')
		{
			board[ret1][ret2] = '0';
			break;
		}

	}

}
int is_full_board(char board[ROW][COL],int row,int col)
{
	int i=0;
	int j=0;
	 for(i=0; i<row; i++)
		{   
			for(j=0; j<col; j++)
			{
				if(board[i][j]==' ')
					return 0;	

			}
		   }
         return 1;     
}
  char is_win(char board[ROW][COL],int row,int col)
  {
	  int i = 0;
	  int j = 0;
	  for(i=0; i<row; i++)
	  {
	    if((board[i][0]==board[i][1]) && (board[i][1]== board[i][2] ))
	   {
		  if(board[i][0]=='*')
			  {
				  return 'Y';
			  }
			  if(board[i][0]=='0')
			  {
				  return 'N';
			  }
	   }
	  }
	  for(j=0; j<col; j++)
	  {
	   if((board[0][j]==board[1][j]) && (board[1][j]== board[2][j] ))
	   {
		  if(board[0][j]=='*')
			  {
				  return 'Y';
			  }
			  if(board[0][j]=='0')
			  {
				  return 'N';
			  }
	   }
	  }
		  if((board[0][0]==board[1][1]) &&  (board[1][1]==board[2][2])) 
			  
		  {
			  if(board[0][0]=='*')
			  {
				  return 'Y';
			  }
			  if(board[0][0]=='0')
			  {
				  return 'N';
			  }
		  }
			  if((board[2][0]==board[1][1]) &&  (board[1][1]==board[0][2])) 
		   {
			  if(board[2][0]=='*')
			  {
				  return 'Y';
			  }
			  if(board[2][0]=='0')
			  {
				  return 'N';
		       }
			  }
		 

		  if(is_full_board(board,ROW,COL)==1)
		  {
			  return 'P';
		  }
		  else
			  return 'G';
		 
  }