// g++ -o problema1.out problema1.cpp -lm
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
// Definir constantes.
const float G = (6.693)*pow(10,-11);
const float R_T = (6.378) * pow(10,6);
const float M_T = (5.9736)* pow(10,24);
const float R = 287.06;
const float L = 6.5 * pow(10,-3);
const float g0 = 9.81;
const float T_0 = 288.15;
const float P_0 = 101325;
const float delta = 0.1;

// Definir funciones generales.
float g(float h){ // Gravedad en función de la altura.
  return (G * M_T)/pow(R_T + h,2);
}
float rho(float h){ // Densidad del aire en función de la altura.
  if (h <= (T_0/L)) {
    return (P_0/(R*T_0))*pow(1 - ((L*h)/T_0), g0/(R*L));
  } else {
    return 0;
  }
}


// Clase Cohete
class Cohete{
public:
  // Atributos.
  string name; // Nombre.
  float E0, TSFC, CD, A, m0, mf0; // Características del Cohete.
  float y0; // Posición inicial.
public:
  // Constructor
  Cohete(string nombre, float energia, float tsfc, float cd, float area, float masa, float combustible, float pos){
    name = nombre;
    E0 = energia;
    TSFC = tsfc;
    CD = cd;
    A = area;
    m0 = masa;
    mf0 = combustible;
    y0 = pos;
  }

  ~Cohete(){}; // Destructor

  // Otros métodos
  float m(float); // Masa total del cohete.

  float mf(float); // Cambio de la masa para combustible

  float E(float); // Fuerza de empuje en función del tiempo.

  float Fa(float); // Fricción del aire.

  float a(float); // Función de aceleración.

  float v(float); // Función de velocidad (cinemática).
  float y(float); // Función de posición (cinemática).

  void properties(); // Imprime las propiedades del cohete
};

float Cohete::m(float t){ // Masa total del cohete.
  return m0 + mf(t);
}

float Cohete::mf(float t){ // Cambio de la masa para combustible
  return mf0 - (TSFC * E0 * t); // Resolución simple de la EDO.
}

float Cohete::E(float t){ // Fuerza de empuje en función del tiempo.
  if (mf(t) <= 0) {
    return 0;
  } else {
    return E0;
  }
}

float Cohete::Fa(float t){ // Fricción del aire.
  return (rho(y(t))/2)*CD*A*v(t)*sqrt(pow(v(t),2));
}

float Cohete::a(float t){ // Aceleración del cohete.
  return (E(t) - Fa(t) - m(t)*g(y(t)))/m(t);
}
float Cohete::v(float t){
  return a(t)*t;
}
float Cohete::y(float t){
  return y0 + v(t)*t + ((a(t)*pow(t,2))/2);
}

void Cohete::properties(){ // Imprime las propiedades del cohete.
    cout << "------Propiedades del cohete " << name << "------"<<'\n';
    cout << "Empuje del cohete: " << E0 << '\n';
    cout << "Consumo específico del empuje: " << TSFC << '\n';
    cout << "Coeficiente de Forma: " << CD << '\n';
    cout << "Sección transversal: " << A <<'\n';
    cout << "Masa del propulsor: " << m0 <<'\n';
    cout << "Masa inicial de combustible: " << mf0 << '\n';
}

// Prototipo de una función.
void physics(Cohete cohete, string filename);

// -----------------------------MAIN------------------------------
int main() {

  // Creamos los cohetes
  Cohete cohete1("Ah Mun", 3*pow(10,7), 3.248 * pow(10,-4), 61.27, 201.06, 1.1 * pow(10,5), 1.5*pow(10,6), 0.99); // Cohete 1

  Cohete cohete2("Ahau Kin", 2.7*pow(10,7), 2.248*pow(10,-4), 61.27, 201.06, 1.1 * pow(10,5), 1.5*pow(10,6), 0.99); // Cohete 2

  Cohete cohete3("Chac", 2.5*pow(10,7), 2.248*pow(10,-4), 70.25, 215.00, 1.8 * pow(10,5), 2.1*pow(10,6), 0.99); // Cohete 3


  // ----Ahora toca hacer que los cohetes se muevan----
  string file1 = "cohete1.txt";
  string file2 = "cohete2.txt";
  string file3 = "cohete3.txt";
  physics(cohete1, file1);
  physics(cohete2, file2);
  physics(cohete3, file3);


  return 0;
}

// ---- La función para hacer la física ----
void physics(Cohete cohete, string filename){
  // Preparamos el archivo.
  FILE* pf;
  pf = fopen(filename, "wt");

  float time = 0;
  // Definimos variables que estaremos buscando.
  float yMax, tNoGas, tImpact;
  // Otras variables auxiliares.
  int yMaxFound = 0, gas = 1;

  // Comenzamos el proceso
  while (cohete.y(time) >= 0) {
    //1. Verificamos la el combustible.
    if (gas == 1) { // Si aún teníamos combustible
      if (cohete.mf(time) <= 0) { // Revisar si ya se acabó
        tNoGas = time; // Guardar el tiempo de ahora
        gas == 0; // Avisar que ya no tenemos
      }
    }
    //2. Verificamos si es altura máxima.
    if (yMaxFound == 0 && cohete.y(time - delta) < cohete.y(time) && cohete.y(time + delta) <= cohete.y(time)) { // Si aún no hayamos la altura máxima y los vecinos son más pequeños que el actual
      yMax = cohete.y(time); // Guardamos la altura.
      yMaxFound = 1; // Avisamos que encontramos la altura máxima.
    }

    // 3. Imprimir en un archivo los datos.
    fprintf(pf, "%f\t%f\t%f\n", time, cohete.y(time), cohete.v(time));

    // Avanzamos el tiempo.
    time += delta;
  }
  tImpact = time;
  cohete.properties();
  cout << "Altura máxima alcanzada: " << yMax << '\n';
  cout << "Tiempo en que se agotó el combustible: " << tNoGas << '\n';
  cout << "Tiempo en que impactó el suelo: " << tImpact << '\n';
  cout << '\n';
  fclose(pf); // Cerrar el respectivo archivo

}
