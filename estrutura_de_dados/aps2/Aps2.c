/* 
    Grupo: Manoel Ribeiro (2019101035)
    GCC: 9.2.1
*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 10

typedef int CHAVE;

typedef struct
{
    CHAVE chave;
} REGISTRO;

typedef struct
{
    int topo;
    REGISTRO A[MAX];
} PILHA;

PILHA pilha;

void limpaConsole()
{
    system("clear");
}

// Funções referentes ao tipo de estrutura pilha

void inicializaPilha(PILHA *pilha)
{
    pilha->topo = 0;
}

bool verificaPilhaVazia(PILHA *pilha)
{
    return pilha->topo == 0 ? true : false;
}

bool verificaPilhaCheia(PILHA *pilha)
{
    int tamanho = sizeof(pilha->A) / sizeof(int);
    return pilha->topo < tamanho ? false : true;
}

void inserirPilha(PILHA *pilha, REGISTRO reg)
{
    pilha->A[pilha->topo++] = reg;
}

void removePilha(PILHA *pilhaExcluir)
{
    pilhaExcluir->A[--pilhaExcluir->topo];
}

void excluirElemntoDaPilha(PILHA *pilhaAExcluir)
{
    if (verificaPilhaVazia(&pilha))
    {
        limpaConsole();
        printf(" A pilha está vazia! \n");
        
        return;
    }
    removePilha(&pilha);
    limpaConsole();
    printf("\n Excluido com sucesso! \n");
    
}

void exibirPilha(PILHA *p)
{
    printf("\n Pilha --> \" ");
    int i;
    for (i = 0; i < p->topo; i++)
    {
        printf("%i ", p->A[i].chave);
    }
    printf("\"\n");
}




int main()
{
  int n = 0;
  char frase[50];
  printf("\nDigite uma frase: ");
  gets(frase);
  printf("Frase %s, \n", frase);
    
//  inicializaPilha(&pilha);

  return 0;
}