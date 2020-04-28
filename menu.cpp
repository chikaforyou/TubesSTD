#include "Novel.h"
#include "penulis.h"
#include "menu.h"

void AA(ListP &LP, adrP P, ListN LN) {
    string nama;
    bool f = false;
    cout<<"--------------------------------------"<<endl;
    cout<<"          Menambahkan penulis"<<endl;
    cout<<"--------------------------------------"<<endl;
    showP(LP);
    cout<<"Ketik nama penulis:"<<endl;
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
    cout<<"          Menambahkan Novel"<<endl;
    cout<<"--------------------------------------"<<endl;
    showN(LN);
    cout<<"Ketik judul novel:"<<endl;
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
    cout<<"             Menghubungkan"<<endl;
    cout<<"--------------------------------------"<<endl;
    showP(LP);
    showN(LN);
    cout<<"Ketik nama penulis dan judul novel:"<<endl;
    while (!f) {
        cout<<"Nama penulis: ";
        cin>>nama;
        if (nama=="stop") {
            break;
        }
        adrP P = findP(LP, nama);

        cout<<"Judul novel: ";
        cin>>judul;
        adrN N = findN(LN, judul);

        if (P != NULL && N != NULL) {
            adrR f = findR(P, info(N));
            if (f != NULL) {
                cout<<"Gagal, penulis dan novel sudah terhubungkan."<<endl;
            } else {
                adrR R = createNewR(info(N));
                relasikan(P, R);
                cout<<"Terhubung."<<endl;
            }
        } else if (P == NULL && N != NULL) {
            cout<<"Gagal, penulis belum terdaftar."<<endl;
        } else if (P != NULL && N == NULL) {
            cout<<"Gagal, novel belum terdaftar."<<endl;
        } else {
            cout<<"Gagal,  penulis dan novel belum terdaftar."<<endl;
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
    cout<<"             Menghapus Penulis"<<endl;
    cout<<"--------------------------------------"<<endl;
    showP(LP);
    if (first(LP) != NULL) {
        cout<<"Ketik nama penulis: ";
        cin>>nama;
        if (nama != "stop") {
            P = findP(LP, nama);
            if (P != NULL) {
                deleteP(LP, P);
                cout<<endl<<"Penulis "<<nama<<" berhasil dihapus."<<endl;
                showP(LP);
            } else {
                cout<<"Gagal, Tidak dapat menemukan penulis."<<endl;
            }
        } else {
            cout<<endl;
            menu(LP, LN);
        }
    } else {
        cout<<"Tidak ada penulis yang dapat dihapus."<<endl;
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
    cout<<"             Menghapus Novel"<<endl;
    cout<<"--------------------------------------"<<endl;
    showN(LN);
    if (first(LN) != NULL) {
        cout<<"Ketik judul novel: ";
        cin>>judul;
        if (judul != "stop") {
            N = findN(LN, judul);
            if (N != NULL) {
                infoR(R) = info(N);
                deleteR(LP, R);
                deleteN(LN, N);
                cout<<"Novel "<<judul<<" berhasil dihapus."<<endl;
                showN(LN);
            } else {
                cout<<"Gagal, tidak dapat menemukan novel."<<endl;
            }
        } else {
            cout<<endl;
            menu(LP, LN);
        }
    } else {
        cout<<"Tidak ada novel yang dapat dihapus."<<endl;
        cout<<endl;
        menu(LP, LN);
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}

void SNP(ListN LN, ListP LP){
    cout<<"----------------------------------------------"<<endl;
    cout<<" Memperlihatkan Novel dengan Penulis Tertentu"<<endl;
    cout<<"----------------------------------------------"<<endl;
    if (first(LP)==NULL && first(LN)==NULL) {
        cout<<"List kosong."<<endl;
    } else {
        adrN N = first(LN);
        if(N!=NULL) {
            while (N!=NULL) {
                bool f = false;
                cout<<"Novel "<<info(N)<<" ditulis oleh: "<<endl;
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
                        cout<<"Tidak diketahui"<<endl;
                    }
                    N=next(N);
                } else {
                    cout<<"Tidak dapat menemukan penulis."<<endl;
                }
            }
        } else {
            cout<<"Belum ada novel yang terdaftar."<<endl;
        }
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}

void SNW(ListN LN, ListP LP) {
    cout<<"----------------------------------------------------"<<endl;
    cout<<"  Memperlihatkan Novel yang Ditulis Oleh 2 Penulis"<<endl;
    cout<<"----------------------------------------------------"<<endl;
    if (first(LP)==NULL && first(LN)==NULL) {
        cout<<"List kosong."<<endl;
    } else {
        adrN N = first(LN);
        if (N!= NULL) {
            cout<<"Novel yang ditulis oleh 2 penulis: "<<endl;
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
                cout<<"Tidak ada novel yang ditulis oleh 2 penulis."<<endl;
            }
        } else {
            cout<<"Belum ada novel yang terdaftar"<<endl;
        }
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}

void SNM(ListP LP, ListN LN) {
    cout<<"---------------------------------------------------------"<<endl;
    cout<<" Memperlihatkan Penulis yang Paling Banyak Menulis Novel"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    if (first(LP)==NULL && first(LN)==NULL) {
        cout<<"List kosong"<<endl;
    } else {
        adrP P = first(LP);
        if (P!=NULL) {
            int Max = 0;
            cout<<"Penulis yang paling banyak menulis novel, yaitu: "<<endl;
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
                    cout<<"- "<<info(P)<<" menulis "<<Max<<" novel"<<endl;
                }
                P=next(P);
            }
        } else {
            cout<<"Tidak dapat menemukan penulis."<<endl;
        }
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}

void SCA(ListN LN, ListP LP) {
    cout<<"--------------------------------------------------------"<<endl;
    cout<<" Memperlihatkan Penulis yang Tidak Pernah Berkolaborasi"<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    if (first(LP)==NULL && first(LN)==NULL) {
        cout<<"List kosong."<<endl;
    } else {
        adrP P = first(LP);
        if (P!=NULL) {
            int i;
            cout<<"Penulis yang tidak pernah berkolaborasi: "<<endl;
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
                cout<<"Tidak ada penulis yang tidak pernah berkolaborasi."<<endl;
            }
        } else {
            cout<<"Tidak dapat menemukan penulis"<<endl;
        }
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}

void MemperlihatkanPN(ListP LP, ListN LN) {
    cout<<"----------------------------------------"<<endl;
    cout<<" Memperlihatkan Semua Penulis dan Novel"<<endl;
    cout<<"----------------------------------------"<<endl;
    if (first(LP)==NULL && first(LN)==NULL) {
        cout<<"List kosong."<<endl;
    } else {
        adrP P = first(LP);
        if (P!=NULL) {
            cout<<"Penulis yang terdaftar:"<<endl;
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
                    cout<<"Tidak dapat menemukan novel."<<endl;
                    cout<<endl;
                }
                P = next(P);
            }
        } else {
            cout<<"Tidak dapat menemukan penulis"<<endl;
        }
    }
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}

