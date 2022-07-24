#ifndef __MAHASISWA_HPP__
#define __MAHASISWA_HPP__
	
#include <iostream>
#include <vector>
#include "include/person.hpp"
#include "include/matkul.hpp"

class mahasiswa : public person{
	private:
		std::string nrp;
		std::string departemen;
		int tahunmasuk;
		int semesterke;
		int skslulus;
		float ipk;
		int jumlahMatkul;
		// std::vector<matkul>matkulTerambil;
		std::vector<float> ips;

	public:
		mahasiswa(int id, std::string nama, int dd, int mm, int yy, std::string nrp, std::string departemen, int tahunmasuk, int semesterke, int sksLulus, int jumlahMatkul);
		std::string getNRP();
		void setNRP(std::string newNRP);

		std::string getDepartemen();
		void setDepartemen(std::string newDepartemen);

		void setSemester(int semesterke);
		int getSemester();

		void setTahunMasuk(int tahunmasuk);
		int getTahunMasuk();
		
		void setSKSLulus(int skslulus);
		int getSKSLulus();
		
		float getIPK();
		void setIPK(float ips);
		void hitungIPK();

		void setIPS(int semester, float ips);
		float getIPS(int semester);
		std::vector<float> getAllIPS();

		std::vector<matkul>matkulTerambil;
	};

#endif
