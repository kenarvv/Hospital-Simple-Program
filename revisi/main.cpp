#include "header.h"
#include <iostream>

using namespace std;

int main()
{
    listJadwalDokter LJD;
    listPasien LP;
    createListJDok(LJD);
    createListPas(LP);
    infotypeJDok dataDok;
    char input = Menu();
    char y, y1;
    string nama, jadwal, id, penyakit, tanggal, spesialis, jamMulai, jamSelesai;
    int bObat;
    adrPas p;
    adrDok d;
    infotypePas datPas;

    while(input != '0'){
        switch(input){

        case '1':
            cout<<"Masukan Tanggal: ";cin >> dataDok.tgl;
            cout<<"Masukan Jam Mulai: ";cin >> dataDok.jamMulai;
            cout<<"Masukan Jam Selesai: ";cin >> dataDok.jamSelesai;
            cout<<"Masukan Kuota: "; cin >> dataDok.kuota;
            cout<<"Masukan Nama Dokter: "; cin >> dataDok.dokter.namaDok;
            cout<<"Masukan ID Dokter: ";cin >> dataDok.dokter.idDok;
            cout<<"Masukan Spesialis : ";cin >> dataDok.dokter.spesialisDok;
            d = createNewElmtJDok(dataDok);
            insertFirstJadwalDokter(LJD, d);
            cout<<"Kembali ke menu utama? (y/n): ";
            cin>>y;
            if((y == 'y') || (y == 'Y')){
                input = Menu();
            }else{
                input = '0';
            }
            break;
        case '2':
            //string nama, jadwal;
            //adrDok p;
            cout<<"Masukan Nama Dokter: "; cin >> nama;
            cout<<"Masukan Tanggal Praktik: "; cin >> jadwal;
            deleteJadwalDokter(LJD, LP, d, nama, jadwal);
            cout<<"Kembali ke menu utama? (y/n): ";
            cin>>y;
            if((y == 'y') || (y == 'Y')){
                input = Menu();
            }else{
                input = '0';
            }
            break;
        case '3':
            //string id, nama, penyakit;
            //int bObat;
            cout<<"Masukan Nama Pasien: "; cin >> nama;
            cout<<"Masukan ID Pasien: "; cin >> id;
            cout<<"Masukan Hasil Diagnosa: "; cin >> nama;
            cout<<"Masukan Biaya Obat: "; cin >> bObat;
            hasilPemeriksaan(LP, id, nama, penyakit, bObat);
            cout<<"Kembali ke menu utama? (y/n): ";
            cin>>y;
            if((y == 'y') || (y == 'Y')){
                input = Menu();
            }else{
                input = '0';
            }
            break;
        case '4':
            //string tanggal, spesialis;
            //adrPas p;
            //infotypePas datPas;
            cout << "Masukan Nama Pasien: "; cin >> datPas.namaPas;
            cout << "Masukan ID Pasien: ";cin >> datPas.idPas;
            cout << "Apakah anda memakai bpjs atau tidak? (y/n): "; cin >> y1;
            if((y1 == 'y') || (y1 == 'Y')){
                datPas.bpjs = true;
            }else{
                datPas.bpjs = false;
            }
            cout << "Masukan Tanggal Praktik: "; cin >> tanggal;
            cout << "Dokter Apa yang anda cari? : "; cin >> spesialis;
            info(p).penyakitPas = " - ";
            info(p).bObat = 0;
            info(p).bDokter = 0;
            info(p).jumBiaya = 0;
            p = createNewElmtPas(datPas);
            insertPasienRe(LP, p, LJD, tanggal, spesialis);
            cout<<"Kembali ke menu utama? (y/n): ";
            cin>>y;
            if((y == 'y') || (y == 'Y')){
                input = Menu();
            }else{
                input = '0';
            }
            break;
        case '5':
            //string nama, tanggal, jamMulai, jamSelesai;
            cout << "Masukan Nama Pasien: "; cin >> nama;
            cout << "Masukan Tanggal Praktik: "; cin >> tanggal;
            cout << "Masukan Jam Mulai: "; cin >> jamMulai;
            cout << "Masukan Jam Selesai: "; cin >> jamSelesai;
            ubahJadwal(LP, LJD, nama, tanggal, jamMulai, jamSelesai);
            cout<<"Kembali ke menu utama? (y/n): ";
            cin>>y;
            if((y == 'y') || (y == 'Y')){
                input = Menu();
            }else{
                input = '0';
            }
            break;
        case '6':
            //string id, nama;
            //adrPas p;
            cout << "Masukan ID Pasien: "; cin >> id;
            cout << "Masukan Nama Pasien: "; cin >> nama;
            deletePasien(LP, p, id, nama);
            cout<<"Kembali ke menu utama? (y/n): ";
            cin>>y;
            if((y == 'y') || (y == 'Y')){
                input = Menu();
            }else{
                input = '0';
            }
            break;
        case '7':
            showAllJadwalDokter(LJD);
            cout<<"Kembali ke menu utama? (y/n): ";
            cin>>y;
            if((y == 'y') || (y == 'Y')){
                input = Menu();
            }else{
                input = '0';
            }
            break;
        case '8':
            showAllPasien(LP);
            cout<<"Kembali ke menu utama? (y/n): ";
            cin>>y;
            if((y == 'y') || (y == 'Y')){
                input = Menu();
            }else{
                input = '0';
            }
            break;
        case '9':
            //adrPas p;
            //string nama, tanggal;
            cout << "Masukan Nama Pasien: "; cin >> nama;
            cout << "Masukan Tanggal Praktik: "; cin >> tanggal;
            p = fungsiFindPasienByNamaTanggal(LP, nama, tanggal);
            cout << "Pada Tanggal " << info(hub(p)).tgl << " Pasien dengan nama " << info(p).namaPas << " Sudah Membuat janji temu dengan dokter " << info(hub(p)).dokter.namaDok << " spesialis " << info(hub(p)).dokter.spesialisDok << endl;
            cout<<"Kembali ke menu utama? (y/n): ";
            cin>>y;
            if((y == 'y') || (y == 'Y')){
                input = Menu();
            }else{
                input = '0';
            }
            break;
        case '10':
            hubPasienDokterByTanggal(LP, LJD);
            cout<<"Kembali ke menu utama? (y/n): ";
            cin>>y;
            if((y == 'y') || (y == 'Y')){
                input = Menu();
            }else{
                input = '0';
            }
            break;
        }
    }

    return 0;
}
