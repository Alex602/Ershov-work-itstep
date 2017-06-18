#pragma once
#include"phone_book.h"
#include<iostream>
#include<iomanip>
#include<string>
using std::ostream;
using std::istream;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
class Record
{
private:
	char*name;
	char*surname;
	char*patronymic;
	char*date_of_birth;
	char*telephone;
public:
	Record();
	Record(const Record&a1);
	Record operator=(const Record&a1);
	bool operator==(const Record&a1);
	bool operator != ( Record&a1);
	void set_name(char*);
	void set_surname(char*);
	void set_patronymic(char*);
	void set_date_of_birth(char*);
	void set_telephone(char*);
	char*get_name()const;
	char*get_surname()const;
	char*get_patronymic()const;
	char*get_date_of_birth()const;
	char*get_telephone()const;
	~Record();
};
