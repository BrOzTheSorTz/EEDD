//
// Created by José Pablo Soriano Torres on 03/10/2022.
//            jpst0002@red.ujaen.es
//

#ifndef LECCION4_MIEXCEPCION_H
#define LECCION4_MIEXCEPCION_H
#include <string>

class MiExcepcion {
private:
    std::string mensaje ="";
public:
    MiExcepcion(std::string msg = "ERROR"):mensaje(msg){};

    virtual ~MiExcepcion() {};

};


#endif //LECCION4_MIEXCEPCION_H
