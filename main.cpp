#include <iostream>
#include <string>
#include "estructura.h"
#include "multilista.h"
#include <locale.h>

using namespace std;
int main(int argc, char** argv) {

	
	setlocale(LC_ALL, "spanish");
	Multilista ml;
	ml.inicializarCabezas();
	int opcion, edad, carrera, actividad;
	string nombre;
	bool volver;
		

	//0 => "Ing. Eléctrica", 1 => "Ing. Electrónica",2 => "Ing. de Sistemas", 3 => "Ing. Industrial"
	//0 => "Danza", 1=> "Natación", 2 => "Básquet", 3 => "Béisbol"

	ml.insertar("Raquel", 54, 1, 1);
	ml.insertar("Jaime", 38, 1, 1);
	ml.insertar("Arturo", 26, 1, 1);
	ml.insertar("Andrés", 22, 1, 1);
	ml.insertar("Ariana", 41, 1, 2);
	ml.insertar("Juanny", 99, 1, 2);
	ml.insertar("Mary Paz", 20, 1, 2);
	ml.insertar("Italia", 31, 1, 3);
	ml.insertar("Mario", 18, 1, 3);
	ml.insertar("Pilar", 22, 1, 3);
	ml.insertar("Xiomara", 101, 1, 3);
	
	
	cout << "\t \t ****** BIENVIDO ******"<<endl;

	do{
			cout << "\n \t ¿Que desea hacer?" <<endl;
			cout << "\n 1) Adicionar a una persona. \n 2) Ver el registro por orden Alfabetico. \n 3) Ver el registro por edades (Descendente)."
	    	    "\n 4) Ver el registro por Actividad. \n 5) Ver el registro por Carrera. \n 6) Realizar una busqueda por Nombre."
				"\n 7) Eliminar un registro. \n 8) Salir."<< endl;
				cout << "Digite la opcion: ";
			cin >> opcion;	
						
		switch (opcion){
			case (1):
				cout << "Ingrese los datos de la persona a adicionar al registro: " << endl;
				cout << "Nombre: ";
				cin.ignore();
				getline(cin,nombre);
				cout << nombre<<endl;
				nombre[0] = toupper(nombre[0]);
				for (int i=1; i<nombre.size(); i++){
					nombre[i] = tolower(nombre[i]);
					if(nombre[i-1]==' '){
						nombre[i] = toupper(nombre[i]);
					}
				}
				cout << "Edad: ";
				cin >> edad;
				
				do{				
					cout << "Digite el numero de la carrera:" << endl;
					cout << " \n 1) Ingenieria Electrica. \n 2) Ingenieria Electronica. \n 3) Ingenieria de Sistemas. \n 4) Ingenieria Industrial." << endl;
					cout << "Carrera: ";
					cin >> carrera;
					if (carrera<0 || carrera >4){
						cout << "\t \t --Digito Incorrecto, intente de nuevo--"<<endl;		
						system("PAUSE");				
						volver = true;
					}else{
					volver = false;	
					}
				}while (volver == true);

				do{
				cout << "Digite el numero de la Actividad:" << endl;
				cout << "\n 1) Danza. \n 2) Natacion. \n 3) Basquet. \n 4) Beisbol." << endl;
				cout << "Actividad: ";
				cin >> actividad;
				if (actividad<0 || actividad >4){
					cout << "\t \t --Digito Incorrecto, intente de nuevo--"<<endl;		
					system("PAUSE");							
					volver = true;
				}else{
					volver = false;
				}
				}while (volver == true);
				ml.insertar(nombre,edad,carrera-1,actividad-1);
				cout << "Se ingreso con Exito a: " << nombre << "." <<endl;
				break;
			case(2):
				cout << "El registro por orden alfabetico de los datos registrados es:" << endl;
				cout << "Nombre \t \t Edad \t Carrera \t Actividad" << endl;
				ml.listar(8);
				break;
			case (3):
				cout << "El registro por orden descendiente de edad de los datos registrados es:" << endl;
				cout << "Nombre \t \t Edad \t Carrera \t \t Actividad" << endl;
				ml.listar(9);
				break;	
			case (4):
				do{
				cout << "Seleccione la actividad sobre la cual desea conocer el registro." << endl;
				cout << "\n 1) Danza. \n 2) Natacion. \n 3) Basquet. \n 4) Beisbol." << endl;
				cout << "Actividad: ";
				cin >> actividad;
				if (actividad<0 || actividad >4){
					cout << "\t \t --Digito Incorrecto, intente de nuevo--"<<endl;		
					system("PAUSE");				
					volver = true;
				}else{
					ml.listar(actividad+3);
					volver = false;
				}
				}while (volver == true);
				
				break;
			case (5):
				do{				
					cout << "Seleccione la carrera sobre la cual desea conocer el registro." << endl;
					cout << " \n 1) Ingenieria Electrica. \n 2) Ingenieria Electronica. \n 3) Ingenieria de Sistemas. \n 4) Ingenieria Industrial." << endl;
					cout << "Carrera: ";
					cin >> carrera;
					if (carrera<0 || carrera >4){
						cout << "\t \t --Digito Incorrecto, intente de nuevo--"<<endl;										
						system("PAUSE");
						volver = true;
					}else{
					ml.listar(carrera-1);	
					volver = false;	
					}
				}while (volver == true);	
				break;
			case (6):
				cout << "Ingrese el nombre de la persona de la que desea obtener su registro: ";
				cin >> nombre;
				ml.buscar_nombre(nombre);
				break;
			case (7):
				cout << "PENDIENTE"<<endl;
				break;
			case (8):
				cout << "\n \n \t \t Muchas gracias por hacer uso de este programa. \n \t \t \t **** Hasta luego ****" <<endl;
				exit(0);
				break;
			default:
				cout << "\t \t --Digito Incorrecto, intente de nuevo--"<<endl;						
				break;
			}
			system("PAUSE");
	}while (true);
	return 0;
}
