#include "expr.h"
#include "ui_expr.h"
#include "model.h"
expr::expr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::expr)
{
    model1 = new model;
    ui->setupUi(this);
    connect(this->ui->btn_0, SIGNAL(clicked(bool)),this,SLOT(getBtn0()) );
    connect(this->ui->btn_1, SIGNAL(clicked(bool)),this, SLOT(getBtn1()));
    connect(this->ui->btn_2, SIGNAL(clicked(bool)),this, SLOT(getBtn2()));
    tmp = "";
}

expr::~expr()
{
    delete ui;
}
void expr::getBtn0()
{
    if(tmp != "")
    {
        tmp +=this->ui->btn_0->text();
        this->ui->lbl_display->setText(tmp);
    }
}
void expr::getBtn1()
{
    tmp +=this->ui->btn_1->text();
    this->ui->lbl_display->setText(tmp);
}
void expr::getBtn2()
{
    tmp +=this->ui->btn_2->text();
    this->ui->lbl_display->setText(tmp);
}

void expr::on_btn_3_clicked()
{
    tmp +=this->ui->btn_3->text();
    this->ui->lbl_display->setText(tmp);
}

void expr::on_btn_4_clicked()
{
    tmp +=this->ui->btn_4->text();
    this->ui->lbl_display->setText(tmp);
}

void expr::on_btn_5_clicked()
{
    tmp +=this->ui->btn_5->text();
    this->ui->lbl_display->setText(tmp);
}

void expr::on_btn_6_clicked()
{
    tmp +=this->ui->btn_6->text();
    this->ui->lbl_display->setText(tmp);
}

void expr::on_btn_7_clicked()
{
    tmp +=this->ui->btn_7->text();
    this->ui->lbl_display->setText(tmp);
}

void expr::on_btn_8_clicked()
{
    tmp +=this->ui->btn_8->text();
    this->ui->lbl_display->setText(tmp);
}

void expr::on_btn_9_clicked()
{
    tmp +=this->ui->btn_9->text();
    this->ui->lbl_display->setText(tmp);
}

void expr::on_btn_plus_clicked()
{
    int num = tmp.toInt();
    model1->setNum1(num);
    tmp = "";
    QString ex = ui->btn_plus->text();
    model1->setFlag(ex);
}

void expr::on_btn_sub_clicked()
{
    int num = tmp.toInt();
    model1->setNum1(num);
    tmp = "";
    QString ex = ui->btn_sub->text();
    model1->setFlag(ex);
}

void expr::on_btn_mult_clicked()
{
    int num = tmp.toInt();
    model1->setNum1(num);
    tmp = "";
    QString ex = ui->btn_mult->text();
    model1->setFlag(ex);
}

void expr::on_btn_divid_clicked()
{
    int num = tmp.toInt();
    model1->setNum1(num);
    tmp = "";
    QString ex = ui->btn_divid->text();
    model1->setFlag(ex);
}

void expr::on_btn_equal_clicked()
{
    int num = tmp.toInt();
    model1->setNum2(num);
   QString res = QString::number(model1->doExpr());
    ui->lbl_display->setText(res);
    tmp = "";
}

void expr::on_btn_clear_clicked()
{
    tmp = "";
    ui->lbl_display->setText("0");
}

