#include "MenuMedicamento.h"

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
const std::string Subtitulo = "Menu de Medicamentos";

MenuMedicamento::MenuMedicamento() {}

MenuMedicamento::~MenuMedicamento() {}

void MenuMedicamento::setOpc(std::string valorOpc) { opc = valorOpc; }

std::string MenuMedicamento::getOpc() { return opc; }

void MenuMedicamento::menu() {
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
        std::cout <<GB; std::cout << "Agregar un Medicamento.        [ " <<RF<< "A" <<GB " ]";
        gotoxy(3, 10);
        std::cout <<GB; std::cout << "Elimnar un Medicamento.        [ " <<RF<< "B" <<GB " ]";
        gotoxy(3, 11);
        std::cout <<GB; std::cout << "Buscar un Medicamento.         [ " <<RF<< "C" <<GB " ]";
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

void MenuMedicamento::agregar() {
    Medicamento nuevoMedicamento;
    std::string auxString;

    const std::string subtiImport = "Agregar un Medicamento";

    system(CLEAR);
    std::cout<<ARB; setborder(ALTURA_BORDE, ANCHURA_BORDE); std::cout<<RTNC;

    gotoxy(((ANCHURA_BORDE - int(Titulo.length())) / 2), 3);
    std::cout << VB << Titulo <<RTNC;
    gotoxy(((ANCHURA_BORDE - int(Subtitulo.length())) / 2), 4);
    std::cout << ARB << Subtitulo <<RTNC;
    gotoxy(((ANCHURA_BORDE - int(subtiImport.length())) / 2), 5);
    std::cout << AB << subtiImport <<RTNC;

    gotoxy(3, 7);
    std::cout << GF << "Ingresar un Medicamento nuevo al archivo." <<RTNC;

    gotoxy(3, 9);
    std::cout << GF << "Dame el codigo del medicamento:" <<RTNC;
    gotoxy(35, 9);
    fflush(stdin);
    std::getline(cin, auxString);
    nuevoMedicamento.setCodigo(auxString);

    gotoxy(3, 11);
    std::cout << GF << "Dame el nombre del medicamento:" <<RTNC;
    fflush(stdin);
    gotoxy(35, 11);
    std::getline(cin, auxString);
    nuevoMedicamento.setNombre(auxString);

    miArchivoMedicamento.addData(nuevoMedicamento);

    gotoxy(3, 13);
    std::cout << VB << "Medicamento Registrado en el archivo..." <<RTNC; pausa();
}

void MenuMedicamento::eliminar() {
    std::string auxCodigo;

    system(CLEAR);
    const std::string subtiImport = "Eliminar un Medicamento";
    std::cout<<ARB; setborder(ALTURA_BORDE, ANCHURA_BORDE); std::cout<<RTNC;

    gotoxy(((ANCHURA_BORDE - int(Titulo.length())) / 2), 3);
    std::cout << VB << Titulo <<RTNC;
    gotoxy(((ANCHURA_BORDE - int(Subtitulo.length())) / 2), 4);
    std::cout << ARB << Subtitulo <<RTNC;
    gotoxy(((ANCHURA_BORDE - int(subtiImport.length())) / 2), 5);
    std::cout << AB << subtiImport <<RTNC;

    gotoxy(3, 7);
    std::cout <<GF<< "Ingresa el codigo del medicamento a buscar:";
    gotoxy(47, 7);
    fflush(stdin);
    getline(std::cin, auxCodigo);

    int idx = miArchivoMedicamento.findData(auxCodigo);

    if (idx != -1) {
        string opcBorrar;
        Medicamento showMedicamento = miArchivoMedicamento.getData(idx);

        gotoxy(3, 11);
        std::cout << "Medicamento: " << std::endl;
        gotoxy(3, 12);
        std::cout << AF << showMedicamento.toString();

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
            miArchivoMedicamento.delData(idx);
            miArchivoMedicamento.compress();
            gotoxy(3, 20);
            std::cout <<VB<< "Medicamento eliminado correctamente."<<RTNC; pausa();
        } else if(opcBorrar == "N" or opcBorrar == "n" or opcBorrar != "Y" or opcBorrar != "y") {
            gotoxy(3, 20);
            std::cout << RB << "Opcion invalida o elegiste \"N\", Saliendo de eliminar medicamento..." <<RTNC; timeStop(1000);
        } 
    } else {
        gotoxy(3, 11);
        std::cout <<RB<< "No se encontró un medicamento con ese codigo."<<RTNC; pausa();
    }

}

void MenuMedicamento::buscar() {
    system(CLEAR);
    const std::string subtiImport = "Buscar un Medicamento";
    std::cout<<ARB; setborder(ALTURA_BORDE, ANCHURA_BORDE); std::cout<<RTNC;
    gotoxy(((ANCHURA_BORDE - int(Titulo.length())) / 2), 3);
    std::cout << VB << Titulo <<RTNC;
    gotoxy(((ANCHURA_BORDE - int(Subtitulo.length())) / 2), 4);
    std::cout << ARB << Subtitulo <<RTNC;
    gotoxy(((ANCHURA_BORDE - int(subtiImport.length())) / 2), 5);
    std::cout << AB << subtiImport <<RTNC;

    std::string auxCodigo;

    gotoxy(3, 7);
    std::cout <<GF<< "Ingresa el codigo del medicamento:";
    gotoxy(38, 7);
    fflush(stdin);
    getline(std::cin, auxCodigo);

    int idx = miArchivoMedicamento.findData(auxCodigo);
        
    if (idx != -1) {
        Medicamento MedicamentoAux = miArchivoMedicamento.getData(idx);

        // Imprime el Codigo del Medicamento
        gotoxy(3, 11);
        std::cout << ARB << "Codigo del medicamento:";
        gotoxy(27, 11);
        std::cout << VF << MedicamentoAux.getCodigo();

        // Imprime el Nombre del Medicamento
        gotoxy(3, 12);
        std::cout << ARB << "Nombre del Medicamento:";
        gotoxy(27, 12);
        std::cout << VF << MedicamentoAux.getNombre();
        pausa();

    } else {
        gotoxy(3, 11);
        std::cout <<RB<< "No se encontro un medicamento con ese codigo."<<RTNC; pausa();
    }
}

void MenuMedicamento::importarArchivo() {
    miArchivoMedicamento.importBackup();
}