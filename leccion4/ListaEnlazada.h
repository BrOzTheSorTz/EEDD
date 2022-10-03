//
// Created by José Pablo Soriano Torres on 03/10/2022.
//            jpst0002@red.ujaen.es
//

#ifndef LECCION4_LISTAENLAZADA_H
#define LECCION4_LISTAENLAZADA_H
#include "Nodo.h"
#include "MiExcepcion.h"

template <class T>
class ListaEnlazada{
private:
    Nodo<T>* cabecera = nullptr;
    Nodo<T>* cola = nullptr;

public:
    ListaEnlazada():cabecera(nullptr),cola(nullptr){};
    virtual ~ListaEnlazada(){};
    ListaEnlazada(const ListaEnlazada &l);
    ListaEnlazada& operator=(ListaEnlazada &l);


//----------------------------------------------------------------------------------------
    void insertaInicio(T &dato);
    void insertaFinal(T &dato);
    void insertar(T &dato,Nodo<T>* p);
    //void insertar(Iterador<T> &i,T &dato);
    void borrarInicio();
    void borraFinal();
    //void borrar(Iterador<T> &i,T &dato);
    T& inicio();
    T& final();


//----------------------------------------------------------------------------------------
    Nodo<T> *getCabecera() const {
        return cabecera;
    }
    void setCabecera(Nodo<T> *cabecera) {
        ListaEnlazada::cabecera = cabecera;
    }
    Nodo<T> *getCola() const {
        return cola;
    }
    void setCola(Nodo<T> *cola) {
        ListaEnlazada::cola = cola;
    }


};

template<class T>
ListaEnlazada<T>::ListaEnlazada(const ListaEnlazada &l) {
    //@todo

}

template<class T>
ListaEnlazada<T> &ListaEnlazada<T>::operator=(ListaEnlazada &l) {

    //@todo
    return *this;
}

template<class T>
void ListaEnlazada<T>::insertaInicio(T &dato) {
    Nodo<T> *nuevo = new Nodo<T>(dato,cabecera);
    if (cabecera == cola || cola == nullptr){
        cola = nuevo; //En el caso de que haya un dato o ninguno
    }
    cabecera = nuevo;


}

template<class T>
void ListaEnlazada<T>::insertaFinal(T &dato) {
    Nodo<T>* nuevo = new Nodo<T>(dato, nullptr);

    if(cabecera==cola== nullptr){ // Para el caso donde no hay ningún dato
        cabecera = nuevo;
        cola = nuevo;
    }else {
        cola->getSig() = nuevo;
        cola = nuevo;
    }
}

template<class T> // p es un puntero al nodo siguiente al que queremos insertar
void ListaEnlazada<T>::insertar(T &dato,Nodo<T>* p) {
    //En el caso de que no haya ningún dato
    if(cabecera == cola == nullptr){
        throw MiExcepcion("No puede insertar en ninguna posición porque la lista está vacia");
    }
    Nodo<T>* nuevo = new Nodo<T>(dato,p);
    Nodo<T>* anterior = cabecera;

    //En el caso de que solo haya un nodo
    if (cabecera == p){
        nuevo->setSig(cabecera);
        cabecera = nuevo;
    }else {
        while (anterior->getSig() != p) {
            anterior = anterior->getSig();
        }
        anterior->getSig() = nuevo;
    }
}

template<class T>
void ListaEnlazada<T>::borrarInicio() {
    if(cabecera == cola == nullptr){
        throw MiExcepcion("No puedes borrar.No hay datos");
    }else if(cabecera == cola){
        delete cabecera;
        cabecera = nullptr;
        cola = nullptr;
    }else {

        Nodo<T> *borra = cabecera;
        cabecera = cabecera->getSig();
        delete borra;
    }
}

template<class T>
void ListaEnlazada<T>::borraFinal() {
    if(cabecera == cola == nullptr){
        throw MiExcepcion("No puedes borrar.No hay datos");
    }else if(cabecera == cola){
        delete cabecera;
        cabecera = nullptr;
        cola = nullptr;
    }else {
        Nodo<T> *anterior = cabecera;
        while (anterior->getSig() != cola) {
            anterior = anterior->getSig();
        }
        delete cola;
        cola = anterior;
        cola->setSig(nullptr);
    }
}

template<class T>
T &ListaEnlazada<T>::inicio() {
    return cabecera->getDato();
}

template<class T>
T &ListaEnlazada<T>::final() {
    return cola->getDato();
}


#endif //LECCION4_LISTAENLAZADA_H
