#include <iostream>

class A
{
 
  private:
    int _a;
  public:
    void show()
    {
      std::cout << "show()" << std::endl;
    }
    void Print()
    {
      std::cout << _a << std::endl;
    }
};
int main()
{
   A *p = NULL;
   p->show();
   //p->Print();//错误，p是NULL指针，对它p->_a 时崩溃
   return 0;
}
