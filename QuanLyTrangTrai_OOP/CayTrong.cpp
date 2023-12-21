#include "CayTrong.h"


void CayTrong::nhapData()
{
    //	cin.ignore();
    cout << "Nhap ten cay: ";
    getline(cin, TenLoai);
    cout << "Nhap ma vung trong: ";
    getline(cin, MaVungTrong);
    cout << "Nhap ngay trong: ";
    getline(cin, NgayTrong);
    cout << "Nhap xuat xu cay trong: ";
    getline(cin, NguonGoc);
    cout << "Nhap tieu chuan cham soc: ";
    getline(cin, TieuChuanChamSoc);
}

void CayTrong::hienThiCay() const
{
    cout << setw(20) << left << TenLoai
        << setw(20) << left << MaVungTrong
        << setw(20) << left << NgayTrong
        << setw(20) << left << NguonGoc
        << setw(25) << left << TieuChuanChamSoc;
}

string CayTrong::getTenLoai() const
{
    return TenLoai;
}
void CayTrong::setTenLoai(string TenLoai) {
    this->TenLoai = TenLoai;
}
string CayTrong::getMaVungTrong()
{
    return MaVungTrong;
}
void CayTrong::setMaVungTrong(string MaVungTrong) {
    this->MaVungTrong = MaVungTrong;
}
string CayTrong::getTieuChuanChamSoc() {
    return TieuChuanChamSoc;
}
void CayTrong::setTieuChuanChamSoc(string TieuChuanChamSoc) {
    this->TieuChuanChamSoc = TieuChuanChamSoc;
}
CayTrong::CayTrong() {

}

CayTrong::~CayTrong() {

}

bool CayTrong::traCuu(string MaVungTrong, string check) {
    if (MaVungTrong == check) {
        return true;
    }
    return false;
}