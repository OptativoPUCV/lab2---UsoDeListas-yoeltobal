#include "arraylist.h"
#include "stack.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "exercises.h"

// Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
// NO MODIFICAR
void imprime_lista(List *L) {
  int *dato;
  dato = (int *)first(L);
  printf("[");
  while (dato != NULL) {
    printf("%d ", *dato);
    dato = (int *)next(L);
  }
  printf("]\n");
}

// Ojo que la pila se vacía al imprimir y se imprime en orden inverso
// NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
  void *dato;
  printf("[");
  while ((dato = pop(P)) != NULL) {
    printf("%d ", *(int *)dato);
  }
  printf("]\n");
}

/*
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List *crea_lista() {
  
  List *L = create_list();
  for (int i = 1; i <= 10; i++){
    int* elemento = (int *) malloc(sizeof(int));
    *elemento = i;
    pushBack(L, elemento);
  }
  return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
  
  int tamLista = get_size(L);
  int suma = 0;
  int* primer = first(L);
  
  for (int i = 0; i < tamLista ;i++) {
    suma += (*primer);
    primer = next(L);
  }
  return suma; 
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List *L, int elem) {
  
  int tamLista = get_size(L);
  int* primer = first(L);

  for (int i = 0; i < tamLista; i++)
    {
      if (elem == (*primer))
      {
        popCurrent(L);
      }
      
      primer = next(L);
    }
  
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack *P1, Stack *P2) {

  Stack *Paux = create_stack();
  int tamPila = get_size(P1);
  int * dato = first(P1);
  
  for(int i = 0; i < tamPila; i++)
    {
      pushFront(Paux, dato);
      dato = next(P1);
    }
  
  dato = first(Paux);
  for(int i = 0; i < tamPila; i++)
    {
      pushFront(P2, dato);
      dato = next(Paux);
    }
  
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
  Stack *pila = create_stack();
  int tam = strlen(cadena);

  for (int i = 0; i < tam; i++) {
    
    if (cadena[i] == '(' || cadena[i] == '{' || cadena[i] ==        '[') {
      
      push(pila, &cadena[i]);
      
    } else if (cadena[i] == ')' || cadena[i] == '}' ||   
    cadena[i] == ']') {
      
      if (get_size(pila) == 0) {
        return 0; 
      }

      char *top_element = (char *)top(pila);

      if ((cadena[i] == ')' && *top_element == '(') ||
      (cadena[i] == '}' && *top_element == '{') ||
      (cadena[i] == ']' && *top_element == '[')) {
        pop(pila);
      } else {
        return 0;
      }
    }
  }

  return get_size(pila) == 0 ? 1 : 0;
}
