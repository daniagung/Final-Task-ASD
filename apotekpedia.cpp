//
// Created by Mobile Innovation 3 on 02/12/2016.
//

#include "apotekpedia.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
using namespace std;

//----------------- Fungsi dan Prosedur Default ----------------//

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
    Q->daftarAnggota = NULL;
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
    if(M == NULL)
        return NULL;
    else {
        while(M != NULL) {
            if(M->info.idObat == idObat){
                return M;
            }
            M = M->next;
        }
        return M;
    }
}

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

void printInfoObat(apotek APK) {
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
                cout<<"\n====== Obat Kosong ======"<<endl;
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
            cout<<endl;
            P = P->next;
        }
    }
}

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
                cout<<endl;
                M = M->next;
            }
            cout << endl;
            cout << "Masukkan ID Obat Yang  Akan Diubah : ";getline(cin, strSearchIDObat);
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
                cout << "Nama Obat Baru      : "<<M->info.namaObat<<endl;
                cout << "Jenis Obat Baru     : ";cin>>M->info.jenisObat;
                cout << "Harga Obat Baru     : ";cin>>M->info.hargaObat;
                cout << "Stock Obat Baru     : ";cin>>M->info.stock;
                cout << "Masukkan Harga Baru : ";cin>>M->info.hargaObat;
                cout << "Data Berhasil Di Ubah"<<endl;
            }
        }
    }
}

void searchAPK(apotek APK) {
    if(APK.first == NULL)
        cout<<"Tidak ada Data Apotek"<<endl;
    else{
        string strSearch;
        cout<<"Masukan ID / Nama APK yang akan dicari : "; getline(cin, strSearch);
        addressAPK P = APK.first;
        while(P!=NULL){
            if((P->info.idAPK == strSearch) || (P->info.namaAPK == strSearch))
                break;
            else
                P = P->next;
        }
        if(P==NULL){
            cout<<"Tidak ada Data yang Sesuai"<<endl;
            cout<<endl;
        }else{
            cout<<"Data Ditemukan"<<endl;
            cout<<"ID Apotek      : "<<P->info.idAPK<<endl;
            cout<<"Nama Apotek    : "<<P->info.namaAPK<<endl;
            cout<<"Alamat Apotek  : "<<P->info.alamat<<endl;
            cout<<"Tanggal Apotek : "<<P->info.tanggal<<endl;
            cout<<endl;
        }
    }
}

