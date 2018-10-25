//sapo.h
//Header da classe sapo
#ifndef SAP_CPP
#define SAP_CPP

#include <cstdlib> //Bibilioteca para função rand, srand
#include <ctime> //Bibilioteca para função time

//Definição da classe sapo e seus atributos
class Sapo{
  private:
      int id;
      int distancia;
      int qnt_pulo;
  public:
      Sapo();
      Sapo(int i);
      int pular();
      int getID();
      void setID(int i);
      int getDistancia();
      void setDistancia(int d);
      int getQnt_pulo();
      void setQnt_pulo(int p);
      static int corrida;
      static int getCorrida();
};
#endif
