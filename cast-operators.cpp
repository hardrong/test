#include <iostream>

typedef  void (*FuncPtr) ();

int doSomething()
{

}
int main()
{
  int firstNumber = 2;
  int secondNumber = 1;
  const int third = 3;
  double result = ((double)firstNumber)/secondNumber;
  double result1 = static_cast<double> (firstNumber) / secondNumber;
  
  //double result2 = dynamic_cast<double> (firstNumber) / secondNumber;
   
  //int *temp = (int *)&third;
    int *temp = const_cast<int *> (&third);
   *temp = 3;
   FuncPtr funcPtrArray[10];
   int doSomething();
   //funcPtrArray[0] = &doSomething();  类型不匹配
    funcPtrArray[0] = reinterpret_cast<FuncPtr> (&doSomething);
  std::cout << result << std::endl; 
  std::cout << result1 << std::endl;
  return 0;
}
