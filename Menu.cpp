//
// Created by manie on 02/10/2020.
//

#include "Menu.h"

void Menu::header()  {
    std::cout<<"top 50 canciones mas escuchadas"<<std::endl;
    std::cout<<"-------------------------------------------"<<std::endl;
}

Menu::Menu() {

}

void Menu::list(const List<Cancion> &list){
    std::cout<<"\033[1;32m";
    for (int i = 0; i < list.getSize(); ++i) {
        std::cout<<list.fetch(i)<<std::endl;
    }
    std::cout<<"\033[0m"<<"-------------------------------------------"<<std::endl;
}

char Menu::options(){
    char ret;
    std::cout<<"Z - Incluir nueva cancion  X - Eliminar una cancion  S - Buscar una cancion  P - Ordenar la lista  F-Salir"<<std::endl;
    std::cin>>ret;
    return ret;
}

int Menu::printMenu(const List<Cancion> &list){
    Menu::header();
    Menu::list(list);
    return Menu::options();
}

void Menu::scanCancion(List<Cancion> &list) {
    Cancion temp;
    std::string strIn;
    int intIn;

    std::cout<<"Ingrese el nombre de la cancion: ";
    std::getline(std::cin >> std::ws, strIn);
    temp.setNombre(strIn);
    std::cout<<"Ingrese el nombre del autor: ";
    std::getline(std::cin >> std::ws, strIn);
    temp.setAutor(strIn);
    std::cout<<"Ingrese el nombre del interprete: ";
    std::getline(std::cin >> std::ws, strIn);
    temp.setInterprete(strIn);
    std::cout<<"Ingrese el nombre del archivo: ";
    std::getline(std::cin >> std::ws, strIn);
    temp.setArchivoId(strIn);
    std::cout<<"Ingrese la posicion en el ranking: ";
    std::cin>>intIn;
    temp.setPosicion(intIn);
    std::cout<<"Ingrese la posicion de la cancion en la lista: ";
    std::cin>>intIn;

    list.insert(temp, intIn);
}

int Menu::deleteCancion(List<Cancion> &list) {
    int intIn;
    std::cout<<"-------------------------------------------"<<std::endl;
    std::cout<<std::endl<<"Ingrese la posicion de la cancion en la lista: ";
    std::cin>>intIn;
    list.erase(intIn);
    return 0;
}

int Menu::buscarCancion(List<Cancion> &list) {
    std::string strIn;
    bool method = 0;
    Cancion canIn;
    int res, campoABuscar;
    std::cout<<"-------------------------------------------"<<std::endl
             <<"Como quiere ordenar la lista?"
             <<std::endl<<"0 - Por nombre de cancion"
             <<std::endl<<"1 - Por nombre de autor"
             <<std::endl<<"Opcion: ";
    std::cin>>campoABuscar;
    std::cout<<std::endl<<"Que metodo desea usar (1 - Linear, 0 - Binaria): ";
    std::cin>>method;

    if(campoABuscar){
        std::cout<<std::endl<<"Ingrese el autor de la cancion que desea buscar: ";
        std::getline(std::cin >> std::ws, strIn);
        canIn.setAutor(strIn);
        if(method)
            res = list.linearSearch(canIn, Cancion::compareByAutor);
        else
            res = list.binarySearch(canIn, Cancion::compareByAutor);
    }else{
        std::cout<<std::endl<<"Ingrese el nombre de la cancion que desea buscar: ";
        std::getline(std::cin >> std::ws, strIn);
        canIn.setNombre(strIn);
        if(method)
            res = list.linearSearch(canIn, Cancion::compareByNombre);
        else
            res = list.binarySearch(canIn, Cancion::compareByNombre);
    }

    std::cout<<"-------------------------------------------"<<std::endl;

    if(res!=-1) {
        std::cout << "\033[1;34m";
        std::cout << std::endl << list.fetch(res).toString() << std::endl;
        std::cout << "\033[0m";
    }
    else
        std::cout<<std::endl<<"Cancion no encontrada"<<std::endl;

    return 0;
}

void Menu::ordenarLista(List<Cancion> &canciones) {
    uint16_t metodoOrd;
    bool campoAOrdenar;

    std::cout<<"-------------------------------------------"<<std::endl;
    std::cout<<std::endl<<"Que metodo desea usar?"
             <<std::endl<<"0 - Burbuja (mejorada)"
             <<std::endl<<"1 - Shell"
             <<std::endl<<"2 - Insercion"
             <<std::endl<<"3 - Seleccion"
             <<std::endl<<"Opcion: ";
    std::cin>>metodoOrd;

    std::cout<<"-------------------------------------------"<<std::endl
             <<"Como quiere ordenar la lista?"
             <<std::endl<<"0 - Por nombre de cancion"
             <<std::endl<<"1 - Por nombre de autor"
             <<std::endl<<"Opcion: ";
    std::cin>>campoAOrdenar;

    switch(metodoOrd){
        case 0:
            if(campoAOrdenar)
                canciones.sortByEnhancedBubble(&Cancion::compareByAutor);
            else
                canciones.sortByEnhancedBubble(&Cancion::compareByNombre);
            break;
        case 1:
            if(campoAOrdenar)
                canciones.sortByShell(&Cancion::compareByAutor);
            else
                canciones.sortByShell(&Cancion::compareByNombre);
            break;

        case 2:
            if(campoAOrdenar)
                canciones.sortByInsert(&Cancion::compareByAutor);
            else
                canciones.sortByInsert(&Cancion::compareByNombre);
            break;

        case 3:
            if(campoAOrdenar)
                canciones.sortBySelect(&Cancion::compareByAutor);
            else
                canciones.sortBySelect(&Cancion::compareByNombre);
            break;
    }
}
