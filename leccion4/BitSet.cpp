//
// Created by José Pablo Soriano Torres on 29/09/2022.
//            jpst0002@red.ujaen.es
//

#include <cmath>
#include "BitSet.h"

BitSet::BitSet(int max) {
    tama = ceil((float)(max+1)/8);//Definimos el número de bytes necesarios
    arr = new char[tama];
    for(int i=0;i<tama;++i) arr[i] = 0;

}

BitSet& BitSet::inserta(int ele) {
    char mascara = 1 << (ele % 8);
    arr[ele/8] |= mascara;

    return *this;

}

void BitSet::elimina(int ele) {
    char mascara = 1 << (ele %8);
    arr[ele/8] &= ~mascara;

}

bool BitSet::contiene(int ele) {
    char mascara = 1 << (ele % 8);
    return (arr[ele/8] & mascara) != 0;
}

BitSet BitSet::operator+(BitSet &c) {
    BitSet *Mayor = this;
    BitSet *Menor = &c;

    if(tama < c.tama) std::swap(Mayor,Menor);
    BitSet resultado(*Mayor);
    for(int i=0;i<Menor->tama;++i){
        resultado.arr[i] |= Menor->arr[i];

    }



    return resultado;
}

BitSet BitSet::operator-(BitSet &c) {

    BitSet *Mayor = this;
    BitSet *Menor = &c;

    if(tama < c.tama) std::swap(Mayor,Menor);
    BitSet resultado(*Mayor);
    for(int i=0;i<Menor->tama;++i){
        resultado.arr[i] &= ~Menor->arr[i]; //A-B = A y! B
    }



    return resultado;
}

BitSet::~BitSet() {
    delete [] arr;

}

BitSet BitSet::intersec(BitSet &b) {

    BitSet resultado(*this);
    for(int i=0; i<resultado.tama;++i){
        if(!b.contiene(resultado.arr[i])){
            resultado.elimina(resultado.arr[i]);
        }
    }

    return resultado;
}
