//
// Created by José Pablo Soriano Torres on 28/09/2022.
//            jpst0002@red.ujaen.es
//

#include "VEstaticoInt.h"
#include <algorithm>

VEstaticoInt::VEstaticoInt(int tama) :_tam(tama){
    _v = new int[tama];
}

VEstaticoInt::VEstaticoInt(const VEstaticoInt &orig) {
    _tam = orig._tam;
    _v = new int [_tam];
    for(int i=0;i<_numElementos;++i){
        _v[i] = orig._v[i]; //Necesario copiar los elementos por separado
    }

}

VEstaticoInt &VEstaticoInt::operator=(const VEstaticoInt &orig) {
    if(this != &orig){
        delete [] _v;
        _v = new int [orig._tam];
        for(int i=0;i<orig._numElementos;++i){
            _v[i] = orig._v[i];

        }

    }

    return *this;
}
//De menor a mayor
void VEstaticoInt::ordenar() {
    std::sort(_v,_v + _numElementos);//El primer, ultimo elemento


}

int VEstaticoInt::busqueda(int dato) {
    int inf = 0;
    int sup = _numElementos -1;
    int medio = (inf + sup)/2;

    while(inf <= sup){
        if(_v[medio] == dato){
            return medio;
        }else if(_v[medio] > dato){
            sup = medio-1;

        }else{
            inf = medio +1;
        }

    }



    return -1;
}

VEstaticoInt::~VEstaticoInt() {
    delete [] _v;

}

int VEstaticoInt::getNumElementos() const {
    return _numElementos;
}


std::ostream &operator<<(std::ostream& os,VEstaticoInt &v){

    for(int i=0;i<v.getNumElementos();++i){
        os << v[i] <<"-";
    }

    return os;
}

