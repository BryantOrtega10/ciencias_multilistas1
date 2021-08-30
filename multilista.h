#include <string>
#include <iostream>
#include <iomanip> 
#ifndef MULTILISTA_H     
#define MULTILISTA_H 

using namespace std;

class Multilista {
private:
	int tam;
	nodo* lista_cabezas[10];
	string listaCarreras[4];
	string listaActividades[4];
	void asignar_pos_nombre(nodo* nueva_persona);
	void asignar_pos_edad(nodo* nueva_persona);
	void asignar_pos_carrera(nodo* nueva_persona, int i_carrera);
	void asignar_pos_actividad(nodo* nueva_persona, int i_actividad);

public:
	Multilista() {
		tam = 0;
	}
	bool lista_vacia();
	bool lista_llena();
	int tam_lista();
	void inicializarCabezas();
	void insertar(string nombre, int edad, int i_carrera, int i_actividad);
	void listar(int i_cab);
	void buscar_nombre(string nombre);
	bool eliminar(string nombre);
	~Multilista();
};

Multilista::~Multilista() {
	while (lista_cabezas[8] != NULL)
	{
		nodo* aux = lista_cabezas[8];
		lista_cabezas[8] = aux->sig[0];
		delete aux;
	}
}

void Multilista::inicializarCabezas() {
	listaCarreras[0] = "Ing. Eléctrica";
	listaCarreras[1] = "Ing. Electrónica";
	listaCarreras[2] = "Ing. de Sistemas";
	listaCarreras[3] = "Ing. Industrial";

	listaActividades[0] = "Danza";
	listaActividades[1] = "Natación";
	listaActividades[2] = "Básquet";
	listaActividades[3] = "Béisbol";

	for (int i = 0; i < 10; i++) {
		lista_cabezas[i] = NULL;
	}
}

bool Multilista::lista_vacia() {
	return (tam == 0);
}
bool Multilista::lista_llena() {
	return (tam > 0);
}
int Multilista::tam_lista() {
	return tam;
}

void Multilista::insertar(string nombre, int edad, int i_carrera, int i_actividad) {
	nodo* nueva_persona = new nodo;
	nueva_persona->nombre = nombre;
	nueva_persona->edad = edad;
	nueva_persona->carrera = &listaCarreras[i_carrera];
	nueva_persona->actividad = &listaActividades[i_actividad];
	asignar_pos_nombre(nueva_persona);
	asignar_pos_edad(nueva_persona);
	asignar_pos_carrera(nueva_persona, i_carrera);
	asignar_pos_actividad(nueva_persona, i_actividad + 4);
	tam++;
}

void Multilista::asignar_pos_nombre(nodo* nueva_persona) {
	nodo* aux = lista_cabezas[8];
	nodo* nodoAnterior = NULL;
	if (aux == NULL) {
		nueva_persona->sig[0] = aux;
		lista_cabezas[8] = nueva_persona;
		return;
	}
	while (aux->nombre < nueva_persona->nombre && aux->sig[0] != NULL) {
		nodoAnterior = aux;
		aux = aux->sig[0];
	}
	if (aux->nombre < nueva_persona->nombre) {
		nueva_persona->sig[0] = aux->sig[0];
		nodoAnterior = aux;
	}
	else {
		nueva_persona->sig[0] = aux;
	}

	if (nodoAnterior != NULL) {
		nodoAnterior->sig[0] = nueva_persona;
	}
	else {
		lista_cabezas[8] = nueva_persona;
	}
}

void Multilista::asignar_pos_edad(nodo* nueva_persona) {
	nodo* aux = lista_cabezas[9];
	nodo* nodoAnterior = NULL;
	if (aux == NULL) {
		nueva_persona->sig[1] = aux;
		lista_cabezas[9] = nueva_persona;
		return;
	}
	while (aux->edad > nueva_persona->edad && aux->sig[1] != NULL) {
		nodoAnterior = aux;
		aux = aux->sig[1];
	}

	if (aux->edad > nueva_persona->edad) {
		nueva_persona->sig[1] = aux->sig[1];
		nodoAnterior = aux;
	}
	else {
		nueva_persona->sig[1] = aux;
	}

	if (nodoAnterior != NULL) {
		nodoAnterior->sig[1] = nueva_persona;
	}
	else {
		lista_cabezas[9] = nueva_persona;
	}
}

