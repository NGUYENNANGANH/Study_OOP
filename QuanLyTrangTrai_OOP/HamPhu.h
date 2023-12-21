#pragma once

#include"GiaSuc.h"
#include"GiaCam.h"

#include "GiuLieuThuHoach.h"


// Ham khung lua chon
void KhungChon1()
{
    cout << setw(35) << ' ' << "  +--------------------------------------+" << endl;
    cout << setw(35) << ' ' << "  |   1. Chon dong vat gia cam           |" << endl;
    cout << setw(35) << ' ' << "  |   2. Chon dong vat gia suc           |" << endl;
    cout << setw(35) << ' ' << "  +--------------------------------------+" << endl;
}

// HAM KHUNG THONG BAO KHONG CO THONG TIN
void KhungKhongCo()
{
    cout << setw(35) << ' ' << "  +--------------------------------------+" << endl;
    cout << setw(35) << ' ' << "  |      KHONG CO THONG TIN LOAI NAY     |" << endl;
    cout << setw(35) << ' ' << "  +--------------------------------------+" << endl;
}

// KHUNG IN DONG VAT GIA CAM
void KhungDongVatGiaCam(GiaCam a)
{
    string separator(134, '-');
    cout << separator << endl;
    cout << setw(61) << setfill(' ') << ' ' << "DANH SACH " << a.GetTenLoai() << endl;
    cout << separator << endl;
    cout << left
        << setw(18) << "Ten loai"
        << setw(18) << "So luong"
        << setw(23) << "Thuc an chinh"
        << setw(39) << "Tinh trang suc khoe"
        << "So nam nuoi" << endl;
    cout << separator << endl;
}

void KhungDongVatGiaCam(string Ten)
{
    string separator(134, '-');
    cout << separator << endl;
    cout << setw(61) << setfill(' ') << ' ' << "DANH SACH " << Ten << endl;
    cout << separator << endl;
    cout << left
        << setw(18) << "Ten loai"
        << setw(18) << "So luong"
        << setw(23) << "Thuc an chinh"
        << setw(39) << "Tinh trang suc khoe"
        << "So nam nuoi" << endl;
    cout << separator << endl;
}

// KHUNG DONG VAT GIA SUC
void KhungGiaSuc(string TenLoai)
{
    string separator(116, '-');
    cout << separator << endl;
    cout << setw(51) << setfill(' ') << ' ' << "DANH SACH " << TenLoai << endl;
    cout << separator << endl;
    cout << left << setw(16) << "Ma loai"
        << setw(21) << "Trong luong"
        << setw(18) << "Thuc an chinh"
        << setw(39) << "Tinh trang suc khoe"
        << "So nam nuoi" << endl;
    cout << separator << endl;
}

