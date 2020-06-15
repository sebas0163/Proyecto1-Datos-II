#include "garbagecollector.hpp"
#include "cliente.cpp"
#include <fstream>

/**
 * @brief GarbageCollector::GarbageCollector constructor de la clase, inicializa las listas y crea una lista con los id
 */
GarbageCollector::GarbageCollector()
{
    direcciones = Lista<Puntero*>();
    ids = Lista<int>();
}
/**
 * @brief GarbageCollector::generarId Genera un id único para cada puntero
 * @return  int con el id
 */
int GarbageCollector::generarId(){
    int id = 1;
    for(int i =1; i<1000;i++){
        if(ids.verificar(i)){
           id ++;
        }else{
            break;
        }
    }
    ids.add(id);
    return id;
}
/**
 * @brief GarbageCollector::agregarPuntero añade un nuevo puntero al garbage collector
 * @param ptr objeto de tipo puntero (VSPtr pointer)
 */
void GarbageCollector::agregarPuntero(Puntero* ptr){
    direcciones.add(ptr);
    ptr->setId(generarId());
}
/**
 * @brief GarbageCollector::verificar Verifica que ningun puntero apunte a un null, si lo hace lo elimina.
 */
void GarbageCollector::verificar(){
    int i = 0;
    while (i<direcciones.largo){
        if(direcciones.buscar(i).dato->comprobar()){
            direcciones.buscar(i).dato->destruir();
            //delete direcciones.buscar(i).dato;
            direcciones.eliminar(i);
            ids.eliminar(i);
        }else{
            i++;
        }
    }
}
/**
 * @brief GarbageCollector::enviarInfo toma todos los datos necesarios de cada puntero, para enviarlos al heap vizualicer, mediante un txt que se está actualizando
 * @return información de todos los punteros en formato html
 */
string GarbageCollector::enviarInfo(){
    ofstream archivo;
    string info ="";
    archivo.open("/home/sebastian/Escritorio/Datos 2/Proyecto1-Datos-II/proyecto_I/datos.txt", ios::out);
    archivo << "";
    archivo.close();
    for (int i =0; i<direcciones.largo;i++){
        info = info + direcciones.buscar(i).dato->obtener_data();
        archivo.open("/home/sebastian/Escritorio/Datos 2/Proyecto1-Datos-II/proyecto_I/datos.txt", ios::out | ios::app);
        archivo << direcciones.buscar(i).dato->obtener_data() << endl;
        archivo.close();

      }

    
    return info;
}
void GarbageCollector::mostrarL(){
    for (int i =0; i<direcciones.largo;i++){
        cout<<direcciones.buscar(i).dato->getId()<<endl;
      }
}
void GarbageCollector::ejecutarHilo(){
    ifstream archivo;
    string info ="";
    bool conexion = false;
    archivo.open("/home/sebastian/Escritorio/Datos 2/Proyecto1-Datos-II/proyecto_I/datos.txt", ios::in);
    while (conexion == false){
        if (archivo.fail()){
            cout << "No se pudo abrir el archivo"<<endl;
        }else{
            getline(archivo,info);
            if (info != ""){
                conexion = true;
            }
        }
    }
    archivo.close();
    Cliente cliente = Cliente();
    verificar();
    enviarInfo();
    cliente.EnviarPwrd("contra");
    cliente.Enviar(enviarInfo());
}
