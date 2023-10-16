#include "MenuMedicos.h"

#include "StandarLibrary.h"
#include "Colores.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#define ALTURA_BORDE 100
#define ANCHURA_BORDE 150
#define ANCHURA_PANTALLA 1366
#define ALTURA_PANTALLA 768

const std::string Titulo = "Sistema Integral de Registros Medicos";
const std::string Subtitulo = "Menu de Medicos";

MenuMedicos::MenuMedicos() : opc("") {}

MenuMedicos::~MenuMedicos() {}

void MenuMedicos::setOpc(std::string valorOpc) { opc = valorOpc; }
std::string MenuMedicos::getOpc() { return opc; }

void MenuMedicos::menu() {
    std::string opciones;
    do {
        system(CLEAR);
        std::cout<<ARB; setborder(ALTURA_BORDE, ANCHURA_BORDE); std::cout<<RTNC;

        gotoxy(((ANCHURA_BORDE - int(Titulo.length())) / 2), 3);
        std::cout << VB << Titulo <<RTNC;
        gotoxy(((ANCHURA_BORDE - int(Subtitulo.length())) / 2), 4);
        std::cout << ARB << Subtitulo <<RTNC;

        gotoxy(3, 7);
        std::cout <<GB; std::cout << "Opciones del Menu:";
        gotoxy(3, 9);
        std::cout <<GB; std::cout << "Agregar un Medico.         [ " <<RF<< "A" <<GB " ]";
        gotoxy(3, 10);
        std::cout <<GB; std::cout << "Elimnar un Medico.         [ " <<RF<< "B" <<GB " ]";
        gotoxy(3, 11);
        std::cout <<GB; std::cout << "Buscar un Medico.          [ " <<RF<< "C" <<GB " ]";
        gotoxy(3, 12);
        std::cout <<GB; std::cout << "Regresar al menu anterior. [ " <<RF<< "X" <<GB " ]";

        gotoxy(3, 14);
        std::cout <<GB << "Tu opcion ==> ";
        gotoxy(18, 14);
        fflush(stdin);
        std::cout <<RF; std::getline(std::cin, opciones); setOpc(opciones); std::cout <<RTNC;

        if (opc == "A" or opc == "a")      { agregar(); } 
        else if (opc == "B" or opc == "b") { eliminar(); } 
        else if (opc == "C" or opc == "c") { buscar(); }
        else if (opc == "X" or opc == "x") { return; }
        else { gotoxy(3, 16); std::cout <<GB; std::cout << "La opcion: \"" <<RB<< opc <<GB<< "\" no es una opcion valida..."<<RTNC; pausa(); }

    } while (opc != "X" and opc != "x");
}

void MenuMedicos::agregar() {
    Medico miMedico;
    Nombre MiNombre;
    Hora miHora;
    std::string miString;
    int auxHora;
    const std::string subtiImport = "Agregar un Medico";

    system(CLEAR);
    std::cout<<ARB; setborder(ALTURA_BORDE, ANCHURA_BORDE); std::cout<<RTNC;

    gotoxy(((ANCHURA_BORDE - int(Titulo.length())) / 2), 3);
    std::cout << VB << Titulo <<RTNC;
    gotoxy(((ANCHURA_BORDE - int(Subtitulo.length())) / 2), 4);
    std::cout << ARB << Subtitulo <<RTNC;
    gotoxy(((ANCHURA_BORDE - int(subtiImport.length())) / 2), 5);
    std::cout << AB << subtiImport <<RTNC;

    gotoxy(3, 7);
    std::cout << GF << "Ingresar un medico nuevo al archivo." <<RTNC;

    gotoxy(3, 9);
    std::cout << GF << "Dame la Cedula del medico:" <<RTNC;
    gotoxy(40, 9);
    fflush(stdin);
    std::getline(cin, miString);
    miMedico.setCedula(miString);

    gotoxy(3, 11);
    std::cout << GF << "Dame el Apellido del Medico:" <<RTNC;
    fflush(stdin);
    gotoxy(40, 11);
    std::getline(cin, miString);
    MiNombre.setApellido(miString);

    gotoxy(3, 13);
    std::cout << GF << "Dame el Nombre del Medico:" <<RTNC;
    gotoxy(40, 13);
    fflush(stdin);
    std::getline(cin, miString);
    MiNombre.setNombre(miString);
    miMedico.setNombre(MiNombre);

    gotoxy(3, 15);
    std::cout << GF << "Dame el Codigo del Medico:" <<RTNC;
    gotoxy(40, 15);
    fflush(stdin);
    std::getline(cin, miString);
    miMedico.setCodigo(miString);

    gotoxy(3, 17);
    std::cout << GF << "Dame la hora de entrada del Medico:" <<RTNC;
    gotoxy(3, 18);
    std::cout << GF << "Hora:" <<RTNC;
    gotoxy(15, 18);
    cin >> auxHora;
    miHora.setHora(auxHora);
    gotoxy(3, 19);
    std::cout << GF << "Minutos:" <<RTNC;
    gotoxy(15, 19);
    cin >> auxHora;
    miHora.setMinuto(auxHora);
    miMedico.setHoraEntrada(miHora);

    gotoxy(3, 21);
    std::cout << GF << "Dame la hora de salida del Medico:" <<RTNC;
    gotoxy(3, 22);
    std::cout << GF << "Hora:" <<RTNC;
    gotoxy(15, 22);
    cin >> auxHora;
    miHora.setHora(auxHora);
    gotoxy(3, 23);
    std::cout << GF << "Minutos:" <<RTNC;
    gotoxy(15, 23);
    cin >> auxHora;
    miHora.setMinuto(auxHora);
    miMedico.setHoraSalida(miHora);

    miArchivoMedico.addData(miMedico);

    gotoxy(3, 25);
    std::cout << VB << "Medico Registrado en el archivo..." <<RTNC; pausa();
}

