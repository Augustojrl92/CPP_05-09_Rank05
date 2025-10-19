# 📦 CPP08 – STL y algoritmos

### 🎯 Objetivo del módulo
Descubrir y dominar la **Standard Template Library (STL)**, uno de los pilares más poderosos de C++.  
Este módulo enseña cómo usar **contenedores genéricos** (como `vector`, `list`, `map`) y **algoritmos estándar** (`find`, `sort`, `for_each`, etc.) para escribir código **eficiente, expresivo y seguro**.

El objetivo es que el estudiante aprenda a **pensar en términos de abstracción**, delegando la gestión de memoria y estructuras de datos al estándar del lenguaje.

---

### 🧠 Conceptos teóricos clave

| Concepto | Descripción |
|-----------|-------------|
| **STL (Standard Template Library)** | Colección de clases y funciones genéricas para estructuras de datos y algoritmos. |
| **Contenedores** | Estructuras que almacenan y organizan datos (`vector`, `list`, `map`, etc.). |
| **Iteradores** | Objetos que permiten recorrer contenedores de forma uniforme. |
| **Algoritmos** | Funciones genéricas para manipular datos (`sort`, `find`, `for_each`, etc.). |
| **Complejidad algorítmica** | Medición del coste en tiempo o espacio de las operaciones. |
| **Template specialization en STL** | Uso avanzado de plantillas con tipos predefinidos. |

---

### 🧩 Ejercicio ex00 – *Easy Find*

#### 🎯 Objetivo
Implementar una función genérica capaz de **buscar un valor en cualquier contenedor STL**.

#### 💡 Descripción
Se crea una función `easyfind()` que recibe un contenedor y un valor, e intenta encontrarlo usando `std::find`.

```cpp
template <typename T>
typename T::iterator easyfind(T &container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not found in container");
    return it;
}
```

#### 💡 Ejemplo de uso
```cpp
std::vector<int> vec;
for (int i = 0; i < 5; i++)
    vec.push_back(i);

try {
    std::vector<int>::iterator it = easyfind(vec, 3);
    std::cout << "Found value: " << *it << std::endl;
} catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
}
```

#### 🧠 Conceptos aprendidos
- **Uso de iteradores STL.**
- **Plantillas genéricas con contenedores.**
- **Excepciones en algoritmos.**
- **Uso de `std::find` del `<algorithm>`.**

---

### 🧩 Ejercicio ex01 – *Span*

#### 🎯 Objetivo
Implementar una clase que calcule la **distancia más corta y más larga** entre números almacenados.

#### 💡 Descripción
Se define la clase `Span`, que utiliza internamente un contenedor (`std::vector<int>`) para almacenar los números, con un tamaño máximo definido en su construcción.

```cpp
class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;
public:
    Span(unsigned int n);
    void addNumber(int n);
    template <typename It>
    void addRange(It begin, It end);
    int shortestSpan() const;
    int longestSpan() const;
};
```

Ejemplo:
```cpp
Span sp(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
```

#### 🧠 Conceptos aprendidos
- **Uso interno de `std::vector`.**
- **Iteradores y rangos genéricos.**
- **Algoritmos `std::min_element`, `std::max_element`, `std::sort`.**
- **Gestión de errores mediante excepciones.**
- **Operaciones de rango con plantillas.**

---

### 🧩 Ejercicio ex02 – *MutantStack*

#### 🎯 Objetivo
Combinar herencia y STL para crear un contenedor híbrido: una **pila (`stack`) que pueda iterarse**.

#### 💡 Descripción
C++ `std::stack` no permite iterar sobre sus elementos.  
La clase `MutantStack` hereda de `std::stack` y expone iteradores al contenedor subyacente.

```cpp
template <typename T>
class MutantStack : public std::stack<T> {
public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
};
```

Ejemplo:
```cpp
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
    std::cout << *it << std::endl;
```

#### 🧠 Conceptos aprendidos
- **Herencia de contenedores STL.**
- **Acceso al contenedor subyacente (`this->c`).**
- **Iteradores en estructuras no iterables.**
- **Composición y extensión de la STL.**

---

### 📊 Diagrama CPP08

```mermaid
graph TD
    A[easyfind()] --> B[Containers]
    B --> C[std::find()]
    D[Span] --> E[std::vector<int>]
    D --> F[Algorithms: sort, min, max]
    G[MutantStack] --> H[std::stack<T>]
    H --> I[Container Iterator Access]
```

---

### 🧾 Resumen CPP08

| Concepto | Descripción |
|-----------|-------------|
| STL | Librería estándar de plantillas |
| Contenedores | `vector`, `list`, `deque`, `map`, `set`, etc. |
| Iteradores | Acceso universal a los elementos |
| Algoritmos | Funciones genéricas de manipulación (`find`, `sort`, etc.) |
| MutantStack | Extensión de `std::stack` con iteradores |
| Reutilización | Integración de plantillas y STL |

💡 **CPP08** introduce la potencia de la **STL moderna**, donde los contenedores y algoritmos permiten escribir código **limpio, seguro y eficiente**, sin reinventar estructuras clásicas.
