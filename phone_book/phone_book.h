#pragma once
#include"phone_book.h"
#include"Record.h"
using namespace std;
class Record;
class phone_book
{
	Record* spisok;
	int size;
public:
	phone_book();
	phone_book(const phone_book&a1); //+
	phone_book operator=(const phone_book&a1); //+
	phone_book operator+(phone_book& a1); //+
	/*friend istream& operator >> (istream& is, phone_book &p);
	friend ostream& operator << (ostream& os, phone_book&p);*/
	phone_book& sort(phone_book&a1);
	void write_phone_book(FILE*f);
	void delRecord(); //+
	void addRecord( Record a); //+
	void read_phone_book(FILE*f);
	Record& operator[](int); // +/-
///	Record& operator[](char*);
	bool operator==(phone_book&a1); //+
	bool operator != (phone_book&a1); //+
	Record* get_spisok() const; //+
	int get_size() const; //+
	~phone_book();
};
