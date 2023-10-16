#include "menuPrincipal.h"

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

MenuPrincipal::MenuPrincipal() : opc(""), importe(false) {
    // Se revisa si ya existen archivos ya creados anteriormente.
    if (ifstream("archivoMedicos.txt")) {
        importe = true;
    }
}

MenuPrincipal::~MenuPrincipal() {}

void MenuPrincipal::menu() {
    //AltEnter();
    do {
        system(CLEAR);
        std::cout<<ARB; setborder(ALTURA_BORDE, ANCHURA_BORDE); std::cout<<RTNC;

        gotoxy(((ANCHURA_BORDE - int(Titulo.length())) / 2), 3);
        std::cout << VB << Titulo <<RTNC;

        gotoxy(3, 7);
        std::cout <<GB; std::cout << "Opciones del Menu:";
        gotoxy(3, 9);
        std::cout <<GB; std::cout << "Consultas.           [ " <<RF<< "A" <<GB " ]";
        gotoxy(3, 10);
        std::cout <<GB; std::cout << "Medicos.             [ " <<RF<< "B" <<GB " ]";
        gotoxy(3, 11);
        std::cout <<GB; std::cout << "Pacientes.           [ " <<RF<< "C" <<GB " ]";
        gotoxy(3, 12);
        std::cout <<GB; std::cout << "Diagnosticos.        [ " <<RF<< "D" <<GB " ]";
        gotoxy(3, 13);
        std::cout <<GB; std::cout << "Medicamentos.        [ " <<RF<< "E" <<GB " ]";
        gotoxy(3, 14);
        std::cout <<GB; std::cout << "Importar archivo.    [ " <<RF<< "F" <<GB " ]";
        gotoxy(3, 15);
        std::cout <<GB; std::cout << "Salir del programa.  [ " <<RF<< "X" <<GB " ]";

        gotoxy(3, 17);
        std::cout <<GB << "Tu opcion ==> ";
        gotoxy(18, 17);
        fflush(stdin);
        std::cout <<RF; std::getline(std::cin, opc);  std::cout <<RTNC;

        if (opc == "A" or opc == "a") { consultas(); }
        else if (opc == "B" or opc == "b") { medicos(); }
        else if (opc == "C" or opc == "c") { pacientes(); }
        else if (opc == "D" or opc == "d") { diagnosticos(); }
        else if (opc == "E" or opc == "e") { medicamentos(); }
        else if (opc == "F" or opc == "f") { importarArchivo(); }
        else if (opc == "X" or opc == "x") { salir(); }

        else { gotoxy(3, 19); std::cout <<GB; std::cout << "La opcion: \"" <<RB<< opc <<GB<< "\" no es una opcion valida..."<<RTNC; pausa(); }

    } while (opc != "X" and opc != "x");
}

void MenuPrincipal::salir() {
    gotoxy(3, 19);
    std::cout <<RB; std::cout << "Saliendo del programa..."<<RTNC; timeStop(2000);
}

void MenuPrincipal::consultas() {
    if (importe) {
        MenuConsultas miMenuConsultas;
        miMenuConsultas.menu();
    } else {
        gotoxy(3, 19);
        std::cout <<RB; std::cout << "Primero importa el archivo..."<<RTNC; pausa();
    }
}

void MenuPrincipal::medicos() {
    if (importe) {
        MenuMedicos miMenuMedicos;
        miMenuMedicos.importarArchivo();
        miMenuMedicos.menu();
    } else {
        gotoxy(3, 19);
        std::cout <<RB; std::cout << "Primero importa el archivo..."<<RTNC; pausa();
    }
}

void MenuPrincipal::pacientes() {
    if (importe) {
        MenuPaciente miMenuPacientes;
        miMenuPacientes.importarArchivo();
        miMenuPacientes.menu();
    } else {
        gotoxy(3, 19);
        std::cout <<RB; std::cout << "Primero importa el archivo..."<<RTNC; pausa();
    }
}

void MenuPrincipal::diagnosticos() {
    if (importe) {
        MenuDiagnosticos miMenuDiagnosticos;
        miMenuDiagnosticos.importarArchivo();
        miMenuDiagnosticos.menu();
    } else {
        gotoxy(3, 19);
        std::cout <<RB; std::cout << "Primero importa el archivo..."<<RTNC; pausa();
    }
}

void MenuPrincipal::medicamentos() {
    if (importe) {
        MenuMedicamento miMenuMedicamento;
        miMenuMedicamento.importarArchivo();
        miMenuMedicamento.menu();
    } else {
        gotoxy(3, 19);
        std::cout <<RB; std::cout << "Primero importa el archivo..."<<RTNC; pausa();
    }
}

void MenuPrincipal::importarArchivo() {
    gotoxy(3, 19); std::cout << ARB << "Dame el nombre del archivo a importar:"<<RTNC;
    std::string nameImporte;
    fflush(stdin);
    std::cout<<AB; gotoxy(42, 19); std::getline(std::cin, nameImporte); std::cout<<RTNC;
    
    miFileMaster.importBackup(nameImporte);

    gotoxy(3, 21); std::cout << VB << "Archivo importado correctamente."<<RTNC; pausa();
    importe = true;
}

void MenuPrincipal::enConstruccion() {
    gotoxy(3, 19); std::cout << RB << "Esta opcion del programa esta en construccion..."<<RTNC; pausa();
}