//
// Created by davide.zollo on 21/08/17.
//


typedef struct nodo{
    int info;
    struct nodo * next;
} nodo;

typedef nodo* pnodo;

void stampaLista(pnodo* l) ;
void aggiungiInTesta(pnodo* l, int value) ;
void aggiungiInCoda(pnodo* l, int value) ;
int lung(pnodo* l) ;
void aggiungiInPosizione(pnodo* l, int val, int pos) ;
void cancellaTesta(pnodo* list) ;
void cancellaCoda(pnodo* l) ;
void creaLista(pnodo* l, int n) ;
void cancellaInPosizione(pnodo* l, int pos) ;
