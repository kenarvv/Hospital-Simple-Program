//KEN ARVIAN NARASOMA
#include "header.h"
#include <iostream>

using namespace std;

int main()
{
    listJadwalDokter LJD;
    listPasien LP;
    createListJDok(LJD);
    createListPas(LP);
    infotypeJDok dataDok, datD;
    string y, y1;
    string nama, jadwal, id, penyakit, tanggal, tanggallama, tanggalbaru, spesialis;
    int bObat, n, i;
    adrPas p;
    adrDok d, p2;
    infotypePas datPas, datP;

     //insert jadwal
    datD.tgl = "9 Desember 2022";
    datD.jam = "12.00 - 13.00";
    datD.kuota = 10;
    datD.dokter.namaDok = "Ken Arvian N";
    datD.dokter.idDok = "123456";
    datD.dokter.spesialisDok = "Bedah Jantung";
    p2 = createNewElmtJDok(datD);
    insertFirstJadwalDokter(LJD, p2);

    datD.tgl = "10 Desember 2022";
    datD.jam = "12.00 - 13.00";
    datD.kuota = 10;
    datD.dokter.namaDok = "Bums Anj";
    datD.dokter.spesialisDok = "Umum";
    p2 = createNewElmtJDok(datD);
    insertFirstJadwalDokter(LJD, p2);

    datD.tgl = "11 Desember 2022";
    datD.jam = "12.00 - 13.00";
    datD.kuota = 10;
    datD.dokter.namaDok = "Killua Bambang";
    datD.dokter.idDok = "123456";
    datD.dokter.spesialisDok = "Umum";
    p2 = createNewElmtJDok(datD);
    insertFirstJadwalDokter(LJD, p2);

    datD.tgl = "12 Desember 2022";
    datD.jam = "12.00 - 13.00";
    datD.kuota = 10;
    datD.dokter.namaDok = "Monilisa";
    datD.dokter.idDok = "123456";
    datD.dokter.spesialisDok = "Gigi";
    p2 = createNewElmtJDok(datD);
    insertFirstJadwalDokter(LJD, p2);

    datD.tgl = "12 Desember 2022";
    datD.jam = "12.00 - 13.00";
    datD.kuota = 10;
    datD.dokter.namaDok = "Gley";
    datD.dokter.spesialisDok = "Mata";
    p2 = createNewElmtJDok(datD);
    insertFirstJadwalDokter(LJD, p2);

    datD.tgl = "13 Desember 2022";
    datD.jam = "12.00 - 13.00";
    datD.kuota = 10;
    datD.dokter.namaDok = "Rafael";
    datD.dokter.idDok = "123456";
    datD.dokter.spesialisDok = "Otak";
    p2 = createNewElmtJDok(datD);
    insertFirstJadwalDokter(LJD, p2);

    //insert pasien
    datP.idPas = "1";
    datP.namaPas = "Sasya";
    datP.bpjs = true;

    adrPas p1 = createNewElmtPas(datP);
    insertPasienRe(LP, p1, LJD, "12 Desember 2022", "Mata");

    datP.idPas = "2";
    datP.namaPas = "rehan";
    datP.bpjs = false;

    p1 = createNewElmtPas(datP);
    insertPasienRe(LP, p1, LJD, "11 Desember 2022", "Umum");

    datP.idPas = "3";
    datP.namaPas = "syahran";
    datP.bpjs = false;

    p1 = createNewElmtPas(datP);
    insertPasienRe(LP, p1, LJD, "13 Desember 2022", "Otak");

    datP.idPas = "4";
    datP.namaPas = "cici";
    datP.bpjs = true;

    p1 = createNewElmtPas(datP);
    insertPasienRe(LP, p1, LJD, "9 Desember 2022", "Bedah Jantung");

    datP.idPas = "5";
    datP.namaPas = "ano";
    datP.bpjs = true;

    p1 = createNewElmtPas(datP);
    insertPasienRe(LP, p1, LJD, "9 Desember 2022", "Bedah Jantung");

    datP.idPas = "6";
    datP.namaPas = "imbi";
    datP.bpjs = true;

    p1 = createNewElmtPas(datP);
    insertPasienRe(LP, p1, LJD, "12 Desember 2022", "Gigi");

    datP.idPas = "7";
    datP.namaPas = "riyan";
    datP.bpjs = true;

    p1 = createNewElmtPas(datP);
    insertPasienRe(LP, p1, LJD, "12 Desember 2022", "Gigi");

    //Show Menu
    int input = Menu();
    while(input != 0){
        switch(input){

        case 1:
            cout<<"Masukan Tanggal: "; cin.ignore(); getline(cin, dataDok.tgl);
            cout<<"Masukan Jam: "; getline (cin, dataDok.jam);
            cout<<"Masukan Kuota: "; cin >> dataDok.kuota;
            cout<<"Masukan Nama Dokter: "; cin.ignore(); getline (cin, dataDok.dokter.namaDok);
            cout<<"Masukan ID Dokter: "; cin >> dataDok.dokter.idDok;
            cout<<"Masukan Spesialis : "; cin.ignore(); getline(cin, dataDok.dokter.spesialisDok);
            d = createNewElmtJDok(dataDok);
            insertFirstJadwalDokter(LJD, d);
            cout<<endl;

            cout<<"Kembali ke menu utama? (y/n): ";
            cin>>y;
            if((y == "y") || (y == "Y")){
                input = Menu();
            }else{
                input = 0;
            }
            break;
        case 2:
            cout<<"Masukan Nama Dokter: "; cin.ignore(); getline(cin, nama);
            cout<<"Masukan Tanggal Praktik: "; getline(cin, jadwal);
            deleteJadwalDokter(LJD, LP, d, nama, jadwal);

            cout<<"Kembali ke menu utama? (y/n): ";
            cin>>y;
            if((y == "y") || (y == "Y")){
                input = Menu();
            }else{
                input = 0;
            }
            break;
        case 3:
            cout<<"Masukan Nama Pasien: "; cin.ignore(); getline(cin, nama);
            cout<<"Masukan ID Pasien: "; cin >> id;
            cout<<"Masukan Hasil Diagnosa: "; cin.ignore(); getline(cin, penyakit);
            cout<<"Masukan Biaya Obat: "; cin >> bObat;
            hasilPemeriksaan(LP, id, nama, penyakit, bObat);

            cout<<"Kembali ke menu utama? (y/n): ";
            cin>>y;
            if((y == "y") || (y == "Y")){
                input = Menu();
            }else{
                input = 0;
            }
            break;
        case 4:
            cout << "Masukan Nama Pasien: "; cin.ignore(); getline(cin, datPas.namaPas);
            cout << "Masukan ID Pasien: ";cin >> datPas.idPas;
            cout << "Apakah anda memakai bpjs atau tidak? (y/n): "; cin >> y1;
            if((y1 == "y") || (y1 == "Y")){
                datPas.bpjs = true;
            }else{
                datPas.bpjs = false;
            }
            cout << "Masukan Tanggal Praktik: "; cin.ignore(); getline(cin, tanggal);
            cout << "Dokter Apa yang anda cari? : "; getline(cin, spesialis);
            p = createNewElmtPas(datPas);
            insertPasienRe(LP, p, LJD, tanggal, spesialis);

            cout<<"Kembali ke menu utama? (y/n): ";
            cin>>y;
            if((y == "y") || (y == "Y")){
                input = Menu();
            }else{
                input = 0;
            }
            break;
        case 5:
            cout << "Masukan Nama Pasien: "; cin.ignore(); getline(cin, nama);
            cout << "Masukan Tanggal Praktik Semula: "; getline(cin, tanggallama);
            cout << "Masukan Tanggal Praktik Baru: "; getline(cin, tanggalbaru);
            cout << "Masukan Spesialis: "; getline(cin, spesialis);
            ubahJadwal(LP, LJD, nama, tanggallama, tanggalbaru, spesialis);


            cout<<"Kembali ke menu utama? (y/n): ";
            cin>>y;
            if((y == "y") || (y == "Y")){
                input = Menu();
            }else{
                input = 0;
            }
            break;
        case 6:
            cout << "Masukan ID Pasien: "; cin >> id;
            cout << "Masukan Nama Pasien: "; cin.ignore(); getline(cin, nama);
            deletePasien(LP, p, id, nama);

            cout<<"Kembali ke menu utama? (y/n): ";
            cin>>y;
            if((y == "y") || (y == "Y")){
                input = Menu();
            }else{
                input = 0;
            }
            break;
        case 7:
            showAllJadwalDokter(LJD);

            cout<<"Kembali ke menu utama? (y/n): ";
            cin>>y;
            if((y == "y") || (y == "Y")){
                input = Menu();
            }else{
                input = 0;
            }
            break;
        case 8:
            showAllPasien(LP);

            cout<<"Kembali ke menu utama? (y/n): ";
            cin>>y;
            if((y == "y") || (y == "Y")){
                input = Menu();
            }else{
                input = 0;
            }
            break;
        case 9:
            cout << "Masukan Nama Pasien: "; cin.ignore(); getline( cin, nama);
            cout << "Masukan Tanggal Praktik: "; getline(cin, tanggal);
            printPasienByNamaTanggal(LP, nama, tanggal);

            cout<<"Kembali ke menu utama? (y/n): ";
            cin>>y;
            if((y == "y") || (y == "Y")){
                input = Menu();
            }else{
                input = 0;
            }
            break;
        case 10:
            hubPasienDokterByTanggal(LP, LJD);

            cout<<"Kembali ke menu utama? (y/n): ";
            cin>>y;
            if((y == "y") || (y == "Y")){
                input = Menu();
            }else{
                input = 0;
            }
            break;
        default :
            cout<<"Invalid"<<endl;

            cout<<"Kembali ke menu utama? (y/n): ";
            cin>>y;
            if((y == "Y") || (y == "Y")){
                input = Menu();
            }else{
                input = 0;
            }
            break;
        }
    }

    return 0;
}
