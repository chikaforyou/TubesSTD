#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <conio.h>
#include <stdlib.h>

void AA(ListP &LP, adrP P, ListN LN);
void AN(ListN &LN, adrN N, ListP LP);
void conn(ListP &LP, ListN &LN);
void DA(ListP &LP, ListN LN, adrP &P);
void DN(ListP &LP, ListN &LN, adrR &R, adrN &N);
void SNP(ListN LN, ListP LP);
void SNW(ListN LN, ListP LP);
void SNM(ListP LP);
void SCA(ListP, ListN LN);
void menu(ListP &LP, ListN &LN);
void showPN(ListP LP, ListN LN);
void manual(ListP LP, ListN LN);
void SPN(ListN LN, ListP LP);

#endif // MENU_H_INCLUDED
