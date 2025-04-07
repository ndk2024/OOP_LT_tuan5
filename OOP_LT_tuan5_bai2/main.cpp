#include <iostream>
#include <string>

using namespace std;

class Sach
{
    private:
        string maSach;
        string ngayNhap;
        double donGia;
        string NXB;
        int SL;
        double ThanhTien;
        string loaiSach;
    public:
        Sach();
        ~Sach();
        virtual void Nhap();
        void Xuat();
        virtual void TinhThanhTien()=0;
        double GetThanhTien()
        {
            return ThanhTien;
        };
        double GetDonGia()
        {
            return donGia;
        };
};
Sach::Sach(){};
Sach::~Sach(){};
void Sach::Nhap()
{
    cin.ignore();
    cout<<"Nhap loai sach (SGK/STK) : ";
    getline(cin, loaiSach);
    cout<<"Nhap ma sach: ";
    getline(cin, maSach);
    cout<<"Nhap ngay nhap sach: ";
    getline(cin, ngayNhap);
    cout<<"Don gia: ";
    cin>>donGia;
    cout<<"Nhap so luong sach: ";
    cin>>SL;
    cin.ignore();
    cout<<"Nha xuat ban: ";
    getline(cin, NXB);
}
void Sach:: Xuat()
{

}
class SGK:public Sach
{
    private:
        bool sachMoi;
    public:
        SGK();
        ~SGK();
        void Nhap();
        void Xuat();
        void TinhThanhTien();
};

class STK:public Sach
{
    private:
        double thue;
    public:
        STK();
        ~STK();
        void Nhap();
        void Xuat();
        void TinhThanhTien();

};

class QuanLy
{
    private:
        Sach *DS_sach[20];
        int n;
        int check;
    public:
        QuanLy();
        void Nhap();
        void Xuat();
        void TinhTongThanhTien();
        void TinhTBDG_STK();
        void XuatDS_NXB();
        void run();
};

void QuanLy::Nhap()
{
    int loai = -1;
    do
    {
        cout<<"Nhap so luong tong: ";
        cin>>n;
    }while(n<0||n>20);

    for(int i=0; i<n; i++)
    {
        cout<<"Cho biet loai sach can nhap (0=SGK, 1=STK): ";
        cin>>loai;
        if(loai==0)
            Sach[i]=new SGK();
        else
            Sach[i]=new STK();
        Sach[i].Nhap();
    }
}
int main()
{

    return 0;
}
