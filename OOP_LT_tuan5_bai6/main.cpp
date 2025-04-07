#include <iostream>
#include <bits/stdc++.h>
//Bài 6
using namespace std;

class SinhVien
{
    private:
        string MSSV;
        string hoTen;
        string diaChi;
        int tinchi;
        double gpa;
    public:
        void Nhap();
        void Xuat();
        double Getgpa()
        {
            return gpa;
        };
        int GetTinChi()
        {
            return tinchi;
        }

};
void SinhVien:: Nhap()
{
    cin.ignore();
    cout<<"Nhap MSSV: ";
    getline(cin, MSSV);
    cout<<"Nhap Ho ten: ";
    getline(cin, hoTen);
    cout<<"Nhap dia chi: ";
    getline(cin, diaChi);
    cout<<"Nhap tong so tin chi: ";
    cin>>tinchi;
    cin.ignore();
}
void SinhVien::Xuat()
{
    cout << left << setw(20) << MSSV
         << left << setw(15) << hoTen
         << left << setw(10) << diaChi
         << left << setw(5) << tinchi;
}
class DaiHoc:public SinhVien
{
    private:
        double diemLV;
        string tenLV;
    public:
        void Nhap();
        void Xuat();
        double GetdiemLV()
        {
           return diemLV;
        }

};

void DaiHoc::Nhap()
{
    SinhVien::Nhap();
    cout<<"Nhap ten luan van: ";
    getline(cin,tenLV);
    cout<<"Nhap diem luan van: ";
    cin>>diemLV;
}
void DaiHoc::Xuat()
{
    SinhVien::Xuat();
    cout<<tenLV<<endl;
    cout<<diemLV<<endl;
}
class CaoDang:public SinhVien
{
    private:
        double diemThi;
    public:
        void Nhap();
        void Xuat();
        double GetdiemThi()
        {
            return diemThi;
        }

};
void CaoDang::Nhap()
{
    SinhVien::Nhap();
    cout<<"Nhap diem thi tot nghiep: ";
    cin>>diemThi;
}
void CaoDang::Xuat()
{
    SinhVien::Xuat();
    cout<<diemThi<<endl;
}
class QuanLy
{
    private:
        DaiHoc a[5];
        CaoDang b[5];
        int n,m;
    public:
        void NhapDH();
        void NhapCD();
        void Xuat_SV();
        void Xuat_dk();// Xuất danh sách sinh viên đủ điều kiện tốt nghiệp
        void Xuat_khong();
        void top1();
        void run();
};
void QuanLy::NhapDH()
{
    do
    {
        cout<<"Nhap so sinh vien Dai Hoc: ";
        cin>>n;
    }while(n<0||n>5);

    for(int i=0; i<n;i++)
    {
        a[i].Nhap();
    }
}
void QuanLy::NhapCD()
{
    do
    {
        cout<<"Nhap so sinh vien Cao Dang: ";
        cin>>m;
    }while(m<0||m>5);

    for(int i=0; i<m;i++)
    {
        b[i].Nhap();
    }
}
void QuanLy::Xuat_SV()
{
    cout<<"Danh sach Sinh vien Dai Hoc: "<<endl;
    for(int i=0; i<n;i++)
    {
        a[i].Xuat();
    }
    cout<<endl;
    cout<<"Danh sach Sinh vien Cao Dang: "<<endl;
    for(int i=0; i<m; i++)
    {
        b[i].Xuat();
    }
    cout<<endl;
}
void QuanLy::Xuat_dk()
{
    cout<<"Danh sach tot nghiep Dai hoc: "<<endl;
    for(int i=0; i<n; i++)
    {
        if(a[i].GetTinChi()>=145 && a[i].Getgpa()>=5 && a[i].GetdiemLV()>=5)
            a[i].Xuat();
    }

    cout<<endl;
    cout<<"Danh sach tot nghiep Cao Dang: "<<endl;
    for(int i=0; i<m; i++)
    {
        if(b[i].GetTinChi()>=110 && b[i].GetdiemThi()>=5 && b[i].Getgpa()>=5)
            b[i].Xuat();
    }
    cout<<endl;
}

void QuanLy::Xuat_khong()
{
    cout<<"Danh sach khong tot nghiep Dai hoc: "<<endl;
    for(int i=0; i<n; i++)
    {
        if(!(a[i].GetTinChi()>=145 && a[i].Getgpa()>=5 && a[i].GetdiemLV()>=5))
            a[i].Xuat();
    }

    cout<<endl;
    cout<<"Danh sach tot khong nghiep Cao Dang: "<<endl;
    for(int i=0; i<m; i++)
    {
        if(!(b[i].GetTinChi()>=110 && b[i].GetdiemThi()>=5 && b[i].Getgpa()>=5))
            b[i].Xuat();
    }
    cout<<endl;
}

void QuanLy::top1()
{
    double top = 0;
    int index_cd=-1;
    int index_dh=index_cd;
    for(int i=0; i<n; i++)
    {
        if(a[i].Getgpa()>top)
        {
            top=a[i].Getgpa();
            index_dh=i;
        }
    }
    top =0;
    for(int i=0; i<m; i++)
    {
        if(b[i].Getgpa()>top)
        {
            top=b[i].Getgpa();
            index_cd=i;
        }
    }
    a[index_dh].Xuat();
    b[index_cd].Xuat();
}
void QuanLy::run() {
    int check = 0;
    do {
        cout << "1. Nhap danh sach Sinh Vien DH.\n";
        cout << "2. Nhap danh sach Sinh Vien CD." << endl;
        cout << "3. Xem danh sach Sinh Vien." << endl;
        cout << "4. Xem danh sach Sinh Vien du dieu kien tot nghiep" << endl;
        cout << "5. Xem danh sach Sinh Vien khong du dieu kien" << endl;
        cout << "6. Cho biet sinh vien có gpa cao nhat." << endl;
        cout << "7. Thoat.";
        cout << "Moi ban chon cong viec: ";
        cin >> check;

        switch (check) {
        case 1: QuanLy::NhapDH(); break;
        case 2: QuanLy::NhapCD(); break;
        case 3: QuanLy::Xuat_SV(); break;
        case 4: QuanLy::Xuat_dk(); break;
        case 5: QuanLy::Xuat_khong(); break;
        case 6: QuanLy::top1();
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
