#include <iostream>
#include"penulis.h"
#include"novel.h"
#include"menu.h"

using namespace std;

int main()
{
    cout<<"---------------------------------------"<<endl;
    cout<<"-    This Program is engineered by    -"<<endl;
    cout<<"-        Imam Rafiif Arrazaan         -"<<endl;
    cout<<"-                and                  -"<<endl;
    cout<<"-         Arvinda Dwi Safira          -"<<endl;
    cout<<"-      We're from class IF-43-07      -"<<endl;
    cout<<"---------------------------------------"<<endl;
    system("pause");
    ListN LN;
    ListP LP;

    createList(LP);
    createList(LN);

    menu(LP, LN);

    return 0;

}
