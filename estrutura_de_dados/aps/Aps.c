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
    CHAVE *dados;
    int primeiro;
    int ultimo;
    int nItens;
} FILA;

LISTA lista;
PILHA pilha;
FILA fila;

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
void inicializaLista(LISTA *lista)
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
        operacoesPilha();
        return;
    }
    removePilha(&pilha);
    limpaConsole();
    printf("\n Excluido com sucesso! \n");
    operacoesPilha();
}

void exibirPilha(PILHA *p)
{
    printf("\n Pilha --> \" ");
    for (int i = 0; i < p->topo; i++)
    {
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

int verificaFilaVazia(FILA *f)
{ // retorna verdadeiro se a fila estÃ¡ vazia
    return (f->nItens == 0);
}

int verificaFIlaCheia(FILA *f)
{ // retorna verdadeiro se a fila estÃ¡ cheia
    return (f->nItens == f->capacidade);
}

void inserirFila(FILA *f, CHAVE valor)
{

    if (f->ultimo == f->capacidade - 1)
        f->ultimo = -1;

    f->ultimo++;
    f->dados[f->ultimo] = valor;
    f->nItens++;
}

int removeDaFila(FILA *f)
{ // pega o item do comeÃ§o da fila

    int temp = f->dados[f->primeiro++]; // pega o valor e incrementa o primeiro

    if (f->primeiro == f->capacidade)
        f->primeiro = 0;

    f->nItens--; // um item retirado
    return temp;
}

void operacoesFila();
void excluirElemntoDaFila(FILA *filaAExcluir)
{
    if (verificaFilaVazia(&fila))
    {
        limpaConsole();
        printf(" A fila está vazia! \n");
        operacoesFila();
        return;
    }
    removeDaFila(&fila);
    limpaConsole();
    printf("\n Excluido com sucesso! \n");
    operacoesFila();
}

void inicializaFila(FILA *fila)
{
    fila->capacidade = MAX;
    fila->dados = (CHAVE *)malloc(fila->capacidade * sizeof(CHAVE));
    fila->primeiro = 0;
    fila->ultimo = -1;
    fila->nItens = 0;
}

void exibirFila(FILA *f)
{
    printf("\n Fila --> \" ");
    int cont, i;
    for (cont = 0, i = f->primeiro; cont < f->nItens; cont++)
    {
        printf("%i ", f->dados[i++]);
        if (i == f->capacidade)
            i = 0;
    }
    printf("\"\n");
}

void inserirNaFila()
{
    printf(" \n");
    int numero;
    exibirFila(&fila);
    printf(" \n");
    printf(" Digite um número para incluir na fila: ");
    scanf("%i", &numero);
    if (!verificaFIlaCheia(&fila))
    {
        CHAVE valor;
        valor = numero;
        inserirFila(&fila, valor);
        limpaConsole();
        operacoesFila();
    }
    else
    {
        printf(" \n");
        exibirFila(&fila);
        printf("\n Fila cheia! \n");
        printf("\n 1 - Excluir elemento ");
        printf("\n 0 - Voltar \n");
        printf(" \n");
        printf(" O que deseja fazer? ");
        scanf("%i", &numero);
        if (numero == 1)
        {
            excluirElemntoDaFila(&fila);
        }
        else
        {
            limpaConsole();
            operacoesFila();
        }
    }
}

void operacoesFila()
{
    exibirFila(&fila);
    int tipoOperacao = escolhaOperacao();
    switch (tipoOperacao)
    {
    case 2:
        limpaConsole();
        inserirNaFila();
        break;
    case 1:
        excluirElemntoDaFila(&fila);
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
        inicializaLista(&lista);
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