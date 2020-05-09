/* 
    Grupo: Manoel Ribeiro (2019101035)
    GCC: 9.2.1
*/

#include <stdio.h>
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

bool verificaPilhaVazia(PILHA *pilha)
{
    return pilha->topo == 0 ? true : false;
}


void exibirPilha(PILHA *p)
{
    if (!verificaPilhaVazia(&pilha)) {
    	printf("\n Pilha --> ");
    	int i;
	    for (i = 0; i < p->topo; i++)
	    {
	       printf("%i ", p->A[i]);
	    }
	};  
}

void push(PILHA *pilhaPush, int reg)
{
    pilhaPush->A[pilhaPush->topo++] = reg;
    exibirPilha(&pilha);
}

void pop(PILHA *pilhaPop)
{
    pilhaPop->A[--pilhaPop->topo];
}

int returnX(PILHA *pilha){
 	int topo = pilha->topo;
    topo--; topo--; int x = pilha->A[topo];
}

int returnY(PILHA *pilha){
	int topo = pilha->topo;
	topo--; int y = pilha->A[topo];
}

void add(PILHA *pilhaAdd)
{
	int soma = returnX(pilhaAdd) + returnY(pilhaAdd);
	pop(&pilha); pop(&pilha);
  	push(&pilha, soma);
}

void sub(PILHA *pilhaSub)
{
	int subtracao = returnX(pilhaSub) - returnY(pilhaSub);
	pop(&pilha); pop(&pilha);
  	push(&pilha, subtracao);
}

void mpy(PILHA *pilhaMpy)
{
	int multiplicacao = returnX(pilhaMpy) * returnY(pilhaMpy);
	pop(&pilha); pop(&pilha);
  	push(&pilha, multiplicacao);
}

void div(PILHA *pilhaDiv)
{
	int divisao = returnX(pilhaDiv) / returnY(pilhaDiv);
	pop(&pilha); pop(&pilha);
  	push(&pilha, divisao);
}

void dec(PILHA *pilhaDec)
{
	int decremento = returnY(pilhaDec) - 1;
	pop(&pilha); pop(&pilha);
  	push(&pilha, decremento);
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
  sub(&pilha); 
  push(&pilha, c); 
  push(&pilha, d); 
  push(&pilha, e); 
  mpy(&pilha); 
  add(&pilha); 
  dec(&pilha); 
  div(&pilha);
  pop(&pilha);
  
}
