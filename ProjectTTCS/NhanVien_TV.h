#include <string>
#include <iostream>
using namespace std;
class NhanVien_TV
{
public:
	NhanVien_TV();
	NhanVien_TV(wstring hoten, wstring chucvu, wstring ngaysinh, float hesoluong);
	~NhanVien_TV();
	wstring getHoTen();
	wstring getChucVu();
	wstring getNgaySinh();
	float getHeSoLuong();
	void setHoTen(wstring hoten);
	void setChucVu(wstring hoten);
	void setNgaySinh(wstring hoten);
	void setHeSoLuong(float hsl);
	void hienThi();
	bool operator==(const NhanVien_TV& nv) const;
private:
	wstring hoten;
	wstring chucvu;
	wstring ngaysinh;
	float hesoluong;
};



