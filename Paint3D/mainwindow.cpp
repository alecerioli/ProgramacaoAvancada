#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QDebug>
#include <QColorDialog>
#include "plotter.h"
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionQuit,
            &QAction::triggered,
            this,
            &MainWindow::finaliza);
    connect(ui->actionDimensoes,
            &QAction::triggered,
            this,
            &MainWindow::dimensoes);
  /*  connect(ui->actionPutVoxel,
            &QAction::triggered,
            ui->widget,
           &Plotter::putVoxel);
           */
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::finaliza()
{
    close();
}

void MainWindow::dimensoes()
{
    Dialog d;
    int x, y, z;
    if(d.exec() == QDialog::Accepted){
        x = d.getX();
        y = d.getY();
        z = d.getZ();
        ui->widget->setDimensoes(x,y,z);
    }
}







