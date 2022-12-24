#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <unistd.h>
#include <stdlib.h>

#include "include/person.hpp"
#include "include/mahasiswa.hpp"
#include "include/dosen.hpp"
#include "include/tendik.hpp"
#include "include/matkul.hpp"
#include "include/function.hpp"

using namespace std;

int main(){
	vector<mahasiswa> recMhs;
	vector<dosen> recDosen;
	vector<tendik> recTendik;
	vector<matkul> recMatkul;

	string nama, nrp, npp, departemen, pendidikan, unit, namaMatkul, kodeMatkul;
	long long unsigned int dd, mm, yy, tahunmasuk, semester, sksMatkul, sksLulus, jumlahMatkul = 0, idMhs = 0, idDsn = 0, idTndk = 0, idMatkul = 0, noID = 0, menu_terpilih;
	double ipSem = 0.0;
	
	program:
	login();
	
	while (userIndex == 2){
		while(1) {
			system("cls || clear");
			cout << "Selamat datang di Benedetta Academy" << endl << endl;
			cout << "Data statistik:" << endl;
			cout << "  1. Jumlah Mahasiswa             : " << recMhs.size() << " mahasiswa" << endl;
			cout << "  2. Jumlah Dosen                 : " << recDosen.size() << " dosen" << endl;
			cout << "  3. Jumlah Tenaga Kependidikan   : " << recTendik.size() << " tendik" << endl;
			cout << "  4. Jumlah Matkul                : " << recMatkul.size() << " matkul" << endl;
			cout << endl;
			cout << "Menu: " << endl;
			cout << "  1. Tambah Mahasiswa" << endl;
			cout << "  2. Tambah Dosen" << endl;
			cout << "  3. Tambah Tenaga Kependidikan" << endl;
			cout << "  4. Tampilkan semua Mahasiswa" << endl;
			cout << "  5. Tampilkan semua Dosen" << endl;
			cout << "  6. Tampilkan semua Tenaga Kependidikan" << endl;
			cout << "  7. Tambah Matkul" << endl;
			cout << "  8. Tampilkan semua Matkul" <<endl;
			cout << "  9. Keluar" << endl;
			cout << "-> Silahkan memilih salah satu: ";
			cin >> menu_terpilih;

			switch (menu_terpilih) {
				case 1:
					{
						if (recMatkul.empty()){
							cout << "Belum ada matkul ditambahkan!" << endl;
							sleep(3);
							system("cls || clear");
							break;
						}
						int pilihan;
						bool flag = true, flagTTL = true;
						while (flag){
							system("cls || clear");
							idMhs++;
							cout << "Masukkan Nama : "; cin.ignore(); getline(cin, nama); cout << endl;
							while (flagTTL){
								cout << "Masukkan TTL (dd mm yy) : "; cin >> dd >> mm >> yy; cout << endl;

								if (dateValidation(dd, mm, yy)){
									flagTTL = false;
								}else{
									cout << "TTL yang anda masukkan tidak valid!" << endl;
									continue;
								}
							}
							cout << "Masukkan NRP : "; cin >> nrp; cout << endl;
							cout << "Masukkan Departemen : "; cin.ignore(); getline(cin, departemen); cout << endl;
							cout << "Masukkan Tahun Masuk : "; cin >> tahunmasuk; cout << endl;
							cout << "Masukkan Semester : "; cin >> semester; cout << endl;
							cout << "Masukkan SKS Lulus : "; cin >> sksLulus; cout << endl;

							mahasiswa mhs(idMhs, nama, dd, mm, yy, nrp, departemen, tahunmasuk, semester, sksLulus, jumlahMatkul);
							recMhs.push_back(mhs);
						
							cout << "Apakah anda ingin mengisi mahasiswa lagi?" << endl;
							cout << "  1. Ya" << endl;
							cout << "  2. Tidak" << endl;
							cout << "Pilihan anda : ";
							cin >> pilihan;
							if (pilihan == 1){
								continue;
							}else if(pilihan == 2){
								flag = false;
								system("cls || clear");
							}
						}
					}
					break;
				case 2:
					{
						int pilihan;
						bool flag = true, flagTTL = true;
						while (flag){
							system("cls || clear");
							idDsn++;
							cout << "Masukkan Nama : "; cin.ignore(); getline(cin, nama); cout << endl;

							while (flagTTL){
								cout << "Masukkan TTL (dd mm yy) : "; cin >> dd >> mm >> yy; cout << endl;

								if (dateValidation(dd, mm, yy)){
									flagTTL = false;
								}else{
									cout << "TTL yang anda masukkan tidak valid!" << endl;
									continue;
								}
							}

							cout << "Masukkan NPP : "; cin >> npp; cout << endl;
							cout << "Masukkan Departemen : "; cin.ignore(); getline(cin, departemen); cout << endl;
							cout << "Masukkan Pendidikan Terakhir : "; cin.ignore(); getline(cin, pendidikan); cout << endl;
					
							dosen dsn(idDsn,nama,dd,mm,yy,npp,departemen,pendidikan);
							recDosen.push_back(dsn);
							cout << "Dosen baru berhasil ditambahkan!" << endl << endl;

							cout << "Apakah anda ingin mengisi dosen lagi?" << endl;
							cout << "  1. Ya" << endl;
							cout << "  2. Tidak" << endl;
							cout << "Masukkan pilihan anda : ";
							cin >> pilihan;
							if (pilihan == 1){
								continue;
							}else if(pilihan == 2){
								flag = false;
								system("cls || clear");
							}
						}
					}
					break;
				case 3:
					{
						int pilihan;
						bool flag = true, flagTTL = true;
						while (flag)
						{
							system("cls || clear");
							idTndk++;
							cout << "Masukkan Nama : "; cin.ignore(); getline(cin, nama); cout << endl;

							while (flagTTL){
								cout << "Masukkan TTL (dd mm yy) : "; cin >> dd >> mm >> yy; cout << endl;

								if (dateValidation(dd, mm, yy)){
									flagTTL = false;
								}else{
									cout << "TTL yang anda masukkan tidak valid!" << endl;
									continue;
								}
							}

							cout << "Masukkan NPP : "; cin >> npp; cout << endl;
							cout << "Masukkan Unit : "; cin.ignore(); getline(cin, unit); cout << endl;
						
							tendik tndk(idTndk,nama,dd,mm,yy,npp,unit);
							recTendik.push_back(tndk);
							cout << "Tendik baru berhasil ditambahkan!" << endl << endl;

							cout << "Apakah anda ingin mengisi tendik lagi?" << endl;
							cout << "  1. Ya" << endl;
							cout << "  2. Tidak" << endl;
							cout << "Masukkan pilihan anda : ";
							cin >> pilihan;
							if (pilihan == 1){
								continue;
							}else if(pilihan == 2){
								flag = false;
								system("cls || clear");
							}
						}
					}
					break;
				case 4:
					{
						if (recMhs.empty()){
							system("cls || clear");
							cout << "Tidak ada Mahasiswa terdaftar!";
							sleep(3);
							system("cls || clear");
							break;
						}
						int pilihan;
						bool flag = true;
						while (flag){
							system("cls || clear");
							for (long long unsigned int i = 0; i < recMhs.size(); i++){
								cout << recMhs[i].getId() << ". Nama Mahasiswa : " << recMhs[i].getNama() << endl;
								cout << "   NRP : " << recMhs[i].getNRP() << endl << endl;
							}

							cout << "Masukkan ID Mahasiswa yang ingin dilihat detailnya : "; cin >> noID;
							if (noID > recMhs.size()){
								cout << endl << "Mahasiswa dengan id " << noID << " tidak ditemukan." << endl;
								sleep(3);
								continue;
							}
							system("cls || clear");
							cout << recMhs[noID-1].getId() << ". Nama Mahasiswa : " << recMhs[noID-1].getNama() << endl;
							cout << "   NRP : " << recMhs[noID-1].getNRP() << endl;
							cout << "   Tanggal Lahir : " << recMhs[noID-1].getTglLahir() << "/" << recMhs[noID-1].getBulanLahir() << "/" << recMhs[noID-1].getTahunLahir() << endl;
							cout << "   Departemen : " << recMhs[noID-1].getDepartemen() << endl;
							cout << "   Tahun Masuk : " << recMhs[noID-1].getTahunMasuk() << endl;
							cout << "   Semester : " << recMhs[noID-1].getSemester() << endl;
							cout << "   SKS Lulus : " << recMhs[noID-1].getSKSLulus() << endl;	

							cout << endl;
							cout << "1. Input Matkul Diambil" << endl;
							cout << "2. Input IP Semester" << endl;
							cout << "3. Lihat IP Semester & IP Kumulatif" << endl;
							cout << "4. Kembali ke Daftar Mahasiswa " << endl;
							cout << "5. Kembali ke Menu Utama " << endl;
							cout << "6. Edit Detail Mahasiswa" << endl;
							cout << "Masukkan pilihan anda : "; cin >> pilihan;
							
							switch (pilihan){
							case 1:
								{
									bool flag = true;
									while (flag){
										system("cls || clear");
										cout << "Daftar Mata Kuliah" << endl;
										for (long long unsigned int i = 0; i < recMatkul.size(); i++){
											cout << recMatkul[i].getIdMatkul() << ". " << "Nama Matkul : "<<recMatkul[i].getMatkul() << endl;
											cout << "   Kode        : " << recMatkul[i].getKodeMatkul() << endl;
											cout << "   SKS         : " << recMatkul[i].getSKSMatkul() << endl;
										}
										cout << endl << "Masukkan ID Matkul yang ingin ditambahkan : "; cin >> idMatkul;
										
										if (idMatkul > recMatkul.size()){
											cout << "Mata Kuliah dengan id " << idMatkul << " tidak ditemukan." << endl;
											sleep(3);
											continue;
										}
										
										int tempID = recMatkul[idMatkul-1].getIdMatkul();
										string tempNamaMatkul = recMatkul[idMatkul-1].getMatkul();
										string tempKode = recMatkul[idMatkul-1].getKodeMatkul();
										int tempSKS = recMatkul[idMatkul-1].getSKSMatkul();

										matkul temp;
										recMhs[noID-1].matkulTerambil.push_back(temp);
										recMhs[noID-1].matkulTerambil[jumlahMatkul].setIdMatkul(tempID);
										recMhs[noID-1].matkulTerambil[jumlahMatkul].setMatkul(tempNamaMatkul);
										recMhs[noID-1].matkulTerambil[jumlahMatkul].setKodeMatkul(tempKode);
										recMhs[noID-1].matkulTerambil[jumlahMatkul].setSKSMatkul(tempSKS);
										jumlahMatkul++;

										cout << "Mata Kuliah berhasil ditambahkan!" << endl;
										sleep(3);

										cout << "Ingin menambah mata kuliah lagi?" << endl;
										cout << "1. Ya" << endl;
										cout << "2. Tidak" << endl;
										cout << "Pilihan anda : ";
										int pilih;
										cin >> pilih;
										switch (pilih){
										case 1:
											continue;
										case 2:
											flag = false;
											break;
										default:
											defaultError();
											break;
										}
									}
								}
								break;
							case 2:
								{
									cout << "Silahkan input IP Semester Mahasiswa " << recMhs[noID-1].getNama() << " (Maks IP Semester 4.0)" << endl;
									for (int i = 1; i <= recMhs[noID-1].getSemester(); i++){
										cout << "IP Semester " << i << " : "; cin >> ipSem;
										if (ipSem > 4.0){
											cout << "IP Semester tidak boleh lebih dari 4.0!" << endl;
											sleep(3);
											continue;
										}
										recMhs[noID-1].setIPS(i, ipSem);
									}
									cout << "IP Semester Mahasiswa " << recMhs[noID-1].getNama() << " berhasil ditambahkan!" << endl;
									sleep(3);
								}
								break;
							case 3:
								{
									if (recMhs[noID-1].getIPS(1) == 0 && recMhs[noID-1].getIPS(2) == 0){
										cout << "IP Semester " << recMhs[noID-1].getNama() << " belum diinput!" << endl;
										sleep(3);
										break;
									}

									for (int i = 1; i <= recMhs[noID-1].getSemester(); i++){
										cout << "IP Semester " << i << " : " << recMhs[noID-1].getIPS(i) << endl;
									}

									float ipk = 0, totalIPK = 0;
									for (int i = 1; i <= recMhs[noID-1].getSemester(); i++){
										totalIPK += recMhs[noID-1].getIPS(i);
									}

									ipk += totalIPK / (recMhs[noID-1].getSemester());
									cout << "IP Kumulatif : " << ipk << endl;
									
									do {
     									cout << '\n' << "Press the Enter key to continue.";
   									} while (cin.get() != '\n');
								}
								break;
							case 4:
								continue;
							case 5:
								{
									flag = false;
									system("cls || clear");
								}
								break;			
							case 6:
								{
									system("cls || clear");
									int uhuk;
									bool uhuk1 = true;
									while (uhuk1)
									{
										cout << "Data yang ingin diubah : " << endl;
										cout << "1. Nama" << endl;
										cout << "2. NRP" << endl;
										cout << "3. Tanggal Lahir" << endl;
										cout << "4. Departemen" << endl;
										cout << "5. Tahun Masuk" << endl;
										cout << "6. Semester" << endl;
										cout << "7. SKS Lulus" << endl;
										cout << "8. Mata Kuliah diambil" << endl;
										cout << "9. Kembali ke daftar mahasiswa" << endl;
										cout << "Masukkan pilihan : "; cin >> uhuk;
										switch (uhuk){
										case 1:
											{
												cout << "Masukkan nama baru : ";
												cin.ignore(); getline(cin, nama);
												recMhs[noID-1].setNama(nama);
												cout << "Nama berhasil diubah!";
												sleep(3);
												uhuk1 = false;
											}
											break;
										case 2:
											{
												cout << "Masukkan NRP baru : ";
												cin.ignore(); cin >> nrp;
												recMhs[noID-1].setNRP(nrp);
												cout << "NRP berhasil dirubah!";
												sleep(3);
												uhuk1 = false;
											}
											break;
										case 3:
											{
												bool flagTTL = true;
												while (flagTTL){
													cout << "Masukkan TTL (dd mm yy) : "; cin >> dd >> mm >> yy; cout << endl;

													if (dateValidation(dd, mm, yy)){
														flagTTL = false;
													}else{
														cout << "TTL yang anda masukkan tidak valid!" << endl;
														continue;
													}
												}
												recMhs[noID-1].setTglLahir(dd,mm,yy);
												cout << "TTL berhasil dirubah!";
												sleep(3);
												uhuk1 = false;
											}
											break;
										case 4:
											{
												cout << "Masukkan departemen baru : ";
												cin.ignore(); getline(cin, departemen);
												recMhs[noID-1].setDepartemen(departemen);
												cout << "Departemen berhasil diubah!";
												sleep(3);
												uhuk1 = false;
											}
											break;
										case 5:
											{
												cout << "Masukkan tahun masuk baru : ";
												cin.ignore(); cin >> tahunmasuk;
												recMhs[noID-1].setTahunMasuk(tahunmasuk);
												cout << "Tahun masuk berhasil diubah!";
												sleep(3);
												uhuk1 = false;
											}
											break;
										case 6:
											{
												cout << "Masukkan Semester baru : ";
												cin.ignore(); cin >> semester;
												recMhs[noID-1].setSemester(semester);
												cout << "Semester berhasil diubah!";
												sleep(3);
												uhuk1 = false;
											}
											break;
										case 7:
											{
												cout << "Masukkan SKS Lulus baru : ";
												cin.ignore(); cin >> sksLulus;
												recMhs[noID-1].setSKSLulus(sksLulus);
												cout << "SKS Lulus berhasil diubah!";
												sleep(3);
												uhuk1 = false;
											}
											break;
										case 8:
											{
												int choice, index = 0;
												cout << "Mata Kuliah Mahasiswa " << recMhs[noID-1].getNama() << endl << endl;
												for (long long unsigned int i = 0; i < recMhs[noID-1].matkulTerambil.size(); i++){
													index++;
													cout << index << ". " << "Nama Matkul : "<< recMhs[noID-1].matkulTerambil[i].getMatkul() << endl;
													cout << "   Kode        : " << recMhs[noID-1].matkulTerambil[i].getKodeMatkul() << endl;
													cout << "   SKS         : " << recMhs[noID-1].matkulTerambil[i].getSKSMatkul() << endl;
												}
												cout << endl;
												cout << "Menu Edit Matkul Terambil" << endl;
												// cout << "1. Hapus Mata Kuliah yang sudah diambil" << endl;
												cout << "1. Hapus semua Mata Kuliah diambil" << endl;
												cout << "2. Kembali ke menu sebelumnya" << endl;
												cout << "Pilihan anda : "; cin >> choice;

												switch (choice){
												// case 1:
												// 	{
												// 		int index;
												// 		cout << "Masukkan ID Matkul yang ingin dihapus : " << endl; cin >> index;
												// 		vector<int, string>::iterator it;
												// 		vector<matkul>::iterator it;		
												// ! Must be fixed
														
												// 	}
												// 	break;
													case 1:
														{
															recMhs[noID-1].matkulTerambil.clear();
															cout << "Seluruh Matkul terambil sudah terhapus!" << endl;
															sleep(3);
															system("cls || clear");
														}
														break;
													case 2:
														system("cls || clear");
														continue;
													default:
														defaultError();
														break;
												}
											}
											break;
										case 9:
											{
												uhuk1 = false;
											}
											break;
										default:
											{
												defaultError();
											}
											continue;
										}
									}
									break;
								}
							default:
								defaultError();
								continue;
							}
						}
					}
					break;
				case 5:
					{
						if (recDosen.empty()){
							system("cls || clear");
							cout << "Tidak ada Dosen terdaftar!";
							sleep(3);
							system("cls || clear");
							break;
						}
						int pilihan;
						bool flag = true;
						while (flag){
							system("cls || clear");
							for (long long unsigned int i = 0; i < recDosen.size(); i++){
								cout << recDosen[i].getId() << ". Nama Dosen : " << recDosen[i].getNama() << endl;
								cout << "   NPP : " << recDosen[i].getNPP() << endl << endl;
							}
							
							cout << "Masukkan ID Dosen yang ingin dilihat detailnya : "; cin >> noID;
							if (noID > recDosen.size()){
								cout << endl << "Dosen dengan id " << noID << " tidak ditemukan." << endl;
								continue;
							}

							system("cls || clear");
							cout << recDosen[noID-1].getId() << ". Nama Dosen : " << recDosen[noID-1].getNama() << endl;
							cout << "   NPP : " << recDosen[noID-1].getNPP() << endl;
							cout << "   Tanggal Lahir : " << recDosen[noID-1].getTglLahir() << "/" << recDosen[noID-1].getBulanLahir() << "/" << recDosen[noID-1].getTahunLahir() << endl;
							cout << "   Departemen : " << recDosen[noID-1].getDepartemen() << endl;
							cout << "   Pendidikan Terakhir : " << recDosen[noID-1].getPendidikan() << endl;

							cout << "1. Kembali ke Daftar Dosen " << endl;
							cout << "2. Kembali ke Menu Utama " << endl;
							cout << "3. Edit Detail Dosen" << endl;
							cout << "Masukkan pilihan anda : "; cin >> pilihan;
							
							switch (pilihan){
							case 1:
								continue;
							case 2:
								{
									flag = false;
									system("cls || clear");
								}
								break;		
							case 3:
								{
									system("cls || clear");
									int uhuk;
									bool uhuk1 = true;
									while (uhuk1)
									{
										cout << "Data yang ingin diubah : " << endl;
										cout << "1. Nama" << endl;
										cout << "2. NRP" << endl;
										cout << "3. Tanggal Lahir" << endl;
										cout << "4. Departemen" << endl;
										cout << "5. Pendidikan Terakhir" << endl;
										cout << "6. Kembali ke daftar dosen" << endl;
										cout << "Masukkan pilihan : "; cin >> uhuk;
										switch (uhuk){
										case 1:
											{
												cout << "Masukkan nama baru : ";
												cin.ignore(); getline(cin, nama);
												recDosen[noID-1].setNama(nama);
												cout << "Nama berhasil diubah!" << endl;
												sleep(3);
												uhuk1 = false;
											}
											break;
										case 2:
											{
												cout << "Masukkan NPP baru : ";
												cin.ignore(); cin >> npp;
												recDosen[noID-1].setNPP(npp);
												cout << "NRP berhasil dirubah!" << endl;
												sleep(3);
												uhuk1 = false;
											}
											break;
										case 3:
											{
												bool flagTTL = true;
												while (flagTTL){
													cout << "Masukkan TTL (dd mm yy) : "; cin >> dd >> mm >> yy; cout << endl;

													if (dateValidation(dd, mm, yy)){
														flagTTL = false;
													}else{
														cout << "TTL yang anda masukkan tidak valid!" << endl;
														continue;
													}
												}
												recDosen[noID-1].setTglLahir(dd,mm,yy);
												cout << "TTL berhasil dirubah!" << endl;
												sleep(3);
												uhuk1 = false;
											}
											break;
										case 4:
											{
												cout << "Masukkan departemen baru : ";
												cin.ignore(); getline(cin, departemen);
												recDosen[noID-1].setDepartemen(departemen);
												cout << "Departemen berhasil diubah!" << endl;
												sleep(3);
												uhuk1 = false;
											}
											break;
										case 5:
											{
												cout << "Masukkan pendidikan terakhir baru : ";
												cin.ignore(); getline(cin, pendidikan);
												recDosen[noID-1].setPendidikan(pendidikan);
												cout << "Pendidikan terakhir berhasil diubah!" << endl;
												sleep(3);
												uhuk1 = false;
											}
											break;
										case 6:
											{
												uhuk1 = false;
												break;
											}
										default:
											{
												defaultError();
											}
											continue;
										}
									}
									break;
								}
							default:
								defaultError();
								continue;
							}
						}
					}
					break;
				case 6:
					{
						if (recTendik.empty()){
							system("cls || clear");
							cout << "Tidak ada Tendik terdaftar!";
							sleep(3);
							system("cls || clear");
							break;
						}
						int pilihan;
						bool flag = true;
						while (flag){
							system("cls || clear");
							for (long long unsigned int i = 0; i < recTendik.size(); i++){
								cout << recTendik[i].getId() << ". Nama Tendik : " << recTendik[i].getNama() << endl;
								cout << "   NPP : " << recTendik[i].getNPP() << endl << endl;
							}
							cout << "Masukkan ID Tendik yang ingin dilihat detailnya : "; cin >> noID;
							if (noID > recTendik.size()){
								cout << endl << "Dosen dengan id " << noID << " tidak ditemukan." << endl;
								continue;
							}

							system("cls || clear");
							cout << recTendik[noID-1].getId() << ". Nama Tendik : " << recTendik[noID-1].getNama() << endl;
							cout << "   NPP : " << recTendik[noID-1].getNPP() << endl;
							cout << "   Tanggal Lahir : " << recTendik[noID-1].getTglLahir() << "/" << recTendik[noID-1].getBulanLahir() << "/" << recTendik[noID-1].getTahunLahir() << endl;
							cout << "   Unit : " << recTendik[noID-1].getUnit() << endl;
							
							cout << "1. Kembali ke Daftar Tendik " << endl;
							cout << "2. Kembali ke Menu Utama " << endl;
							cout << "3. Edit Detail Tendik" << endl;
							cout << "Masukkan pilihan anda : "; cin >> pilihan;
							
							switch (pilihan){
							case 1:
								continue;
							case 2:
								{
									flag = false;
									system("cls || clear");
								}
								break;			
							case 3:
								{
									system("cls || clear");
									int uhuk;
									bool uhuk1 = true;
									while (uhuk1)
									{
										cout << "Data yang ingin diubah : " << endl;
										cout << "1. Nama" << endl;
										cout << "2. NPP" << endl;
										cout << "3. Tanggal Lahir" << endl;
										cout << "4. Unit" << endl;
										cout << "5. Kembali ke daftar tendik" << endl;
										cout << "Masukkan pilihan : "; cin >> uhuk;
										switch (uhuk){
										case 1:
											{
												cout << "Masukkan nama baru : ";
												cin.ignore(); getline(cin, nama);
												recTendik[noID-1].setNama(nama);
												cout << "Nama berhasil diubah!" << endl;
												sleep(3);
												uhuk1 = false;
											}
											break;
										case 2:
											{
												cout << "Masukkan NPP baru : ";
												cin.ignore(); cin >> npp;
												recTendik[noID-1].setNPP(npp);
												cout << "NRP berhasil dirubah!" << endl;
												sleep(3);
												uhuk1 = false;
											}
											break;
										case 3:
											{
												bool flagTTL = true;
												while (flagTTL){
													cout << "Masukkan TTL (dd mm yy) : "; cin >> dd >> mm >> yy; cout << endl;

													if (dateValidation(dd, mm, yy)){
														flagTTL = false;
													}else{
														cout << "TTL yang anda masukkan tidak valid!" << endl;
														continue;
													}
												}
												recTendik[noID-1].setTglLahir(dd,mm,yy);
												cout << "TTL berhasil dirubah!" << endl;
												sleep(3);
												uhuk1 = false;
											}
											break;
										case 4:
											{
												cout << "Masukkan unit baru : ";
												cin.ignore(); getline(cin, unit);
												recTendik[noID-1].setUnit(unit);
												cout << "Unit berhasil diubah!" << endl;
												sleep(3);
												uhuk1 = false;
											}
											break;
										case 5:
											{
												uhuk1 = false;
												break;
											}
										default:
											{
												defaultError();
											}
											continue;
										}
									}
								}
								break;
							default:
								defaultError();
								continue;
							}
						}
					}
					break;
				case 7:
					{
						int pilihan;
						bool flag = true;
						while (flag){
							system("cls || clear");
							idMatkul++;
							cout << "Masukkan Nama Mata Kuliah : "; cin.ignore(); getline(cin, namaMatkul); cout << endl;
							cout << "Masukkan Kode Matkul : "; cin >> kodeMatkul; cout << endl;
							cout << "Masukkan SKS Matkul : "; cin >> sksMatkul; cout << endl;

							matkul mtkl(idMatkul, namaMatkul, kodeMatkul, sksMatkul);
							recMatkul.push_back(mtkl);

							cout << "Apakah anda ingin mengisi matkul lagi?" << endl;
							cout << "  1. Ya" << endl;
							cout << "  2. Tidak" << endl;
							cout << "Masukkan pilihan anda : ";
							cin >> pilihan;
							if (pilihan == 1){
								continue;
							}else if(pilihan == 2){
								flag = false;
								system("cls || clear");
							}
						}
						break;
					}
					break;
				case 8:
					{
						if (recMatkul.empty()){
							system("cls || clear");
							cout << "Tidak ada Matkul terdaftar!";
							sleep(3);
							system("cls || clear");
							break;
						}
						int pilihan;
						bool flag = true;
						while (flag){
							system("cls || clear");
							for (long long unsigned int i = 0; i < recMatkul.size(); i++){
								cout << recMatkul[i].getIdMatkul() << ". Nama Matkul : " << recMatkul[i].getMatkul() << endl << endl;
							}

							cout << "Masukkan ID Matkul yang ingin dilihat detailnya : "; cin >> noID;
							if (noID > recMatkul.size()){
								cout << endl << "Matkul dengan id " << noID << " tidak ditemukan." << endl;
								continue;
							}
							
							system("cls || clear");
							cout << recMatkul[noID-1].getIdMatkul() << ". Nama Matkul : " << recMatkul[noID-1].getMatkul() << endl;
							cout << "   Kode Matkul : " << recMatkul[noID-1].getKodeMatkul() << endl;
							cout << "   SKS Matkul : " << recMatkul[noID-1].getSKSMatkul() << endl << endl;

							cout << "1. Kembali ke Daftar Matkul " << endl;
							cout << "2. Kembali ke Menu Utama " << endl;
							cout << "3. Edit Detail Matkul" << endl;
							cout << "Masukkan pilihan anda : "; cin >> pilihan;

							switch (pilihan){
							case 1:
								continue;
							case 2:
								{
									flag = false;
									system("cls || clear");
								}
								break;
							case 3:
								{
									system("cls || clear");
									int uhuk;
									bool uhuk1 = true;
									while (uhuk1){
										cout << "Data yang ingin diubah : " << endl;
										cout << "1. Nama Matkul" << endl;
										cout << "2. Kode Matkul" << endl;
										cout << "3. SKS Matkul" << endl;
										cout << "4. Kembali ke menu utama" << endl;
										cout << "Masukkan pilihan : "; cin >> uhuk;
										switch (uhuk){
										case 1:
											{
												cout << "Masukkan nama matkul baru : ";
												cin.ignore(); getline(cin, namaMatkul);
												recMatkul[noID-1].setMatkul(namaMatkul);
												cout << "Nama matkul berhasil diubah!" << endl;
												sleep(3);
												uhuk1 = false;
											}
											break;
										case 2:
											{
												cout << "Masukkan kode matkul baru : ";
												cin.ignore(); cin >> kodeMatkul;
												recMatkul[noID-1].setKodeMatkul(kodeMatkul);
												cout << "Kode Matkul berhasil diubah!" << endl;
												sleep(3);
												uhuk1 = false;
											}
											break;
										case 3:
											{
												cout << "Masukkan SKS Matkul baru : ";
												cin.ignore(); cin >> sksMatkul;
												recMatkul[noID-1].setSKSMatkul(sksMatkul);
												cout << "SKS Matkul berhasil diubah!" << endl;
												sleep(3);
												uhuk1 = false;
											}
											break;
										case 4:
											{
												uhuk1 = false;
												break;
											}
										default:
											defaultError();
											break;
										}
									}
								}
								break;
							default:
								defaultError();
								break;
							}
						}
					}
					break;
				case 9:
					{
						system("cls || clear");
						userIndex = 0;
						goto program;
					}
					break;
				default:
					{
						defaultError();
					}
					break;
			}
		}
	}

	while (userIndex == 3){
		long long unsigned int inputIDMhs;
		while (1){
			system("cls || clear");
			if (recMhs.empty()){
				cout << "Belum ada mahasiwa ditambahkan!" << endl;
				sleep(3);
				system("cls || clear");
				goto program;
			}
			
			cout << "Selamat datang di Benedetta Academy" << endl << endl;
			for (long long unsigned int i = 0; i < recMhs.size(); i++){
				cout << recMhs[i].getId() << ". Nama : " << recMhs[i].getNama() << endl;
				cout << "    NRP : " << recMhs[i].getNRP() << endl << endl;
			}
			cout << "Masukkan ID Mahasiswa : "; cin >> inputIDMhs;

			while (inputIDMhs > recMhs.size()){
				cout << "ID Mahasiwa tidak ditemukan!" << endl;
				sleep(3);
				break;
			}

			cout << "Selamat datang, " << recMhs[inputIDMhs-1].getNama() << "!" << endl;
			cout << "Data Mahasiwa" << endl;
			cout << "  Nama 	   : " << recMhs[inputIDMhs-1].getNama() << endl;
			cout << "  TTL  	   : " << recMhs[inputIDMhs-1].getTglLahir() << "/" << recMhs[inputIDMhs-1].getBulanLahir() << "/" << recMhs[inputIDMhs-1].getTahunLahir() << endl;
			cout << "  NRP  	   : " << recMhs[inputIDMhs-1].getNRP() << endl;
			cout << "  Departemen  : " << recMhs[inputIDMhs-1].getDepartemen() << endl;
			cout << "  Tahun Masuk : " << recMhs[inputIDMhs-1].getTahunMasuk() << endl;
			cout << "  Semester    : " << recMhs[inputIDMhs-1].getSemester() << endl;
			cout << "  SKS Lulus   : " << recMhs[inputIDMhs-1].getSKSLulus() << endl;
			
			cout << "Menu :" << endl;
			cout << "1. Lihat IP Semester dan IP Kumulatif" << endl;
			cout << "2. Lihat Matkul diambil" << endl;
			cout << "3. Keluar" << endl;
			cout << "-> Silahkan memilih salah satu: ";
			cin >> menu_terpilih;
			switch (menu_terpilih){
			case 1:
				{
					system("cls || clear");
					if (recMhs[inputIDMhs-1].getIPS(1) == 0 && recMhs[inputIDMhs-1].getIPS(2) == 0){
						cout << "IP Semester " << recMhs[inputIDMhs-1].getNama() << " belum diinput!" << endl;
						sleep(3);
						break;
					}

					for (int i = 1; i <= recMhs[inputIDMhs-1].getSemester(); i++){
						cout << "IP Semester " << i << " : " << recMhs[inputIDMhs-1].getIPS(i) << endl;
					}

					float ipk = 0, totalIPK = 0;
					for (int i = 1; i <= recMhs[inputIDMhs-1].getSemester(); i++){
						totalIPK += recMhs[inputIDMhs-1].getIPS(i);
					}

					ipk += totalIPK / (recMhs[inputIDMhs-1].getSemester());
					cout << "IP Kumulatif : " << ipk << endl;				
					do {
     					cout << '\n' << "Press the Enter key to continue.";
   					} while (cin.get() != '\n');
				}
				break;
			case 2:
				{
					system("cls || clear");
					cout << "Mata Kuliah Mahasiswa " << recMhs[noID-1].getNama() << endl << endl;
					for (long long unsigned int i = 0; i < recMhs[noID-1].matkulTerambil.size(); i++){
						cout << recMhs[noID-1].matkulTerambil[i].getIdMatkul() << ". " << "Nama Matkul : "<< recMhs[noID-1].matkulTerambil[i].getMatkul() << endl;
						cout << "   Kode        : " << recMhs[noID-1].matkulTerambil[i].getKodeMatkul() << endl;
						cout << "   SKS         : " << recMhs[noID-1].matkulTerambil[i].getSKSMatkul() << endl;
					}
					int sksDitempuh = 0;
					for (long long unsigned int i = 0; i < recMhs[noID-1].matkulTerambil.size(); i++){
						sksDitempuh += recMhs[noID-1].matkulTerambil[i].getSKSMatkul();
					}
					cout << endl << "SKS yang sedang anda tempuh : " << sksDitempuh << " sks" << endl;

					do {
     					cout << '\n' << "Press the Enter key to continue.";
   					} while (cin.get() != '\n');
				}
				break;
			case 3:
				{
					system("cls || clear");
					userIndex = 0;
					goto program;
				}
				break;
			default:
				defaultError();
				break;
			}
		}
	}

	while (userIndex == 4){
		system("cls || clear");
		cout << "Menu dosen belum dibuat, silahkan kembali ke menu utama." << endl;
		sleep(3);
		do {
     		cout << '\n' << "Press the Enter key to continue.";
		} while (cin.get() != '\n');
		goto program;
	}
	
	while (userIndex == 5){
		system("cls || clear");
		cout << "Menu tendik belum dibuat, silahkan kembali ke menu utama." << endl;
		sleep(3);
		do {
     		cout << '\n' << "Press the Enter key to continue.";
		} while (cin.get() != '\n');
		goto program;
	}
	return 0;
}