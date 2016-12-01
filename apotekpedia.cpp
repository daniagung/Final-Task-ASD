//
// Created by Dani Agung Prastiyo on 20/11/2016.
// Created by Hermawan wiwid

#include "apotekpedia.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <cstdio>
#include <sstream>

using namespace std;

//----------------- Fungsi dan Prosedur Default ----------------//


//----------------- Create ----------------//

void createListAPK(apotek &R) {
    first(R)= NULL;
    last(R)= NULL;
}

void createAPK(infotypeAPK &APK) {

    cout<<"== Input Apotek Baru =="<<endl;
    cout<<"Input ID APK        : "; getline(cin, APK.idAPK);
    cout<<"Nama Apotek   : "; getline(cin, APK.namaAPK);
    cout<<"Alamat Apotek : "; getline(cin, APK.alamat);
    time_t now = time(0);
    string dt = ctime(&now);
    cout<<"Tanggal Input      : "<<dt;
    APK.tanggal=dt;
}

void createObat(infotypeObat &ObatAPK) {
    cout<<"== Input Obat Baru =="<<endl;
    cout<<"Input ID Obat : "; getline(cin, ObatAPK.idObat);
    cout<<"Nama Obat     : "; getline(cin, ObatAPK.namaObat);
    cout<<"Jenis Obat    : "; getline(cin, ObatAPK.jenisObat);
    cout<<"Stock Obat    : "; getline (cin, ObatAPK.stock);
    cout<<"Kadaluarsa    : "; getline(cin, ObatAPK.kadaluarsa);
    cout<<"Harga (NUM)   : "; cin>>ObatAPK.hargaObat; cin.ignore();

    cout<<endl;
}

//----------------- Address ----------------//

addressAPK alokasiAPK(infotypeAPK APK) {
    addressAPK P;
    P = new elmAPK;
    info(P) = APK;
    next(P) = NULL;
    prev(P) = NULL;
    P->daftarObat = NULL;
    return P;
}

addressObat alokasiObat(infotypeObat ObatAPK) {
    addressObat Q = new elmObat;
    Q->info = ObatAPK;
    Q->next = NULL;
    return Q;
}

addressAPK findElmAPK(apotek R, string idAPK) {
    addressAPK P;
    if(first(R) == NULL)
    {
        return NULL;
    }
    else
    {
        bool ketemu = false;
        P = first(R);
        while ((info(P).idAPK != idAPK) && (ketemu == false))
        {
            if (next(P) == NULL) {
                ketemu = true;
            }
            else {
                P = next(P);
            }
        }
        if (ketemu)
            return NULL;
        else
            return P;
    }
}

addressObat findElmObat(addressAPK PAPK, string idObat){
    addressObat M;
    M = PAPK->daftarObat;
    if (M==NULL)
        return NULL;
    else{
        while (M != NULL){
            if (M->info.idObat == idObat){
                return M;
            }
            M = M -> next;
        }
        return M;
    }
}

//----------------- View ----------------//

void printInfoAPK(apotek APK){
    addressAPK P;
    P = APK.first;
    if(APK.first == NULL)
        cout<<"Tidak ada Apotek yang terdaftar"<<endl;
    else{
        cout<<"========== List Apotek yang Tersedia =========="<<endl;
        int i = 1;
        while(P != NULL){

            cout<<"Data Apotek Ke-"<<i<<endl; i++;
            cout<<"ID Apotek            : "<<P->info.idAPK<<endl;
            cout<<"Nama Apotek          : "<<P->info.namaAPK<<endl;
            cout<<"Alamat Apotek        : "<<P->info.alamat<<endl;
            cout<<"TGL Pendataan Apotek : "<<P->info.tanggal<<endl;
            cout<<endl;
            P = P->next;
        }
    }
}

void printInfoObat(apotek APK){
    addressAPK P;
    addressObat Q;
    P = APK.first;
    if(APK.first == NULL)
        cout<<"Tidak Ada Apotek Terdaftar"<<endl;
    else {
        cout<<"==== Data Apotek beserta Obatnya ===="<<endl;
        cout<<endl;
        int i = 1;
        while(P != NULL){
            cout<<"--- Data Apotek ke-"<<i<< " ---"<<endl; i++;
            cout<<"ID Apotek    : "<<P->info.idAPK<<endl;
            cout<<"Nama Apotek  : "<<P->info.namaAPK<<endl;
            Q = P->daftarObat;
            if(Q==NULL){
                cout<<"====== Obat Kosong ======"<<endl;
            }else{
                cout<<"\n====== List Obat ======"<<endl;
            }
            while(Q != NULL){
                cout<<"ID Obat      : "<<Q->info.idObat<<endl;
                cout<<"Nama Obat    : "<<Q->info.namaObat<<endl;
                cout<<"Jenis Obat   : "<<Q->info.jenisObat<<endl;
                cout<<"Harga Obat   : "<<Q->info.hargaObat<<endl;
                cout<<"Stock Obat   : "<<Q->info.stock<<endl;
                cout<<"Kadaluarsa   : "<<Q->info.kadaluarsa<<endl;
                cout<<endl;
                Q = Q->next;
            }
//            cout<<Q<<endl;
            cout<<endl;
            P = P->next;
        }
    }
}
//
//    addressAPK P;
//    addressObat S;
//    if(APK.first == NULL)
//        cout<<"Tidak ada Obat yang Terdaftar"<<endl;
//    else{
//        cout<<"===== Data Apotek beserta Obatnya ====="<<endl;
//        cout<<endl;
//        int i = 1;
//        while (P != NULL){
//            cout<<"Data Apotek Ke-"<<i<<endl; i++;
//            cout<<"ID Apotek            : "<<P->info.idAPK<<endl;
//            cout<<"Nama Apotek          : "<<P->info.namaAPK<<endl;
//            S = P->daftarObat;
//            if(S==NULL){
//                cout<<"Obat Kosong"<<endl;
//            } else{
//                cout<<"==== List Obat ===="<<endl;
//            }
//            while (S != NULL){
//                cout<<"ID Obat      : "<<S->info.idObat<<endl;
//                cout<<"Nama Obat    : "<<S->info.namaObat<<endl;
//                cout<<"Jenis Obat   : "<<S->info.jenisObat<<endl;
//                cout<<"Harga Obat   : "<<S->info.hargaObat<<endl;
//                cout<<"Stock Obat   : "<<S->info.stock<<endl;
//                cout<<"Kadaluarsa   : "<<S->info.kadaluarsa<<endl;
//                cout<<endl;
//                S = S->next;
//            }
//            cout<<endl;
//            P = P->next;
//        }
//    }
//}

