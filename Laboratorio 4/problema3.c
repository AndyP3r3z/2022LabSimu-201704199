// gcc -o problema3.out problema3.c -lm
// Librerías.
#include <stdio.h>
#include <math.h>
// Definir variables globales.
float a[3];
float b[3];
// Prototipar funciones.
float norm(float v[3]); // Para obtener la norma de un vector.
void sum(); // Suma los dos vectores.
float dot(float v[3], float u[3]); // Producto punto.
void cross(float v[3], float u[3]); // Producto cruz.
void fillVectors(); // Llenar los dos vectores.

int main(int argc, char const *argv[]) {

  fillVectors(); // Llenar los vectores.
  puts("");
  puts("Resultados:");
  printf("||a|| = %.2f,\n||b|| = %.2f,\n", norm(a), norm(b)); // Imprimir sus normas.
  printf("a + b = "); sum(); puts(",");// Imprimir la suma de los vectores.
  printf("a • b = %.2f,\n", dot(a,b)); // Imprimir el producto punto de los vectores.
  printf("a × b = "); cross(a,b); puts(",");// Imprmir un producto vectorial
  printf("b × a = "); cross(b,a); puts(".");// Imprmir el otro producto vectorial
  return 0;
}

// Para obtener la norma de un vector.
float norm(float v[3]){
  float norma = 0;
  norma = sqrt(dot(v,v)); // por definición de norma.
  return norma;
}

// Suma de los dos vectores.
void sum(){
  static float v[3];
  printf("( ");
  for (int i = 0; i < 3; i++) {
    v[i] = a[i] + b[i]; // Sumar todas las entradas.
    printf("%.2f ", v[i]);
  }
  printf(")");
}

// Producto punto.
float dot(float v[3], float u[3]){
  float sum = 0;
  for (int i = 0; i < 3; i++) {
    sum += v[i]*u[i]; // Agregar a la suma el producto de las entradas.
  }
  return sum;
}

// Producto cruz.
void cross(float v[3], float u[3]){
  static float w[3];
  w[0] = v[1]*u[2] - v[2]*u[1];
  w[1] = v[2]*u[0] - v[0]*u[2];
  w[2] = v[0]*u[1] - v[1]*u[0];

  // Imprimir el vector
  printf("( ");
  for (int i = 0; i < 3; i++) {
    printf("%.2f ", w[i]);
  }
  printf(")");
}

// Llenar los vectores.
void fillVectors() {
  puts("Se llenará el vector a.");
  for (int i = 0; i < 3; i++) {
    printf("Ingrese la componente %d del vector a.\n", i+1);
    scanf("%f", &a[i]);
  }
  puts("Se llenará el vector b.");
  for (int i = 0; i < 3; i++) {
    printf("Ingrese la componente %d del vector b.\n", i+1);
    scanf("%f", &b[i]);
  }
}
