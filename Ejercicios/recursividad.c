/*
Autor: andyp
Fecha: Tue Mar  22 16:36:16 CST 2022
Librerías: stdio
Resumen: Lee dos números enteros para generar un rango y muestra todos los que son primos dentro del rango
Compilar: gcc -o recursividad.out recursividad.c
Entradas: dos números enteros.
Salidas: números primos en ese rango
*/
#include <stdio.h>
#include <ctype.h>
int main() {
  int n;
  scanf("%d\n", &n);
  if (isdigit(n)) {
    printf("%d\n", n);
  }
  return 0;
}
