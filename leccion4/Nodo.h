//
// Created by José Pablo Soriano Torres on 03/10/2022.
//            jpst0002@red.ujaen.es
//

#ifndef LECCION4_NODO_H
#define LECCION4_NODO_H

template <class T>
class Nodo{
private:
    T dato;
    Nodo* sig = nullptr;

public:
    Nodo(T &dato,Nodo* sig = nullptr):dato(dato),sig(sig){};

    T getDato() const {
        return dato;
    }
    void setDato(T dato) {
        Nodo::dato = dato;
    }
    Nodo *getSig() const {
        return sig;
    }
    void setSig(Nodo *sig) {
        Nodo::sig = sig;
    }


};

#endif //LECCION4_NODO_H
