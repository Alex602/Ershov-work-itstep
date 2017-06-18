#pragma once
#include"Record.h"
#include"phone_book.h"
Record::Record()
{
	name=nullptr;
	surname=nullptr;
	patronymic=nullptr;
	date_of_birth=nullptr;
	telephone=nullptr;
}

Record::Record(const Record & a1)
{
	name = nullptr;
	if (a1.name && strlen(a1.name)) {
		name = new char[strlen(a1.name) + 1];
		strcpy_s(name, strlen(a1.name) + 1, a1.name);
	}
	surname = nullptr;
	if (a1.surname && strlen(a1.surname)) {
		surname = new char[strlen(a1.surname) + 1];
		strcpy_s(surname, strlen(a1.surname) + 1, a1.surname);
	}
	patronymic = nullptr;
	if (a1.patronymic && strlen(a1.patronymic)) {
		patronymic = new char[strlen(a1.patronymic) + 1];
		strcpy_s(patronymic, strlen(a1.patronymic) + 1, a1.patronymic);
	}
	date_of_birth = nullptr;
	if (a1.date_of_birth && strlen(a1.date_of_birth)) {
		date_of_birth = new char[strlen(a1.date_of_birth) + 1];
		strcpy_s(date_of_birth, strlen(a1.date_of_birth) + 1, a1.date_of_birth);
	}
	telephone = nullptr;
	if (a1.telephone && strlen(a1.telephone)) {
		telephone = new char[strlen(a1.telephone) + 1];
		strcpy_s(telephone, strlen(a1.telephone) + 1, a1.telephone);
	}
}

Record Record::operator=(const Record & a1)
{
	if (a1.name && strlen(a1.name)) {
		if (Record::name) delete[]Record::name;
		name = new char[strlen(a1.name) + 1];
		strcpy_s(name, strlen(a1.name) + 1, a1.name);
	}else name = nullptr;

	if (a1.surname && strlen(a1.surname)) {
		if (Record::surname) delete[]Record::surname;
		surname = new char[strlen(a1.surname) + 1];
		strcpy_s(surname, strlen(a1.surname) + 1, a1.surname);
	}else 	surname = nullptr;

	if (a1.patronymic && strlen(a1.patronymic)) {
		if (Record::patronymic) delete[]Record::patronymic;
		patronymic = new char[strlen(a1.patronymic) + 1];
		strcpy_s(patronymic, strlen(a1.patronymic) + 1, a1.patronymic);
	}else 	patronymic = nullptr;

	if (a1.date_of_birth && strlen(a1.date_of_birth)) {
		if (Record::date_of_birth) delete[]Record::date_of_birth;
		date_of_birth = new char[strlen(a1.date_of_birth) + 1];
		strcpy_s(date_of_birth, strlen(a1.date_of_birth) + 1, a1.date_of_birth);
	}else 	date_of_birth = nullptr;

	if (a1.telephone && strlen(a1.telephone)) {
		if (Record::telephone) delete[]Record::telephone;
		telephone = new char[strlen(a1.telephone) + 1];
		strcpy_s(telephone, strlen(a1.telephone) + 1, a1.telephone);
	}else 	telephone = nullptr;
	return *this;
}

bool Record::operator==(const Record & a1)
{
	if (a1.name && strcmp(a1.name, name) == 0 && a1.surname && strcmp(a1.surname, surname) == 0 && a1.patronymic && strcmp(a1.patronymic, patronymic) == 0 &&
		a1.date_of_birth && strcmp(a1.date_of_birth, date_of_birth) == 0 && a1.telephone && strcmp(a1.telephone, telephone) == 0) return true;
	else return false;
}

bool Record::operator!=( Record & a1)
{
	return!(*this == a1);
}

void Record::set_name(char *name)
{
	if (name && strlen(name)) {
		if(Record::name)delete[]Record::name;
		Record::name = new char[strlen(name) + 1];
		strcpy_s(Record::name, strlen(name)+1, name);
	}
	else return;
}

void Record::set_surname(char *surname)
{
	if (surname && strlen(surname)) {
		if (Record::surname)delete[]Record::surname;
		Record::surname = new char[strlen(surname) + 1];
		strcpy_s(Record::surname, strlen(surname)+1, surname);
	}
	else return;
}

void Record::set_patronymic(char *patronymic)
{
	if (patronymic && strlen(patronymic)) {
		if (Record::patronymic)delete[]Record::patronymic;
		Record::patronymic = new char[strlen(patronymic) + 1];
		strcpy_s(Record::patronymic, strlen(patronymic)+1, patronymic);
	}
	else return;
}

void Record::set_date_of_birth(char *date_of_birth)
{
	if (date_of_birth && strlen(date_of_birth)) {
		if (Record::date_of_birth)delete[]Record::date_of_birth;
		Record::date_of_birth = new char[strlen(date_of_birth) + 1];
		strcpy_s(Record::date_of_birth, strlen(date_of_birth)+1, date_of_birth);
	}
	else return;
}

void Record::set_telephone(char *telephone)
{
	if (telephone && strlen(telephone)) {
		if (Record::telephone)delete[]Record::telephone;
		Record::telephone = new char[strlen(telephone) + 1];
		strcpy_s(Record::telephone, strlen(telephone)+1, telephone);
	}
	else return;
}

char * Record::get_name()const
{
	return name;
}

char * Record::get_surname()const
{
	return surname;
}

char * Record::get_patronymic()const
{
	return patronymic;
}

char * Record::get_date_of_birth()const
{
	return date_of_birth;
}

char * Record::get_telephone()const
{
	return telephone;
}


Record::~Record()
{
	delete[]name;
	delete[]surname;
	delete[]patronymic;
	delete[]date_of_birth;
	delete[]telephone;
}