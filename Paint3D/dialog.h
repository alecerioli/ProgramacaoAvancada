#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

/**
 * @brief A classe Dialog
 * representa uma caixa de dialogo que permite digitar as dimensoes do escultor.
 */
class Dialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Dialog eh o construtor da classe Dialog.
     * @param parent: parametro geralmente nulo.
     */
    explicit Dialog(QWidget *parent = nullptr);
    /**
     * @brief ~Dialog eh o destrutor da classe Dialog.
     */
    ~Dialog();
    /**
     * @brief getX eh uma funcao para saber a dimensao de X.
     * @return dimensao X.
     */
    int getX();
    /**
     * @brief getY eh uma funcao para saber a dimensao de Y.
     * @return dimensao Y.
     */
    int getY();
    /**
     * @brief getZ eh uma funcao para saber a dimensao de Z.
     * @return dimensao Z.
     */
    int getZ();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
