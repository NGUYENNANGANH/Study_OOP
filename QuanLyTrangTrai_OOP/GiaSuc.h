#pragma once
#include"DongVat.h"


// Class Gia Suc
class GiaSuc : public DongVat
{
private:
    string MaLoai;
    float TrongLuong;

public:
    // Ham nhap
    void Nhap();
    // Ham in
    void In() const;
    // Ham lay ma dv
    string GetTenDongVat();
    // Ham lay trong luong
    float GetTrongLuong();
    // Ham lay ra tinh trang suc khoe
    string GetTinhTrangSucKhoe();
    // ham chinh sua MaDv
    void setMaLoai(string MaLoai);
    // ham thay doi thuc an
    void setThucAnChinh(string ThucAnChinh);
    // ham chinh sua so nam nuoi
    void setSoNamNuoi(float SoNamNuoi);
    // ham chinh sua trong luong
    void setTrongLuong(float TrongLuong);
    // ham cap nhat tinh trang suc khoe
    void setTinhTrangSucKhoe(string TinhTrangSucKhoe);
};