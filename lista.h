#ifndef _lista_
#define _lista_

typedef struct TipoItem
{
	int grau;
	double coeficiente;
}TipoItem;

typedef struct TipoCelula *ponteiro;
typedef struct TipoCelula
{
	TipoItem item;
	ponteiro ant, prox; 
}TipoCelula;

typedef struct lista
{
	ponteiro primeiro, ultimo;
}lista;


/*------------------------FUNÇÔES---------------------------*/
lista * aloca_lista();
void cria_lista(lista *l);
int vazia(lista l);
void insere(TipoItem x, lista *l);
void retira(lista *l);
void lista_recebe_lista(lista *novo, lista *x);
int calcula_grau(lista *l);
#endif
