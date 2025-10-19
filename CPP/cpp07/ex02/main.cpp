/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:27:39 by aurodrig          #+#    #+#             */
/*   Updated: 2025/07/23 12:09:15 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// #include "Array.hpp"

// // ANSI colors
// #define RESET   "\033[0m"
// #define GREEN   "\033[1;32m"
// #define RED     "\033[1;31m"
// #define YELLOW  "\033[1;33m"
// #define CYAN    "\033[1;36m"

// #define MAX_VAL 750

// int main(int, char**) {
//     std::cout << CYAN << "\n🧪 Test 1: Creación e inicialización de arrays\n" << RESET;
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));

//     for (int i = 0; i < MAX_VAL; i++) {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     // ❗ Fuerza un error modificando el array "numbers"
//     //numbers[42] = -1; // ahora ya no coincide con mirror[42]
//     bool initMatch = true;
//     for (int i = 0; i < MAX_VAL; i++) {
//         if (numbers[i] != mirror[i]) {
//             std::cerr << RED << "❌ Error: Valores distintos tras inicialización en índice " << i << RESET << std::endl;
//             initMatch = false;
//             break;
//         }
//     }
//     if (initMatch)
//         std::cout << GREEN << "✔ Arrays inicializados correctamente con los mismos valores\n" << RESET;

//     std::cout << CYAN << "\n🧪 Test 2: Copia (asignación y constructor de copia)\n" << RESET;
//     {
         
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);

//         // ❗ Fuerza un error modificando la copia
//         //test[42] = -999;

//         bool copyMatch = true;
//         for (int i = 0; i < MAX_VAL; i++) {
//             if (test[i] != numbers[i]) {
//                 std::cerr << RED << "❌ Error: Copia incorrecta en índice " << i << RESET << std::endl;
//                 copyMatch = false;
//                 break;
//             }
//         }
//         if (copyMatch)
//             std::cout << GREEN << "✔ Copia realizada correctamente por constructor y asignación\n" << RESET;
//     }

//     //numbers[123] = 88888;  // ❗ Esto rompe la integridad


//     std::cout << CYAN << "\n🧪 Test 3: Verificación de integridad tras scope\n" << RESET;
//     bool matchAfterScope = true;
//     for (int i = 0; i < MAX_VAL; i++) {
//         if (mirror[i] != numbers[i]) {
//             std::cerr << RED << "❌ Error: Datos modificados tras destructor/copias\n" << RESET;
//             matchAfterScope = false;
//             break;
//         }
//     }
//     if (matchAfterScope)
//         std::cout << GREEN << "✔ Los datos originales se mantuvieron intactos\n" << RESET;

//     std::cout << CYAN << "\n🧪 Test 4: Acceso fuera de rango\n" << RESET;

//     try {
//         numbers[-2] = 0;

//         std::cerr << RED << "❌ No se lanzó excepción para índice -2\n" << RESET;
//     } catch (const std::exception& e) {
//         std::cout << GREEN << "✔ Excepción atrapada: " << e.what() << RESET << std::endl;
//     }

//     try {
//         numbers[MAX_VAL] = 0;
//         std::cerr << RED << "❌ No se lanzó excepción para índice MAX_VAL\n" << RESET;
//     } catch (const std::exception& e) {
//         std::cout << GREEN << "✔ Excepción atrapada: " << e.what() << RESET << std::endl;
//     }

//     std::cout << CYAN << "\n🧪 Test 5: Reescritura con nuevos valores aleatorios\n" << RESET;
//     bool overwriteOk = true;
//     for (int i = 0; i < MAX_VAL; i++) {
//         int newVal = rand();
//         numbers[i] = newVal;// +1;❗
//         if (numbers[i] != newVal) {
//             std::cerr << RED << "❌ Error al escribir nuevo valor en índice " << i << RESET << std::endl;
//             overwriteOk = false;
//             break;
//         }
//     }
//     if (overwriteOk)
//         std::cout << GREEN << "✔ Se reescribieron los valores correctamente\n" << RESET;

//     delete[] mirror;
//      std::cout << CYAN << "\n🧪 Test extra 6 : Array de std::string\n" << RESET;
//     Array<std::string> strArr(3);
//     strArr[0] = "pepe";
//     strArr[1] = "papa";
//     strArr[2] = "maracaibo";

//     for (unsigned int i = 0; i < strArr.size(); ++i) {
//         std::cout << "strArr[" << i << "] = " << strArr[i] << std::endl;
//     }

//     std::cout << CYAN << "\n🧪 Test extra 7: Verificación del método size()\n" << RESET;
//     Array<char> charArray(10);
//     if (charArray.size() == 10)
//         std::cout << GREEN << "✔ El método size() devuelve el tamaño correcto para charArray\n" << RESET;
//     else
//         std::cerr << RED << "❌ Error: size() devolvió " << charArray.size() << " en vez de 10\n" << RESET;

//     Array<double> emptyArray;
//     if (emptyArray.size() == 0)
//         std::cout << GREEN << "✔ El método size() también funciona para arrays vacíos\n" << RESET;
//     else
//         std::cerr << RED << "❌ Error: size() en array vacío devolvió " << emptyArray.size() << " en vez de 0\n" << RESET;



//     std::cout << YELLOW << "\n📝 Tests finalizados\n" << RESET;

//     return 0;
// }

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

// Colores
#define RESET   "\033[0m"
#define GREEN   "\033[1;32m"
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define CYAN    "\033[1;36m"

#define MAX_VAL 10

// Función auxiliar para imprimir arrays
template <typename T>
void printArray(const Array<T>& arr, const std::string& name) {
    std::cout << YELLOW << name << ": [";
    for (unsigned int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i];
        if (i < arr.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << RESET << std::endl;
}

int main(int, char**) {
    srand(static_cast<unsigned int>(time(NULL)));

    std::cout << CYAN << "\n🧪 Test 1: Creación e inicialización de arrays\n" << RESET;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];

    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand() % 100; // valores entre 0 y 99
        numbers[i] = value;
        mirror[i] = value;
    }
         // ❗ Fuerza un error modificando el array "numbers"
         //numbers[4] = -1; // ahora ya no coincide con mirror[42]

    printArray(numbers, "numbers");

    bool initMatch = true;
    for (int i = 0; i < MAX_VAL; i++) {
        if (numbers[i] != mirror[i]) {
            std::cerr << RED << "❌ Error: Valores distintos tras inicialización en índice " 
                      << i << RESET << std::endl;
            initMatch = false;
            break;
        }
    }
    if (initMatch)
        std::cout << GREEN << "✔ Arrays inicializados correctamente\n" << RESET;

    // ------------------------------------------------------

    std::cout << CYAN << "\n🧪 Test 2: Copia (constructor y asignación)\n" << RESET;
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        printArray(test, "test (copia de tmp)");
        // ❗ Fuerza un error modificando la copia
         //test[6] = -999;

        bool copyMatch = true;
        for (int i = 0; i < MAX_VAL; i++) {
            if (test[i] != numbers[i]) {
                std::cerr << RED << "❌ Error: Copia incorrecta en índice " << i << RESET << std::endl;
                copyMatch = false;
                break;
            }
        }
        if (copyMatch)
            std::cout << GREEN << "✔ Copia realizada correctamente\n" << RESET;
    }

    // ------------------------------------------------------

    //numbers[8] = 88888;  // ❗ Esto rompe la integridad

    std::cout << CYAN << "\n🧪 Test 3: Verificación de integridad tras scope\n" << RESET;
    bool matchAfterScope = true;
    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << RED << "❌ Error: Datos modificados tras destructor/copias\n" << RESET;
            matchAfterScope = false;
            break;
        }
    }
    if (matchAfterScope)
        std::cout << GREEN << "✔ Los datos originales se mantuvieron intactos\n" << RESET;

    // ------------------------------------------------------

    std::cout << CYAN << "\n🧪 Test 4: Acceso fuera de rango\n" << RESET;
    try {
        numbers[-1] = 0;
        std::cerr << RED << "❌ No se lanzó excepción para índice -1\n" << RESET;
    } catch (const std::exception& e) {
        std::cout << GREEN << "✔ Excepción atrapada: " << e.what() << RESET << std::endl;
    }

    try {
        numbers[MAX_VAL] = 0;
        std::cerr << RED << "❌ No se lanzó excepción para índice MAX_VAL\n" << RESET;
    } catch (const std::exception& e) {
        std::cout << GREEN << "✔ Excepción atrapada: " << e.what() << RESET << std::endl;
    }

    // ------------------------------------------------------

    std::cout << CYAN << "\n🧪 Test 5: Reescritura con nuevos valores aleatorios\n" << RESET;
    bool overwriteOk = true;
    for (int i = 0; i < MAX_VAL; i++) {
        int newVal = rand()%100;
        numbers[i] = newVal; //+1;
        if (numbers[i] != newVal) {
            std::cerr << RED << "❌ Error al escribir nuevo valor en índice " << i << RESET << std::endl;
            overwriteOk = false;
            break;
        } 
    }
    if (overwriteOk){
        printArray(numbers, "numbers (reescrito)");
        std::cout << GREEN << "✔ Se reescribieron los valores correctamente\n" << RESET;
    }

    // ------------------------------------------------------

    delete[] mirror;

    std::cout << YELLOW << "\n📝 Tests finalizados\n" << RESET;
    return 0;
}





