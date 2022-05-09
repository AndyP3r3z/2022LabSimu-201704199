// gcc -o problema6.out problema5.c
// Librerías.
#include <stdio.h>
// prototipar funciones.
int factorial(int n);

// Función principal.
int main(int argc, char const *argv[]) {
  int a = 1; // Número que se pedirá, es 1 por defecto.
  puts("Ingrese un número entero positivo:");
  scanf("%d", &a); // Guardamos el número.
  printf("%d! = %d\n", a, factorial(a)); // Devolvemos su factorial.
  return 0;
}

// Función recursiva.
int factorial(int n){
  if (n > 1) {
    return n*factorial(n-1); // Si es mayor a 1, que lo multiplique por el anterior.
  } else if (n == 1 || n == 0) {
    return 1; // Límite inferior.
  } else {
    return 0; // Por si algo sale mal.
  }
}
