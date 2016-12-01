#include <iostream>
#include <windows.h>
#include <conio.h>
#include "apotekpedia.h"

using namespace std;

int main () {
    apotek mainAPK;
    createListAPK(mainAPK);
    addressAPK addAPK;
    infotypeAPK dataAPK;
    addressObat addObat;
    infotypeObat dataObat;

    {   // Test Case Parent Apotek

        dataAPK.idAPK = "APK-0001";
        dataAPK.namaAPK = "Apotek Setia Budi";
        dataAPK.alamat= "Jalan Bismillah Bandung";
        dataAPK.tanggal=" "    ;
        addAPK = alokasiAPK(dataAPK);
        insertLastAPK(mainAPK, addAPK);


        dataAPK.idAPK = "APK-0002";
        dataAPK.namaAPK = "Apotek Hamasah";
        dataAPK.alamat= "Jalan Kebenaran Bandung";
        dataAPK.tanggal=" "    ;
        addAPK = alokasiAPK(dataAPK);
        insertLastAPK(mainAPK, addAPK);



        dataAPK.idAPK = "APK-0003";
        dataAPK.namaAPK = "Apotek Cinta";
        dataAPK.alamat= "Jalan Putus Nyambung Bandung";
        dataAPK.tanggal=" "    ;
        addAPK = alokasiAPK(dataAPK);
        insertLastAPK(mainAPK, addAPK);



        dataAPK.idAPK = "APK-0004";
        dataAPK.namaAPK = "Apotek Kimia Farma";
        dataAPK.alamat= "Jalan atom Bandung";
        dataAPK.tanggal=" "    ;
        addAPK = alokasiAPK(dataAPK);
        insertLastAPK(mainAPK, addAPK);



        dataAPK.idAPK = "APK-0005";
        dataAPK.namaAPK = "Apotek Genesis";
        dataAPK.alamat= "Jalan Terminator Bandung";
        dataAPK.tanggal=" "    ;
        addAPK = alokasiAPK(dataAPK);
        insertLastAPK(mainAPK, addAPK);

        //Test case Obat

        dataObat.idObat="MED-001";
        dataObat.namaObat="Xamarin";
        dataObat.jenisObat="Migran";
        dataObat.hargaObat=10000;
        dataObat.stock= "17";
        dataObat.kadaluarsa="15 September 2017";
        addAPK = findElmAPK(mainAPK, "APK-0001");
        insertObatFirst(addAPK, dataObat);


        dataObat.idObat="MED-002";
        dataObat.namaObat="Maltos";
        dataObat.jenisObat="pusing";
        dataObat.hargaObat=20000;
        dataObat.stock="147";
        dataObat.kadaluarsa="15 Desember 2017";
        addAPK = findElmAPK(mainAPK, "APK-0002");
        insertObatFirst(addAPK, dataObat);


        dataObat.idObat="MED-002";
        dataObat.namaObat="Panasilin";
        dataObat.jenisObat="luka-luka";
        dataObat.hargaObat=80000;
        dataObat.stock="117";
        dataObat.kadaluarsa="15 Oktober 2017";
        addAPK = findElmAPK(mainAPK, "APK-0003");
        insertObatFirst(addAPK, dataObat);

    }
    ObatLabel:
    system("cls");
    cout << "#### TUGAS BESAR STRUKTUR DATA ####"<<endl
         << "       #### DEEP WEB TEAM ####"<<endl
         <<endl
         << "         1. Insert Toko Apotek"<<endl
         << "         2. Insert Obat Apotek"<<endl
         << "         3. Edit Info Apotek"<<endl // Berdasarkan ID
         << "         4. Edit Info Obat Apotek"<<endl // Berdasarkan ID Obat
         << "         5. Delete Apotek"<<endl // Berdasarkan ID
         << "         6. Delete Obat APK"<<endl // Berdasarkan ID Obat
         << "         7. Print Info Apotek"<<endl
         << "         8. Print APK & Obatnya"<<endl
         << "         9. Search Apotek"<<endl //Berdasarkan ID APK
         << "         10. Search Obat APK"<<endl //Berdasarkan Apotek
         << "         11. Sorting Apotek by ID"<<endl
         << "         12. Sorting Obat APK by ID"<<endl
         << "         13. Hitung Total APK / Obat"<<endl
         << "         0. EXIT"<<endl;
    cout << endl;
    cout << "Pilih Menu (Angka): "; int Obat;
    cin>>Obat; cin.ignore();
    switch (Obat) {
        case 1  :  system("cls"); addapotek(mainAPK);     getch(); goto ObatLabel;
        case 2  :  system("cls"); addObatAPK(mainAPK);         getch(); goto ObatLabel;
        case 3  :  system("cls"); editInfoAPK(mainAPK);        getch(); goto ObatLabel;
        case 4  :  system("cls"); editObat(mainAPK);     getch(); goto ObatLabel;
        case 5  :  system("cls"); deleteAPKOption(mainAPK);    getch(); goto ObatLabel;
        case 6  :  system("cls"); deleteObatOption(mainAPK);  getch(); goto ObatLabel;
        case 7  :  system("cls"); printInfoAPK(mainAPK);       getch(); goto ObatLabel;
        case 8  :  system("cls"); printInfoObat(mainAPK);     getch(); goto ObatLabel;
        case 9  :  system("cls"); searchAPK(mainAPK);          getch(); goto ObatLabel;
        case 10  :  system("cls"); searchObat(mainAPK);        getch(); goto ObatLabel;
//      case 11  :  system("cls"); sortapotek(mainAPK);    getch(); goto ObatLabel;
            //     case 12  :  system("cls"); sortObat(mainAPK);          getch(); goto ObatLabel;
        case 13  :  system("cls"); menucountObat(mainAPK);          getch(); goto ObatLabel;
        case 0  :  goto ExitLabel; // Case Exit
        default : cin.ignore();  goto ObatLabel; // Case Handling Inputan Lain
    }
    ExitLabel: ;

    return 0;
}
