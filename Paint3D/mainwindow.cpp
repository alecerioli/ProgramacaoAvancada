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

    connect(ui->horizontalSliderR,
            &QAbstractSlider::valueChanged,
            ui->widget,
            &Plotter::getCorVermelha);

    connect(ui->horizontalSliderG,
            &QAbstractSlider::valueChanged,
            ui->widget,
            &Plotter::getCorVerde);

    connect(ui->horizontalSliderB,
            &QAbstractSlider::valueChanged,
            ui->widget,
            &Plotter::getCorAzul);

    connect(ui->horizontalSliderProf,
            &QAbstractSlider::valueChanged,
            ui->widget,
            &Plotter::getProf);

    connect(ui->horizontalSliderRaio,
            &QAbstractSlider::valueChanged,
            ui->widget,
            &Plotter::getRaioEsfera);

    connect(ui->horizontalSliderRaioX,
            &QAbstractSlider::valueChanged,
            ui->widget,
            &Plotter::getRaioXElipsoide);

    connect(ui->horizontalSliderRaioY,
            &QAbstractSlider::valueChanged,
            ui->widget,
            &Plotter::getRaioYElipsoide);

    connect(ui->horizontalSliderRaioZ,
            &QAbstractSlider::valueChanged,
            ui->widget,
            &Plotter::getRaioZElipsoide);

    connect(ui->horizontalSliderLarg,
            &QAbstractSlider::valueChanged,
            ui->widget,
            &Plotter::getLarguraCaixa);

    connect(ui->horizontalSliderAlt,
            &QAbstractSlider::valueChanged,
            ui->widget,
            &Plotter::getAlturaCaixa);

    connect(ui->horizontalSliderEsp,
            &QAbstractSlider::valueChanged,
            ui->widget,
            &Plotter::getEspessuraCaixa);

    connect(ui->actionPutVoxel,
            &QAction::triggered,
            ui->widget,
            &Plotter::colocaVoxel);

    connect(ui->actionCutVoxel,
            &QAction::triggered,
            ui->widget,
            &Plotter::retiraVoxel);

    connect(ui->actionPutSphere,
            &QAction::triggered,
            ui->widget,
            &Plotter::colocaEsfera);

    connect(ui->actionCutSphere,
            &QAction::triggered,
            ui->widget,
            &Plotter::retiraEsfera);

    connect(ui->actionPutEllipsoid,
            &QAction::triggered,
            ui->widget,
            &Plotter::colocaElipsoide);

    connect(ui->actionCutEllipsoid,
            &QAction::triggered,
            ui->widget,
            &Plotter::retiraElipsoide);

    connect(ui->actionPutBox,
            &QAction::triggered,
            ui->widget,
            &Plotter::colocaCaixa);

    connect(ui->actionCutBox,
            &QAction::triggered,
            ui->widget,
            &Plotter::retiraCaixa);
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







