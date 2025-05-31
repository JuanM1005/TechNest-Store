#include "Sistema.h"

void logo()
{
    system("cls");
    system("color 02");
     std::cout <<"<============ TechNest ===============>\n" << std::endl;
    std::cout << " _____________________________" << std::endl;
    std::cout << "|                             |" << std::endl;
    std::cout << "|                             |" << std::endl;
    std::cout << "|                             |" << std::endl;
    std::cout << "|                             |" << std::endl;
    std::cout << "|                             |" << std::endl;
    std::cout << "|_____________________________|" << std::endl;
    // Cuerpo de la computadora
    std::cout << "           |      |            " << std::endl;
    std::cout << "           |      |            " << std::endl;
    std::cout << "           |      |            " << std::endl;
    // Base de la computadora
    std::cout << "      |||||||||||||||||||      " << std::endl;

}

void acceso() {
    string nombre, password;
    int intentos = 0;
    Admin a1("Juan");
    Admin a2("Luis");
    Admin a3("Noe");

    while (true) {
        system("color 0E");
        system("cls");
        cout << "Ingrese su nombre de administrador" << endl;
        cin >> nombre;
        cout << "Ingrese la contrasenia para acceder al programa" << endl;
        cin >> password;
        system("cls");
        // Verificar si el nombre y la contrasenia coinciden con alguno de los administradores
        if ((a1.verificarPassword(password) && a1.getNombre() == nombre) ||
            (a2.verificarPassword(password) && a2.getNombre() == nombre) ||
            (a3.verificarPassword(password) && a3.getNombre() == nombre)) {
            cout<< "Bienvenido "<< nombre<< ", en unos momentos ingresaras al programa..." << endl;
            Sleep(3000); // Esperar 2 segundos antes de mostrar el menu principal
            logo();
            Sleep(2000);
            menuPrincipal(); // Llamada a la funcion menu
            return;
        }

        // Si no se encontro un administrador con el nombre y contrasenia ingresados, mostrar mensaje de error
        intentos += 1;
        system("color 04");
        cerr << "Error, el nombre de administrador o la clave ingresada no son correctas. Intente de nuevo otra vez" << endl;
        Sleep(1500);
        system("cls");
        if (intentos == 3) {
            system("color 04");
            system("cls");
            cout << "Llegaste al limite de intentos permitidos" << endl;
            Sleep(3000);
            system("cls");
            cout << "Saliendo..." << endl;
            Sleep(3000);
            break;
        }
    }
}

void menuPrincipal() {
    int opc = 0, option = 0;
    while(opc != 5) {
        system("cls");
        system("color 0F");
        cout << "\tTechNest" << endl;
        cout << "== Menu Principal ==" <<
            "\n1. Administrar producto\n"
            "2. Buscar producto\n"
            "3. Gestionar pedidos\n"
            "4. Gestionar proveedores\n"
            "5. Salir del programa\n"
            "========================\n"
            "Ingrese su opcion: ";
        try {
            cin >> opc;
            if (cin.fail()) { // Verificar si la entrada fallo
                cin.clear(); // Borrar el estado de error
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada
                throw invalid_argument("Entrada no valida. Por favor, ingrese un numero.");
            }
            if(opc < 1 || opc > 5) {
                cin.clear(); // Limpiar el estado de error
                cin.ignore();
                throw out_of_range("Opcion invalida. Por favor, ingrese una opcion valida."); // Limpiar buffer de entrada
            }
            switch (opc) {
                case 1:
                    system("cls");
                    system("color 1F");
                    cout << "Administrar producto" << endl;
                    cout << "1. Dar de alta un producto\n"
                            << "2. Dar de baja un producto\n"
                            << "======================\n"
                            << "Ingrese su opcion: \033[0m";
                    cin >> option;
                    system("cls");
                    switch(option) {
                        case 1:
                            system("color 1F");
                            agregarProductoMenu(capacidadMaxima);
                            system("cls");
                            menuPrincipal();
                            break;
                        case 2:
                            system("color 1F");
                            eliminarProductoMenu(capacidadMaxima);
                            system("pause");
                            break;
                        default:
                            system("cls");
                            system("color 04");
                            cerr << "Error, la opcion que ingresaste no es valida, intentalo de nuevo\n";
                            system("pause");
                    }
                    break;
                case 2:
                    system("cls");
                    system("color 06");
                    if(capacidadMaxima.inventarioVacio()) {
                        cout<< "\tEl inventario esta vacio." << endl;
                    } else {
                        capacidadMaxima.mostrarInventario();
                    }
                    system("pause"); // Pausa para que el usuario pueda ver la informacion
                    break;
                case 3:
                    system("cls");
                    system("color 0A");
                    cout << endl << setw(40) << right << "Gestionar pedidos" << endl;
                    pedidos(listaPedidos);
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    system("color 01");
                    cout << "Gestionar proveedores" << endl;
                    system("cls");
                    submenuProveedores(listaProveedores);
                    break;
                case 5:
                    system("color 0A");
                    system("cls");
                    char seleccion;
                    cout << "Estas seguro que deseas salir del programa? (S/N): ";
                    cin >> seleccion;
                    if (seleccion == 'S' || seleccion == 's') {
                        cout << "Saliendo del programa...\n";
                        Sleep(3000);
                    } else if (seleccion == 'N' || seleccion == 'n') {
                        cout << endl << "\tIngresar como otro administrador..." << endl;
                        system("pause");
                        acceso();
                    } else {
                        // Opcion no valida
                        cerr << "Opcion no valida." << endl;
                    }
                    break;
            }
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << endl;
            system("pause");
        } catch (const out_of_range& e) {
            cerr << "Error: " << e.what() << endl;
            system("pause");
        }
    }
}
