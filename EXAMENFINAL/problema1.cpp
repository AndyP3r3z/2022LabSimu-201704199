// g++ -o problema1.out problema1.cpp -lm
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
// Definir constantes.
const double G = (6.693)*pow(10,-11);
const double R_T = (6.378) * pow(10,6);
const double M_T = (5.9736)* pow(10,24);
const double R = 287.06;
const double L = 6.5 * pow(10,-3);
const double g0 = 9.81;
const double T_0 = 288.15;
const double P_0 = 101325;
const double delta = 0.1;

// Definir funciones generales.
double g(double h){ // Gravedad en función de la altura.
  return (G * M_T)/pow(R_T + h,2);
}
double rho(double h){ // Densidad del aire en función de la altura.
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
  double E0, TSFC, CD, A, m0, mf0; // Características del Cohete.
  double y0; // Posición inicial.
public:
  // Constructor
  Cohete(string nombre, double energia, double tsfc, double cd, double area, double masa, double combustible, double pos){
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
  double m(double); // Masa total del cohete.

  double mf(double); // Cambio de la masa para combustible

  double E(double); // Fuerza de empuje en función del tiempo.

  double Fa(double); // Fricción del aire.

  double a(double); // Función de aceleración.

  double v(double); // Función de velocidad (cinemática).
  double y(double); // Función de posición (cinemática).

  void properties(); // Imprime las propiedades del cohete
};

double Cohete::m(double t){ // Masa total del cohete.
  return m0 + mf(t);
}

double Cohete::mf(double t){ // Cambio de la masa para combustible
  return mf0 - (TSFC * E0 * t); // Resolución simple de la EDO.
}

double Cohete::E(double t){ // Fuerza de empuje en función del tiempo.
  if (mf(t) <= 0) {
    return 0;
  } else {
    return E0;
  }
}

double Cohete::Fa(double t){ // Fricción del aire.
  return (rho(y(t))/2)*CD*A*v(t)*sqrt(pow(v(t),2));
}

double Cohete::a(double t){ // Aceleración del cohete.
  return (E(t) - Fa(t) - m(t)*g(y(t)))/m(t);
}
double Cohete::v(double t){
  return a(t)*t;
}
double Cohete::y(double t){
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
void physics(Cohete cohete, const char *filename);

// -----------------------------MAIN------------------------------
int main() {

  // Creamos los cohetes
  Cohete cohete1("Ah Mun", 3*pow(10,7), 3.248 * pow(10,-4), 61.27, 201.06, 1.1 * pow(10,5), 1.5*pow(10,6), 0.99); // Cohete 1

  Cohete cohete2("Ahau Kin", 2.7*pow(10,7), 2.248*pow(10,-4), 61.27, 201.06, 1.1 * pow(10,5), 1.5*pow(10,6), 0.99); // Cohete 2

  Cohete cohete3("Chac", 2.5*pow(10,7), 2.248*pow(10,-4), 70.25, 215.00, 1.8 * pow(10,5), 2.1*pow(10,6), 0.99); // Cohete 3


  // ----Ahora toca hacer que los cohetes se muevan----
  physics(cohete1, "cohete1.txt");
  physics(cohete2, "cohete2.txt");
  physics(cohete3, "cohete3.txt");


  return 0;
}

// ---- La función para hacer la física ----
void physics(Cohete cohete, const char *filename){
  // Preparamos el archivo.
  FILE* pf;
  pf = fopen(filename, "w");

  double time = 0;
  // Definimos variables que estaremos buscando.
  double yMax, tNoGas, tImpact;
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
    if (yMaxFound == 0 && cohete.y(time - delta) < cohete.y(time) && cohete.y(time + delta) <= cohete.y(time)) { // Si aún no hayamos la altura máxima y los vecinos son más pequeños que el actual.
      yMax = cohete.y(time); // Guardamos la altura.
      yMaxFound = 1; // Avisamos que encontramos la altura máxima.
    }

    // 3. Imprimir en un archivo los datos.
    fprintf(pf, "%.3lf\t%.3lf\t%.3lf\n", time, cohete.y(time), cohete.v(time));

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
