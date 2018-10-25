//sapo.cpp
#include "../include/sapo.h"

int Sapo::corrida;

Sapo::Sapo(){
  id = 0;
  distancia = 0;
  qnt_pulo = 0;
}
Sapo::Sapo(int i){
  id = i;
  distancia = 0;
  qnt_pulo = 0;
}
//Tá com problemas
int Sapo::pular(){
  int tamanho_pulo;
  //srand(time(NULL));
  tamanho_pulo = (rand() % 6) + 1; //gera um numero randomico de 1 a 5
  distancia += tamanho_pulo;
  qnt_pulo++;

  return distancia;
}
int Sapo::getID(){
  return id;
}
void Sapo::setID(int i){
  id = i;
}
int Sapo::getDistancia(){
  return distancia;
}
void Sapo::setDistancia(int d){
  distancia = d;
}
int Sapo::getQnt_pulo(){
  return qnt_pulo;
}
void Sapo::setQnt_pulo(int p){
  qnt_pulo = p;
}
int Sapo::getCorrida(){
  return corrida;
}
