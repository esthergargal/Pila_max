/* 
 * @file:   Pila_max_Cola.h
 * @author: Esther García Gallego
 *
 * Created on 6 de noviembre de 2020, 18:12
 */

#ifndef PILA_MAX_COLA_H
#define PILA_MAX_COLA_H
#include "cola.h"
#include <ostream>

// ------------------------- Declaración del STRUCT ------------------------- //
struct elemento{
    int ele;                ///< Elemento a almacenar
    int maximo = 0;       ///< El máximo
};

/**
 * @brief Sobrecarga del operador de salida del struct
 * @param os Salida de parámetros
 * @param elemento El elemento a imprimir por pantalla
 * @return os Output stream
 */
std::ostream &operator<<(std::ostream &os, const elemento& elemento);


// -------------------------- Auxiliares para Struct ------------------------- //

/**
 * @brief Función auxiliar que comprueba si dos elementos son iguales.
 * @param uno Un elemento a comparar.
 * @param otro El elemento con el que se compara.
 * @return @retval true si ambos elementos son iguales @retval false en caso contrario
 */
bool iguales(const elemento &uno, const elemento &otro);

/**
 * @brief Función auxiliar que comprueba si un elemento es menor a otro.
 * @param uno Un elemento a comparar.
 * @param otro El elemento con el que se compara.
 * @return @retval true si el elemento "uno" es menor que el elemento "otro" @retval false en caso contrario
 * @note Vamos a considerar que un elemento es menor a otro si su atributo "ele", lo es.
 * @warning No se tiene en cuenta el máximo
 */
bool elementoMenor(const elemento &uno, const elemento &otro);

// -------------------------- Funciones auxiliares --------------------------- //

/**
 * @biref Función auxiliar para poder trabajar con índices en las colas
 * @param cola
 * @return aux Vector de elementos
 */
elemento *vectorizar(const Cola<elemento> &cola);

/**
 * @biref Función auxiliar que espeja los elementos de la cola, es decir, pone el primero en el último lugar y viceversa
 * @param cola La cola a espejar
 */
Cola<elemento> espejar(const Cola<elemento> &cola);


/////////////////////////// IMPLEMENTACIÓN DEL TDA /////////////////////////////

/**
 * @class Pila_max
 */
class Pila_max {
private:
    Cola<elemento> cola;                   ///< Cola que estructura la pila de elementos (struct)
    
public:
    
// ----------------------- Constructores y Destructores ---------------------- //
    
    //No se necesitan porque ya están implementados en la clase Cola
    
// ---------------------------- Métodos del TDA ----------------------------- //
    
    /**
     * @brief Añade una copia del elemento v a la pila
     * @param num El elemento a añadir
     */
    void poner(int num);
    
    /**
     * @brief Elimina el elemento en el tope de la pila 
     */
    void quitar();
    
    /**
     * @brief Consulta el elemento en el tope de la pila
     * @return elem El último elemento que ha entrado en la pila
     */
    elemento tope();
    
    /**
     * @brief Consulta si la pila no contiene elementos
     * @return @retval true si la pila está vacía @retval false si no
     */
    bool vacia() const;
    
    /**
     * @brief Consulta el tamaño de la pila
     * @return tam El número de elementos que contiene la pila
     */
    int num_elementos() const;

// ------------------------------- Operadores ------------------------------- //
    
    /**
     * @brief Consulta si una pila es igual a otra
     * @param otra La pila con la que se compara
     * @return @retval true si es igual @retval false si no
     * @note Se considera que una pila es igual a otra si todos sus elementos lo son
     * @note Si ambas pilas tienen distinto número de elementos son automáticamente distintas
     */
    bool operator==(const Pila_max& otra) const;
    
    /**
     * @brief Consulta si una pila es menor a otra
     * @param otra La pila con la que se compara
     * @return @retval true si es menor @retval false si no
     * @note Se considera que una pila es menor a otra si todos sus elementos son menores
     * @note Si la pila que llama al operador tiene mayor número de elementos que la pila con la que se compara, la primera es automáticamente mayor
     */
    bool operator<(const Pila_max& otra) const;


};

#endif /* PILA_MAX_COLA_H */

