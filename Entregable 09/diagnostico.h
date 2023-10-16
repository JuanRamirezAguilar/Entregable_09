#ifndef DIAGNOSTICO_H
#define DIAGNOSTICO_H

#include <string>

class Diagnostico {
    private:
        std::string codigo;
        std::string descripcion;
        std::string indicacion;

    public:
        // Constructores
        Diagnostico();
        Diagnostico(std::string valorCodigo, std::string valorDescripcion, std::string valorIndicacion);
        Diagnostico(const Diagnostico& copia);
        // Destructor
        ~Diagnostico();
        // Metodos
        std::string toString() const;
        // Setters
        void setCodigo(std::string valorCodigo);
        void setDescripcion(std::string valorDescripcion);
        void setIndicacion(std::string valorIndicacion);
        // Getters
        std::string getCodigo() const;
        std::string getDescripcion() const;
        std::string getIndicacion() const;
        // Operadores
        Diagnostico &operator = (const Diagnostico& copia);
        bool operator == (const Diagnostico& comparado);
        bool operator != (const Diagnostico& comparado);
        friend std::ostream& operator << (std::ostream& out, const Diagnostico& objSalida);
        friend std::istream& operator >> (std::istream& in, Diagnostico& objEntrada);
};

#endif // DIAGNOSTICO_H