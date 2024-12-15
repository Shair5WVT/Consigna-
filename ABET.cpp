#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Producto {
    string nombre;
    int cantidad;
    double precio;
};

void listarProductos(const vector<Producto>& inventario) {
    cout << "\n--- Lista de Productos ---" << endl;
    if (inventario.empty()) {
        cout << "El inventario está vacío." << endl;
    } else {
        for (size_t i = 0; i < inventario.size(); ++i) {
            cout << i + 1 << ". Nombre: " << inventario[i].nombre
                 << ", Cantidad: " << inventario[i].cantidad
                 << ", Precio: $" << fixed << setprecision(2) << inventario[i].precio << endl;
        }
    }
}

void agregarProducto(vector<Producto>& inventario) {
    Producto nuevoProducto;
    cout << "Ingrese el nombre del producto: ";
    cin.ignore();
    getline(cin, nuevoProducto.nombre);
    cout << "Ingrese la cantidad del producto: ";
    cin >> nuevoProducto.cantidad;
    cout << "RECUERDE USAR '.' PARA LOS DECIMALES\n";
    cout << "Ingrese el precio del producto: ";
    cin >> nuevoProducto.precio;
    inventario.push_back(nuevoProducto);
    cout << "Producto añadido con éxito." << endl;
}

void editarProducto(vector<Producto>& inventario) {
    listarProductos(inventario);
    if (!inventario.empty()) {
        size_t index;
        cout << "Ingrese el número del producto que desea editar: ";
        cin >> index;
        if (index > 0 && index <= inventario.size()) {
            --index; // Ajustar índice
            cout << "\n--- Editando producto ---" << endl;
            cout << "Nuevo nombre del producto (actual: " << inventario[index].nombre << "): ";
            cin.ignore();
            string nuevoNombre;
            getline(cin, nuevoNombre);
            if (!nuevoNombre.empty()) {
                inventario[index].nombre = nuevoNombre;
            }
            cout << "Nueva cantidad (actual: " << inventario[index].cantidad << "): ";
            int nuevaCantidad;
            cin >> nuevaCantidad;
            inventario[index].cantidad = nuevaCantidad;
            cout << "Nuevo precio (actual: " << inventario[index].precio << "): ";
            double nuevoPrecio;
            cin >> nuevoPrecio;
            inventario[index].precio = nuevoPrecio;
            cout << "Producto editado con éxito." << endl;
        } else {
            cout << "Número de producto inválido." << endl;
        }
    }
}

void eliminarProducto(vector<Producto>& inventario) {
    listarProductos(inventario);
    if (!inventario.empty()) {
        size_t index;
        cout << "Ingrese el número del producto que desea eliminar: ";
        cin >> index;
        if (index > 0 && index <= inventario.size()) {
            inventario.erase(inventario.begin() + index - 1);
            cout << "Producto eliminado con éxito." << endl;
        } else {
            cout << "Número de producto inválido." << endl;
        }
    }
}

int main() {
    vector<Producto> inventario;
    int opcion;
    do {
        cout << "\n--- Menú de Inventario ---" << endl;
        cout << "1. Listar productos" << endl;
        cout << "2. Añadir producto" << endl;
        cout << "3. Editar producto" << endl;
        cout << "4. Eliminar producto" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                listarProductos(inventario);
                break;
            case 2:
                agregarProducto(inventario);
                break;
            case 3:
                editarProducto(inventario);
                break;
            case 4:
                eliminarProducto(inventario);
                break;
            case 5:
                cout << "Saliendo del sistema de inventario." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
    } while (opcion != 5);
    getch();
    return 0;
}