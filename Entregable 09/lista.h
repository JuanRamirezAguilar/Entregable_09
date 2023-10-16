#ifndef LISTA_H
#define LISTA_H

#include <iostream>

template <class DATO>
class Lista;

class Encabezado {

    private:
        int tam;

    public:
        Encabezado() : tam(0) {};
        int get_tam() const {return tam;}
        void aum_tam() {tam++;}
        void dis_tam() {tam--;}
        void clear_tam() {tam = 0;}
};

template <class DATO>
class Nodo {
    private:
        DATO dato;
        Nodo<DATO>* sig;

    public:
        Nodo() : sig(nullptr){}; // Constructor
        DATO get_dato () { return dato; }
        friend class Lista<DATO>;
};

template <class DATO>
class Lista {
    private:
        Nodo<DATO>* lista;
        Encabezado encabezado;

    public:
        Lista() : lista(nullptr){};
        ~Lista();
        Lista(const Lista<DATO>& otraLista);
        bool vacia()const;
        Nodo<DATO>* ult()const;
        Nodo<DATO>* pri()const;
        Nodo<DATO>* ant(Nodo<DATO>* pos)const;
        void insertar(Nodo<DATO>* pos, DATO elem);
        void insertar(DATO elem);
        bool eliminar(Nodo<DATO>* pos);
        bool eliminar(DATO elem);
        void anular();
        Nodo<DATO>* buscar(DATO elem)const;
        int length() const;
        DATO indice(int indice);
        DATO indice(int indice) const;
        void organizar();
        void imprimir(bool array)const;

        Lista<DATO>& operator = (const Lista<DATO>& otraLista);
        bool operator == (const Lista<DATO>& otraLista) const;
};

template <class DATO>
Lista<DATO>::Lista(const Lista<DATO>& otraLista) : lista(nullptr) {
    // Copiar el tamaño del encabezado
    encabezado = otraLista.encabezado;

    // Copiar los elementos de la otra lista
    Nodo<DATO>* aux = otraLista.lista;
    while (aux != nullptr) {
        insertar(aux->dato);
        aux = aux->sig;
    }
}

template <class DATO>
Lista<DATO>::~Lista() {
    anular();
}

template <class DATO>
bool Lista<DATO>::vacia ()const {
    return lista == nullptr;
}

template <class DATO>
Nodo<DATO>* Lista<DATO>::ult ()const {
    if (vacia()) {return lista;}
    Nodo <DATO>* aux = lista;
    while (aux->sig != nullptr) {
        aux = aux->sig;
    }
    return aux;
}

template <class DATO>
Nodo<DATO>* Lista<DATO>::pri ()const {
    return (vacia()) ? nullptr : lista;
}

template <class DATO>
Nodo<DATO>* Lista<DATO>::ant (Nodo<DATO>* pos) const {
    if (vacia() || pos == nullptr)
        return nullptr;

    Nodo<DATO>* aux = lista;
    while ((aux != nullptr) && (aux->sig != pos)) {
        aux = aux->sig;
    }
    return aux;
}

template <class DATO>
void Lista<DATO>::insertar (Nodo<DATO>* pos, DATO elem) {
    Nodo<DATO>* nuevo_nodo = new Nodo<DATO>;
    nuevo_nodo->dato = elem;
    if (pos == nullptr) {
        nuevo_nodo->sig = lista;
        lista = nuevo_nodo;
        encabezado.aum_tam();
    } else {
        nuevo_nodo->sig = pos->sig;
        pos->sig = nuevo_nodo;
        encabezado.aum_tam();
    }
}

template <class DATO>
void Lista<DATO>::insertar (DATO elem) {
    insertar(ult(), elem);
}

template <class DATO>
bool Lista<DATO>::eliminar(Nodo<DATO>* pos) {
    if (vacia() || pos == nullptr)
        return false;

    if (pos == lista) {
        lista = lista->sig;
    } else {
        ant(pos)->sig = pos->sig;
    }
    delete pos;
    encabezado.dis_tam();
    return true;
}

template <class DATO>
bool Lista<DATO>::eliminar(DATO elem) {
    Nodo<DATO>* buscado = buscar(elem);
    if (buscado) {
        eliminar(buscado); return true;
    } else {
        std::cout << "No se encontro elemento que eliminar...";
        std::cin.clear(); std::cin.sync(); std::cin.ignore();
        return false;
    }
}

