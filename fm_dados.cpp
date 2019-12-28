#include "fm_dados.h"
#include "ui_fm_dados.h"

#include <QFile>
#include <QTextStream>
#include<QMessageBox>
#include <QInputDialog>
#include "arquivos.h"





fm_dados::fm_dados(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fm_dados)
{
    ui->setupUi(this);

    setWindowTitle("Venda");
}

fm_dados::~fm_dados()
{
    delete ui;
}

void fm_dados::atualizarEstaticas()
{
   ui->txt_total->setText(QString::number(dadosTotais.total(),'f',2));
   ui->txt_maiorValor->setText(QString::number(dadosTotais.maiorValor(),'f',2));
   ui->txt_menorValor->setText(QString::number(dadosTotais.menorValor(),'f',2));
}


void fm_dados::inserirCompraNaTabela(Compra compra, int row)
{


    ui->tableWidget->setItem(row,1,new QTableWidgetItem(compra.getProduto()));
    ui->tableWidget->setItem(row,2,new QTableWidgetItem(QString::number(compra.getValor())));
    ui->tableWidget->setItem(row,3,new QTableWidgetItem(QString::number(compra.getQuantidade())));


}


void fm_dados::on_btn_adicionar_clicked()
{

    if(ui->txt_produto->text().size() != 0 && ui->txt_preco->text().size() != 0 && ui->txt_quantidade->text().size() != 0){
        Compra compra;
        compra.setProduto(ui->txt_produto->text());
        compra.setValor(ui->txt_preco ->text().toFloat());
        compra.setQuantidade(ui->txt_quantidade->text().toInt());

        int qnt_row = ui->tableWidget->rowCount();

        ui->tableWidget->insertRow(qnt_row);
       inserirCompraNaTabela(compra, qnt_row);

        ui->txt_produto->clear();
        ui->txt_preco->clear();
        ui->txt_quantidade->clear();
        ui->txt_produto->setFocus();
        dadosTotais.inserirCompra(compra);

        atualizarEstaticas();

}
}

void fm_dados::on_btn_produtoSort_clicked()
{
    ui->tableWidget->clearContents();

    dadosTotais.ordenarPorProduto();
    for(int i = 0; i<dadosTotais.size(); i++){
        inserirCompraNaTabela(dadosTotais[i], i);
    }
}



void fm_dados::on_btn_precoSort_clicked()
{
    ui->tableWidget->clearContents();
    dadosTotais.ordenarPorValor();
    for(int i = 0; i<dadosTotais.size();i++){
        inserirCompraNaTabela(dadosTotais[i],i);
    }
}

void fm_dados::on_btn_quantidadeSort_clicked()
{
    ui->tableWidget->clearContents();
    dadosTotais.ordenarPorQuantidade();
    for(int i = 0; i<dadosTotais.size();i++){
        inserirCompraNaTabela(dadosTotais[i],i);
    }
}

void fm_dados::salvar()
{
    QString nomeArquivo = QFileDialog::getSaveFileName(this,"Lista de Compras","","Texto(*.txt);;Arquivos Separado por Vírgulas(*.csv)");
    if( Arquivos::salvarConsumo(nomeArquivo,dadosTotais) ){
        QMessageBox::information(this, "Salvar consumo","Dados Salvos com Sucesso");
    }else{
        QMessageBox::information(this, "Salvar consumo","Não foi possível salvar os dados");
    }

}

void fm_dados::carregar()
{

    QString nomeArquivo = QFileDialog::getOpenFileName(this,"Lista de Consumo","","Texto Puro(*.txt);;Arquivos Separado por Vírgulas(*.csv)");
    dadosTotais.clear();

    if(Arquivos::carregarConsumo(nomeArquivo,dadosTotais)){

        ui->tableWidget->clearContents();
        for(int i=0;i<dadosTotais.size();i++){

            if(i >= ui->tableWidget->rowCount())
                ui->tableWidget->insertRow(i);

            inserirCompraNaTabela(dadosTotais[i],i);
        }

    }else{
        QMessageBox::information(this, "Carregar turma","Não foi possível carregar os dados");
    }
}





void fm_dados::on_btn_salvar_clicked()
{
    salvar();
}



void fm_dados::on_btn_carregar_clicked()
{
    carregar();
}

void fm_dados::on_tableWidget_cellDoubleClicked(int row, int column)
{
    QString editar;
    if(column == 1){
        editar = QInputDialog::getText(this, "Editar", "Insira o produto:", QLineEdit::Normal);
    }else if(column == 2){
        editar = QInputDialog::getText(this, "Editar", "Insira o valor:", QLineEdit::Normal);
    }else if(column == 3){
       editar= QInputDialog::getText(this, "Editar", "Insira a quantidade:", QLineEdit::Normal);
    }

    dadosTotais.mudarNaTabela(row, column, editar);
    for(int i=0; i<dadosTotais.size() ; i++){
        setTable(dadosTotais.retornoCompra(i), i);
    }
}

void fm_dados::setTable(Compra *x, int quantLinhas)
{

    ui->tableWidget->setItem(quantLinhas,1,new QTableWidgetItem(x->getProduto()));
    ui->tableWidget->setItem(quantLinhas,2,new QTableWidgetItem(x->getValor()));
    ui->tableWidget->setItem(quantLinhas,3,new QTableWidgetItem(x->getQuantidade()));

    atualizarEstaticas();
    ui->txt_produto->setFocus();


}


