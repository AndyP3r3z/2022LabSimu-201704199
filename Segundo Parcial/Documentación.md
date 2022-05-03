# Documentación

## Problema 1: Precio del combustible
### Metodología

 1. Se comenzó con la abstracción del problema, analizando los dos requerimientos del programa. Se determinó que el problema se podría reducir a la utilización de sumatorias simples y sumatorias de productos y al despeje de la ecuación de la recta.
 2. Se planeó hacer primero el programa y que imprimiese los resultados en la consola, al tiempo que tomaba estos valores y escribía un archivo *gnuplot* para hacer la gráfica.
 3. Se procedió a realizar el pseudocódigo del programa de una manera ordenada y  con la ayuda de la abstracción del problema que se hizo al comienzo.


### Abstracción del problema
La primera parte requiere que, con los valores ingresados, se pueda calcular la ecuación de la recta que mejor describa el comportamiento de los datos. La ecuación de la recta tiene la forma

![y = mx + b, ](https://latex.codecogs.com/svg.image?y=mx&plus;b,)

por lo que es necesario hallar primero las variables *m* y *b*. Se puede hacer esto por medio del método de mínimos cuadrados, que hacen uso de las fórmulas

![m](https://latex.codecogs.com/svg.image?m=%5Cfrac%7Bn%5Ccdot%5Cdisplaystyle%5Csum_%7Bi=1%7D%5En%7Bx_iy_i%7D-%5Cdisplaystyle%5Csum_%7Bi=1%7D%5En%7Bx_i%7D%5Cdisplaystyle%5Csum_%7Bi=1%7D%5En%7By_i%7D%7D%7Bn%5Ccdot%5Cdisplaystyle%5Csum_%7Bi=1%7D%5En%7Bx_i%7D%5E2-%5Cleft%7C%5Cdisplaystyle%5Csum_%7Bi=1%7D%5En%7Bx_i%7D%5Cright%7C%5E2%7D)

y

![b](https://latex.codecogs.com/svg.image?b=%5Cfrac%7B%5Cdisplaystyle%5Csum_%7Bi=1%7D%5Eny_i%5Cdisplaystyle%5Csum_%7Bi=1%7D%5En%7Bx_i%7D%5E2-%5Cdisplaystyle%5Csum_%7Bi=1%7D%5Enx_i%5Cdisplaystyle%5Csum_%7Bi=1%7D%5En%7Bx_iy_i%7D%7D%7Bn%5Ccdot%5Cdisplaystyle%5Csum_%7Bi=1%7D%5En%7Bx_i%7D%5E2-%5Cleft%7C%5Cdisplaystyle%5Csum_%7Bi=1%7D%5Enx_i%5Cright%7C%5E2%7D.)

Así, esta parte del problema se reduce a poder hacer sumatorias simples y sumatorias de productos. Cabe destacar, que para este problema en específico, el valor en *x* (que representa el número de la semana) corresponde directamente al índice en la iteración.
Luego de obtener estos valores, se puede utilizar el programa *gnuplot* para graficar la comparación entre los puntos y la recta que mejor aproxima.

Por otro lado, si el gobierno tiene un tope de 30 quetzales por galón, significa que  ![y=30](https://latex.codecogs.com/svg.image?y=30). Por lo que teniendo los otros dos parámetros de la ecuación de la recta, podemos obtener cuántas semanas tardará en llegar a dicho tope si se sigue con la tendencia despejando *x*:

![enter image description here](https://latex.codecogs.com/svg.image?%5Cfrac%7By-b%7D%7Bm%7D=x.)

### Pseudocódigo


	1. Preparar el programa:
	    1.1. Importar librerías.
	    2.2. y = arreglo con datos.
	    2.3. n = longitud del arreglo.
	    2.4. x = arreglo con numeros del 1 al 10.
	INICIO PRINCIPAL
	2. Obtener los valores de m y b:
		2.1. m = ( n*sump(x,y) - sum(x)*sum(y) )/( n*sump(x,x) - (sum(x)^2) )
		2.2. b = ( sum(y)*sump(x,x) - sum(x)*sump(x,y) )/( n*sump(x,x) - (sum(x)^2) )
	3. Dar el Output:
		3.1. Imprimir los valores de m y b.
		3.2. Imprimir el valor de (y-b)/m cuando y = 30.
		3.3. Correr el gnuplot e imprimir un mensaje de éxito.
    FIN PRINCIPAL

    INICIO sum(v)
	  1. Definir una variable ans = 0.
		2. Para cada elemento del arreglo:
			2.1. Sumar dicho elemento a ans.
		3. Retornar ans.
    FIN sum(v)

    INICIO sump(v,w)
		1. Definir una variable ans = 0.
		2. Para cada par de elementos de los distintos arreglos:
			2.1. Sumar a ans el producto de los dos arreglos en la posición actual.
		3. Retornar ans.
    FIN sump(v,w)

    INICIO gnuplot()
	  1. Poner los puntos de los datos.
		2. Poner la recta que se adecúa más a los datos.
		3. Poner los ejes como "Semana" y "Precio por Galón (Q.)"
		4. Poner los valores de m y b.
		5. Obtener la gráfica.
    FIN gnuplot()

### Resultados
Con este procedimiento se determinó que
 1. La recta que más se adecúa a los datos es *y = 0.446x + 19.667*.
 2. Si se sigue con esta tendencia, la gasolina alcanzará un precio de 30 quetzales en 23.2 semanas.

## Problema 2: Bisección Newton-Raphson
### Metodología

 1. Al igual que el problema anterior, se comenzó con el análisis y la abstracción del problema. En esta abstracción se determinó que el problema se reducía a tener la función y su derivada, y poder iterar sobre una fórmula recursiva.
 2. Antes de hacer esto, se preparó la gráfica con el programa de *gnuplot* para poder hacerse una idea del valor aproximado de *x*. Con la gráfica (en [este archivo](Newton-Raphson/funci%C3%B3n.pdf)), se determinó que un buen valor aproximado era *1*.
 3. Luego de la abstracción y de asegurarse del valor aproximado del cero de la función, se procedió a escribir el pseudocódigo en *c* del problema.
 4. Se escribió el código del programa, se corrió y se comparó con lo esperado.

### Abstracción del problema
Lo primero es hacerse una idea, al menos, de dónde puede estar el cero. Por lo que se puede utilizar una graficadora para ver más o menos dónde se encuentra, así como para corroborar en el momento debido, que todo salió de acuerdo con lo esperado. Se decide usar *gnuplot* para poder hacer la gráfica.

Con la gráfica hecha, se debe pasar a resolver el problema. Se utilizará el método de Newton-Raphson para esto.
Lo primero es tener la función y su derivada, ésta última se obtuvo a mano y dió como resultado

![-e^x(sin(e^x - 2) + 1.)](https://latex.codecogs.com/svg.image?-%5Cmathrm%7Be%7D%5Ex%5Cleft%28%5Csin%5Cleft%28%5Cmathrm%7Be%7D%5Ex-2%5Cright%29&plus;1%5Cright%29.)

Luego de esto, el método de Newton-Raphson debe tener un rango en el que puede revisar si el cero de la función se encuentra allí. Ya habiendo tenido la idea por medio de la gráfica de dónde se encuentra el cero, se puede pedir al usuario que ingrese el valor aproximado de *x*, un valor de tolerancia y el máximo de iteraciones que se debería de hacer en caso no de un resultado dentro de los límites de la tolerancia.

Con todos estos datos, se puede proceder a la solución del problema. El método consiste simplemente en iterar de tal manera que se vaya aproximando cada vez más al cero de la función, mediante la relación

![x_{n+1}=x_n-\frac{f(x_n)}{f'(x_n)}.](https://latex.codecogs.com/svg.image?x_%7Bn&plus;1%7D=x_n-%5Cfrac%7Bf%28x_n%29%7D%7Bf%27%28x_n%29%7D.)

Realizar esto es bastante sencillo, mediante un ciclo *while* que siempre verifique la tolerancia y el número de iteraciones que se han realizado.

### Pseudocódigo
#### Gnuplot
	1. Preparar la Salida.
		1.1. Terminal como PDF.
		1.2. Dar nombre al archivo de salida.
	2. Preparar el el lienzo.
		2.1. Título de la gráfica.
		2.2. Etiquetas de los ejes de coordenadas.
		2.3. Ajustes visuales.
	3. Graficar función.
#### C
	1. Preparar el programa.
		1.1. Importar librerías.
		1.2. Definir funciones.
			1.2.1. f(x).
			1.2.2. f'(x).
			1.2.3. NewtonRaphson().
	INICIO PRINCIPAL
	2. Pedir al usuario los valores a utilizar.
		2.1. Valor inicial para la aproximación.
		2.2. Tolerancia mínima.
		2.3. Número máximo de iteraciones.
	3. Solucionar el problema con la función NewtonRaphson().
	4. ¿Se pasó de las iteraciones máximas?
		4.1. Sí -> Imprimir un mensaje informando que no se llegó a una solución aceptable.
		4.2. No -> Imprimir las iteraciones necesitadas y el valor encontrado.
	FIN PRINCIPAL

	INICIO f(x):
	a. Retornar cos(e^x-2)-e^x+2
	FIN f(x)

	INICIO f'(x):
	a. Retornar -e^x*(sin(e^x-2)+1)
	FIN f'(x)

	INICIO NewtonRaphson(x_0, tolerance, imax, iact, ans):
	a. Definir variables necesarias para la iteración.
	b. Hacer la primera iteración a mano (para que el ciclo tenga valores con los que trabajar).
	c. Mientras la diferencia entre los valores consecutivos de x sea mayor a la tolerancia y el número de iteraciones no haya pasado el máximo:
		c.1. Sacar el próximo valor de x.
		c.2. Avanzar a la siguiente iteración.
	d. Apuntar a la memoria para dar la respuesta.

### Resultados
Con un valor de tolerancia de 0.0000001 y luego de 3 iteraciones, se encontró que el cero de la función está aproximadamente en x = 1.007624.
