#include "diagnostico.h"
#include <iostream>

// Constructores
Diagnostico::Diagnostico() : codigo(""), descripcion(""), indicacion("") {}
Diagnostico::Diagnostico(std::string valorCodigo, std::string valorDescripcion, std::string valorIndicacion) : 
codigo(valorCodigo), descripcion(valorDescripcion), indicacion(valorIndicacion) {}
Diagnostico::Diagnostico(const Diagnostico& copia) : codigo(copia.codigo), descripcion(copia.descripcion), indicacion(copia.indicacion) {}

// Destructor
Diagnostico::~Diagnostico() {}

// Metodos
std::string Diagnostico::toString() const{
    return codigo + ", " + descripcion + ", " + indicacion;
}

// Setters
void Diagnostico::setCodigo(std::string valorCodigo) {codigo = valorCodigo;}
void Diagnostico::setDescripcion(std::string valorDescripcion) {descripcion = valorDescripcion;}
void Diagnostico::setIndicacion(std::string valorIndicacion) {indicacion = valorIndicacion;}

// Getters
std::string Diagnostico::getCodigo() const {return codigo;}
std::string Diagnostico::getDescripcion() const {return descripcion;}
std::string Diagnostico::getIndicacion() const {return indicacion;}

// Operadores
Diagnostico& Diagnostico::operator = (const Diagnostico& copia) {
    if (this == &copia) { return *this; }
    codigo = copia.codigo;
    descripcion = copia.descripcion;
    indicacion = copia.indicacion;
    return *this;
}
bool Diagnostico::operator == (const Diagnostico& comparado) {
    return (descripcion == comparado.descripcion);
}

bool Diagnostico::operator != (const Diagnostico& comparado) {
    return !(*this == comparado);
}

std::ostream& operator << (std::ostream& out, const Diagnostico& objSalida) {
    out << objSalida.codigo << "*" << objSalida.descripcion << "*" << objSalida.indicacion << "*";
    return out;
}

std::istream& operator >> (std::istream& in, Diagnostico& objEntrada) {
    std::string myString;

    std::getline(in, myString, '*');
    objEntrada.setCodigo(myString);

    std::getline(in, myString, '*');
    objEntrada.setDescripcion(myString);

    std::getline(in, myString, '*');
    if (myString == ")") {
        objEntrada.setDescripcion(objEntrada.getDescripcion() + myString);
        std::getline(in, myString, '*');
    }
    objEntrada.setIndicacion(myString);

    return in;
}