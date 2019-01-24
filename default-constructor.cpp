#include  <iostream>

template <class T>
class Array
{
  public:
    Array(int size);
    void printf()
    {
      std::cout << "hello" << std::endl;
    }
  private:
    T* _data;
};
template <class T>
Array<T>::Array(int size)
{
  _data = new T[size];
}
int main()
{
  //printf();
  return 0;
}
