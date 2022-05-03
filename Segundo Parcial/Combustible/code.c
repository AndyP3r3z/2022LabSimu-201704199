// Compilar con: gcc -o executable.out code.c -lm

// 1. Preparar el programa:
//     1.1. Importar librerías.
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//     2.2. Guardar los datos de y
float y[] = {20.20,20.90,20.60,21.30,21.75,22.05,23.62,22.95,23.80,24.00};
//     2.3. n = longitud del arreglo.
int n = sizeof(y)/sizeof(y[0]);
//     2.4. x = arreglo con numeros del 1 al 10.
float x[] = {1,2,3,4,5,6,7,8,9,10};
// Antes de continuar, prototipamos nuestras funciones
int gnuplot(float m, float b);// Función para sacar el archivo de gnuplot
float sum(float v[]);
float sump(float v[], float w[]);

// INICIO PRINCIPAL
int main(int argc, char const *argv[]) {
// 2. Obtener los valores de m y b:
// 	2.1. m
  float m;
  m = ( n*sump(x,y) - sum(x)*sum(y) )/( n*sump(x,x) - (sum(x)*sum(x)) );
// 	2.2. b
  float b;
  b = ( sum(y)*sump(x,x) - sum(x)*sump(x,y) )/( n*sump(x,x) - (sum(x)*sum(x)) );
// 3. Dar el Output:
// 	3.1. Imprimir los valores de m y b.
  printf("y = %fx + %f\n", m, b);
// 	3.2. Imprimir el valor de (y-b)/m cuando y = 30.
  printf("Tiempo estimado para alcanzar un precio de Q.30.00: %.1f semanas\n", (30-b)/m);
// 	3.3. Correr el gnuplot e imprimir un mensaje de éxito.
  gnuplot(m, b);
  puts("SE HA FINALIZADO CON ÉXITO.\n");
  return 0;
}
// FIN PRINCIPAL

// INICIO sum(v)
float sum(float v[]){
  //  1. Definir una variable ans = 0.
  float ans = 0;
  //  2. Para cada elemento del arreglo:
  for (int i = 0; i < n; i++) {
  //    2.1. Sumar dicho elemento a ans.
    ans += v[i];
  }
  //  3. Retornar ans.
  return ans;
}
// FIN sum(v)

// INICIO sump(v,w)
float sump(float v[], float w[]){
// 	1. Definir una variable ans = 0.
  float ans = 0;
// 	2. Para cada par de elementos de los distintos arreglos:
  for (int i = 0; i < n; i++) {
// 		2.1. Sumar a ans el producto de los dos arreglos en la posición actual.
    ans += v[i]*w[i];
  }
// 	3. Retornar ans.
  return ans;
}
// FIN sump(v,w)

// INICIO gnuplot()
int gnuplot(float m, float b) {
  FILE *pfile = fopen("gnuplot.gp", "wt");
  //    0. Preparación del archivo.
  fprintf(pfile, "unset label\nclear\nset terminal pdf\nset output 'tendencia.pdf'\nset title 'Tendencia de la Gasolina'\n");
  // 		1. Poner los ejes como "Semana" y "Precio por Galón (Q.)"
  fprintf(pfile, "set xlabel 'Semana'\nset ylabel 'Precio por Galon (Q.)'\n");
  fprintf(pfile, "set grid\nset key left\n");
  // 	  2. Poner los puntos de los datos.
  fprintf(pfile, "plot 'data' w p, ");
  // 		3. Poner la recta que se adecúa más a los datos.
  		// 4. Poner los valores de m y b.
  fprintf(pfile, "%.3f*x + %.3f w l\n", m, b);
  // 5. Obtener la gráfica
  fclose(pfile);
  system("gnuplot gnuplot.gp");
  return 0;
}
// FIN gnuplot()
