#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

/*----------------------------------------------------------------------------*/
lista * aloca_lista()
{
	lista *l = malloc(sizeof(lista));
	l->ultimo = l->primeiro = NULL;
	return l;
}
/*----------------------------------------------------------------------------*/
void cria_lista(lista *l)
{
	l->primeiro = (ponteiro) malloc(sizeof(TipoCelula));
	l->ultimo = l->primeiro;
	l->primeiro->ant = NULL;
	l->primeiro->prox = NULL;
}
/*----------------------------------------------------------------------------*/
int vazia(lista l)
{
	return (l.ultimo == l.primeiro);
}
/*----------------------------------------------------------------------------*/
void insere(TipoItem x, lista *l)
{
	ponteiro aux = l->ultimo;

	l->ultimo->prox = (ponteiro) malloc (sizeof(TipoCelula)); 
	l->ultimo = l->ultimo->prox;
	l->ultimo->ant = aux;
	l->ultimo->item = x;
	l->ultimo->prox = NULL;
}
/*----------------------------------------------------------------------------*/
void retira(lista *l)
{
	ponteiro aux;

	aux = l->ultimo;
	l->ultimo = l->ultimo->ant;
	free (aux);
}
/*----------------------------------------------------------------------------*/
void lista_recebe_lista(lista *novo, lista *x)
{
	ponteiro aux = x->primeiro->prox;
	
	while (aux != NULL) {
		insere (aux->item, novo);
		aux = aux->prox;
	}
}
/*----------------------------------------------------------------------------*/
int calcula_grau(lista *l)
{
	return l->primeiro->prox->item.grau;
}