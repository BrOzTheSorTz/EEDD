//
// Created by José Pablo Soriano Torres on 28/09/2022.
//            jpst0002@red.ujaen.es
//

#ifndef LECCION4_VESTATICOINT_H
#define LECCION4_VESTATICOINT_H


class VEstaticoInt {
private:
    int _tam;
    int _numElementos;
    int *_v = nullptr;

public:
    VEstaticoInt(int tama);
    VEstaticoInt(const VEstaticoInt& orig);
    VEstaticoInt& operator=(const VEstaticoInt& orig);

    int lee(unsigned pos){return _v[pos];}
    void escribe(unsigned pos,int dato){_v[pos] = dato;}
    int &operator[](unsigned pos){
        return _v[pos];
    }

    void ordenar();
    int busqueda(int dato);

    virtual ~VEstaticoInt();

};


#endif //LECCION4_VESTATICOINT_H