void MenuMedicos::eliminar() {
    std::string opcElim;
    gotoxy(3, 16);
    std::cout << GB << "Eliminar por Nombre.  [ " <<RF<< "A" <<GB " ]";
    gotoxy(3, 17);
    std::cout << GB << "Eliminar por Codigo.  [ " <<RF<< "B" <<GB " ]";
    gotoxy(3, 18);
    std::cout << GB << "Regresar al menu.     [ " <<RF<< "X" <<GB " ]";
    gotoxy(3, 19);
    std::cout <<GB << "Tu opcion ==> ";
    gotoxy(18, 19);
    std::cout <<RF; std::getline(std::cin, opcElim); setOpc(opcElim); std::cout <<RTNC;

    if (opcElim == "A" or opcElim == "a") {
        Nombre miNombre;
        system(CLEAR);
        const std::string subtiImport = "Eliminar un Medico";
        std::cout<<ARB; setborder(ALTURA_BORDE, ANCHURA_BORDE); std::cout<<RTNC;

        gotoxy(((ANCHURA_BORDE - int(Titulo.length())) / 2), 3);
        std::cout << VB << Titulo <<RTNC;
        gotoxy(((ANCHURA_BORDE - int(Subtitulo.length())) / 2), 4);
        std::cout << ARB << Subtitulo <<RTNC;
        gotoxy(((ANCHURA_BORDE - int(subtiImport.length())) / 2), 5);
        std::cout << AB << subtiImport <<RTNC;

        std::string stringAux;
        gotoxy(3, 7);
        std::cout <<GF<< "Ingresa el apellido del Medico a buscar: ";
        gotoxy(45, 7);
        fflush(stdin);
        getline(std::cin, stringAux);
        miNombre.setNombre(stringAux);

        gotoxy(3, 9);
        std::cout <<GF<< "Ingresa el nombre del Medico a buscar: ";
        gotoxy(43, 9);
        fflush(stdin);
        getline(std::cin, stringAux);
        miNombre.setApellido(stringAux);

        int idx = miArchivoMedico.findData(miNombre);

        if (idx != -1) {
            string opcBorrar;
            Medico showMedico = miArchivoMedico.getData(idx);

            gotoxy(3, 11);
            std::cout << "Medico: " << std::endl;
            gotoxy(3, 12);
            std::cout << AF << showMedico.toString();

            gotoxy(3, 15);
            std::cout << ARB << "Seguro que lo quieres borrar?" << RTNC <<std::endl;
            gotoxy(3, 16);
            std::cout << GB << "Si.  [ " <<RF<< "Y" <<GB " ]";
            gotoxy(3, 17);
            std::cout << GB << "No.  [ " <<RF<< "N" <<GB " ]";
            gotoxy(3, 18);
            std::cout <<GB << "Tu opcion ==> ";
            gotoxy(18, 18);
            std::cout <<RF; std::getline(std::cin, opcBorrar); setOpc(opcBorrar); std::cout <<RTNC;

            if (opcBorrar == "Y" or opcBorrar == "y") {
                miArchivoMedico.delData(idx);
                miArchivoMedico.compress();
                gotoxy(3, 20);
                std::cout <<VB<< "Medico eliminado correctamente."<<RTNC; pausa();
            } else if(opcBorrar == "N" or opcBorrar == "n" or opcBorrar != "Y" or opcBorrar != "y") {
                gotoxy(3, 20);
                std::cout << RB << "Opcion invalida o elegiste \"N\", Saliendo de eliminar medico..." <<RTNC; timeStop(1000);
            } 
        } else {
            gotoxy(3, 11);
            std::cout <<RB<< "No se encontró un medico con ese nombre."<<RTNC; pausa();
        }

    } else if (opcElim == "B" or opcElim == "b") {
        system(CLEAR);
        const std::string subtiImport = "Eliminar un Medico";
        std::cout<<ARB; setborder(ALTURA_BORDE, ANCHURA_BORDE); std::cout<<RTNC;

        gotoxy(((ANCHURA_BORDE - int(Titulo.length())) / 2), 3);
        std::cout << VB << Titulo <<RTNC;
        gotoxy(((ANCHURA_BORDE - int(Subtitulo.length())) / 2), 4);
        std::cout << ARB << Subtitulo <<RTNC;
        gotoxy(((ANCHURA_BORDE - int(subtiImport.length())) / 2), 5);
        std::cout << AB << subtiImport <<RTNC;

        std::string codigo;
        gotoxy(3, 7);
        std::cout <<GF<< "Ingresa el codigo del Medico a buscar: ";
        gotoxy(43, 7);
        fflush(stdin);
        getline(std::cin, codigo);
        /////////////////////////////////
        int idx = miArchivoMedico.findData(codigo);

        if (idx != -1) {
            string opcBorrar;
            Medico showMedico = miArchivoMedico.getData(idx);

            gotoxy(3, 9);
            std::cout << "Medico: " << std::endl;
            gotoxy(3, 10);
            std::cout << AF << showMedico.toString();

            gotoxy(3, 13);
            std::cout << ARB << "Seguro que lo quieres borrar?" << RTNC <<std::endl;
            gotoxy(3, 14);
            std::cout << GB << "Si.  [ " <<RF<< "Y" <<GB " ]";
            gotoxy(3, 15);
            std::cout << GB << "No.  [ " <<RF<< "N" <<GB " ]";
            gotoxy(3, 16);
            std::cout <<GB << "Tu opcion ==> ";
            gotoxy(18, 16);
            std::cout <<RF; std::getline(std::cin, opcBorrar); setOpc(opcBorrar); std::cout <<RTNC;

            if (opcBorrar == "Y" or opcBorrar == "y") {
                miArchivoMedico.delData(idx);
                miArchivoMedico.compress();
                gotoxy(3, 18);
                std::cout <<VB<< "Medico eliminado correctamente."<<RTNC; pausa();
            } else if(opcBorrar == "N" or opcBorrar == "n" or opcBorrar != "Y" or opcBorrar != "y") {
                gotoxy(3, 18);
                std::cout << RB << "Opcion invalida o elegiste \"N\", Saliendo de eliminar medico..." <<RTNC; timeStop(1000);
            } 
        } else {
            gotoxy(3, 9);
            std::cout <<RB<< "No se encontro un medico con ese codigo."<<RTNC; pausa();
        }

    } else if (opcElim == "X" or opcElim == "x") {
        return;
    } else {
        gotoxy(3, 21); std::cout <<GB; std::cout << "La opcion: \"" <<RB<< opcElim <<GB<< "\" no es una opcion valida..."<<RTNC; pausa();
    }
}

