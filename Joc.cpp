#include "Joc.h"

Joc::Joc(){
//Pre: -; Post: demana al usuari una llavor per barrejar les cartes i prepara el tauler per a una partida nova
    Baralla baralla;
    baralla.emplena();
    cout << "ENTRA LA LLAVOR:" << endl;
    int llavor;
    cin >> llavor;
    baralla.barreja(llavor);
    a_tauler.repartir(baralla);

    while(baralla.n_cartes()>0) a_ma.empila(baralla.robar_carta());
}


void Joc::mostrar(bool mostrar_tot) const{
//Pre: -; Post: mostra l'estat actual de la partida
    cout << "ESTAT DEL JOC" << endl;
    mostrar_piles_pal();
    mostrar_ma_descartades();
    a_tauler.mostrar(mostrar_tot);
    if(!joc_acabat()) cout << "JOC EN CURS" << endl;
    else{
        cout << "JOC ACABAT" << endl;
        cout << "HAS GUANYAT LA PARTIDA!" << endl;
    }
}

bool Joc::joc_acabat()const{
//Pre: -; Post: retorna true si el joc ha acabat, es a dir, el cim de les piles dels pals té el valor K
    bool acabat=false;
    if(!a_piques.buida() and !a_cors.buida() and !a_diamants.buida() and !a_trevols.buida()){
        if(a_piques.cim().valor()==13 and a_cors.cim().valor()==13 and a_diamants.cim().valor()==13 and a_trevols.cim().valor()==13) acabat=true;
    }
    return acabat;
}


void Joc::obrir_carta(){
//Pre: -; Post: es mou la carta al cim de la ma a la pila de descartades i es mostra. Si la ma és buida, s'emplena amb la pila de descartades. Si ambdues piles són buides, no passa res
    if(!a_ma.buida()){
        Carta c(a_ma.cim());
        a_ma.desempila();
        c.canvia_visibilitat();
        a_descartades.empila(c);
    }else if(a_ma.buida() and !a_descartades.buida()){
        while(!a_descartades.buida()){
            Carta c(a_descartades.cim());
            a_descartades.desempila();
            c.canvia_visibilitat();
            a_ma.empila(c);
        }
    }
}

void Joc::posar_carta_ma_tauler(int col){
//Pre: -; Post: la carta al cim de la pila de descartades es mourà a la columna indicada només si és possible
    //Si el nombre introduit és major al nombre de columnes
    if(col>a_tauler.obtNC()) cout << "LA CARTA NO ES POT POSAR A LA COLUMNA " << col << endl;
    //Si el nombre introduit és correcte
    else{
        Carta c_ma(a_descartades.cim());
        int fila=1;
        //Si la primera posició de la columna és buida
        if(a_tauler.obtCarta(fila-1,col-1).valor()==0){
            //Si la carta és una K, es pot moure - en cas contrari no es pot moure
            if(c_ma.valor()==13){
                a_tauler.afegirCarta(fila-1, col-1, c_ma);
                a_descartades.desempila();
            } else cout << "LA CARTA NO ES POT POSAR A LA COLUMNA " << col << endl;
        //Si la posició de la fila no es 1 significa que hem de comprobar quina és la carta que hi ha al final
        }else{
            //Anem sumant el nombre de files fins que trobem l'ultima carta
            while(a_tauler.obtCarta(fila,col-1).valor()!=0){
                fila++;
            }
            Carta c_tauler(a_tauler.obtCarta(fila-1, col-1));
            if(c_tauler.apta_tauler(c_ma)){
                a_tauler.afegirCarta(fila, col-1, c_ma);
                a_descartades.desempila();
            } else cout << "LA CARTA NO ES POT POSAR A LA COLUMNA " << col << endl;
        }
    }
}

