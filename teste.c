#include <string.h>
#include <malloc.h>
#include "lista.h"
#include "polinomio.h"

int main(void) 
{
    polinomio p = constroi_polinomio("5 0 3 0 1"),
    q = constroi_polinomio("6 0 0 4 0 -1"),
    p_linha = derivada(p);

  printf("p: ");
  escreve_polinomio(p);
  printf("\n");

  printf("q: ");
  escreve_polinomio(q);
  printf("\n");

  printf("p+q: ");
  destroi_polinomio(escreve_polinomio(soma(p,q)));
  printf("\n");

  printf("p-q: ");
  destroi_polinomio(escreve_polinomio(subtrai(p,q)));
  printf("\n");

  printf("p*q: ");
  destroi_polinomio(escreve_polinomio(multiplica(p,q)));
  printf("\n");

  printf("p': ");
  escreve_polinomio(p_linha);
  printf("\n");

  printf("primitiva(p'): ");
  escreve_polinomio(primitiva(p_linha));
  printf("\n");

  printf("p(1): %f\n", avalia(p,1));
  printf("p(2): %f\n", avalia(p,2));

  destroi_polinomio(p_linha);
  destroi_polinomio(q);
  destroi_polinomio(p);
  
  return 0;
}