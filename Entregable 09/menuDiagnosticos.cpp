#include "menuDiagnosticos.h"

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
const std::string Subtitulo = "Menu de Diagnosticos";

MenuDiagnosticos::MenuDiagnosticos() {}

MenuDiagnosticos::~MenuDiagnosticos() {}

void MenuDiagnosticos::setOpc(std::string valorOpc) { opc = valorOpc; }
std::string MenuDiagnosticos::getOpc() { return opc; }

void MenuDiagnosticos::menu() {
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
        std::cout <<GB; std::cout << "Agregar un Diagnostico.        [ " <<RF<< "A" <<GB " ]";
        gotoxy(3, 10);
        std::cout <<GB; std::cout << "Elimnar un Diagnostico.        [ " <<RF<< "B" <<GB " ]";
        gotoxy(3, 11);
        std::cout <<GB; std::cout << "Buscar un Diagnostico.         [ " <<RF<< "C" <<GB " ]";
        gotoxy(3, 12);
        std::cout <<GB; std::cout << "Regresar al menu anterior.     [ " <<RF<< "X" <<GB " ]";

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

void MenuDiagnosticos::agregar() {
    Diagnostico nuevoDiagnostico;
    std::string auxString;

    const std::string subtiImport = "Agregar un Diagnostico";

    system(CLEAR);
    std::cout<<ARB; setborder(ALTURA_BORDE, ANCHURA_BORDE); std::cout<<RTNC;

    gotoxy(((ANCHURA_BORDE - int(Titulo.length())) / 2), 3);
    std::cout << VB << Titulo <<RTNC;
    gotoxy(((ANCHURA_BORDE - int(Subtitulo.length())) / 2), 4);
    std::cout << ARB << Subtitulo <<RTNC;
    gotoxy(((ANCHURA_BORDE - int(subtiImport.length())) / 2), 5);
    std::cout << AB << subtiImport <<RTNC;

    gotoxy(3, 7);
    std::cout << GF << "Ingresar un Diagnostico nuevo al archivo." <<RTNC;

    bool codigoValido = false;
    while (!codigoValido) {
        gotoxy(3, 9);
        std::cout << GF << "Dame el codigo del diagnostico:" <<RTNC;
        gotoxy(35, 9);
        fflush(stdin);
        std::getline(cin, auxString);

        if (miArchivoDiagnostico.findData(auxString) != -1) {
            gotoxy(3, 11);
            std::cout << RB << "El codigo introducido no es valida intentalo de nuevo" <<RTNC; pausa();

            // Este bucle borra los escrito en la pantalla
            for (int x = 3; x < 100; x++) {
                for (int y = 9; y < 12; y++) {
                    gotoxy(x, y); std::cout << " ";
                }
            }
        } else {
            codigoValido = true;
            nuevoDiagnostico.setCodigo(auxString);
        }
    }

    gotoxy(3, 13);
    std::cout << GF << "Dame la descripcion del diagnostico:" <<RTNC;
    fflush(stdin);
    gotoxy(40, 13);
    std::getline(cin, auxString);
    nuevoDiagnostico.setDescripcion(auxString);

    gotoxy(3, 15);
    std::cout << GF << "Dame la indicacion del diagnostico:" <<RTNC;
    fflush(stdin);
    gotoxy(39, 15);
    std::getline(cin, auxString);
    nuevoDiagnostico.setIndicacion(auxString);

    miArchivoDiagnostico.addData(nuevoDiagnostico);

    gotoxy(3, 17);
    std::cout << VB << "Diagnostico Registrado en el archivo..." <<RTNC; pausa();
}

void MenuDiagnosticos::eliminar() {
    std::string auxCodigo;

    system(CLEAR);
    const std::string subtiImport = "Eliminar un Diagnostico";
    std::cout<<ARB; setborder(ALTURA_BORDE, ANCHURA_BORDE); std::cout<<RTNC;

    gotoxy(((ANCHURA_BORDE - int(Titulo.length())) / 2), 3);
    std::cout << VB << Titulo <<RTNC;
    gotoxy(((ANCHURA_BORDE - int(Subtitulo.length())) / 2), 4);
    std::cout << ARB << Subtitulo <<RTNC;
    gotoxy(((ANCHURA_BORDE - int(subtiImport.length())) / 2), 5);
    std::cout << AB << subtiImport <<RTNC;

    gotoxy(3, 7);
    std::cout <<GF<< "Ingresa el codigo del diagnostico a eliminar:";
    gotoxy(49, 7);
    fflush(stdin);
    getline(std::cin, auxCodigo);

    int idx = miArchivoDiagnostico.findData(auxCodigo);

    if (idx != -1) {
        string opcBorrar;
        Diagnostico showDiagnostico = miArchivoDiagnostico.getData(idx);

        gotoxy(3, 11);
        std::cout << "Medicamento: " << std::endl;
        gotoxy(3, 12);
        std::cout << AF << showDiagnostico.toString();

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
            miArchivoDiagnostico.delData(idx);
            miArchivoDiagnostico.compress();
            gotoxy(3, 20);
            std::cout <<VB<< "Diagnostico eliminado correctamente."<<RTNC; pausa();
        } else if(opcBorrar == "N" or opcBorrar == "n" or opcBorrar != "Y" or opcBorrar != "y") {
            gotoxy(3, 20);
            std::cout << RB << "Opcion invalida o elegiste \"N\", Saliendo de eliminar diagnostico..." <<RTNC; timeStop(1000);
        } 
    } else {
        gotoxy(3, 11);
        std::cout <<RB<< "No se encontró un diagnostico con ese codigo."<<RTNC; pausa();
    }
}