//----------------- Editing ----------------//

void editInfoAPK(apotek &APK){
    if(APK.first != NULL){ //Cek Apotek Apakah Kosong atau Tidak
        printInfoAPK(APK);
        string strSearchAPK;
        cout << "Masukkan ID Apotek yang mau di Edit : ";cin>>strSearchAPK; cin.ignore();
        addressAPK PAPK = findElmAPK(APK, strSearchAPK); //Mencari Elemen Apotek
        if(PAPK == NULL){
            cout<<"ID apotek Tidak Ditemukan"<<endl;
            cout<<endl;
        } else {
            cout<<"ID APK Ditemukan"<<endl;
            cout<<"Edit Nama APK : "; getline(cin, PAPK->info.namaAPK);
            cout<<"Edit Alamat APK : "; getline(cin, PAPK->info.alamat);
            cout<<"Edit Successfull"<<endl;
            cout<<endl;
        }
    } else {
        cout<<"Tidak ada Apotek yang bisa di edit (Kosong) "<<endl;
    }
}

void editHargaObat(apotek &APK) {
    if(APK.first == NULL)
        cout<<"Tidak ada Apotek yang Terdata (Kosong)"<<endl;
    else {
        printInfoAPK(APK);
        string strSearchID;
        string strSearchIDObat;
        cout << "Masukkan ID Apotek Yang Akan Diubah Harga Obatnya : ";getline(cin, strSearchID);
        addressAPK PAPK = findElmAPK(APK, strSearchID);
        if (PAPK == NULL) {
            cout << "Tidak Ditemukan Apotek";
        }
        else {
            addressObat M = PAPK->daftarObat;
            cout << "List Obat APK - "<<PAPK->info.namaAPK<<endl;
            while (M != NULL){ // Looping Untuk Menampilkan Obat Apotek
                cout<<"ID Obat    : "<<M->info.idObat<<endl;
                cout<<"Nama Obat  : "<<M->info.namaObat<<endl;
                cout <<"Jenis Obat   : "<<M->info.jenisObat<<endl;
                cout <<"Harga Obat   : "<<M->info.hargaObat<<endl;
                cout <<"Stock Obat   : "<<M->info.stock<<endl;
                cout<<endl;
                M = M->next;
            }
            cout << endl;
            cout << "Masukkan ID Obat Yang Harganya Akan Diubah : ";getline(cin, strSearchIDObat);
            M = PAPK->daftarObat;
            while (M != NULL) {
                if (M->info.idObat == strSearchIDObat) {
                    break;
                }
                else {
                    M = M->next;
                }
            }
            if (M == NULL) {
                cout << "Tidak Ada Obat Yang Sesuai"<<endl;
            }
            else {
                cout << "Obat Ditemukan"<<endl;
                cout << "Nama Obat : "<<M->info.namaObat<<endl;
                cout << "Masukkan Harga Baru : ";cin>>M->info.hargaObat;
                cout << endl;
                cout << "Harga Berhasil Diubah"<<endl;
            }
        }
    }
}



//    //
//    if(APK.first != NULL){ //mengecek apakah apotek kosong
//        printInfoAPK(APK);
//        string strSearchAPK;
//        cout<<"Masukkan ID Apotek yang mau di Edit: "<<endl;
//        addressAPK PAPK = findElmAPK(APK, strSearchAPK);
//        if(PAPK == NULL){
//            cout<<"ID Apotek tidak ditemukan"<<endl;
//            cout<<endl;
//        }else {
//            cout<<"ID Apotek ditemukan"<<endl;
//            cout<<"Edit Nama Apotek: ";getline(cin, PAPK->info.namaAPK);
//            cout<<"Edit Alamat Apotek : ";getline(cin, PAPK->info.alamat);
//            cout<<"Data Berhasil di Edit"<<endl;
//            cout<<endl;
//        }
//    }else {
//    }   cout<<"Tidak ada Apotek yang bisa di edit (Kosong)"<<endl;
//}
//
//void editHargaObat(apotek &APK){
//    if(APK.first == NULL)
//        cout<<"Tidak ada Obat yang Terdata(Kosong)"<<endl;
//    else{
//        printInfoAPK(APK);
//        string searchByIDAPK;
//        string searchByObat;
//        cout<<"Masukkan ID Apotek yang Akan di Edit Harga Obatnya : ";getline(cin, searchByIDAPK);
//        addressAPK PAPK = findElmAPK (APK, searchByObat);
//        if (PAPK == NULL){
//            cout<<"Tidak Ditemukan Apotek";
//        }
//        else{
//            addressObat M= PAPK->daftarObat;
//            cout <<"List Obat APK - "<<PAPK->info.namaAPK<<endl;
//            while (M != NULL){ //Looping untuk menampilkan Obat Apotek
//                cout <<"ID Obat      : "<<M->info.idObat<<endl;
//                cout <<"Nama Obat    : "<<M->info.namaObat<<endl;
//                cout <<"Jenis Obat   : "<<M->info.jenisObat<<endl;
//                cout <<"Harga Obat   : "<<M->info.hargaObat<<endl;
//                cout <<"Stock Obat   : "<<M->info.stock<<endl;
//                cout <<"Kadaluarsa   : "<<M->info.kadaluarsa<<endl;
//                cout <<endl;
//                M = M->next;
//            }
//            cout <<endl;
//            cout <<"Masukkan ID Obat yang Harganya Akan Diubah : "; getline(cin, searchByObat);
//            M = PAPK->daftarObat;
//            while (M != NULL){
//                if (M->info.idObat == searchByObat){
//                    break;
//                }
//                else{
//                    M = M->next;
//                }
//            }
//            if (M == NULL){
//                cout <<"Tidak ada Obat yang Sesuai"<<endl; //Jika ID obat tidak sesuai
//            }
//            else{
//                cout <<"Obat Ditemukan"<<endl;
//                cout <<"Nama Obat : "<<M->info.hargaObat;
//                cout <<"Masukkan Harga Baru : ";cin>>M->info.hargaObat;
//                cout <<endl;
//                cout <<"Harga Berhasil Diubah"<<endl;
//            }
//        }
//    }
//}

