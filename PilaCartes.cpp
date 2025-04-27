#include "PilaCartes.h"

PilaCartes::PilaCartes(){
//Pre: -; Post: pila buida
    a_cim = nullptr;
}

PilaCartes::PilaCartes(const PilaCartes &o){
//Pre: -; Post: aquesta pila és còpia de la pila o
    a_cim = nullptr;
    copia(o);
}

PilaCartes::~PilaCartes(){
// Pre: -; Post: memòria alliberada
    allibera();
}

PilaCartes& PilaCartes::operator=(const PilaCartes& o){
// Pre: - ; Post: aquesta pila és còpia de la pila o i la seva memòria dinàmica ha estat prèviament alliberada
    if(this!=&o){
        allibera();
        copia(o);
    }
    return *this;
}

bool PilaCartes::buida() const{
// Pre: - ; Post: retorna cert si la pila és buida; fals en cas contrari
    return a_cim==nullptr;
}

Carta PilaCartes::cim() const{
// Pre: -; Post: retorna la carta del cim de la pila
    if(!buida()) return a_cim->carta;
    else return Carta(); //Carta default=error
}

void PilaCartes::empila(Carta c){
// Pre: --; Post: ha afegit c a dalt de la pila
    Node* nou = new Node;
    nou->carta = c;
    nou->seg = a_cim;
    a_cim = nou;
}

void PilaCartes::desempila(){
// Pre: pila no buida; Post: ha eliminat element de dalt de la pila
    if(!buida()){
        Node* aux = a_cim;
        a_cim = a_cim->seg;
        delete aux;
    }
}

void PilaCartes::copia(const PilaCartes& o){
// Pre: pila buida; Post: aquesta pila és còpia de la pila o
    if (!o.buida()){
        a_cim=nullptr;
        Node *aux = o.a_cim;
        while(aux!=nullptr){
            empila(aux->carta);
            aux=aux->seg;
        }
    }
}

void PilaCartes::allibera(){
// Pre: --; Post: memòria dinàmica alliberada
    while(!buida()) {
        desempila();
    }
}
