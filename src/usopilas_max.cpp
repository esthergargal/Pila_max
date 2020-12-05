/* 
 * @file:   usopilas_max.cpp
 * @author: Esther García Gallego
 * 
 * Created on 13 de noviembre de 2020, 12:08
 */

#include <iostream>
#include "Pila_Max.h"

using namespace std;

int main() {
    Pila_max p, q;
    int i,j;
        
    for (i = 10; i >= 0; i--)
        p.poner(i);
    
    for(j = 0; j >= -10; j--)
        q.poner(j);
    
 // Probar el operator < 
 
    if(q < p)
        cout << "\nLa cola q es menor que la cola p" << endl;
    else
        cout << "\nLa cola q es mayor que la cola p" << endl;
    
    cout << "\n------- Cola q ---------- " << endl;
    while (!q.vacia()) {
        elemento x = q.tope();
        cout << x << endl;
        q.quitar();
    }
   
 // Probar el operator ==

    cout << "\nCopiamos la cola p en la cola q y comprobamos: " << endl;
    q = p;
    
    if(q == p)
        cout << "\nLa cola q es igual que la cola p" << endl;
        
    
    cout << "\n------- Cola p ---------- " << endl;
    while (!p.vacia()) {
        elemento x = p.tope();
        cout << x << endl;
        p.quitar();
    }
    
    cout << "\n------- Cola q ---------- " << endl;
    while (!q.vacia()) {
        elemento x = q.tope();
        cout << x << endl;
        q.quitar();
    }
    
    return 0;
}

