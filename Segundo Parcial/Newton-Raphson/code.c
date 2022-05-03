// Compilar con gcc -o executable.out code.c -lm

	// 1. Preparar el programa.
	// 	1.1. Importar librerías.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
	// 	1.2. Definir funciones.
	// 		1.2.1. f(x).
float f(float x);
	// 		1.2.2. f'(x).
float df(float x);
	// 		1.2.3. NewtonRaphson().
void NewtonRaphson(float x_0, float tol, int imax, int *iact, float *ans);
	// INICIO PRINCIPAL.
void main(void){
  // definir variables
  float x_ini, tolerance, xS;
  int it, Ait;

	// 2. Pedir al usuario los valores a utilizar.
	// 	2.1. Valor inicial para la aproximación.
  puts("Ingrese el valor aproximado de x");
  scanf("%f", &x_ini);
	// 	2.2. Tolerancia mínima.
  puts("Ingrese el valor de tolerancia");
  scanf("%f", &tolerance);
	// 	2.3. Número máximo de iteraciones.
  puts("Ingrese el valor maximo de iteraciones");
  scanf("%d", &it);

	// 3. Solucionar el problema con la función NewtonRaphson().
  NewtonRaphson(x_ini, tolerance,it, &Ait, &xS);
	// 4. ¿Se pasó de las iteraciones máximas?
  if (Ait == it) {
	// 	4.1. Sí -> Imprimir un mensaje informando que no se llegó a una solución aceptable.
  printf("No se llegó a una solución aceptable luego de %d iteraciones\n", it);
  } else{
	// 	4.2. No -> Imprimir las iteraciones necesitadas y el valor encontrado.
  printf("Luego de %d iteraciones, se encontró la solución x = %f\n", Ait, xS);
  }
}
  // FIN PRINCIPAL

	// INICIO f(x):
float f(float x){
	// a. Retornar cos(e^x-2)-e^x+2
  return cos(exp(x) - 2) - exp(x) + 2;
}
	// FIN f(x)

	// INICIO f'(x):
float dfdx(float x){
	// a. Retornar -e^x*(sin(e^x-2)+1)
  return -exp(x)*(sin(exp(x) - 2) + 1);
}
	// FIN f'(x)

// INICIO NewtonRaphson(x_0, tolerance, imax, iact, ans):
void NewtonRaphson(float x_0, float tol, int imax, int *iact, float *ans) {
  // a.  Definir variables necesarias para la iteración.
  float xant, x, dif;
  xant = x_0;
	// b. Hacer la primera iteración a mano (para que el ciclo tenga valores con los que trabajar).
  int i = 1;
  x = xant - f(xant)/dfdx(xant);
  dif = x - xant;
  (dif < 0)?dif = -dif:dif; // Valor absoluto de dif
	// c. Mientras la diferencia entre los valores consecutivos de x sea menor a la tolerancia y el número de iteraciones no haya pasado el máximo:
  while (dif > tol && i < imax){
	   // 	c.1. Sacar el próximo valor de x.
    xant = x;
	   // 	c.2. Avanzar a la siguiente iteración.
    x = xant - f(xant)/dfdx(xant);
    dif = x - xant;
    (dif < 0)?dif = -dif:dif; // Valor absoluto de dif
    i++;
  }
	// d. Apuntar a la memoria para dar la respuesta.
  *ans = x;
  *iact = i;
}
