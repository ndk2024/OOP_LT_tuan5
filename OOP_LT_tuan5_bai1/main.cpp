#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class cVehicle {
private:
    string maSo;
    string hoten;
    string soXe;
    double doanhthu;

public:
    void Nhap();
    void Xuat();
    double GetDoanhThu();
};

void cVehicle::Nhap() {
    cin.ignore();
    cout << "Nhap ma so: ";
    getline(cin, maSo);
    cout << "Nhap ho ten: ";
    getline(cin, hoten);
    cout << "Nhap so xe: ";
    getline(cin, soXe);
    cout << "Nhap doanh thu: ";
    cin >> doanhthu;
}

void cVehicle::Xuat() {
    cout << maSo << endl;
    cout << hoten << endl;
    cout << soXe << endl;
    cout << doanhthu << endl;
}

double cVehicle::GetDoanhThu() {
    return doanhthu;
}

class cityVehicle : public cVehicle {
private:
    string soTuyen;
    int soKM;

public:
    void Nhap();
    void Xuat();
};

void cityVehicle::Xuat() {
    cVehicle::Xuat();
    cout << soTuyen << endl;
    cout << soKM << endl;
}

void cityVehicle::Nhap() {
    cVehicle::Nhap();
    cout << "Nhap so tuyen: ";
    getline(cin, soTuyen);
    cout << "Nhap so km: ";
    cin >> soKM;
}

class provinceVehicle : public cVehicle {
private:
    string noiDen;
    int soNgay;

public:
    void Nhap();
    void Xuat();
};

void provinceVehicle::Xuat() {
    cVehicle::Xuat();
    cout << noiDen << endl;
    cout << soNgay << endl;
}

void provinceVehicle::Nhap() {
    cVehicle::Nhap();
    cout << "Nhap noi den: ";
    getline(cin, noiDen);
    cout << "Nhap so ngay: ";
    cin >> soNgay;
}

class QuanLy {
private:
    cityVehicle CV[5];
    provinceVehicle PV[5];
    int n, m;

public:
    void NhapXeCV();
    void NhapXePV();
    void XuatXeCV();
    void XuatXePV();
    void Dthu_city();
    void Dthu_prov();
    void TinhDoanhthu();
    void run();
};

void QuanLy::NhapXeCV() {
    do {
        cout << "Nhap so chuyen xe city: ";
        cin >> n;
    } while (n < 1 || n > 5);
    for (int i = 0; i < n; i++) {
        CV[i].Nhap();
    }
}

void QuanLy::NhapXePV() {
    do {
        cout << "Nhap so chuyen xe province: ";
        cin >> m;
    } while (m < 1 || m > 5);

    for (int i = 0; i < m; i++) {
        PV[i].Nhap();
    }
}

void QuanLy::XuatXeCV() {
    for (int i = 0; i < n; i++) {
        CV[i].Xuat();
        cout << endl;
    }
}

void QuanLy::XuatXePV() {
    for (int i = 0; i < m; i++) {
        PV[i].Xuat();
        cout << endl;
    }
}

void QuanLy::TinhDoanhthu() {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += CV[i].GetDoanhThu();
    }
    for (int i = 0; i < m; i++) {
        sum += PV[i].GetDoanhThu();
    }
    cout << "Tong doanh thu ca hai: ";
    cout << sum << endl;
}

void QuanLy::Dthu_city() {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += CV[i].GetDoanhThu();
    }
    cout << "Tong doanh thu city: ";
    cout << sum << endl;
}

void QuanLy::Dthu_prov() {
    double sum = 0;
    for (int i = 0; i < m; i++) {
        sum += PV[i].GetDoanhThu();
    }
    cout << "Tong doanh thu province: ";
    cout << sum << endl;
}

void QuanLy::run() {
    int check = 0;
    do {
        cout << "1. Nhap danh sach xe city.\n";
        cout << "2. Xem danh sach xe city." << endl;
        cout << "3. Nhap danh sach xe province." << endl;
        cout << "4. Xem danh sach xe province" << endl;
        cout << "5. Tong doanh thu city" << endl;
        cout << "6. Tong doanh thu province." << endl;
        cout << "7. Tong doanh thu ca hai" << endl;
        cout << "8. Thoat" << endl;
        cout << "Moi bac chon cong viec: ";
        cin >> check;

        switch (check) {
        case 1: QuanLy::NhapXeCV(); break;
        case 2: QuanLy::XuatXeCV(); break;
        case 3: QuanLy::NhapXePV(); break;
        case 4: QuanLy::XuatXePV(); break;
        case 5: QuanLy::Dthu_city(); break;
        case 6: QuanLy::Dthu_prov(); break;
        case 7: QuanLy::TinhDoanhthu(); break;
        default: exit(0);
        }

    } while (check >= 1 && check <= 7);
}

int main()
{
    QuanLy ql;
    ql.run();
    return 0;
}
