#include "Lista.h"

Lista::Lista() : prim(NULL), ult(NULL){
    // Completar

}

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::~Lista() {
    // Completar
    destruirNodos();
}

Lista& Lista::operator=(const Lista& aCopiar) {
    // Completar
    destruirNodos();
    copiarNodos(aCopiar);
    return *this;
}

void Lista::agregarAdelante(const int& elem) {
    // Completar
    Nodo* nuevo = new Nodo(elem,NULL,NULL);
    if (prim == NULL){
        prim = nuevo;
        return;
    }
    Nodo* actual = prim;
    actual->ant = nuevo;

}

void Lista::agregarAtras(const int& elem) {
    // Completar
    Nodo* nuevo = new Nodo(elem,NULL,NULL);
    if (prim == NULL){
        prim = nuevo;
        return;
    }
    Nodo* actual = prim;
    while (actual->sig != NULL){
        actual = actual->sig;
    }
    actual->sig = nuevo;
}

void Lista::eliminar(Nat i) {
    // Completar
    Nodo* actual = prim;
    for (int j = 0; j<=i;j++) {
        if (j == i) {
            delete actual;
        } else {
            actual->sig;
        }
    }
}

int Lista::longitud() const {
    // Completar
    Nodo* actual = prim;
    int cont = 0;
    while (actual != NULL){
        cont++;
        actual = actual->sig;
    }
    return cont;
}

const int& Lista::iesimo(Nat i) const {
    // Completar
    Nodo* actual = prim;
    for (int j = 0; j < i; j++){
        actual = actual->sig;
    }
    return actual->valor;
}

int& Lista::iesimo(Nat i) {
    // Completar (hint: es igual a la anterior...)
    Nodo* actual = prim;
    for (int j = 0; j < i; j++){
        actual = actual->sig;
    }
    return actual->valor;
}

void Lista::mostrar(ostream& o) {
    // Completar
}

void Lista::destruirNodos() {
    Nodo* actual = prim;
    while (actual != NULL){
        Nodo* siguiente = actual->sig;
        delete actual;
        actual = siguiente;
    }
    prim = NULL;
}

void Lista::copiarNodos(const Lista &aCopiar) {
    Nodo* actual = aCopiar.prim;
    while (actual != NULL){
        agregarAtras(actual->valor);
        actual = actual->sig;
    }
}