#include "compra.h"


Compra::Compra()
{

}

Compra::Compra(QString p, float v, int q)
{
    produto= p;
    valor=v;
    quantidade=q;
}


QString Compra::getProduto() const
{
    return produto;
}

void Compra::setProduto(const QString &value)
{
    produto= value;
}

float Compra::getValor() const
{
    return valor;
}

void Compra::setValor(float value)
{
    valor= value;
}

int Compra::getQuantidade() const
{
    return quantidade;

}

void Compra::setQuantidade(int value)
{
    quantidade= value;
}