void Multilista::asignar_pos_carrera(nodo* nueva_persona, int i_carrera) {
	nueva_persona->sig[2] = NULL;
	if (lista_cabezas[i_carrera] == NULL) {
		lista_cabezas[i_carrera] = nueva_persona;
	}
	else {
		nodo* aux = lista_cabezas[i_carrera];
		while (aux->sig[2] != NULL) {
			aux = aux->sig[2];
		}
		aux->sig[2] = nueva_persona;
	}
}

void Multilista::asignar_pos_actividad(nodo* nueva_persona, int i_actividad) {
	nueva_persona->sig[3] = lista_cabezas[i_actividad];
	lista_cabezas[i_actividad] = nueva_persona;
}

void Multilista::buscar_nombre(string nombre) {
	nodo* aux = lista_cabezas[8];
	while (aux->nombre != nombre && aux->sig[0] != NULL) {
		aux = aux->sig[0];
	}
	if (aux->nombre == nombre) {
		cout << aux->nombre << setw(15) << "\t" << aux->edad << "\t" << *aux->carrera << "\t" << *aux->actividad << endl;
		return;
	}

	cout << "Nombre no encontrado" << endl;
	return;
}

void Multilista::listar(int i_cab) {
	int i_sig;
	if (i_cab >= 0 && i_cab <= 3) i_sig = 2;
	else if (i_cab >= 4 && i_cab <= 7) i_sig = 3;
	else if (i_cab == 8) i_sig = 0;
	else if (i_cab == 9) i_sig = 1;
	else {
		cout << "Opción invalida";
		return;
	}

	nodo* aux = lista_cabezas[i_cab];
	while (aux != NULL) {
		cout << aux->nombre << setw(15) << "\t" << aux->edad << "\t" << *aux->carrera << "\t" << *aux->actividad << endl;
		aux = aux->sig[i_sig];
	}
}

bool Multilista::eliminar(string nombre) {
	nodo* aux[4];
	aux[0] = lista_cabezas[8];
	nodo* nodoAnterior[4] = {NULL, NULL, NULL, NULL};
	if (aux == NULL) {
		return false;
	}
	while (aux[0]->nombre != nombre && aux[0]->sig[0] != NULL) {
		nodoAnterior[0] = aux[0];
		aux[0] = aux[0]->sig[0];
	}
	if (aux[0]->nombre == nombre) {
		//Buscar otros nodos anteriores 
		aux[1] = lista_cabezas[9];
		int i_carrera, i_actividad;

		if (aux[0]->carrera == &listaCarreras[0]) i_carrera = 0;
		else if (aux[0]->carrera == &listaCarreras[1]) i_carrera = 1;
		else if (aux[0]->carrera == &listaCarreras[2]) i_carrera = 2;
		else if (aux[0]->carrera == &listaCarreras[3]) i_carrera = 3;

		aux[2] = lista_cabezas[i_carrera];

		if (aux[0]->actividad == &listaActividades[0]) i_actividad = 4;
		else if (aux[0]->actividad == &listaActividades[1]) i_actividad = 5;
		else if (aux[0]->actividad == &listaActividades[2]) i_actividad = 6;
		else if (aux[0]->actividad == &listaActividades[3]) i_actividad = 7;
		
		aux[3] = lista_cabezas[i_actividad];

		while (aux[1]->nombre != nombre && aux[1]->sig[1] != NULL) {
			nodoAnterior[1] = aux[1];
			aux[1] = aux[1]->sig[1];
		}
		while (aux[2]->nombre != nombre && aux[2]->sig[2] != NULL) {
			nodoAnterior[2] = aux[2];
			aux[2] = aux[2]->sig[2];
		}
		while (aux[3]->nombre != nombre && aux[3]->sig[3] != NULL) {
			nodoAnterior[3] = aux[3];
			aux[3] = aux[3]->sig[3];
		}


		if (nodoAnterior[0] != NULL) nodoAnterior[0]->sig[0] = aux[0]->sig[0];
		else lista_cabezas[8] = aux[0]->sig[0];

		if (nodoAnterior[1] != NULL) nodoAnterior[1]->sig[1] = aux[1]->sig[1];
		else lista_cabezas[9] = aux[1]->sig[1];

		if (nodoAnterior[2] != NULL) nodoAnterior[2]->sig[2] = aux[2]->sig[2];
		else lista_cabezas[i_carrera] = aux[2]->sig[2];

		if (nodoAnterior[3] != NULL) nodoAnterior[3]->sig[3] = aux[3]->sig[3];
		else lista_cabezas[i_actividad] = aux[3]->sig[3];

		delete aux[0];
		tam--;
		return true;
	}

	return false;
}

#endif
