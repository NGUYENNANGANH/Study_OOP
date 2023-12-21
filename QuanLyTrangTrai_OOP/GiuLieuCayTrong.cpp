#include"GiuLieuCayTrong.h"


void DuLieuCayTrong::nhapData() {
    CayTrong::nhapData();
    cout << "Ngay nhap cay: ";
    getline(cin, NgayNhap);
    cout << "Nhap so luong cay trong: ";
    cin >> SoLuong;
    cin.ignore();
    cout << "Nhap tinh trang suc khoe cua cay: ";
    getline(cin, TinhTrangSucKhoe);
}


void DuLieuCayTrong::hienThiCay() const {
    CayTrong::hienThiCay();
    cout << setw(20) << left << NgayNhap
        << setw(20) << left << SoLuong
        << setw(25) << left << TinhTrangSucKhoe
        << endl;

}

int DuLieuCayTrong::getSoLuong() {
    return SoLuong;
}
void DuLieuCayTrong::setSoLuong(int SoLuong) {
    this->SoLuong = SoLuong;
}
string DuLieuCayTrong::getTinhTrangSucKhoe() {
    return TinhTrangSucKhoe;
}
void DuLieuCayTrong::setTinhTrangSucKhoe(string TinhTrangSucKhoe) {
    this->TinhTrangSucKhoe = TinhTrangSucKhoe;
}

string DuLieuCayTrong::getNgayNhap() {
    return NgayNhap;
}
void DuLieuCayTrong::setNgayNhap(string NgayNhap) {
    this->NgayNhap = NgayNhap;
}
DuLieuCayTrong::DuLieuCayTrong() {

}
DuLieuCayTrong::~DuLieuCayTrong() {

}

