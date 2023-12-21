
#include "GiuLieuThuHoach.h"

// Các hàm bạn _____________________________________________________________________________

void DuLieuThuHoach::nhapData() {
    CayTrong::nhapData();
    cout << "Ngay thu hoach chinh thuc: ";
    getline(cin, NgayThuHoach);
    cout << "San luong thu hoach: "; cin >> SanLuongThuHoach;
    cout << "Dien tich vung trong: "; cin >> DienTich;
    cin.ignore();

}

void DuLieuThuHoach::hienThiCay() {
    CayTrong::hienThiCay();
    cout << setw(25) << left << SanLuongThuHoach
        << setw(20) << left << NgayThuHoach
        << setw(20) << left << DienTich
        << endl;

}

string DuLieuThuHoach::getNgayThuHoach()
{
    return NgayThuHoach;
}

void DuLieuThuHoach::setNgayThuHoach(string NgayThuHoach) {
    this->NgayThuHoach = NgayThuHoach;
}
float DuLieuThuHoach::getSanLuong()
{
    return SanLuongThuHoach;
}
void DuLieuThuHoach::setSanLuong(float SanLuong) {
    this->SanLuongThuHoach = SanLuong;
}
float DuLieuThuHoach::getDienTich() {
    return DienTich;
}
void DuLieuThuHoach::setDienTich(float DienTich) {
    this->DienTich = DienTich;
}

tm convertStringToDate(const string& date) {
    tm tm = {};
    stringstream ss(date);
    ss >> get_time(&tm, "%d-%m-%Y");
    return tm;
}

bool SapXepTheoSL(DuLieuThuHoach a, DuLieuThuHoach b) {
    return a.getSanLuong() < b.getSanLuong();
}


bool SapXepTheoNgayThuHoach(DuLieuThuHoach& a, DuLieuThuHoach& b)
{

    tm dateA = convertStringToDate(a.getNgayThuHoach());
    tm dateB = convertStringToDate(b.getNgayThuHoach());
    return mktime(&dateA) < mktime(&dateB);
}

DuLieuThuHoach::DuLieuThuHoach() {

}
DuLieuThuHoach::~DuLieuThuHoach() {

}