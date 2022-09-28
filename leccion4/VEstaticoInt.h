//
// Created by José Pablo Soriano Torres on 28/09/2022.
//            jpst0002@red.ujaen.es
//

#ifndef LECCION4_VESTATICOINT_H
#define LECCION4_VESTATICOINT_H

#include <iostream>

class VEstaticoInt {
private:
    int _tam;
    int _numElementos=0;
    int *_v = nullptr;

public:
    VEstaticoInt(int tama);
    VEstaticoInt(const VEstaticoInt& orig);
    VEstaticoInt& operator=(const VEstaticoInt& orig);

    int lee(unsigned pos){return _v[pos];}
    void escribe(unsigned pos,int dato){_v[pos] = dato;++_numElementos;}
    int &operator[](unsigned pos){
        return _v[pos];
    }

    int getNumElementos() const;

    void ordenar();
    int busqueda(int dato);

    virtual ~VEstaticoInt();

};

std::ostream &operator<<(std::ostream& os, VEstaticoInt &v);

#endif //LECCION4_VESTATICOINT_H
