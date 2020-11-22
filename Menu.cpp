//
// Created by manie on 02/10/2020.
//

#include "Menu.h"

void Menu::header() {
    std::cout << "top 50 canciones mas escuchadas" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
}

Menu::Menu() {

}

void Menu::list(const List<Cancion> &list) {
    std::cout << "\033[1;32m";
    List<Cancion>::Position aux;
    aux = list.getFirstPos();

    while (aux != nullptr){
        std::cout<<list.fetch(aux)<<std::endl;
        aux = aux->getNext();
    }

    std::cout << "\033[0m" << "-------------------------------------------" << std::endl;
}

char Menu::options() {
    char ret;
    std::cout
            << "Z - Incluir nueva cancion  X - Eliminar una cancion  S - Buscar una cancion  F-Salir"
            << std::endl;
    std::cin >> ret;
    return ret;
}

int Menu::printMenu(const List<Cancion> &list) {
    Menu::header();
    Menu::list(list);
    return Menu::options();
}

void Menu::scanCancion(List<Cancion> &list) {
    Cancion temp;
    std::string strIn;
    int intIn;

    std::cout << "Ingrese el nombre de la cancion: ";
    std::getline(std::cin >> std::ws, strIn);
    temp.setNombre(strIn);
    std::cout << "Ingrese el nombre del autor: ";
    std::getline(std::cin >> std::ws, strIn);
    temp.setAutor(strIn);
    std::cout << "Ingrese el nombre del interprete: ";
    std::getline(std::cin >> std::ws, strIn);
    temp.setInterprete(strIn);
    std::cout << "Ingrese el nombre del archivo: ";
    std::getline(std::cin >> std::ws, strIn);
    temp.setArchivoId(strIn);
    std::cout << "Ingrese la posicion en el ranking: ";
    std::cin >> intIn;
    temp.setPosicion(intIn);

    list.insert(list.getLastPos(), temp);
}

int Menu::deleteCancion(List<Cancion> &list) {
    List<Cancion>::Position pos;
    int campoAEliminar;
    Cancion canIn;
    std::string strIn;

    std::cout << "-------------------------------------------" << std::endl
              << "Por que campo quieres eliminar la cancion en la lista?"
              << std::endl << "0 - Por nombre de cancion"
              << std::endl << "1 - Por nombre de autor"
              << std::endl << "Opcion: ";
    std::cin >> campoAEliminar;


    if (campoAEliminar) {
        std::cout << std::endl << "Ingrese el autor de la cancion que desea eliminar: ";
        std::getline(std::cin >> std::ws, strIn);
        canIn.setAutor(strIn);
        pos = list.find(canIn, Cancion::compareByAutor);
    } else {
        std::cout << std::endl << "Ingrese el nombre de la cancion que desea eliminar: ";
        std::getline(std::cin >> std::ws, strIn);
        canIn.setNombre(strIn);
        pos = list.find(canIn, Cancion::compareByNombre);
    }
    list.erase(pos);
    return 0;
}

int Menu::buscarCancion(List<Cancion> &list) {
    std::string strIn;
    bool method = 0;
    Cancion canIn;
    List<Cancion>::Position pos, res;
    int campoABuscar;

    std::cout << "-------------------------------------------" << std::endl
              << "Por que campo quieres buscar en la lista?"
              << std::endl << "0 - Por nombre de cancion"
              << std::endl << "1 - Por nombre de autor"
              << std::endl << "Opcion: ";
    std::cin >> campoABuscar;


    if (campoABuscar) {
        std::cout << std::endl << "Ingrese el autor de la cancion que desea buscar: ";
        std::getline(std::cin >> std::ws, strIn);
        canIn.setAutor(strIn);
        res = list.find(canIn, Cancion::compareByAutor);
    } else {
        std::cout << std::endl << "Ingrese el nombre de la cancion que desea buscar: ";
        std::getline(std::cin >> std::ws, strIn);
        canIn.setNombre(strIn);
        res = list.find(canIn, Cancion::compareByNombre);
    }

    std::cout << "-------------------------------------------" << std::endl;

    if (res != nullptr) {
        std::cout << "\033[1;34m";
        std::cout << std::endl << list.fetch(res).toString() << std::endl;
        std::cout << "\033[0m";
    } else
        std::cout << std::endl << "Cancion no encontrada" << std::endl;

    return 0;
}



