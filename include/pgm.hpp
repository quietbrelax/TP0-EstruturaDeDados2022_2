/*
-----------------------------------------------------
Arquivo PGM.hpp referente ao TP0
Definicao das chamadas das funcoes da Estrutura PGM
Materia Estrutura de Dados
Semestre 2022/02

Aluna: Maria Clara Oliveira Domingos Ruas
Matricula: 2021019572
-----------------------------------------------------

Projeto de conversao de imagem PPM em PPM


*/
#pragma once
#include <string>
#include "ppm.hpp"
#include <fstream>

class pgm {
  private:
    int * ptr;
    int largura;
    int altura;
public:
    pgm();
    void criaPGM(std::string);
    int * getPgm();
    void liberaMem();
    void transformaPGM(ppm);
    void geraPGM(std::string);
};