//----------------- Seacrhing ----------------//

void searchAPK(apotek APK){
    if (APK.first == NULL)
        cout <<"Tidak Ada Data Apotek"<<endl;
    else{
        string strSearch;
        cout <<"Masukkan ID / Nama APK yang akan dicari : "; getline(cin, strSearch);
        addressAPK P = APK.first;
        while (P != NULL){
            if((P->info.idAPK == strSearch) || (P->info.namaAPK == strSearch))
                break;
            else
                P = P->next;
        }
        if (P==NULL){
            cout <<"Tidak ada Data yang Sesuai"<<endl;
            cout <<endl;
        }else{
            cout <<"Data Ditemukan"<<endl;
            cout <<"ID Apotek            : "<<P->info.idAPK<<endl;
            cout <<"Nama Apotek          : "<<P->info.namaAPK<<endl;
            cout <<"Alamat Apotek        : "<<P->info.alamat<<endl;
            cout<<"TGL Pendataan Apotek : "<<P->info.tanggal<<endl;
        }
    }
}

void searchObat(apotek APK) {
    if (APK.first == NULL)
        cout << "Tidak ada Data Apotek" << endl;
    else {
        string strSearch;
        cout << "Masukkan ID / Nama Obat yang akan dicari : ";
        getline(cin, strSearch);
        addressAPK P = APK.first;
        addressObat Q;
        bool checkFound = false;
        while (P != NULL) {
            Q = P->daftarObat;
            while (Q != NULL) {
                if ((Q->info.idObat == strSearch) || (Q->info.namaObat == strSearch)) {
                    checkFound = true;
                    break;
                }
                Q = Q->next;
            }
            if (checkFound)
                break;
            P = P->next;
        }
        if (Q == NULL) {
            cout << "Tidak ada Data yang Sesuai" << endl;
            cout << endl;
        } else {
            cout << "Data Ditemukan" << endl;
            cout << "ID Obat      : " << Q->info.idObat << endl;
            cout << "Nama Obat    : " << Q->info.namaObat << endl;
            cout << "Jenis Obat   : " << Q->info.jenisObat << endl;
            cout << "Harga Obat   : " << Q->info.hargaObat << endl;
            cout << "Stock Obat   : " << Q->info.stock << endl;
            cout << "Kadaluarsa   : " << Q->info.kadaluarsa << endl;
            cout << "Terdapat di Apotek : " << P->info.namaAPK << endl;
            cout << endl;
        }
    }
}

//----------------- Insert Obat ----------------//
void insertObatFirst(addressAPK PAPK, infotypeObat addObat){
    if (PAPK == NULL){
        cout <<"Tidak Ditemukan Apotek";
    }
    else{
        addressObat M = alokasiObat(addObat);
        if (PAPK->daftarObat == NULL){
            PAPK->daftarObat = M;
        }
        else {
            M->next = PAPK->daftarObat;
            PAPK->daftarObat = M;
        }
    }
}


void insertObatLast(addressAPK PAPK, infotypeObat addObat){
    if (PAPK == NULL){
        cout <<"Tidak Ditemukan Apotek";
    }
    else {
        addressObat P;
        P = PAPK->daftarObat;
        addressObat M = alokasiObat(addObat);
        if (P == NULL){
            insertObatFirst(PAPK, addObat);

        } else {
            while (P->next != NULL){
                P = P->next;
            }
            P->next = M;
        }
    }
}


void insertObatAfter(addressAPK PAPK, infotypeObat addObat){
    string searchIDObat;
    addressObat M = PAPK->daftarObat;
    if (M == NULL) {
        cout << "karena tidak ada Obat yang Tersedia, maka langsung dimasukkan ke Awal List" <<endl;
        insertObatFirst(PAPK, addObat);
    }
    else {
        cout << "List Obat Apotek - "<<PAPK->info.namaAPK<<endl;
        while (M != NULL){
            //looping untuk menampilkan obat apotek
            cout << "Data Ditemukan" << endl;
            cout << "ID Obat      : " << M->info.idObat << endl;
            cout << "Nama Obat    : " << M->info.namaObat << endl;
            cout << "Jenis Obat   : " << M->info.jenisObat << endl;
            cout << "Harga Obat   : " << M->info.hargaObat << endl;
            cout << "Stock Obat   : " << M->info.stock << endl;
            cout << "Kadaluarsa   : " << M->info.kadaluarsa << endl;
            cout << endl;
            M = M->next;
        }
        cout <<endl;
        cout << "Masukkan ID Obat yang Ingin di Insert Sesudahnya: ";getline(cin, searchIDObat);
        M = findElmObat(PAPK,searchIDObat);
        if (M == NULL){
            cout<<"elemen ysng di insert sesudahnya tidak tersedia"<<endl;
        }
        else {
            addressObat addAPKSisip;
            addAPKSisip = alokasiObat(addObat);
            if (M->next == NULL){
                //Jika Elemen di Ujung
                insertObatLast(PAPK, addObat);
            } else {
                addAPKSisip->next = M->next;
                M->next = addAPKSisip;
            }
        }
    }
}


