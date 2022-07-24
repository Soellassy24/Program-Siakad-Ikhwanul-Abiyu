#ifndef __MATKUL_HPP__
#define __MATKUL_HPP__

class matkul{
    private:
        int idMatkul;
        std::string namaMatkul;
        std::string kodeMatkul;
        int sksMatkul;
    public:
        matkul();
        matkul(int idMatkul, std::string namaMatkul, std::string kodeMatkul, int sksMatkul);

        int getIdMatkul();
        void setIdMatkul(int idMatkul);

	    std::string getMatkul();
        void setMatkul(std::string namaMatkul);
        
        std::string getKodeMatkul();
        void setKodeMatkul(std::string kodeMatkul);

        int getSKSMatkul();
        void setSKSMatkul(int sksMatkul);

        void middleErase(int index);
};

#endif