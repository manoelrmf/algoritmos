#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define MAX 50

typedef int TIPOCHAVE;

typedef struct 
{
    TIPOCHAVE chave;    
} REGISTRO;

typedef struct 
{
    REGISTRO A[MAX];
    int nroElem;
} LISTA;

void inicializa(LISTA* l){
    l->nroElem = 0;
}

int tamanho(LISTA* l){
    return l->nroElem;
}

void exibir(LISTA* l){
    int i;
    printf("Lista: \" ");
    for(i = 0; i < l->nroElem; i++){
        printf("%i ", l->A[i].chave);
    }
    printf("\"\n");
}

int buscaSequencial(LISTA* l, TIPOCHAVE ch){
    int i = 0;
    for(i = 0; i < l->nroElem; i++){
        if(ch == l->A[i].chave) return i;
    }

    return -1;
}

bool inserirElemento(LISTA* l, REGISTRO reg, int i){
    int j;
    if((l->nroElem == MAX) || (i < 0) || (i > l->nroElem))
        return false;
    for(j = l->nroElem; j > i; j--){
        l->A[j] = l->A[j-1];
    }
    l->A[i] = reg;
    l->nroElem++;

    return true;
}

bool excluirElemento(TIPOCHAVE ch, LISTA* l){
    int pos, j;
    pos = buscaSequencial(l,ch);
    if(pos == -1) return false;
    for(j = pos; j < l->nroElem - 1; j++){
        l->A[j] = l->A[j+1];
    }
    l->nroElem--;
    return true;
}

void reinicializarLista(LISTA* l){
    l->nroElem = 0;
}

int main (){
    LISTA lista;
    inicializa(&lista);
    REGISTRO reg;
    reg.chave = 0;
    if(inserirElemento(&lista, reg, 0)){
        printf("Inserido com sucesso \n");
    }

    if(buscaSequencial(&lista, 1) != -1){
        printf("Encontrado \n");
    } else{
        printf ("Nao encontrado \n");
    }

}