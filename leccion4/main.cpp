//
// Created by José Pablo Soriano Torres on 28/09/2022.
//            jpst0002@red.ujaen.es
//

#include <iostream>
#include "VEstaticoInt.h"
#include "VDinamico.h"

int main(){

    VEstaticoInt notas(10);
    for (int i=0;i<10;++i){
        notas.escribe(i,i+1);
    }
    notas[2]=19;
    notas.ordenar();
    std::cout<<notas<<std::endl;


    int numPer = 18;
    VDinamico<float> edades(numPer);

    int numPerActu = 20;
    float e = 3.4;
    for (int i = 0; i < numPerActu; ++i) {
        edades.añade(e );

    }

    std::cout<<edades[3]<<std::endl;

    for(int i=0;i<=30;++i){
        edades.elimina();
    }

    return 0;
}
