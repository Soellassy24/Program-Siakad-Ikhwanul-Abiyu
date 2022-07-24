#include <iostream>
#include <conio.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

const int maxYear = 9999;
const int minYear = 1800;

string unameAdm = "admin", passAdm = "admin", unameAdmInput, passAdmInput;
string unameMhs = "mahasiswa", passMhs = "mahasiswa", unameMhsInput, passMhsInput;
string unameDsn = "dosen", passDsn = "dosen", unameDsnInput, passDsnInput;
string unameTndk = "tendik", passTndk = "tendik", unameTndkInput, passTndkInput;
int userIndex = 0;

// enum IN {
// 	IN_BACK = 8, 
// 	IN_RET = 13
// };

// std::string takePass(char sp = '*'){
// 	string pw = "";
// 	char ch_ipt;
// 	while (true){
// 		ch_ipt = getch();
// 		if (ch_ipt == IN::IN_RET){
// 			cout << endl;
// 			return pw;
// 		}else if(ch_ipt == IN::IN_BACK && pw.length() != 0){
// 			pw.pop_back();
// 			cout << "\b \b";
// 			continue;
// 		}else if(ch_ipt == IN::IN_BACK && pw.length() == 0){
// 			continue;
// 		}
// 		pw.push_back(ch_ipt);
// 		cout << sp;
// 	}
// }

bool isLeap(int yyInput){
	return (((yyInput % 4 == 0) && (yyInput % 100 != 0)) || (yyInput % 400 == 0));
}

bool dateValidation(int ddInput, int mmInput, int yyInput){
	if ((yyInput > maxYear) || (yyInput < minYear)) {
		return false;
	}
	if ((mmInput < 1) || (mmInput > 12)){
		return false;
	}
	if ((ddInput < 1) || (ddInput > 31)){
		return false;
	}
	if (mmInput == 2){
		if (isLeap(yyInput)){
			return (ddInput <= 29);
		}else{
			return (ddInput <= 28);
		}
	}
	if ((mmInput == 4) || (mmInput == 6) || (mmInput == 9) || (mmInput == 11)){
		return (ddInput <= 30);
	}
	
	return true;
}

void defaultError(){
	cout << "Pilihan tidak tersedia!" << endl;
	sleep(3);
	system("cls || clear");
}

