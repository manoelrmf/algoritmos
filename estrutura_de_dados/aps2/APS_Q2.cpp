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
    int A[MAX];
} PILHA;

PILHA pilha;

void inicializaPilha(PILHA *pilha)
{
    pilha->topo = 0;
}

void push(PILHA *pilha, int reg)
{
    pilha->A[pilha->topo++] = reg;
}

void pop(PILHA *pilhaPop)
{
    pilhaPop->A[--pilhaPop->topo];
}

void add(PILHA *pilhaAdd)
{
	int topo = pilhaAdd->topo;
	topo--; int x = pilhaAdd->A[topo];
	topo--; int y = pilhaAdd->A[topo];
	int result = x + y;
	pop(&pilha);
  	push(&pilha, result);
}

bool verificaPilhaVazia(PILHA *pilha)
{
    return pilha->topo == 0 ? true : false;
}

void exibirPilha(PILHA *p)
{
    printf("\n Pilha --> \" ");
    int i;
    for (i = 0; i < p->topo; i++)
    {
        printf("%i ", p->A[i]);
    }
    printf("\"\n");
}

 main()
{
  int a = 9;
  int b = 3;
  int c = 2;
  int d = 1;
  int e = 1;
  inicializaPilha(&pilha);
  push(&pilha, a);
  push(&pilha, b);
  push(&pilha, c);
  push(&pilha, d);

  add(&pilha);
  exibirPilha(&pilha);
  	
}
