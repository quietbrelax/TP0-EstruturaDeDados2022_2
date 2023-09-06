/*
-----------------------------------------------------
Arquivo PPM.cpp referente ao TP0
Implementacao das funcoes da Estrutura PPM
Materia Estrutura de Dados
Semestre 2022/02

Aluna: Maria Clara Oliveira Domingos Ruas
Matricula: 2021019572
-----------------------------------------------------

Projeto de conversao de imagem PPM em PPM


*/

#include "ppm.hpp"
#include "memlog.h"
#include <string>
#include <iostream>
#include <fstream>

ppm::ppm(){

  /*
    Descricao: Funcao construtor da classe
    Entradas: 
    Saida:
  */

  //Inicializacao dos valores nulos
  
  this -> altura = 0;
  this -> largura = 0;
}

void ppm::criaPPM(std::string fileName){
  /*
  Descricao: Prepara o espaco para a leitura do arquivo
  Entrada: string Nome do arquivo para ser lido
  Saida:
  */

  //Variaveis auxiliares
    int number;
    std::string cabecalho;
    int i = 0;

  // Abre arquivo para leitura
  std::ifstream MyReadFile(fileName);
    
    //Le a primeira linha do arquivo referente ao codigo Netpbm
    getline(MyReadFile, cabecalho);

    //Guarda os valores referentes a largura e altura do arquivo em pixels
   while (MyReadFile >> number) {
      if(i == 0){
          this -> largura = number;
      }
      else if (i == 1){
          this -> altura = number;
      }
      else{
          break;
      } 
      i++;
    }
    
  //Fecha o arquivo
    MyReadFile.close();

  //Checagem basica para a atribuicao dos valores de altura e largura
if(this -> altura == 0 || this -> largura == 0){
      std::cout << "Falha na leitura" << std::endl;
      return;
    }
    
    //Alocacao dinamica do espaco necessario para armazenar os dados do arquivo
    //Criacao de um vetor de valores para cada cor para facilitar a manipulacao posterior

    this -> red = (int *)malloc((this -> largura * this -> altura) * sizeof(int));
    this -> green = (int *)malloc((this -> largura * this -> altura) * sizeof(int));
    this -> blue = (int *)malloc((this -> largura * this -> altura) * sizeof(int));
}

void ppm:: lePPM(std::string fileName){
  /*
  Descricao: Coleta os valores do arquivo e os organiza distribuindo entre os tres vetores da estrutura
  Entrada: string Nome do arquivo para ser lido
  Saida:
  */

  //Vetor dinamico auxiliar para guardar inicialmente os valores lidos 
    int * valores = (int *)malloc((this-> largura * this-> altura * 3) * sizeof(int));
  
  //Variaveis auxiliares
    int number;
    std::string cabecalho;
    int i = 0;
  // Abre arquivo para leitrua
  std::ifstream MyReadFile(fileName);
    
    //Le a primeira linha do arquivo referente ao codigo Netpbm
    getline(MyReadFile, cabecalho);

    //Pega os valores referentes as cores dentro do arquivo e coloca em vetores
     while (MyReadFile >> number) {
      if(i > 2){
          valores[i - 3] = number;
          //Comando para geracao de log
          //ESCREVEMEMLOG((long int)(&(valores[i - 3])), sizeof(int), 0);
      } 
      i++;
      if(i > this -> largura * this -> altura * 3 + 2){
        break;
      }
    }
    
    //Fecha o arquivo
    MyReadFile.close();

    //Libera a memoria
    free(valores);

    //Distribui os valores de acordo com a ordem nos tres vetores da estrutura
    int j = 0;
    for(int i = 0; i < this -> largura * this -> altura; i++){
      red[i] = valores[j];
      //Comando para geracao de log
      //ESCREVEMEMLOG((long int)(&(red[i])), sizeof(int), 0);
      //LEMEMLOG((long int)(&(valores[j])), sizeof(int), 0);
      j++;
      green[i] = valores[j];
      //Comando para geracao de log
      //ESCREVEMEMLOG((long int)(&(green[i])), sizeof(int), 0);
      //LEMEMLOG((long int)(&(valores[j])), sizeof(int), 0);
      j++;
      blue[i] = valores[j];
      //Comando para geracao de log
      //ESCREVEMEMLOG((long int)(&(blue[i])), sizeof(int), 0);
      //LEMEMLOG((long int)(&(valores[j])), sizeof(int), 0);
      j++;
    }

}


int ppm:: getRed(int i){
  /*
  Descricao: Acesso ao atributo privado da classe do vetor de vermelho, finalidade de encapsulamento
  Entrada: int Posicao requisitada do vetor
  Saida: int (valor da posicao referente a cor vermelha)
  */
  LEMEMLOG((long int)(&(red[i])), sizeof(int), 0);
    return this -> red[i];
}

int ppm:: getGreen(int i){
  /*
  Descricao: Acesso ao atributo privado da classe do vetor de verde, finalidade de encapsulamento
  Entrada: int Posicao requisitada do vetor
  Saida: int (valor da posicao referente a cor verde
  */
  LEMEMLOG((long int)(&(green[i])), sizeof(int), 0);
    return this -> green[i];
}

int ppm:: getBlue(int i){
  /*
  Descricao: Acesso ao atributo privado da classe do vetor de azul, finalidade de encapsulamento
  Entrada: int Posicao requisitada do vetor
  Saida: int (valor da posicao referente a cor azul)
  */
  LEMEMLOG((long int)(&(blue[i])), sizeof(int), 0);
    return this -> blue[i];
}

void ppm::liberaMem(){
  /*
    Descricao: Libera a memoria alocada
    Entrada:
    Saida: 
  */

  free(red);
  free(green);
  free(blue);
}
