#ifndef MODEL_H
#define MODEL_H
#include<QString>
class model
{
public:
    model();
    //设置数字
    void setNum1(int num);
    void setNum2(int num);
    //设置符号
    void setFlag(QString flag);
    //计算
    int doExpr();
private:
    //用于计算的2个数字num1,num2，符号flag
    int num1;
    int num2;
    QString flag;

};

#endif // MODEL_H