void NhapThongTin(vector<vector<GiaSuc>>& c, vector<GiaCam>& b)
{
    KhungChon1();
    cout << "NHAP LUA CHON: ";
    int n;
    cin >> n;
    cin.ignore();
    if (n == 1)
    {
        int i = 0;
        cout << "NHAP SO LOAI BAN MUON THEM: ";
        int a;
        cin >> a;
        cin.ignore();
        for (i = 0; i < a; i++)
        {
            GiaCam c;
            c.Nhap();
            b.push_back(c);
        }
    }
    if (n == 2)
    {
        cout << "Nhap so loai ban muon them vao: ";
        int SoLoai;
        cin >> SoLoai;
        cin.ignore();
        for (int k = 0; k < SoLoai; k++)
        {
            cout << "-------------------------------------------------------------" << endl;
            cout << "Nhap so luong ban muon them loai " << k + 1 << " : ";
            int a;
            cin >> a;
            cin.ignore();
            for (int i = 0; i < a; i++)
            {
                GiaSuc f;
                f.Nhap();
                bool found = false;
                string TenDongVat = regex_replace(f.GetTenDongVat(), regex("\\d+$"), ""); // Remove trailing digits
                for (auto& vec : c)
                {
                    if (!vec.empty() && regex_replace(vec[0].GetTenDongVat(), regex("\\d+$"), "") == TenDongVat)
                    {
                        vec.push_back(f);
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    c.push_back(vector<GiaSuc>{f});
                }
            }
        }
    }
}

// HAM XEM THONG TIN
void XemThongTin(vector<vector<GiaSuc>> c, vector<GiaCam> b)
{
    KhungChon1();
    cout << "NHAP LUA CHON: ";
    int n;
    cin >> n;
    cin.ignore();

    //Xem thong tin gia suc
    if (n == 2)
    {
        cout << "BAN MUON BIET THONG TIN VE LOAI NAO: ";
        string TenLoai;
        getline(cin, TenLoai);

        regex regexPattern(TenLoai + "\\d+$");

        int CoHieu = 0;
        for (int i = 0; i < c.size(); i++)
        {
            string pp = c[i][0].GetTenDongVat();
            if (regex_search(pp, regexPattern))
            {
                CoHieu += 1;
                cout << setw(35) << ' ' << "  +--------------------------------------+" << endl;
                cout << setw(35) << ' ' << "  |   1. Tat ca thong tin                |" << endl;
                cout << setw(35) << ' ' << "  |   2. Thong tin 1 con                 |" << endl;
                cout << setw(35) << ' ' << "  +--------------------------------------+" << endl;
                cout << "Nhap lua chon: ";
                int Chon;
                cin >> Chon;
                cin.ignore();
                if (Chon == 1)
                {
                    KhungGiaSuc(TenLoai);
                    for (int j = 0; j < c[i].size(); j++)
                    {

                        c[i][j].In();
                    }
                }
                else if (Chon == 2)
                {
                    cout << "Nhap ma dong vat: ";
                    string MaDv;
                    getline(cin, MaDv);
                    KhungGiaSuc(TenLoai);
                    for (int j = 0; j < c[i].size(); j++)
                    {
                        if (c[i][j].GetTenDongVat() == MaDv)
                            c[i][j].In();
                    }
                    break;
                }
            }

        }
        if (CoHieu == 0)
        {
            KhungKhongCo();
        }
    }

    //Xem thong tin gia cam
    if (n == 1)
    {
        cout << setw(35) << ' ' << "  +--------------------------------------+" << endl;
        cout << setw(35) << ' ' << "  |   1. Tat ca thong tin                |" << endl;
        cout << setw(35) << ' ' << "  |   2. Thong tin 1 loai                |" << endl;
        cout << setw(35) << ' ' << "  +--------------------------------------+" << endl;
        cout << "Nhap lua chon: ";
        int n;
        cin >> n;
        cin.ignore();
        if (n == 1)
        {
            string a = "DONG VAT GIA CAM";
            KhungDongVatGiaCam(a);
            for (int i = 0; i < b.size(); i++)
            {
                b[i].In();
            }
        }

        if (n == 2)
        {
            string TenLoai;
            cout << "Nhap ten loai ban muon xem: ";
            getline(cin, TenLoai);
            regex regexPattern(TenLoai); // Pattern to match the input directly

            int CoHieu1 = 0;
            KhungDongVatGiaCam(TenLoai);
            for (int i = 0; i < b.size(); i++)
            {
                if (regex_match(b[i].GetTenLoai(), regexPattern))
                {
                    CoHieu1 += 1;
                    b[i].In();
                }
            }
            if (CoHieu1 == 0)
            {
                KhungKhongCo();
            }
        }
    }
}

// HAM CAP NHAT THONG TIN
void CapNhatThongTin(vector<vector<GiaSuc>>& c, vector<GiaCam>& b)
{
    KhungChon1();
    int n;
    cout << "NHAP LUA CHON: ";
    cin >> n;
    cin.ignore();

    // cap nhat thong tin dong vat dong vat gia cam
    if (n == 1)
    {
        cout << "NHAP TEN LOAI BAN MUON CHINH SUA THONG TIN: ";
        string TenLoai;
        getline(cin, TenLoai);
        for (int i = 0; i < b.size(); i++)
        {
            if (b[i].GetTenLoai() == TenLoai)
            {

                cout << setw(35) << ' ' << "+--------------------------------------+" << endl;
                cout << setw(35) << ' ' << "| 1. Cap Nhat Ten Loai                 |" << endl;
                cout << setw(35) << ' ' << "| 2. Cap Nhat So Luong                 |" << endl;
                cout << setw(35) << ' ' << "| 3. Cap Nhat Thuc An                  |" << endl;
                cout << setw(35) << ' ' << "| 4. Cap Nhat Tinh Trang Suc Khoe      |" << endl;
                cout << setw(35) << ' ' << "| 5. Cap Nhat So Nam Nuoi              |" << endl;
                cout << setw(35) << ' ' << "+--------------------------------------+" << endl;
                cout << "Chon thong tin ban muon cap nhat(VD:1 2 3): ";

                string LuaChon;
                getline(cin, LuaChon);
                stringstream ss(LuaChon);
                string LuaChon1;
                while (getline(ss, LuaChon1, ' '))
                {
                    if (LuaChon1 == "1")
                    {
                        cout << "Nhap ten loai ban muon thay doi: ";
                        string TenLoai;
                        getline(cin, TenLoai);
                        b[i].setTenLoai(TenLoai);
                    }
                    else if (LuaChon1 == "2")
                    {
                        cout << "Nhap so luong ban muon thay doi: ";
                        int SoLuong1;
                        cin >> SoLuong1;
                        b[i].setSoLuong(SoLuong1);
                    }
                    else if (LuaChon1 == "3")
                    {
                        cout << "Nhap thuc an ban muon thay doi: ";
                        string ThucAn;
                        cin.ignore();
                        getline(cin, ThucAn);
                        b[i].setThucAnChinh(ThucAn);
                    }
                    else if (LuaChon1 == "4")
                    {
                        cout << "Nhap tinh trang suc khoe: ";
                        string TinhTrangSucKhoe;
                        getline(cin, TinhTrangSucKhoe);
                        b[i].setTinhTrangSucKhoe(TinhTrangSucKhoe);
                    }
                    else if (LuaChon1 == "5")
                    {
                        cout << "Nhap so nam nuoi: ";
                        float SoNamNuoi;
                        cin >> SoNamNuoi;
                        b[i].setSoNamNuoi(SoNamNuoi);
                    }
                }
            }
        }
    }

    // cap nhat thong tin cua dong vat gia suc
    else if (n == 2)
    {
        cout << "NHAP MA DONG VAT BAN MUON THAY DOI(VD: BO0001): ";
        string TenLoai;
        getline(cin, TenLoai);
        regex regexPattern(TenLoai);
        for (int i = 0; i < c.size(); i++)
        {
            string pp = c[i][0].GetTenDongVat();
            if (regex_search(pp, regexPattern))
            {
                for (int j = 0; j < c[i].size(); j++)
                {
                    if (c[i][j].GetTenDongVat() == TenLoai)
                    {
                        cout << setw(35) << ' ' << "  +--------------------------------------+" << endl;
                        cout << setw(35) << ' ' << "  | 1. Cap nhat ma loai                  |" << endl;
                        cout << setw(35) << ' ' << "  | 2. Cap nhat thuc an chinh            |" << endl;
                        cout << setw(35) << ' ' << "  | 3. Cap nhat so nam nuoi              |" << endl;
                        cout << setw(35) << ' ' << "  | 4. Cap nhat trong luong              |" << endl;
                        cout << setw(35) << ' ' << "  | 5. Cap nhat tinh trang suc khoe      |" << endl;
                        cout << setw(35) << ' ' << "  +--------------------------------------+" << endl;
                        cout << "Chon thong tin ban muon cap nhat (VD: 1 2 3): ";
                        string LuaChon;
                        getline(cin, LuaChon);
                        stringstream ss(LuaChon);
                        string LuaChon1;
                        while (getline(ss, LuaChon1, ' '))
                        {
                            if (LuaChon1 == "1")
                            {
                                cout << "Cap nhat ma loai: ";
                                string MaLoai;
                                getline(cin, MaLoai);
                                c[i][j].setMaLoai(MaLoai);
                            }
                            else if (LuaChon1 == "2")
                            {
                                cout << "Cap nhat thuc an chinh: ";
                                string ThucAnChinh;
                                getline(cin, ThucAnChinh);
                                c[i][j].setThucAnChinh(ThucAnChinh);
                            }
                            else if (LuaChon1 == "3")
                            {
                                cout << "Cap nhat so nam nuoi: ";
                                float SoNamNuoi;
                                cin >> SoNamNuoi;
                                cin.ignore();
                                c[i][j].setSoNamNuoi(SoNamNuoi);
                            }
                            else if (LuaChon1 == "4")
                            {
                                cout << "Cap nhat trong luong: ";
                                float TrongLuong;
                                cin >> TrongLuong;
                                cin.ignore();
                                c[i][j].setTrongLuong(TrongLuong);
                            }
                            else
                            {
                                cout << "Cap nhat tinh trang suc khoe: ";
                                string TinhTrangSucKhoe;
                                getline(cin, TinhTrangSucKhoe);
                                c[i][j].setTinhTrangSucKhoe(TinhTrangSucKhoe);
                            }
                        }
                    }
                }

                break;
            }
        }
    }
}

// Ham so sanh de sap xep theo trong luong
bool cmp(GiaSuc c, GiaSuc b)
{
    return c.GetTrongLuong() < b.GetTrongLuong();
}

// Ham sap xep vector theo trong luong su dung std::sort
void SapXepTheoCanNang(vector<vector<GiaSuc>>& c, vector<GiaCam>& b)
{
    cout << "NHAP MA DONG VAT BAN MUON SAP XEP THEO CAN NANG(VD: BO): ";
    string TenLoai;
    getline(cin, TenLoai);
    regex regexPattern(TenLoai);
    for (int i = 0; i < c.size(); i++)
    {
        string pp = c[i][0].GetTenDongVat();
        if (regex_search(pp, regexPattern))
        {
            sort(c[i].begin(), c[i].end(), cmp);
            break;
        }
    }
    cout << TenLoai << " da duoc sap xep!" << endl;
}

// Ham thong tin cac dong vat co tinh trang suc khoe khong tot
void XuatThongTinDongVatBiBenh(vector<vector<GiaSuc>> c, vector<GiaCam> b)
{

    // Xuat thong tin dong vat gia suc
    for (int i = 0; i < c.size(); i++)
    {
        for (int j = 0; j < c[i].size(); j++)
        {
            if (c[i][j].GetTinhTrangSucKhoe() != "TOT")
            {
                cout << "\nDANH SACH DONG VAT GIA SUC BI BENH" << endl;
                KhungGiaSuc("DONG VAT BI BENH");
                break;
            }
        }
        break;
    }

    for (int i = 0; i < c.size(); i++)
    {
        for (int j = 0; j < c[i].size(); j++)
        {
            if (c[i][j].GetTinhTrangSucKhoe() != "TOT")
            {
                c[i][j].In();
            }
        }
    }

    // Xuat thong tin dong vat gia cam
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i].GetTinhTrangSucKhoe() != "TOT")
        {
            cout << "\n\nDANH SACH DONG VAT GIA CAM BI BENH" << endl;
            KhungDongVatGiaCam("DONG VAT BI BENH");
            break;
        }
    }
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i].GetTinhTrangSucKhoe() != "TOT")
        {
            b[i].In();
        }
    }
}

