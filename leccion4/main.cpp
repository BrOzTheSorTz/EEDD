//
// Created by José Pablo Soriano Torres on 28/09/2022.
//            jpst0002@red.ujaen.es
//

#include <iostream>
#include "VEstaticoInt.h"

int main(){

    VEstaticoInt notas(10);
    for (int i=0;i<10;++i){
        notas.escribe(i,i+1);
    }
    notas[2]=19;
    notas.ordenar();
    std::cout<<notas<<std::endl;


    return 0;
}
