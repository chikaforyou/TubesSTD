#include <iostream>
#include"penulis.h"
#include"novel.h"
#include"menu.h"

using namespace std;

int main()
{
    cout<<"---------------------------------------"<<endl;
    cout<<"-      Program ini dirancang oleh     -"<<endl;
    cout<<"-        Imam Rafiif Arrazaan         -"<<endl;
    cout<<"-                dan                  -"<<endl;
    cout<<"-         Arvinda Dwi Safira          -"<<endl;
    cout<<"-      Kami dari kelas IF-43-07       -"<<endl;
    cout<<"---------------------------------------"<<endl;
    system("pause");
    ListN LN;
    ListP LP;

    createList(LP);
    createList(LN);

    menu(LP, LN);

    return 0;

}
