#include "Inventario.h"

// Constructor
Inventario::Inventario(int capacidadMaxima) : capacidadMaxima(capacidadMaxima) {}

// Método para dar de alta un producto
void Inventario::agregarProducto(const Producto& producto) {
    if (productos.size() >= capacidadMaxima) {
        std::cerr << "No se puede agregar el producto. Inventario lleno." << std::endl;
        return;
    }
    productos.push_back(producto);
    std::cout << "Producto agregado al inventario." << std::endl;
}

// Método para dar de baja un producto por su ID
void Inventario::eliminarProducto(int id) {
    bool encontrado = false;

    for (auto it = productos.begin(); it != productos.end(); ++it) {
        if (id == it->getIdProducto()) {
            productos.erase(it);
            std::cout << "Producto eliminado del inventario." << std::endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        std::cerr << "Producto no encontrado en el inventario." << std::endl;
    }
}

// Método para verificar si el inventario está vacío
bool Inventario::inventarioVacio() const {
    return productos.empty();
}

// Método para imprimir información de todos los productos en el inventario
void Inventario::mostrarInventario() const {
    if (productos.empty()) {
        std::cout << "El inventario está vacío." << std::endl;
        return;
    }

    std::cout << "\tInventario:" << std::endl;
    for (const auto& producto : productos) {
        producto.imprimirInfo();
        std::cout << std::endl;
    }
}
