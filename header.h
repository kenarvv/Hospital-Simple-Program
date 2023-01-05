#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

//SASYA KHAIRUNISA
#include <iostream>
#include <string>
using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define hub(P) (P)->hub
#define first(L) ((L).first)
#define last(L) ((L).last)
#define nil NULL

struct pasien{
    string idPas, namaPas, penyakitPas;
    bool bpjs;
    bool statusP = false;
    int bDokter, bObat, jumBiaya;
};

struct dataDokter{
    string idDok, namaDok, spesialisDok;
};

struct jadwalPraktek{
    string tgl, jam;
    int kuota;
    bool status;
    dataDokter dokter;
};

typedef struct elmtPas *adrPas;
typedef struct elmtDok *adrDok;

typedef pasien infotypePas;
typedef jadwalPraktek infotypeJDok;

struct elmtPas{
    infotypePas info;
    adrPas next, prev;
    adrDok hub;
};

struct elmtDok{
    infotypeJDok info;
    adrDok next, prev;
};

struct listPasien{
    adrPas first, last;
};

struct listJadwalDokter{
    adrDok first, last;
};

void createListPas(listPasien &LP);//SASYA KHAIRUNISA
void createListJDok(listJadwalDokter &LJD);//SASYA KHAIRUNISA
adrPas createNewElmtPas(infotypePas x);//SASYA KHAIRUNISA
adrDok createNewElmtJDok(infotypeJDok x);//SASYA KHAIRUNISA
void insertFirstJadwalDokter(listJadwalDokter &LJD, adrDok p);//SASYA KHAIRUNISA
void showAllJadwalDokter(listJadwalDokter LJD);//SASYA KHAIRUNISA
void deleteFirstJadwal(listJadwalDokter &LJD, adrDok &p);//SASYA KHAIRUNISA
void deleteAfterJadwal(listJadwalDokter &LJD, adrDok prec, adrDok &p);//SASYA KHAIRUNISA
void deleteLastJadwal(listJadwalDokter &LJD, adrDok &p);//SASYA KHAIRUNISA
adrDok findJadwalPraktekByNamaTanggal(listJadwalDokter LJD, string namaDokter, string JadwalP);//SASYA KHAIRUNISA
void deleteJadwalDokter(listJadwalDokter &LJD, listPasien &LP, adrDok &d, string namaDokter, string JadwalP);//KEN ARVIAN NARASOMA
adrDok findJadwalPraktekSpesialis(listJadwalDokter LJD, string tanggal, string spesialis); //SASYA KHAIRUNISA
void insertPasienRe(listPasien &LP, adrPas p,listJadwalDokter &LJD, string tanggal, string spesialis);//SASYA KHAIRUNISA
void showAllPasien(listPasien LP);//SASYA KHAIRUNISA
void deleteFirstPasien(listPasien &LP, adrPas &p);//KEN ARVIAN NARASOMA
void deleteAfterPasien(listPasien &LP, adrPas prec, adrPas &p);//KEN ARVIAN NARASOMA
void deleteLastPasien(listPasien &LP, adrPas &p);//KEN ARVIAN NARASOMA
adrPas findPasienByIdNama(listPasien LP, string id, string nama);//KEN ARVIAN NARASOMA
void deletePasien(listPasien &LP, adrPas &p, string id, string nama);//KEN ARVIAN NARASOMA
void hasilPemeriksaan(listPasien &LP, string id, string nama,string penyakit, int biayaObat);//KEN ARVIAN NARASOMA
void printPasienByNamaTanggal(listPasien LP, string nama, string tanggal);//KEN ARVIAN NARASOMA
int countPasien(listJadwalDokter LJD, listPasien LP, string tanggal);//KEN ARVIAN NARASOMA
void hubPasienDokterByTanggal(listPasien LP, listJadwalDokter LJD);//KEN ARVIAN NARASOMA
adrPas fungsiFindPasienByNamaTanggal(listPasien LP, string nama, string tanggal);//KEN ARVIAN NARASOMA
adrDok findJadwalBaru(listJadwalDokter LJD, string tanggal, string spesialis);//KEN ARVIAN NARASOMA
void ubahJadwal(listPasien &LP, listJadwalDokter LJD, string nama, string tanggalLama, string tanggalBaru, string spesialis);//KEN ARVIAN NARASOMA
int Menu();//SASYA KHAIRUNISA

#endif // HEADER_H_INCLUDED
