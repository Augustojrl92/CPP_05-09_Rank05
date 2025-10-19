# 💻 C++ Modules (CPP05–CPP09) – 42

## 🧭 Introducción
Los módulos **CPP05 → CPP09** del cursus de **42** representan la **segunda etapa del aprendizaje de C++**, centrada en las características avanzadas del lenguaje y su aplicación práctica.

Mientras que los módulos **CPP00–CPP04** se enfocan en los fundamentos de la **Programación Orientada a Objetos (POO)**, este bloque lleva esas bases al siguiente nivel: manejo de **excepciones**, **conversiones de tipo**, **plantillas (templates)** y **contenedores de la STL**.  
El objetivo es escribir código **genérico, reutilizable y seguro**, aplicando las mejores prácticas modernas de C++.

---

## 📚 Tabla de Contenidos
- [⚠️ CPP05 – Excepciones y control de flujo](#-cpp05--excepciones-y-control-de-flujo)
- [🔄 CPP06 – Conversión de tipos y castings](#-cpp06--conversión-de-tipos-y-castings)
- [🧩 CPP07 – Plantillas y programación genérica](#-cpp07--plantillas-y-programación-genérica)
- [📦 CPP08 – STL y algoritmos](#-cpp08--stl-y-algoritmos)
- [⚡ CPP09 – Contenedores personalizados y rendimiento](#-cpp09--contenedores-personalizados-y-rendimiento)
- [🧾 Conclusión General](#-conclusión-general)
- [📚 Recursos Recomendados](#-recursos-recomendados)

---

## 🧠 Objetivo general del bloque
Este conjunto de módulos introduce al estudiante a la **programación moderna en C++**, dominando conceptos como:
- **Excepciones y control de errores**
- **Conversión entre tipos primitivos y clases**
- **Templates y funciones genéricas**
- **Contenedores de la STL (Standard Template Library)**
- **Algoritmos, iteradores y eficiencia**
- **Optimización de código y buenas prácticas**

💡 En resumen: pasar de escribir código orientado a objetos a diseñar **código genérico, escalable y de alto rendimiento.**

---

## 🧾 Relación con los módulos anteriores
| Bloque | Enfoque principal | Resultado |
|--------|------------------|------------|
| **CPP00–CPP04** | Fundamentos de OOP | Diseño de clases y jerarquías orientadas a objetos |
| **CPP05–CPP09** | C++ avanzado | Diseño genérico, plantillas, STL y programación moderna |

---

# ⚠️ CPP05 – Excepciones y control de flujo

### 🎯 Objetivo del módulo
Aprender el uso de **excepciones en C++** como mecanismo de control de errores seguro y estructurado.  
El módulo entrena al estudiante para reemplazar el manejo de errores tradicional basado en *return codes* por un enfoque **orientado a objetos** mediante `try`, `throw` y `catch`.

Además, se profundiza en el concepto de **jerarquías de clases de excepción**, el **control del flujo de ejecución**, y la importancia de **mantener la coherencia del estado del programa** tras un error.

---

### 🧠 Conceptos teóricos clave

| Concepto | Descripción |
|-----------|-------------|
| **Excepciones (`try / throw / catch`)** | Mecanismo para manejar errores en tiempo de ejecución sin romper la lógica del programa. |
| **Jerarquías de excepciones** | Las clases de error heredan de `std::exception`, lo que permite capturarlas de forma genérica. |
| **Control de flujo** | Permite definir cómo se recupera el programa después de un error. |
| **Const-correctness en excepciones** | Las funciones `what()` deben ser constantes (`const noexcept`). |
| **Buenas prácticas** | Solo lanzar excepciones en situaciones excepcionales; evitar usarlas como lógica normal del programa. |

---

### 🧩 Ejercicio ex00 – *Bureaucrat*

#### 🎯 Objetivo
Implementar una clase que controle los **límites de valores** mediante excepciones personalizadas.

#### 💡 Descripción
`Bureaucrat` tiene un atributo `grade` que representa su rango.  
Los valores válidos están entre **1 (más alto)** y **150 (más bajo)**.  
Si un valor excede esos límites, se lanza una excepción.

```cpp
class Bureaucrat {
private:
    const std::string _name;
    int _grade;
public:
    Bureaucrat(std::string name, int grade);
    ~Bureaucrat();

    const std::string& getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    class GradeTooHighException : public std::exception {
        const char* what() const noexcept override;
    };
    class GradeTooLowException : public std::exception {
        const char* what() const noexcept override;
    };
};
```

#### 🧠 Conceptos aprendidos
- **Lanzamiento de excepciones personalizadas (`throw`)**
- **Captura con `try / catch`**
- **Diseño de clases robustas con validación interna**
- **Sobrecarga del operador `<<` para salida formateada**

---

### 🧩 Ejercicio ex01 – *Forms and Bureaucrats*

#### 🎯 Objetivo
Introducir relaciones entre clases y manejo de errores cruzados.

#### 💡 Descripción
Se añade la clase `Form`, que puede ser firmada por un `Bureaucrat` si su `grade` es lo suficientemente alto.  
Las reglas se verifican mediante excepciones.

```cpp
class Form {
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;
public:
    Form(std::string name, int gradeSign, int gradeExec);
    void beSigned(const Bureaucrat& b);

    class GradeTooHighException : public std::exception {
        const char* what() const noexcept override;
    };
    class GradeTooLowException : public std::exception {
        const char* what() const noexcept override;
    };
};
```

#### 🧠 Conceptos aprendidos
- **Comunicación entre clases mediante excepciones**
- **Control de flujo seguro en relaciones jerárquicas**
- **Uso del principio de *encapsulación con validación***

---

### 🧩 Ejercicio ex02 – *AForm, Shrubbery, Robotomy, Presidential***

#### 🎯 Objetivo
Aplicar el **polimorfismo** al sistema de formularios con **ejecuciones específicas** según el tipo de formulario.

#### 💡 Descripción
Se crean tres clases derivadas de una clase base `AForm`, cada una con su propio comportamiento de ejecución y validación.

```cpp
class AForm {
protected:
    std::string _target;
public:
    virtual void execute(const Bureaucrat& executor) const = 0;
};
```

Ejemplos de formularios:
- `ShrubberyCreationForm` — genera un archivo ASCII con árboles 🌲  
- `RobotomyRequestForm` — realiza una “robotomía” con 50% de éxito 🤖  
- `PresidentialPardonForm` — emite un perdón presidencial 🏛️  

#### 🧠 Conceptos aprendidos
- **Polimorfismo aplicado a excepciones**
- **Control de flujo jerárquico**
- **Uso de `virtual` y `override` con validación**
- **Manejo de errores específicos y generales**

---

### 📊 Diagrama CPP05

```mermaid
graph TD
    A[Bureaucrat] --> B[Form]
    B --> C[AForm]
    C --> D[ShrubberyCreationForm]
    C --> E[RobotomyRequestForm]
    C --> F[PresidentialPardonForm]
```

---

### 🧾 Resumen CPP05

| Concepto | Descripción |
|-----------|-------------|
| Excepciones | Control estructurado de errores en C++ |
| `try` / `throw` / `catch` | Flujo de manejo de errores |
| Clases personalizadas de excepción | Derivadas de `std::exception` |
| Polimorfismo en excepciones | Sobrescritura de `what()` |
| Robustez | Código seguro ante errores y validaciones |

💡 **CPP05** marca la transición hacia el **C++ robusto y orientado a errores**, donde cada clase gestiona su coherencia interna y se comunica mediante excepciones seguras.

# 🔄 CPP06 – Conversión de tipos y castings

### 🎯 Objetivo del módulo
Aprender a manipular y convertir **tipos de datos en C++**, tanto de forma **implícita** como **explícita**, utilizando los operadores de *casting* modernos del lenguaje (`static_cast`, `dynamic_cast`, `const_cast`, `reinterpret_cast`).  
Este módulo busca que el estudiante comprenda cómo C++ maneja la **conversión entre tipos primitivos, objetos y punteros**, y cuándo cada conversión es segura o peligrosa.

---

### 🧠 Conceptos teóricos clave

| Concepto | Descripción |
|-----------|-------------|
| **Conversión implícita** | El compilador transforma un tipo en otro automáticamente cuando es posible sin pérdida de información. |
| **Conversión explícita** | Se realiza mediante *casts* para indicar intencionalmente el cambio de tipo. |
| **`static_cast`** | Conversión segura y en tiempo de compilación entre tipos compatibles. |
| **`dynamic_cast`** | Conversión segura entre punteros o referencias dentro de una jerarquía de clases con funciones virtuales. |
| **`const_cast`** | Permite agregar o eliminar la cualificación `const` de una variable. |
| **`reinterpret_cast`** | Conversión de bajo nivel (peligrosa) que trata bits de memoria como otro tipo. |
| **Conversión de cadenas y números** | Uso de `std::stoi`, `std::stof`, `std::to_string`, etc. |

---

### 🧩 Ejercicio ex00 – *Scalar Converter*

#### 🎯 Objetivo
Implementar una clase que convierta una **cadena de texto** a los tipos primitivos `char`, `int`, `float` y `double`.

#### 💡 Descripción
El programa recibe un único argumento (una cadena) y determina su tipo antes de imprimir las conversiones posibles.

```cpp
int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}
```

```cpp
class ScalarConverter {
private:
    ScalarConverter();
public:
    static void convert(std::string const &literal);
};
```

Ejemplo de salida:
```
$ ./convert 42
char: '*'
int: 42
float: 42.0f
double: 42.0
```

#### 🧠 Conceptos aprendidos
- **Conversión de cadenas a tipos primitivos.**
- **Validación y detección de tipo de dato.**
- **Uso de funciones estándar: `std::stoi`, `std::stod`, `std::stof`.**
- **Formato de salida y control de precisión.**

---

### 🧩 Ejercicio ex01 – *Serialization*

#### 🎯 Objetivo
Aprender a convertir punteros a valores enteros (y viceversa) mediante **reinterpretación de memoria**.

#### 💡 Descripción
Se define una estructura `Data` y una clase que implementa funciones `serialize` y `deserialize` usando `reinterpret_cast`.

```cpp
struct Data {
    std::string name;
    int age;
};
```

```cpp
class Serializer {
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};
```

Ejemplo:
```cpp
Data d = {"Alice", 25};
uintptr_t raw = Serializer::serialize(&d);
Data* ptr = Serializer::deserialize(raw);
std::cout << ptr->name << " - " << ptr->age << std::endl;
```

#### 🧠 Conceptos aprendidos
- **Uso de `reinterpret_cast` para manipular direcciones.**
- **Comprensión del tipo `uintptr_t`.**
- **Conversión entre punteros y enteros de forma controlada.**
- **Representación interna de datos en memoria.**

---

### 🧩 Ejercicio ex02 – *Dynamic Casting*

#### 🎯 Objetivo
Aplicar **casting dinámico (`dynamic_cast`)** para identificar el tipo real de objetos en tiempo de ejecución.

#### 💡 Descripción
Se crea una jerarquía de clases con una base `Base` y tres derivadas (`A`, `B`, `C`).  
El programa genera una instancia aleatoria y luego la identifica mediante `dynamic_cast`.

```cpp
class Base { public: virtual ~Base() {}; };
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate();
void identify(Base* p);
void identify(Base& p);
```

Uso típico:
```cpp
Base* ptr = generate();
identify(ptr);   // output: "Actual type: B"
identify(*ptr);  // output: "Actual type: B"
```

#### 🧠 Conceptos aprendidos
- **Uso práctico de `dynamic_cast`.**
- **Identificación de tipos en tiempo de ejecución (RTTI).**
- **Comparación entre `dynamic_cast` y `static_cast`.**
- **Diseño de jerarquías con funciones virtuales.**

---

### 📊 Diagrama CPP06

```mermaid
graph TD
    A[ScalarConverter] --> B[Tipos primitivos]
    A --> C[Validación de entrada]
    D[Serializer] --> E[reinterpret_cast]
    F[Base] --> G[A]
    F --> H[B]
    F --> I[C]
```

---

### 🧾 Resumen CPP06

| Concepto | Descripción |
|-----------|-------------|
| `static_cast` | Conversión segura en tiempo de compilación |
| `dynamic_cast` | Conversión segura en tiempo de ejecución |
| `const_cast` | Añade o elimina `const` |
| `reinterpret_cast` | Reinterpreta los bits de memoria (peligroso) |
| RTTI | *Run-Time Type Information* para determinar tipos reales |
| Conversión de cadenas | De texto a numérico (`std::stoi`, `std::stof`, etc.) |

💡 **CPP06** enseña cómo C++ gestiona la **tipificación estricta** y cómo el programador puede manipular tipos con precisión, seguridad y control total sobre la memoria.

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

```
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

```
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

# ⚡ CPP09 – Contenedores personalizados y rendimiento

### 🎯 Objetivo del módulo
Diseñar y analizar **estructuras de datos y algoritmos personalizados**, aplicando los principios de eficiencia, modularidad y reutilización.  
El módulo CPP09 consolida todo lo aprendido en los anteriores — plantillas, STL, iteradores y algoritmos — para construir contenedores y sistemas propios que compitan en **rendimiento y complejidad algorítmica** con los del estándar.

---

### 🧠 Conceptos teóricos clave

| Concepto | Descripción |
|-----------|-------------|
| **Eficiencia algorítmica** | Evaluar el coste temporal y espacial de las operaciones. |
| **Contenedores personalizados** | Implementación de estructuras propias basadas en plantillas (`stack`, `queue`, `deque`, `map`, etc.). |
| **Algoritmos de ordenación y búsqueda** | Implementaciones prácticas de *merge sort*, *binary search*, y más. |
| **STL como referencia** | Replicar el comportamiento de contenedores estándar para entender su funcionamiento interno. |
| **Complejidad Big O** | Análisis del tiempo de ejecución de operaciones comunes. |
| **Optimización y rendimiento** | Técnicas para minimizar copias, uso de `const &`, y operaciones eficientes sobre datos. |

---

### 🧩 Ejercicio ex00 – *Bitcoin Exchange*

#### 🎯 Objetivo
Leer, almacenar y procesar datos históricos de valores de Bitcoin.  
Implementar un sistema que calcule el valor de una cantidad en función del precio histórico más cercano a una fecha dada.

#### 💡 Descripción
El programa recibe un archivo CSV con pares de valores (`date, value`) y un archivo de entrada con consultas (`date | amount`).  
Debe validar los datos, buscar la fecha más próxima y calcular el resultado.

```cpp
class BitcoinExchange {
private:
    std::map<std::string, float> _database;
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void loadDatabase(const std::string &filename);
    void processInput(const std::string &filename) const;
};
```

Ejemplo de entrada:
```
date | value
2011-01-03 | 3
2012-01-03 | 2
2013-01-03 | 1
```

Salida esperada:
```
2012-01-03 => 2 = 6
```

#### 🧠 Conceptos aprendidos
- **Uso de `std::map` para búsqueda por clave.**
- **Validación de formato y datos.**
- **Algoritmos de búsqueda (`lower_bound`).**
- **Gestión de archivos y excepciones.**
- **Comparación de fechas y parsing de strings.**

---

### 🧩 Ejercicio ex01 – *Reverse Polish Notation (RPN)*

#### 🎯 Objetivo
Implementar un **evaluador de expresiones matemáticas** utilizando la notación polaca inversa (RPN).

#### 💡 Descripción
La expresión se procesa con una **pila (`std::stack<int>`)**, aplicando operaciones a medida que se encuentran los operadores.

Ejemplo:
```
Input: "8 9 * 9 - 9 - 9 - 4 - 1 +"
Output: 42
```

```cpp
class RPN {
private:
    std::stack<int> _stack;
public:
    RPN();
    void evaluate(const std::string &expr);
};
```

#### 🧠 Conceptos aprendidos
- **Uso de `std::stack` como estructura LIFO.**
- **Procesamiento de expresiones matemáticas.**
- **Validación de entrada y control de errores.**
- **Conversión entre representación infija y postfija.**
- **Aplicación práctica de estructuras estándar.**

---

### 🧩 Ejercicio ex02 – *PmergeMe*

#### 🎯 Objetivo
Analizar y optimizar el **rendimiento de algoritmos de ordenación** implementando el *merge-insertion sort*.

#### 💡 Descripción
El programa toma una lista de enteros desde la línea de comandos y los ordena utilizando una combinación de *merge sort* y *insertion sort*.  
Además, compara los tiempos de ejecución entre dos contenedores (`std::vector` y `std::deque`).

```cpp
class PmergeMe {
private:
    std::vector<int> _vec;
    std::deque<int> _deq;
public:
    void sortAndCompare(char **argv);
private:
    template <typename T>
    void mergeInsertSort(T &container);
};
```

Ejemplo:
```
$ ./PmergeMe 9 3 5 1 7
Before: 9 3 5 1 7
After: 1 3 5 7 9
Time to process a range of 5 elements with std::vector : 0.0021 us
Time to process a range of 5 elements with std::deque  : 0.0024 us
```

#### 🧠 Conceptos aprendidos
- **Implementación de algoritmos híbridos (merge + insertion).**
- **Comparación de rendimiento entre contenedores.**
- **Uso de `std::chrono` para medir tiempos.**
- **Optimización con referencias y plantillas.**
- **Pensamiento algorítmico y eficiencia.**

---

### 📊 Diagrama CPP09

```
graph TD
    A[BitcoinExchange] --> B[std::map]
    B --> C[CSV Parsing]
    D[RPN] --> E[std::stack]
    F[PmergeMe] --> G[std::vector]
    F --> H[std::deque]
    F --> I[Merge-Insertion Sort]
```

---

### 🧾 Resumen CPP09

| Concepto | Descripción |
|-----------|-------------|
| Map | Contenedor asociativo clave-valor |
| Stack | Estructura LIFO para operaciones secuenciales |
| Vector / Deque | Contenedores secuenciales eficientes |
| Algoritmos híbridos | Combinación de merge e insertion sort |
| Optimización | Comparación de rendimiento y eficiencia |
| Parsing | Lectura y validación de datos desde archivos |

💡 **CPP09** culmina el aprendizaje de C++ en 42, integrando **plantillas, STL, algoritmos y eficiencia**.  
El estudiante pasa de escribir código funcional a **razonar sobre rendimiento, diseño y complejidad algorítmica**.

# 🧾 Conclusión General

Los módulos **CPP05–CPP09** representan el salto de un programador principiante en C++ a un **desarrollador con pensamiento algorítmico y dominio del lenguaje**.  
En este bloque, se pasa de escribir clases y herencias básicas a **entender el funcionamiento interno de C++**, sus **mecanismos de abstracción**, y la **optimización de código real**.

Cada módulo amplía una capa del conocimiento:

| Módulo | Enfoque principal | Resultado |
|--------|------------------|------------|
| **CPP05** | Excepciones y control de flujo | Código robusto y seguro ante errores |
| **CPP06** | Conversión de tipos y castings | Precisión y control sobre la memoria |
| **CPP07** | Plantillas y programación genérica | Reutilización y diseño de código flexible |
| **CPP08** | STL y algoritmos | Uso de contenedores y funciones estándar |
| **CPP09** | Eficiencia y estructuras personalizadas | Razonamiento algorítmico y optimización |

💡 Al finalizar este bloque, el estudiante es capaz de:
- Escribir código **genérico, seguro y eficiente**.  
- Analizar la **complejidad temporal y espacial** de sus programas.  
- Usar la **STL como herramienta profesional**, no como magia oculta.  
- Entender cómo C++ combina **bajo nivel y abstracción**, equilibrando rendimiento y legibilidad.

⚙️ En resumen, este bloque convierte el conocimiento en **maestría aplicada**, formando la base para proyectos mayores, entrevistas técnicas y desarrollo profesional en C++.

---

# 📚 Recursos Recomendados

Para complementar los módulos CPP05–CPP09, estos recursos te ayudarán a profundizar en los temas más relevantes del C++ moderno:

## 📘 Libros
- *Effective C++* – Scott Meyers  
  > Consejos prácticos sobre diseño, rendimiento y buenas prácticas.
- *The C++ Programming Language* – Bjarne Stroustrup  
  > Referencia completa escrita por el creador de C++.
- *Accelerated C++* – Andrew Koenig & Barbara Moo  
  > Excelente para aprender C++ con enfoque en STL y eficiencia.
- *Effective Modern C++* – Scott Meyers  
  > Centrado en C++11/14, ideal para avanzar más allá del cursus.

---

## 🎥 Videos y cursos
- [C++ STL Crash Course – The Cherno (YouTube)](https://www.youtube.com/watch?v=YcZffQ0M6Gk)  
- [CppCon Conference Talks](https://www.youtube.com/user/CppCon)  
- [FreeCodeCamp – C++ Full Course](https://www.youtube.com/watch?v=vLnPwxZdW4Y)

---

## 🌐 Documentación y referencias
- [cppreference.com](https://en.cppreference.com/) – Guía técnica y detallada del lenguaje.  
- [cplusplus.com](https://cplusplus.com/reference/) – Referencia clásica para funciones estándar.  
- [ISO C++ Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines) – Recomendaciones oficiales de buenas prácticas.

---

