#include "Novel.h"
#include "penulis.h"
#include "menu.h"

void AA(ListP &LP, adrP P, ListN LN) {
    string nama;
    bool f = false;
    cout<<"--------------------------------------"<<endl;
    cout<<"             Add Author"<<endl;
    cout<<"--------------------------------------"<<endl;
    showP(LP);
    cout<<"Type the name of Author:"<<endl;
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
    cout<<"Type the title of Novel:"<<endl;
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
    cout<<"Type the name of Author and the title of Novel:"<<endl;
    while (!f) {
        cout<<"The name of Author: ";
        cin>>nama;
        if (nama=="stop") {
            break;
        }
        adrP P = findP(LP, nama);

        cout<<"The title of Novel: ";
        cin>>judul;
        adrN N = findN(LN, judul);

        if (P != NULL && N != NULL) {
            adrR f = findR(P, info(N));
            if (f != NULL) {
                cout<<"Failed, the Author and the Novel has been connected."<<endl;
            } else {
                adrR R = createNewR(info(N));
                relasikan(P, R);
                cout<<"Connected."<<endl;
            }
        } else if (P == NULL && N != NULL) {
            cout<<"Failed, the Author hasn't been registered."<<endl;
        } else if (P != NULL && N == NULL) {
            cout<<"Failed, the Novel hasn't been registered."<<endl;
        } else {
            cout<<"Failed, the Author and the Novel haven't been registered."<<endl;
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
        cout<<"Type the name of Author: ";
        cin>>nama;
        if (nama != "stop") {
            P = findP(LP, nama);
            if (P != NULL) {
                deleteP(LP, P);
                cout<<endl<<"Author "<<nama<<" has been deleted."<<endl;
                showP(LP);
            } else {
                cout<<"Failed, the Author could not be found."<<endl;
            }
        } else {
            cout<<endl;
            menu(LP, LN);
        }
    } else {
        cout<<"No Authors could be deleted."<<endl;
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
        cout<<"Type the title of Novel: ";
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
                cout<<"Failed, the Novel could not be found."<<endl;
            }
        } else {
            cout<<endl;
            menu(LP, LN);
        }
    } else {
        cout<<"No Novels could be deleted."<<endl;
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
        if(N!=NULL) {
            while (N!=NULL) {
                bool f = false;
                cout<<"Novel "<<info(N)<<" written by: "<<endl;
                adrP P = first(LP);
                if (P!=NULL) {
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
                } else {
                    cout<<"Could not find any Author."<<endl;
                }
            }
        } else {
            cout<<"Could not found any Novel."<<endl;
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
        adrN N = first(LN);
        if (N!= NULL) {
            cout<<"Novel(s) Written by 2 Authors: "<<endl;
            bool f = false;
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
                cout<<"There are no Novels written by 2 Authors."<<endl;
            }
        } else {
            cout<<"Could not found any Novel"<<endl;
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
        if (P!=NULL) {
            int Max = 0;
            cout<<"Author(s) who wrote Novel the most is/are: "<<endl;
            while (P!=NULL) {
                int i = 0;
                adrR R = firstR(P);
                while (R!=NULL) {
                    i++;
                    R=nextR(R);
                }
                if (Max<i){
                    Max = i;
                }
                P=next(P);
            }
            P = first(LP);
            while (P!=NULL) {
                int i = 0;
                adrR R = firstR(P);
                while (R!=NULL) {
                    i++;
                    R=nextR(R);
                }
                if (Max==i) {
                    cout<<"- "<<info(P)<<" wrote "<<Max<<" Novel(s)"<<endl;
                }
                P=next(P);
            }
        } else {
            cout<<"Could not found any Author."<<endl;
        }
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
        if (P!=NULL) {
            int i;
            cout<<"Author who never collaborate: "<<endl;
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
                cout<<"No Authors has never collaborated."<<endl;
            }
        } else {
            cout<<"Could not found any Author"<<endl;
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
        if (P!=NULL) {
            cout<<"Registered Author:"<<endl;
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
                    cout<<"Novel could not be found."<<endl;
                    cout<<endl;
                }
                P = next(P);
            }
        } else {
            cout<<"Could not found any Author"<<endl;
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
        cout<<"Type the name of Author: ";
        cin>>penulis;
        adrP p = findP(LP, penulis);
        if (p!=NULL) {
            cout<<"Novel(s) that written by "<<info(p)<<" is/are:"<<endl;
            adrR r = firstR(p);
            if (r!=NULL) {
                while (r!=NULL) {
                    cout<<"- "<<infoR(r)<<endl;
                    r=nextR(r);
                }
            } else {
                cout<<"Novel of The Author could not be found"<<endl;
            }
        } else {
            cout<<"The Author could not be found."<<endl;
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
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}

void menu(ListP &LP, ListN &LN) {
    int x;

    adrP P;
    adrN N;
    adrR R;

    cout<<"Program's Features: "<<endl;
	cout<<"1. Add Author"<<"                                  "<<"7.  Show Novel(s) Written by 2 Authors"<<endl;
	cout<<"2. Add Novel"<<"                                   "<<"8.  Show Author(s) Who Wrote The Most"<<endl;
	cout<<"3. Connecting"<<"                                  "<<"9.  Show Author(s) Who Never Collaborate"<<endl;
	cout<<"4. Delete Author "<<"                              "<<"10. Show All Authors and Novels"<<endl;
	cout<<"5. Delete Novel"<<"                                "<<"11. Show All Novels and Authors"<<endl;
	cout<<"6. Show Novel(s) With Particular Author"<<"        "<<"12. Manual"<<endl;

	cout<<endl;
	cout<<"Choose a feature: ";
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
