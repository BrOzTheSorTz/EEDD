//
// Created by José Pablo Soriano Torres on 29/09/2022.
//            jpst0002@red.ujaen.es
//

#ifndef LECCION4_BITSET_H
#define LECCION4_BITSET_H


class BitSet {
protected:
    char *arr;
    int tama;
public:
    BitSet(int max);
    BitSet& inserta(int ele);
    void elimina(int ele);
    bool contiene(int ele);
    BitSet operator+(BitSet &c);
    BitSet operator-(BitSet &c);
    BitSet intersec(BitSet &b);

    virtual ~BitSet();

};


#endif //LECCION4_BITSET_H
