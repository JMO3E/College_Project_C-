/// 
/// Este cpp file fue creado por Joseph Marrero
///

//variables
int totalInvs;

// Funcion para guardar los valores de los inventarios de cada telefono
void guardarSumaInventario(int inventarios) {

	totalInvs = totalInvs + inventarios;
}

// Funcion para devolver los valores de los inventarios al main
int totalInventario() {

	return totalInvs;
}