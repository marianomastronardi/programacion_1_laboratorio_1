#include "calculadora.h"

/** \brief suma dos numeros enteros
 *
 * \param num1: primer parametro fundamental del tipo int
 * \param num2: segundo parametro fundamental del tipo int
 * \return retorna la suma de los dos parametros fundamentales
 *
 */

int suma(int num1, int num2){
    return num1 + num2;
};

/** \brief resta de dos numeros enteros
 *
 * \param num1: primer parametro fundamental del tipo int
 * \param num2: segundo parametro fundamental del tipo int
 * \return retorna la resta de los dos parametros fundamentales
 *
 */

int resta(int num1, int num2){
    return num1 - num2;
};

/** \brief producto de dos numeros enteros
 *
 * \param num1: primer parametro fundamental del tipo int
 * \param num2: segundo parametro fundamental del tipo int
 * \return retorna el producto de los dos parametros fundamentales
 *
 */

int multiplicar(int num1, int num2){
    return num1*num2;
};

/** \brief divide dos numeros del tipo int, donde:
 *          1º parametro fundamental: numerador
 *          2º parametro fundamental: denominador
 * \param num1: primer parametro fundamental del tipo int
 * \param num2: segundo parametro fundamental del tipo int
 * \return retorna la division de los dos parametros fundamentales
 *
 */

float dividir(int num1,int num2){
    return (float)num1/num2;
};

/** \brief realiza el factorial de un numero entero
 *
 * \param numero: unico parametro fundamental
 * \return retorna el factorial del parametro fundamental
 *
 */

int factorial(int numero){

    for(int i=numero-1 ;i>1 ;i--){
        numero = numero * i;
    };

    return numero;
};

