#include"DongVat.h"
void DongVat::In() const
{
    cout << left
        << setw(23) << ThucAn
        << setw(39) << TinhTrangSucKhoe
        << SoNamNuoi << endl;
}

void DongVat::Nhap()
{
    cout << setw(10) << ' ' << "So nam nuoi: ";
    cin >> SoNamNuoi;
    cin.ignore();
    cout << setw(10) << ' ' << "Thuc an chinh: ";
    getline(cin, ThucAn);

    cout << setw(10) << ' ' << "Tinh trang suc khoe: ";
    getline(cin, TinhTrangSucKhoe);
}