#include <iostream>
#include <stdlib.h>
#include <stdio.h>

/* Grupo
* Nome: Manoel Ribeiro 
* Matricula: 2019101035
*/

using namespace std;

int main() {
   
   int valor, tab[20], i;
   bool achou;

   for(int i = 0; i < 20; i++){
      cout<<"Posicao["<<i<<"] - Digite um numero : "; cin>>tab[i];
   }

   cout<<"Digite o valor:"; cin>>valor;

   i = 0;
   achou = false;

   while(i <= 20 && !achou){
      if(tab[i] == valor){
        achou = true;
      }else{
          i++;
      }
   }

   if(achou){
      cout<<"Ok! valor encontrado"<<endl;
   }else{
       cout<<"Valor nao encontrado"<<endl;
   }
   
    return 0;
}