void addObatAPK(apotek &APK){
    if (APK.first == NULL){
        cout<<"Tidak Ada Apotek yang Terdaftar"<<endl;
    } else {
        string seacrhAPK;
        printInfoAPK(APK);
        cout<<"Masukkan ID Apotek yang akan ditambah Obat-nya: "; cin>>seacrhAPK; cin.ignore();
        addressAPK PAPK = findElmAPK(APK, seacrhAPK);
        if (PAPK == NULL){
            cout<<"Tidak Ditemukan Apotek";
        } else {
            infotypeObat addObat;
            createObat(addObat);
            char menu;
            cout<<endl;
            cout<<"Pilih Jenis Insert Yang Anda Suka: "<<endl
                <<"1. Insert First"<<endl
                <<"2. Insert Last"<<endl
                <<"3. Insert After"<<endl;
            ObatLabel :
            cout<<"Pilihan: ";cin>>menu; cin.ignore();
            switch (menu){
                case '1' : insertObatFirst(PAPK, addObat); break;
                case '2' : insertObatLast(PAPK,addObat); break;
                case '3' : insertObatAfter(PAPK,addObat); break;
                default  : cin.ignore(); goto ObatLabel;
            }
            cout<<"Data Berhasil di Insert"<<endl;
        }
    }
}

//----------------- Delete Apotek ----------------//

addressAPK deleteFirstAPK(apotek &APK){
    addressAPK P;
    if (first(APK) == NULL){
        return NULL;
    }
    else {
        P = first(APK);
        if ((first(APK) != NULL)&&(next(first(APK))==NULL)){
            first(APK) = NULL;
            last(APK) = NULL;
            return P;
        }
        else {
            prev(next(P)) = NULL;
            first(APK) = next(P);
            next(P) = NULL;
            return  P;
        }
    }
}

void deleteLastAPK(apotek &APK){
    addressAPK P;
    if (first(APK) == NULL){
        cout<<"Data Apotek tidak Tersedia"<<endl;
    } else {
        P = last(APK);
        if (prev(P) == NULL){
            first(APK) = NULL;
            last(APK) = NULL;
            delete P;
        } else {
            next(prev(P)) = NULL;
            last(APK) = prev(P);
            prev(P) = NULL;

        }
    }
}

void deleteAfterAPK(apotek &APK){
    addressAPK P;
    if (first(APK) = NULL){
        cout<<"Data Apotek Tidak ditemukan"<<endl;
    } else {
        string hapus;
        cout<<endl;
        printInfoAPK(APK);
        cout<<"Masukkan ID Apotek Sebelum Apotek di depan Yang akan dihapus : ";
        getline(cin, hapus);
        addressAPK R = findElmAPK(APK,hapus);
        if (R ->next == NULL){
            cout<<"ini adalah Elemen Terakhir"<<endl;
        } else {
            addressAPK P = R->next;
            if (P->next == NULL){ //elemen yang dihapus berada diujung
                R->next = NULL;
                P->prev = NULL;
                delete P;
            } else {
                //elemen yang dihapus di tenggah-tenggah
                R->next = P->next;
                P->prev->prev = R;
                P->next = NULL;
                P->prev = NULL;
                delete P;
            }
            cout<<"Delete Data Apotek Berhasih Yeah"<<endl;
        }
    }
}

void deleteAPKbyID(apotek &APK){
    string searchAPK;
    printInfoAPK(APK);
    cout<<"Masukkan ID Apotek Sebelum Apotek di depan Yang akan dihapus : "; getline(cin, searchAPK);
    addressAPK PAPK = findElmAPK(APK, searchAPK);
    if (PAPK == NULL){
        //ksus elemen tidak ditemukan
        cout<<"ID Apotek tidak ditemukan"<<endl;
    }
    else {
        if (APK.first->next == NULL){
            APK.first = NULL;
            APK.last = NULL;
            delete PAPK;
        }
        else if ((PAPK == APK.last) && (PAPK->next != NULL)){
            //Kasus elemen Yang di delete di elemen yang pertama
            deleteFirstAPK(APK);
        }
        else if ((PAPK == APK.last) && (PAPK->prev != NULL)){
            //Kasus Elemen yang di delete elemen terakhir
            deleteLastAPK(APK);
        }
        else if ((PAPK != APK.first) && (PAPK != APK.last) && (PAPK->next != NULL)){
            //kasus element di tenggah
            addressAPK P =PAPK->prev;
            PAPK->next = PAPK->next;
            PAPK->next->prev = P;
            PAPK->next = NULL;
            PAPK->prev = NULL;
            delete PAPK;
        }
        else
            cout<<"Tidak Dapat Di Delete"<<endl;

    }
}


