#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <fstream>
#include <QDebug>

#include "consumo.h"
#include "compra.h"


class Arquivos
{
public:
    Arquivos();
    static bool salvarConsumo(QString &arquivo, Consumo &consumo);
    static bool carregarConsumo(QString &arquivo,  Consumo &consumo);
};

#endif // GERENCIADORDEARQUIVOS_H
