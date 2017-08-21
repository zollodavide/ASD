#include <stdio.h>
#include <malloc.h>
#include "lista.h"

int main() {

    pnodo lista;

    aggiungiInTesta(&lista, 3);
    aggiungiInTesta(&lista, 2);
    aggiungiInTesta(&lista, 1);
    stampaLista(&lista);

    aggiungiInCoda(&lista, 4);
    stampaLista(&lista);

    aggiungiInPosizione(&lista, 5, 2) ;
    stampaLista(&lista);

    cancellaTesta(&lista);
    stampaLista(&lista);

    cancellaCoda(&lista);
    stampaLista(&lista);

    cancellaInPosizione(&lista, 1);
    stampaLista(&lista);


    printf("-----------------\n");


}


void creaLista(pnodo* l, int n) {

    pnodo head;

    pnodo x = head;
    *l = head;
    x = (pnodo)malloc(sizeof(nodo));
    int i = 1;
    while(i<n) {
        x->info = i;
        x->next= (pnodo)malloc(sizeof(nodo));
        x = x->next;
        i++;
    }
}

void stampaLista(pnodo* l) {

    pnodo tmp = *l;
    if(tmp == NULL) {
        printf("LISTA VUOTA");
        return;
    }
    while(tmp!=NULL) {
        printf("%d ", tmp->info);
        tmp = tmp->next;
    }
    printf("\n");

}


void aggiungiInTesta(pnodo* l, int value) {

    pnodo x = (pnodo)malloc(sizeof(nodo));
    x->info = value;
    x->next = *l;
    *l = x;

}

void aggiungiInCoda(pnodo* l, int value) {

    pnodo x = (pnodo)malloc(sizeof(nodo));
    x->info = value;
    x->next = NULL;

    if(*l == NULL)
        *l = x;

    else {
        pnodo temp = *l;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = x;
    }
}

void aggiungiInPosizione(pnodo* l, int val, int pos) {

    pnodo x = (pnodo)malloc(sizeof(nodo));
    x->info = val;

    if(pos>lung(l))
        return;

    else {
        pnodo temp = *l;
        int i = 0;

        while(i<pos-1) {
            temp = temp->next;
            i++;
        }
        x->next = temp->next;
        temp->next = x;

    }
}

int lung(pnodo* l) {
    int cont = 0;
    pnodo tmp = *l;
    while(tmp != NULL) {
        cont++;
        tmp = tmp->next;
    }
    return cont;
}

void cancellaTesta(pnodo* list) {

    if(*list != NULL) {
        pnodo tmp = *list;
        *list = tmp->next;
        free(tmp);
    }
    else
        printf("Lista vuota");

}

void cancellaCoda(pnodo* l) {

    if(*l != NULL) {
        pnodo tmp = *l;
        pnodo daCancellare = tmp->next;

        while(tmp->next->next != NULL) {
            tmp = tmp->next;
            daCancellare = tmp->next;

        }
        tmp->next= NULL;
        free(daCancellare);
    }
}

void cancellaInPosizione(pnodo* l, int pos) {

    if (pos > lung(l)-1) {
        printf("errore: posizione non valida\n");
        return;
    }

    if (pos == 0) {
        cancellaTesta(l);
        return;
    }

    if (pos == lung(l)-1) {
        cancellaCoda(l);
        return;
    }

    pnodo x = *l;
    pnodo daCancellare = x->next;
    int i= 0;
    while(i<pos-1) {
        x = x->next;
        daCancellare = x->next;
        i++;
    }

    x->next = x->next->next;
    free(daCancellare);

}