void XoaDongVat(vector<vector<GiaSuc>>& c, vector<GiaCam>& b, vector<GiaCam>& a1, vector<GiaSuc>& b1)
{
    KhungChon1();
    cout << "MOI BAN CHON: ";
    int Chon;
    cin >> Chon;
    cin.ignore();

    if (Chon == 1)
    {
        cout << "NHAP DONG VAT BAN MUON XOA: ";
        string TenDongVat;
        getline(cin, TenDongVat);

        regex regexPattern(TenDongVat + "\\d*");
        for (int i = 0; i < b.size();)
        {
            if (regex_match(b[i].GetTenLoai(), regexPattern))
            {
                a1.push_back(b[i]);
                b.erase(b.begin() + i);
            }
            else
            {
                ++i;
            }
        }
        cout << "Dong vat " << TenDongVat << " da duoc xoa!" << endl << endl;
    }
    else if (Chon == 2)
    {
        cout << "MA DONG VAT BAN MUON XOA: ";
        string MaDongVat;
        getline(cin, MaDongVat);

        regex regexPattern(MaDongVat);
        for (int i = 0; i < c.size(); i++)
        {
            for (int j = 0; j < c[i].size();)
            {
                string pp = c[i][j].GetTenDongVat();
                if (regex_search(pp, regexPattern))
                {
                    b1.push_back(c[i][j]);
                    c[i].erase(c[i].begin() + j);
                }
                else
                {
                    ++j;
                }
            }

        }
        cout << "Dong vat " << MaDongVat << " da duoc xoa!" << endl;
    }
    else
    {
        cout << "Lua chon khong hop le!";
    }
}