void login(){
	bool ulangAdm = false, ulangMhs = false, ulangDsn = false, ulangTndk = false, ulangTapiSelamatDatang = true;
	int i = 0, pilihan;
	while (ulangTapiSelamatDatang){
		system("cls || clear");
		cout << "Selamat Datang di Benedetta Academy" << endl;
		cout << "1. Keluar program" << endl;
		cout << "2. Masuk sebagai admin" << endl;
		cout << "3. Masuk sebagai mahasiswa" << endl;
		cout << "4. Masuk sebagai dosen" << endl;
		cout << "5. Masuk sebagai tendik" << endl;
		cout << "Masukkan pilihan anda : "; cin >> pilihan;
		switch (pilihan){
		case 1:
			{
				system("cls || clear");
				exit(0);
			}
		case 2:
			{
				userIndex = 2;
				ulangTapiSelamatDatang = false;
				ulangAdm = true;
			}
			break;
		case 3:
			{
				userIndex = 3;
				ulangTapiSelamatDatang = false;
				ulangMhs = true;
			}
			break;
		case 4:
			{
				userIndex = 4;
				ulangTapiSelamatDatang = false;
				ulangDsn = true;
			}
			break;
		case 5:
			{
				userIndex = 5;
				ulangTapiSelamatDatang = false;
				ulangTndk = true;
			}
			break;
		default:
			defaultError();
			continue;
		}
	}
	while (ulangAdm){
		i++;
		system("cls || clear");
		cout << "Masukkan username (admin) : "; cin >> unameAdmInput; cout << endl;
		cout << "Masukkan password (admin) : "; cin >> passAdmInput; cout << endl;
		if ((unameAdm.compare(unameAdmInput) == 0) && (passAdm.compare(passAdmInput) == 0)){
			ulangAdm = false;
			i = 0;
			break;
		}else if((unameAdm.compare(unameAdmInput) != 0) && (passAdm.compare(passAdmInput) == 0)){
			cout << "Username anda salah!" << endl;
			cout << "Percobaan ke " << i << " dari 5 percobaan";
			sleep(3);
			if (i == 5){
				exit(0);
			}
			continue;
		}else if ((unameAdm.compare(unameAdmInput) == 0) && (passAdm.compare(passAdmInput) != 0)){
			cout << "password anda salah!" << endl;
			cout << "Percobaan ke " << i << " dari 5 percobaan";
			sleep(3);
			if (i == 5){
				exit(0);
			}
			continue;
		}else{
			cout << "Username dan password salah!" << endl;
			cout << "Percobaan ke " << i << " dari 5 percobaan";
			sleep(3);
			if (i == 5){
				exit(0);
			}
			continue;
		}
	}
	while (ulangMhs){
		i++;
		system("cls || clear");
		cout << "Masukkan username (mahasiwa) : "; cin >> unameMhsInput; cout << endl;
		cout << "Masukkan password (mahasiswa) : "; cin >> passMhsInput; cout << endl;
		if ((unameMhs.compare(unameMhsInput) == 0) && (passMhs.compare(passMhsInput) == 0)){
			ulangMhs = false;
			i = 0;
			break;
		}else if((unameMhs.compare(unameMhsInput) != 0) && (passMhs.compare(passMhsInput) == 0)){
			cout << "Username anda salah!" << endl;
			cout << "Percobaan ke " << i << " dari 5 percobaan";
			sleep(3);
			if (i == 5){
				exit(0);
			}
			continue;
		}else if ((unameMhs.compare(unameMhsInput) == 0) && (passMhs.compare(passMhsInput) != 0)){
			cout << "password anda salah!" << endl;
			cout << "Percobaan ke " << i << " dari 5 percobaan";
			sleep(3);
			if (i == 5){
				exit(0);
			}
			continue;
		}else{
			cout << "Username dan password salah!" << endl;
			cout << "Percobaan ke " << i << " dari 5 percobaan";
			sleep(3);
			if (i == 5){
				exit(0);
			}
			continue;
		}
	}
	while (ulangDsn){
		i++;
		system("cls || clear");
		cout << "Masukkan username (dosen) : "; cin >> unameDsnInput; cout << endl;
		cout << "Masukkan password (dosen) : "; cin >> passDsnInput; cout << endl;
		if ((unameDsn.compare(unameDsnInput) == 0) && (passDsn.compare(passDsnInput) == 0)){
			ulangDsn = false;
			i = 0;
			break;
		}else if((unameDsn.compare(unameDsnInput) != 0) && (passDsn.compare(passDsnInput) == 0)){
			cout << "Username anda salah!" << endl;
			cout << "Percobaan ke " << i << " dari 5 percobaan";
			sleep(3);
			if (i == 5){
				exit(0);
			}
			continue;
		}else if ((unameDsn.compare(unameDsnInput) == 0) && (passDsn.compare(passDsnInput) != 0)){
			cout << "password anda salah!" << endl;
			cout << "Percobaan ke " << i << " dari 5 percobaan";
			sleep(3);
			if (i == 5){
				exit(0);
			}
			continue;
		}else{
			cout << "Username dan password salah!" << endl;
			cout << "Percobaan ke " << i << " dari 5 percobaan";
			sleep(3);
			if (i == 5){
				exit(0);
			}
			continue;
		}
	}
	while (ulangTndk){
		i++;
		system("cls || clear");
		cout << "Masukkan username (tendik) : "; cin >> unameTndkInput; cout << endl;
		cout << "Masukkan password (tendik) : "; cin >> passTndkInput; cout << endl;
		if ((unameTndk.compare(unameTndkInput) == 0) && (passTndk.compare(passTndkInput) == 0)){
			ulangTndk = false;
			i = 0;
			break;
		}else if((unameTndk.compare(unameTndkInput) != 0) && (passTndk.compare(passTndkInput) == 0)){
			cout << "Username anda salah!" << endl;
			cout << "Percobaan ke " << i << " dari 5 percobaan";
			sleep(3);
			if (i == 5){
				exit(0);
			}
			continue;
		}else if ((unameTndk.compare(unameTndkInput) == 0) && (passTndk.compare(passTndkInput) != 0)){
			cout << "password anda salah!" << endl;
			cout << "Percobaan ke " << i << " dari 5 percobaan";
			sleep(3);
			if (i == 5){
				exit(0);
			}
			continue;
		}else{
			cout << "Username dan password salah!" << endl;
			cout << "Percobaan ke " << i << " dari 5 percobaan";
			sleep(3);
			if (i == 5){
				exit(0);
			}
			continue;
		}
	}
}