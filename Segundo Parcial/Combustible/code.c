// Compilar con: gcc -o executable.out code.c -lm

// 1. Preparar el programa:
//     1.1. Importar librerías.
#include <stdio.h>
#include <math.h>
//     2.2. Guardar los datos de y
float y[] = {20.20,20.90,20.60,21.30,21.75,22.05,23.62,22.95,23.80,24.00};
//     2.3. n = longitud del arreglo.
int n = sizeof(y)/sizeof(y[0]);
//     2.4. x = arreglo con numeros del 1 al 10.
float x[] = {1,2,3,4,5,6,7,8,9,10};
// Antes de continuar, prototipamos nuestras funciones
int gnuplot();// Función para sacar el archivo de gnuplot
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
  printf("Tiempo estimado para alcanzar un precio de Q.30.00: %.1f semanas", (30-b)/m);
// 	3.3. Crear el archivo de gnuplot con la función gnuplot()
  if (gnuplot() != 0){
    return 1;
  }
// 	3.4. Imprimir un mensaje de éxito y recordar al usuario correr el gnuplot (dar el comando para que sólo se tenga que copiar y pegar)
  puts("SE HA FINALIZADO CON ÉXITO. NO SE OLVIDE EJECUTAR EL ARCHIVO DE GNUPLOT CON EL SIGUIENTE COMANDO:\n");
  puts("gnuplot combustible.gp");
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
int gnuplot() {
  //    0. Preparación del archivo.
  FILE* pfile;  // Inicializamos el puntero del archivo.
  char *salida = "combustible.gp"; // Nombre del archivo.
  if ((pfile = fopen(salida, "w")) == NULL) { // Abrimos y validamos la comunicación.
    puts("Error de escritura.");
    return 1;
  }
  putc("unset label\nclear\nset terminal pdf\nset output 'tendencia.pdf'\nset title 'Tendencia de la Gasolina'\n",pfile);
  // 		1. Poner los ejes como "Semana" y "Precio por Galón (Q.)"
  putc("set xlabel 'Semana'\nset ylabel 'Precio por Galon (Q.)'\n", pfile);
  putc("set grid\n", pfile);
  // 	  2. Poner los puntos de los datos.
  putc("set style data linespoint\n", pfile);
  putc("plot 'data'\n", pfile);
  // 		3. Poner la recta que se adecúa más a los datos.
  putc("set style data line\n", pfile);
  putc("", pfile);
  // 		4. Poner los valores de m y b.
  // putc("plot m*x + b", pfile);
  // 		5. Poner el tiempo estimado para que el precio sea de Q.30.00.
  fclose(pfile);
  return 0;
}
// FIN gnuplot()