template <class DATO>
void Lista<DATO>::anular () {
    Nodo<DATO>* actual = lista;
    Nodo<DATO>* siguiente;
    while (actual != nullptr) {
        siguiente = actual->sig;
        delete actual;
        actual = siguiente;
    }
    lista = nullptr;
    encabezado.clear_tam();
}

template <class DATO>
Nodo<DATO>* Lista<DATO>::buscar (DATO elem)const {
    Nodo<DATO>* aux = lista;
    while (aux != nullptr) {
        if (aux->dato == elem)
            return aux;
        aux = aux->sig;
    }
    return aux;
}


template <class DATO>
int Lista<DATO>::length() const {
    return encabezado.get_tam();
}

template <class DATO>
void Lista<DATO>::organizar() {
    if (!vacia()) {
        Nodo<DATO>* actual , *siguiente;
        DATO aux;

        actual = lista;
        while(actual->sig != nullptr) {
            siguiente = actual->sig;
            while(siguiente != nullptr) {
                if(actual->dato > siguiente->dato) {
                    aux = siguiente->dato;
                    siguiente->dato = actual->dato;
                    actual->dato = aux;
                }
                siguiente = siguiente->sig;
            }
            actual = actual->sig;
            siguiente = actual->sig;
        }
    } else {
        std::cout << "No se puede ordenar una lista vacia.";
        std::cin.clear(); std::cin.sync(); std::cin.ignore();
    }
}

template <class DATO>
void Lista<DATO>::imprimir (bool array)const {
    if (!vacia()) {
        Nodo<DATO>* aux = lista;
        if (!array) {
            short indice = 1;
            while (aux != nullptr) {
                std::cout << indice++ << "._ ";
                std::cout << aux->dato <<std::endl<<std::endl;
                aux = aux->sig;
            }
        } else {
            std::cout << "[";
            while (aux != nullptr) {
                if (aux->sig != nullptr) {
                    std::cout << aux->dato << ", ";
                }
                else {
                    std::cout << aux->dato << "]";
                }
                aux = aux->sig;
            }
        }
        std::cout<<std::endl;
    } else {
        std::cout << "La lista esta vacia.";
        std::cin.clear(); std::cin.sync(); std::cin.ignore();
    }
}

template <class DATO>
DATO Lista<DATO>::indice(int indice) {
    if (indice > length() || indice < 0) {
        throw std::out_of_range("Índice fuera de rango");
    } else {
        int index = 0;
        Nodo<DATO>* aux = lista;
        while (index <= indice && aux != nullptr) {
            if (index == indice) {
                return aux->dato;
            }
            index++;
            aux = aux->sig;
        }
    }
    throw std::logic_error("Elemento no encontrado"); // Opción de manejo adicional si el elemento no existe.
}

template <class DATO>
DATO Lista<DATO>::indice(int indice) const {
    if (indice > length() || indice < 0) {
        throw std::out_of_range("Índice fuera de rango");
    } else {
        int index = 0;
        Nodo<DATO>* aux = lista;
        while (index <= indice && aux != nullptr) {
            if (index == indice) {
                return aux->dato;
            }
            index++;
            aux = aux->sig;
        }
    }
    throw std::logic_error("Elemento no encontrado"); // Opción de manejo adicional si el elemento no existe.
}

template <class DATO>
Lista<DATO>& Lista<DATO>::operator=(const Lista<DATO>& otraLista) {
    if (this == &otraLista) {
        return *this; // Evitar autoasignación
    }

    // Limpiar la lista actual
    anular();

    // Copiar el tamaño del encabezado
    encabezado = otraLista.encabezado;

    // Copiar los elementos de la otra lista
    Nodo<DATO>* aux = otraLista.lista;
    while (aux != nullptr) {
        insertar(aux->dato);
        aux = aux->sig;
    }
    return *this;
}

template <class DATO>
bool Lista<DATO>::operator==(const Lista<DATO>& otraLista) const {
    if (this->length() != otraLista.length()) {
        return false;
    }

    Nodo<DATO>* aux1 = this->lista;
    Nodo<DATO>* aux2 = otraLista.lista;

    while (aux1 != nullptr && aux2 != nullptr) {
        if (aux1->dato != aux2->dato) {
            return false;
        }
        aux1 = aux1->sig;
        aux2 = aux2->sig;
    }

    return true;
}

#endif