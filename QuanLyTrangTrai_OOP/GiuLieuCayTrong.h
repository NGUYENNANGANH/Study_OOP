#pragma once
#include "CayTrong.h"
using namespace std;

class DuLieuCayTrong : public CayTrong {
private:
    int SoLuong;
    string TinhTrangSucKhoe;
    string NgayNhap;
public:
    DuLieuCayTrong();
    DuLieuCayTrong(string TenLoai, string MaVungTrong, string NgayTrong, string NguonGoc, string TieuChuanChamSoc,
        int SoLuong, string TinhTrangSucKhoe, string NgayNhap) :CayTrong(TenLoai, MaVungTrong, NgayTrong, NguonGoc, TieuChuanChamSoc) {
        this->SoLuong = SoLuong;
        this->TinhTrangSucKhoe = TinhTrangSucKhoe;
        this->NgayNhap = NgayNhap;
    }
    ~DuLieuCayTrong();
    int getSoLuong();
    void setSoLuong(int SoLuong);
    string getTinhTrangSucKhoe();
    void setTinhTrangSucKhoe(string TinhTrangSucKhoe);
    string getNgayNhap();
    void setNgayNhap(string NgayNhap);
    void nhapData();
    void hienThiCay() const;



};

