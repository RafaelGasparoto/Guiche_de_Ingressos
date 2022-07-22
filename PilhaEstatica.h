#ifndef PILHAESTATICA_H_INCLUDED
#define PILHAESTATICA_H_INCLUDED

#define MAXG 2000//maximo de ingressos suportado

typedef struct//struct da pilha
{
    int quantidade, topo, ingressoNUMERO[MAXG];
    //varivel para a quantidade de ingressos
    //variavel para o topo da pilha
    //variavel vetor para armazenar o numero do ingresso no espaço X da pilha
}pilha;

int vaziap(pilha *p)//função que verifica se a pilha está vazia
{
    return p->topo == -1 ? 1 : 0;
}

pilha *criap()//função que cria a pilha
{
    pilha *p = (pilha*)malloc(sizeof(pilha));//aloca um ponteiro do tipo pilha
    p->topo = -1;//inicia o topo da fila em -1
    return p;//retorna o ponteiro do tipo pilha
}

void ColocaNaPilha(pilha *p, int A, int B, int guiche)//função para colocar os ingressos na pilha
{
    int a = A;

    while(p->topo+1 < MAXG && A <= B)//enquanto a quantidade de ingressos(a quantidade de ingressos na pilha estacia é o topo+1)da pilha for menor que a quantidade do maximo suportado e o ingresso A for <= ao B
    {
        p->topo++;//incrementa o topo
        p->ingressoNUMERO[p->topo] = A;//armazena o ingresso A no topo da pilha
        A++;//incrementa o numero do ingresso
    }
    if(A >= B)//se todos os ingressos foram armazenados
        printf("%d ingresso(s) carregado(s) no guiche %d\n", B-a+1, guiche);
    else//caso a exceda a quantidade de ingressos suportado não será armazenados todos os ingressos desejados então a quantidade armazenada é igual a quantidade armazena - a o valor inicial
        printf("%d ingresso(s) carregado(s) no guiche %d\n", A-a, guiche);
}

void pushp(pilha *p, int A, int B, int guiche)
{
    if(p->topo+1 < MAXG)//se a quantidade de ingressos for diferente do maximo possivel
    {
        ColocaNaPilha(p, A, B, guiche);//coloca os ingressos na pilha
    }
    else//caso a pilha esteja cheia
    {
        printf("Pilha de ingressos do guiche %d cheia!\n", guiche);
    }
}

int popp(pilha *p)//fução para retirar o ingresso da pilha
{
    int x = p->ingressoNUMERO[p->topo];//armazena o numero do ingresso
    p->topo--;//decrementa o numero do topo no vetor
    return x;//retorna o numero do ingresso
}

void desalocarp(pilha *p)//função para desalocar o ponteiro da pilha
{
    free(p);
}
#endif // PILHAESTATICA_H_INCLUDED
