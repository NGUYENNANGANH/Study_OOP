#pragma once
#include"GiuLieuCayTrong.h"
using namespace std;

// __________________________Class dữ liệu thu hoạch_________________________________________________________________________

class DuLieuThuHoach : public CayTrong
{
private:
    //don vi tan
    float SanLuongThuHoach;
    //ngay thu hoach cay trong chinh thuc
    string NgayThuHoach;
    //dien tich vung trong
    float DienTich;

public:
    DuLieuThuHoach();
    DuLieuThuHoach(string TenLoai, string MaVungTrong, string NgayTrong, string NguonGoc, string TieuChuanChamSoc, float SanLuongThuHoach, string NgayThuHoach, float DienTich)
        : CayTrong(TenLoai, MaVungTrong, NgayTrong, NguonGoc, TieuChuanChamSoc) {
        this->SanLuongThuHoach = SanLuongThuHoach;
        this->NgayThuHoach = NgayThuHoach;
        this->DienTich = DienTich;
    }
    ~DuLieuThuHoach();
    void nhapData();
    void hienThiCay();
    string getNgayThuHoach();
    void setNgayThuHoach(string NgayThuHoach);
    float getSanLuong();
    void setSanLuong(float SanLuong);
    float getDienTich();
    void setDienTich(float DienTich);
    bool SapXepTheoSL();
    bool SapXepTheoNgayThuHoach();
    friend tm convertStringToDate(const string& date);
};
