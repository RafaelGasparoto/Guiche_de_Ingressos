#include <stdio.h>
#include <stdlib.h>
#define MAXN 21//tamanho para o vetor nome, o tamanho maximo de nome é 20 caracteres + "\0"
#define MAXC 9 //tamanho para o vetor comandos, o comando de mais caracteres é "carregar" com 8 caracteres + "\0"
//#include "FilaDinamica.h"
//#include "PilhaDinamica.h"
#include "FilaEstatica.h"
#include "PilhaEstatica.h"

int tira(fila *f, pilha *p, int guiche)//função que tira a pessoa da fila e o ingresso da pilha
{
    int total = 0;//variavel para armazenar quantidade de ingressos vendidos

    if(vazia(f))//usa uma função para verificar se a fila estiver vazia
    {
        printf("Fila vazia\n");
    }
    else
    {
        if(vaziap(p))//usa uma função para verificar se a pilha está vazia
        {
            printf("Guiche %d sem ingressos! %s triste.\n", guiche, nome(f));//notifica que o guiche está sem ingressos, usa uma função para retornar o nome da primeira pessoa da fila
            pop(f);//função para retirar a pessoa da fila
        }
        else//caso a pilha não esteja vazia
        {
            //laço que roda enquanto a pilha não estiver vazia
            //pComprouTudo função que retorna se a pessoa já comprou a quantidade que queria, caso sim retorna 1, caso nao, retorna 0
            //como o laço precisa rodar enquanto for verdade então roda enquanto as funções
            while(!vaziap(p) && !pComprouTudo(f))
            {
                printf("%s comprou ingresso %d\n", nome(f), popp(p));//notifica a pessoa que comprou o ingresso numero x, popp desempilha o ingresso no topo da pilha
                total++;//incrementa a quantidade de ingressos comprados
            }
            pop(f);//retira a pessoa da fila
        }
    }
    return total;//retorna a quantidade de ingressos comprados
}

void desalocar(fila *f, pilha *p)//função para desalocar fila e pilha
{
    desalocarf(f);//função que desaloca a fila
    desalocarp(p);//função que desaloca a pilha
}

int main()
{
    fila *f0, *f1; //ponteiros para as filas 0 e 1
    f0 = cria();//cria um ponteiro do tipo fila
    f1 = cria();
    pilha *p0, *p1;//ponteiros para as pilhas 0 e 1
    p0 = criap();//cria um ponteiro do tipo pilha
    p1 = criap();

    int ingressos, guiche, A, B, total = 0;

    //a variavel ingressos irá armazenar a quantidade de ingresssos que a pessoa quer
    //a variavel guiche irá designar o guiche em que a pessoa está
    //as variaveis A e B irão armazenar a quantidade de ingresssos que será colocado na pilha, indo de A até B
    //a variavel total irá armazenar a quantidade de ingresssos vendidos

    char comando[MAXC], nome[MAXN];

    //a variavel comando armazena o comando que a pessoa quer fazer
    //a variavel nome armazena o nome da pessoa que entra na fila

    do
    {
        printf("Comando (chega, vende, carrega): ");
        scanf("%s", comando); //armazena o comando que quer fazer
        if(strcmp(comando, "chega") == 0)//avalia o comando, caso for "chega" entra na condição
        {
            printf("Nome: ");
            scanf("%s", nome);//armazena o nome da pessoa
            printf("Quantidade de ingressos: ");
            scanf("%d", &ingressos);//armazena a quantidade de ingressos
            if(menorfila(f0, f1))//avalia qual é a menor fila
            {
                guiche = 0;//se a f0 for menor então a pessoa vai ir tambem para o guiche 0
                push(f0, nome, guiche, ingressos);//coloca a pessoa na fila 0
            }
            else
            {
                guiche = 1;//se a f1 for menor então a pessoa vai ir tambem para o guiche 1
                push(f1, nome, guiche, ingressos);//coloca a pessoa na fila 1
            }
        }
        else if(strcmp(comando, "carrega") == 0)//avalia o comando, caso for "carrega" entra na condição
        {
            printf("Guiche: ");
            scanf("%d", &guiche);//guiche que quer carregar
            printf("Numero dos ingressos (ex: 5 ate 15): ");// numero do ingresso A até o B
            scanf("%d %d", &A, &B);

            if(guiche == 0)//se o guiche for o 0
                pushp(p0, A, B, guiche);//empilha a pilha do guiche 0
            else
                pushp(p1, A, B, guiche);//empilha a pilha do guice 1
        }
        else if(strcmp(comando, "vende") == 0)//avalia o comando, caso for "vende" entra na condição
        {
            printf("Numero do guiche (0 ou 1): ");
            scanf("%d", &guiche);//guiche que quer fazer a venda

            if(guiche == 0)//caso for o guiche 0
                total += tira(f0, p0, guiche);//chama uma função que retorna um inteiro contendo o total de ingressos vendidos na ação
            else//caso for o guiche 1
                total += tira(f1, p1, guiche);//chama uma função que retorna um inteiro contendo o total de ingressos vendidos na ação
        }
        else if(strcmp(comando, "fim") == 0)//avalia o comando, caso for "fim" entra na condição
        {
            printf("total de ingressos vendidos %d\n", total);//mostra o total de ingressos vendidos

            desalocar(f0, p0);//função para desalocar a fila e pilha
            desalocar(f1, p1);
        }
        else
        {
            printf("Comando Invalido.\n");//caso a pessoa digite um comando que não existe
            fflush(stdin);//limpa o buffer para o caso de um comando invalido
        }
        system("Pause");
        system("cls");
        //printf("%d %d %d %d\n", f0->tam, f1->tam, p0->quantidade, p1->quantidade);
    }while(strcmp(comando, "fim") != 0);
    return 0;
}
