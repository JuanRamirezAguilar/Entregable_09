#include "menuConsultas.h"

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
const std::string Subtitulo = "Menu de Consultas";

MenuConsultas::MenuConsultas() : opc("x"), existeImporte(false) {}
MenuConsultas::~MenuConsultas() {}

void MenuConsultas::setOpc(std::string valorOpc) { opc = valorOpc; }
void MenuConsultas::setExisteImporte(bool valorBool) { existeImporte = valorBool; }
void MenuConsultas::setLista(Lista<Consulta> list) { consultas = list; }

std::string MenuConsultas::getOpc() { return opc; }

bool MenuConsultas::getExisteImporte() { return existeImporte; }
Lista<Consulta> MenuConsultas::getConsultas() { return consultas; }


void MenuConsultas::menu() {
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
        std::cout <<GB; std::cout << "Buscar una consulta por indice. [ " <<RF<< "A" <<GB " ]";
        gotoxy(3, 10);
        std::cout <<GB; std::cout << "Imprimir todos los datos.       [ " <<RF<< "B" <<GB " ]";
        gotoxy(3, 11);
        std::cout <<GB; std::cout << "Importar archivo.               [ " <<RF<< "C" <<GB " ]";
        gotoxy(3, 12);
        std::cout <<GB; std::cout << "Salir del programa.             [ " <<RF<< "X" <<GB " ]";

        gotoxy(3, 14);
        std::cout <<GB << "Tu opcion ==> ";
        gotoxy(18, 14);
        std::cout <<RF; std::getline(std::cin, opciones); setOpc(opciones); std::cout <<RTNC;

        if (opc == "A" or opc == "a") { buscarRegistro(); } 
        else if (opc == "B" or opc == "b") { imprimirTodo(); } 
        else if (opc == "C" or opc == "c") { importar(); } 
        else if (opc == "X" or opc == "x") { return; } 
        else { gotoxy(3, 16); std::cout <<GB; std::cout << "La opcion: \"" <<RB<< opc <<GB<< "\" no es una opcion valida..."<<RTNC; pausa(); }

    } while (opc != "X" and opc != "x");
}

void MenuConsultas::buscarRegistro() {
    if (!existeImporte) {
        gotoxy(3, 16);
        std::cout <<RB; std::cout << "Primero importa un archivo..."<<RTNC; pausa();
    } else {

        const std::string subtiImport = "Consulta por indice";
        int indice = -1;

        while (indice < 0 or indice >= consultas.length()) {
            system(CLEAR);
            std::cout<<ARB; setborder(ALTURA_BORDE, ANCHURA_BORDE); std::cout<<RTNC;

            gotoxy(((ANCHURA_BORDE - int(Titulo.length())) / 2), 3);
            std::cout << VB << Titulo <<RTNC;
            gotoxy(((ANCHURA_BORDE - int(Subtitulo.length())) / 2), 4);
            std::cout << ARB << Subtitulo <<RTNC;
            gotoxy(((ANCHURA_BORDE - int(subtiImport.length())) / 2), 5);
            std::cout << AB << subtiImport <<RTNC;

            gotoxy(3, 7);
            std::cout <<GB; std::cout << "Dame el indice del registro que quiereas ver."<<RTNC;
            gotoxy(3, 8);
            std::cout <<GB; std::cout << "Indice del registro ==>  "; std::cout<<RTNC;
            gotoxy(29, 8);
            std::cout <<RF; std::cin >> indice; std::cout <<RTNC;

            if (indice < 0 or indice >= consultas.length()) {
                gotoxy(3, 10);
                std::cout <<RB; std::cout << "Indice fuera de Rango..."<<RTNC; pausa();
            } else {
                gotoxy(3, 10);
                std::cout <<GB; std::cout << "Registro Encontrado."<<RTNC;
                gotoxy(3, 11);
                std::cout <<VB<< indice << ")._ " <<RTNC<<std::endl;
                gotoxy(3, 12);
                std::cout <<AF<< "Nombre Paciente: " << GB << consultas.indice(indice).getPaciente().getNombre().toString() <<RTNC<<std::endl;
                gotoxy(3, 13);
                std::cout <<ARF<< "Nombre del Medico: " << GB << consultas.indice(indice).getMedico().getNombre().toString() <<RTNC<<std::endl<<std::endl;
                gotoxy(3, 14);
                std::cout <<GB<< std::endl << "Presiona Enter para continuar..."; std::cout<<RTNC; pausa();
            }
        }
    }
}

