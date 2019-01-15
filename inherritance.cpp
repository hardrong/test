#include <iostream>

class Person
{
 protected:
    int _year = 2018;
    int _age = 10;
 public:
    void show()
    {
      std::cout << " _year" << std::endl;
    }
};

class man:public Person 
{
  public:
    void print()
{   
      std::cout << _year << std::endl;
 

}
 protected:
  int  _book = 20;
};

int main()
{
   man m;
   Person p;
   Person p1 = m;
   Person *p2 = &m;
   Person &p3 = m;
   

   m.print();

   return 0;
}
