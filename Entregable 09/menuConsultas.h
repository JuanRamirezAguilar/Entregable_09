#ifndef MENUCONSULTAS_H
#define MENUCONSULTAS_H

#include "Consulta.h"
#include "archivoConsulta.h"
#include "lista.h"

#include <string>

class MenuConsultas {
    private:
        std::string opc;
        bool existeImporte;
        Lista<Consulta> consultas;
        ArchivoConsulta archivo;


    public:

        MenuConsultas();
        ~MenuConsultas();
        
        void setOpc(std::string valorOpc);
        void setExisteImporte(bool valorBool);
        void setLista(Lista<Consulta> list);

        std::string getOpc();
        bool getExisteImporte();
        Lista<Consulta> getConsultas();

        void menu();
        void buscarRegistro();
        void importar();
        void imprimirTodo();

};

#endif