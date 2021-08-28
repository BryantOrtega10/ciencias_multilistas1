#include <iostream>
#include <string>
#include "estructura.h"
#include "multilista.h"
#include <locale.h>

//JOHAN

int main(int argc, char** argv) {

	setlocale(LC_ALL, "spanish");
	Multilista ml;
	
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

	ml.listar(7);//Beisbol
	cout << endl;
	ml.listar(8);//Nombre Asc
	cout << endl;
	ml.listar(9);//Edad Desc
	cout << endl;

	ml.buscar_nombre("Xiomara");
	
	

	//ml.eliminar()

	return 0;
}