void searchObat(apotek APK){
    if(APK.first == NULL)
        cout<<"Tidak ada Data Apotek"<<endl;
    else{
        string strSearch;
        cout<<"Masukan ID / Nama Obat yang akan dicari : "; getline(cin, strSearch);
        addressAPK P = APK.first;
        addressObat Q;
        bool checkFound = false;
        while(P!=NULL){
            Q = P->daftarObat;
            while(Q != NULL){
                if((Q->info.idObat == strSearch) || (Q->info.namaObat == strSearch)){
                    checkFound = true;
                    break;
                }
                Q = Q->next;
            }
            if(checkFound)
                break;
            P = P->next;
        }

        if(Q==NULL){
            cout<<"Tidak ada Data yang Sesuai"<<endl;
            cout<<endl;
        }else{
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


void insertObatFirst(addressAPK PAPK, infotypeObat addObat) {
    if (PAPK == NULL) {
        cout << "Tidak Ditemukan Apotek";
    }
    else {
        addressObat M = alokasiObat(addObat);
        if (PAPK->daftarObat == NULL) {
            PAPK->daftarObat = M;
        }
        else {
            M->next = PAPK->daftarObat;
            PAPK->daftarObat = M;
        }
    }
}

void insertObatLast(addressAPK PAPK, infotypeObat addObat) {
    if (PAPK == NULL) {
        cout << "Tidak Ditemukan Apotek";
    }
    else {
        addressObat P;
        P = PAPK->daftarObat;
        addressObat M = alokasiObat(addObat);
        if(P == NULL){
            insertObatFirst(PAPK,addObat);
        } else {
            while(P->next != NULL){
                P = P->next;
            }
            P->next = M;
        }
    }
}

void insertObatAfter(addressAPK PAPK, infotypeObat addObat) {
    string strSearchIDObat;
    addressObat M = PAPK->daftarObat;
    if (M == NULL)
    {
        cout << "Karena tidak ada Obat yang tersedia, maka langsung dimasukkan ke awal list"<<endl;
        insertObatFirst(PAPK,addObat);
    }
    else
    {
        cout << "List Obat APK - "<<PAPK->info.namaAPK<<endl;
        while (M != NULL){ // Looping Untuk Menampilkan Obat Apotek
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
        cout << endl;

        cout << "Masukan ID Obat yang ingin di Insert Sesudah-nya: ";getline(cin, strSearchIDObat);
        M = findElmObat(PAPK, strSearchIDObat);
        if(M == NULL){
            cout<<"Element Yang akan diInsert Sesudah-nya tidak tersedia"<<endl;
        } else {
            addressObat adAPKenuSisip;
            adAPKenuSisip = alokasiObat(addObat);
            if(M->next == NULL){ //Jika elemen diujung
                insertObatLast(PAPK,addObat);
            } else {
                adAPKenuSisip->next = M->next;
                M->next = adAPKenuSisip;
            }
        }
    }

}

void addObatAPK(apotek &APK){
    if (APK.first == NULL)
    {
        cout << "Tidak ada Apotek yang terdaftar"<<endl;
    }
    else
    {
        string strSearchAPK;
        printInfoAPK(APK);
        cout << "Masukkan ID Apotek yang akan diTambah Obat-nya: ";
        cin>>strSearchAPK; cin.ignore();
        addressAPK PAPK = findElmAPK(APK, strSearchAPK);
        if (PAPK == NULL) {
            cout << "Tidak Ditemukan Apotek";
        }
        else {
            infotypeObat addObat;
            createObat(addObat);
            char opt;
            cout<<endl;
            cout<<"Pilih Jenis Insert : "<<endl
                <<"1. Insert First"<<endl
                <<"2. Insert Last"<<endl
                <<"3. Insert After"<<endl;
            ObatLabel:
            cout<<"Option : "; cin>>opt; cin.ignore();
            switch (opt) {
              case '1' :  insertObatFirst(PAPK,addObat); break;
              case '2' :  insertObatLast(PAPK,addObat); break;
              case '3' :  insertObatAfter(PAPK,addObat); break;
              default : cin.ignore(); goto ObatLabel;
            }
            cout << "Data Berhasil di Insert"<<endl;
        }
    }

}


addressAPK deleteFirstAPK(apotek &APK) {
    addressAPK P;
    if(first(APK) == NULL)
    {
        return NULL;
    }
    else
    {
        P = first(APK);
        if ((first(APK) != NULL)&&(next(first(APK))==NULL))
        {
            first(APK) = NULL;
            last(APK) = NULL;
            return P;
        }
        else
        {
            prev(next(P)) = NULL;
            first(APK) = next(P);
            next(P) = NULL;
            return P;
        }
    }
}

void deleteLastAPK(apotek &APK) {
    addressAPK P;
    if(first(APK) == NULL)
    {
        cout<<"Data Apotek Tidak Tersedia"<<endl;
    }
    else
    {
        P = last(APK);
        if(prev(P) == NULL)
        {
            first(APK) = NULL;
            last(APK) = NULL;
            delete P;
        }
        else
        {
            next(prev(P)) = NULL;
            last(APK) = prev(P);
            prev(P) = NULL;

        }
    }
}

void deleteAfterAPK(apotek &APK) {
    addressAPK P;
    if (first(APK)==NULL)
    {
        cout<<"Data Apotek Tidak Tersedia"<<endl;
    }
    else
    {
        string delA;
        cout<<endl;
        printInfoAPK(APK);
        cout<<endl;
        cout<<"Masukkan ID Apotek sebelum Apotek yang akan dihapus : ";
        getline(cin, delA);
        addressAPK R = findElmAPK(APK,delA);
        if (R->next == NULL)
        {
            cout<< "Ini adalah elemen terakhir"<<endl;
        }
        else
        {
            addressAPK P = R->next;
            if (P->next == NULL) //elemen yang dihapus, berada diujung
            {
                R->next = NULL;
                P->prev = NULL;
                delete P;
            }
            else //elemen yang dihapus ditengah-tengah
            {
                R->next = P->next;
                P->next->prev = R;
                P->next = NULL;
                P->prev = NULL;
                delete P;
            }
            cout<<"Delete Data APK Berhasil"<<endl;
        }
    }
}

void deleteAPKbyID(apotek &APK){ //
    string strSearchAPK;
    printInfoAPK(APK);
    cout << "Masukkan ID Apotek yang mau di Delete : ";getline(cin,strSearchAPK);
    addressAPK PAPK = findElmAPK(APK, strSearchAPK);
    if(PAPK == NULL){ // Kasus Element Tidak Ditemukan
        cout<<"ID APK Tidak Ditemukan"<<endl;
    }else{
        if(APK.first->next == NULL) {// Element Satu
            APK.first = NULL;
            APK.last = NULL;
            delete PAPK;
        } else if((PAPK == APK.first) && (PAPK->next != NULL)){
            // Kasus Element yang akan didelete posisi pertama
            // dan banyak element lebih dari 1
            deleteFirstAPK(APK);
        } else if((PAPK == APK.last) && (PAPK->prev != NULL)){
            // Kasus Element yang akan didelete posisi Akhir
            // dan banyak element lebih dari 1
            deleteLastAPK(APK);
        } else if((PAPK != APK.first) && (PAPK != APK.last) && (PAPK->next != NULL)){ //Kasus Element Ditengah
            addressAPK P = PAPK->prev;
            P->next = PAPK->next;
            PAPK->next->prev = P;
            PAPK->next = NULL;
            PAPK->prev = NULL;
            delete PAPK;
        } else
            cout<<"Nothing to delete"<<endl;
    }
}

void deleteAPKOption(apotek &APK) {
    if(APK.first == NULL)
        cout<<"Tidak ada data Apotek (Kosong)"<<endl;
    else {
        char pilihan;
        ObatAwal:
        cout << "Jenis Metode Delete Yang Akan Dilakukan"<<endl
             << "1. Delete First"<<endl
             << "2. Delete Last"<<endl
             << "3. Delete After"<<endl
             << "4. Delete By ID"<<endl
             << "5. Exit"<<endl;

        cout << "Masukkan Pilihan : ";
        cin>>pilihan; cin.ignore();
        switch (pilihan)
        {
            case '1' : deleteFirstAPK(APK); cout<<"Delete Data APK Berhasil"<<endl; break;
            case '2' : deleteLastAPK(APK); cout<<"Delete Data APK Berhasil"<<endl; break;
            case '3' : deleteAfterAPK(APK);  break;
            case '4' : deleteAPKbyID(APK);cout<<"Prosedur Delete Data APK Selesai"<<endl; break;
            case '5' : goto ObatAkhir;
            default : cin.ignore(); goto ObatAwal;
        }
        ObatAkhir:
        ;
    }
}



void deleteObatFirst(apotek &APK) {
    cout<<endl;
    printInfoAPK(APK);
    cout<<endl;
    string strSearchID;
    cout << "Masukkan ID Apotek yang akan dihapus Obatnya: ";getline(cin, strSearchID);
    addressAPK PAPK = findElmAPK(APK, strSearchID);
    if (PAPK == NULL) {
        cout << "Tidak Ditemukan Apotek";
    }
    else {
        addressObat M = PAPK->daftarObat;
        if (M == NULL) {
            cout << "Tidak Terdapat Obat"<<endl;
        }
        else
        {
            if (M->next == NULL) {
                //cout<<M->info.idObat<<endl;
                PAPK->daftarObat = NULL;
                M = NULL;
                delete M;
            }
            else {
                PAPK->daftarObat = M->next;
                M->next = NULL;
                delete M;
            }
            cout << "Obat Berhasil Dihapus"<<endl;
        }

    }
}

void deleteObatAfter(apotek &APK) {
    cout<<endl;
    printInfoAPK(APK);
    cout<<endl;
    string strSearchID;
    string strSearchIDObat;
    cout << "Masukkan ID Apotek yang akan dihapus Obatnya: ";getline(cin, strSearchID);
    addressAPK PAPK = findElmAPK(APK, strSearchID);
    if (PAPK == NULL) {
        cout << "Tidak Ditemukan Apotek";
    }
    else {
        addressObat M = PAPK->daftarObat;
        if (M == NULL) {
            cout << "Tidak Terdapat Obat"<<endl;
        }
        else
        {
            cout << "List Obat APK - "<<PAPK->info.namaAPK<<endl;
            while (M != NULL){ // Looping Untuk Menampilkan Obat Apotek
                cout<<"ID Obat    : "<<M->info.idObat<<endl;
                cout<<"Nama Obat  : "<<M->info.namaObat<<endl;
                cout<<"Harga Obat : "<<M->info.hargaObat<<endl;
                cout<<endl;
                M = M->next;
            }
            cout << endl;
            cout << "Masukkan ID Obat Sebelum ID yang akan dihapus : ";
            cin >> strSearchIDObat; cin.ignore();
            M = findElmObat(PAPK,strSearchIDObat);
            if ((M != PAPK->daftarObat) && (M->next == NULL)) //element diujung
            {
                cout << "Tidak ada Obat setelah Obat ini"<<endl;
            }
            else if ((M == PAPK->daftarObat) && (M->next == NULL)) //Obat tunggal
            {
                cout << "Ini adalah satu-satunya Obat di Apotek ini"<<endl;
            }
            else
            {
                addressObat N = M->next;
                if (N->next == NULL)
                {
                    M->next = NULL;
                    delete N;
                }
                else
                {
                    M->next = N->next;
                    N->next = NULL;
                    delete N;
                }
                cout << "Obat Berhasil Dihapus"<<endl;
            }
        }
    }
}

void deleteObatLast(apotek &APK) {
    cout<<endl;
    printInfoAPK(APK);
    cout<<endl;
    string strSearchID;
    cout << "Masukkan ID Apotek yang akan dihapus Obatnya: ";getline(cin, strSearchID);
    addressAPK PAPK = findElmAPK(APK, strSearchID);
    if (PAPK == NULL) {
        cout << "Tidak Ditemukan Apotek"<<endl;
    }
    else
    {
        addressObat M = PAPK->daftarObat;
        if (M == NULL) {
            cout << "Obat Kosong Pada APK Tersebut"<<endl;
        }
        else
        {
            if (PAPK->daftarObat == M && M->next == NULL) // Kalo datanya tinggal satu
            {
                deleteObatFirst(APK);
            }
            else
            {
                while (M->next != NULL)
                {
                    M = M->next;
                }
                addressObat N = PAPK->daftarObat;
                while (N->next->info.idObat != M->info.idObat)
                {
                    N = N->next;
                }
                N->next = NULL;
                delete M;
                cout << "Obat Berhasil Dihapus"<<endl;
            }
        }
    }
}

void deleteObatByID(apotek &APK) {
    string strSearchID;
    string strSearchIDObat;
    printInfoAPK(APK);
    cout << "Masukkan ID Apotek yang akan dihapus Obatnya: ";getline(cin, strSearchID);
    addressAPK PAPK = findElmAPK(APK, strSearchID);
    if (PAPK == NULL) {
        cout << "Tidak Ditemukan Apotek";
    }
    else {
        addressObat M = PAPK->daftarObat;
        if (M == NULL)
        {
            cout << "Tidak terdapat Obat dalam Apotek tersebut"<<endl;
        }
        else
        {
            cout << "List Obat APK - "<<PAPK->info.namaAPK<<endl;
            while (M != NULL){ // Looping Untuk Menampilkan Obat Apotek
                cout<<"ID Obat    : "<<M->info.idObat<<endl;
                cout<<"Nama Obat  : "<<M->info.namaObat<<endl;
                cout<<"Harga Obat : "<<M->info.hargaObat<<endl;
                cout<<endl;
                M = M->next;
            }
            cout << endl;
            cout << "Masukkan ID Obat Yang Ingin Dihapus : ";getline(cin, strSearchIDObat);
            M = PAPK->daftarObat;
            while (M != NULL) { // Looping Posisi Element yang akan dihapus
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
                if (PAPK->daftarObat->next == NULL) { //Hanya Terdapat Satu Obat
                    PAPK->daftarObat = NULL;
                    delete M;
                    cout << "Obat Berhasil Dihapus"<<endl;
                }
                else {                              //Terdapat Banyak Obat
                    if (M == PAPK->daftarObat) {     //Obat berada di awal
                        PAPK->daftarObat = M->next;
                        M->next = NULL;
                        delete M;
                        cout << "Obat Berhasil Dihapus"<<endl;
                    }
                    else if (M->next == NULL) {     //Obat berada di akhir
                        addressObat Q = PAPK->daftarObat;
                        while (Q->next != M) {
                            Q = Q->next;
                        }
                        Q->next = NULL;
                        delete M;
                        cout << "Obat Berhasil Dihapus"<<endl;
                    }
                    else {                          //Obat berada di tengah
                        addressObat Q = PAPK->daftarObat;
                        while (Q->next != M) {
                            Q = Q->next;
                        }
                        Q->next = M->next;
                        M->next = NULL;
                        delete M;
                        cout << "Obat Berhasil Dihapus"<<endl;
                    }
                }
            }
        }

    }
}

void deleteObatOption(apotek &APK) {
    if (APK.first == NULL)
    {
        cout << "Tidak terdapat Apotek"<<endl;
    }
    else
    {
        char pilihan;
        ObatAwal:
        cout << "Jenis Metode Delete Yang Akan Dilakukan"<<endl
             << "1. Delete First"<<endl
             << "2. Delete After"<<endl
             << "3. Delete Last"<<endl
             << "4. Delete By ID"<<endl
             << "5. Exit"<<endl;

        cout << "Masukkan Pilihan : ";
        cin>>pilihan; cin.ignore();
        switch (pilihan)
        {
            case '1' : deleteObatFirst(APK); break; goto ObatAwal;
            case '2' : deleteObatAfter(APK); break; goto ObatAwal;
            case '3' : deleteObatLast(APK); break; goto ObatAwal;
            case '4' : deleteObatByID(APK); break; goto ObatAwal;
            case '5' : goto ObatAkhir;
            default : cin.ignore(); goto ObatAwal;
        }

        ObatAkhir:
        ;
    }

}




void insertFirstAPK(apotek &R, addressAPK P) { //
    if(first(R) == NULL){ //Kondisi Ketika List Kosong
        first(R) = P;
        last(R) = P;
    } else {
        P->next = R.first;
        R.first->prev = P;
        R.first = P;
    }
}

void insertLastAPK(apotek &R, addressAPK P) { //
    if(first(R) == NULL){ //Kondisi Ketika List Kosong
        first(R) = P;
        last(R) = P;
    } else {
        prev(P) = last(R);
        next(prev(P)) = P;
        last(R) = P;
    }
}

void insertAfterAPK(apotek &R, addressAPK P) { //
    if (R.first == NULL)
    {
        cout << "Karena Elemen Kosong, Maka Elemen Langsung Diinsert Di Awal List"<<endl;
        insertFirstAPK(R,P);
    }
    else
    {
        string strSearchID;
        printInfoAPK(R);
        cout << endl;
        cout << "Masukan ID APK yang ingin di Insert Sesudah-nya: ";getline(cin, strSearchID);
        addressAPK PAPK;
        PAPK = findElmAPK(R, strSearchID);
        if(PAPK == NULL){
            cout<<"Element Yang akan diInsert Sesudah-nya tidak tersedia"<<endl;
        } else {
            if(PAPK->next == NULL){ // Element yang mau diInsert sesudahnya berada di Ujung
                insertLastAPK(R,P);

            } else {
                P->next = PAPK->next;
                P->prev = PAPK;
                PAPK->next->prev = P;
                PAPK->next = P;
            }
        }
    }

}

void addapotek(apotek &R){
    infotypeAPK addAPK;
    createAPK(addAPK);
    addressAPK PAPK;
    PAPK = alokasiAPK(addAPK);
    char opt;
    cout<<endl;
    cout<<"Pilih Jenis Insert : "<<endl
        <<"1. Insert First"<<endl
        <<"2. Insert Last"<<endl
        <<"3. Insert After"<<endl;
    ObatLabel:
    cout<<"Option : "; cin>>opt; cin.ignore();
    switch (opt) {
      case '1' :  insertFirstAPK(R,PAPK); break;
      case '2' :  insertLastAPK(R,PAPK); break;
      case '3' :  insertAfterAPK(R,PAPK); break;
      default : cin.ignore(); goto ObatLabel;
    }
    cout << "Data Berhasil di Insert"<<endl;
}



void countTotalAPK(apotek APK){
    addressAPK PAPK;
    PAPK = APK.first;
    if(PAPK == NULL){
        cout<<"Total Apotek yang terdata Kosong Pemirsa!!"<<endl;
    } else {
        int countNum = 0;
        while(PAPK!= NULL){
            countNum++;
            PAPK = PAPK->next;
        }
        cout<<"Total APK yang tersedia adalah : "<<countNum<<" Apotek"<<endl;
    }
}

void countTotalObat(apotek APK){
    if(APK.first == NULL)
        cout<<"Tidak ada Data Apotek"<<endl;
    else {
        string strSearchID;
        string strSearchIDObat;
        printInfoAPK(APK);
        cout << endl;
        cout << "Masukkan ID Apotek yang akan dihitung Obatnya: ";getline(cin, strSearchID);
        addressAPK PAPK = findElmAPK(APK, strSearchID);
        if(PAPK != NULL){
            int countNum = 0; //Counter Hitung
            addressObat M = PAPK->daftarObat;
            while(M != NULL){ //Looping Hitung Element
                countNum++;
                M = M->next;
            }
            cout << endl;
            cout<<"Apotek : "<<PAPK->info.namaAPK<<" - Mempunyai "<<countNum<<" Obat"<<endl;
        } else {
            cout << endl;
            cout<<"Tidak Terdapat ID Apotek"<<endl;
        }
    }
}

void countObat(apotek APK) {
    char opt;
    cout<<"===== Pilih Element List yang mau dihitung ====="<<endl
        <<"1. Apotek"<<endl
        <<"2. Obat suatu Apotek"<<endl
        <<"3. Back to Main Obat"<<endl;
    ObatLabel:
    cout<<"Option : "; cin>>opt; cin.ignore();
    switch (opt) {
      case '1' :  countTotalAPK(APK); break;
      case '2' :  countTotalObat(APK); break;
      case '3' :  break;
      default : goto ObatLabel;
    }
}




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
                    cout <<"Harga Obat : "<<M->info.hargaObat<<endl;
                    cout << endl;
                    M = M->next;
                }
            }
        }
    }
}
