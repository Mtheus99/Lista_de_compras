#include "arquivos.h"

Arquivos::Arquivos()
{

}

bool Arquivos::salvarConsumo(QString &arquivo, Consumo &consumo)
{
    QFile file(arquivo);

    if(!file.open(QIODevice::WriteOnly)){
        return false;
    }

    QTextStream out(&file);

    for(int i=0;i<consumo.size();i++){
        out <<"Produto: "<< consumo[i].getProduto()<<", valor: "<<consumo[i].getValor()<<", quantidade: "<<consumo[i].getQuantidade()<<" \n "<<"\n";
    }

    file.close();
    return true;
}

bool Arquivos::carregarConsumo(QString &arquivo, Consumo &consumo)
{
    QFile file(arquivo);

    if(!file.open(QIODevice::ReadOnly)){
        return false;
    }

    QTextStream in(&file);

    QString linha;

    while(!in.atEnd()){
        linha = in.readLine();

        QStringList dados = linha.split(",");

        Compra a(dados[1],dados[2].toFloat(),dados[3].toInt());
        consumo.inserirCompra(a);

    }
    return true;
}
