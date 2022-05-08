//Compilar: gcc -o problema1.out problema1.c
// Se incluyen librerías.
#include <stdio.h>
// Declaramos variables.
int v[10];
char c;
// Prototipamos funciones.
void fillVector();
void printVector(char o);

// Función principal
int main(){
	fillVector(); // Llenar el vector.
	// Pedir el orden
	puts("¿En qué orden desea ver los elementos?\n'a'=ascendente\n'd'=descendente");
	scanf("%s", &c);
	// No dejar pasar hasta que se ingrese lo esperado.
	while(c != 'd' && c != 'a'){
		puts("No se ingresó un valor esperado.");
		puts("¿En qué orden desea ver los elementos?\n'a'=ascendente\n'd'=descendente");
		scanf("%s", &c);
	}
	printVector(c); // Imprimir el vector.
	return 0;
}

// Función para llenar el vector
void fillVector(){
	for (int i = 0; i < 10; i++){
		v[i] = (i + 1)*2;
	}
}

// Función para imprimir el vector.
void printVector(char o){
	// Variables auxiliares.
	int n = 1, k = 0;
	int a = 1;
	// Ver si quiere en orden contrario.
	if (o == 'd'){
		n = -1; // Cambia el sentido de recorrido del arreglo.
		k = 9; // Define el inicio y el final del recorrido.
	}
	for (int i = k; i != 9-k+n; i += n){
		printf("%d\n", v[i]); // Imprimir el valor.
	}
}
