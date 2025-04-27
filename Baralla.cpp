#include <stdlib.h>
#include "Baralla.h"

Baralla::Baralla(){
//Pre: --; Post: baralla buida amb memòria resevada per a_max=53 cartes
    a_n = 0;
    a_max = 53;
    reserva();
}

Baralla::Baralla(const Baralla &b){
//Pre: --; Post: aquesta baralla és còpia de la baralla b
    copia(b);
}

Baralla::~Baralla(){
//Pre: --; Post: memòria alliberada
    allibera();
}

Baralla &Baralla::operator=(const Baralla &b){
//Pre: --; Post: aquesta baralla és còpia de la baralla b
    if (this != &b){
        allibera();
        copia(b);
    }
    return *this;
}

void Baralla::afegir(const Carta&c){
//Pre: --; Post: c afegit a la carta
    if (a_n == a_max) expandeix();
    a_c[a_n] = c;
    a_n++;
}

void Baralla::emplena(){
//Pre: --; Post: es va expandint la baralla amb les 13 cartes de cada pal.
    for(int i=1; i<=4; i++){
        for(int j=1; j<=13; j++){;
            afegir(Carta(Pal[i-1],Valor[j-1]));
        }
    }
}

void Baralla::barreja(int llavor){
//Pre: nombre enter; Post: la baralla es barreja en funcio del nombre entrat
    if(llavor<0) llavor=-llavor;
    for(int i=a_n-1;i>0;i--){
        int pos=aleatori(llavor, i+1);
        intercanvi(a_c[pos], a_c[i]);
    }
}

void Baralla::mostrar()const{
//Pre: --; Post: mostra el contingut de la baralla de cartes
    cout << "BARALLA" << endl;
    for(int i=0; i<=a_n-1;i++){
        cout << a_c[i];
        cout << " ";
    }
}

Carta Baralla::robar_carta(){
//Pre:--; Post: retorna l'última carta de la baralla i l'elimina de la baralla
    Carta c_robada(a_c[a_n-1]);
    a_n--;
    return c_robada;
}

int Baralla::n_cartes()const{
//Pre:--; Post: retorna a_n
    return a_n;
}

void Baralla::allibera(){
//Pre: --; Post: memòria alliberada
    delete[] a_c;
}

void Baralla::copia(const Baralla  &b){
//Pre: memòria alliberada; Post: aquesta baralla és còpia de la baralla b
    a_n = b.a_n;
    a_max = b.a_max;
    reserva();
    for(int i=0; i<a_n; i++) a_c[i] = b.a_c[i];
}

void Baralla::reserva(){
//Pre: --; Post: memòria reservada per a_max Cartes
    a_c = new Carta[a_max];
}

void Baralla::expandeix(){
//Pre: --; Post: la memòria reservada es dobla¡
    a_max += 13; // s’amplia la capacitat;
    Carta *aux = a_c; // baralla a substituir;
    for(int i=0; i<a_n; i++){// es copien les caselles
        a_c[i] = aux[i];
        delete[] aux; //s’allibera la vella
    }
}

int Baralla::aleatori(int &llavor, int n_cartes){
//Pre: -; Pro: genera un numero aleatori a partir d'una llavor
    unsigned valor_x = a*llavor+c;
    llavor = valor_x;
    return ((valor_x/32)%m)%n_cartes;
}

void Baralla::intercanvi(Carta &a, Carta &b){
//Pre: -; Post: s'intercanvia la informació entre les dues cartes seleccionades
    Carta c=a;
    a=b;
    b=c;
}
