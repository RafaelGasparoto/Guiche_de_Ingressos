#ifndef FILAESTATICA_H_INCLUDED
#define FILAESTATICA_H_INCLUDED
#include <string.h>
#define MAXP 20//maximo de pessoas suportado pela fila
#define MAXN 21//tamanho maximo do nome da pessoa

typedef struct//struct da fila
{
    char nome[MAXP][MAXN];//matriz para armazenar o nome da pessoa
    int fim, ini, tam, Ningressos[MAXP];
    //fim e ini para o espaço x da fila
    //tam para o tamanho da fila
    //Ningressos que no espaço x armazena a quantidade de ingressos que a pessoa quer
}fila;

fila * cria()//função que cria a fila
{
    fila *f = (fila*)malloc(sizeof(fila));//aloca um ponteiro do tipo fila
    f->fim = f->ini = -1;//inicia o inicio e o fim da fila em  0
    f->tam = 0;//inicia o tamanho da fila
    return f;//retorna o ponteiro da fila
}

int vazia(fila *f)//função que retorna se a fila está vazia ou não
{
    return f->tam == 0 ? 1 : 0;
}

char *nome(fila *f)//função que retorna um ponteiro do tipo char para o nome da primeira pessoa da fila
{
    return f->nome[f->ini];
}

int menorfila(fila *f0, fila *f1)//função que retorna qual é a menor fila
{
    return f0->tam <= f1->tam ? 1 : 0;//caso o tamanho da fila 0 for <= a fila 1 então retorna 1 caso contrario 0
}

void insere(fila *f, char nome[MAXN], int ingressos)//função para inserir uma pessoa na fila
{
    f->fim = (f->fim+1) % MAXP;//atualiza o fim da fila

    if(f->tam == 0)//se a fila estiver vazia
        f->ini = f->fim;//o inicio da fila vai ser igual ao fim

    f->Ningressos[f->fim] = ingressos;//armazena a quantidade de ingressos que a pessoa quer
    strcpy(f->nome[f->fim], nome);//armazena o nome da pessoa
    f->tam++;//incrementa a quantidade de pessoas
}

void push(fila *f, char nome[MAXN], int guiche,int ingressos)//função que coloca uma pessoa na fila
{
    if(f->tam < MAXP)//se o tamanho da fila for menor que a quantidade suportada
    {
        insere(f, nome, ingressos);//função que coloca a pessoa na fila, poderia ser tudo aqui mesmo mas quis deixar separado
        printf("%s entrou na fila %d\n", f->nome[f->fim], guiche);//notifica que a pessoa P entrou na fila X
    }
    else//caso as filas estejam cheias
        printf("%s desistiu, filas cheias.\n", nome);
    return;
}

int pComprouTudo(fila *f)//função que retorna se a pessoa já comprou a quantidade de ingressos que ela queria
{
    int x = f->Ningressos[f->ini]--;//x recebe a quantidade de ingressos que a pessoa quer no momento e decrementa essa quantidade da pessoa

    return x == 0 ? 1 : 0;//se a pessoa já comprou todos os ingressos que queria retorna 1, caso ainda não comprou a quantidade que queria retorna 0
}

void pop(fila *f)//função para retirar a pessoa da fila
{
    f->ini = (f->ini+1) % MAXP;//atualiza o inicio da fila
    f->tam--;//diminiu o tamanho da fila
}

void desalocarf(fila *f)//função que desaloca a fila
{
    free(f);//livra o ponteiro da fila
}

#endif // FILAESTATICA_H_INCLUDED
