#ifndef FM_DADOS_H
#define FM_DADOS_H

#include <QDialog>
#include <QMainWindow>
#include <QDebug>
#include <QVector>
#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>



#include "arquivos.h"
#include "consumo.h"
#include"compra.h"

namespace Ui {
class fm_dados;
}

class fm_dados : public QDialog
{
    Q_OBJECT
private:
      Consumo dadosTotais;

public:
    explicit fm_dados(QWidget *parent =nullptr);
    ~fm_dados();
      void atualizarEstaticas();

private slots:

    void on_btn_adicionar_clicked();

    void on_btn_produtoSort_clicked();

    void on_btn_precoSort_clicked();

    void on_btn_quantidadeSort_clicked();

    void salvar();
    void carregar();

    void on_btn_salvar_clicked();



    void on_btn_carregar_clicked();

    void on_tableWidget_cellDoubleClicked(int row, int column);
    void setTable(Compra *x, int quantLinhas);



private:

    Ui::fm_dados *ui;
 void inserirCompraNaTabela(Compra compra, int row);

};

#endif // FM_DADOS_H
