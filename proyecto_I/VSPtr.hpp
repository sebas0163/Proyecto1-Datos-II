/**
 *@file VSPtr.hpp.
 * @author Sebastian Moya.
 * @brief Plantilla de la clase Visual Studio Pointer.
 */
#ifndef VSPTR_HPP
#define VSPTR_HPP
#include "Lista.hpp"
#include <iostream>
#include "puntero.hpp"
#include "garbagecollector.hpp"
#include "singleton.hpp"
#include <string.h>

using namespace std;
/**
 *@brief Clase encargada del manejo del VSPtr
 */
template <typename T> class VSPtr : public Puntero{
public:
    /**
     * @brief VSPtr Constructor de la clase. Se encagar de crear una instancia del GC, inicializa el puntero y añade el puntero al GC.
     */
    VSPtr(){
        GarbageCollector* gc = Singleton::getInstancia();
        dato = new T;
        gc->agregarPuntero(this);
    }
    /**
     * @brief New metodo estatico que permite llamar al constructor de la clase.
     * @return  retorna el nuevo puntero.
     */
    static VSPtr New(){
        return VSPtr();
    }
    /**
     * @brief setData metodo que copia el dato que se desea en la direccion de memoria del puntero.
     * @param data dato que se va a guardar en la direccion de memoria
     */
    void setData(T data){
        *dato = data;
    }
    /**
     * @brief operator * sobrecarga del operador "*" que retorna el mismo puntero.
     * @return  retorna la instancia del puntero.
     */
    VSPtr<T>& operator *(){
        return *this;
    }
    /**
     * @brief operator & Sobrecarga del operador "&".
     * @return retorna el valor que al que se apunta.
     */
    T operator &(){
        return *dato;
    }
    /**
     * @brief comprobar metodo que verifica si el puntero "dato" apunta a nullptr.
     * @return retorna si apunta o no al nullptr.
     */
    bool comprobar(){
        if (dato == nullptr){
            return true;
        }else{
            return false;
        }
        Puntero::comprobar();
    }
    /**
     * @brief getDato metodo que permite obtener el puntero dato.
     * @return puntero dato.
     */
    T* getDato(){
        return dato;
    }
    /**
     * @brief operator = Sobrecarga del operador "=" que se encarga de verificar si el dato que guarda el VSPtr es igual al que se le está pasando. Si es asi al puntero se le asigna el id del puntero pasado y se pone al puntero a apuntar al la misma direccion del puntero pasado.
     * @param pointer puntero al que se le desea copiar los datos.
     */
    void operator =(VSPtr pointer){//modificar
        this->setId(pointer.getId());
        this->dato = pointer.getDato();
        cout<<"copie el id en el garbage y aumentê la referencia"<< endl;
        return;
    }
    /**
     * @brief operator = Segunda sobrecarga del operador "=" en la cual se verifica que el parametro coincida con el dato que guarda el puntero. Si es así el se llama al metodo setData().
     * @param data Valor al que se desea guardar en la direccion de memoria a la que apunta dato.
     */
    void operator=(T data){
        if(sizeof (*dato)== sizeof(data)){
            setData(data);
        }else{
            cout<<"No es posible realizar la accion"<<endl;
        }
     }
    /**
     * @brief eliminarRef metodo que permite hacer que dato sea nulo. Es decir elimina la referencia.
     */
    void eliminarRef(){
        dato = nullptr;
    }
    /**
     * @brief destruir método que elimina el puntero dato.
     */
    void destruir(){
        delete dato;
        cout<<"se ha destruido la referencia con exito"<<endl;
        Puntero::destruir();
    }
    string obtener_data(){
        long  direccion = (long)dato;
        string str_dat;
        string data;
        try {
            str_dat = to_string(*dato); //bug con strings
        }  catch (exception& e) {
            str_dat = *dato;
            cout<<"error"<<endl;
        }
        string tipo =typeid(*dato).name();
        data= "<tr><td>"+tipo+"</td>"+"<td>"+to_string(direccion)+"</td>"+"<td>"+str_dat + "</td><td>"+to_string(getId())+"</td></tr>";
        return data;
    }
    string infoPunt(){
        long  direccion = (long)dato;
        string str_dat;
        string data;
        try {
            str_dat = to_string(*dato); //bug con strings
        }  catch (exception& e) {
            str_dat = *dato;
            cout<<"error"<<endl;
        }
        string tipo =typeid(*dato).name();
        data= "Tipo: "+tipo+"\r\n Dirección: "+to_string(direccion)+ "\r\n Dato: "+str_dat +"\r\n Id: "+to_string(getId())+"\r\n";
        return data;
    }

private:
    T* dato;

};
#endif // VSPTR_H
