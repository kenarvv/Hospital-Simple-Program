#include "header.h"

//KEN ARVIAN NARASOMA
void createListPas(listPasien &LP){
    first(LP) = nil;
    last(LP) = nil;
}

//SASYA KHAIRUNISA
void createListJDok(listJadwalDokter &LJD){
    first(LJD) = nil;
    last(LJD) = nil;
}

//KEN ARVIAN NARASOMA
adrPas createNewElmtPas(infotypePas x){
    adrPas p = new elmtPas;
    info(p) = x;
    next(p) = nil;
    prev(p) = nil;
    hub(p) = nil;
    return p;
}

//SASYA KHAIRUNISA
adrDok createNewElmtJDok(infotypeJDok x){
    adrDok p = new elmtDok;
    info(p) = x;
    next(p) = nil;
    prev(p) = nil;
    return p;
}

//SASYA KHAIRUNISA
void insertFirstJadwalDokter(listJadwalDokter &LJD, adrDok p){
    if(first(LJD) == nil){
        first(LJD) = p;
        last(LJD) = p;
    }else{
        next(p) = first(LJD);
        prev(first(LJD)) = p;
        first(LJD) = p;
    }
}

//SASYA KHAIRUNISA
void showAllJadwalDokter(listJadwalDokter LJD){
    cout<<"==============LIST JADWAL PRAKTEK DOKTER==============="<<endl<<endl;
    if(first(LJD) != nil){
        adrDok p = first(LJD);
        int i = 1;
        while(p != nil){
            cout<<"No."<<i<<endl;
            cout<<"Tanggal: "<<info(p).tgl<<endl;
            cout<<"Jam: "<<info(p).jam<<endl;
            cout<<"Nama: "<<info(p).dokter.namaDok<<endl;
            cout<<"ID: "<<info(p).dokter.idDok<<endl;
            cout<<"Spesialis: "<<info(p).dokter.spesialisDok<<endl;
            cout<<"Kuota: "<<info(p).kuota<<endl<<endl;
            p = next(p);
            i++;
        }
    }else{
        cout<<"[SHOW ALL JADWAL DOKTER] Note: Jadwal Kosong"<<endl<<endl;
    }
    cout<<"======================================================="<<endl<<endl;
}

//SASYA KHAIRUNISA
void deleteFirstJadwal(listJadwalDokter &LJD, adrDok &p){
    if(first(LJD) == nil){
        cout<<"[DELETE JADWAL DOKTER(F)] Note: Jadwal Kosong"<<endl;
        p = nil;
    }else if(next(first(LJD)) == nil){
        p = first(LJD);
        first(LJD) = next(p);
        p = nil;
        p = nil;
    }else{
        p = first(LJD);
        first(LJD) = next(p);
        next(p) = nil;
        prev(first(LJD)) = nil;
        prev(p) = nil;
    }
}

//SASYA KHAIRUNISA
void deleteAfterJadwal(listJadwalDokter &LJD, adrDok prec, adrDok &p){
    if(next(prec) == nil){
        cout<<"[DELETE JADWAL DOKTER(A)] Note: Jadwal Kosong"<<endl;
    }else if(next(next(prec)) == nil){
        deleteLastJadwal(LJD, p);
    }else{
        p = next(prec);
        next(prec) = next(p);
        prev(next(p)) = prec;
        prev(p) = nil;
        next(p)= nil;
    }
}

//SASYA KHAIRUNISA
void deleteLastJadwal(listJadwalDokter &LJD, adrDok &p){
    if(first(LJD) == nil){
        cout<<"[DELETE JADWAL DOKTER(L)] Note: Jadwal Kosong"<<endl;
        p = nil;
    }else if(next(first(LJD)) == nil){
        p = first(LJD);
        first(LJD) = nil;
        last(LJD) = nil;
    }else{
        p = last(LJD);
        last(LJD) = prev(p);
        next(last(LJD)) = nil;
        prev(p) = nil;
    }
}

//SASYA KHAIRUNISA
adrDok findJadwalPraktekByNamaTanggal(listJadwalDokter LJD, string namaDokter, string JadwalP){
    adrDok p = first(LJD);
    while(p != nil){
        if(info(p).dokter.namaDok == namaDokter && info(p).tgl == JadwalP){
            return p;
        }
        p = next(p);
    }
    return nil;
}

