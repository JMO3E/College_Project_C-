#pragma once

/// 
/// Este cpp file fue creado por Joseph Marrero
///

//Librerias
#include <fstream>
#include <string>

using namespace std;

//Variables Globales
string arrayInfo[500];						//array para guardar la informacion del file
string archivoActual;
int indexArr = 0;							//variable index para acomodar la informacion del file dentro del array

// Funcion para guardar la informacion al textfile
void guardarInfo() {

	//variable
	int indexSave = 0;

	ofstream archivo;

	archivo.open(archivoActual);

	while (arrayInfo[indexSave] != "---") {

		archivo << arrayInfo[indexSave] + "\n";

		indexSave++;
	}

	archivo << "---";

	archivo.close();
}

/// <summary>
/// Funcion para guardar los datos del file en el array
/// </summary>
void archivoInfo(string fInfo) {

	int x = 0;

	for (x = 0; x < 1; x++) {

		arrayInfo[indexArr] = fInfo;
	}

	indexArr++;
}

/// <summary>
/// Funcion para buscar el archivo y extraer su informacion
/// </summary>
void CargarArchivo() {

	// Variables
	int input;
	int x = 0;
	int num = 1;

	string archivos[3] = { "DB1.txt", "DB2.txt", "DB3.txt" };				//Array que guarda los archivos que se utilizaran


	indexArr = 0;

	// Loop para hacer el output de los archivos
	for (x = 0; x < 3; x++) {
		cout << num;
		cout << "- " + archivos[x] + "\n";
		num++;
	}

	cout << "\n";

	cout << "- Cual archivo deseas: " << endl;
	cout << "> ";
	cin >> input;
	cout << "\n";

	// Se verifica si el archivo existe
	try {

		if (input > x)
		{
			throw (input);
		}

		archivoActual = archivos[--input];
		input++;

		// Se comienza a extraer la informacion del archivo
		if (input <= x) {

			ifstream archivo(archivos[--input]);

			if (archivo.is_open()) {

				int y = 1;

				string info;

				while (getline(archivo, info)) {

					archivoInfo(info);

					if (info != "--") {

						if (info != "---") {

							printf("%s", info.c_str());
						}
					}

					y++;

					cout << "\n";
				}

				archivo.close();
			}
		}
	}

	catch (int _input) {
		cout << "- El archivo que seleccionastes no existe, seleccione otro." << endl;
	}

	cout << "\n";
}