/// 
/// Este cpp file fue creado por Joseph Marrero
///

using namespace std;

int input;

/// <summary>
/// Funcion para enseñar el Menu de la aplicacion
/// </summary>
void Menu() {

    cout << "---------------------------------------------------------------------------" << endl;
    cout << "                                   Menu" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "           1. Cargar Datos del Archivo" << endl;
    cout << "           2. Almacenar Datos en el Archivo" << endl;
    cout << "           3. Valor del Inventario" << endl;
    cout << "           4. Valor del Inventario para marca o modelo" << endl;
    cout << "           5. Mostrar cantidad disponible para marca o modelo" << endl;
    cout << "           6. Añadir a inventario" << endl;
    cout << "           7. Vender Telefono" << endl;
    cout << "           8. Mostrar inventario en orden alfabetico para marca o modelo" << endl;
    cout << "           0. Salir" << endl;
    cout << "---------------------------------------------------------------------------\n" << endl;

    cout << "- Seleccione una opcion: " << endl;
    cout << "> ";
    cin >> input;
    cout << "\n";
};