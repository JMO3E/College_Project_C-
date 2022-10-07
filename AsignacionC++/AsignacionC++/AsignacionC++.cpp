/// 
/// Este cpp file fue creado por Joseph Marrero
///

//Librerias
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

//Inicializacion de los files
#include "TelefonoMovil.cpp"
#include "Menu.cpp"
#include "CargarArchivos.cpp"
#include "precioInventarios.cpp"
#include "precioInvMarcaModelo.cpp"
#include "valorInventario.cpp"


using namespace std; 

/// <summary>
/// Esta funcion se encarga de actualizar la varriable de inventario del telefono y despues se guarda en el text file o DB.
/// </summary>
void inventarioUpdate(int sum, int idx, int indDB, int indArray, string inputModelo) {

    // Este if verifica si el resultado de la resta o actualizacion no es igual a cero
    if (sum != 0) {

        // Este while se encarga de buscar el telefono que se actualizo y modifica el inventario y despues se actualiza el text file
        while (arrayInfo[indDB] != "---") {

            indArray++;

            indArray++;

            // Este if verifica si el modelo que el usuario escogio es el mismo que el que esta dentro del array y si es cierto se actualiza
            if (inputModelo == arrayInfo[indArray]) {

                idx = indArray + 2;

                arrayInfo[idx] = to_string(sum);

                // Esta funcion se encarga de actualizar el text file o DB
                guardarInfo();
            }

            indArray++;

            indArray++;

            indArray++;

            indDB = indArray;
        }
    }
}

