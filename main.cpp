/*
Metodologia i tecnologia de la programaci� II - Pr�ctica final: El Solitari
Programa realitzat per Gemma Reina Lara - u1987712
*/

#include <iostream>
#include <stdlib.h>
#include "Carta.h"
#include "Baralla.h"
#include "Tauler.h"
#include "Joc.h"

using namespace std;

void posar_ma_tauler(Joc &joc){
//Pre: -; Post: si hi ha alguna carta a la pila de descartades, es demana a l'usuari que indiqui la columna on la vol posar. La carta es mour� nom�s si �s possible
    if(joc.comprobar_descartades()) cout << "NO HI HA CAP CARTA PER AGAFAR" << endl;
    else{
        cout << "A QUINA COLUMNA LA VOLS POSAR:" << endl;
        int col;
        cin >> col;
        joc.posar_carta_ma_tauler(col);
    }
}

void moure_tauler(Joc &joc){
//Pre: -; Post: agafa una o m�s cartes obertes de la columna entrada com origen i, si �s possible, es posen al final de la columna dest�
    cout << "ENTRA LA COLUMNA ORIGEN I LA FILA ORIGEN:" << endl;
    int col, fila;
    cin >> col >> fila;
    if(!joc.comprobar_carta(col, fila)) cout << "LA CARTA NO ES POT MOURE" << endl;
    else{
        cout << "ENTRA LA COLUMNA DESTI:" << endl;
        int desti_col;
        cin >> desti_col;
        joc.moure_cartes_tauler(col, fila, desti_col);
    }
}

void moure_tauler_pila(Joc &joc){
//Pre: -; Post: s'entra una columna i, si no �s buida, es comprova la pila segons el pal a la que corresp�n i es mou si �s possible
    cout << "ENTRA LA COLUMNA ORIGEN:" << endl;
    int col;
    cin >> col;
    joc.moure_cartes_tauler_pila(col);
}

void recuperar_pila_tauler(Joc &joc){
//Pre: -; Post: demana la pila d'origen entre les piles de pal i si aquesta no �s buida, demana la columna on es vol moure. La carta es mou si �s possible
    cout << "ENTRA LA PILA:" << endl;
    int n;
    cin >> n;
    if(joc.comprobar_pila(n)) cout << "A LA PILA NO HI HA CAP CARTA PER RECUPERAR" << endl;
    else{
        cout << "A QUINA COLUMNA LA VOLS POSAR:" << endl;
        int col;
        cin >> col;
        joc.recuperar_carta_pila_tauler(n, col);
    }
}


void mostrar_menu(){
//Pre: -; Post: mostra el men� d'opcions
    cout << "MENU" << endl;
    cout << "1: OBRIR UNA CARTA (O TORNAR A COMENCAR)" << endl;
    cout << "2: POSAR UNA CARTA (MA->TAULER)" << endl;
    cout << "3: POSAR UNA CARTA (MA->PILA)" << endl;
    cout << "4: MOURE UNA CARTA (TAULER->TAULER)" << endl;
    cout << "5: MOURE UNA CARTA (TAULER->PILA)" << endl;
    cout << "6: RECUPERAR UNA CARTA (PILA->TAULER)" << endl;
    cout << "E: ESPIAR EL TAULER" << endl;
    cout << "M: MOSTRAR EL MENU" << endl;
    cout << "A: ABANDONAR LA PARTIDA" << endl;
}

void tramitar_opcio(char opcio, Joc &joc){
//Pre: car�cter d'opci� i joc amb partida comen�ada; Post: crida a la funci� corresponent segons el car�cter entrat
    if(opcio=='1'){
        joc.obrir_carta();
        joc.mostrar();
    }
    else if(opcio=='2'){
        posar_ma_tauler(joc);
        joc.mostrar();
    }
    else if(opcio=='3'){
        joc.posar_ma_pila();
        joc.mostrar();
    }
    else if(opcio=='4'){
        moure_tauler(joc);
        joc.mostrar();
    }
    else if(opcio=='5'){
        moure_tauler_pila(joc); //check***
        joc.mostrar();
    }
    else if(opcio=='6'){
        recuperar_pila_tauler(joc); //check**
        joc.mostrar();
    }
    else if(opcio=='E') joc.mostrar(true);
    else if(opcio=='M') mostrar_menu();
    else if(opcio!='A'){
        cout << "OPCIO NO DEFINIDA " << opcio << endl;
        mostrar_menu();
        joc.mostrar();
    }
}


int main(){
//Programa principal amb el qual interact�a l'usuari
    Joc joc;
    joc.mostrar();
    mostrar_menu();
    char opcio='x';
    while(opcio!='A' and !joc.joc_acabat()){
        cout << "OPCIO:" << endl;
        cin >> opcio;
        tramitar_opcio(opcio, joc);
    }

    if(opcio=='A') cout << "HAS ABANDONAT LA PARTIDA!";
    return 0;
}
