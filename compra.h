#ifndef COMPRA_H
#define COMPRA_H

#include <QObject>
#include <QVector>
#include <algorithm>
#include <numeric>

class Compra
{

private:

    QString produto;
    float valor;
    int quantidade;

public:

    explicit Compra();
    Compra(QString p,float v, int q);


    QString getProduto() const;
    void setProduto(const QString &value);

    float getValor() const;
    void setValor(float value);

    int getQuantidade() const;
    void setQuantidade(int value);

signals:

public slots:


};

#endif // COMPRA_H