void deleteAPKOption(apotek &APK){
    if(APK.first == NULL)
        cout<<"Tidak ada Data Apotek (Kosong)"<<endl;
    else {
        char menu;
        ObatLabel :
        cout << "Pilih Jenis Metode Delete"<<endl
             << "1. Pilih Delete First"<<endl
             << "2. Pilih Delete Last"<<endl
             << "3. Pilih Delete After"<<endl
             << "4. Pilih Delete By ID"<<endl
             << "5. Exit"<<endl;

        cout <<"Masukkan Pilihan : ";
        cin>>menu; cin.ignore();
        switch (menu){
            case '1' : deleteFirstAPK(APK); cout<<"Delete Data APK Berhasil"<<endl; break;
            case '2' : deleteLastAPK(APK); cout<<"Delete Data APK Berhasil"<<endl; break;
            case '3' : deleteAfterAPK(APK); cout<<"Delete Data APK Berhasil"<<endl; break;
            case '4' : deleteAPKbyID(APK); cout<<"Delete Data APK Berhasil"<<endl; break;
            default  : cin.ignore(); goto ObatLabel;
        }
        //obatAkhir;
    }
}

//----------------- Delete Obat ----------------//

void deleteObatFirst(apotek &APK){
    cout<<endl;
    printInfoAPK(APK);
    cout<<endl;
    string SearchByID;
    cout<<"Masukkan ID Apotek yang Akan Dihapus Obatnya: "; getline(cin,SearchByID);
    addressAPK PAPK = findElmAPK(APK, SearchByID);
    if (PAPK == NULL){
        cout<<"Tidak Ditemukan Apotek";
    }
    else {
        addressObat M = PAPK->daftarObat;
        if (M == NULL){
            cout<<"Tidak Terdapat Obat"<<endl;
        }
        else {
            if (M->next == NULL){
                PAPK->daftarObat = NULL;
                M = NULL;
                delete M;
            }
            else {
                PAPK->daftarObat = M->next;
                M->next = NULL;
                delete M;
            }
            cout<<"Obat Berhasil dihapus"<<endl;
        }
    }
}


void deleteObatLast(apotek &APK){
    cout<<endl;
    printInfoAPK(APK);
    cout<<endl;
    string SearchID;
    cout << "Masukkan Id Apotek yang akan dihapus Obatnya: "; getline(cin, SearchID);
    addressAPK PAPK = findElmAPK(APK, SearchID);
    if (PAPK == NULL) {
        cout <<"Tidak Ditemukan Apotek"<<endl;
    }
    else{
        addressObat M = PAPK->daftarObat;
        if (M == NULL){
            cout << "Obat Kosong Pada Apotek Tersebut"<<endl;
        }
        else {
            while (M->next != NULL){
                M = M->next;
            }
            addressObat N = PAPK->daftarObat;
            while (N->next->info.idObat != M->info.idObat){
                N = N->next;
            }
            N->next = NULL;
            delete M;
            cout <<"Obat Berhasil Dihapus"<<endl;
        }
    }
}


void deleteObatAfter(apotek &APK){
    cout<<endl;
    printInfoAPK(APK);
    cout<<endl;
    string searchByIDAPK;
    string SearchIDObat;
    cout << "Masukkan ID Apotek yang akan di hapus Obatnya: ";getline(cin, searchByIDAPK);
    addressAPK PAPK = findElmAPK(APK, searchByIDAPK);
    if (PAPK == NULL){
        cout<<"tidak Ditemukan Apotek"<<endl;
    }
    else {
        addressObat  M = PAPK->daftarObat;
        if (M == NULL){
            cout<<"Tidak Terdapat Obat"<<endl;
        }
        else {
            cout << "List Obat APK - "<<PAPK->info.namaAPK<<endl;
            while (M != NULL) {
                //Loping untuk menapilkan Obat Apotek
                cout << "Data Ditemukan" << endl;
                cout << "ID Obat      : " << M->info.idObat << endl;
                cout << "Nama Obat    : " << M->info.namaObat << endl;
                cout << "Jenis Obat   : " << M->info.jenisObat << endl;
                cout << "Harga Obat   : " << M->info.hargaObat << endl;
                cout << "Stock Obat   : " << M->info.stock << endl;
                cout << "Kadaluarsa   : " << M->info.kadaluarsa << endl;
                cout << endl;
                M = M->next;
            }
            cout <<endl;
            cout<< "Masukkan ID Obat Sebelum ID yang akan Dihapus : ";
            cin>> SearchIDObat; cin.ignore();
            M = findElmObat(PAPK, SearchIDObat);
            if ((M != PAPK->daftarObat) && (M->next == NULL)){
                //elemen yang di ujung ya
                cout<<"Tidak ada Obat lagi Setelah Obat ini"<<endl;
            }
            else if ((M == PAPK->daftarObat) && (M->next == NULL)) {
                // Jika Obat Tunggal
                cout<<"Obat Ini adalah Satu-satunya Obat Yang ada di Apotek"<<endl;
            }
            else{
                addressObat N = M->next;
                if (N->next == NULL ){
                    M->next = NULL;
                    delete N;
                }
                else {
                    M->next = N->next;
                    N->next = NULL;
                    delete  N;
                }
                cout << "Obat Berhasil Dihapus"<<endl;
            }
        }
    }
}

