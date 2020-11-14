//
// Created by manie on 02/10/2020.
//

#ifndef LISTA_ESTATICA_MENU_H
#define LISTA_ESTATICA_MENU_H

#include "List.h"
#include "Cancion.h"
#include <iostream>
#include <iomanip>


class Menu {
public:
    Menu();
    static void header();
    static void list(const List<Cancion>&);
    static char options();
    static void scanCancion(List<Cancion>&);
    static int deleteCancion(List<Cancion>&);
    static int buscarCancion(List<Cancion>&);
    static int printMenu(const List<Cancion> &);
    static void ordenarLista(List<Cancion>&);
};


#endif //LISTA_ESTATICA_MENU_H