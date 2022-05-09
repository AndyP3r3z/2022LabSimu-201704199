// gcc -o problema6.out problema6.c -lm
// Librerías.
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// Prototipar funciones.
float a(int m);
float b(int m);
float c(int m);
float d(int m);

// INICIO
int main(int argc, char const *argv[]) {
  int n; // Definir variable n.
  // Pedir el número al usuario
  puts("Ingrese un número entero mayor que 2.");
  scanf("%d", &n); // Guardamos el número en la variable
  system("clear\n"); // Limpiamos consola.
  puts("----Resultados----");
  printf("∑ k²(k-3) = %f\n", a(n)); // Inciso a
  printf("∑ 3/(k-1) = %f\n", b(n)); // Inciso b
  printf("∑ ((1+√(5))/2)^k/√(5) - ((1-√(5))/2)^k/√(5) = %f\n", c(n)); // Inciso c
  printf("∑ 0.1(3*2^(k-2)+4) = %f\n", d(n)); // Inciso d
  return 0;
}
// Inciso a
float a(int m){
  float sum = 0; // Iniciar la variable
  for (float k = 1; k <= m; k++) {
    sum += pow(k,2)*(k-3); // Sumar lo correspondiente.
  }
  return sum;
}
// Inciso b
float b(int m){
  float sum = 0; // Iniciar la variable
  for (float k = 2; k <= m; k++) {
    sum += 3/(k-1); // Sumar lo correspondiente.
  }
  return sum;
}
// Inciso c
float c(int m){
  float sum = 0; // Iniciar la variable
  for (float k = 1; k <= m; k++) {
    sum += pow((1+sqrt(5))/2,k)/sqrt(5) - pow((1-sqrt(5))/2,k)/sqrt(5); // Sumar lo correspondiente.
  }
  return sum;
}
// Inciso d
float d(int m){
  float sum = 0; // Iniciar la variable
  for (float k = 1; k <= m; k++) {
    sum += 0.1*(3*pow(2,(k-2)) + 4); // Sumar lo correspondiente.
  }
  return sum;
}
