#include "Carta.h"

Carta::Carta(){
//Pre: -; Post: crea una carta per defecte
    a_pal = '0';
    a_valor = 0;
    a_visible = false;
}

Carta::Carta(char pal, int valor, bool visible){
//Pre: -; Post: crea una carta amb els valors entrats
    a_pal = pal;
    a_valor = valor;
    a_visible = visible;
}

Carta::Carta(const Carta &c){
//Pre: -; Post: crea una copia de la carta entrada com a paràmetre
    a_pal = c.a_pal;
    a_valor = c.a_valor;
    a_visible = c.a_visible;
}

int Carta::valor()const{
//Pre: -; Post: permet l'accès al atribut privat desde fora de la classe
    return a_valor;
}

char Carta::pal()const{
//Pre: -; Post: permet l'accès al atribut privat desde fora de la classe
    return a_pal;
}

bool Carta::visible()const{
//Pre: -; Post: permet l'accès al atribut privat desde fora de la classe
    return a_visible;
}

ostream &operator<<(ostream &o, const Carta &c){
//Pre: canal o i carta c; Post: escriu la carta c al canal o
    if(c.a_visible){
        if(c.a_valor==1) o << "A";
        else if(c.a_valor==10) o << "D";
        else if(c.a_valor==11) o << "J";
        else if(c.a_valor==12) o << "Q";
        else if(c.a_valor==13) o << "K";
        else o << c.a_valor;
        o << c.a_pal;
    } else o << "**";
    return o;
}

void Carta::canvia_visibilitat(){
//Pre: -; Post: canvía l'atribut booleà al valor contrari al que tè
    a_visible=!a_visible;
}

bool Carta::mateix_color(const Carta &c)const{
//Pre: Carta c; Post: retorna true si ambdues cartes tenen el mateix color de pal, retorna false altrament
    return ((a_pal=='P' or a_pal=='T') and (c.pal()=='P' or c.pal()=='T')) or ((a_pal=='c' or a_pal=='d') and (c.pal()=='c' or c.pal()=='d'));
}

bool Carta::apta_tauler(const Carta &c)const{
//Pre: Carta c; Post: retorna true si la carta entrada es pot colocar sobre la carta *this en el tauler, retorna false altrament
    return !mateix_color(c) && c.valor()==a_valor-1;
}
