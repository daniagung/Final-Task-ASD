#ifndef APOTEKPEDIA_H_INCLUDED
#define APOTEKPEDIA_H_INCLUDED

//
// Created by Dani Agung Prastiyo on 20/11/2016.
//


// ---- Library --- //
#include <iostream>
#include <ctime>

// Define Pointer
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define first(R) (R).first
#define last(R) (R).last

using namespace std;

// ---- Deklarasi Pointer addressAPK --- //
typedef int *addressAnggota;
typedef struct elmAPK *addressAPK;
typedef struct elmObat *addressObat;

// ----- Deklarasi Tipe Bentukan Infotype ----- //
struct infotypeAPK
{
    string idAPK;
    string namaAPK;
    string alamat;
    string tanggal;
};

struct infotypeObat {
    string idObat;
    string namaObat;
    string kadaluarsa;
    string stock;
    string hargaObat;
    string jenisObat;

};

// ------ Tipe Bentukan Element List ------ //

//Tipe bentukan Parent Apotek
struct elmAPK
{
    infotypeAPK info;
    addressObat daftarObat;
    addressAPK next;
    addressAPK prev;
};

//Tipe bentukan Child Obat
struct elmObat {
    infotypeObat info;
    addressObat next;
};

// ------ Tipe Bentukan List ----- //
struct apotek
{
    addressAPK first;
    addressAPK last;
};

struct Obat {
    addressObat first;
};

//----------------- Fungsi dan Prosedur Default ----------------//
void createListAPK(apotek &R);
void createListObat(Obat &R);
void createAPK(infotypeAPK &APK);
void createObat(infotypeObat &ObatAPK);
addressAPK alokasiAPK(infotypeAPK APK);
addressObat alokasiObat(infotypeObat ObatAPK);

addressAPK findElmAPK(apotek R, string idAPK);
addressObat findElmObat(addressAPK PAPK, string idObat);

void printInfoAPK(apotek APK);
void printInfoObat(apotek APK);
void editInfoAPK(apotek &APK);
void editObat(apotek &APK);
void searchAPK(apotek APK);
void searchObat(apotek APK);

void insertObatFirst(addressAPK PAPK, infotypeObat addObat);
void insertObatLast(addressAPK PAPK, infotypeObat addObat);
void insertObatAfter(addressAPK PAPK, infotypeObat addObat);
void addObatAPK(apotek &APK);

addressAPK deleteFirstAPK(apotek &APK);
void deleteLastAPK(apotek &APK);
void deleteAfterAPK(apotek &APK);
void deleteAPKbyID(apotek &APK);
void deleteAPKOption(apotek &APK);

void deleteObatFirst(apotek &APK);
void deleteObatAfter(apotek &APK);
void deleteObatLast(apotek &APK);
void deleteObatByID(apotek &APK);
void deleteObatOption(apotek &APK);

void insertFirstAPK(apotek &R, addressAPK P);
void insertLastAPK(apotek &R, addressAPK P);
void insertAfterAPK(apotek &R, addressAPK P);
void addapotek(apotek &R);

void countTotalAPK(apotek APK);
void countTotalObat(apotek APK);
void menucountObat(apotek APK);


void sortapotek(apotek &APK);
void sortobat(addressObat &APK);


#endif // APOTEKPEDIA_H_INCLUDED
