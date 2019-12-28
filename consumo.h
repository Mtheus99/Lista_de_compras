#ifndef CONSUMO_H
#define CONSUMO_H

#include <QObject>
#include <QVector>
#include <numeric>
#include <algorithm>
#include <QMainWindow>


#include "compra.h"

class Consumo: public QObject
{
    Q_OBJECT

private:
    QVector<Compra> consumo;

public:
    explicit  Consumo(QObject *parent = nullptr);
    void inserirCompra(const Compra a);
    void ordenarPorProduto();
    void ordenarPorValor();
    void ordenarPorQuantidade();
    float total();
    float maiorValor();
    float menorValor();

    int size();
    void clear();
    void mudarNaTabela(int o, int j, QString x);

    Compra* retornoCompra(int i);
    Compra operator[](int r);

    signals:

public slots:


};

#endif // CONSUMO_H


















