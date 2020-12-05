/* 
 * @file:   Pila_max_VD.cpp
 * @author: Esther García Gallego
 * 
 * Created on 8 de noviembre de 2020, 12:35
 */

#include "Pila_max_VD.h"
#include <vector>

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

// ------------------------- Métodos del TDA Pila VD ------------------------ //

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
    
    pila.push_back(v);
}

void Pila_max::quitar(){
    pila.pop_back();
}

bool Pila_max::vacia() const{
    return num_elementos() == 0;
}

elemento Pila_max::tope(){
    return pila.back();
}

int Pila_max::num_elementos() const{
    return pila.size();
}

// ------------------------------- Operadores ------------------------------- //

bool Pila_max::operator==(const Pila_max& otra) const{     
    bool igual = true;
    
    for(int i = 0; i < num_elementos() && igual; i++)
        if(!iguales(pila[i], otra.pila[i]))
            igual = false;
    
    return igual;
}

bool Pila_max::operator<(const Pila_max& otra) const{   
    bool menor = true;
    
    for(int i = 0; i < num_elementos() && menor; i++)
        if(!elementoMenor(pila[i], otra.pila[i]))
            menor = false;
    
    return menor;
}

