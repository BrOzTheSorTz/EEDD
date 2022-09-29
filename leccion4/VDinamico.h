//
// Created by José Pablo Soriano Torres on 29/09/2022.
//            jpst0002@red.ujaen.es
//

#ifndef LECCION4_VDINAMICO_H
#define LECCION4_VDINAMICO_H




template <typename T>
class VDinamico {
private:
    int _taml = 0;
    int _tamf = 0;
    T* _v;

public:
    VDinamico(int tam = 10);
    VDinamico(const VDinamico<T> &orig);
    VDinamico<T>& operator= (const VDinamico<T> &otro);

    void añade (T &dato);
    T& elimina();
    T& operator[](int pos);

};

template<typename T>
VDinamico<T>::VDinamico(int tam):_tamf(tam) {
    _v = new T[tam];
}


template<typename T>
VDinamico<T>::VDinamico(const VDinamico<T> &orig):_tamf(orig._tamf),_taml(orig._tamf) {
    _v = new T[_tamf];
    for(int i=0;i<_taml;++i){
        _v[i] = orig._v[i];
    }

}

template<typename T>
VDinamico<T> &VDinamico<T>::operator=(const VDinamico<T> &otro) {
    if(this != &otro){
        delete [] _v;
        _tamf = otro._tamf;
        _taml = otro._taml;

        _v = new T[_tamf];
        for(int i=0;i<_taml;++i){
            _v[i] = otro._v[i];
        }

    }
    return *this;
}

template<typename T>
void VDinamico<T>::añade(T &dato) {

    if(_tamf == _taml){
        _tamf = _tamf*2;
        T* aux = new T[_tamf*2];
        for(int i= 0;i<_taml;++i){
            aux[i] = _v[i];
        }

        delete [] _v;
        _v = aux;


    }
    _v[_taml++] = dato;

}

template<typename T>
T &VDinamico<T>::operator[](int pos) {
    return _v[pos];
}

template<typename T>
T& VDinamico<T>::elimina() {
    int pos = -1;


    if(_taml*3 < _tamf){
        _tamf = _tamf /2;
        T* aux = new T[_tamf];

        for(int i=0;i<_taml;++i){
            aux[i]=_v[i];
        }
        delete [] _v;
        _v = aux;

    }


    return _v[--_taml];
}


#endif //LECCION4_VDINAMICO_H
