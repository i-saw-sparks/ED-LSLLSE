#include <iostream>
#include "StaticList.h"
#include "Menu.h"
#include "Cancion.h"

int main(){
    StaticList<Cancion, 4000> songs;

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