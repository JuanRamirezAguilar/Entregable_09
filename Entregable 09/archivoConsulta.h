#ifndef ARCHIVOCONSULTA_H
#define ARCHIVOCONSULTA_H

#include <fstream>
#include <string>

#include "lista.h"

#include "Consulta.h"

#include "indexDuple.h"

#define NombreArchivo "archivoMedicamentos.txt"
#define archivoIndicePorNombre "archivoConsultasNombre.txt"

class ArchivoConsulta {
    private:
        std::fstream archivo;
        std::fstream indicePorNombre; // int, int

        Lista<indexDuple<int>> indexadoPorNombre;

        void reIndex();

        template <class T>
        Lista<indexDuple<T>> fileToList(std::fstream, Lista<indexDuple<T>>);

        template <class T>
        Lista<indexDuple<T>> listToFile(const Lista<indexDuple<T>>&, std::fstream&);

        template <class T>
        int getIndex(const Lista<T>&, const T&);

    public:
        ArchivoConsulta();
        ~ArchivoConsulta();
        void addData(const Consulta&);
        void addData(const Lista<Consulta>&);
        void delData(const int&);
        int findData(const Consulta&);
        void clear();

        void compress();
        Lista<Consulta> importBackup(std::string&); // Se uso esta funcion.
        void exportBackup(const std::string&);
};

#endif