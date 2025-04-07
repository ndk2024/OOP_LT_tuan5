#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
//Bài 7
class GiaSuc
{
    protected:
        double lit_sua;
    private:
        int soluong;
        int sinhcon;
    public:
        GiaSuc()
        {
            sinhcon = rand() % 10 + 1; // ngẫu nhiên sinh con từ 1 đến 10
        }
        void Nhap();
        double Get_lit_sua()
        {
            return lit_sua;
        }
        int Get_sinhcon()
        {
            return sinhcon;
        }
        int Get_soluong()
        {
            return soluong;
        }
        int capnhat_soluong()
        {
            soluong=soluong+sinhcon;
            return soluong;
        }
};

void GiaSuc::Nhap()
{
    cin >> soluong;
}

class Bo : public GiaSuc
{
    public:
        void Xuat()
        {
            cout << "Um bo!" << endl;
        }
        double sua()
        {
            lit_sua = rand() % 21;
            return lit_sua;
        }
};

class Cuu : public GiaSuc
{
    public:
        void Xuat()
        {
            cout << "peee!" << endl;
        }
        double sua()
        {
            lit_sua = rand() % 6;
            return lit_sua;
        }
};

class De : public GiaSuc
{
    public:
        void Xuat()
        {
            cout << "Beeee!" << endl;
        }
        double sua()
        {
            lit_sua = rand() % 11;
            return lit_sua;
        }
};

int main()
{
    // Seed cho hàm sinh số ngẫu nhiên
    srand(static_cast<unsigned int>(time(0)));

    Bo bo;
    De de;
    Cuu cuu;

    cout << "Nhap so luong bo: ";
    bo.Nhap();
    cout << "Nhap so luong de: ";
    de.Nhap();
    cout << "Nhap so luong cuu: ";
    cuu.Nhap();

    // Câu a, khi tất cả bị bỏ đói
    for (int i = 0; i < bo.Get_soluong(); i++)
        bo.Xuat();
    for (int i = 0; i < de.Get_soluong(); i++)
        de.Xuat();
    for (int i = 0; i < cuu.Get_soluong(); i++)
        cuu.Xuat();

    // Câu b
    cout<<"Tong so bo: ";
    int sum_bo=bo.capnhat_soluong();
    cout<<sum_bo<<endl;

    cout<<"Tong so de: ";
    int sum_de=de.capnhat_soluong();
    cout<<sum_de<<endl;

    cout<<"Tong so cuu: ";
    int sum_cuu=cuu.capnhat_soluong();
    cout<<sum_cuu<<endl;

    int sum_sua=bo.sua()*sum_bo+de.sua()*sum_de+cuu.sua()*sum_cuu;
    cout<<"Tong so lit sua ma gia suc cho: ";
    cout<<sum_sua<<endl;
    return 0;
}

