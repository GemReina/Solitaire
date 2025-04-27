#ifndef TAULER_H
#define TAULER_H
#include "Carta.h"
#include "Baralla.h"
#include <iostream>

using namespace std;

class Tauler{
//Matriu dinámica de dues dimensions que guarda la disposició de les diferents columnes i les cartes que té cada columna.
    public:
        Tauler();
        //Pre:--; Post: matriu buida (amb el nombre de files i columnes necessari pel nostre joc)
        Tauler(int nf, int nc);
        //Pre: nf>0 i nc>0; Post: objecte vàlid amb memòria reservada
        Tauler(const Tauler &t);
        //Pre:--; Post: informació de t copiada a l’actual
        ~Tauler();
        //Pre:-;- Post: allibera la memòria reservada per l’objecte
        Tauler &operator=(const Tauler &t);
        // Pre: --; Post: s’ha assignat sense aliasing la informació de t a l’objecte actual

        void afegirCarta(int i, int j, const Carta &c);
        //Pre: --; Post: Coloca la carta a la posició corresponent
        void retirarCarta(int i, int j);
        //Pre: posició i,j; Post: retira la carta de la posició entrada del tauler i si hi ha alguna carta no visible a sobre la mostra
        Carta obtCarta(int i, int j) const;
        //Pre: --; Post: Retorna la carta de la posició corresponent
        int obtNF()const;
        //Pre: --; Post: retorna el nombre de files de la matriu
        int obtNC()const;
        //Pre: --; Post: retorna el nombre de columnes de la matriu
        void repartir(Baralla &b);
        //Pre: --; Post: Per cada columna: per cada fila agafa l’últim element de la baralla i el col·loca a la posició de la matriu corresponent.
        void mostrar(bool mostrar_tot=false)const;
        //Pre: --; Post: Mostra l'estat actual del tauler

    private:
        int a_fila; //nombre de files
        int a_col; //nombre de columnes
        Carta** a_carta; //vector de punters

        void allibera();
        // Pre: --; Post: memòria alliberada
        void reserva();
        // Pre: a_fila>0 ^ a_col>0; Post: memòria reservada
        void copia(const Tauler &t);
        // Pre: --; Post: fa un duplicat de la matriu

};
#endif // TAULER_H
