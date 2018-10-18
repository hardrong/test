class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
     bool *arr = new bool[rows*cols];
        memset(arr,false,rows*cols);
        int length = 0;
        for(int i=0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(ishasPath(matrix,rows,i,cols,,str,length,arr))
             return true;
            }
       
        }
        delete[] arr;
        return false;
        
    }
  bool ishasPath(char *matrix,int rows,int row,int cols,int col,char *str,int &length,bool *arr)
  {
      if(str[length] == '\0')
          return true;
      bool haspath = false;
      if(rows >= 0 && row < rows && col < cols && cols >= 0 
         && matrix[row*cols+col] == str[length]
        &&!arr[row*cols+col])
       
      {
          length++;
          arr[row*cols+col] = true;
          haspath = ishasPath(matrix,rows,row-1,cols,col,str,length,arr)||
              ishasPath(matrix,rows,row,cols,col-1,str,length,arr)||
              ishasPath(matrix,rows,row+1,cols,col,str,length,arr)||
              ishasPath(matrix,rows,row,cols,col+1,str,length,arr);
          if(!haspath)
          {
            --length;
              arr[row*cols+col] = false;
          }
          
      }
      return haspath;
  }

};
