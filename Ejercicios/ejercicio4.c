/*
Autor: andyp
Fecha: Tue Mar  22 16:36:16 CST 2022
Librerías: stdio
Resumen: Lee un número mayor que 1 y determina si es primo
Compilar: gcc -o ejercicio4.out ejercicio4.c
Entradas: Número mayor que 1
Salidas: Confirmación de primo.
*/
// Librerías
#include <stdio.h>
// Numerar los pasos del pseudocódigo
int main() {
  // 1. Inicializar variables
  int N, i = 2, primo = 1;
  // 2. Leer un número para determinar si es primo.
  puts("Ingrese un número entero: ");
  scanf("%d", &N);
  // 3. Iniciar loop. Condición: i < N - 1 && primo == 1
  while (i < N - 1 && primo == 1) {
    // 3.1. Comprobar si N es divisible entre i.
    if (N % i == 0) {
      // 3.1.1 Si es divisible, no es primo, cambiamos el valor de la variable.
      primo = 0;
    }
    // 3.2. Aumentamos el contador.
    i++;
  }
  // 4. Imprimir resultado
  if (primo == 0) {
    printf("%d no es primo. \n", N);
  } else {
    printf("%d es primo. \n", N);
  }
  return 0;
}
