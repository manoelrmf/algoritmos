#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 10

typedef int CHAVE;

typedef struct{
    CHAVE chave;
} REGISTRO;

typedef struct{
    REGISTRO A[MAX];
    int numElementos;
} LISTA;

LISTA lista;

int buscaSequencial(LISTA* listaAbuscar, CHAVE ch){
    int i = 0;
    for(i = 0; i < listaAbuscar->numElementos; i++){
        if(ch == listaAbuscar->A[i].chave) return i;
    }

    return -1;
}

// Funções referentes ao tipo de estrutura lista

bool excluirElemento(CHAVE ch, LISTA* listaAexcluir){
    int pos, j;
    pos = buscaSequencial(listaAexcluir,ch);
    if(pos == -1) return false;
    for(j = pos; j < listaAexcluir->numElementos - 1; j++){
        listaAexcluir->A[j] = listaAexcluir->A[j+1];
    }
    listaAexcluir->numElementos--;
    return true;
}

bool inserirElemento(LISTA* l, REGISTRO reg, int i){
    int j;
    if((l->numElementos == MAX) || (i < 0) || (i > l->numElementos))
        return false;
    for(j = l->numElementos; j > i; j--){
        l->A[j] = l->A[j-1];
    }
    l->A[i] = reg;
    l->numElementos++;

    return true;
}

void exibir(LISTA* l){
    int i;
    printf("\n Lista: \" ");
    for(i = 0; i < l->numElementos; i++){
        printf("%i ", l->A[i].chave);
    }
    printf("\"\n");
}
void inicializa(LISTA* lista){
    lista->numElementos = 0;
}

int escolhaOperacaoLista(){
    int id;
    printf(" \n");
    printf(" 2 - Inserir elemento \n");
    printf(" 1 - Excluir elemento \n");
    printf(" 0 - Voltar \n");
    printf("\n Qual operação deseja fazer? ");
    scanf("%i", &id);
    return id;
}

void operacoesLista();
void excluirElemntoDaLista(){
    int numero;
     printf(" Qual elemento deseja excluir? ");
        scanf("%i", &numero);
        if (excluirElemento(numero, &lista))
        {
            printf("\n Excluido com sucesso! \n");
            operacoesLista();
        }
        else
        {
            printf("\n Erro ao excluir! \n");
            operacoesLista();
        }
}

void ordenaLista(LISTA* listaAOrdenar){
    int contador, aux, i, tamanhoVet = listaAOrdenar->numElementos;

     for (contador = 1; contador < tamanhoVet; contador++) {
	   for (i = 0; i < tamanhoVet - 1; i++) {
	     if (listaAOrdenar->A[i].chave > listaAOrdenar->A[i + 1].chave) {
	       aux = listaAOrdenar->A[i].chave;
	       listaAOrdenar->A[i].chave = listaAOrdenar->A[i + 1].chave;
	       listaAOrdenar->A[i + 1].chave = aux;
	    }
	  }
	}
}

bool verificaVagaLista(LISTA* listaAverifica){
    return listaAverifica->numElementos < 10;
}

void operacoesLista();

void inserirNaLista(){
    printf(" \n");
    printf("\nTipo de estrutura selecionada: 3 - Lista \n");
    int numero;
    exibir(&lista);
    printf(" \n");
    printf("Digite um número para incluir na lista: ");
    scanf("%i", &numero);
    if(verificaVagaLista(&lista)){ 
        REGISTRO registro;
        registro.chave = numero;
        if(inserirElemento(&lista, registro, 0)){
        ordenaLista(&lista);
        inserirNaLista();
        }
    }else{
        printf(" \n");
        exibir(&lista);
        printf("\nLista cheia! \n");
        printf("\n 1 - Excluir elemento ");
        printf("\n 0 - Voltar \n");
        printf(" \n");
        printf(" O que deseja fazer? ");
        scanf("%i", &numero);
        if(numero == 1){
           excluirElemntoDaLista();
        }else{
            operacoesLista();
        }

    }
}
int main();
void operacoesLista(){
    printf("\n Tipo de estrutura selecionada: 3 - Lista \n");
    exibir(&lista);
    int tipoOperacao = escolhaOperacaoLista();
    switch (tipoOperacao){
    case 2:
        inserirNaLista();
        break;
    case 1:
        excluirElemntoDaLista();
        break;
    default:
        main();
        break;
    }
}

// Funções referentes ao tipo de estrutura fila
void fila(){
    printf("Fila");
}

// Funções referentes ao tipo de estrutura pilha
void pilha(){
    printf("Pilha");    
}

int escolheEstrutura(){
    int id;
    printf(" \n");
    printf(" 3 - Lista \n");
    printf(" 2 - Fila \n");
    printf(" 1 - Pilha \n");
    printf(" 0 - Sair \n");
    printf("\n Qual estrutura deseja utilizar? ");
    scanf("%i", &id);
    return id;
}

int main (){
   int tipoEstrutura = escolheEstrutura();
    switch (tipoEstrutura){
    case 3:
        inicializa(&lista);
        operacoesLista();
        break;
    case 2:
        fila();
        break;
    case 1:
        pilha();        
        break;
    default:
        printf("\n Até a próxima! \n");
        break;
    }
}