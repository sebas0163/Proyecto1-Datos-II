#ifndef LISTA_HPP
#define LISTA_HPP
#include "Nodo.hpp"
#include<iostream>

using namespace std;
template<typename T>class Lista
{
    public:
        Nodo<T> *head;
        int largo;
        Lista(){
            head = nullptr;
            largo = 0;
        }
        void add(T dato){
            if(head == nullptr){
                Nodo<T>* n_Nodo = new Nodo<T>(dato);
                head = n_Nodo;
            }else{
                Nodo<T> *temp = head;
                while(temp->next != nullptr){
                    temp = temp ->next;
                }
                temp->next = new Nodo<T>(dato);
            }
            largo ++;
        }
        void print(){
            if(head != nullptr){
                Nodo<T> *temp = head;
                while (temp != nullptr){
                    cout<<temp->dato<<endl;
                    temp = temp ->next;
                }
            }else{
                cout<< "lista vacia"<<endl;
            }

        }
        void modificarNodo(int pos, T dato){
            Nodo<T> *temp = head;
            for(int i = 0; i<pos; i++ ){
                temp = temp->next;
            }
            temp->dato = dato;

        }
        void eliminarDato(T _dato){
            if(verificar(_dato)){
               int pos = getPos(_dato);
               eliminarPos(pos);
            }else{
                cout<<"No existe el dato a eliminar"<<endl;
            }
        }
        void eliminarPos(int pos){
            if(pos<=largo && pos>=0){
                Nodo<T>* temp= head;
                Nodo<T>* post= head->next;
                for(int i =1;i<pos;i++){
                    temp = temp ->next;
                    post= post->next;
                }
                temp ->next = post->next;
                delete post;
            }else{
                cout<<"posicion fuera de rango"<<endl;
            }
        }
        void agregaPos(T dato, int pos){
            if(pos==0){
                Nodo<T> *temp= new Nodo<T>(dato);
                temp->next= head;
                head = temp;
                temp =0;
                largo ++;
                delete temp;
            }else{
                Nodo<T>* nNodo = new Nodo<T>(dato);
                Nodo<T>* temp = head->next;
                for(int i=1;i<pos; i++){
                    temp = temp ->next;
                }
                nNodo->next = temp->next;
                temp->next = nNodo;
                nNodo=0;
                temp =0;
                largo++;
                delete temp,nNodo;
            }
        }
        bool verificar(T valor){
            Nodo<T> *temp = head;
            bool estado = false;
            while(temp != nullptr){
                if(temp->dato == valor){
                    estado = true;
                    break;
                }else{
                    temp = temp ->next;
                }
            }
            return estado;
        }
        int getPos(T dato){
            if(verificar(dato)){
                int pos = 0;
                Nodo<T> *temp = head;
                while(temp->dato != dato){
                    pos++;
                    temp = temp->next;
                }
                return pos;
            }else{
                cout<<"No se encuentra el valor en la lista"<<endl;
            }
            return 0;
        }
        Nodo<T> buscar(int pos){
            if(pos > largo -1){
                //return nullptr;
            }else{
                return buscar_Aux(pos);
            }
        }
        void reset(){
            Nodo<T> *temp = head;
            for(int i =0; i<largo; i++){
              head = temp->next;
              delete temp;
              temp = head;
            }
            delete temp;
            largo =0;
        }
        void eliminar(int pos){
            if(pos > largo){
                cout<<"no exite la posicion"<< endl;
            }else if (pos ==0){
                head = head->next;
            }else{
                Nodo<T>* temp = head ->next;
                Nodo<T>* prev= head;
                int indice = 1;
                while(indice != pos){
                    prev = prev->next;
                    temp = temp->next;
                    indice ++;
                }
                prev->next = temp ->next;
                delete temp;
                largo --;
            }
        }

    protected:

    private:
        Nodo<T> buscar_Aux(int pos){
            int indice = 0;
            Nodo<T> *temp = head;
            while(pos != indice){
                temp = temp ->next;
                indice ++;
            }
            return *temp;
        }

};

#endif // LISTA_H