void deleteObatByID(apotek &APK){
    string SearchIDAPK;
    string SearchIDObat;
    printInfoAPK(APK);
    cout <<"Masukkan ID Apotek yang akan dihapus Obatnya: "; getline(cin, SearchIDAPK);
    addressAPK  PAPK = findElmAPK(APK, SearchIDAPK); //mengambil keberadaan APK dimana
    if (PAPK == NULL){
        cout << "Tidak Ditemukan Apotek";
    }
    else {
        addressObat M = PAPK->daftarObat;
        if (M == NULL){
            cout << "Tidak Terdapat Obat Dalam Apotek Tersebut"<<endl;
        }
        else {
            cout << "List Obat APK - "<<PAPK->info.namaAPK<<endl;
            while (M != NULL){ //Looping untuk menamoikan Obat Apotek
                cout << "Data Ditemukan" << endl;
                cout << "ID Obat      : " << M->info.idObat << endl;
                cout << "Nama Obat    : " << M->info.namaObat << endl;
                cout << "Jenis Obat   : " << M->info.jenisObat << endl;
                cout << "Harga Obat   : " << M->info.hargaObat << endl;
                cout << "Stock Obat   : " << M->info.stock << endl;
                cout << "Kadaluarsa   : " << M->info.kadaluarsa << endl;
                cout << endl;
                M = M->next;
            }
            cout<<endl;
            cout<< "Masukkan ID Obat Yang Ingin Dihapus : "; getline(cin, SearchIDObat);
            //mencari ID Obat
            M = PAPK->daftarObat;
            while (M != NULL){
                //looping untuk posisi elemnt yang dihapus
                if (M->info.idObat == SearchIDObat){
                    break;
                }
                else{
                    M = M->next;
                }
            }
            if (M == NULL){
                cout <<"Tidak ada ID Obat yang sesuai"<<endl;
            }
            else{
                if (PAPK->daftarObat->next == NULL){
                    //jika terdapat satu obat
                    PAPK->daftarObat = NULL;
                    delete M;
                    cout << "Obat Berhasil Dihapus"<<endl;
                }

                else{ // Jika Terdapat Banyak Obat
                    if (M == PAPK->daftarObat){
                        //jika ada di awal list
                        addressObat  Q = PAPK->daftarObat;
                        while (Q->next != M){
                            Q = Q->next;
                        }
                        Q->next = NULL;
                        delete M;
                        cout<<"Obat Berhasil Dihapus"<<endl;
                    }
                    else if (M->next == NULL) {
                        addressObat Q = PAPK->daftarObat;
                        //jika berada di tenggah
                        while (Q->next != M){
                            Q = Q->next;
                        }
                        Q->next = M->next;
                        M->next = NULL;
                        delete M;
                        cout <<"Obat Berhasil Dihapus"<<endl;
                    }
                    else {
                        addressObat  Q = PAPK->daftarObat;
                        //Jika Berada di akhir
                        while (Q->next != M){
                            Q = Q->next;
                        }
                        Q->next = NULL;
                        delete M;
                        cout << "Obat Berhasil Dihapus"<<endl;

                    }
                }
            }
        }
    }
}

void deleteObatOption(apotek &APK){
    if (APK.first == NULL){
        cout<<"Tidak Terdapat Apotek"<<endl;
    }
    else {
        char menu;
        ObatAwal :
        cout << "Jenis Metode Delete Yang Ingin Dilakukan" << endl
             << "1. Pilih Delete First" << endl
             << "2. Pilih Delete Last" << endl
             << "3. Pilih Delete After" << endl
             << "4. Pilih Delete By ID" << endl
             << "5. Exit" << endl;

        cout << "Masukkan Pilihan : ";
        cin >> menu; cin.ignore();
        switch (menu) {
            case '1' :
                deleteObatFirst(APK);
                cout << "Delete Data APK Berhasil" << endl; break; goto ObatAwal;
            case '2' :
                deleteObatLast(APK);
                cout << "Delete Data APK Berhasil" << endl; break; goto ObatAwal;
            case '3' :
                deleteAfterAPK(APK);
                cout << "Delete Data APK Berhasil" << endl; break; goto ObatAwal;
            case '4' :
                deleteObatByID(APK);
                cout << "Delete Data APK Berhasil" << endl; break; goto ObatAwal;
            case '5' : goto ObatAkhir;
            default  : cin.ignore(); goto ObatAwal;
        }
        ObatAkhir :;
    }
}

//----------------- Inser Apotek Code By Hermawan Wiwid ----------------//

void insertFirstAPK(apotek &R, addressAPK P){
    if (first(R)== NULL){//kondisi ketika list kosong
        first(R) = P;
        last(R) = P;
    }
    else {
        P->next = R.first;
        R.first->prev =P;
        R.first = P;
    }
}


void insertLastAPK(apotek &R, addressAPK P){
    if(first(R) == NULL){
        //kondisi ketika list ksosong
        first(R) = P;
        last(R) = P;
    }
    else {
        prev(P) = last(R);
        next(prev(P)) = P;
        last(R) = P;
    }
}

void insertAfterAPK(apotek &R, addressAPK P){
    if (R.first == NULL){
        cout<<"karena Element Kosong maka Element langsung di insert di awal list"<<endl;
        insertFirstAPK(R, P);
    }
    else {
        string SearchByID;
        printInfoAPK(R);
        cout<<endl;
        cout<<"Masukkan ID APK yang ingin di Insert Sesudahnya: ";getline(cin, SearchByID);
        addressAPK PAPK;
        PAPK = findElmAPK(R, SearchByID);
        if (PAPK == NULL){
            cout<<"element yang akan di Insert Sesudahnya Tidak Tersedia"<<endl;
        }
        else {
            if (PAPK->next == NULL){
                insertLastAPK(R, P);
            }
            else {
                P->next = PAPK->next;
                P->prev = PAPK;
                PAPK->next->prev = P;
                PAPK->next = P;
            }
        }
    }
}


//----------------- Penambahan Insert Parent Apotek  ----------------//

