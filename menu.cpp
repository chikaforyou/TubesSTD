#include "novel.h"
#include "penulis.h"
#include "menu.h"

void AA(ListP &LP, adrP P, ListN LN) {
    string nama;
    bool f = false;
    showP(LP);
    cout<<"Type author's name:"<<endl;
    while (!f) {
        cin>>nama;
        if (nama=="stop") {
            f = true;
        } else {
            P = createNewP(nama);
            addP(LP, P);
        }
    }
    cout<<endl;
    showP(LP);
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}
void AN(ListN &LN, adrN N, ListP LP) {
    string judul;
    bool f = false;
    showN(LN);
    cout<<"Type novel's title:"<<endl;
    while (!f) {
        cin>>judul;
        if (judul=="stop") {
            f = true;
        } else {
            N = createNewN(judul);
            addN(LN, N);
        }
    }
    cout<<endl;
    showN(LN);
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}
void conn(ListP &LP, ListN &LN) {
    bool f = false;
    string nama, judul;
    showP(LP);
    showN(LN);
    cout<<"Type author's name and novel's title to be connected:"<<endl;
    while (!f) {
        cout<<"Author's name:";
        cin>>nama;
        if (nama=="stop") {
            break;
        }
        adrP P = findP(LP, nama);

        cout<<"Novel's title:";
        cin>>judul;
        adrN N = findN(LN, judul);

        if (P != NULL && N != NULL) {
            adrR f = findR(P, info(N));
            if (f != NULL) {
                cout<<"Connecting failed, author and novel had been connected."<<endl;
            } else {
                adrR R = createNewR(info(N));
                relasikan(P, R);
                cout<<"Connecting success."<<endl;
            }
        } else if (P == NULL && N != NULL) {
            cout<<"Connecting failed, author hasn't been registered."<<endl;
        } else if (P != NULL && N == NULL) {
            cout<<"Connecting failed, novel hasn't been registered."<<endl;
        } else {
            cout<<"Connecting failed, author and novel hasn't been registered."<<endl;
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}

void DA(ListP &LP, ListN LN, adrP &P){
    string nama;
    showP(LP);
    cout<<"Type author's name to be deleted: ";
    cin>>nama;
    P = findP(LP, nama);
    if (P != NULL) {
        deleteP(LP, P);
        cout<<endl<<"Deleting success."<<endl;
        showP(LP);
    } else {
         cout<<"Deleting failed, author not found."<<endl;
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}
void DN(ListP &LP, ListN &LN, adrR &R, adrN &N){
    string judul;
    showN(LN);
    cout<<"Type novel to be deleted: ";
    cin>>judul;
    N = findN(LN, judul);
    if (N != NULL) {
        infoR(R) = info(N);
        deleteR(LP, R);
        deleteN(LN, N);
        cout<<"Deleting success."<<endl;
        showN(LN);
    } else {
        cout<<"Deleting failed, novel not found."<<endl;
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}

void SNP(ListN LN, ListP LP){
    if (first(LP)==NULL && first(LN)==NULL) {
        cout<<"List is empty"<<endl;
    } else {
        adrN N = first(LN);
        while (N!=NULL) {
            bool f = false;
            cout<<"Novel "<<info(N)<<" written by: "<<endl;
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
                cout<<"Unknown"<<endl;
            }
            N=next(N);
        }
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}
void SNW(ListN LN, ListP LP) {
    if (first(LP)==NULL && first(LN)==NULL) {
        cout<<"List is empty"<<endl;
    } else {
        bool f = false;
        adrN N = first(LN);
        cout<<"Novel written by 2 authors: "<<endl;
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
            cout<<"None"<<endl;
        }
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}
void SNM(ListP LP, ListN LN) {
    if (first(LP)==NULL && first(LN)==NULL) {
        cout<<"List is empty"<<endl;
    } else {
        adrP P = first(LP);
        adrP Q;
        int Max = 0;
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
        cout<<"One of author who had written the most novel is "<<info(Q)<<endl;
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}
void SCA(ListN LN, ListP LP) {
    if (first(LP)==NULL && first(LN)==NULL) {
        cout<<"List is empty"<<endl;
    } else {
        adrP P = first(LP);
        cout<<" Author who doesn't collaborate: "<<endl;
        while (P!=NULL) {
            int i = 0;
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
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}

void showPN(ListP LP, ListN LN) {
    if (first(LP)==NULL && first(LN)==NULL) {
        cout<<"List is empty"<<endl;
    } else {
        adrP P = first(LP);
        cout<<"Registered author:"<<endl;
        while (P != NULL) {
            cout << "Author: " << info(P) << endl;
            adrR Q = firstR(P);
            if (Q != NULL) {
                while (Q != NULL) {
                    cout<<"--> Novel: "<<infoR(Q)<<endl;
                    Q = nextR(Q);
                }
                cout<<endl;
            } else {
                cout<<"Novel not found."<<endl;
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
    if (first(LP)==NULL && first(LN)==NULL) {
        cout<<"List is empty"<<endl;
    } else {
        string penulis;
        cout<<"Type author's name: ";
        cin>>penulis;
        adrP p = findP(LP, penulis);
        if (p!=NULL) {
            cout<<"Novel that written by "<<info(p)<<", is:"<<endl;
            adrR r = firstR(p);
            while (r!=NULL) {
                cout<<"- "<<infoR(r)<<endl;
                r=nextR(r);
            }
        } else {
            cout<<"Author not found"<<endl;
        }
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}
void manual(ListP LP, ListN LN) {
    cout<<"1. Type 'stop' to stop registering/connecting."<<endl;
    cout<<"3. Type '13' to clear the screen."<<endl;
    cout<<"3. Type '14' to close the program."<<endl;
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}

void menu(ListP &LP, ListN &LN) {
    int x;

    adrP P;
    adrN N;
    adrR R;

    cout<<"Program's Feature: "<<endl;
	cout<<"1. Add Author"<<"                                  "<<"7. Show Novel Written by 2 Author"<<endl;
	cout<<"2. Add Novel"<<"                                   "<<"8. Show Author Who Wrote The Most"<<endl;
	cout<<"3. Connecting"<<"                                  "<<"9. Show Independent Author"<<endl;
	cout<<"4. Delete Author "<<"                              "<<"10. Show All Authors and Novels"<<endl;
	cout<<"5. Delete Novel"<<"                                "<<"11. Show All Novels and Authors"<<endl;
	cout<<"6. Show Novel With Particular Author"<<"           "<<"12. Manual"<<endl;

	cout<<endl;
	cout<<"Choose feature: ";
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
        SPN(LN, LP);
	} else if (x==7) {
        SNW(LN, LP);
	} else if (x==8) {
        SNM(LP, LN);
	} else if (x==9) {
        SCA(LN, LP);
	} else if (x==10) {
        showPN(LP, LN);
    } else if (x==11) {
        SNP(LN, LP);
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
