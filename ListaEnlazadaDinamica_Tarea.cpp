#include <iostream>
using namespace std;

//Crear la estructura del nodo
struct Nodo {
    int dato;
    Nodo* siguiente;
};

int main() {
    Nodo* primero = NULL; // Apunta al inicio de la lista
    Nodo* ultimo = NULL;  // Apunta al final de la lista
    char respuesta;
    int valor;

    //Menú interactivo
    do {
        cout << "Desea ingresar un nuevo valor? (S/N): ";
        cin >> respuesta;

        if (respuesta == 'S' || respuesta == 's') {
            cout << "Ingrese el valor: ";
            cin >> valor;

            //Creacion nodos dinamicamente
            Nodo* nuevoNodo = new Nodo();
            nuevoNodo->dato = valor;
            nuevoNodo->siguiente = NULL;

            // Enlazar nodo con el anterior
            if (primero == NULL) {
                primero = nuevoNodo; // Si la lista está vacía, el nuevo nodo es el primero
                ultimo = nuevoNodo;
            }
            else {
                ultimo->siguiente = nuevoNodo; // Enlazamos el último nodo actual con el nuevo
                ultimo = nuevoNodo;            // Actualizamos cuál es el último nodo
            }
        }
    } while (respuesta == 'S' || respuesta == 's');

    //Lista completa-mostrar
    cout << "\nContenido de la lista:\n";
    Nodo* actual = primero;

    while (actual != NULL) {
        cout << "[" << actual->dato << " | ";
        if (actual->siguiente != NULL) {
            cout << "*] -> ";
        }
        else {
            cout << "NULL]";
        }
        actual = actual->siguiente; // Avanzar al siguiente nodo
    }
    cout << endl;

    //Liberar memoria
    actual = primero;
    while (actual != NULL) {
        Nodo* aux = actual;         // Guardamos el nodo actual temporalmente
        actual = actual->siguiente; // Avanzamos al siguiente antes de borrar
        delete aux;                 // Liberamos la memoria del nodo guardado
    }

    return 0;
}