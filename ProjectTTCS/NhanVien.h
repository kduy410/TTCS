#include <string>
#include <iostream>
using namespace std;
class NhanVien
{
	
public:
	NhanVien();
	NhanVien(string hoten, string chucvu, string ngaysinh, float hesoluong);
	
	~NhanVien();

	string getHoTen();
	string getChucVu();
	string getNgaySinh();
	float getHeSoLuong();

	void setHoTen(string hoten);
	void setChucVu(string hoten);
	void setNgaySinh(string hoten);
	void setHeSoLuong(float hsl);
	
	void hienThi();
	bool operator==(const NhanVien& nv) const;
private:

	string hoten;
	string chucvu;
	string ngaysinh;
	float hesoluong;

};



