#include<iostream>
#include"novel.h"

void createList(ListN &L) {
    first(L) = NULL;
}

adrN createNewN(string nama) {
    adrN P = new novel;
    info(P) = nama;
    next(P) = NULL;
    return P;
}

void addN(ListN &L, adrN P) {
    adrN f = findN(L, info(P));
    if (f != NULL) {
        cout<<"Novel had been registered."<<endl;
    } else {
        if (first(L) != NULL) {
            adrN Q = first(L);
            while(next(Q) != NULL) {
                Q = next(Q);
            }
            next(Q) = P;
            next(P) = NULL;
        } else {
            first(L) = P;
            next(P) = NULL;
        }
    }
}

void deleteN(ListN &L, adrN P) {
    adrN prec;
    if (P != NULL) {
        if (P == first(L)) {
            deleteFirstN(L, P);
       } else if (next(P) == NULL) {
           deleteLastN(L);
       } else {
           prec = first(L);
           while (next(prec) != P) {
                prec = next(prec);
           }
           deleteAfterN(L, prec);
       }
    } else {
        cout<<"List is empty."<<endl;
    }
}

void deleteFirstN(ListN &L, adrN &P) {
    first(L) = next(P);
    next(P) = NULL;
}

void deleteLastN(ListN &L) {
    adrN P = first(L);
    while (next(next(P)) != NULL) {
        P = next(P);
    }
    adrN Q = next(P);
    next(Q) = NULL;
    next(P) = NULL;
}

void deleteAfterN(ListN &L, adrN prec) {
    adrN P = first(L);
    while (next(P) != NULL && info(P) != info(prec)) {
        P = next(P);
    }
    adrN Q = next(P);
    next(P) = next(Q);
    next(Q) = NULL;

}

adrN findN(ListN L, string judul) {
    if (first(L) != NULL) {
        adrN P = first(L);
        do {
            if (info(P) != judul) {
                P = next(P);
            } else {
                return P;
            }
        } while (P != NULL);
    } else {
        return NULL;
    }
}

void showN(ListN L) {
    int i = 0;
    adrN P = first(L);
    cout<<endl<<"Registered Novel:"<<endl;
    if (first(L) != NULL) {
        while (P != NULL) {
            i++;
            cout<<i<<". "<<info(P)<<endl;
            P = next(P);
        }
    } else {
        cout<<"No Novels are registered."<<endl;
    }
    cout<<endl;
}
