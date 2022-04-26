/*
Autor: andyp
Fecha: Tue Mar  22 16:36:16 CST 2022
Librerías: stdio
Resumen: Programa que pide un número indeterminado de alturas, para cuando se ingresa uno negativo y calcula la media, la altura máxima y la mínima.
Compilar: gcc -o ejercicio1.out ejercicio1.c
Entradas: 3 números reales
Salidas: media aritmética
*/
// Librerías
#include <stdio.h>
// Numerar los pasos del pseudocódigo
int main() {
  // 1. Inicializar variables
  int n = 0;
  float sum = 0, x, min, max;
  // 2. Pedir un número y guardarlo
  puts("Ingrese una altura: ");
  scanf("%f", &x);
  max = x;
  min = x;
  // 3. Iniciar loop, verificador: x >= 0.
  while (x >= 0) {
  // 3.1. Contar cuantas veces se ha repetido el loop.
  n += 1;
  // 3.2. Sumar x.
  sum += x;
  // 3.3. Verificar si es mayor que el mayor anterior (guardarlo si lo es).
  if (x > max) {
    max = x;
  }
  // 3.4. Verificar si es menor que el menor anterior (guardarlo si lo es).
  if (x < min) {
    min = x;
  }
  // 3.5. Volver a pedir un valor.
  puts("Ingrese una altura: ");
  scanf("%f", &x);
  }
  // Verificar si hubo alguno no negativo.
  if (n == 0) {
    // No hubo ninguno.
    puts("No se ingresó ningún número no negativo.\n");
  } else {
    // Hubo al menos uno.
    printf("La media de alturas es: %.2f \n", sum/n);
    printf("La mayor altura es: %.2f \n", max);
    printf("La mínima altura es: %.2f \n", min);
  }
  return 0;
}
