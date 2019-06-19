#include "NhanVien_TV.h"
wstring NhanVien_TV::getHoTen() { return this->hoten; }
wstring NhanVien_TV::getChucVu() { return this->chucvu; }
wstring NhanVien_TV::getNgaySinh() { return this->ngaysinh; }
float NhanVien_TV::getHeSoLuong() { return this->hesoluong; }
void NhanVien_TV::setHoTen(wstring ht) { this->hoten = ht; };
void NhanVien_TV::setChucVu(wstring cv) { this->chucvu = cv; };
void NhanVien_TV::setNgaySinh(wstring ns) { this->ngaysinh = ns; };
void NhanVien_TV::setHeSoLuong(float hsl) { this->hesoluong = hsl; };
void NhanVien_TV::hienThi() {
	wcout << hoten << '\t' << chucvu << '\t' << ngaysinh << '\t' << hesoluong << endl;
}
NhanVien_TV::NhanVien_TV()
{
}
NhanVien_TV::~NhanVien_TV()
{
}
NhanVien_TV::NhanVien_TV(wstring hoten, wstring chucvu, wstring ngaysinh, float hsl)
{
	this->hoten = hoten;
	this->chucvu = chucvu;
	this->ngaysinh = ngaysinh;
	this->hesoluong = hsl;
}
bool NhanVien_TV::operator==(const NhanVien_TV& nv) const {
	return (hoten == nv.hoten) && (ngaysinh == nv.ngaysinh) && (chucvu == nv.chucvu) && (hesoluong == nv.hesoluong);
}