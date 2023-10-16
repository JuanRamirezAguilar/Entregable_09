#include "archivoConsulta.h"

#include <fstream>
#include <cstdlib>
#include <sstream>

#include "Paciente.h"
#include "Nombre.h"
#include "Fecha.h"
#include "Domicilio.h"
#include "Hora.h"
#include "Medico.h"
#include "Diagnostico.h"
#include "Medicamento.h"
#include "Consulta.h"

#include "ArchivoMedico.h"

ArchivoConsulta::ArchivoConsulta() {}


ArchivoConsulta::~ArchivoConsulta() {}

Lista<Consulta> ArchivoConsulta::importBackup(std::string& nombreArchivo) {
    std::ifstream archivoEntrada;
    archivoEntrada.open(nombreArchivo, std::ios::in);
    Lista<Consulta> miLista;    
    if (!archivoEntrada) {
        throw std::runtime_error("Error al abrir el archivo.");
    }

    ArchivoMedico archMed;
    Lista<Medico> medicos;

    std::string miCampo;
    while(!archivoEntrada.eof()) {

        std::getline(archivoEntrada, miCampo, '#');
        if (miCampo.empty()) { continue; }

        // Se instancian las clases necesarias
        Nombre miNombre;
        Fecha miFecha;
        Hora miHora;
        Domicilio miDomicilio;
        Paciente miPaciente;
        Medico miMedico;
        Medicamento miMedicamento;
        Diagnostico miDiagnostico;
        Consulta miConsulta;
        std::string codigo;

        std::stringstream flujoDeRegistro(miCampo);


        // Toma la fecha de la consulta
        flujoDeRegistro >> miFecha;
        miConsulta.setFecha(miFecha);
        
        // Toma la hora de la consulta
        flujoDeRegistro >> miHora;
        miConsulta.setHora(miHora);

        // Toma el Diagnostico de la consulta
        flujoDeRegistro >> miDiagnostico;
        miConsulta.setDiagnostico(miDiagnostico);

        // Toma el Medico de la consulta;
        flujoDeRegistro >> miMedico;
        miConsulta.setMedico(miMedico);
        if (!medicos.buscar(miMedico)) {
            medicos.insertar(miMedico);
        }
        
        // Toma el Paciente de la consulta;
        flujoDeRegistro >> miPaciente;
        miConsulta.setPaciente(miPaciente);

        // Toma el Medicamento de la consulta;
        flujoDeRegistro >> miMedicamento;
        miConsulta.setMedicamento1(miMedicamento);
        flujoDeRegistro >> miMedicamento;
        miConsulta.setMedicamento2(miMedicamento);
        flujoDeRegistro >> miMedicamento;
        miConsulta.setMedicamento3(miMedicamento);

        // Se ingresa en la lista
        miLista.insertar(miConsulta);
    }

    archivoEntrada.close();

    return miLista;

}