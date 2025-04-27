#include "Tauler.h"

Tauler::Tauler(){
//Pre:--; Post: matriu buida (amb el nombre de files i columnes necessari pel nostre joc)
    a_fila=19;
    a_col=7;
    reserva();
}

Tauler::Tauler(int nf, int nc){
//Pre: nf>0 i nc>0; Post: objecte vàlid amb memòria reservada
    a_fila=nf;
    a_col=nc;
    reserva();
}

Tauler::Tauler(const Tauler &t){
//Pre:--; Post: informació de t copiada a l’actual
    reserva();
    copia(t);
}

Tauler::~Tauler(){
//Pre:-;- Post: allibera la memòria reservada per l’objecte
    allibera();
}

Tauler & Tauler::operator=(const Tauler &t) {
// Pre: --; Post: s’ha assignat sense aliasing la informació de t a l’objecte actual
    if(this!=&t){
        allibera();
        copia(t);
    }
    return *this;
}

void Tauler::afegirCarta(int i, int j, const Carta &c){
//Pre: --; Post: Coloca la carta a la posició corresponent
    a_carta[i][j]=c;
}

void Tauler::retirarCarta(int i, int j){
//Pre: posició i,j; Post: retira la carta de la posició entrada del tauler i si hi ha alguna carta no visible a sobre la mostra
    a_carta[i][j]=Carta();
    if(i>0 and !a_carta[i-1][j].visible()){
        a_carta[i-1][j].canvia_visibilitat();
    }
}

Carta Tauler::obtCarta(int i, int j) const{
//Pre: posició i,j; Post: Retorna la carta de la posició corresponent
    return a_carta[i][j];
}

int Tauler::obtNF()const{
//Pre: --; Post: retorna el nombre de files de la matriu
    return a_fila;
}

int Tauler::obtNC()const{
//Pre: --; Post: retorna el nombre de columnes de la matriu
    return a_col;
}

void Tauler::repartir(Baralla &b){
//Pre: --; Post: Per cada columna y per cada fila agafa l’últim element de la baralla i el col·loca a la posició de la matriu corresponent.
    for(int i=0; i<a_col;i++){
        for(int j=0; j<=i;j++){
            a_carta[j][i]=b.robar_carta();
            if(j==i)a_carta[j][i].canvia_visibilitat();
        }
    }
}

void Tauler::mostrar(bool mostrar_tot)const{
//Pre: --; Post: Mostra l'estat actual del tauler
    for(int j=0; j<a_col; j++) cout << "c" << j+1 << " ";
    cout << endl;

    for(int i=0; i<a_fila; i++){
        bool fila_buida=true;
        //mirem si la fila és buida o no
        for (int j=0; j<a_col; j++){
            if(a_carta[i][j].valor()!=0) fila_buida=false;
        }
        //si la fila no és buida, la mostrem
        if (!fila_buida){
            for (int j=0; j < a_col; j++) {
                if(a_carta[i][j].valor() != 0) {
                    if(mostrar_tot && !a_carta[i][j].visible()){
                        a_carta[i][j].canvia_visibilitat();
                        cout << a_carta[i][j] << " ";
                        a_carta[i][j].canvia_visibilitat();
                    } else cout << a_carta[i][j] << " ";
                } else cout << "   ";
            }
            cout << "f" << i + 1 << endl;
        }
    }
}

void Tauler::allibera() {
// Pre: --; Post: memòria alliberada
    for(int i=0;i<a_fila; i++) delete[] a_carta[i];
    delete[] a_carta;
}

void Tauler::reserva() {
// Pre: a_fila>0 ^ a_col>0; Post: memòria reservada
    a_carta = new Carta*[a_fila]; // creació d’un vector de punters
    for(int i=0; i<a_fila; i++) a_carta[i]= new Carta[a_col];
}

void Tauler::copia(const Tauler &t) {
// Pre: --; Post: fa un duplicat de la matriu
    a_fila = t.a_fila;
    a_col = t.a_col;
    reserva();
    for(int i=0; i<a_fila; i++) {
        for (int j=0; j<a_col; j++){
          a_carta[i][j]=t.a_carta[i][j];
        }
    }
}
