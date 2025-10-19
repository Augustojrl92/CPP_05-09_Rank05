# 🧩 CPP07 – Plantillas y programación genérica

### 🎯 Objetivo del módulo
Introducir el concepto de **programación genérica** mediante el uso de **plantillas (templates)** en C++.  
El objetivo es diseñar **clases y funciones reutilizables** que funcionen con cualquier tipo de dato, sin duplicar código.  

Este módulo es el punto de partida hacia el **paradigma de metaprogramación**, base de la STL y de librerías modernas de C++.

---

### 🧠 Conceptos teóricos clave

| Concepto | Descripción |
|-----------|-------------|
| **Templates** | Mecanismo que permite definir clases y funciones genéricas. |
| **Function Templates** | Permiten escribir una función que trabaje con múltiples tipos (`template<typename T>`). |
| **Class Templates** | Permiten crear clases genéricas que se instancian con diferentes tipos. |
| **Template specialization** | Personalización de una plantilla para un tipo específico. |
| **`typename` vs `class`** | Palabras clave equivalentes en la declaración de plantillas. |
| **Instanciación** | Proceso en el que el compilador genera código concreto a partir de una plantilla. |
| **Generic Programming** | Paradigma basado en escribir código que se adapte a cualquier tipo. |

---

### 🧩 Ejercicio ex00 – *Templates Basics*

#### 🎯 Objetivo
Entender cómo declarar, definir e instanciar **funciones plantilla** en C++.

#### 💡 Descripción
Se deben implementar tres funciones genéricas: `swap`, `min` y `max`, que funcionen con cualquier tipo compatible.

```cpp
template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T const &min(T const &a, T const &b) {
    return (a < b ? a : b);
}

template <typename T>
T const &max(T const &a, T const &b) {
    return (a > b ? a : b);
}
```

#### Ejemplo:
```cpp
int a = 2, b = 3;
::swap(a, b);
std::cout << "min: " << ::min(a, b) << ", max: " << ::max(a, b) << std::endl;
```

#### 🧠 Conceptos aprendidos
- **Declaración de funciones genéricas.**
- **Parámetros de tipo (`typename T`).**
- **Comparación y operaciones con tipos arbitrarios.**
- **Instanciación automática de plantillas.**

---

### 🧩 Ejercicio ex01 – *Array Template*

#### 🎯 Objetivo
Diseñar una **clase plantilla genérica** que represente un array con control de límites.

#### 💡 Descripción
Se crea una clase `Array<T>` que gestione internamente un puntero dinámico y proporcione operaciones seguras de acceso mediante `operator[]`.

```cpp
template <typename T>
class Array {
private:
    T* _array;
    unsigned int _size;
public:
    Array() : _array(NULL), _size(0) {}
    Array(unsigned int n) : _array(new T[n]()), _size(n) {}
    Array(const Array &other);
    Array &operator=(const Array &other);
    ~Array();

    T &operator[](unsigned int index);
    const T &operator[](unsigned int index) const;
    unsigned int size() const;
};
```

#### 🧠 Conceptos aprendidos
- **Uso de templates en clases.**
- **Control de memoria dinámica con tipos genéricos.**
- **Implementación de `operator[]` seguro (con excepciones).**
- **Regla de los tres (constructor, asignación y destructor).**
- **Uso de `const` y sobrecarga de operadores en plantillas.**

---

### 💡 Ejemplo de uso
```cpp
Array<int> intArray(5);
for (unsigned int i = 0; i < intArray.size(); i++)
    intArray[i] = i * 10;

Array<std::string> strArray(3);
strArray[0] = "Hello";
strArray[1] = "C++";
strArray[2] = "Templates";

for (unsigned int i = 0; i < strArray.size(); i++)
    std::cout << strArray[i] << std::endl;
```

---

### 📊 Diagrama CPP07

```mermaid
graph TD
    A[Template Functions] --> B[swap(T)]
    A --> C[min(T)]
    A --> D[max(T)]
    E[Class Template Array<T>] --> F[Dynamic Memory]
    E --> G[Operator Overloading]
    G --> H[Exceptions]
```

---

### 🧾 Resumen CPP07

| Concepto | Descripción |
|-----------|-------------|
| Function Templates | Código genérico reutilizable para múltiples tipos |
| Class Templates | Clases parametrizadas por tipo (`Array<T>`) |
| Especialización | Adaptación de una plantilla a un tipo concreto |
| Tipos genéricos | `typename` o `class` como parámetros de plantilla |
| Seguridad | Control de límites y excepciones |
| Reutilización | Código flexible y libre de duplicación |

💡 **CPP07** enseña a diseñar código **modular, genérico y reusable**, piedra angular del estilo moderno de C++.  
Este módulo abre la puerta al uso completo de la **STL (Standard Template Library)** que se aborda en el siguiente.
