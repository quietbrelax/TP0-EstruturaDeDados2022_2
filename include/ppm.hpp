/*
-----------------------------------------------------
Arquivo PPM.hpp referente ao TP0
Definicao das chamadas das funcoes da Estrutura PPM
Materia Estrutura de Dados
Semestre 2022/02

Aluna: Maria Clara Oliveira Domingos Ruas
Matricula: 2021019572
-----------------------------------------------------

Projeto de conversao de imagem PPM em PPM


*/

#pragma once
#include <string>
#include <fstream>

class ppm {
  private:
    int * red;
    int * green;
    int * blue;
    int altura;
    int largura;
public:
    ppm();
    void criaPPM(std::string);
    void lePPM(std::string);
    int getRed(int);
    int getGreen(int);
    int getBlue(int);
    void liberaMem();
};