#include <string>
#include <iostream>
#ifndef MULTILISTA_H     
#define MULTILISTA_H 

using namespace std;

class Multilista {
private:
	int tam;
	nodo* lista_cabezas[10];
	string listaCarreras[4] = {"Ing. El�ctrica", "Ing. Electr�nica","Ing. de Sistemas", "Ing. Industrial"};
	string listaActividades[4] = { "Danza", "Nataci�n","B�squet", "B�isbol" };


public:
	Multilista() {
		for (int i = 0; i < 10; i++) {
			lista_cabezas[i] = NULL;
		}
		tam = 0;
	}
	bool lista_vacia();
	bool lista_llena();
	int tam_lista();
	void insertar(string nombre, int edad, int i_carrera, int i_actividad);
	void asignar_pos_nombre(nodo* nueva_persona);
	void asignar_pos_edad(nodo* nueva_persona);
	void asignar_pos_carrera(nodo* nueva_persona, int i_carrera);
	void asignar_pos_actividad(nodo* nueva_persona, int i_actividad);
	
	void listar(int i_cab);
	void buscar_nombre(string nombre);

	bool eliminar(string nombre);
};

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
	if (aux->nombre < nueva_persona->nombre){
		nueva_persona->sig[0] = aux->sig[0];
		nodoAnterior = aux;
	}
	else{
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

	if (aux->edad > nueva_persona->edad){
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
	else{
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
		cout << aux->nombre <<setw(15)<<"\t" << aux->edad << "\t" << *aux->carrera << "\t" << *aux->actividad << endl;
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
	else if (i_cab >= 9) i_sig = 1;
	else {
		cout << "Opción invalida";
		return;
	}

	nodo* aux = lista_cabezas[i_cab];
	while (aux != NULL) {
		cout << aux->nombre <<setw(15)<<"\t" << aux->edad << "\t" << *aux->carrera << "\t" << *aux->actividad << endl;
		aux = aux->sig[i_sig];
	}
}

#endif
