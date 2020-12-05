/* 
 * @file:   Pila_max_Cola.cpp
 * @author: Esther García Gallego
 * 
 * Created on 6 de noviembre de 2020, 18:12
 */

#include "Pila_max_Cola.h"
#include "cola.h"     

using namespace std;


ostream &operator<<(ostream &os, const elemento& elemento){
    os << "Elemento: "<< elemento.ele << "    Máximo: " << elemento.maximo;
    return os;
}

// -------------------------- Auxiliares para Struct ------------------------- //

bool iguales(const elemento &uno, const elemento &otro){  
    return  uno.ele == otro.ele && uno.maximo == otro.maximo;
}

bool elementoMenor(const elemento &uno, const elemento &otro){                      
    return uno.ele < otro.ele;
}
// -------------------------- Funciones auxiliares --------------------------- //


elemento *vectorizar(const Cola<elemento> &cola){

    
    Cola<elemento> colaCopia(cola);                                             // Copia de la cola, porque no queremos modificarla
    int iter = cola.num_elementos();                                            // El último elemento accesible en la cola es el num_elementos() - 1
    elemento* aux = new elemento [iter];                                        // Vector de elementos
    
    while(iter != 0){                                                           // Mientras queden elementos rellenamos de atrás hacia adelante
        aux[iter - 1] = colaCopia.frente();                                     // Devolvemos el primer elemento de la cola aux[11] = 10 aux[10] = 9
        colaCopia.quitar();                                                     // Quitamos el primer elemento
        iter--;
    }
    
    return aux;
}

Cola<elemento> espejar(const Cola<elemento> &cola){
    
    elemento *aux;
    elemento v;                                                                 // Para almacenar elementos
    aux = vectorizar(cola);                                                     // Convertimos la cola en un vector para poder trabajar con el operador []
    
    Cola<elemento> pila;                                                        // Creamos la cola en la que se va a guardar la pila (la cola revertida)
    for(int i = 0; i < cola.num_elementos(); i++){           
        v = aux[i];                                                             // Copia en v el elemento almacenado en aux con índice i
        pila.poner(v);                                                          // Mete en la cola el elemento v
    }
    
    return pila;
}


// ---------------------------- Métodos del TDA ------------------------------- //

void Pila_max::poner(int num){
    elemento v;
    v.ele = num;
    
    if (!vacia()){
        int maxtope = tope().maximo;
        if (v.ele < maxtope)
            v.maximo = maxtope;
        else
            v.maximo = v.ele;
    } else
        v.maximo = v.ele;
    
    cola.poner(v);
}

void Pila_max::quitar(){
    Cola<elemento> copia;
    copia = espejar(cola);                                                      // En la copia guardamos la cola espejada (ahora podemos trabajar como pilas)
    copia.quitar();                                                             // Elimina el primer elemento de la lista de "copia" (el último en cola)
    cola = espejar(copia);                                                      // Actualizamos la cola, que ahora tiene un elemento menos
}

bool Pila_max::vacia() const{
    return cola.vacia();
}

elemento Pila_max::tope(){                        
    assert(!vacia());                                                           // Si la cola está vacía, no se puede devolver el tope
    Cola<elemento> copia;
    copia = espejar(cola);                                                      // Convertimos la cola en una pila

    return copia.frente();                                                      // Devolvemos el primer elemento de copia (el último elemento de la cola)
}

int Pila_max::num_elementos() const{
    return cola.num_elementos();
}

// ------------------------------- Operadores ------------------------------- //

bool Pila_max::operator<(const Pila_max& otra) const {

    bool menor = true;
    int util_v1 = cola.num_elementos(),                                         // Número de elementos de la pila que llama al operador
        util_v2 = otra.cola.num_elementos();                                    // Número de elementos de la pila a comparar
    
    if (util_v1 > util_v2)                                                      // Si el número de elementos de la primera es mayor, automáticamente una > otra
        menor = false;
    else if (util_v1 == util_v2){                                               // Si el número de elementos de la primera es igual
        
        elemento *unaV = new elemento [util_v1];                                // Vector para almacenar los elementos de una cola
        elemento *otraV = new elemento [util_v2];                               // Vector para almacenar los elementos de la otra cola
        
        unaV = vectorizar(cola);                                                // Almacenamos los elementos de una cola
        otraV = vectorizar(otra.cola);                                          // Almacenamos los elementos de la otra cola
        
        for (int i = 0; i < num_elementos() && menor; i++)
            if (!elementoMenor(unaV[i], otraV[i]))
                menor = false;
    }
    
    return menor;
}

bool Pila_max::operator==(const Pila_max& otra) const{     
    bool igual = true;

    int util_v1 = cola.num_elementos(),                                         // Número de elementos de la pila que llama al operador
        util_v2 = otra.cola.num_elementos();                                    // Número de elementos de la pila a comparar

    if (util_v1 != util_v2)                                                     // Si el número de elementos de ambas es distinto, automáticamente una != otra
        igual = false;
    else {

        elemento *unaV = new elemento [util_v1];                                // Vector para almacenar los elementos de una cola
        elemento *otraV = new elemento [util_v2];                               // Vector para almacenar los elementos de la otra cola

        unaV = vectorizar(cola);                                                // Almacenamos los elementos de una cola
        otraV = vectorizar(otra.cola);                                          // Almacenamos los elementos de la otra cola

        for (int i = 0; i < num_elementos() && igual; i++)
            if (!iguales(unaV[i], otraV[i]))
                igual = false;
    }

    return igual;
}
