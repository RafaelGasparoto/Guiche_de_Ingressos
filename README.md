# Guiche de Ingressos

Programa feito em C que simula um guiche de venda de ingressos.  
O programa aceita 3 comandos básicos que são "carregar" para carregar uma pilha de ingressos do guiche 0 ou 1, "chega" que tem como parametos adicionais o nome de uma pessoa e a quantidade de ingressos que ela quer comprar, "vende" + o guiche que vai efetuar a venda.  
Um guiche só pode vender caso tenha ingressos, se um guiche tentar vender sem ter ingressos a pessoa sai da fila sem ingressos.  
O programa foi feito para colocar em prática o uso de filas e pilhas em C, o conceito de fila é utilizado na fila de pessoas e o conceito de pilha na pilha de ingressos do guiche.  
A pilha e a fila foi implementada tanto estática como dinamica, só é preciso alterar entre as bibliotecas no cabeçalho  

#include "FilaDinamica.h"
#include "PilhaDinamica.h"
#include "FilaEstatica.h"
#include "PilhaEstatica.h"
