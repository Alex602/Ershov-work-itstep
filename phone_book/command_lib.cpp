#include"phone_book.h"
#include"Record.h"
#include"command_lib.h"
#define CIN_FLUSH if (std::cin.peek()) std::cin.ignore()
/*istream& operator >> (istream& is, Record &p) {
	string name, surname, patronymic, date_of_birth, phone;
	if (p.get_name())return is;
	else {
		is >> name;
		char* ch = new char[name.length() + 1];
		strcpy_s(ch, name.length() + 1, name.c_str());
		p.set_name(ch);
		delete[]ch;
	}

	if (p.get_surname())return is;
	else {
		is >> surname;
		char* ch1 = new char[surname.length() + 1];
		strcpy_s(ch1, surname.length() + 1, surname.c_str());
		p.set_surname(ch1);
		delete[]ch1;
	}

	if (p.get_patronymic())return is;
	else {
		is >> patronymic;
		char* ch2 = new char[patronymic.length() + 1];
		strcpy_s(ch2, patronymic.length() + 1, patronymic.c_str());
		p.set_patronymic(ch2);
		delete[]ch2;
	}

	if (p.get_date_of_birth())return is;
	else {
		is >> date_of_birth;
		char* ch3 = new char[date_of_birth.length() + 1];
		strcpy_s(ch3, date_of_birth.length() + 1, date_of_birth.c_str());
		p.set_date_of_birth(ch3);
		delete[]ch3;
	}

	if (p.get_telephone())return is;
	else {
		is >> phone;
		char* ch4 = new char[phone.length() + 1];
		strcpy_s(ch4, phone.length() + 1, phone.c_str());
		p.set_telephone(ch4);
		delete[]ch4;
	}
	return is;
}*/







istream& operator >> (istream& is, Record &p) {
	string name, surname, patronymic, date_of_birth, phone;
	if (p.get_name())return is;
	else {
		CIN_FLUSH;
		getline(is, name);
		char* ch = new char[name.length() + 1];
		strcpy_s(ch, name.length() + 1, name.c_str());
		p.set_name(ch);
		delete[]ch;
	}

	if (p.get_surname())return is;
	else {
		CIN_FLUSH;
		getline(is, surname);
		char* ch1 = new char[surname.length() + 1];
		strcpy_s(ch1, surname.length() + 1, surname.c_str());
		p.set_surname(ch1);
		delete[]ch1;
	}

	if (p.get_patronymic())return is;
	else {
		CIN_FLUSH;
		getline(is, patronymic);
		char* ch2 = new char[patronymic.length() + 1];
		strcpy_s(ch2, patronymic.length() + 1, patronymic.c_str());
		p.set_patronymic(ch2);
		delete[]ch2;
	}

	if (p.get_date_of_birth())return is;
	else {
		CIN_FLUSH;
		getline(is, date_of_birth);
		char* ch3 = new char[date_of_birth.length() + 1];
		strcpy_s(ch3, date_of_birth.length() + 1, date_of_birth.c_str());
		p.set_date_of_birth(ch3);
		delete[]ch3;
	}

	if (p.get_telephone())return is;
	else {
		CIN_FLUSH;
		getline(is, phone);
		char* ch4 = new char[phone.length() + 1];
		strcpy_s(ch4, phone.length() + 1, phone.c_str());
		p.set_telephone(ch4);
		delete[]ch4;
	}
	return is;
}










istream& operator >> (istream& is, phone_book &p) {
	cout << endl << "please, enter nomber record's: " << endl;
	int t;
	char in_p[11] = { 0 };
	char c1[10] = { 0 };
	is >> in_p;
	for (size_t q = 0; q < strlen(in_p); q++) {
		if ((int)in_p[q] > 47 && (int)in_p[q] < 58)
		{
			c1[q] = in_p[q];
		}
	}
	t = atoi(c1);
	if (t == 0) exit(1);
	for (size_t i = 0; i < t; i++) {
		Record p1;
		cin >> p1;
		p.addRecord(p1);
	}
	return is;
}

ostream& operator << (ostream& os, phone_book &p) {
	if (p.get_size()>0) {
		for (size_t i = 0; i < p.get_size(); i++) {
			os << endl << "name:" << p.get_spisok()[i].get_name() << endl;
			os << "surname:" << p.get_spisok()[i].get_surname() << endl;
			os << "patronymic:" << p.get_spisok()[i].get_patronymic() << endl;
			os << "date of birth:" << p.get_spisok()[i].get_date_of_birth() << endl;
			os << "telephone:" << p.get_spisok()[i].get_telephone() << endl;
		}
	}
	else {
		cout << endl << "can't display record;" << endl;
	}
	return os;
}

