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
    REGISTRO A[MAX];
    int numElementos;
} LISTA;

typedef struct
{
    int topo;
    REGISTRO A[MAX];
} PILHA;



typedef struct 
{
	int capacidade;
    REGISTRO *registro;
	int primeiro;
	int ultimo;
	int nItens; 
} FILA;


LISTA lista;
PILHA pilha;
FILA fila;

int tamanhoFila;

void limpaConsole()
{
    system("clear");
}

// Funções referentes ao tipo de estrutura lista

int buscaSequencial(LISTA *listaAbuscar, CHAVE ch)
{
    int i = 0;
    for (i = 0; i < listaAbuscar->numElementos; i++)
    {
        if (ch == listaAbuscar->A[i].chave)
            return i;
    }

    return -1;
}

bool excluirElemento(CHAVE ch, LISTA *listaAexcluir)
{
    int pos, j;
    pos = buscaSequencial(listaAexcluir, ch);
    if (pos == -1)
        return false;
    for (j = pos; j < listaAexcluir->numElementos - 1; j++)
    {
        listaAexcluir->A[j] = listaAexcluir->A[j + 1];
    }
    listaAexcluir->numElementos--;
    return true;
}

bool inserirElemento(LISTA *l, REGISTRO reg, int i)
{
    int j;
    if ((l->numElementos == MAX) || (i < 0) || (i > l->numElementos))
        return false;
    for (j = l->numElementos; j > i; j--)
    {
        l->A[j] = l->A[j - 1];
    }
    l->A[i] = reg;
    l->numElementos++;

    return true;
}

void exibir(LISTA *l)
{
    int i;
    printf("\n Lista --> \" ");
    for (i = 0; i < l->numElementos; i++)
    {
        printf("%i ", l->A[i].chave);
    }
    printf("\"\n");
}
void inicializa(LISTA *lista)
{
    lista->numElementos = 0;
}

