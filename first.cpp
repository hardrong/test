#include<iostream>
#include<malloc.h>
using namespace std;
class Date
{
  public :
 Date(int a = 10,int b = 2, int c = 3)
 {
      _year = a;
      _month = b;
      _day = c;
 }

 void display()
 {
 cout << _year << _month << _day << endl;
 }
  private:
   int _year;
    int _month;
    int _day;
};
class seqlist
{
 public:
 seqlist (int capacity = 10)
 {
   _pData = (int*)malloc(capacity*sizeof(int));
   _size = 0;
   _capacity = capacity;
 }
 private:
 int *_pData;
 int _size;
 int _capacity;
};
int main()
{
  Date m;
  seqlist a(20);
 m.display();

  return 0;
}
