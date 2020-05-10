#ifndef NODO_HPP
#define NODO_HPP


template<typename T> class Nodo{
public:
    Nodo<T> *next;
    T dato;

    Nodo(T _dato){
       dato = _dato;
       next = nullptr;
    }

private:
};


#endif // NODO_H
