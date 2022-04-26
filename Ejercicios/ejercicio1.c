/*
Autor: andyp
Fecha: Tue Mar  22 16:36:16 CST 2022
Librerías: stdio
Resumen: Programa que lee 3 números reales del teclado y hace la media aritmética de los positivos.
Compilar: gcc -o ejercicio1.out ejercicio1.c
Entradas: 3 números reales
Salidas: media aritmética
*/
// Librerías
#include <stdio.h>
// Numerar los pasos del pseudocódigo
int main(){
  // 1. Inicializar variables.
  int i = 0, n = 0;
  float x = 0, sum = 0;
  // 2. Iniciar loop con la condición.
  for (i; i < 3; i++) {
    // 2.1. Leer un número.
    puts("Ingrese un número real: ");
    scanf("%f", &x);
    // 2.2. Comprobar si es mayor a 0.
    if (x > 0) {
      // 2.2.1. Si sí: sumarlo.
      sum += x;
      n ++;
    }
    // 2.2.2. Si no: no sumarlo.
  }
  // 3. Comprobar la suma.
  if (n == 0) {
    // 3.1. Igual a 0: No se ingresó ningún positivo.
    puts("No se ingresó ningún número positivo.\n");
  } else {
    // 3.2. No es igual a 0: Mostrar el primedio.
    printf("La media aritmética de los reales positivos ingresados es %.2f \n", sum/n);
  }
  return 0;
}