// Ham in thong tin cac dong vat da xoa
void InThongTinDaXoa(vector<GiaCam> a1, vector<GiaSuc> b1)
{


    // In thong tin ve dong vat gia cam bi xoa
    if (!a1.empty()) {
        string a = "GIA CAM BI XOA";
        KhungDongVatGiaCam(a);
        for (const auto& giaCam : a1)
        {
            giaCam.In();
        }
        cout << "\n\n";
    }

    // In thong tin ve dong vat gia suc bi xoa
    if (!b1.empty()) {
        string b = "GIA SUC BI XOA";
        KhungGiaSuc(b);

        for (const auto& giaSuc : b1)
        {
            giaSuc.In();
        }
    }

}






//ham hoi nguoi dung co muon tiep tuc khong
bool askContinue() {
    char answer;
    cout << "Ban co muon nhap tiep khong (y/n)? : ";
    cin >> answer;
    return tolower(answer) == 'y';
}

//ham chuyen doi chu hoa thanh chu thuong
string chuyenDoi(string& str) {
    for (int i = 0; i < str.size(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

//ham tim kiem cay trong theo ten (trong ds du lieu cay trong)

void timKiemCayTheoTen(const vector<DuLieuCayTrong>& dsCayTrong, const string& tenCay) {
    bool found = false;

    cout << "Ket qua tim kiem cho '" << tenCay << "':" << endl;


    cout << setw(20) << left << "Ten cay" << setw(20) << left << "Ma vung trong";
    cout << setw(20) << left << "Ngay trong" << setw(20) << left << "Nguon goc";
    cout << setw(25) << left << "Tieu chuan cham soc" << setw(20) << left << "Ngay nhap";
    cout << setw(20) << left << "So luong" << setw(25) << left << "Tinh trang suc khoe";
    cout << endl;
    cout << endl;
    for (const DuLieuCayTrong& cay : dsCayTrong) {
        if (cay.getTenLoai() == tenCay) {
            cay.hienThiCay();
            found = true;
        }
    }

    if (!found) {
        cout << "Khong tim thay cay co ten '" << tenCay << "' trong danh sach." << endl;
    }
}

