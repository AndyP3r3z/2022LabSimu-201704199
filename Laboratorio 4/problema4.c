// gcc -o problema4.out problema4.c -lm
// Librerías
#include <stdio.h>
#include <math.h>
// Declaración de variables.
int matA[3][3], matB[3][3], cte;
// Variables de control y conteo.
int i, j, k;
// Prototipar funciones.
void printMatrix(int A[3][3]);
void fillVars();
void cA();
void sum();
void res();
void multi();
int detA();
void transB();
void invA();
void Gauss(int A[3][3]);
// Función principal
int main(){
  puts("\n    *** Operaciones con Matrices de 3X3 ***");
  fillVars(); // Llena las variables para comenzar.
  cA(); //2.1 Multiplica por una constante
  sum(); //2.2 Suma de matrices
  res(); //2.3 Resta de matrices
  multi(); //2.4 Multiplicación de matrices
  printf("\nEl determinante de A es: \n%d\n", detA()); //2.5 Determinante de A
  transB();//2.6 Traspuesta de B
  if (detA() != 0){ // Verificar que A tiene inversa
    puts("\nLa inversa de A es:");
    invA(); //2.7 Inversa de A
  }else{
    puts("\nLa matriz A matriz no es invertible");
  }
  puts("\nLa reducción de Gauss para A será:");//2.8 Reducción de Gauss de A
  Gauss(matA);
  puts("\nLa reducción de Gauss-Jordan para B será:");//2.9 Reducción de Gauss de B
  Gauss(matB);
  return 0;
}

void printMatrix(int A[3][3]){
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%d ", A[i][j]);
      if (j == 2){puts("\n");} // Salto de línea.
    }
  }
}
void printMatrixf(float A[3][3]){
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%.2f ", A[i][j]);
      if (j == 2){puts("\n");} // Salto de línea.
    }
  }
} // Para matrices float
void fillVars(){
  // Llena la matriz A
  puts("\nIngrese los elementos para A (#fila,#columna): ");
  for ( i = 0; i < 3; i++){
    for ( j = 0; j < 3; j++){
      printf("Ingerse a_%d,%d y preione enter: ",i+1,j+1);
      scanf("%d",&matA[i][j]);
    }
  }
  // Llena la matriz B
  puts("\nIngrese los elementos para B (#fila,#columna): ");
  for ( i = 0; i < 3; i++){
    for ( j = 0; j < 3; j++){
      printf("Ingerse b_%d,%d y preione enter: ",i+1,j+1);
      scanf("%d",&matB[i][j]);
    }
  }
  //Muestra las matrices ingresadas
  puts("\nLa matriz A es: ");
  printMatrix(matA);
  puts("\nLa matriz B es: ");
  printMatrix(matB);
  // Llena la constante
  puts("\nIngrese el valor de la constante: ");
  scanf("%d",&cte);
}
void cA(){
  int cteA[3][3];
  for ( i = 0; i < 3; i++){
    for ( j = 0; j < 3; j++){
      cteA[i][j]=cte*matA[i][j]; // Multiplicamos cada entrada por la constante.
    }
  }
  //Impresion de resultados
  printf("\nSea c = %d, la matriz %dA es: \n",cte,cte);
  printMatrix(cteA);
}
void sum(){
  int suma[3][3];
  puts("\nLa suma de A y B es: ");
  for ( i = 0; i < 3; i++){
    for ( j = 0; j < 3; j++){
      suma[i][j] = matA[i][j] + matB[i][j];
    }
  }
  printMatrix(suma);
}
void res(){
  int resta[3][3];
  puts("\nLa resta de A y B es: ");
  for ( i = 0; i < 3; i++){
    for ( j = 0; j < 3; j++){
      resta[i][j] = matA[i][j] - matB[i][j];
    }
  }
  printMatrix(resta);
}
void multi(){
  int C[3][3];
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      int sum = 0;
      // Sumar
      for (k = 0; k < 3; k++) {
        sum += matA[i][k]*matB[k][i];
      }
      C[i][j] = sum;
    }
  }
  printf("El producto de las matrices es:\n");
  printMatrix(C);
}
int detA(){
  int det = (matA[0][0]*matA[1][1]*matA[2][2]+matA[0][1]*matA[1][2]*matA[2][0]+matA[1][0]*matA[2][1]*matA[0][2])-matA[0][2]*matA[1][1]*matA[2][0]-matA[0][1]*matA[1][0]*matA[2][2]-matA[1][2]*matA[2][1]*matA[0][0];
  return det;
}
void transB(){
  int transB[3][3];
  puts("\nLa transpuesta de B es: ");
  for (i = 0; i < 3; i++){
    for (j = 0; j < 3; j++){
      transB[i][j] = matB[j][i];
    }
  }
  printMatrix(transB);
}
void invA(){
  int adjA[3][3];
  float inv[i][j];
  adjA[0][0] = +matA[1][1]*matA[2][2] - matA[2][1]*matA[1][2];
  adjA[1][0] = -matA[1][0]*matA[2][2] + matA[2][0]*matA[1][2];
  adjA[2][0] = +matA[1][0]*matA[2][1] - matA[2][0]*matA[1][1];
  adjA[0][1] = -matA[0][1]*matA[2][2] + matA[2][1]*matA[0][2];
  adjA[1][1] = +matA[0][0]*matA[2][2] - matA[2][0]*matA[0][2];
  adjA[2][1] = -matA[0][0]*matA[2][1] + matA[2][0]*matA[0][1];
  adjA[0][2] = +matA[0][1]*matA[1][2] - matA[1][1]*matA[0][2];
  adjA[1][2] = -matA[0][0]*matA[1][2] + matA[1][0]*matA[0][2];
  adjA[2][2] = +matA[0][0]*matA[1][1] - matA[1][0]*matA[0][1];
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      inv[i][j]=adjA[i][j]*pow(detA(),-1);
    }
  }
  printMatrixf(inv);
}
void Gauss(int A[3][3]){
  float aux, R[3][3];
  //2.8.1 Tomando la idea de cómo se haría a "mano" se sigue el mismo procedimietno
  for (i = 0; i < 3; i++){
    for (j = 0; j < 3; j++){
      //Verdadero: definiremos la variable g=matA[i][j]/matA[j][i] y tambien se entrara a un loop.
      if (i != j){
        aux = A[i][j]/A[j][i];
        /* for: empezando en k=o, verificara si k<4, Verdadero: empezará a definir cada elemento de
        R[i][k] = A[i][k] - aux*(A[i][j])
        y por ultimo se le aumentará a k por 1. */
        for (k = 0; k<4; k++){
          R[i][k] = A[i][k] - aux*(A[i][j]);
        }
      }
    }
  }
  printMatrixf(R);
}