void MenuConsultas::importar() {
    std::string fileName;
    const std::string subtiImport = "Importar archivo";

    do {
        system(CLEAR);
        std::cout<<ARB; setborder(ALTURA_BORDE, ANCHURA_BORDE); std::cout<<RTNC;

        gotoxy(((ANCHURA_BORDE - int(Titulo.length())) / 2), 3);
        std::cout << VB << Titulo <<RTNC;
        gotoxy(((ANCHURA_BORDE - int(Subtitulo.length())) / 2), 4);
        std::cout << ARB << Subtitulo <<RTNC;
        gotoxy(((ANCHURA_BORDE - int(subtiImport.length())) / 2), 5);
        std::cout << AB << subtiImport <<RTNC;

        gotoxy(3, 7);
        std::cout <<GB; std::cout << "Dame el nombre del archivo a importar (o si quieres salir ingresa \"X\").";
        gotoxy(3, 8);
        std::cout <<GB; std::cout << "Nombre del Archivo ==>  "; std::cout<<RTNC;
        gotoxy(28, 8);
        std::cout <<RF; std::getline(std::cin, fileName); std::cout <<RTNC;

        if (fileName != "X" and fileName != "x") {
            gotoxy(3, 9);
            std::cout <<VB; std::cout << "Leyendo el archivo..."; std::cout<<RTNC;
            consultas = archivo.importBackup(fileName); // Pasa el respaldo a la consulta.
            gotoxy(3, 10);
            std::cout <<VB; std::cout << "Archivo leido..."; std::cout<<RTNC;
            gotoxy(3, 11);
            std::cout <<GB; std::cout << "Presiona Enter para continuar..."; std::cout<<RTNC; pausa();
            existeImporte = true;
            fileName = "X";
        }
    } while (fileName != "X" and fileName != "x");
}

void MenuConsultas::imprimirTodo() {
    if (!existeImporte) {
        gotoxy(3, 16);
        std::cout <<RB; std::cout << "Primero importa un archivo..."<<RTNC; pausa();
    } else {

        const std::string subtiImport = "Imprimir todo";

        system(CLEAR);
        std::cout<<ARB; setborder(ALTURA_BORDE, ANCHURA_BORDE); std::cout<<RTNC;

        gotoxy(((ANCHURA_BORDE - int(Titulo.length())) / 2), 3);
        std::cout << VB << Titulo <<RTNC;
        gotoxy(((ANCHURA_BORDE - int(Subtitulo.length())) / 2), 4);
        std::cout << ARB << Subtitulo <<RTNC;
        gotoxy(((ANCHURA_BORDE - int(subtiImport.length())) / 2), 5);
        std::cout << AB << subtiImport <<RTNC;

        gotoxy(3, 7);
        std::cout <<GB; std::cout << "Se imprimiran todos los datos del programa."<<RTNC;  pausa();

        system(CLEAR);
        for (int i = 0; i < consultas.length(); i++) {
            std::cout <<VB<< i + 1 << ")._ " <<RTNC<<std::endl;
            std::cout <<AF<< "Nombre Paciente: " << GB << consultas.indice(i).getPaciente().getNombre().toString() <<RTNC<<std::endl;
            std::cout <<ARF<< "Nombre del Medico: " << GB << consultas.indice(i).getMedico().getNombre().toString() <<RTNC<<std::endl<<std::endl;
        }
        std::cout <<GB<< std::endl << "Presiona Enter para continuar..."; std::cout<<RTNC; pausa();
    }
}