int escolhaOperacao()
{
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
void excluirElemntoDaLista(LISTA *listaAexcluirElemento)
{
    if (listaAexcluirElemento->numElementos == 0)
    {
        limpaConsole();
        printf(" A lista está vazia! \n");
        operacoesLista();
        return;
    }
    int numero;
    printf(" Qual elemento deseja excluir? ");
    scanf("%i", &numero);
    if (excluirElemento(numero, &lista))
    {
        limpaConsole();
        printf("\n Excluido com sucesso! \n");
        operacoesLista();
    }
    else
    {
        limpaConsole();
        printf("\n Valor não econtrado! \n");
        operacoesLista();
    }
}

void ordenaLista(LISTA *listaAOrdenar)
{
    int contador, aux, i, tamanhoVet = listaAOrdenar->numElementos;

    for (contador = 1; contador < tamanhoVet; contador++)
    {
        for (i = 0; i < tamanhoVet - 1; i++)
        {
            if (listaAOrdenar->A[i].chave > listaAOrdenar->A[i + 1].chave)
            {
                aux = listaAOrdenar->A[i].chave;
                listaAOrdenar->A[i].chave = listaAOrdenar->A[i + 1].chave;
                listaAOrdenar->A[i + 1].chave = aux;
            }
        }
    }
}

bool verificaVagaLista(LISTA *listaAverifica)
{
    return listaAverifica->numElementos < 10;
}

void operacoesLista();

void inserirNaLista()
{
    printf(" \n");
    int numero;
    exibir(&lista);
    printf(" \n");
    printf(" Digite um número para incluir na lista: ");
    scanf("%i", &numero);
    if (verificaVagaLista(&lista))
    {
        REGISTRO registro;
        registro.chave = numero;
        if (inserirElemento(&lista, registro, 0))
        {
            ordenaLista(&lista);
            limpaConsole();
            operacoesLista();
        }
    }
    else
    {
        printf(" \n");
        exibir(&lista);
        printf("\n Lista cheia! \n");
        printf("\n 1 - Excluir elemento ");
        printf("\n 0 - Voltar \n");
        printf(" \n");
        printf(" O que deseja fazer? ");
        scanf("%i", &numero);
        if (numero == 1)
        {
            excluirElemntoDaLista(&lista);
        }
        else
        {
            limpaConsole();
            operacoesLista();
        }
    }
}
int main();
void operacoesLista()
{
    exibir(&lista);
    int tipoOperacao = escolhaOperacao();
    switch (tipoOperacao)
    {
    case 2:
        limpaConsole();
        inserirNaLista();
        break;
    case 1:
        excluirElemntoDaLista(&lista);
        break;
    case 0:
        limpaConsole();
        main();
        break;
    default:
        limpaConsole();
        printf(" Valor inválido! \n");
        operacoesLista();
        break;
    }
}

// Funções referentes ao tipo de estrutura pilha
void operacoesPilha();

void inicializaPilha(PILHA *pilha) {
   pilha->topo = 0;
}

bool verificaPilhaVazia(PILHA *pilha){
    return pilha->topo == 0 ? true : false;
}

bool verificaPilhaCheia(PILHA *pilha) {
	int tamanho = sizeof(pilha->A)/sizeof(int);
    return pilha->topo < tamanho  ? false : true ; 
}

void inserirPilha(PILHA *pilha, REGISTRO reg){
    pilha->A[pilha->topo++] = reg;
}

void removePilha(PILHA *pilhaExcluir){
    pilhaExcluir->A[--pilhaExcluir->topo];
}

void excluirElemntoDaPilha(PILHA *pilhaAExcluir)
{
    if (verificaPilhaVazia(&pilha))
    {
        limpaConsole();
        printf(" A pilha está vazia! \n");
        operacoesPilha();
        return;
    }
    removePilha(&pilha);
    limpaConsole();
    printf("\n Excluido com sucesso! \n");
    operacoesPilha();
}

void exibirPilha(PILHA *p) {
    printf("\n Pilha --> \" ");
	for (int i = 0; i < p->topo; i++) {
        printf("%i ", p->A[i].chave);
	}
    printf("\"\n");
}

void inserirNaPilha()
{
    printf(" \n");
    int numero;
    exibirPilha(&pilha);
    printf(" \n");
    printf(" Digite um número para incluir na pilha: ");
    scanf("%i", &numero);
    if (!verificaPilhaCheia(&pilha))
    {
        REGISTRO registro;
        registro.chave = numero;
        inserirPilha(&pilha, registro);
        limpaConsole();
        operacoesPilha();
    }
    else
    {
        printf(" \n");
        exibirPilha(&pilha);
        printf("\n Pilha cheia! \n");
        printf("\n 1 - Excluir elemento ");
        printf("\n 0 - Voltar \n");
        printf(" \n");
        printf(" O que deseja fazer? ");
        scanf("%i", &numero);
        if (numero == 1)
        {
            excluirElemntoDaPilha(&pilha);
        }
        else
        {
            limpaConsole();
            operacoesPilha();
        }
    }
}

void operacoesPilha()
{
    exibirPilha(&pilha);
    int tipoOperacao = escolhaOperacao();
    switch (tipoOperacao)
    {
    case 2:
        limpaConsole();
        inserirNaPilha();
        break;
    case 1:
        excluirElemntoDaPilha(&pilha);
        break;
    case 0:
        limpaConsole();
        main();
        break;
    default:
        limpaConsole();
        printf(" Valor inválido! \n");
        operacoesPilha();
        break;
    }
}

int escolheEstrutura()
{
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

void inicializaFila(FILA *fila) { 
	fila->capacidade = MAX;
	fila->registro = (REGISTRO*) malloc (fila->capacidade * sizeof(REGISTRO));
	fila->primeiro = 0;
	fila->ultimo = -1;
	fila->nItens = 0; 
}

void exibirFila(FILA *f){

	int cont, i;

	for ( cont=0, i= f->primeiro; cont < f->nItens; cont++){

		printf("%.2f\t",f->registro[i++]);

		if (i == f->capacidade)
			i=0;

	}
	printf("\n\n");

}

void operacoesFila()
{
    exibirFila(&fila);
    int tipoOperacao = escolhaOperacao();
    switch (tipoOperacao)
    {
    case 2:
        limpaConsole();
        printf("inserir na fila");
        break;
    case 1:
        printf("excluir da fila");
        break;
    case 0:
        limpaConsole();
        main();
        break;
    default:
        limpaConsole();
        printf(" Valor inválido! \n");
        operacoesFila();
        break;
    }
}

int main()
{
    int tipoEstrutura = escolheEstrutura();
    switch (tipoEstrutura)
    {
    case 3:
        inicializa(&lista);
        limpaConsole();
        operacoesLista();
        break;
    case 2:
        inicializaFila(&fila);
        limpaConsole();
        operacoesFila();
        break;
    case 1:
        inicializaPilha(&pilha);
        limpaConsole();
        operacoesPilha();
        break;
    default:
        printf("\n Até a próxima! \n");
        break;
    }
}