#ifndef CARTA_H
#define CARTA_H
#include <iostream>

using namespace std;

const int A = 1;
const int D = 10;
const int J = 11;
const int Q = 12;
const int K = 13;

class Carta{
//Objecte carta que pot estar a la mà, a la pila de descartades, al tauler o les piles dels pals.
    public:
        Carta();
        //Pre: -; Post: crea una carta per defecte
        Carta(char p, int v, bool visible = false);
        //Pre: -; Post: crea una carta amb els valors entrats
        Carta(const Carta &c);
        //Pre: -; Post: crea una copia de la carta entrada com a paràmetre
        int valor()const;
        //Pre: -; Post: permet l'accès al atribut privat desde fora de la classe
        char pal()const;
        //Pre: -; Post: permet l'accès al atribut privat desde fora de la classe
        bool visible()const;
        //Pre: -; Post: permet l'accès al atribut privat desde fora de la classe

        friend ostream &operator<<(ostream &o, const Carta &c);
        //Pre: canal o i carta c; Post: escriu la carta c al canal o

        void canvia_visibilitat();
        //Pre: -; Post: canvía l'atribut booleà al valor contrari al que tè
        bool mateix_color(const Carta &c)const;
        //Pre: Carta c; Post: retorna true si ambdues cartes tenen el mateix color de pal, retorna false altrament
        bool apta_tauler(const Carta &c)const;
        //Pre: Carta c; Post: retorna true si la carta entrada es pot colocar sobre la carta *this en el tauler, retorna false altrament

    private:
        char a_pal; //Pal
        int a_valor; //Valor
        bool a_visible; //Cert si és visible, fals altrament
};

#endif // CARTA_H
