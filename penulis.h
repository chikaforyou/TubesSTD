#ifndef PENULIS_H_INCLUDED
#define PENULIS_H_INCLUDED
#include <iostream>
#define first(L) L.first
#define firstR(P) P->firstR
#define next(P) P->next
#define info(P) P->info
#define nextR(P) P->nextR
#define infoR(P) P->infoR

using namespace std;
typedef struct penulis *adrP;
typedef struct relasi *adrR;

struct penulis {
    string info;
    adrP next;
    adrR firstR;
};

struct relasi {
    adrR nextR;
    string infoR;
};

struct ListP {
    adrP first;
};


void createList(ListP &L);
adrP createNewP(string nama);
adrR createNewR(string judul);
void addP(ListP &L, adrP P);
void addR(adrP P, adrR R);
void deleteP(ListP &L, adrP P);
void deleteFirstP(ListP &L, adrP &P);
void deleteLastP(ListP &L);
void deleteAfterP(ListP &L, adrP prec);
void deleteR(ListP &L, adrR P);
void deleteFirstR(ListP &L, adrR &P, adrP Q);
void deleteLastR(ListP &L, adrP Q);
void deleteAfterR(adrR prec, adrP Q);
adrR findR(adrP P, string judul);
adrP findP(ListP L, string nama);
void relasikan(adrP P, adrR R);
void showP(ListP L);

#endif // PENULIS_H_INCLUDED
