#include <string>
#ifndef ESTRUCTURA1_H     
#define ESTRUCTURA1_H 

using namespace std;

struct nodo {
	string nombre;
	int edad;
	string* carrera;
	string* actividad;
	nodo* sig[4]; //0 - Nombre, 1 - Edad, 2 - Carrera, 3 - Actividad
};

#endif
