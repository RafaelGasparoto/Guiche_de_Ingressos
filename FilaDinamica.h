#ifndef FILADINAMICA_H_INCLUDED
#define FILADINAMICA_H_INCLUDED
#include <string.h>
#define MAXP 20//maximo de pessoas suportado pela fila
#define MAXN 21//tamanho maximo do nome da pessoa

typedef struct Nodo//nodo que armazena informa��es da pessoa na fila
{
    char nome[MAXN];//nome da pessoa
    int Ningressos;//numero de ingressos que a pessoa quer
    struct Nodo *prox;//ponteiro para o proximo nodo da fila
}nodo;

typedef struct
{
    nodo *fim, *ini;//ponteiro para o fim e para o inicio da fila
    int tam;//tamanho da fila
}fila;

fila * cria()
{
    fila *f = (fila*)malloc(sizeof(fila));//aloca um ponteiro do tipo fila

    f->fim = f->ini = NULL;//aponta o inicio e o fim da fila para NULL
    f->tam = 0;//inicia o tamanho da fila em 0
    return f;//retorna o ponteiro da fila
}

int vazia(fila *f)//fun��o que retorna se a fila est� vazia ou n�o
{
    return f->tam == 0 ? 1 : 0;
}

char *nome(fila *f)//fun��o que retorna um ponteiro do tipo char para o nome da primeira pessoa da fila
{
    return f->ini->nome;
}

int menorfila(fila *f0, fila *f1)//fun��o que retorna qual � a menor fila
{
    return f0->tam <= f1->tam ? 1 : 0;//caso o tamanho da fila 0 for <= a fila 1 ent�o retorna 1 caso contrario 0
}

nodo *insere(fila *f, char nome[MAXN], int ingressos)//fun��o que retorna um nodo com a nova pessoa da fila
{
    nodo *novo = (nodo*)malloc(sizeof(nodo));//aloca um ponteiro do tipo nodo

    novo->Ningressos = ingressos;//armazena a quantidade de ingressos que a pessoa quer
    strcpy(novo->nome, nome);//armazena o nome da pessoa
    novo->prox = NULL;//aponta o nodo para NULL

    if(f->ini == NULL)//se o ponteiro para o inicio for NULL, ou seja, se a fila estiver vazia
        f->ini = novo;//ponteiro do inicio recebe o nodo

    if(f->fim != NULL)//se o ponteiro para o fim for diferente de NULL, ou seja, j� existe pelo menos 1 pessoa na fila
        f->fim->prox = novo;//atualiza o proximo do fim da fila para apontar para o novo da fila

    f->tam++;//incrementa o tamanho da fila
    return novo;//retorna um nodo novo
}

void push(fila *f, char nome[MAXN], int guiche,int ingressos)//fun��o que coloca uma pessoa na fila
{
    if(f->tam < MAXP)//se o tamanho da fila for menor que a quantidade suportada
    {
        f->fim = insere(f, nome, ingressos);//ponteiro do fim da fila recebe o novo fim
        printf("%s entrou na fila %d\n", f->fim->nome, guiche);//notifica que a pessoa P entrou na fila X
    }
    else//caso as filas estejam cheias
        printf("%s desistiu, filas cheias.\n", nome);

    return;
}

int pComprouTudo(fila *f)//fun��o que retorna se a pessoa j� comprou a quantidade de ingressos que ela queria
{
    int x = f->ini->Ningressos--;//x recebe a quantidade de ingressos que a pessoa quer no momento e decrementa essa quantidade da pessoa

    return x == 0 ? 1 : 0;//se a pessoa j� comprou todos os ingressos que queria retorna 1, caso ainda n�o comprou a quantidade que queria retorna 0
}

void pop(fila *f)//fun��o para retirar a pessoa da fila
{
    nodo *aux = f->ini->prox;//nodo auxiliar que recebe segunda (ou NULL) pessoa da fila

    free(f->ini);//livra o nodo do primeiro da fila
    f->ini = aux;//atualiza o inicio da fila
    f->tam--;//decrementa a quantidade de pessoas da fila
    return;
}

void desalocarf(fila *f)//fun��o que desaloca a fila
{
    nodo * aux;//nodo auxiliar

    while(f->ini != NULL)//enquanto o ponteiro de inicio da fila for diferente de NULL
    {
        aux = f->ini->prox;//auxiliar recebe o proximo do inicio da fila
        free(f->ini);//livra o nodo do primeiro da fila
        f->ini = aux;//atualiza o inicio da fila
    }

    free(f);//livra o ponteiro da fila
    return;
}
#endif // FILADINAMICA_H_INCLUDED
