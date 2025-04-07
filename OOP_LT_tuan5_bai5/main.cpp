#include <iostream>
#include <bits/stdc++.h>
//Bài 5
using namespace std;
class NhanVien
{
    protected:
        string hoTen;
        string ngaySinh;
        double luong;
    public:
        NhanVien();
        void Nhap();
        void Xuat();
        double getLuong()const
        {
            return luong;
        }
        ~NhanVien();
};

NhanVien :: NhanVien()
{
    hoTen="";
    ngaySinh="";
    luong=0;
}
NhanVien::~NhanVien(){};

void NhanVien::Nhap()
{
    cin.ignore();
    cout<<"Nhap ho ten: ";
    getline(cin, hoTen);
    cout<<"Nhap ngay sinh: ";
    getline(cin, ngaySinh);
}

void NhanVien:: Xuat()
{
    cout << left << setw(20) << hoTen
         << left << setw(15) << ngaySinh
         << left << setw(10) << fixed << setprecision(0) << luong;
    cout<<endl;
}

class NVVP:public NhanVien
{
    private:
        int soNgayLam;
    public:
        void Nhap();
        void TinhLuong();
};
void NVVP::Nhap()
{
    NhanVien::Nhap();
    cout<<"So ngay lam: ";
    cin>>soNgayLam;
}
void NVVP::TinhLuong()
{
    luong=soNgayLam*100000;
}
class NVSX:public NhanVien
{
    private:
        double luongcb;
        int soSP;
    public:
        void Nhap();
        void TinhLuong();
};

void NVSX::Nhap()
{
    NhanVien::Nhap();
    cout<<"Nhap luong can ban: ";
    cin>>luongcb;
    cout<<"Nhap so san pham: ";
    cin>>soSP;
}
void NVSX::TinhLuong()
{
    luong=luongcb + soSP*5000;
}

class QuanLy
{
    private:
        NVVP a[5];
        NVSX b[5];
        int n,m;
    public:
        void NhapVP();
        void NhapSX();
        void XuatVP();
        void XuatSX();
        void TongLuong();
        void run();
};

void QuanLy:: TongLuong()
{
    double sum=0;
    for(int i=0;i<n; i++)
    {
        a[i].TinhLuong();
        sum+=a[i].getLuong();
    }
    for(int i=0; i<m; i++)
    {
        b[i].TinhLuong();
        sum+=b[i].getLuong();
    }
    cout<<"Tong luong can tra: "<<sum<<endl;
}
void QuanLy::NhapVP()
{
    do
    {
        cout<<"Nhap so NVVP: ";
        cin>>n;
    }while(n<0||n>5);

    for(int i=0; i<n; i++)
    {
        a[i].Nhap();
    }
}
void QuanLy::XuatSX()
{
    for(int i=0; i<m; i++)
    {
        b[i].Xuat();
    }
}

void QuanLy::XuatVP()
{
    for(int i=0; i<n; i++)
    {
        a[i].Xuat();
    }
}
void QuanLy::NhapSX()
{
    do
    {
        cout<<"Nhap so NVSX: ";
        cin>>m;
    }while(m<0||m>5);
    for(int i=0; i<m; i++)
    {
        b[i].Nhap();
    }
}
void QuanLy::run() {
    int check = 0;
    do {
        cout << "1. Nhap danh sach NVVP.\n";
        cout << "2. Xem danh sach NVVP." << endl;
        cout << "3. Nhap danh sach NVSX." << endl;
        cout << "4. Xem danh sach NVSX" << endl;
        cout << "5. Tong luong can tra" << endl;
        cout << "6. Thoat" << endl;
        cout << "Moi ban chon cong viec: ";
        cin >> check;

        switch (check) {
        case 1: QuanLy::NhapVP(); break;
        case 2: QuanLy::XuatVP(); break;
        case 3: QuanLy::NhapSX(); break;
        case 4: QuanLy::XuatSX(); break;
        case 5: QuanLy::TongLuong(); break;
        default: exit(0);
        }

    } while (check >= 1 && check <= 5);
}
int main()
{
    QuanLy a;

    a.run();
    return 0;
}
