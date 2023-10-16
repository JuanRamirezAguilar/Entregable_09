#include "hora.h"
#include <chrono>
#include <cstdio>

#include <iostream>

// Constructores
Hora::Hora() {
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    hora = local->tm_hour;
    minuto = local->tm_min;
}

Hora::Hora(int valorHora, int valorMinuto) : Hora() {
    if ((valorHora >= 0 && valorHora <= 23) && (valorMinuto >= 0 && valorMinuto <= 59)) {
        hora = valorHora; minuto = valorMinuto;
    } else {
        std::cout << "Error en la hora dada, estableciendo la hora predeterminada"; std::cin.ignore();
    }
}

Hora::Hora(const Hora& copia) : minuto(copia.minuto), hora(copia.hora) {}

// Destructor
Hora::~Hora() {}

// Metodos
std::string Hora::toString() const {
    char buffer[6];
    snprintf(buffer, sizeof(buffer), "%02d:%02d", hora, minuto);
    return std::string(buffer);
}

int Hora::toInt() const {
    return (hora * 100) + (minuto * 10);
}

// Setters
void Hora::setMinuto(int valorMinuto) { 
    if (valorMinuto >= 0 && valorMinuto <= 59) {
        minuto = valorMinuto;
    } else {minuto = 0;}
}

void Hora::setHora(int valorHora) {
    if (valorHora >= 0 && valorHora <= 23) {
        hora = valorHora;
    } else {valorHora = 0;}
}

// Getters
int Hora::getMinuto() const {return minuto;}
int Hora::getHora() const {return hora;}

// Operadores
Hora& Hora::operator = (const Hora& copia) {
    if (this == &copia) { return *this; }
    minuto = copia.minuto;
    hora = copia.hora;
    return *this;
}

bool Hora::operator == (const Hora& comparado) const {
    return toInt() == comparado.toInt();
}

bool Hora::operator != (const Hora& comparado) const {
    return !(*this == comparado);
}

bool Hora::operator < (const Hora& comparado) const {
    return toInt() < comparado.toInt();
}

bool Hora::operator <= (const Hora& comparado) const {
    return *this < comparado || *this == comparado;
}

bool Hora::operator > (const Hora& comparado) const {
    return toInt() < comparado.toInt();
}

bool Hora::operator >= (const Hora& comparado) const {
    return *this > comparado || *this == comparado;
}

std::ostream& operator << (std::ostream& out, const Hora& objSalida) {
    out << objSalida.hora << ":" << objSalida.minuto << "*";
    return out;
}

std::istream& operator >> (std::istream& in, Hora& objEntrada) {
    std::string myString;

    std::getline(in, myString, ':');
    objEntrada.setHora(std::stoi(myString));

    std::getline(in, myString, '*');
    objEntrada.setMinuto(std::stoi(myString));
    
    return in;
}

/*std::istream& operator >> (std::istream& in, Hora& objEntrada) {
    std::string myString;
    std::getline(in, myString, ':');
    // Verificar si el primer carácter es cero y eliminarlo si es necesario
    if (myString.size() > 1 && myString[0] == '0') {
        myString = myString.substr(1); // Eliminar el primer carácter
    }
    objEntrada.setHora(std::stoi(myString));
    std::getline(in, myString, '*');
    // Verificar si el primer carácter es cero y eliminarlo si es necesario
    if (myString.size() > 1 && myString[0] == '0') {
        myString = myString.substr(1); // Eliminar el primer carácter
    }
    objEntrada.setMinuto(std::stoi(myString));
    return in;
}*/