void MenuDiagnosticos::buscar() {
    std::string opcBuscar;
    gotoxy(3, 16);
    std::cout << GB << "Buscar por Codigo.        [ " <<RF<< "A" <<GB " ]";
    gotoxy(3, 17);
    std::cout << GB << "Buscar por Descripcion.   [ " <<RF<< "B" <<GB " ]";
    gotoxy(3, 18);
    std::cout << GB << "Regresar al menu.         [ " <<RF<< "X" <<GB " ]";
    gotoxy(3, 19);
    std::cout <<GB << "Tu opcion ==> ";
    gotoxy(18, 19);
    fflush(stdin);
    std::cout <<RF; std::getline(std::cin, opcBuscar); setOpc(opcBuscar); std::cout <<RTNC;

    if (opcBuscar == "A" or opcBuscar == "a") {
        system(CLEAR);
        const std::string subtiImport = "Buscar un Diagnostico";
        std::cout<<ARB; setborder(ALTURA_BORDE, ANCHURA_BORDE); std::cout<<RTNC;

        gotoxy(((ANCHURA_BORDE - int(Titulo.length())) / 2), 3);
        std::cout << VB << Titulo <<RTNC;
        gotoxy(((ANCHURA_BORDE - int(Subtitulo.length())) / 2), 4);
        std::cout << ARB << Subtitulo <<RTNC;
        gotoxy(((ANCHURA_BORDE - int(subtiImport.length())) / 2), 5);
        std::cout << AB << subtiImport <<RTNC;

        std::string stringAux;

        gotoxy(3, 7);
        std::cout <<GF<< "Ingresa el codigo del diagnostico a buscar: ";
        gotoxy(48, 7);
        fflush(stdin);
        getline(std::cin, stringAux);

        int idx = miArchivoDiagnostico.findData(stringAux);
        
        if (idx != -1) {
            Diagnostico diagnosticoAux = miArchivoDiagnostico.getData(idx);

            // Imprime el codigo del Diagnostico
            gotoxy(3, 9);
            cout << ARB << "Codigo del Diagnostico:";
            gotoxy(27, 9);
            cout << VF << diagnosticoAux.getCodigo();

            // Imprime la descripcion del Diagnostico
            gotoxy(3, 10);
            cout << ARB << "Descripcion del Diagnostico:";
            gotoxy(32, 10);
            cout << VF << diagnosticoAux.getDescripcion();

            // Imprime la indicacion del Diagnostico
            gotoxy(3, 11);
            cout << ARB << "Indicacion del Diagnostico:";
            gotoxy(31, 11);
            cout << VF << diagnosticoAux.getIndicacion();
            pausa();

        } else {
            gotoxy(3, 9);
            std::cout <<RB<< "No se encontro un diagnostico con ese nombre."<<RTNC; pausa();
        }

    } else if (opcBuscar == "B" or opcBuscar == "b") {
        system(CLEAR);
        const std::string subtiImport = "Buscar un Diagnostico";
        std::cout<<ARB; setborder(ALTURA_BORDE, ANCHURA_BORDE); std::cout<<RTNC;

        gotoxy(((ANCHURA_BORDE - int(Titulo.length())) / 2), 3);
        std::cout << VB << Titulo <<RTNC;
        gotoxy(((ANCHURA_BORDE - int(Subtitulo.length())) / 2), 4);
        std::cout << ARB << Subtitulo <<RTNC;
        gotoxy(((ANCHURA_BORDE - int(subtiImport.length())) / 2), 5);
        std::cout << AB << subtiImport <<RTNC;

        std::string stringAux;

        gotoxy(3, 7);
        std::cout <<GF<< "Ingresa la descripcion del diagnostico a buscar: ";
        gotoxy(53, 7);
        fflush(stdin);
        getline(std::cin, stringAux);

        Diagnostico aux;
        aux.setDescripcion(stringAux);

        int idx = miArchivoDiagnostico.findData(aux);
        
        if (idx != -1) {
            Diagnostico diagnosticoAux = miArchivoDiagnostico.getData(idx);

            // Imprime el codigo del Diagnostico
            gotoxy(3, 9);
            cout << ARB << "Codigo del Diagnostico:";
            gotoxy(27, 9);
            cout << VF << diagnosticoAux.getCodigo();

            // Imprime la descripcion del Diagnostico
            gotoxy(3, 10);
            cout << ARB << "Descripcion del Diagnostico:";
            gotoxy(32, 10);
            cout << VF << diagnosticoAux.getDescripcion();

            // Imprime la indicacion del Diagnostico
            gotoxy(3, 11);
            cout << ARB << "Indicacion del Diagnostico:";
            gotoxy(31, 11);
            cout << VF << diagnosticoAux.getIndicacion();
            pausa();

        } else {
            gotoxy(3, 9);
            std::cout <<RB<< "No se encontro un diagnostico con ese nombre."<<RTNC; pausa();
        }
    } else if (opcBuscar == "X" or opcBuscar == "x") {
        return;
    } else {
        gotoxy(3, 21); std::cout <<GB; std::cout << "La opcion: \"" <<RB<< opcBuscar <<GB<< "\" no es una opcion valida..."<<RTNC; pausa();
    }
}

void MenuDiagnosticos::importarArchivo()
{ miArchivoDiagnostico.importBackup(); }