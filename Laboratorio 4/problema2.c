// COMPILAR: gcc -o problema2.out problema2.c
// Librería
#include <stdio.h>
// Definir variables
int v[5];
// Prototipar funciones
void fillVector();
void sort();
void printVector();

// Inicio del Main
int main(int argc, char const *argv[]) {
  fillVector(); // Llenamos el vector
  printVector();
  sort(); // Luego lo ordenamos
  printVector(); // Por último, lo imprimimos
  return 0;
}

// Llenar el vector
void fillVector(){
  int n = 0;
  for (int i = 0; i < 5; i++) {
    printf("Ingrese un número entero.\n");
    scanf("%d", &n);
    v[i] = n;
    }
  }

// Ordenar el vector
void sort(){
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4-i; j++) {
      if (v[j] > v[j+1]) {
        int aux = v[j];
        v[j] = v[j+1];
        v[j+1] = aux;
      }
    }
  }
}

// Imprimir el vector
void printVector(){
  puts("El vector ordenado es:");
  for (int i = 0; i < 5; i++) {
    printf("%d ", v[i]);
  }
  puts("");
}
