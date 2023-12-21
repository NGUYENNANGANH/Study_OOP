#pragma once
#include<iostream>
#include<string>
#include<vector>
#include <iomanip>
#include <algorithm>
#include<sstream>
#include <regex>
#include <fstream>
#include <ctime>
using namespace std;


class CayTrong {
protected:
    string TenLoai;
    string MaVungTrong;
    string NgayTrong;
    string NguonGoc;
    string TieuChuanChamSoc;
public:
    CayTrong();
    CayTrong(string TenLoai, string MaVungTrong, string NgayTrong, string NguonGoc, string TieuChuanChamSoc) {
        this->TenLoai = TenLoai;
        this->MaVungTrong = MaVungTrong;
        this->NgayTrong = NgayTrong;
        this->NguonGoc = NguonGoc;
        this->TieuChuanChamSoc = TieuChuanChamSoc;
    }
    ~CayTrong();
    string getTenLoai() const;
    void setTenLoai(string TenLoai);
    string getMaVungTrong();
    void setMaVungTrong(string MaVungTrong);
    string getTieuChuanChamSoc();
    void setTieuChuanChamSoc(string TieuChuanChamSoc);
    void nhapData();
    void hienThiCay() const;
    bool traCuu(string MaVungTrong, string check);

};
