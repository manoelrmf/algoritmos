#include <iostream>
#include <stdlib.h>
#include <stdio.h>

/* Grupo
* Nome: Manoel Ribeiro 
* Matricula: 2019101035
*/

using namespace std;

int main() {
   
   int valor, vetor[100], i, contador, aux;
   #define tamanhoVet 5
   bool achou;

   for(int i = 0; i < tamanhoVet; i++){
      cout<<"Posicao["<<i<<"] - Digite um numero : "; cin>>vetor[i];
   }

   for (contador = 1; contador < tamanhoVet; contador++) {
	   for (i = 0; i < tamanhoVet - 1; i++) {
	     if (vetor[i] > vetor[i + 1]) {
	       aux = vetor[i];
	       vetor[i] = vetor[i + 1];
	       vetor[i + 1] = aux;
	     }
	   }
	 }
	 
	for (int j = 0; j < tamanhoVet; j++) {
	 cout<<vetor[j]<<"  ";
	}
	printf("\n");
   
   cout<<"Digite o valor: "; cin>>valor;

   i = 0;
   achou = false;

   while(i <= tamanhoVet && !achou){
      if(vetor[i] == valor){
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
