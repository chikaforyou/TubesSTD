#include "novel.h"
#include "penulis.h"
#include "menu.h"

void AA(ListP &LP, adrP P, ListN LN) {
    string nama;
    bool f = false;
    cout<<"--------------------------------------"<<endl;
    cout<<"             Add Author"<<endl;
    cout<<"--------------------------------------"<<endl;
    showP(LP);
    cout<<"Type the name of author:"<<endl;
    while (!f) {
        cin>>nama;
        if (nama=="stop") {
            f = true;
        } else {
            P = createNewP(nama);
            addP(LP, P);
        }
    }
    showP(LP);
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}

void AN(ListN &LN, adrN N, ListP LP) {
    string judul;
    bool f = false;
    cout<<"--------------------------------------"<<endl;
    cout<<"             Add Novel"<<endl;
    cout<<"--------------------------------------"<<endl;
    showN(LN);
    cout<<"Type the title of novel:"<<endl;
    while (!f) {
        cin>>judul;
        if (judul=="stop") {
            f = true;
        } else {
            N = createNewN(judul);
            addN(LN, N);
        }
    }
    showN(LN);
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}

void conn(ListP &LP, ListN &LN) {
    bool f = false;
    string nama, judul;
    cout<<"--------------------------------------"<<endl;
    cout<<"             Connecting"<<endl;
    cout<<"--------------------------------------"<<endl;
    showP(LP);
    showN(LN);
    cout<<"Type the name of author and the title of novel:"<<endl;
    while (!f) {
        cout<<"The name of author: ";
        cin>>nama;
        if (nama=="stop") {
            break;
        }
        adrP P = findP(LP, nama);

        cout<<"The title of novel: ";
        cin>>judul;
        adrN N = findN(LN, judul);

        if (P != NULL && N != NULL) {
            adrR f = findR(P, info(N));
            if (f != NULL) {
                cout<<"Failed, the author and the novel has been connected."<<endl;
            } else {
                adrR R = createNewR(info(N));
                relasikan(P, R);
                cout<<"Connected."<<endl;
            }
        } else if (P == NULL && N != NULL) {
            cout<<"Failed, the author hasn't been registered."<<endl;
        } else if (P != NULL && N == NULL) {
            cout<<"Failed, the novel hasn't been registered."<<endl;
        } else {
            cout<<"Failed, the author and the novel haven't been registered."<<endl;
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}

void DA(ListP &LP, ListN LN, adrP &P){
    string nama;
    cout<<"--------------------------------------"<<endl;
    cout<<"             Delete Author"<<endl;
    cout<<"--------------------------------------"<<endl;
    showP(LP);
    if (first(LP) != NULL) {
        cout<<"Type the name of author: ";
        cin>>nama;
        if (nama != "stop") {
            P = findP(LP, nama);
            if (P != NULL) {
                deleteP(LP, P);
                cout<<endl<<"Author "<<nama<<" has been deleted."<<endl;
                showP(LP);
            } else {
                cout<<"Failed, the author could not be found."<<endl;
            }
        } else {
            cout<<endl;
            menu(LP, LN);
        }
    } else {
        cout<<"No authors could be deleted."<<endl;
        cout<<endl;
        menu(LP, LN);
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}

void DN(ListP &LP, ListN &LN, adrR &R, adrN &N){
    string judul;
    cout<<"--------------------------------------"<<endl;
    cout<<"             Delete Novel"<<endl;
    cout<<"--------------------------------------"<<endl;
    showN(LN);
    if (first(LN) != NULL) {
        cout<<"Type the title of novel: ";
        cin>>judul;
        if (judul != "stop") {
            N = findN(LN, judul);
            if (N != NULL) {
                infoR(R) = info(N);
                deleteR(LP, R);
                deleteN(LN, N);
                cout<<"Novel "<<judul<<" has been deleted."<<endl;
                showN(LN);
            } else {
                cout<<"Failed, the novel could not be found."<<endl;
            }
        } else {
            cout<<endl;
            menu(LP, LN);
        }
    } else {
        cout<<"No novels could be deleted."<<endl;
        cout<<endl;
        menu(LP, LN);
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}

void SNP(ListN LN, ListP LP){
    cout<<"--------------------------------------"<<endl;
    cout<<" Show Novel(s) With Particular Author"<<endl;
    cout<<"--------------------------------------"<<endl;
    if (first(LP)==NULL && first(LN)==NULL) {
        cout<<"List is empty."<<endl;
    } else {
        adrN N = first(LN);
        while (N!=NULL) {
            bool f = false;
            cout<<"Novel "<<info(N)<<" ditulis oleh: "<<endl;
            adrP P = first(LP);
            while (P!=NULL) {
                adrR R = firstR(P);
                while (R!=NULL) {
                    if (info(N)==infoR(R)) {
                        f = true;
                        cout<<"- "<<info(P)<<endl;
                    }
                    R=nextR(R);
                }
                P=next(P);
            }
            if (f = false) {
                cout<<"Unknown."<<endl;
            }
            N=next(N);
        }
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}

void SNW(ListN LN, ListP LP) {
    cout<<"--------------------------------------"<<endl;
    cout<<"  Show Novel(s) Written by 2 Authors"<<endl;
    cout<<"--------------------------------------"<<endl;
    if (first(LP)==NULL && first(LN)==NULL) {
        cout<<"List is empty."<<endl;
    } else {
        bool f = false;
        adrN N = first(LN);
        cout<<"Novel yang ditulis oleh 2 penulis: "<<endl;
        while (N!=NULL) {
            int i = 0;
            adrP P = first(LP);
            while (P!=NULL) {
                adrR R = firstR(P);
                while (R!=NULL) {
                    if (info(N)==infoR(R)) {
                        i++;
                    }
                    R=nextR(R);
                }
                P=next(P);
            }
            if (i==2) {
                f = true;
                cout<<"- "<<info(N)<<endl;
            }
            N=next(N);
        }
        if (f = false) {
            cout<<"There are no novels written by 2 authors."<<endl;
        }
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}

void SNM(ListP LP, ListN LN) {
    cout<<"--------------------------------------"<<endl;
    cout<<"  Show Author(s) Who Wrote The Most"<<endl;
    cout<<"--------------------------------------"<<endl;
    if (first(LP)==NULL && first(LN)==NULL) {
        cout<<"List is empty"<<endl;
    } else {
        adrP P = first(LP);
        adrP Q;
        int Max = 0;
<<<<<<< Updated upstream
=======
        cout<<"Author(s) who wrote novel the most is/are: "<<endl;
>>>>>>> Stashed changes
        while (P!=NULL) {
            int i = 0;
            adrR R = firstR(P);
            while (R!=NULL) {
                i++;
                R=nextR(R);
            }
            if (Max<i){
                Max = i;
                Q = P;
            }
            P=next(P);
        }
        cout<<"Salah satu penulis yang menulis novel paling banyak adalah "<<info(Q)<<endl;
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}

void SCA(ListN LN, ListP LP) {
    cout<<"--------------------------------------"<<endl;
    cout<<" Show Author(s) Who Never Collaborate"<<endl;
    cout<<"--------------------------------------"<<endl;
    if (first(LP)==NULL && first(LN)==NULL) {
        cout<<"List is empty."<<endl;
    } else {
        adrP P = first(LP);
        int i;
        cout<<"Author who never collaborate: "<<endl;
>>>>>>> Stashed changes
        while (P!=NULL) {
            i = 0;
            adrR R = firstR(P);
            while (R!=NULL) {
                adrP Q = first(LP);
                while (Q!=NULL) {
                    adrR S = firstR(Q);
                    while (S!=NULL) {
                        if (info(P)==info(Q)) {
                            break;
                        }
                        if (infoR(R)==infoR(S)) {
                            i++;
                        }
                        S=nextR(S);
                    }
                    Q=next(Q);
                }
                R=nextR(R);
            }
            if (i==0) {
                cout<<"- "<<info(P)<<endl;
            }
            P=next(P);
        }
        if (i != 0) {
            cout<<"No authors has never collaborated."<<endl;
        }
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}

void showPN(ListP LP, ListN LN) {
    cout<<"--------------------------------------"<<endl;
    cout<<"     Show All Authors and Novels"<<endl;
    cout<<"--------------------------------------"<<endl;
    if (first(LP)==NULL && first(LN)==NULL) {
        cout<<"List is empty."<<endl;
    } else {
        adrP P = first(LP);
        cout<<"List penulis yang terdaftar:"<<endl;
        while (P != NULL) {
            cout << "Penulis: " << info(P) << endl;
            adrR Q = firstR(P);
            if (Q != NULL) {
                while (Q != NULL) {
                    cout<<"--> Novel: "<<infoR(Q)<<endl;
                    Q = nextR(Q);
                }
                cout<<endl;
            } else {
                cout<<"Novel could not be found."<<endl;
                cout<<endl;


            }
            P = next(P);
        }
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}

void SPN (ListN LN, ListP LP) {
    cout<<"--------------------------------------"<<endl;
    cout<<"     Show All Novels and Authors"<<endl;
    cout<<"--------------------------------------"<<endl;
    if (first(LP)==NULL && first(LN)==NULL) {
        cout<<"List is empty."<<endl;
    } else {
        string penulis;
        cout<<"Type the name of author: ";
        cin>>penulis;
        adrP p = findP(LP, penulis);
        if (p!=NULL) {
            cout<<"Novel(s) that written by "<<info(p)<<" is/are:"<<endl;
>>>>>>> Stashed changes
            adrR r = firstR(p);
            while (r!=NULL) {
                cout<<"- "<<infoR(r)<<endl;
                r=nextR(r);
            }
        } else {
<<<<<<< Updated upstream
            cout<<"Penulis tidak ditemukan"<<endl;
=======
            cout<<"The Author could not be found."<<endl;
>>>>>>> Stashed changes
        }
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}
void manual(ListP LP, ListN LN) {
    cout<<"--------------------------------------"<<endl;
    cout<<"               Manual"<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"1. Type 'stop' to stop registering/connecting or back to main menu."<<endl;
    cout<<"3. Type '13' to clear the screen."<<endl;
    cout<<"3. Type '14' to close the program."<<endl;
>>>>>>> Stashed changes
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}

void menu(ListP &LP, ListN &LN) {
    int x;

    adrP P;
    adrN N;
    adrR R;

<<<<<<< Updated upstream
    cout<<"Menu Program: "<<endl;
	cout<<"1. Add Author"<<"                                  "<<"7. Show Novel Written by 2 Author"<<endl;
	cout<<"2. Add Novel"<<"                                   "<<"8. Show Author Who Wrote The Most"<<endl;
	cout<<"3. Connecting"<<"                                  "<<"9. Show Independent Author"<<endl;
=======
    cout<<"Program's Features: "<<endl;
	cout<<"1. Add Author"<<"                                  "<<"7. Show Novel(s) Written by 2 Authors"<<endl;
	cout<<"2. Add Novel"<<"                                   "<<"8. Show Author(s) Who Wrote The Most"<<endl;
	cout<<"3. Connecting"<<"                                  "<<"9. Show Author(s) Who Never Collaborate"<<endl;
	cout<<"4. Delete Author "<<"                              "<<"10. Show All Authors and Novels"<<endl;
	cout<<"5. Delete Novel"<<"                                "<<"11. Show All Novels and Authors"<<endl;
	cout<<"6. Show Novel(s) With Particular Author"<<"        "<<"12. Manual"<<endl;

	cout<<endl;
<<<<<<< Updated upstream
	cout<<"Pilih menu: ";
=======
	cout<<"Choose a feature: ";
>>>>>>> Stashed changes
	cin>>x;
	system("CLS");
	if (x==1) {
        AA(LP, P, LN);
	} else if (x==2) {
        AN(LN, N, LP);
	} else if (x==3) {
        conn(LP, LN);
	} else if (x==4) {
        DA(LP, LN, P);
	} else if (x==5) {
        DN(LP, LN, R, N);
	} else if (x==6) {
        SNP(LN, LP);
	} else if (x==7) {
        SNW(LN, LP);
	} else if (x==8) {
        SNM(LP, LN);
	} else if (x==9) {
        SCA(LN, LP);
	} else if (x==10) {
        showPN(LP, LN);
    } else if (x==11) {
        SPN(LN, LP);
    } else if (x==12) {
        manual(LP, LN);
    } else if (x==13) {
        system("CLS");
        cout<<"Cleared"<<endl;
        cout<<endl;
        system("pause");
        cout<<endl;
        menu(LP, LN);
	} else if (x==14) {
        cout<<"Close Program"<<endl;
	} else {
        cout<<"Not found, try again!"<<endl;
        menu(LP, LN);
	}
}
