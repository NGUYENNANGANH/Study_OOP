#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <regex>
#include <fstream>
#include <ctime>

using namespace std;
// Class Dong Vat
class DongVat
{
protected:
    string ThucAn;
    string TinhTrangSucKhoe;
    float SoNamNuoi;

public:
    // Ham in
    void In() const;
    // Ham nhap
    void Nhap();
};