void addapotek(apotek &R){
    infotypeAPK addAPK;
    createAPK(addAPK);
    addressAPK  PAPK;
    PAPK = alokasiAPK(addAPK);
    char menu;
    cout<<endl;
    cout<<"Pilih Jenis Insert : "<<endl
        <<"1. Insert First" <<endl
        <<"2. Insert Last" <<endl
        <<"3. Insert After" <<endl;
    ObatLabel :
    cout<<"Pilihan : "<<endl; cin>>menu; cin.ignore();
    switch (menu){
        case '1' : insertFirstAPK(R, PAPK); break;
        case '2' : insertLastAPK(R, PAPK); break;
        case '3' : insertAfterAPK(R, PAPK); break;
        default : cin.ignore(); goto ObatLabel;
    }
    cout <<"\nAlhamdulillah Data Berhasil Di Insert"<<endl;
}


//----------------- Penambahan Counter  ----------------//

void countTotalAPK(apotek APK){
    addressAPK PAPK;
    PAPK = APK.first;
    if (PAPK == NULL){
        cout<<"Total Apotek yang Terdata Tidak Ada Bro"<<endl;
    }
    else {
        int countNum = 0;
        while (PAPK != NULL) {
            countNum++;
            PAPK = PAPK->next;
        }
        cout << "Total APotek yang Tersedia Sekarang Adalah : " << countNum << "Apotek" << endl;
    }
}


void countTotalObat(apotek APK){
    if (APK.first == NULL)
        cout<<"Tidak ada Data Obat"<<endl;
    else {
        string SearchByIDAPK;
        string SearchByIDObat;
        printInfoAPK(APK);
        cout<<endl;
        cout<<"Masukkan ID Apotek yang akan dihitung Jumalah Jenis Obatnya : "; getline(cin, SearchByIDAPK);
        addressAPK PAPK = findElmAPK(APK, SearchByIDAPK);
        if (PAPK != NULL){
            int countNum = 0; //counter hitung
            addressObat M = PAPK->daftarObat;
            //looping hitung element
            while (M != NULL){
                countNum++;
                M = M->next;
            }
            cout<<endl;
            cout<<"Apotek : "<<PAPK->info.namaAPK<<" - Mempunyai "<<countNum<<" Obat"<<endl;
        }
        else {
            cout<<endl;
            cout<<"Tidak Terdapat ID Apotek"<<endl;
        }
    }
}

void menucountObat(apotek APK){
    char menu;
    cout<<"====== Pilih Element List Yang Mau Dihitung ======"<<endl
        <<"1. Apotek"<<endl
        <<"2.Obat Di Suatu Apotek"<<endl
        <<"3. Kembali Ke Menu Utama"<<endl;
    ObatLabel :
    cout<<"Pilihan : ";cin>>menu; cin.ignore();
    switch (menu){
        case '1' : countTotalAPK(APK); break;
        case '2' : countTotalObat(APK); break;
        case '3' : break;
        default  : goto ObatLabel;
    }
}


//----------------- Sorting Metode Merger Sort----------------//
//Source Code By :

int countLengthAPK(apotek APK){
    int countNum = 0;
    if(APK.first == NULL){
        return 0;
    } else {
        addressAPK PAPK;
        PAPK = APK.first;
        while(PAPK != NULL){
            countNum++;
            PAPK = PAPK->next;
        }
        return countNum;
    }
}

apotek mergeInAPK(apotek left, apotek right){
    //cout<<"ASASD"<<endl;
    //cout<<left.first.info->idAPK<<endl;
    //cout<<right.first<<endl;

    apotek resultList;
    createListAPK(resultList); //List Baru untuk Penampung Element Terurut
    addressAPK PAPK; //Address Buat Menampung data Pop untuk diinsert

    while((left.first != NULL) && (right.first != NULL)){ //Selama Salah Satu List Belum Habis
        if(left.first->info.idAPK <= right.first->info.idAPK){
            PAPK = deleteFirstAPK(left);
        } else {
            PAPK = deleteFirstAPK(right);
        }
        insertLastAPK(resultList,PAPK); //Memasukan Element yang di Pop dari Salah Satu List, (Right/Left)
    }

    // Jika terdapat sisa Element dari List dari Kiri / Kanan (Sisanya pasti terurut karena proses rekursif awal)
    while(left.first != NULL){
        PAPK = deleteFirstAPK(left);
        insertLastAPK(resultList,PAPK);
    }
    while(right.first != NULL){
        PAPK = deleteFirstAPK(right);
        insertLastAPK(resultList,PAPK);
    }
    return resultList;
}

apotek mergeSortAPK(apotek APK){
    int lengthList = countLengthAPK(APK);
    //cout<<lengthList<<endl;
    apotek tmpList; // Ini nantinya akan jadi representatif list Kiri
    createListAPK(tmpList);
    addressAPK PAPK;

    // Jika List Elemenya Satu Return List Tersebut
    if(lengthList <=1){
        return APK;
    }
    //
    int i = 0;
    while(i < lengthList/2){
        PAPK = deleteFirstAPK(APK);
        insertFirstAPK(tmpList,PAPK);
        i++;
    }

    // Recursively sort both sublists
    tmpList = mergeSortAPK(tmpList);
    APK = mergeSortAPK(APK);

    // Then merge the now-sorted sublists.
    return mergeInAPK(tmpList,APK);
}

void sortapotek(apotek &APK){ //Has been edited
    if(APK.first == NULL){
        cout<<"Tidak ada Data Apotek"<<endl;
    } else {
        APK = mergeSortAPK(APK);
        cout<<"========== SORT BERHASIL =========="<<endl;
        cout << endl;
        cout << "HASIL :"<<endl;
        cout << endl;
        printInfoAPK(APK);
    }
}




int countLengthObat(addressObat PAPK){
    int countNum = 0;
    if(PAPK == NULL){
        return 0;
    } else {
        addressObat M;
        M = PAPK;
        while(M != NULL){
            countNum++;
            M = M->next;
        }
        return countNum;
    }
}

