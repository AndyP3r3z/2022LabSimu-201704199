/*
Autor: andyp
Fecha: Tue Mar  22 16:36:16 CST 2022
Librerías: stdio
Resumen: Calcula la raiz cuadrada entera por defecto de un numero N positivo dado.
Compilar: gcc -o ejercicio3.out ejercicio3.c
Entradas: 3 números reales
Salidas: media aritmética
*/
// Librerías
#include <stdio.h>
// Numerar los pasos del pseudocódigo
int main() {
  // 1. Inicializar variables
  int i = 1;
  float N;
  // 2. Leer el número para sacarle raíz
  puts("Ingrese un número real: ");
  scanf("%f", &N);
  // 3. Iniciar loop. Condición: i*i <= N.
  while (i*i <= N) {
    // 3.1. Sumar 1 a i
    i += 1;
  }
  // 4. Imprimir resultado
  printf("%d /n", i - 1);
  return 0;
}
