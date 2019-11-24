#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

/**
 * @brief A classe MainWindow
 * representa a janela principal da interface grafica.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow eh o construtor da classe MainWindow.
     * @param parent: parametro geralmente nulo.
     */
    explicit MainWindow(QWidget *parent =
            nullptr);
    /**
     * @brief ~MainWindow eh o destrutor da classe MainWindow.
     */
    ~MainWindow();

public slots:
    /**
     * @brief finaliza eh uma funcao que fecha a interface grafica.
     */
    void finaliza();
    /**
     * @brief dimensoes eh uma funcao que captura as dimensoes do escultor
     * atravez de funcoes da classe Dialog.
     */
    void dimensoes();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H





