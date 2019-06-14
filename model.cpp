#include "model.h"
model::model()
{
}
void model::setNum1(int num)
{
    num1 = num;
}
void model::setNum2(int num)
{
    num2 = num;
}
void model::setFlag(QString flag)
{
    this->flag = flag;
}
int model::doExpr()
{
    int result = 0;
    if(flag == "+")
        result = num1+num2;
    else if(flag == "-")
        result = num1-num2;
    else if (flag == "*")
        result = num1*num2;
    else if(flag == "/")
    {
        if(num2 == 0)
            return -1;
        else
            result = num1 / num2;
    }

    return result;

}