void Joc::posar_ma_pila(){
//Pre: -; Post: si hi ha alguna carta a la pila de descartades, es comprova la pila segons el pal a la que correspón i es mou si és possible
    //Si la pila de descartades és buida
    if (a_descartades.buida()) cout << "NO HI HA CAP CARTA PER AGAFAR" << endl;
    else {
        //Mirem el pal de la carta i escollim la pila corresponent
        Carta c_ma(a_descartades.cim());
        auto& p = pila_corresponent(c_ma);

        //Si la pila és buida
        if (p.buida()) {
            //Si és A empilem
            if (c_ma.valor() == 1) {
                p.empila(c_ma);
                a_descartades.desempila();
            } else cout << "LA CARTA NO ES POT APILAR" << endl;
        //Si no és buida, s'empila la carta si és possible
        } else {
            Carta c_pila(p.cim());
            if (c_ma.valor() == c_pila.valor() + 1) {
                p.empila(c_ma);
                a_descartades.desempila();
            } else cout << "LA CARTA NO ES POT APILAR" << endl;
        }
    }
}

void Joc::moure_cartes_tauler(int col, int fila, int desti){
//Pre: -; Post: agafa una o més cartes visibles de la columna entrada com origen i, si és possible, es posen al final de la columna destí
    //Si el nombre introduit és major al nombre de columnes
    if(desti>a_tauler.obtNC()) cout << "LA CARTA NO ES POT POSAR A LA COLUMNA " << desti << endl;
    else{
        int fdesti=1;
        Carta c_origen(a_tauler.obtCarta(fila-1, col-1));
        //Si la columna és buida la carta ha de ser K
        if(a_tauler.obtCarta(fdesti-1,desti-1).valor()==0){
            if(a_tauler.obtCarta(fila-1,col-1).valor()==13){
                while(a_tauler.obtCarta(fila-1,col-1).visible()){
                    a_tauler.afegirCarta(fdesti-1, desti-1, a_tauler.obtCarta(fila-1, col-1));
                    a_tauler.retirarCarta(fila-1,col-1);
                    fdesti++;
                    fila++;
                }
            } else cout << "LA CARTA NO ES POT POSAR A LA COLUMNA " << desti << endl;
        }else{
            //Si la columna no és buida, hem de mirar si es pot moure la carta
            while(a_tauler.obtCarta(fdesti,desti-1).valor()!=0){
                fdesti++;
            }
            Carta c_tauler(a_tauler.obtCarta(fdesti-1, desti-1));
            if(c_tauler.apta_tauler(a_tauler.obtCarta(fila-1, col-1))){
                while(a_tauler.obtCarta(fila-1,col-1).visible()){
                    a_tauler.afegirCarta(fdesti, desti-1, a_tauler.obtCarta(fila-1, col-1));
                    a_tauler.retirarCarta(fila-1,col-1);
                    fdesti++;
                    fila++;
                }
            } else cout << "LA CARTA NO ES POT POSAR A LA COLUMNA " << desti << endl;
        }
    }
}

void Joc::moure_cartes_tauler_pila(int col){
//Pre: -; Post: Si la columna entrada no és buida, es comprova la pila segons el pal a la que correspón i es mou si és possible
    int fila=1;
    //Si la primera posició de la columna és buida
    if(a_tauler.obtCarta(fila-1,col-1).valor()==0) cout << "NO HI HA CAP CARTA PER AGAFAR" << endl;
    else {
        //Anem sumant el nombre de files fins que trobem l¡ultima carta
        while(a_tauler.obtCarta(fila,col-1).valor()!=0){
            fila++;
        }
        Carta c_tauler(a_tauler.obtCarta(fila-1, col-1));
        //Mirem el pal de la carta i ens enfoquem en la pila corresponent
        auto& p = pila_corresponent(c_tauler);

        //Si la pila és buida
        if (p.buida()) {
            //Si és A empilem
            if (c_tauler.valor() == 1) {
                p.empila(c_tauler);
                a_tauler.retirarCarta(fila-1,col-1);
                //borrem carta y revelem la següent
            } else cout << "LA CARTA NO ES POT APILAR" << endl;
        } else {
            Carta c_pila(p.cim());
            if (c_tauler.valor() == c_pila.valor() + 1) {
                p.empila(c_tauler);
                //borrem carta i revelem la següent
                a_tauler.retirarCarta(fila-1,col-1);
            } else cout << "LA CARTA NO ES POT APILAR" << endl;
        }
    }
}

