#ifndef BARALLA_H
#define BARALLA_H
#include "Carta.h"
#include <iostream>

using namespace std;

const int MAX_cartes = 52;
const unsigned a = 1103515245;
const unsigned c = 12345;
const unsigned m = 32768;

class Baralla{
//Taula baralla que conté una baralla francesa de 52 cartes. S’utilitza per barrejar les cartes, repartir les que han d’anar al tauler i generar la mà inicial.
    public:
        Baralla();
        //Pre: --; Post: baralla buida amb memòria resevada per a_max=53 cartes
        Baralla(const Baralla &b);
        //Pre: --; Post: aquesta baralla és còpia de la baralla b
        ~Baralla();
        //Pre: --; Post: memòria alliberada
        Baralla &operator=(const Baralla &b);
        //Pre: --; Post: aquesta baralla és còpia de la baralla b

        void afegir(const Carta &c);
        //Pre: --; Post: p afegit a la taula
        void emplena();
        //Pre: --; Post: es va expandint la baralla amb les 13 cartes de cada pal
        void barreja(int llavor);
        //Pre: nombre enter; Post: la baralla es barreja en funcio del nombre entrat
        void mostrar()const;
        //Pre: --; Post: mostra el contingut de la baralla de cartes
        Carta robar_carta();
        //Pre:--; Post: retorna l'última carta de la baralla i l'elimina de la baralla
        int n_cartes() const;
        //Pre:--; Post: retorna a_n


    private:
        int a_n; // nombre de caselles ocupades
        int a_max; // nombre de posicions reservades (capacitat)
        Carta *a_c; //array dinàmic de cartes

        char Pal[4]={'P', 'c', 'd', 'T'};
        int Valor[13]={A, 2, 3, 4, 5, 6 , 7, 8, 9, D, J, Q, K};

        void allibera();
        //Pre: --; Post: memòria alliberada
        void copia(const Baralla &b);
        //Pre: memòria alliberada; Post: aquesta baralla és còpia de la baralla b
        void reserva();
        //Pre: --; Post: memòria reservada per a_max Cartes
        void expandeix();
        //Pre: --; Post: la memòria reservada es dobla
        int aleatori(int &llavor, int n_cartes);
        //Pre: --; Post; genera un numero aleatori a partir d'una llavor
        void intercanvi(Carta &a, Carta &b);
        //Pre: -; Post: s'intercanvia la informació entre les dues cartes seleccionades

};

#endif // BARALLA_H