void MenuMedicos::buscar() {
    std::string opcBuscar;
    gotoxy(3, 16);
    std::cout << GB << "Buscar por Nombre.  [ " <<RF<< "A" <<GB " ]";
    gotoxy(3, 17);
    std::cout << GB << "Buscar por Codigo.  [ " <<RF<< "B" <<GB " ]";
    gotoxy(3, 18);
    std::cout << GB << "Regresar al menu.   [ " <<RF<< "X" <<GB " ]";
    gotoxy(3, 19);
    std::cout <<GB << "Tu opcion ==> ";
    gotoxy(18, 19);
    fflush(stdin);
    std::cout <<RF; std::getline(std::cin, opcBuscar); setOpc(opcBuscar); std::cout <<RTNC;

    if (opcBuscar == "A" or opcBuscar == "a") {
        system(CLEAR);
        const std::string subtiImport = "Buscar un Medico";
        std::cout<<ARB; setborder(ALTURA_BORDE, ANCHURA_BORDE); std::cout<<RTNC;

        gotoxy(((ANCHURA_BORDE - int(Titulo.length())) / 2), 3);
        std::cout << VB << Titulo <<RTNC;
        gotoxy(((ANCHURA_BORDE - int(Subtitulo.length())) / 2), 4);
        std::cout << ARB << Subtitulo <<RTNC;
        gotoxy(((ANCHURA_BORDE - int(subtiImport.length())) / 2), 5);
        std::cout << AB << subtiImport <<RTNC;

        std::string stringAux;
        Nombre nombreAux;

        gotoxy(3, 7);
        std::cout <<GF<< "Ingresa el apellido del Medico a buscar: ";
        gotoxy(45, 7);
        fflush(stdin);
        getline(std::cin, stringAux);
        nombreAux.setApellido(stringAux);

        gotoxy(3, 9);
        std::cout <<GF<< "Ingresa el nombre del Medico a buscar: ";
        gotoxy(43, 9);
        fflush(stdin);
        getline(std::cin, stringAux);
        nombreAux.setNombre(stringAux);

        int idx = miArchivoMedico.findData(nombreAux);
        
        if (idx != -1) {
            Medico medicoAux = miArchivoMedico.getData(idx);

            // Imprime el Nombre del Medico
            gotoxy(3, 11);
            cout << ARB << "Nombre del Medico: ";
            gotoxy(23, 11);
            cout << VF << medicoAux.getNombre().toString();

            // Imprime el Codigo del Medico
            gotoxy(3, 12);
            cout << ARB << "Codigo del Medico: ";
            gotoxy(23, 12);
            cout << VF << medicoAux.getCodigo();

            // Imprime la Cedula del Medico
            gotoxy(3, 13);
            cout << ARB << "Cedula del Medico: ";
            gotoxy(23, 13);
            cout << VF << medicoAux.getCedula();

            // Imprime la Hora de Entrada del Medico
            gotoxy(3, 14);
            cout << ARB << "Hora de Entrada del Medico: ";
            gotoxy(31, 14);
            cout << VF << medicoAux.getHoraEntrada().toString();

            // Imprime la Hora de Salida del Medico
            gotoxy(3, 15);
            cout << ARB << "Hora de Salida del Medico: ";
            gotoxy(31, 15);
            cout << VF << medicoAux.getHoraSalida().toString();

            pausa();

        } else {
            gotoxy(3, 11);
            std::cout <<RB<< "No se encontro un medico con ese nombre."<<RTNC; pausa();
        }

    } else if (opcBuscar == "B" or opcBuscar == "b") {
        system(CLEAR);
        const std::string subtiImport = "Buscar un Medico";
        std::cout<<ARB; setborder(ALTURA_BORDE, ANCHURA_BORDE); std::cout<<RTNC;

        gotoxy(((ANCHURA_BORDE - int(Titulo.length())) / 2), 3);
        std::cout << VB << Titulo <<RTNC;
        gotoxy(((ANCHURA_BORDE - int(Subtitulo.length())) / 2), 4);
        std::cout << ARB << Subtitulo <<RTNC;
        gotoxy(((ANCHURA_BORDE - int(subtiImport.length())) / 2), 5);
        std::cout << AB << subtiImport <<RTNC;

        std::string stringAux;

        gotoxy(3, 7);
        std::cout <<GF<< "Ingresa el codigo del Medico a buscar: ";
        gotoxy(45, 7);
        fflush(stdin);
        getline(std::cin, stringAux);

        int idx = miArchivoMedico.findData(stringAux);
        
        if (idx != -1) {
            Medico medicoAux = miArchivoMedico.getData(idx);

            // Imprime el Nombre del Medico
            gotoxy(3, 9);
            cout << ARB << "Nombre del Medico: ";
            gotoxy(23, 9);
            cout << VF << medicoAux.getNombre().toString();

            // Imprime el Codigo del Medico
            gotoxy(3, 10);
            cout << ARB << "Codigo del Medico: ";
            gotoxy(23, 10);
            cout << VF << medicoAux.getCodigo();

            // Imprime la Cedula del Medico
            gotoxy(3, 11);
            cout << ARB << "Cedula del Medico: ";
            gotoxy(23, 11);
            cout << VF << medicoAux.getCedula();

            // Imprime la Hora de Entrada del Medico
            gotoxy(3, 12);
            cout << ARB << "Hora de Entrada del Medico: ";
            gotoxy(31, 12);
            cout << VF << medicoAux.getHoraEntrada().toString();

            // Imprime la Hora de Salida del Medico
            gotoxy(3, 13);
            cout << ARB << "Hora de Salida del Medico: ";
            gotoxy(31, 13);
            cout << VF << medicoAux.getHoraSalida().toString();

            pausa();

        } else {
            gotoxy(3, 9);
            std::cout <<RB<< "No se encontro un medico con ese codigo."<<RTNC; pausa();
        }
    } else if (opcBuscar == "X" or opcBuscar == "x") {
        return;
    } else {
        gotoxy(3, 21); std::cout <<GB; std::cout << "La opcion: \"" <<RB<< opcBuscar <<GB<< "\" no es una opcion valida..."<<RTNC; pausa();
    }
}

void MenuMedicos::importarArchivo() {
    miArchivoMedico.importBackup();
}