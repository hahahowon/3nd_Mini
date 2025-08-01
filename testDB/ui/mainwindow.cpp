#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "exsql.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if (ExSql::connectDB()){ // DB 연결(열기) 되면
        ExSql::printUsers(); // 그 테이블 보여주는 함수 호출
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
