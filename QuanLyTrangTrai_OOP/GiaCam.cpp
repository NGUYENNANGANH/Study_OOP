#include"GiaCam.h"

void GiaCam::In() const
{
    cout << left
        << setw(18) << TenLoai
        << setw(18) << SoLuong;
    DongVat::In();
}

void GiaCam::Nhap()
{
    cout << endl << setw(10) << ' ' << "Ten loai: ";
    getline(cin, TenLoai);
    cout << setw(10) << ' ' << "Nhap so luong: ";
    cin >> SoLuong;
    cin.ignore();
    DongVat::Nhap();
}

void GiaCam::setTinhTrangSucKhoe(string TinhTrangSucKhoe)
{
    this->TinhTrangSucKhoe = TinhTrangSucKhoe;
}
void GiaCam::setSoNamNuoi(float SoNamNuoi)
{
    this->SoNamNuoi = SoNamNuoi;
}
void GiaCam::setSoLuong(int SoLuong)
{
    this->SoLuong = SoLuong;
}
void GiaCam::setThucAnChinh(string ThucAnChinh)
{
    this->ThucAn = ThucAnChinh;
}
void GiaCam::setTenLoai(string TenLoai)
{
    this->TenLoai = TenLoai;
}
string GiaCam::GetTenLoai()
{
    return TenLoai;
}
string GiaCam::GetTinhTrangSucKhoe()
{
    return TinhTrangSucKhoe;
}