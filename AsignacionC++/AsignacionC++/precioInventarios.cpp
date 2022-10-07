/// 
/// Este cpp file fue creado por Joseph Marrero
///

//variables
double totalPres;

// Funcion para guardar el valor del inventario para el telefono que se pidio
void guardarPrecioInventarios(double precio, int inventario, bool primeraVez) {

	// Se verifica si es la primera vez que se entra a la funcion y se utiliza para limpiar la variable Total
	if (primeraVez) {

		totalPres = 0;
	}

	totalPres = totalPres + (precio * inventario);
}

// Funcion para devolver el valor del inventario para el telefono que se pidio
double totalPrecios() {

	return totalPres;
}