//SASYA KHAIRUNISA
void deleteJadwalDokter(listJadwalDokter &LJD, listPasien &LP, adrDok &d, string namaDokter, string JadwalP){
   adrDok q = findJadwalPraktekByNamaTanggal(LJD, namaDokter, JadwalP);
   if(q != nil){
        if(q == first(LJD)){
            deleteFirstJadwal(LJD, d);
        }else if(q == last(LJD)){
            deleteLastJadwal(LJD, d);
        }else{
            adrDok prec = prev(q);
            deleteAfterJadwal(LJD, prec, d);
        }
        if(first(LP) != nil){
            adrPas p = first(LP);
            string tanggalB, Spesialis;
            do{
                if(hub(p) == d){
                    if(!info(p).statusP){
                        cout<<"Masukan jadwal baru untuk "<< info(p).namaPas<<": "; getline(cin, tanggalB);
                        cout<<"Masukan spesialis dokter: "; getline( cin, Spesialis);
                        ubahJadwal(LP, LJD, info(p).namaPas, info(d).tgl, tanggalB, Spesialis);
                    }
                }
                p = next(p);
            }while(p != first(LP));
        }
        cout<<"Cancel Berhasil"<<endl;
   }else{
        cout<<"[DELETE JADWAL DOKTER] Note: Jadwal Tidak Ditemukan"<<endl;
   }
}

//SASYA KHAIRUNISA
adrDok findJadwalPraktekSpesialis(listJadwalDokter LJD, string tanggal, string spesialis){
    adrDok p = first(LJD);
    while(p != nil){
        if(info(p).tgl == tanggal && info(p).dokter.spesialisDok == spesialis && info(p).kuota > 0){
            return p;
        }
        p = next(p);
    }
    return nil;
}

//KEN ARVIAN NARASOMA
void insertPasienRe(listPasien &LP, adrPas p,listJadwalDokter &LJD, string tanggal, string spesialis) {
    adrDok pJadwal = findJadwalPraktekSpesialis(LJD, tanggal, spesialis);
    if(pJadwal == nil){
        cout<<"[INSERT PASIEN] Note: Jadwal Kosong/Penuh"<<endl;
    }else{
        if(first(LP) == nil){
            first(LP) = p;
            last(LP) = p;
            next(p) = p;
            prev(p) = p;
        }else{
            next(last(LP)) = p;
            prev(p) = last(LP);
            last(LP) = p;
            next(p) = first(LP);
            prev(first(LP)) = last(LP);
        }
        info(p).bObat = 0;
        info(p).penyakitPas = " - ";
        info(p).bDokter = 0;
        info(p).jumBiaya = 0;
        hub(p)=pJadwal;
        info(hub(p)).kuota--;
        cout<<"Anda Berhasil Membuat Janji Temu Dengan Dokter "<<info(hub(p)).dokter.namaDok<<endl;
    }
}

