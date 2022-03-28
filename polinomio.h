#ifndef _polinomio_
#define _polinomio_

#include "lista.h"
/* -------------------------------------------------------------------------- */
/* um polinomio é uma referência para uma lista */
typedef lista *polinomio;
/* -------------------------------------------------------------------------- */

polinomio constroi_polinomio(char *s);
void destroi_polinomio(polinomio p);
polinomio escreve_polinomio(polinomio p);

polinomio soma(polinomio p, polinomio q);
polinomio subtrai(polinomio p, polinomio q);
polinomio multiplica(polinomio p, polinomio q);

polinomio derivada(polinomio p);
polinomio primitiva(polinomio p);

float avalia(polinomio p, float x);

#endif
