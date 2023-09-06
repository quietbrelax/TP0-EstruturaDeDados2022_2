/*
-----------------------------------------------------
Arquivo PGM.cpp referente ao TP0
Implementacao das funcoes da Estrutura PGM
Materia Estrutura de Dados
Semestre 2022/02

Aluna: Maria Clara Oliveira Domingos Ruas
Matricula: 2021019572
-----------------------------------------------------

Projeto de conversao de imagem PPM em PPM


*/

#include "ppm.hpp"
#include <string>
#include "pgm.hpp"
#include <fstream>


pgm::pgm(){
    /*
    Descricao: Funcao construtor da classe
    Entradas: 
    Saida:
    */

    //Inicializacao dos valores nulos

    this ->largura = 0;
    this ->altura = 0;
}

void pgm::criaPGM(std::string fileName){
    /*
    Descricao: Prepara o espaco para o armazenamento dos dados
    Entrada: string Nome do arquivo a ser convertido
    Saida:
    
    */

    //Variaveis auxiliares
    int number;
    std::string cabecalho;
    int i = 0;

  // Abre o arquivo para leitura
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


    //Fecha arquivo
    MyReadFile.close();
    
    //Alocacao dinamica do espaco necessario para armazenar os dados
    this -> ptr = (int *) malloc((this -> largura * this -> altura) * sizeof(int));
    
}

void pgm:: transformaPGM(ppm rgb){

    /*
    Descricao: Converte os dados de uma imagem PPM (colorida) em PGM (escala cinza)
    Entrada: ppm (estrutura criada) a ser convertido
    Saida:
    */


    /*
    Realiza a conversao segundo a formula:
    Y = 49/255 (0.30R + 0.59G + 0.11B)
    onde R é o valor vermelho, G o valor verde e B o valor azul
    */
  for(int i = 0; i < this -> largura * this -> altura; i++){
      ptr[i] = (49.0/255)*(0.30*rgb.getRed(i) + 0.59*rgb.getGreen(i) + 0.11*rgb.getBlue(i));
      //ESCREVEMEMLOG((long int)(&(ptr[i])), sizeof(int), 0);
    }
}

void pgm:: geraPGM(std::string nomeArquivo){
    /*
    Descricao: Gera um arquivo PGM com os valores convertidos
    Entrada: string referente ao nome do arquivo a ser criado
    Saida:
    */

    //Gera arquivo para escrita
    std::ofstream MyWriteFile(nomeArquivo);

    //Cabecalho do arquivo, contendo o codigo Netpbm, dimensoes e range dos tons (no caso, de 0 a 49)
    MyWriteFile << "P2\n";
    MyWriteFile << this -> largura << " " << this -> altura << "\n";
    MyWriteFile << "49\n";

    //Escreve os valores referentes a cada tom de cada pixel, saltando de linha quando atinge a largura do arquivo
    for(int i = 0; i < this -> largura * this -> altura; i++){
        MyWriteFile << this -> ptr[i] << " ";
        if((i+1)%(this -> largura) == 0){
            MyWriteFile << "\n";
        }
    }

    //Fecha o arquivo
    MyWriteFile.close();
}


int * pgm:: getPgm(){
    /*
    Descricao: Acesso ao atributo privado da classe, finalidade de encapsulamento
    Entrada:
    Saida: int * (ponteiro do tipo inteiro, refrente ao primeiro termo da matriz dinamica)
    */
    return this -> ptr;
}

void pgm::liberaMem(){
    /*
    Descricao: Libera a memoria alocada
    Entrada:
    Saida: 
    */
  free(ptr);
}