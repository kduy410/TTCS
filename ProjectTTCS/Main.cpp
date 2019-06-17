#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "NhanVien.h"
#include <iomanip>
#include <cstdlib>

using namespace std;

#define M 1024

int StringToInt(string NumberAsString) {
	int NumberAsInt;
	stringstream ss;
	ss << NumberAsString;
	ss >> NumberAsInt;
	return NumberAsInt;
}
string IntToString(int NumberAsInt) {
	string NumberAsString;
	stringstream ss;
	ss << NumberAsInt;
	ss >> NumberAsString;
	return NumberAsString;
}
float StringToFloat(string NumberAsString) {
	float NumberAsFloat;
	stringstream ss;
	ss << NumberAsString;
	ss >> NumberAsFloat;
	return NumberAsFloat;
}
string	FloatToString(float NumberAsFloat) {
	string NumberAsString;
	stringstream ss;
	ss << NumberAsFloat;
	ss >> NumberAsString;
	return NumberAsString;
}
bool Equal(char x, char y) {
	return (x == y) ? true : false;
}
bool Equal(string x, string y) {
	//int pos = 0;
	//if (x[0] == y[0]) {
	//	while (x[pos] != '\0' && y[pos] != '\0') {
	//		if (x[pos] != y[pos]) return false;
	//		else pos++;
	//	}
	//	return true;
	//}
	//else return false;
	return (x == y) ? true : false;
}
bool Equal(string x, char y) {
	int pos = 0;
	while (x != "\0")
	{
		if (x[pos] == y)
			return true;
		else pos++;
	}
	return false;
}
string toLower(const string input) {
	string str = input;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z') {
			//Convert lowercase to uppercase 
			//str[i] = str[i] - 32;
			continue;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z') {
			//Convert uppercase to lowercase 
			str[i] = str[i] + 32;
		}
	}
	return str;
}
string toUpper(const string input) {
	string str = input;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z') {
			//Convert lowercase to uppercase 
			str[i] = str[i] - 32;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z') {
			//Convert uppercase to lowercase 
			//str[i] = str[i] + 32;
			continue;
		}
	}
	return str;
}
string setWidth(string n, int size) {
	int temp = size - (n).length();
	if (temp < 0) {
		return n;
	}
	else {
		for (int i = 0; i < temp; i++)
		{
			n += ' ';
		}
	}
	return n;
}
string setWidth(char x, int size) {
	string temp = &x;
	for (int i = 0; i < size; i++)
	{
		temp += x;
	}
	return temp;
}
int Find(string line, char x)
{
	int pos = 0;
	while (line[pos] != '\0')
	{
		if (Equal(line[pos], x)) {
			return pos;
		}
		else if (line[pos + 1] == '\0') {
			return pos + 1;
		}
		else pos++;
	}
	/*for (int i = 0; i < line.length(); i++)
	{
		if (Equal(line[i], x)) {
			return i;
		}
	}
*/
}
string* Split(string line, char x) {
	string* substring = new string[100];
	int found, pos = 0;
	string temp = line;
	while (temp != "\0") {
		found = Find(temp, x);
		for (int i = 0; i < found; i++)
		{
			substring[pos] += temp[i];
		}
		temp.erase(0, found + 1);
		pos++;
	}
	return substring;
}
string outputBOD(string line) {
	string* a = Split(line, '/');
	string day, mon, year;
	int d = StringToInt(*a);
	int m = StringToInt(*(a + 1));
	if (d > 0 && d < 10) {
		day = "0" + IntToString(d);
	}
	else day = *a;
	if (m > 0 && m < 10) {
		mon = "0" + IntToString(m);
	}
	else mon = *(a + 1);
	string x = day + "/" + mon + "/" + *(a + 2);
	return x;
}
struct LinkedList {
	NhanVien data;
	struct LinkedList* next;
};
typedef LinkedList* node;//Thay kiểu dữ liệu = NODE cho ngắn gọn
node CreateNode(NhanVien value) {
	node temp; //Khai báo 1 node
	//temp = (node)malloc(sizeof(struct LinkedList));//Cấp phát vùng nhớ dùng malloc
	temp = new LinkedList;
	temp->next = NULL; //cho next trỏ tới NULL
	temp->data = value; //gán giá trị cho node
	return temp;//trả về node mới đã có giá trị
}
node AddHead(node head, NhanVien value) {
	node temp = CreateNode(value);//khởi tạo node temp với data = value
	if (head == NULL) {
		head = temp; //nếu liked list đang trống thì node temp là head
	}
	else {
		temp->next = head; //trỏ next của temp = head hiện tại
		head = temp; //đổi head hiện tại = temp (vì temp bây h là head mới)
	}
	return head;
}
node AddTail(node head, NhanVien value) {
	node temp, p; //khai báo 2 node tạm
	temp = CreateNode(value);//gọi hàm createnode để khởi tạo node temp có next trỏ tới NULL và data là value
	if (head == NULL) {
		head = temp;
	}
	else {
		p = head;//khởi tạo p trỏ tới head
		while (p->next != NULL) {
			p = p->next;//duyệt đến cuối.node cuối là node có next = null
		}
		p->next = temp;//gán next của node cuối = temp,khi đó temp sẽ là node cuối(temp.next=NULL)
	}
	return head;
}
node AddAt(node head, NhanVien value, int position) {
	if (position == 0 || head == NULL) {
		head = AddHead(head, value);//nếu vị trí chèn = 0, => thêm vào đầu
	}
	else {
		//bắt đầu tìm vị trí cần chèn. dùng k để đếm vị trí
		int k = 1;
		node p = head;
		while (p->next != NULL && k != position) {
			p = p->next;
			++k;
		}
		if (k != position) {
			//nếu duyệt hết danh sách mà vẫn chưa đến vị trí cần chèn, mặc định chèn cuối
			//nếu k muốn chèn, thông báo vị trí không hợp lệ
			head = AddTail(head, value);
			//cout<<"Vi tri chen vuot qua vi tri cuoi cung"<<endl;
		}
		else {
			node temp = CreateNode(value);
			temp->next = p->next;
			p->next = temp;
		}
	}
	return head;
}
node DelHead(node head) {
	if (head == NULL) {
		cout << "Danh sach rong!!!";
	}
	else
	{
		head = head->next;
	}
	return head;
}
node DelTail(node head) {
	node p = head;
	while (p->next->next != NULL) {
		p = p->next;
	}
	p->next = p->next->next;//cho next = NULL
	//hoặc p->next  = NULL
	return head;
}
node DelAt(node head, int position) {
	if (position == 0 || head == NULL) {
		head = DelHead(head); //nếu vị trí chèn = 0,Xoá đầu
	}
	else {
		//tìm vị trí chèn. dùng k để đếm vị trí
		int k = 1;
		node p = head;
		while (p->next->next != NULL && k != position)
		{
			p = p->next;
			++k;
		}
		if (k != position) {
			//nếu duyệt hết danh sách mà không tìm được vị trí cần xoá, mặc định xoá cuối
			//nếu k muốn xoá,thông báo vị trí xoá k hợp lệ
			head = DelTail(head);
			//cout << "Vi tri xoa vuot qua vi tri cuoi"<<endl;
		}
		else {
			p->next = p->next->next;
		}
	}
	return head;
}
NhanVien Get(node head, int index) {
	int k = 0;
	node p = head;
	while (p != NULL && k != index) {
		p = p->next;
		++k;
	}
	return p->data;
}
int Search(node head, NhanVien value) {
	int pos = 0;
	for (node p = head; p != NULL; p = p->next)
	{
		if (p->data == value)
		{
			return pos;
		}
		++pos;
	}
	return -1;
}
int Search(node head, NhanVien value, float hsl) {
	int pos = 0;
	for (node p = head; p != NULL; p = p->next)
	{
		if (p->data == value && p->data.getHeSoLuong() == hsl)
		{
			return pos;
		}
		++pos;
	}
	return -1;
}
int Search(node head, string value) {
	int pos = 0;
	for (node p = head; p != NULL; p = p->next)
	{
		if (p->data.getHoTen() == value)
		{
			return pos;
		}
		else if (p->data.getChucVu() == value)
		{
			return pos;
		}
		else if (p->data.getNgaySinh() == value)
		{
			return pos;
		}
		++pos;
	}
	return -1;
}
node DelByVal(node head, NhanVien value) {
	int pos = Search(head, value);
	while (pos != -1) {
		DelAt(head, pos);
		pos = Search(head, value);
	}
	return head;
}
bool FindSubString(const string str1, const string str2) {
	int i = 0, save, temp, size1;
	string s1 = toLower(str1);
	string s2 = toLower(str2);
	int size2 = str2.length();
	while (s1[i] != '\0') {//LẬP CHUỖI DÀI
		if (s1[i] == s2[0]) {//KT PHẦN TỬ 1 CỦA CHUỖI 2 CÓ BẰNG PHẦN TỬ thứ i CỦA CHUỖI 1
			int j = 1;
			save = i;
			temp = i;//LƯU VỊ TRÍ KHI I = PHẦN TỬ 1 CỦA CHUỖI 2
			size1 = 1;//LƯU LẠI KÍCH THƯỚC CỦA CHUỖI 1(PHẦN TRÙNG VỚI CHUỖI 2)
			while ((s2[j] != '\0' || s1[save + 1] != '\0') && s1[save + 1] == s2[j]) {
				j++;
				save++;
				size1++;
			}
			if (s2[j] == '\0' && size2 == size1)
				return true;
			else {
				i = temp;
				i++;
			}
		}
		else i++;
	}
	return false;
}
node DelByString(node head, string subString) {
	for (node p = head; p != NULL; p = p->next)
	{
		if (FindSubString(p->data.getHoTen(), subString))
		{
			int pos = Search(head, p->data);
			head = DelAt(head, pos);
		}
		else if (FindSubString(p->data.getChucVu(), subString))
		{
			int pos = Search(head, p->data);
			head = DelAt(head, pos);
		}
		else if (FindSubString(p->data.getNgaySinh(), subString))
		{
			int pos = Search(head, p->data);
			head = DelAt(head, pos);
		}
		else if (p->data.getHeSoLuong() == StringToFloat(subString)
			//&&
			//FindSubString(FloatToString(p->data.getHeSoLuong()),subString)
			)
		{
			/*cout << StringToFloat(subString) << endl;
			cout << p->data.getHeSoLuong() << endl;*/
			int pos = Search(head, p->data, StringToFloat(subString));
			head = DelAt(head, pos);
		}
	}
	return head;
}
int SearchByString(node head, node p, string subString) {
	if (FindSubString(p->data.getHoTen(), subString))
	{
		int pos = Search(head, p->data);
		return pos;
	}
	else if (FindSubString(p->data.getChucVu(), subString))
	{
		int pos = Search(head, p->data);
		return pos;
	}
	else if (FindSubString(p->data.getNgaySinh(), subString))
	{
		int pos = Search(head, p->data);
		return pos;
	}
	else if (p->data.getHeSoLuong() == StringToFloat(subString)
		//&&
		//FindSubString(FloatToString(p->data.getHeSoLuong()),subString)
		)
	{
		/*cout << StringToFloat(subString) << endl;
		cout << p->data.getHeSoLuong() << endl;*/
		int pos = Search(head, p->data, StringToFloat(subString));
		return pos;
	}
	return -1;
}
void DisplaySBS(node head, string sub) {
	int flag = 0;
	cout << setWidth('<>', 100) << endl;
	for (node p = head; p != NULL; p = p->next)
	{
		int i = SearchByString(head, p, sub);
		if (i != -1) {
			flag++;
			NhanVien value = Get(head, i);
			cout << setWidth('-', 100)<<endl;
			cout << "STT: " << i + 1 << endl;
			cout << "Ho ten : " << value.getHoTen() << endl;
			cout << "Chuc vu : " << value.getChucVu() << endl;
			cout << "Ngay sinh : " << value.getNgaySinh() << endl;
			cout << "He so luong : " << fixed << setprecision(3) << value.getHeSoLuong() << endl;
			//value.hienThi();
			//cout << "====================" << endl;
		}
	}
	if (flag == 0) {
		cout << "====================" << endl;
		cout << "KHONG TIM THAY" << endl;
		cout << "====================" << endl;
	}
	cout << setWidth('*', 100) << endl;
}
void Traverser(node head) {
	cout << endl;
	int i = 0;
	cout << setWidth('=', 100) << endl;
	cout << setWidth("STT", 10) << "|";
	cout << setWidth("Ho va ten", 25) << "|";
	cout << setWidth("Chuc vu", 25) << "|";
	cout << setWidth("Ngay thang nam sinh", 25) << "|";
	cout << "He so luong" << endl;
	for (node p = head; p != NULL; p = p->next)
	{
		cout << setWidth(IntToString(i + 1), 10) << "|";
		cout << setWidth(p->data.getHoTen(), 25) << "|";
		cout << setWidth(p->data.getChucVu(), 25) << "|";
		cout << setWidth(p->data.getNgaySinh(), 25) << "|";
		cout << fixed << setprecision(3) << p->data.getHeSoLuong() << endl;
		++i;
	}
	cout << endl;
}
node InitHead() {
	node head;
	head = NULL;
	return head;
}
int Length(node head) {
	int len = 0;
	for (node p = head; p != NULL; p = p->next)
	{
		++len;
	}
	return len;
}
node Input(NhanVien value) {
	node head = InitHead();
	/*int n;
	NhanVien value;*/
	//do {
	//	/*cout << "Nhập số nhân viên: ";
	//	cin >> n;*/
	//	
	//} while (n <= 0);
	//for (int i = 0; i < n; i++)
	//{
	//	/*cout << "Nhap gia tri can them: ";
	//	cin >> value;*/
	//	head = AddTail(head, value);
	//}
	head = AddTail(head, value);
	return head;
}
char* ToCharArray(string line, char a[]) {
	string tempLine = line;
	for (int i = 0; i < tempLine.size(); i++)
	{
		a[i] = tempLine[i];
	}
	return a;
}
int CountTotal(fstream &file, string dir) {
	file.open(dir);
	int count = 0;
	string line = "";
	getline(file, line);
	while (getline(file, line)) {
		count++;
	}
	file.close();
	return count;
}
node InputList(fstream &file, string name, node head) {
	file.open(name);
	string line;
	getline(file, line);
	while (getline(file, line)) {
		string* ptr = new string[4];
		ptr = Split(line, ';');
		string hoten = *(ptr);
		string chucvu = *(ptr + 1);
		string ngaysinh = outputBOD(*(ptr + 2));
		float hsl = (float)StringToFloat(*(ptr + 3));
		NhanVien* nhanvien = new NhanVien(hoten, chucvu, ngaysinh, hsl);
		head = AddTail(head, *nhanvien);
	}
	file.close();
	return head;
}
node OutPutList(node head, string name) {
	fstream _file;
	_file.open(name, ios::out);
	_file << setWidth("STT", 10)
		<< setWidth("Ho va ten", 25)
		<< setWidth("Chuc vu", 25)
		<< setWidth("Ngay thang nam sinh", 25)
		<< setWidth("He so luong", 25)
		<< "\n";
	int i = 1;
	for (node p = head; p != NULL; p = p->next)
	{
		float num = p->data.getHeSoLuong();
		_file << setWidth(IntToString(i), 10)
			<< setWidth(p->data.getHoTen(), 25)
			<< setWidth(p->data.getChucVu(), 25)
			<< setWidth(p->data.getNgaySinh(), 25)
			<< fixed << setprecision(2)
			<< num
			<< "\n";
		i++;
	}
	_file.close();
	cin.get();
	cout << "Xuat file thanh cong!!!";
	return head;
}
bool compareBD(const string d1, const string d2) {
	string* str1 = Split(d1, '/');
	string* str2 = Split(d2, '/');

	int ngay1 = StringToInt(*str1);
	int ngay2 = StringToInt(*str2);
	int thang1 = StringToInt(*(str1 + 1));
	int thang2 = StringToInt(*(str2 + 1));
	int nam1 = StringToInt(*(str1 + 2));
	int nam2 = StringToInt(*(str2 + 2));
	if (nam1 < nam2) {
		return true;
	}
	if (nam1 == nam2 && thang1 < thang2) {
		return true;
	}
	if (nam1 == nam2 && thang1 == thang2 && ngay1 < ngay2) {
		return true;
	}
	return false;
}
bool compareHSL(float d1, float d2) {
	if (d1 <= d2) {
		return true;
	}
	else return false;
}
int ranking(const string str) {
	string temp = toLower(str);

	string ct = "chu tich";
	string pct = "pho chu tich";
	string gd = "giam doc";
	string pgd = "pho giam doc";
	string tk = "thu ky";
	string ql = "quan ly";
	string tp = "truong phong";
	string pp = "pho phong";
	string nv = "nhan vien";
	string trainee = "thuc tap sinh";
	int x = 0;

	if (Equal(temp, ct))  x = 10;
	else if (Equal(temp, pct))  x = 9.5;
	else if (Equal(temp, gd))  x = 9;
	else if (Equal(temp, pgd))  x = 8.5;
	else if (Equal(temp, tk))  x = 8;
	else if (Equal(temp, ql))  x = 7.5;
	else if (Equal(temp, tp))  x = 7;
	else if (Equal(temp, pp))  x = 6.5;
	else if (Equal(temp, nv))  x = 5;
	else if (Equal(temp, trainee))  x = 4;
	return x;
}
bool compareCV(const string d1, const string d2) {
	int x = ranking(d1);
	int y = ranking(d2);
	if (x <= y)return true;
	else return false;
}
bool compareName(string d1, string d2) {
	string s1 = toUpper(d1);
	string s2 = toUpper(d2);
	string* str1 = Split(s1, ' ');
	string* str2 = Split(s2, ' ');
	int p1 = 0;
	int p2 = 0;
	while (*(str1 + p1) != "\0") {
		++p1;
	}
	while (*(str2 + p2) != "\0")
	{
		++p2;
	}
	//for (int i = 0; i < (*(str1 + p1 - 1)).length(); i++)
	//{
	//	for (int j = 0; i < (*(str2 + p2 - 1)).length(); i++)
	//	{
	//		if ((*(str1 + p1 - 1))[i] <= (*(str2 + p2 - 1))[j]) {
	//			/*	cout << *(str1 + p1 - 1) << endl;
	//				cout << *(str2 + p2 - 1) << endl;*/
	//			return true;
	//		}
	//		else return false;
	//	}
	//}
	int i = 0;
	int j = 0;
	while ((*(str1 + p1 - 1))[i] != '\0' && (*(str2 + p2 - 1))[j] != '\0')
	{
		if ((*(str1 + p1 - 1))[i] == (*(str2 + p2 - 1))[j]) { i++;j++; }
		else if ((*(str1 + p1 - 1))[i] > (*(str2 + p2 - 1))[j]) return false;
		else if ((*(str1 + p1 - 1))[i] < (*(str2 + p2 - 1))[j]) return true;
	}
	return false;
	/*return false;*/
}
node SortByBD_SelectionSort(node head, const int i) {// Chỉ sort danh sách không có trùng dữ liệu
	for (node p = head; p->next != NULL; p = p->next)
	{
		node temp = CreateNode(p->data);
		for (node q = p->next; q != NULL; q = q->next)
		{
			bool sortDesc = compareBD(temp->data.getNgaySinh(), q->data.getNgaySinh());
			if (i == 0) { //Giảm dần
				if (sortDesc) {
					int posP = Search(head, temp->data);
					int posQ = Search(head, q->data);
					head = DelAt(head, posP);//Xoá P
					head = AddAt(head, q->data, posP);//Thêm Q
					head = DelAt(head, posQ); //Xoá Q
					head = AddAt(head, temp->data, posQ);//Thêm P
					//Traverser(head);
				}
			}
			else {
				if (!sortDesc) {
					int posP = Search(head, temp->data);
					int posQ = Search(head, q->data);
					head = DelAt(head, posP);//Xoá P
					head = AddAt(head, q->data, posP);//Thêm Q
					head = DelAt(head, posQ); //Xoá Q
					head = AddAt(head, temp->data, posQ);//Thêm P
				}
			}
		}
	}
	return head;
}
node SortedMerge(node a, node b, int thutu, int type) {
	node result = NULL;

	//Base case
	if (a == NULL)
		return b;
	else if (b == NULL)
		return a;
	//chọn a hoặc b, và đệ qui
	if (type == 0) { //TÊN
		if (thutu == 1) {
			if (compareName(a->data.getHoTen(), b->data.getHoTen())) {
				result = a;
				result->next = SortedMerge(a->next, b, thutu, type);
			}
			else {
				result = b;
				result->next = SortedMerge(a, b->next, thutu, type);
			}
		}
		else {
			if (!compareName(a->data.getHoTen(), b->data.getHoTen())) {
				result = a;
				result->next = SortedMerge(a->next, b, thutu, type);
			}
			else {
				result = b;
				result->next = SortedMerge(a, b->next, thutu, type);
			}
		}
	}
	if (type == 1) { //CHỨC VỤ
		if (thutu == 1) {
			if (compareCV(a->data.getChucVu(), b->data.getChucVu())) {
				result = a;
				result->next = SortedMerge(a->next, b, thutu, type);
			}
			else {
				result = b;
				result->next = SortedMerge(a, b->next, thutu, type);
			}
		}
		else {
			if (!compareCV(a->data.getChucVu(), b->data.getChucVu())) {
				result = a;
				result->next = SortedMerge(a->next, b, thutu, type);
			}
			else {
				result = b;
				result->next = SortedMerge(a, b->next, thutu, type);
			}
		}
	}
	if (type == 2) { //NGÀY SINH
		if (thutu == 1) {
			if (compareBD(a->data.getNgaySinh(), b->data.getNgaySinh())) {
				result = a;
				result->next = SortedMerge(a->next, b, thutu, type);
			}
			else {
				result = b;
				result->next = SortedMerge(a, b->next, thutu, type);
			}
		}
		else {
			if (!compareBD(a->data.getNgaySinh(), b->data.getNgaySinh())) {
				result = a;
				result->next = SortedMerge(a->next, b, thutu, type);
			}
			else {
				result = b;
				result->next = SortedMerge(a, b->next, thutu, type);
			}
		}

	}
	if (type == 3) { //HỆ SỐ LƯƠNG
		if (thutu == 1) {
			if (compareHSL(a->data.getHeSoLuong(), b->data.getHeSoLuong())) {
				result = a;
				result->next = SortedMerge(a->next, b, thutu, type);
			}
			else {
				result = b;
				result->next = SortedMerge(a, b->next, thutu, type);
			}
		}
		else {
			if (!compareHSL(a->data.getHeSoLuong(), b->data.getHeSoLuong())) {
				result = a;
				result->next = SortedMerge(a->next, b, thutu, type);
			}
			else {
				result = b;
				result->next = SortedMerge(a, b->next, thutu, type);
			}
		}
		return result;
	}


	return result;
}
int checkType(string line) {
	if (Equal(toLower(line), "ho va ten")
		|| Equal(toLower(line), "ten")
		|| Equal(toLower(line), "hovaten")
		|| Equal(toLower(line), "hoten")) {
		return 0;
	}
	if (Equal(toLower(line), "chuc vu")
		|| Equal(toLower(line), "chucvu")) {
		return 1;
	}
	if ((Equal(toLower(line), "ngay thang nam sinh"))
		|| (Equal(toLower(line), "ngay thang nam"))
		|| (Equal(toLower(line), "ngay thang"))
		|| (Equal(toLower(line), "nam sinh"))
		|| (Equal(toLower(line), "ngay sinh"))
		|| (Equal(toLower(line), "ngaysinh"))
		|| (Equal(toLower(line), "namsinh"))
		|| (Equal(toLower(line), "ngaythangnamsinh"))
		|| (Equal(toLower(line), "ngaythang")))
	{
		return 2;
	}
	if (Equal(toLower(line), "luong") || Equal(toLower(line), "he so luong")
		|| (Equal(toLower(line), "hesoluong"))) {
		return 3;
	}
	return -1;
}
void FrontBackSplit(node source, node* frontRef, node* backRef) {
	node fast;
	node slow;
	slow = source;
	fast = source->next;
	//di chuyển fast 2 node,di chuyển slow 1 node
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	//'slow' is before the midpoint in the list, so split it in two at that point
	//slow nằm ở phía trước điểm giữa của danh sách, nên chia danh sách làm 2 ở điểm đó
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}
void MergeSort(node* headRef, int thutu, int type) {
	node head = *headRef;
	node a;
	node b;

	//Length = 0 hoặc 1
	if ((head == NULL) || (head->next == NULL)) {
		return;
	}
	//Split head into 'a' and 'b' sublist
	FrontBackSplit(head, &a, &b);
	/* Recursively sort the sublists */
	MergeSort(&a, thutu, type);
	MergeSort(&b, thutu, type);
	//answer=merge the two sorted list together
	*headRef = SortedMerge(a, b, thutu, type);
}
void SortAll(node* headRef) {
	node head = *headRef;
	int order;
	string input;
	//fflush(stdin);
	cin.ignore();
	cout << setWidth('*', 100) << endl;
	cout << "TIEU CHI SAP XEP: " << endl;
	getline(cin, input);
	int type = checkType(input);
	cout << type;
	if (type == -1) {
		cout << "LOI CU PHAP!!!";
		return;
	}
	cout << "THU TU SAP XEP: " << endl;
	cout << "1.Thap->Cao \n";
	cout << "2.Cao->Thap \n";
	cin >> order;

	if (order == 1) {
		MergeSort(headRef, 1, type);
		/*	cout << setWidth('*', 100) << endl;
			Traverser(head);
			cout << setWidth('*', 100) << endl;*/
	}
	else
	{
		MergeSort(headRef, 2, type);
		/*	cout << setWidth('*', 100) << endl;
			Traverser(head);
			cout << setWidth('*', 100) << endl;*/
	}
	//cout << setWidth('*', 100) << endl;
	//Traverser(head);
	//cout << setWidth('*', 100) << endl;
}
node AddEmp(node head) {
	cin.ignore();
	string ht;
	string cv;
	string ns;
	float hsl;
	int pos;
	cout << setWidth('#', 100) << endl;
	cout << "HO VA TEN: \n";
	getline(cin, ht);
	cout << "CHUC VU: \n";
	getline(cin, cv);
	cout << "NGAY THANG NAM SINH: \n";
	getline(cin, ns);
	cout << "HE SO LUONG: \n";
	cin >> hsl;
	cout << "VI TRI CAN CHEN: \n";
	cin >> pos;
	cout << setWidth('#', 100) << endl;
	NhanVien nv = NhanVien(ht, cv, ns, hsl);
	head = AddAt(head, nv, pos - 1);
	return head;
}
node DelAll(node head) {
	cin.ignore();
	string s;
	cout << setWidth('#', 100) << endl;
	cout << "NHAP CHUOI CAN XOA: \n";
	getline(cin, s);
	cout << setWidth('#', 100) << endl;
	head = DelByString(head, s);
	return head;
}
void Display(node head) {
	cin.ignore();
	string s;
	cout << setWidth('#', 100) << endl;
	cout << "NHAP CHUOI TIM KIEM: \n";
	getline(cin, s);
	cout << setWidth('#', 100) << endl;
	DisplaySBS(head, s);
}
int main()
{
	fstream file;
	string line;
	cout << setWidth('*', 100) << endl;
	cout << "NHAP DANH SACH NHAN VIEN: ";
	cin >> line;
	int n = CountTotal(file, line);
	cout << "TONG SO NHAN VIEN: " << n << endl;
	cout << setWidth('*', 100) << endl;
	node head = InitHead();
	head = InputList(file, line, head);
	Traverser(head);
	cout << setWidth('*', 100) << endl;
	int chon = -1;

	while (chon != 0) {
		//system("cls");
		cout << setWidth('*', 100) << endl;

		cout << "1.SAP XEP NHAN VIEN THEO TIEU CHI,THU TU" << endl;

		cout << "2.THEM NHAN VIEN THEO VI TRI" << endl;

		cout << "3.XOA NHAN VIEN THEO TU KHOA" << endl;

		cout << "4.TIM NHAN VIEN THEO TU KHOA" << endl;

		cout << "5.XUAT DANH SACH" << endl;

		cout << "0.THOAT" << endl;

		cout << setWidth('*', 100) << endl;

		cin >> chon;


		if (chon == 1) {
			SortAll(&head);
			cout << setWidth('*', 100) << endl;
			Traverser(head);
			cout << setWidth('*', 100) << endl;
		}

		if (chon == 2) {
			head = AddEmp(head);
			cout << setWidth('*', 100) << endl;
			Traverser(head);
			cout << setWidth('*', 100) << endl;
		}
		if (chon == 3) {
			head = DelAll(head);
			cout << setWidth('*', 100) << endl;
			Traverser(head);
			cout << setWidth('*', 100) << endl;
		}
		if (chon == 4) {
			Display(head);
		}
		if (chon == 5) {
			cin.ignore();
			string dir;
			cout << setWidth('!~!', 100) << endl;
			cout << "NHAP DIA CHI: ";
			getline(cin, dir);
			OutPutList(head,dir);
			cout << setWidth('!~!', 100) << endl;
		}
	}




	//file.open("Text.txt");
	////Bỏ dòng đầu tiên
	//getline(file, line);
	/*NhanVien nv=NhanVien("Nguyễn Văn A", "Tổng giám đốc", "11/11/1970", 2.5);
	cout << nv.getHoTen() << endl;
	cout << nv.getChucVu() << endl;
	cout << nv.getNgaySinh() << endl;
	cout << nv.getHeSoLuong() << endl;

	NhanVien a[100] = { nv };*/
	/*NhanVien* nv = new NhanVien[100];
	int pos = 0;*/

	//node head = InitHead();
	//head = InputList(file, "Text.txt", head);
	////while (getline(file, line)) {
	////	string* ptr = new string[4];
	////	ptr = Split(line, ';');
	////	string hoten = *(ptr);
	////	string chucvu = *(ptr + 1);
	////	string ngaysinh = *(ptr + 2);
	////	float hsl = StringToFloat(*(ptr + 3));
	////	NhanVien* nhanvien = new NhanVien(hoten, chucvu, ngaysinh, hsl);
	////	head = AddTail(head, *nhanvien);
	////	/*	nv[pos] = *nhanvien;
	////		pos++;*/
	////}
	///*for (int i = 0; i < sizeof(nv); i++)
	//{
	//	nv[i].hienThi();
	//	cout << endl;
	//}
	//nv[2].hienThi();*/
	//Traverser(head);
	///*NhanVien nv = NhanVien("Nguyen Thi C", "Truong phong", "10/01/1970", 3.0);
	//int pos = Search(head, nv);
	//if (pos == -1) {
	//	cout << "Khong co nhan vien nay" << endl;
	//}
	//else cout << Get(head, pos).getHoTen();
	//DelByVal(head, nv);
	//Traverser(head);*/
	///*file.close();*/
	////head = SortByBD_SelectionSort(head, 0);//0-giảm dần|| 1=tăng dần
	//MergeSort(&head, 0, 1);
	//Traverser(head);
	//NhanVien nv = NhanVien("Dich Le Nhiet Ba", "Pho chu tich", "03/06/1992", 2.5);
	////head= AddHead(head, nv);
	////head = AddTail(head, nv);
	//head = AddAt(head, nv, 10);
	//Traverser(head);
	//head = DelByString(head, "3.0");
	//Traverser(head);
	//DisplaySBS(head, "1.0");
	//OutPutList(head, "C:\\Users\\Duy\\Desktop\\output.txt");

	///*cout << StringToFloat("2.7") << endl;
	//cout << FloatToString(2.7) << endl;*/
	std::system("pause");
	return 0;
}