#include <iostream>
#include <vector>
using namespace std;
bool SearchNumber(vector <vector<int> > &array,int number)
{
     int  j;
   for(j = array[0].size()-1; j >= 0; j--)
   {
     if(array[0][j] == number)
     {
       return true;
     }
     else if(array[0][j] <  number)
     {
         break;
     }
   }
   if(j < 0)
   {
     return false;
   }
   for(size_t  i = 0; i < array.size(); i++)
   {
       if(array[i][j] == number)
      {
        return true;
      }
   }
   return false;
}
int main()
{
     int  arr[4][4]= { {1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15} };
     vector<vector<int> > array; 
  for(int i = 0; i< 4; i++)
  {
        vector<int > arr1;
    for(int j = 0; j < 4; j++)
    {
       arr1.push_back(arr[i][j]);
    }
      array.push_back(arr1);
    
  }

  if(SearchNumber(array,12))
  {
    cout << " 找到了" << endl;
  }
  else 
  {
    cout << "没有找到" << endl;
  }
  return 0;
}
