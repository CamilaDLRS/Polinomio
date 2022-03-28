#include "polinomio.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*----------------------------------------------------------------------------*/
polinomio constroi_polinomio(char *s)
{
	int i = 0, j = 0, grau = -1;
	char *copiaCoeficiente;

	polinomio p = aloca_lista();
	cria_lista (p);
	TipoItem item;

	while (s[i] != '\0') {
		j = 0;

		if (s[i] == ' ')
			i++;

		copiaCoeficiente = malloc(sizeof(char));
		do {
			copiaCoeficiente[j] = s[i];
			j++;
			i++;
			copiaCoeficiente = realloc(copiaCoeficiente, j + 1 * sizeof(char));
		} while (s[i] != ' ' && s[i] != '\0');

		item.coeficiente = atof(copiaCoeficiente);
		insere(item, p);
		grau++;
		
		free (copiaCoeficiente);
	}

	ponteiro aux = p->primeiro->prox;

	while (aux != NULL) {
		aux->item.grau = grau;
		grau--;
		aux = aux->prox;
	}

	return p;
}
/*----------------------------------------------------------------------------*/
void destroi_polinomio(polinomio p)
{
	while (!vazia(*p))
		retira(p);
}
/*----------------------------------------------------------------------------*/
polinomio escreve_polinomio(polinomio p)
{	
	ponteiro aux = p->primeiro->prox;
	
	while (aux != NULL) {
		if (aux->item.coeficiente != 0) {

			if (aux->item.grau == 0)
				printf ("%g ", aux->item.coeficiente);

			else if (aux->item.grau == 1) {
				if (aux->item.coeficiente != 1 && aux->item.coeficiente != -1)
					printf("%gx ", aux->item.coeficiente);
				else
					if (aux->item.coeficiente == -1)
						printf("-x ");
					else
						printf("x ");
			}
			else {
				if (aux->item.coeficiente != 1 && aux->item.coeficiente != -1)
					printf("%gx^%d ", aux->item.coeficiente, aux->item.grau);
				else
					if (aux->item.coeficiente == -1)
						printf("-x^%d ", aux->item.grau);
					else
						printf("x^%d ", aux->item.grau);
			}
		}
		aux = aux->prox;

		while (aux != NULL) {
			if (aux->item.coeficiente != 0)
				if (aux->item.coeficiente > 0) {
					printf("+ ");
					break;
				}
				else
					break;
			aux = aux->prox;
		}
	}
    return p;
}
/*----------------------------------------------------------------------------*/
polinomio soma(polinomio p, polinomio q)
{
	polinomio novo = aloca_lista();
	cria_lista(novo);
	ponteiro auxN;

	int gP = calcula_grau(p), gQ = calcula_grau(q);

	if (gP >= gQ) {
		lista_recebe_lista(novo, p);
		
		auxN = novo->ultimo;
		ponteiro auxQ = q->ultimo;

		while (auxQ != NULL) {
			auxN->item.coeficiente += auxQ->item.coeficiente;
			auxN = auxN->ant;
			auxQ = auxQ->ant;
		}		
	}
	else {
		lista_recebe_lista(novo, q);

		auxN = novo->ultimo;
		ponteiro auxP = p->ultimo;
		
		while (auxP != NULL) {
			auxN->item.coeficiente += auxP->item.coeficiente;
			auxN = auxN->ant;
			auxP = auxP->ant;
		}
	}

	return novo;
}
/*----------------------------------------------------------------------------*/
polinomio multiplica(polinomio p, polinomio q)
{
	polinomio novo = aloca_lista();
	cria_lista(novo);
	ponteiro auxP = p->primeiro->prox, auxQ = q->primeiro->prox;
	ponteiro auxN, auxNFixo;
	TipoItem item;

	int maiorGrau = auxP->item.grau + auxQ->item.grau;
	item.coeficiente = 0;

	for (int i = maiorGrau; i >= 0; i--) {
		item.grau = i;
		insere(item, novo);
	}

	auxNFixo = novo->primeiro->prox;

	while (auxP != NULL) {
		auxQ = q->primeiro->prox;
		auxN = auxNFixo;

		while (auxQ != NULL) {
			auxN->item.coeficiente += auxP->item.coeficiente * auxQ->item.coeficiente;
			auxQ = auxQ->prox;
			auxN = auxN->prox;
		}
		auxNFixo = auxNFixo->prox;
		auxP = auxP->prox;
	}

	return novo;
}
/*----------------------------------------------------------------------------*/
polinomio subtrai(polinomio p, polinomio q)
{
	int gP, gQ, maiorGrau;
	polinomio novo = aloca_lista();
	cria_lista(novo);
	ponteiro auxN, auxQ, auxP;
	TipoItem item;

	gP = calcula_grau(p);
	gQ = calcula_grau(q);

	if (gP > gQ)
		maiorGrau = gP;
	else
		maiorGrau = gQ;

	item.coeficiente = 0;

	for (int i = maiorGrau; i >= 0; i--) {
		item.grau = i;
		insere(item, novo);
	}
	
	auxN = novo->ultimo;
	auxQ = q->ultimo;
	auxP = p->ultimo;

	while (auxP != NULL) {
		auxN->item.coeficiente += auxP->item.coeficiente;
		auxN = auxN->ant;
		auxP = auxP->ant;
	}

	auxN = novo->ultimo;

	while (auxQ != NULL) {
		auxN->item.coeficiente += - auxQ->item.coeficiente;
		auxN = auxN->ant;
		auxQ = auxQ->ant;
	}

	return novo;
}
/*----------------------------------------------------------------------------*/
polinomio derivada(polinomio p)
{
	polinomio novo = aloca_lista();
	cria_lista(novo);
	ponteiro auxP = p->primeiro->prox;
	TipoItem item;

	while (auxP != NULL) {
		item.coeficiente = auxP->item.coeficiente * auxP->item.grau;
		item.grau = auxP->item.grau - 1;
		insere(item, novo);
		auxP = auxP->prox;
	}

	novo->ultimo->item.coeficiente = 0;
	novo->ultimo->item.grau = 1; 

	return novo;
}
/*----------------------------------------------------------------------------*/
polinomio primitiva(polinomio p)
{
	polinomio novo = aloca_lista();
	cria_lista(novo);
	ponteiro auxP = p->primeiro->prox;
	TipoItem item;

	while (auxP != NULL) {
		item.grau = auxP->item.grau + 1;
		item.coeficiente = auxP->item.coeficiente / item.grau;
		insere(item, novo);
		auxP= auxP->prox;
	}

	return novo;
}
/*----------------------------------------------------------------------------*/
float avalia(polinomio p, float x)
{  
	float resposta = 0;

	ponteiro auxP = p->primeiro->prox;

	while (auxP != NULL && auxP->item.grau != 0) {
		resposta += auxP->item.coeficiente * pow (x, auxP->item.grau);
		auxP = auxP->prox;
	}

	return resposta += auxP->item.coeficiente;
}