void SPN (ListN LN, ListP LP) {
    cout<<"----------------------------------------"<<endl;
    cout<<" Memperlihatkan Semua Novel dan Penulis"<<endl;
    cout<<"----------------------------------------"<<endl;
    if (first(LP)==NULL && first(LN)==NULL) {
        cout<<"List kosong."<<endl;
    } else {
        string penulis;
        cout<<"Ketik nama penulis: ";
        cin>>penulis;
        adrP p = findP(LP, penulis);
        if (p!=NULL) {
            cout<<"Novel yang ditulis oleh "<<info(p)<<" adalah:"<<endl;
            adrR r = firstR(p);
            if (r!=NULL) {
                while (r!=NULL) {
                    cout<<"- "<<infoR(r)<<endl;
                    r=nextR(r);
                }
            } else {
                cout<<"Tidak dapat menemukan novel"<<endl;
            }
        } else {
            cout<<"Tidak dapat menemukan penulis."<<endl;
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
    cout<<"1. Ketik 'stop' untuk berhenti memberi inputan."<<endl;
    cout<<"3. Ketik '13' untuk membersihkan tampilan."<<endl;
    cout<<"3. Ketik '14' untuk menutup program."<<endl;
    cout<<endl;
    cout<<"______________________________________"<<endl;
    menu(LP, LN);
}

void menu(ListP &LP, ListN &LN) {
    int x;

    adrP P;
    adrN N;
    adrR R;

    cout<<"Menu Program: "<<endl;
	cout<<"1. Menambahkan Penulis"<<"                                 "<<"7.  Memperlihatkan Novel yang Ditulis Oleh 2 Penulis"<<endl;
	cout<<"2. Menambahkan Novel"<<"                                   "<<"8.  Memperlihatkan Penulis yang Paling Banyak Menulis Novel"<<endl;
	cout<<"3. Menyambungkan"<<"                                       "<<"9.  Memperlihatkan Penulis yang Tidak Pernah Berkolaborasi"<<endl;
	cout<<"4. Menghapus Penulis "<<"                                  "<<"10. Memperlihatkan Semua Penulis dan Novel"<<endl;
	cout<<"5. Menghapus Novel"<<"                                     "<<"11. Memperlihatkan Semua Novel dan Penulis"<<endl;
	cout<<"6. Memperlihatkan Novel dengan Penulis Tertentu"<<"        "<<"12. Manual"<<endl;

	cout<<endl;
	cout<<"Pilih Menu: ";
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
        MemperlihatkanPN(LP, LN);
    } else if (x==11) {
        SNP(LN, LP);
    } else if (x==12) {
        manual(LP, LN);
    } else if (x==13) {
        system("CLS");
        cout<<"Terbersihkan"<<endl;
        cout<<endl;
        system("pause");
        cout<<endl;
        menu(LP, LN);
	} else if (x==14) {
        cout<<"Menutup Program"<<endl;
	} else {
        cout<<"Menu tidak ditemukan, Coba lagi!"<<endl;
        menu(LP, LN);
	}
}
