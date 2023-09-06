/*
-----------------------------------------------------
Arquivo Main.cpp referente ao TP0
Materia Estrutura de Dados
Semestre 2022/02

Aluna: Maria Clara Oliveira Domingos Ruas
Matricula: 2021019572
-----------------------------------------------------

Projeto de conversao de imagem PPM em PPM


*/

#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

#include "ppm.hpp"
#include "pgm.hpp"
#include "memlog.h"


using namespace std;

char LOGNOME[100];
int RANGE = 0;


int main(int argc, char *argv[]) {
  /*
  Descricao: programa principal da aplicacao
  Entradas: 
  Saídas: 0
  */

  string nomeArqPPM, nomeArqPGM;
  ppm arqRGB;
  pgm arqGS;
  string i = "-i";
  string o = "-o";
  string l = "-l";
  string p = "-p";
  

  for(int j = 0; j < argc; j++){
    if(argv[j] == i){
      nomeArqPPM = argv[j + 1];
    }
    if(argv[j] == o){
      nomeArqPGM = argv[j + 1];
    }
    //Comando para geracao de log
    /*if(argv[j] == l){
      RANGE = 1;
    }
    if(argv[j] == p){
      strcpy(LOGNOME, argv[j + 1]);
    }*/
  }

  /*iniciaMemLog(LOGNOME);

  if(RANGE){
    ativaMemLog();
  }
  else{
    desativaMemLog();
  }*/

  arqRGB.criaPPM(nomeArqPPM);
  arqRGB.lePPM(nomeArqPPM);
  arqGS.criaPGM(nomeArqPPM);
  arqGS.transformaPGM(arqRGB);
  arqGS.geraPGM(nomeArqPGM);
  arqGS.liberaMem();
  arqRGB.liberaMem();

	return 0;
}
