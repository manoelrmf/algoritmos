/* 
    Grupo: Manoel Ribeiro (2019101035)
    GCC: 9.2.1
*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 50

typedef struct
{
    int topo;
    char A[MAX];
} PILHA;

PILHA pilha;

void inicializaPilha(PILHA *pilha)
{
    pilha->topo = 0;
}

void push(PILHA *pilha, char reg)
{
    pilha->A[pilha->topo++] = reg;
}

char pop(PILHA *pilha)
{
    return pilha->A[--pilha->topo];
}

bool verificaPilhaVazia(PILHA *pilha)
{
    return pilha->topo == 0 ? true : false;
}

 main()
{
  int n = 0;
  char frase[MAX];
  printf("\nDigite uma frase: ");
  gets(frase);
  inicializaPilha(&pilha);
	while(n < MAX){
		if(frase[n] == NULL) break;
		push(&pilha, frase[n]);
		n++;
	}
	
	while(!verificaPilhaVazia(&pilha)){
		printf("%c ", pop(&pilha));
	}
	
}
