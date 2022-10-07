using namespace std;

class TelefonoMovil {

    private:

    string marca;
    string modelo;
    double precio;
    int inventario;

    public:

    TelefonoMovil() {
        marca = "Generica";
        modelo = "Basico";
        precio = 50.00;
        inventario = 0;
    }

    TelefonoMovil(string _marca, string _modelo, double _precio, int _inventario) {
        marca = _marca;
        modelo = _modelo;
        precio = _precio;
        inventario = _inventario;
    }

    string getMarca() {
        return marca;
    }

    void setMarca(string _marca) {
        marca = _marca;
    }

    string getModelo() {
        return modelo;
    }

    void setModelo(string _modelo) {
        modelo = _modelo;
    }

    double getPrecio() {
        return precio;
    }

    void setPrecio(double _precio) {
        precio = _precio;
    }

    int getInventario() {
        return inventario;
    }

    void setInventario(int _inventario) {
        inventario = _inventario;
    }
};