void Joc::recuperar_carta_pila_tauler(int n, int col){
//Pre: -; Post: agafa la carta de la pila indicada i comproba que es pugui moure a la columna entrada. La carta es mou si és possible
    //Si el nombre introduit és major al nombre de columnes
    if(col>a_tauler.obtNC()) cout << "LA CARTA NO ES POT POSAR A LA COLUMNA " << col << endl;
    else{
        auto& p=escollir_pila(n);
        Carta c_pila(p.cim());
        int fila=1;
        //Si la primera posició de la columna és buida
        if(a_tauler.obtCarta(fila-1,col-1).valor()==0){
            //Si la carta és una K, es pot moure - en cas contrari no es pot moure
            if(c_pila.valor()==13){
                a_tauler.afegirCarta(fila-1, col-1, c_pila);
                p.desempila();
            }else cout << "LA CARTA NO ES POT POSAR A LA COLUMNA " << col << endl;
            //Si la posició de la fila no es 1 significa que hem de comprobar quina és la carta que hi ha al final
        }else{
            //Anem sumant el nombre de files fins que trobem l'ultima carta
            while(a_tauler.obtCarta(fila,col-1).valor()!=0){
                fila++;
            }
            Carta c_tauler(a_tauler.obtCarta(fila-1, col-1));
            if(c_tauler.apta_tauler(c_pila)){
                a_tauler.afegirCarta(fila, col-1, c_pila);
                p.desempila();
            } else cout << "LA CARTA NO ES POT POSAR A LA COLUMNA " << col << endl;
        }
    }
}


PilaCartes& Joc::pila_corresponent(Carta c){
//Pre: Carta de la baralla; Post: retorna la pila de cartes a la que pertany la carta segons el pal
    if(c.pal()=='P') return a_piques;
    else if(c.pal()=='c') return a_cors;
    else if(c.pal()=='d') return a_diamants;
    else return a_trevols;
}

PilaCartes& Joc::escollir_pila(int n){
//Pre: nombre enter; Post: retorna la pila de cartes a la que pertany segons el nombre introduit
    if(n==1) return a_piques;
    else if(n==2) return a_cors;
    else if(n==3) return a_diamants;
    else return a_trevols;
}


bool Joc::comprobar_descartades()const{
//Pre: -; Post: retorna true si la pila és buida, retorna false altrament
    return a_descartades.buida();
}

bool Joc::comprobar_pila(int n){
//Pre: -; Post: retorna true si la pila indicada és buida, retorna false altrament
    auto& p=escollir_pila(n);
    return p.buida();
}

bool Joc::comprobar_carta(int col, int fila)const{
//Pre: -; Post: retorna true si la carta és visible, retorna false altrament
    return a_tauler.obtCarta(fila-1,col-1).visible();
}


void Joc::mostrar_piles_pal()const{
//Pre: -; Post: Mostra les piles segons el pal
    if(!a_piques.buida()) cout << a_piques.cim();
    else cout << "  ";
    cout << " ";
    if(!a_cors.buida()) cout << a_cors.cim();
    else cout << "  ";
    cout << " ";
    if(!a_diamants.buida()) cout << a_diamants.cim();
    else cout << "  ";
    cout << " ";
    if(!a_trevols.buida()) cout << a_trevols.cim();
    else cout << "  ";
    cout << "    ";
}

void Joc::mostrar_ma_descartades()const{
//Pre: -; Post: Mostra la ma i la pila de descartades
    if(!a_ma.buida()) cout << a_ma.cim();
    else cout << "  ";
    cout << " ";
    if(!a_descartades.buida()) cout << a_descartades.cim();
    else cout << "  ";
    cout << endl;
}
