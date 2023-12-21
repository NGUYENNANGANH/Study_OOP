#pragma once
#include"DongVat.h"
// Class Gia Cam
class GiaCam : public DongVat
{
private:
    int SoLuong;
    string TenLoai;

public:
    // Ham nhap
    void Nhap();
    // Ham in
    void In() const;
    // Ham lay ra tinh trang suc khoe
    string GetTinhTrangSucKhoe();
    // Ham lay ra ten loai
    string GetTenLoai();
    // Ham chinh sua tinh trang suc khoe
    void setTinhTrangSucKhoe(string TinhTrangSucKhoe);
    // Ham chinh sua so nam nuoi
    void setSoNamNuoi(float SoNamNuoi);
    // Ham sua so luong
    void setSoLuong(int SoLuong);
    // Ham chinh sua thuc an
    void setThucAnChinh(string ThucAnChinh);
    // Ham chinh sua ten loai
    void setTenLoai(string TenLoai);
};