//Funcion principal
int main() {

    // Variables
    const int total = 20;                   //variable para crear un limite en el array

    int indexObj;                           //variable para cambiar el index del objeto
    int indexDB;                            //variable para verificar cuando se llega al limite entre la informacion de los telefonos
    int indexArray;                         //variable index para buscar la informacion del telefono dentro del array

    int sum;                                //variable para guardar el resultado del inventario de las opciones 6 y 7
    int indDB;                              //variable para verificar si llegamos al final del arrayInfo
    int indArray;                           //variable pque se usa para aumentar el valor y acomodar los datos en dicho espacio
    int idx;

    bool verificar = false;                 //variable para verificar si la opcion uno ya se utilizo, de esa manera se desbloquea la opcion 2
    bool salir = false;                     //variable para verificar si el usuario quiere salir del programa

    string inputModelo, inputMarca;         //variable para guardar los inputs de las opciones 4,5,6,7
    int inputInventario;                    //variable para guardar el input de la opcion 6
    double inputPrecio;                     //variable para guardar el input de la opcion 6

    TelefonoMovil telefonos[total];         //objeto de la clase telefonoMovil

    // Este while se encarga de mantener el programa corriendo
    while (!salir) {

        // Funcion del file "Menu.cpp", donde esta el menu guardado
        Menu();

        // Este switch se encarga de verificar el input del usuario
        switch (input) {

            // Este case verifica si el usuario que terminar el programa
            case 0:

                salir = true;

                cout << "- Gracias por utilizar la aplicacion!" << endl;

            break;

            // Este case verifica si el usuario quiere extraer la informacion de los files o DB
            case 1:

                // Funcion que se encarga de extraer los datos del los text files
                CargarArchivo();

                verificar = true;

                indexObj = 0;
                indexDB = 0;                        
                indexArray = 0;

                /// <summary>
                /// Este loop se utiliza para crear los objetos
                /// </summary>
                while (arrayInfo[indexDB] != "---") {

                    indexArray++;

                    telefonos[indexObj].setMarca(arrayInfo[indexArray]);               //Se asigna la marca

                    indexArray++;

                    telefonos[indexObj].setModelo(arrayInfo[indexArray]);              //Se asigna el modelo
                    
                    indexArray++;

                    telefonos[indexObj].setPrecio(stod(arrayInfo[indexArray]));        //Se asigna el precio
                   
                    indexArray++;

                    telefonos[indexObj].setInventario(stoi(arrayInfo[indexArray]));    //Se asigna el inventario

                    indexArray++;

                    indexObj++;

                    indexDB = indexArray;
                }
                break;

            // Este case verifica si el usuario quiere crear un telefono nuevo
            case 2:

                // Verifica si la opcion uno ya fue escogida y despues creas un telefono
                if (verificar) {

                    int indexCheck = 0;

                    while (arrayInfo[indexCheck] != "---") {

                        indexCheck++;
                    }

                    arrayInfo[indexCheck] = "--";

                    indexCheck++;

                    cout << "- Informacion del telefono nuevo: \n" << endl;

                    cout << "1. Marca: ";
                    cin >> arrayInfo[indexCheck];

                    indexCheck++;

                    cout << "2. Modelo: ";
                    cin >> arrayInfo[indexCheck];

                    indexCheck++;

                    cout << "3. Precio: ";
                    cin >> arrayInfo[indexCheck];

                    indexCheck++;

                    cout << "4. Inventario: ";
                    cin >> arrayInfo[indexCheck];

                    indexCheck++;

                    arrayInfo[indexCheck] = "---";

                    cout << "\n";

                    guardarInfo();

                    cout << "- Un telefono fue creado!" << endl;
                }

                else if (!verificar) {
                    cout << "- Seleccione un archivo para desbloquear esta funcionalidad utilizando la opcion numero uno." << endl;
                }

                break;
            
            // Este case verifica si el usuario quiere la suma total de precios de los distintos telefonos
            case 3:

                bool primeraVez;

                for (int index = 0; index < indexObj; index++) {

                    if (index == 0) {
                        primeraVez = true;
                    }

                    else if (index != 0) {
                        primeraVez = false;
                    }

                    // Esta funcion esta en el file "precioInventarios.cpp" y se encarga de hacer la suma
                    guardarPrecioInventarios(telefonos[index].getPrecio(), telefonos[index].getInventario(), primeraVez);
                }

                cout << "- La suma de los precios es: ";

                // Esta funcion esta en el file "precioInventarios.cpp" y se encarga de extraer el resultado
                cout << totalPrecios() << endl;

                break;

            // Este case verifica si el usuario quiere la suma total de precios de la marca y modelo escogida
            case 4:

                cout << "- Cual telefono desea buscar: " << endl;

                cout << "1. Marca: ";
                cin >> inputMarca;

                cout << "2. Modelo: ";
                cin >> inputModelo;

                cout << endl;

                for (int index = 0; index < indexObj; index++) {

                    if (inputMarca == telefonos[index].getMarca()) {
                        if (inputModelo == telefonos[index].getModelo()) {

                            // Esta funcion esta en el file "precioInvMarcaModelo.cpp" y se encarga de hacer la suma
                            guardarPrecioInventario(telefonos[index].getPrecio(), telefonos[index].getInventario());
                        }
                    }
                }

                cout << "- La suma del precio para la marca '" + inputMarca + "' y modelo '" + inputModelo + "' es: ";

                // Esta funcion esta en el file "precioInvMarcaModelo.cpp" y se encarga de extraer el resultado
                cout << totalPrecio() << endl;
          
                break;

            // Este case verifica si el usuario quiere la suma total de invenatrios de la marca y modelo escogida
            case 5:

                cout << "- Cual telefono desea buscar: " << endl;

                cout << "1. Marca: ";
                cin >> inputMarca;

                cout << "2. Modelo: ";
                cin >> inputModelo;

                cout << endl;

                for (int index = 0; index < indexObj; index++) {

                    if (inputMarca == telefonos[index].getMarca()) {
                        if (inputModelo == telefonos[index].getModelo()) {

                            // Esta funcion esta en el file "valorInventario.cpp" y se encarga de hacer la suma
                            guardarSumaInventario(telefonos[index].getInventario());
                        }
                    }
                }

                cout << "- La suma de inventario para la marca '" + inputMarca + "' y modelo '" + inputModelo + "' es: ";

                // Esta funcion esta en el file "valorInventario.cpp" y se encarga de extraer el resultado
                cout << totalInventario() << endl;

                break;

            // Este case verifica si el usuario quiere hacer una actualizacion al inventario del telefono escogido y si no existe el telefono se crea uno
            case 6:
                
                sum = 0;
                indDB = 0;
                indArray = 0;

                cout << "- Añadir a inventario: " << endl;

                cout << "1. Marca: ";
                cin >> inputMarca;

                cout << "2. Modelo: ";
                cin >> inputModelo;

                cout << "3. Inventario: ";
                cin >> inputInventario;

                cout << endl;

                for (int index = 0; index < indexObj; index++) {

                    if (inputMarca == telefonos[index].getMarca()) {

                        if (inputModelo == telefonos[index].getModelo()) {

                            sum = telefonos[index].getInventario();

                            sum = sum + inputInventario;

                            telefonos[index].setInventario(sum);
                        }
                    }
                }

                // Esta funcion se encarga de hacer una actualizacion del inventario y esta arriba del main
                inventarioUpdate(sum, 0, indDB, indArray, inputModelo);

                // Este if verifica si el inventario es cero, y si es cierto se crea un telefono nuevo
                if (sum == 0) {

                    cout << "- Al no existir un telefono con los datos que escribistes, se creara uno. Solo necesitas añadir el precio: " << endl;

                    cout << "4. Precio: ";
                    cin >> inputPrecio;

                    cout << endl;

                    telefonos[indexObj].setMarca(inputMarca);                 //Se asigna la marca

                    telefonos[indexObj].setModelo(inputModelo);               //Se asigna el modelo

                    telefonos[indexObj].setPrecio(inputPrecio);              //Se asigna el precio

                    telefonos[indexObj].setInventario(inputInventario);      //Se asigna el inventario

                    idx = 0;

                    while (arrayInfo[indDB] != "---") {

                        indArray++;

                        indDB = indArray;
                    }

                    // Este loop se encarga se actualizar el array y despues el textfile
                    for (int z = 0; z < 6; z++) {

                        idx = indDB;

                        arrayInfo[idx] = "--";

                        z = 1 + idx;

                        arrayInfo[z] = inputMarca;

                        z++;

                        arrayInfo[z] = inputModelo;

                        z++;

                        arrayInfo[z] = to_string(inputPrecio);

                        z++;

                        arrayInfo[z] = to_string(inputInventario);

                        z++;

                        arrayInfo[z] = "---";

                        guardarInfo();
                    }
                }

                break;

            // Este case verifica si el usuario quiere vender un telefono y despues se actuliza el inventario
            case 7:

                cout << "- Cual telefono deseas vender: " << endl;
                cout << "\n";

                for (int index = 0; index < indexObj; index++) {

                    cout << "- Marca: ";
                    cout << telefonos[index].getMarca();

                    cout << endl;

                    cout << "- Modelo: ";
                    cout << telefonos[index].getModelo();

                    cout << "\n" << endl;
                }

                cout << "> Marca: ";
                cin >> inputMarca;

                cout << "> Modelo: ";
                cin >> inputModelo;

                for (int index = 0; index < indexObj; index++) {

                    if (inputMarca == telefonos[index].getMarca()) {

                        if (inputModelo == telefonos[index].getModelo()) {

                            sum = telefonos[index].getInventario();

                            if (sum > 0) {
                                
                                sum = sum - 1;
                            }

                            else if (sum <= 0) {

                                sum = 0;

                                cout << "No tenemos unidades de es modelo. ";
                            }

                            telefonos[index].setInventario(sum);
                        }
                    }
                }

                // Esta funcion se encarga de hacer una actualizacion del inventario y esta arriba del main
                inventarioUpdate(sum, 0, 0, 0, inputModelo);

                break;
            
            // Este case verifica si el usuario quiere acomodar en orden alfabetico el inventario
            case 8:

                // Estos string guardan la marca y modelo
                vector<string> arrOrdenMarca;
                vector<string> arrOrdenModelo;

                cout << "- Orden alfabetico del inventario: " << endl;

                for (int index = 0; index < indexObj; index++) {

                    arrOrdenMarca.push_back(telefonos[index].getMarca());

                    arrOrdenModelo.push_back(telefonos[index].getModelo());
                }

                cout << endl;

                // Se realiza la comparacion y se van cambiando de orden
                sort(arrOrdenMarca.begin(), arrOrdenMarca.end());

                // Se realiza la comparacion y se van cambiando de orden
                sort(arrOrdenModelo.begin(), arrOrdenModelo.end());

                for (int indx = 0; indx < arrOrdenMarca.size(); indx++) {

                    cout << arrOrdenMarca[indx] << endl;
                    cout << arrOrdenModelo[indx] << endl;

                    cout << "\n";
                }

                break;
        }
    }

    return 0;
}