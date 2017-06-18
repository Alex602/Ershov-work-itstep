#include"phone_book.h"
#include"Record.h"
#include"command_lib.h"
#include<iostream>
#include<string>
#include<iomanip>
using std::string;
using std::ostream;
using std::istream;
using std::endl;
using std::cin;
using std::cout;
using std::setw;

void main() {
	phone_book *a=new phone_book[3];
	for (size_t i = 0; i < 3; i++) {
		cin >> a[i];
	}
	for (size_t i = 0; i < 3; i++) {
		cout << a[i];
	}
	FILE*u=nullptr;
	
//	
	phone_book f;
	//cin >> f;
	
	//f.write_phone_book(u);
	f.read_phone_book(u);
	f.sort(f);
	cout << f;
//	cout << a[2][1].get_name();
	system("pause");
	//p.set_date_of_birth(ch3);
}