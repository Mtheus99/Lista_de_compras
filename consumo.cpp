#include "consumo.h"

Consumo::Consumo(QObject *parent) :QObject (parent)
{

}

void Consumo::inserirCompra(const Compra a)
{
    consumo.push_back(a);
}

void Consumo::ordenarPorProduto()
{
    std::sort(consumo.begin(), consumo.end(), [](Compra a, Compra b){return a.getProduto()< b.getProduto();});
}

void Consumo::ordenarPorValor()
{
    ordenarPorProduto();
    std::stable_sort(consumo.begin(),consumo.end(),[](Compra a, Compra b){return a.getValor()<b.getValor();});
}

void Consumo::ordenarPorQuantidade()
{

    ordenarPorProduto();
    std::stable_sort(consumo.begin(),consumo.end(),[](Compra a, Compra b){return a.getQuantidade()<b.getQuantidade();});
}


float Consumo::total()
{
  //calculando o total da compra
  return std::accumulate(consumo.begin(),consumo.end(),0.0, [](float acc, Compra a){return acc+=(a.getValor()* a.getQuantidade());});

}



float Consumo::maiorValor()
{
    Compra *maior = std::max_element(consumo.begin(),consumo.end(),[](Compra a, Compra b){ return a.getValor() < b.getValor();});
    return maior->getValor();
}

float Consumo::menorValor()
{
    Compra *menor = std::min_element(consumo.begin(),consumo.end(),[](Compra a, Compra b){return a.getValor() < b.getValor();});
    return menor->getValor();
}




int Consumo::size()
{
    return  consumo.size();
}

void Consumo::clear()
{
    consumo.clear();
}

void Consumo::mudarNaTabela(int o, int j, QString x)
{
        if(j==1){
            consumo[o].setProduto(x);
        }else if(j==2){
            consumo[o].setValor(x.toFloat());
        }else if(j==3){
            consumo[o].setQuantidade(x.toInt());
        }

}

Compra *Consumo::retornoCompra(int i)
{
    return &consumo[i];

}

Compra Consumo::operator[](int i)
{
    return consumo[i];
}




