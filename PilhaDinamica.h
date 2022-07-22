#ifndef PILHADINAMICA_H_INCLUDED
#define PILHADINAMICA_H_INCLUDED

#define MAXG 2000//maximo de ingressos suportado

typedef struct Nodop//nodop que armazena o numero do ingresso
{
    int ingressoNUMERO;//numero do ingresso
    struct Nodop *prox;
}nodop;

typedef struct//struct da pilha
{
    nodop *topo;//ponteiro do tipo noopo que representa o topo da pilha
    int quantidade;//quantidade de ingressos existentes na pilha
}pilha;

int vaziap(pilha *p)//função que verifica se a pilha está vazia
{
    return p->quantidade == 0 ? 1 : 0;
}

pilha *criap()//função que cria a pilha
{
    pilha *p = (pilha*)malloc(sizeof(pilha));//aloca um ponteiro do tipo pilha
    p->topo = NULL;//aponta o ponteiro do topo da pilha para NULL
    p->quantidade = 0;//inicia a quantidade de ingressos que possui na pilha
    return p;//retorna um ponteiro do tipo pilha
}

nodop *inserep(pilha *p, int A)//função que insere um nodo para o ingresso A na pilha
{
    nodop *novo = (nodop*)malloc(sizeof(nodop));//aloca um ponteiro do tipo nodop
    novo->ingressoNUMERO = A;//armazena o numero do ingresso A
    novo->prox = p->topo;//o novo nodop aponta para o o topo da pilha
    p->quantidade++;//incrementa a quantidade de ingressos na fila
    return novo;
}

void ColocaNaPilha(pilha *p, int A, int B, int guiche)//função para colocar os ingressos na pilha
{
    int a = A;

    while(p->quantidade != MAXG && A <= B)//enquanto a quantidade de ingressos da pilha for diferente do maximo suportado e o ingresso A for <= ao B
    {
        p->topo = inserep(p, A);//o topo da pilha recebe a função que retorna o novo topo
        A++;//incrementa o ingresso
    }
    if(A >= B)//se todos os ingressos foram armazenados
        printf("%d ingresso(s) carregado(s) no guiche %d\n", B-a+1, guiche);
    else//caso a exceda a quantidade de ingressos suportado não será armazenados todos os ingressos desejados
        printf("%d ingresso(s) carregado(s) no guiche %d\n", A-a, guiche);
}

void pushp(pilha *p, int A, int B, int guiche)
{
    if(p->quantidade != MAXG)//se a quantidade de ingressos for diferente do maximo possivel
    {
        ColocaNaPilha(p, A, B, guiche);//coloca os ingressos na pilha
    }
    else//caso a pilha esteja cheia
    {
        printf("Pilha de ingressos do guiche %d cheia!\n", guiche);
    }
}

int popp(pilha *p)//fução para retirar da o ingresso da pilha
{
    int x = p->topo->ingressoNUMERO;//armazena o numero do ingresso
    nodop * aux = p->topo->prox;//nodop auxliar que recebe o proximo ingresso do topo da pilha

    p->quantidade--;//decrementa a quantidade de ingressos
    free(p->topo);//livra o ponteiro do topo
    p->topo = aux;//topo recebe o aux que é o proximo pilha antiga
    return x;//retorna o numero do ingresso
}

void desalocarp(pilha *p)//função para desalocar a pilha
{
    nodop *aux;//nodop auxiliar paara desalocar

    while(p->topo != NULL)//enquanto o topo for diferente de NULL
    {
        aux = p->topo->prox;//auxiliar que recebe o proximo ingresso do topo da pilha
        free(p->topo);//livra o ponteiro do topo
        p->topo = aux;//topo recebe o aux que é o proximo da pilha antiga
    }
    free(p);//livra o ponteiro da pilha
}
#endif // PILHADINAMICA_H_INCLUDED