//KEN ARVIAN NARASOMA
void showAllPasien(listPasien LP){
    adrPas p = first(LP);
    int i = 1;
    cout<<"===============LIST PASIEN==============="<<endl<<endl;
    if(first(LP) != nil){
        do{
            cout<<"Pasien No."<<i<<endl;
            cout<<"ID: "<<info(p).idPas<<endl;
            cout<<"Nama: "<<info(p).namaPas<<endl;
            if(hub(p) != nil){
                cout<<"Dokter: "<<info(hub(p)).dokter.namaDok<<endl;
                cout<<"Spesialis: "<<info(hub(p)).dokter.spesialisDok<<endl;
                cout<<"Tanggal: "<<info(hub(p)).tgl<<endl;
                cout<<"Pada Pukul: "<<info(hub(p)).jam<<endl;
            }else{
                cout<<"Dokter: "<<"-"<<endl;
                cout<<"Spesialis: "<<"-"<<endl;
                cout<<"Tanggal: "<<"-"<<endl;
                cout<<"Pada Pukul: "<<"-"<<endl;
            }
            cout<<"BPJS: ";
            if(info(p).bpjs){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
            cout<<"Hasil Pemeriksaan: "<<info(p).penyakitPas<<endl;
            cout<<"Biaya Dokter: "<<info(p).bDokter<<endl;
            cout<<"Biaya Obat: "<<info(p).bObat<<endl;
            cout<<"Biaya Total: "<<info(p).jumBiaya<<endl<<endl;
            p = next(p);
            i++;
        }while(p != first(LP));
    }else{
        cout<<"[SHOW PASIEN] Note: Jadwal Kosong"<<endl<<endl;
    }
    cout<<"========================================="<<endl<<endl;
}

//KEN ARVIAN NARASOMA
void deleteFirstPasien(listPasien &LP, adrPas &p){
    if(first(LP) == nil){
        cout<<"[DELETE PASIEN(F)] Note: Jadwal Kosong"<<endl;
        p = nil;
    }else if(next(first(LP)) == first(LP)){
        p = first(LP);
        first(LP) = nil;
        last(LP) = nil;
    }else{
        p = first(LP);
        first(LP) = next(p);
        prev(first(LP)) = last(LP);
        next(last(LP)) = first(LP);
        next(p) = nil;
        prev(p) = nil;
    }
}

//KEN ARVIAN NARASOMA
void deleteAfterPasien(listPasien &LP, adrPas prec, adrPas &p){
    if(next(prec) == first(LP)){
        deleteFirstPasien(LP, p);
    }else if(next(next(prec)) == first(LP)){
        deleteLastPasien(LP, p);
    }else{
        p = next(prec);
        next(prec) = next(p);
        prev(next(p)) = prec;
        prev(p) = nil;
        next(p)= nil;
    }
}

//KEN ARVIAN NARASOMA
void deleteLastPasien(listPasien &LP, adrPas &p){
    if(first(LP) == nil){
        cout<<"[DELETE PASIEN(A)] Note: Jadwal Kosong"<<endl;
        p = nil;
    }else if(next(first(LP)) == first(LP)){
        p = first(LP);
        first(LP) = nil;
        last(LP) = nil;
    }else{
        p = last(LP);
        last(LP) = prev(p);
        next(last(LP)) = first(LP);
        prev(first(LP)) = last(LP);
        next(p) = nil;
        prev(p) = nil;
    }
}

//KEN ARVIAN NARASOMA
adrPas findPasienByIdNama(listPasien LP, string id, string nama){
    adrPas p = first(LP);
    do{
        if(info(p).idPas == id && info(p).namaPas == nama){
            return p;
        }
        p = next(p);
    }while(p != first(LP));
    return nil;
}

//KEN ARVIAN NARASOMA
void deletePasien(listPasien &LP, adrPas &p, string id, string nama){
    p = findPasienByIdNama(LP, id, nama);
    if(p != nil){
        if(!info(p).statusP){
            info(hub(p)).kuota++;
            if(p == first(LP)){
                deleteFirstPasien(LP, p);
            }
            else if(p == last(LP)){
                deleteLastPasien(LP,p);
            }
            else{
                adrPas prec = prev(p);
                deleteAfterPasien(LP,prec,p);
            }
        }else{
            cout<<info(p).namaPas<<" Sudah Di Periksa"<<endl;
        }
    }else{
        cout<<"[DELETE PASIEN] Note: Pasien Tidak Ditemukan"<<endl;
    }
}

//KEN ARVIAN NARASOMA & SASYA KHAIRUNISA
void hasilPemeriksaan(listPasien &LP, string id, string nama, string penyakit, int biayaObat){
    adrPas p = findPasienByIdNama(LP, id, nama);
    if (p != nil){
        info(p).penyakitPas = penyakit;
        info(p).bObat = biayaObat;
        info(p).statusP = true;
        if(info(hub(p)).dokter.spesialisDok == "umum" || info(hub(p)).dokter.spesialisDok == "Umum"){
            info(p).bDokter = 100000;
        }else{
            info(p).bDokter = 200000;
        }
        int jumlahhh = info(p).bDokter + info(p).bObat;
        if(info(p).bpjs == true){
            if(jumlahhh > 500000){
                info(p).jumBiaya = jumlahhh - 500000;
            }else{
                info(p).jumBiaya = 0;
            }
        }else{
            info(p).jumBiaya = info(p).bDokter + info(p).bObat;
        }
        cout<<"Input Laporan Pemeriksaan Berhasil"<<endl;
    }else{
        cout << "[SEARCH EDIT] Note: Pasien Tidak Ditemukan" << endl;
    }
}

//KEN ARVIAN NARASOMA & SASYA KHAIRUNISA
void printPasienByNamaTanggal(listPasien LP, string nama, string tanggalLama){
    adrPas p = fungsiFindPasienByNamaTanggal(LP, nama, tanggalLama);
    if(first(LP) != nil){
        if(p == nil){
            cout<<"Pasien Tidak Ditemukan"<<endl;
        }else{
            cout<<"ID Pasien  : "<<info(p).idPas<<endl;
            cout<<"Nama Pasien: "<<info(p).namaPas<<endl;
            cout<<"Nama Dokter: "<<info(hub(p)).dokter.namaDok<<endl;
            cout<<"Spesialis  : "<<info(hub(p)).dokter.spesialisDok<<endl;
            cout<<"Jadwal Temu: "<<info(hub(p)).tgl<<endl;
        }
    }else{
        cout<<"List Pasien Kosong"<<endl;
    }
}

//KEN ARVIAN NARASOMA & SASYA KHAIRUNISA
int countPasien(listPasien LP, string tanggal){
    adrPas p = first(LP);
    int jum = 0;
    do{
        if(info(hub(p)).tgl == tanggal){
            jum++;
        }
        p = next(p);
    }while(p != first(LP));
    return jum;
}

//KEN ARVIAN NARASOMA & SASYA KHAIRUNISA
void hubPasienDokterByTanggal(listPasien LP, listJadwalDokter LJD){
    if(first(LJD) != nil){
        adrDok d = first(LJD);
        adrPas p;
        int jum;
        int i = 1;
        while(d != nil){

            if(!info(d).status){
                jum = countPasien(LP, info(d).tgl);
                cout<< i << ". Tanggal: "<<info(d).tgl<< ", Jumlah Pasien: " << jum <<  endl;
                p = first(LP);
                do{
                    if(info(d).tgl == info(hub(p)).tgl){
                        cout << "    -  ID: " << info(p).idPas << ", Pasien: "<<info(p).namaPas<<", Dokter: "<<info(hub(p)).dokter.namaDok<<endl;
                        info(hub(p)).status=true;
                    }
                    p = next(p);
                }while(p != first(LP));
                cout<<endl;
                i++;
                info(d).status = false;
            }
            d = next(d);
        }
    }else{
        cout << "[INSERT CONNECT] Note: List Kosong" << endl;
    }
}

//KEN ARVIAN NARASOMA & SASYA KHAIRUNISA
adrDok findJadwalBaru(listJadwalDokter LJD, string tanggal, string spesialis){
    adrDok d = first(LJD);
    while(d != nil){
        if(info(d).tgl == tanggal && info(d).dokter.spesialisDok == spesialis && info(d).kuota > 0){
            return d;
        }
        d = next(d);
    }
    return nil;
}

//KEN ARVIAN NARASOMA & SASYA KHAIRUNISA
adrPas fungsiFindPasienByNamaTanggal(listPasien LP, string nama, string tanggal){
    adrPas p = first(LP);
    do{
        if(info(p).namaPas == nama && info(hub(p)).tgl == tanggal){
            return p;
        }
        p = next(p);
    }while(p != first(LP));
    return nil;
}

//KEN ARVIAN NARASOMA & SASYA KHAIRUNISA
void ubahJadwal(listPasien &LP, listJadwalDokter LJD, string nama, string tanggalLama, string tanggalBaru, string spesialis){
    adrPas p = fungsiFindPasienByNamaTanggal(LP, nama, tanggalLama);
    if(p!= nil){
        adrDok d = findJadwalBaru(LJD, tanggalBaru, spesialis);
        if(d!=nil){
            if(!info(p).statusP){
                info(hub(p)).kuota++;
                info(d).kuota--;
                hub(p) = d;
                cout << "Pengubahan Jadwal Berhasil"<<endl;
            }else{
                cout<<info(p).namaPas<<" Sudah Di Periksa"<<endl;
            }
        }else{
            cout<<"Jadwal Tidak Tersedia"<<endl;
        }
    }else{
        cout<<"Pasien Tidak Ditemukan"<<endl;
    }
}

//KEN ARVIAN NARASOMA & SASYA KHAIRUNISA
int Menu(){
    cout<<"========================= MENU =========================="<<endl;
    cout<<"|                                                        |"<<endl;
    cout<<"| 1.  Buat Jadwal Praktek Dokter                         |"<<endl;
    cout<<"| 2.  Cancel Jadwal Praktek Dokter                       |"<<endl;
    cout<<"| 3.  Input Laporan Pemeriksaan                          |"<<endl;
    cout<<"|                                                        |"<<endl;
    cout<<"| 4.  Buat Jadwal Temu Pasien                            |"<<endl;
    cout<<"| 5.  Ubah Janji Temu Pasien                             |"<<endl;
    cout<<"| 6.  Cancel Janji Temu Pasien                           |"<<endl;
    cout<<"|                                                        |"<<endl;
    cout<<"| 7.  Tampilkan Seluruh Jadwal Praktek Dokter            |"<<endl;
    cout<<"| 8.  Tampilkan Seluruh Data Pasien                      |"<<endl;
    cout<<"| 9.  Cari Janji Temu Pasien                             |"<<endl;
    cout<<"| 10. Tampilkan Data Pasien Pada Seluruh Jadwal Praktek  |"<<endl;
    cout<<"| 0.  Exit                                               |"<<endl;
    cout<<"|                                                        |"<<endl;
    cout<<"========================================================="<<endl;
    cout<<"Pilih Menu: ";
    int input = 0;
    cin>>input;

    return input;
}
