/*
Autor: andyp
Fecha: Tue Mar  22 16:36:16 CST 2022
Librerías: stdio
Resumen: Lee dos números enteros para generar un rango y muestra todos los que son primos dentro del rango
Compilar: gcc -o ejercicio5.out ejercicio5.c
Entradas: dos números enteros.
Salidas: números primos en ese rango
*/
// Librerías
#include <stdio.h>
// Numerar los pasos del pseudocódigo
// 0. Definición de función para verificar si es primo
int primo(int N){
  // 0.1. Inicializar variables
  int i = 2, value = 1;
  // 0.2. Iniciar loop. Condición: i < N - 1 && value == 1
  while (i < N - 1 && value == 1) {
    // 0.2.1. Comprobar si N es divisible entre i.
    if (N % i == 0) {
      // 0.2.1.1 Si es divisible, no es primo, cambiamos el valor de la variable.
      value = 0;
    }
    // 0.2.2. Aumentamos el contador.
    i++;
  }
  return value;
}

int main() {
  // 1. Inicializar variables
  int N1, N2;
  // 2. Leer los dos números del rango
  puts("Ingrese el límite inferior del rango: ");
  scanf("%d", &N1);
  puts("Ingrese el límite superior del rango: ");
  scanf("%d", &N2);
  puts("---------------------------------------------------------");
  printf("Los números primos dentro del rango [ %d , %d ) son: \n", N1, N2);
  // 3. Iniciar loop. N1<=i<=N2.
  for (int i = N1; i < N2; i++) {
    // 3.1. Verificar si es primo. Escribirlo si lo es.
    if (primo(i) == 1) {
      printf("%d\n", i);
    }
  }
  return 0;
}
