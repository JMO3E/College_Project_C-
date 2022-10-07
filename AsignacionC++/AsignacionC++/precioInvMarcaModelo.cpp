/// 
/// Este cpp file fue creado por Joseph Marrero
///

//variables
double totalPre;

// Funcion para guardar los valores de los inventarios de cada telefono
void guardarPrecioInventario(double precio, int inventario) {
	
	totalPre = totalPre + (precio * inventario);
}

// Funcion para devolver los valores de los inventarios al main
double totalPrecio(){

	return totalPre;
}