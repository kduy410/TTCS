#include "NhanVien.h"

string NhanVien::getHoTen() { return this->hoten; }
string NhanVien::getChucVu() { return this->chucvu; }
string NhanVien::getNgaySinh() { return this->ngaysinh; }
float NhanVien::getHeSoLuong() { return this->hesoluong; }

void NhanVien::setHoTen(string ht) { this->hoten = ht; };
void NhanVien::setChucVu(string cv) { this->chucvu = cv; };
void NhanVien::setNgaySinh(string ns) { this->ngaysinh = ns; };
void NhanVien::setHeSoLuong(float hsl) { this->hesoluong = hsl; };

void NhanVien::hienThi() {
	cout << hoten << '\t' << chucvu << '\t' << ngaysinh << '\t' << hesoluong << endl;
}

NhanVien::NhanVien()
{
}


NhanVien::~NhanVien()
{
}

NhanVien::NhanVien(string hoten, string chucvu, string ngaysinh, float hsl)
{
	this->hoten = hoten;
	this->chucvu = chucvu;
	this->ngaysinh = ngaysinh;
	this->hesoluong = hsl;
}
bool NhanVien::operator==(const NhanVien& nv) const {
	return (hoten == nv.hoten) && (ngaysinh == nv.ngaysinh) && (chucvu == nv.chucvu) && (hesoluong == nv.hesoluong);
}