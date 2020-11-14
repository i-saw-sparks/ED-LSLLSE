#include <iostream>
#include "List.h"
#include "Menu.h"
#include "Cancion.h"

int main(){
    List<Cancion> songs;

    bool running = true;

    do{
        switch(Menu::printMenu(songs)){
            case 'Z':
                Menu::scanCancion(songs);
                break;
            case 'X':
                Menu::deleteCancion(songs);
                break;
            case 'S':
                Menu::buscarCancion(songs);
                break;
            case 'P':
                Menu::ordenarLista(songs);
                break;
            case 'F':
                running = false;
                break;
        }

    }while(running);
}