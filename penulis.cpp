#include<iostream>
#include"penulis.h"
#include"novel.h"

void createList(ListP &L) {
    first(L) = NULL;
}

adrP createNewP(string nama) {
    adrP P = new penulis;
    info(P) = nama;
    next(P) = NULL;
    firstR(P) = NULL;
    return P;
}

adrR createNewR(string judul) {
    adrR P = new relasi;
    infoR(P) = judul;
    nextR(P) = NULL;
    return P;

}

void addP(ListP &L, adrP P) {
    adrP f = findP(L, info(P));
    if (f != NULL) {
        cout<<"Penulis sudah terdaftar."<<endl;
    } else {
        if (first(L) != NULL) {
            adrP Q = first(L);
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

void addR(adrP P, adrR R) {
    if (P != NULL) {
        adrR Q = firstR(P);
        if (Q != NULL) {
            while(nextR(Q) != NULL) {
            Q = nextR(Q);
            }
            nextR(Q) = R;
            nextR(R) = NULL;
        } else {
            firstR(P) = R;
            nextR(R) = NULL;
        }
    } else {
        firstR(P) = R;
        nextR(R) = NULL;
    }
}

void deleteP(ListP &L, adrP P) {
    adrP prec;
    if (P != NULL) {
        if (P == first(L)) {
            deleteFirstP(L, P);
       } else if (next(P) == NULL) {
           deleteLastP(L);
       } else {
           prec = first(L);
           while (next(prec) != P) {
                prec = next(prec);
           }
           deleteAfterP(L, prec);
       }
    } else {
        cout<<"List kosong."<<endl;
    }
}

void deleteFirstP(ListP &L, adrP &P) {
    first(L) = next(P);
    next(P) = NULL;
}

void deleteLastP(ListP &L) {
    adrP P = first(L);
    while (next(next(P)) != NULL) {
        P = next(P);
    }
    adrP Q = next(P);
    next(Q) = NULL;
    next(P) = NULL;
}

void deleteAfterP(ListP &L, adrP prec) {
    adrP P = first(L);
    while (next(P) != NULL && info(P) != info(prec)) {
        P = next(P);
    }
    adrP Q = next(P);
    next(P) = next(Q);
    next(Q) = NULL;
}

void deleteR(ListP &L, adrR P) {
    adrP Q;
    adrR R, prec;
    if (P != NULL) {
        Q = first(L);
        while (Q != NULL) {
            R = firstR(Q);
            while (R != NULL) {
                if (infoR(R) == infoR(P)) {
                    if (R == firstR(Q)) {
                        deleteFirstR(L, R, Q);
                    } else if (nextR(R) == NULL) {
                        deleteLastR(L, Q);
                    } else {
                        prec = firstR(Q);
                        while (infoR(nextR(prec)) != infoR(P)) {
                            prec = nextR(prec);
                        }
                        deleteAfterR(prec, Q);

                    }
                }
                R = nextR(R);
            }
            Q = next(Q);
        }
    } else {
        cout<<"Tidak dapat menghapus novel, list kosong."<<endl;
    }
}


void deleteFirstR(ListP &L, adrR &R, adrP Q) {
    firstR(Q) = nextR(R);
    nextR(R) = NULL;
}

void deleteLastR(ListP &L, adrP Q) {
    adrR P = firstR(Q);
    while (nextR(nextR(P)) != NULL) {
        P = nextR(P);
    }
    adrR R = nextR(P);
    nextR(R) = NULL;
    nextR(P) = NULL;
}

void deleteAfterR(adrR prec, adrP Q) {
    adrR P = firstR(Q);
    while (nextR(P) != NULL && infoR(P) != infoR(prec)) {
        P = nextR(P);
    }
    adrR R = nextR(P);
    nextR(P) = nextR(R);
    nextR(R) = NULL;
}

adrP findP(ListP L, string nama) {
    if (first(L) != NULL) {
        adrP P = first(L);
        do {
            if (info(P) != nama) {
                P = next(P);
            } else {
                return P;
            }
        } while (P != NULL);
    } else {
        return NULL;
    }
}

adrR findR(adrP P, string judul) {
    if (firstR(P) != NULL) {
        adrR Q = firstR(P);
        do {
            if (infoR(Q) != judul) {
                Q = nextR(Q);
            } else {
                return Q;
            }
        } while (Q != NULL);
    } else {
        return NULL;
    }
}

void relasikan(adrP P, adrR R) {
    if (P != NULL && R != NULL) {
        addR(P, R);
    } else {
        cout<<"Penulis tidak ditemukan."<<endl;
    }
}

void showP(ListP L) {
    adrP P = first(L);
    int i = 0;
    cout<<endl<<"Registered author:"<<endl;
    if (first(L) != NULL) {
        while (P != NULL) {
            i++;
            cout<<i<<". "<<info(P)<<endl;
            P = next(P);
        }
    } else {
        cout<<"No authors are registered."<<endl;
    }
    cout<<endl;
}
