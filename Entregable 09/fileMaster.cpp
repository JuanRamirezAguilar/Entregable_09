#include "fileMaster.h"

#include "ArchivoConsulta.h"

#include <fstream>
#include <cstdlib>
#include <sstream>
#include <iostream>

#include "Paciente.h"
#include "Nombre.h"
#include "Fecha.h"
#include "Domicilio.h"
#include "Hora.h"
#include "Medico.h"
#include "Diagnostico.h"
#include "Medicamento.h"
#include "Consulta.h"

FileMaster::FileMaster() {}
FileMaster::~FileMaster() {}

Lista<Consulta> FileMaster::getMisConsultas() {return misConsultas;}
Lista<Medico> FileMaster::getMisMedicos() {return misMedicos;}

void FileMaster::importBackup(const std::string& nombreArchivo) {
    ArchivoMedico miArchivoMedico;
    ArchivoPaciente miArchivoPaciente;
    archivoMedicamento miArchivoMedicamento;
    ArchivoDiagnostico miArchivoDiagnostico;

    std::ifstream archivoEntrada;
    archivoEntrada.open(nombreArchivo, std::ios::in);   
    if (!archivoEntrada) {
        throw std::runtime_error("Error al abrir el archivo fileMaster::importBackup()");
    }

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
        if (!misDiagnosticos.buscar(miDiagnostico)) {
            misDiagnosticos.insertar(miDiagnostico);
        }

        // Toma el Medico de la consulta;
        flujoDeRegistro >> miMedico;
        miConsulta.setMedico(miMedico);
        if (!misMedicos.buscar(miMedico)) {
            misMedicos.insertar(miMedico);
        }
        
        // Toma el Paciente de la consulta;
        flujoDeRegistro >> miPaciente;
        miConsulta.setPaciente(miPaciente);
        if (!misPacientes.buscar(miPaciente)) {
            misPacientes.insertar(miPaciente);
        }

        // Toma el Medicamento de la consulta;
        flujoDeRegistro >> miMedicamento;
        miConsulta.setMedicamento1(miMedicamento);
        if (!misMedicamentos.buscar(miMedicamento)) {
            misMedicamentos.insertar(miMedicamento);
        }
        flujoDeRegistro >> miMedicamento;
        miConsulta.setMedicamento2(miMedicamento);
        if (!misMedicamentos.buscar(miMedicamento)) {
            misMedicamentos.insertar(miMedicamento);
        }
        flujoDeRegistro >> miMedicamento;
        miConsulta.setMedicamento3(miMedicamento);
        if (!misMedicamentos.buscar(miMedicamento)) {
            misMedicamentos.insertar(miMedicamento);
        }

        // Se ingresa en la lista
        misConsultas.insertar(miConsulta);
    }
    
    miArchivoMedico.addData(misMedicos);
    miArchivoPaciente.addData(misPacientes);
    miArchivoMedicamento.addData(misMedicamentos);
    miArchivoDiagnostico.addData(misDiagnosticos);
    archivoEntrada.close();
}