addressObat deleteObatFirstMergeSort(addressObat &M){
    //cout<<M->info.namaObat<<endl;
    addressObat S, Q;
    S = new elmObat;
    S->info = M->info;
    S->next = NULL;
    Q = M;

    if (M == NULL) {
        cout << "Tidak Terdapat Obat"<<endl;
    }
    else {
        //cout<<M->next<<endl;
        if (M->next == NULL)
        {
            M = NULL;
            return S;
        }
        else
        {
            //cout<<Q->next->info.namaObat<<endl;
            M = Q->next;
            Q->next = NULL;
            return Q;
        }
    }
}

void insertObatFirstMergeSort(addressObat &PAPK, addressObat M) {
    if (PAPK == NULL) {
        PAPK = M;
    }
    else {
        M->next = PAPK;
        PAPK = M;
    }
}

void insertObatLastMergeSort(addressObat &PAPK, addressObat P) {
    addressObat Q = PAPK;
    if(Q == NULL){
        insertObatFirstMergeSort(PAPK,P);
    } else {
        while(Q->next != NULL){
            Q = Q->next;
        }
        Q->next = P;
    }
}

addressObat mergeInObat(addressObat left, addressObat right){
    //cout<<"ASASD"<<endl;
    //cout<<left.first.info->idAPK<<endl;
    //cout<<right.first<<endl;

    addressObat resultList;
    resultList = NULL; //List Baru untuk Penampung Element Terurut
    addressObat M; //Address Buat Menampung data Pop untuk diinsert

    while((left != NULL) && (right != NULL)){ //Selama Salah Satu List Belum Habis
        if(left->info.idObat <= right->info.idObat){
            M = deleteObatFirstMergeSort(left);
        } else {
            M = deleteObatFirstMergeSort(right);
        }
        insertObatLastMergeSort(resultList,M); //Memasukan Element yang di Pop dari Salah Satu List, (Right/Left)
        //cout<<"Z"<<endl;
    }

    // Jika terdapat sisa Element dari List dari Kiri / Kanan (Sisanya pasti terurut karena proses rekursif awal)
    while(left != NULL){
        M = deleteObatFirstMergeSort(left);
        insertObatLastMergeSort(resultList,M);
        //cout<<"y"<<endl;
    }
    while(right != NULL){
        M = deleteObatFirstMergeSort(right);
        insertObatLastMergeSort(resultList,M);
        //cout<<"x"<<endl;
    }
    return resultList;
}

addressObat mergeSortObat(addressObat PAPK){
    int lengthList = countLengthObat(PAPK);
    //cout<<lengthList<<endl;
    addressObat tmpList; // Ini nantinya akan jadi representatif list Kiri
    tmpList = NULL;
    addressObat M;

    // Jika List Elemenya Satu Return List Tersebut
    if(lengthList <=1){
        return PAPK;
    }
    //
    int i = 0;


    while(i < lengthList/2){
        M = deleteObatFirstMergeSort(PAPK);
        //cout<<tmpList<<endl;
        insertObatFirstMergeSort(tmpList,M);
        i++;
        //cout<<PAPK->daftarObat->info.namaObat<<endl;
        //cout<<tmpList->daftarObat->info.namaObat<<endl;
        //cout<<tmpList->daftarObat->info.namaObat<<endl;
    }

    //cout<<tmpList->info.idAPK<<endl;
    // Recursively sort both sublists
    tmpList = mergeSortObat(tmpList);
    //cout<<"X"<<endl;
    PAPK = mergeSortObat(PAPK);
    //cout<<"Y"<<endl;
    // Then merge the now-sorted sublists.
    return mergeInObat(tmpList,PAPK);
}

void sortObat(apotek &APK){
    if (APK.first == NULL)
    {
        cout << "Tidak Ada Apotek"<<endl;
    }
    else
    {
        string strSearchID;
        printInfoAPK(APK);
        cout << endl;
        cout << "Masukkan ID Apotek yang akan diSorting Obatnya: ";getline(cin, strSearchID);
        addressAPK PAPK = findElmAPK(APK, strSearchID);
        //cout<<PAPK->daftarObat->info.namaObat<<endl;
        if (PAPK == NULL)
        {
            cout << "Tidak Ada ID Apotek Yang Sesuai"<<endl;
        }
        else
        {
            if (PAPK->daftarObat == NULL)
            {
                cout << "Tidak Terdapat Obat"<<endl;
            }
            else
            {
                //cout<<"X"<<endl;
                //addressObat X;
                //X = deleteObatFirstMergeSort(PAPK->daftarObat);
                //cout<<X->info.namaObat<<endl;
                PAPK->daftarObat = mergeSortObat(PAPK->daftarObat);
                //cout<<"y"<<endl;
                cout<<"========== Sorting pada "<<PAPK->info.namaAPK<<" Telah Berhasil Dilakukan =========="<<endl;
                cout << endl;
                cout << "HASIL :"<<endl;
                cout << endl;
                addressObat M = PAPK->daftarObat;
                while (M != NULL)
                {
                    cout <<"ID Obat    : "<<M->info.idObat<<endl;
                    cout <<"Nama Obat  : "<<M->info.namaObat<<endl;
                    cout<<"Jenis Obat    : "<<M->info.jenisObat<<endl;
                    cout<<"Stock Obat    : "<<M->info.stock<<endl;
                    cout<<"Kadaluarsa    : "<<M->info.kadaluarsa<<endl;
                    cout <<"Harga Obat : "<<M->info.hargaObat<<endl;
                    cout << endl;
                    M = M->next;
                }
            }
        }
    }
}
