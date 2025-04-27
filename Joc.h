#ifndef JOC_H
#define JOC_H
#include "Baralla.h"
#include "PilaCartes.h"
#include "Tauler.h"
#include <iostream>

using namespace std;

class Joc{
//Conté tots els elements del joc i permet saber en tot moment com l'estat en el que es troba el joc.
    public:
        Joc();
        //Pre: -; Post: demana al usuari una llavor per barrejar les cartes i prepara el tauler per a una partida nova

        void mostrar(bool mostrar_tot=false) const;
        //Pre: -; Post: mostra l'estat actual de la partida
        bool joc_acabat()const;
        //Pre: -; Post: retorna true si el joc ha acabat, es a dir, el cim de les piles dels pals té el valor K

        void obrir_carta();
        //Pre: -; Post: es mou la carta al cim de la ma a la pila de descartades i es mostra. Si la ma és buida, s'emplena amb la pila de descartades. Si ambdues piles són buides, no passa res
        void posar_carta_ma_tauler(int col);
        //Pre: -; Post: la carta al cim de la pila de descartades es mourà a la columna indicada només si és possible
        void posar_ma_pila();
        //Pre: -; Post: si hi ha alguna carta a la pila de descartades, es comprova la pila segons el pal a la que correspón i es mou si és possible
        void moure_cartes_tauler(int col, int fila, int desti_col);
        //Pre: -; Post: agafa una o més cartes visibles de la columna entrada com origen i, si és possible, es posen al final de la columna destí
        void moure_cartes_tauler_pila(int col);
        //Pre: -; Post: Si la columna entrada no és buida, es comprova la pila segons el pal a la que correspón i es mou si és possible
        void recuperar_carta_pila_tauler(int n, int col);
        //Pre: -; Post: agafa la carta de la pila indicada i comproba que es pugui moure a la columna entrada. La carta es mou si és possible

        PilaCartes& pila_corresponent(Carta c);
        //Pre: Carta de la baralla; Post: retorna la pila de cartes a la que pertany la carta segons el pal
        PilaCartes& escollir_pila(int n);
        //Pre: nombre enter; Post: retorna la pila de cartes a la que pertany el nombre introduit

        bool comprobar_descartades()const;
        //Pre: -; Post: retorna true si la pila és buida, retorna false altrament
        bool comprobar_pila(int n);
        //Pre: -; Post: retorna true si la pila indicada és buida, retorna false altrament
        bool comprobar_carta(int col, int fila)const;
        //Pre: -; Post: retorna true si la carta és visible, retorna false altrament

    private:
        PilaCartes a_piques;
        PilaCartes a_cors;
        PilaCartes a_diamants;
        PilaCartes a_trevols;
        PilaCartes a_ma;
        PilaCartes a_descartades;
        Tauler a_tauler;

        void mostrar_piles_pal()const;
        //Pre: -; Post: Mostra les piles segons el pal
        void mostrar_ma_descartades() const;
        //Pre: -; Post: Mostra la ma i la pila de descartades
};

#endif // JOC_H
