#include"GiaSuc.h"
void GiaSuc::Nhap()
{
    cout << endl << setw(10) << ' ' << "Ma loai(TenLoai + So : BO1): ";
    getline(cin, MaLoai);
    cout << setw(10) << ' ' << "Trong luong: ";
    cin >> TrongLuong;
    cin.ignore();
    DongVat::Nhap();
}

void GiaSuc::In() const
{

    cout << left << setw(16) << MaLoai
        << setw(21) << TrongLuong;
    DongVat::In();
}

void GiaSuc::setMaLoai(string MaLoai)
{
    this->MaLoai = MaLoai;
}
void GiaSuc::setThucAnChinh(string ThucAnChinh)
{
    this->ThucAn = ThucAnChinh;
}
void GiaSuc::setSoNamNuoi(float SoNamNuoi)
{
    this->SoNamNuoi = SoNamNuoi;
}
void GiaSuc::setTrongLuong(float TrongLuong)
{
    this->TrongLuong = TrongLuong;
}
void GiaSuc::setTinhTrangSucKhoe(string TinhTrangSucKhoe)
{
    this->TinhTrangSucKhoe = TinhTrangSucKhoe;
}
string GiaSuc::GetTenDongVat()
{
    return MaLoai;
}
float GiaSuc::GetTrongLuong()
{
    return TrongLuong;
}
string GiaSuc::GetTinhTrangSucKhoe()
{
    return TinhTrangSucKhoe;
}