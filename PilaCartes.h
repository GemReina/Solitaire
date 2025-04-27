#ifndef PILACARTES_H
#define PILACARTES_H
#include "Carta.h"
#include <iostream>

using namespace std;

class PilaCartes{
//Pila dinámica que guarda una pila de cartes. S'utilitza per construir les piles dels pals, la pila de descartades i la mà de joc.
    public:
        PilaCartes();
        // Pre: -; Post: pila buida
        PilaCartes(const PilaCartes& o);
        // Pre: -; Post: aquesta pila és còpia de la pila o
        ~PilaCartes();
        // Pre: -; Post: memòria alliberada
        PilaCartes& operator=(const PilaCartes& o);
        // Pre: -; Post: aquesta pila és còpia de la pila o i la seva memòria dinàmica ha estat prèviament alliberada

        bool buida() const;
        // Pre: - ; Post: retorna cert si la pila és buida; fals en cas contrari
        Carta cim() const;
        // Pre: -; Post: retorna la carta al cim de la pila
        void empila(Carta c);
        // Pre: -; Post: ha afegit c a dalt de la pila
        void desempila();
        // Pre: pila no buida; Post: ha eliminat element de dalt de la pila

    private:
        struct Node{
            Carta carta;
            Node* seg;
        };
        Node* a_cim;

        void copia(const PilaCartes& o);
        // Pre: pila buida; Post: aquesta pila és còpia de la pila o
        void allibera();
        // Pre: -; Post: memòria dinàmica alliberada

};

#endif // PILACARTES_H
