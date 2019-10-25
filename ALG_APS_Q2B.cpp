#include <iostream>
#include <stdlib.h>
#include <stdio.h>

/* Grupo
* Nome: Manoel Ribeiro , Raiza Albuquerque, Eduardo Mello
* Matricula: 2019101035, 2017101805, 2019100620
*/

using namespace std;

 #define tamanhoVet 5


bool pesquisaBinaria(int valorAserProcurado, int tamVetor, int vetor[]) {
   int esquerda, meio, direita;
   esquerda = 0; direita = tamVetor - 1;
   while (esquerda <= direita) { 
      meio = (esquerda + direita)/2; 
      if (vetor[meio] == valorAserProcurado) return true;
      if (vetor[meio] < valorAserProcurado) esquerda = meio + 1;
      else direita = meio - 1;
   }
   return false;
}


int main() {
   
   int valor, vetor[100], i, contador, aux;
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
	cout<<endl;
   
    cout<<"Digite o valor de pesquisa: "; cin>>valor;

    if(pesquisaBinaria(valor, tamanhoVet, vetor)){
       cout<<"Ok! valor encontrado"<<endl;
    }else{
        cout<<"Valor nao encontrado"<<endl;
    }
    return 0;
}
