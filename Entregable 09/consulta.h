#ifndef CONSULTA_H
#define CONSULTA_H

#include "Fecha.h"
#include "Hora.h"
#include "Paciente.h"
#include "Medico.h"
#include "Diagnostico.h"
#include "Medicamento.h"

class Consulta {
    private:
        Fecha fecha;
        Hora hora;
        Paciente paciente;
        Medico medico;
        Diagnostico diagnostico;
        Medicamento medicamento1;
        Medicamento medicamento2;
        Medicamento medicamento3;
    public:
        // Constructores
        Consulta();
        Consulta(Fecha valorFecha, Hora valorHora, Paciente valorPaciente, Medico valorMedico,
                Diagnostico valorDiagnostico, Medicamento valorMedicamento1, Medicamento valorMedicamento2,
                Medicamento valorMedicamento3);
        Consulta(const Consulta& copia);
        // Destructor
        ~Consulta();
        // Metodos
        std::string toString() const;
        int toInt() const;
        // Setters
        void setFecha(Fecha valorFecha);
        void setHora(Hora valorHora);
        void setPaciente(Paciente valorPaciente);
        void setMedico(Medico valorMedico);
        void setDiagnostico(Diagnostico valorDiagnostico);
        void setMedicamento1(Medicamento valorMedicamento);
        void setMedicamento2(Medicamento valorMedicamento);
        void setMedicamento3(Medicamento valorMedicamento);
        // Getters
        Fecha getFecha() const;
        Hora getHora() const;
        Paciente getPaciente() const;
        Medico getMedico() const;
        Diagnostico getDiagnostico() const;
        Medicamento getMedicamento1() const;
        Medicamento getMedicamento2() const;
        Medicamento getMedicamento3() const;
        // Operadores
        Consulta &operator = (const Consulta& copia);
        bool operator == (const Consulta& comparado) const;
        bool operator != (const Consulta& comparado) const;
        bool operator < (const Consulta& comparado) const;
        bool operator <= (const Consulta& comparado) const;
        bool operator > (const Consulta& comparado) const;
        bool operator >= (const Consulta& comparado) const;
        friend std::ostream& operator << (std::ostream& out, const Consulta& objSalida);
};

#endif