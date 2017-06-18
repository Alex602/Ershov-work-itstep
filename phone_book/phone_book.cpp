#pragma once
#include"phone_book.h"
#include"Record.h"
#include<windows.h>
phone_book::phone_book()
{
	spisok = nullptr;
	size = 0;
}

phone_book::phone_book(const phone_book & a1)
{
///	spisok = nullptr; size = 0;
	if (a1.spisok ) {
		size = a1.size;
		spisok=new Record[size];
		for (size_t j = 0; j < size; j++) {
			spisok[j] = a1.spisok[j];
		}
	}
	else {
		spisok=nullptr; size=0;
	}
}
	phone_book phone_book::operator=(const phone_book & a1)
	{
	///	spisok = nullptr; size = 0;
		if (a1.spisok) {
			if (spisok)delete[]spisok;
			size = a1.size;
			spisok=new Record[size];
			for (size_t j = 0; j < size; j++) {
				spisok[j] = a1.spisok[j];
			}	
		}else {spisok=nullptr; size=0;}
		return *this;
	}

void phone_book::addRecord( Record a)
{
		if (a.get_name() && a.get_surname() && a.get_date_of_birth()&&a.get_patronymic()&&
			a.get_telephone()) {
			if (spisok) {
				Record *buffer = new Record[size + 1];
				for (size_t y = 0; y < size; y++) {
					buffer[y] = spisok[y];
				}
				delete[]spisok;
				buffer[size] = a;
				spisok = buffer;
				size += 1;
			}
			else {
				size += 1;
				if (spisok)delete[]spisok;
				Record*i = new Record[1];
				i[0] = a;
				spisok = i;
			}
		}
		else return;
}

void phone_book::read_phone_book(FILE *f)
{
	fopen_s(&f, "phone_book.dat", "rb+");
	int size_time;
	fread_s(&size_time, sizeof(size_time), sizeof(size_time), 1, f);
	size = size_time;
	if (size > 0) {
		if (spisok)delete[]spisok;
		spisok = new Record[size];
		for (size_t i = 0; i < size; i++) {

			unsigned int sz = 0;
			fread_s(&sz, sizeof(sz), sizeof(sz), 1, f);
			char *buffer = new char[sz + 1];
			buffer[sz] = 0;
			fread_s(buffer, sz, sz, 1, f);
			spisok[i].set_name(buffer);
			delete[]buffer;

			unsigned int sz1 = 0;
			fread_s(&sz1, sizeof(sz1), sizeof(sz1), 1, f);
			char *buffer1 = new char[sz1 + 1];
			buffer1[sz1] = 0;
			fread_s(buffer1, sz1, sz1, 1, f);
			spisok[i].set_surname(buffer1);
			delete[]buffer1;

			unsigned int sz2 = 0;
			fread_s(&sz2, sizeof(sz2), sizeof(sz2), 1, f);
			char *buffer2 = new char[sz2 + 1];
			buffer2[sz2] = 0;
			fread_s(buffer2, sz2, sz2, 1, f);
			spisok[i].set_patronymic(buffer2);
			delete[]buffer2;

			unsigned int sz3 = 0;
			fread_s(&sz3, sizeof(sz3), sizeof(sz3), 1, f);
			char *buffer3 = new char[sz3 + 1];
			buffer3[sz3] = 0;
			fread_s(buffer3, sz3, sz3, 1, f);
			spisok[i].set_date_of_birth(buffer3);
			delete[]buffer3;

			unsigned int sz4 = 0;
			fread_s(&sz4, sizeof(sz4), sizeof(sz4), 1, f);
			char *buffer4 = new char[sz4 + 1];
			buffer4[sz4] = 0;
			fread_s(buffer4, sz4, sz4, 1, f);
			spisok[i].set_telephone(buffer4);
			delete[]buffer4;
		}
		fclose(f);
	}
	
		else return;
}

phone_book& phone_book::sort(phone_book & a1)
{
	if (a1.size <= 0) {	cout << endl << "Data error!" << endl;	Sleep(5000); exit(1); }
	else {
		for (int i = 0; i < a1.size-1; i++) {
			for (int z = a1.size-1; z > i; z--) {
			char*buff = new char[strlen(a1.spisok[z].get_name()) + strlen(a1.spisok[z].get_surname()) + strlen(a1.spisok[z].get_patronymic())+ 1];
			strcpy_s(buff, strlen(a1.spisok[z].get_name()) + strlen(a1.spisok[z].get_surname()) + strlen(a1.spisok[z].get_patronymic()) + 1, a1.spisok[z].get_name());
			strncpy_s(buff, strlen(a1.spisok[z].get_name()) + strlen(a1.spisok[z].get_surname()) + strlen(a1.spisok[z].get_patronymic()) + 1, a1.spisok[z].get_surname() ,strlen(a1.spisok[z].get_surname()) );
			strcat_s(buff, strlen(a1.spisok[z].get_name()) +strlen(a1.spisok[z].get_surname()) + strlen(a1.spisok[z].get_patronymic()) + 1, a1.spisok[z].get_patronymic());
			char*buff1 = new char[strlen(a1.spisok[z-1].get_name()) + strlen(a1.spisok[z-1].get_surname()) + strlen(a1.spisok[z-1].get_patronymic()) + 1];
			strcpy_s(buff1, strlen(a1.spisok[z-1].get_name()) + strlen(a1.spisok[z-1].get_surname()) + strlen(a1.spisok[z-1].get_patronymic()) + 1, a1.spisok[z-1].get_name());
			strncpy_s(buff1, strlen(a1.spisok[z - 1].get_surname()) + strlen(a1.spisok[z - 1].get_name()) + strlen(a1.spisok[z - 1].get_patronymic()) + 1, a1.spisok[z-1].get_surname(), strlen(a1.spisok[z-1].get_surname()));
			strcat_s(buff1, strlen(a1.spisok[z-1].get_surname())+ strlen(a1.spisok[z - 1].get_name()) + strlen(a1.spisok[z-1].get_patronymic()) + 1, a1.spisok[z-1].get_patronymic());
			if (strcmp(buff1, buff) > 0) {
				 Record buffer = a1.spisok[z];
				 a1.spisok[z] = a1.spisok[z - 1];
				 a1.spisok[z - 1] = buffer;
				}	
			delete[]buff; delete[]buff1;
			}
		}
	}
}

void phone_book::write_phone_book(FILE *f)
{
	if (size > 0 && spisok) {
		fopen_s(&f, "phone_book.dat", "wb+");
		int size_time = size;
		fwrite(&size_time, sizeof(size_time), 1, f);
		for (size_t i = 0; i < size; i++) {

			unsigned int sz = strlen(spisok[i].get_name());
			fwrite(&sz, sizeof(sz), 1, f);
			fwrite(spisok[i].get_name(), sz, 1, f);

			unsigned int sz1 = strlen(spisok[i].get_surname());
			fwrite(&sz1, sizeof(sz1), 1, f);
			fwrite(spisok[i].get_surname(), sz1, 1, f);

			unsigned int sz2 = strlen(spisok[i].get_patronymic());
			fwrite(&sz2, sizeof(sz2), 1, f);
			fwrite(spisok[i].get_patronymic(), sz2, 1, f);

			unsigned int sz3 = strlen(spisok[i].get_date_of_birth());
			fwrite(&sz3, sizeof(sz3), 1, f);
			fwrite(spisok[i].get_date_of_birth(), sz3, 1, f);

			unsigned int sz4 = strlen(spisok[i].get_telephone());
			fwrite(&sz4, sizeof(sz4), 1, f);
			fwrite(spisok[i].get_telephone(), sz4, 1, f);
		}
		fclose(f);
	}
	else {
		int zero = 0;
		fwrite(&zero, sizeof(zero), 1, f);
	}
}

void phone_book::delRecord()
{
		if (size == 0)return;
		if (size == 1) {
			delete[]spisok;
			spisok = nullptr;
			size = 0;
			return;
		}
		else {
			Record *buffer = new Record[size-1];
			for (size_t i = 0; i < size-1; i++) {
				buffer[i] = spisok[i];
			}
			delete[]spisok;
			spisok = new Record[size - 1];
			for (size_t j = 0; j < size-1; j++) {
				spisok[j] = buffer[j];
			}
			delete[]buffer;
			size -= 1;
		}
}

phone_book phone_book::operator+(phone_book& a1)
{
	phone_book r;
	if (spisok && a1.spisok){
	r.size=size+a1.size;
	r.spisok=new Record[size+a1.size];
	for (size_t i=0; i<size; i++){
			r.spisok[i]=spisok[i];	
		}
	for (size_t j=0; j<a1.size; j++){
			r.spisok[j+size]=a1.spisok[j];
		}
		return r;
	}
	else {
		if (a1.spisok) return a1;
		else {r.spisok=nullptr; 
				r.size=0;
				return r;}
	}
}

Record* phone_book::get_spisok() const
{
	return spisok;
}

int phone_book::get_size() const
{
	return size;
}

phone_book::~phone_book()
{
	delete[]spisok;
}

Record& phone_book::operator[](int index){

	if (index>=0 && index<size && size>0){
		return spisok[index];
	}
	else{
		if (index<0 &&size>0) return spisok[0];
		if (index>size && size>0) return spisok[size-1];
	}
}

bool phone_book::operator==(phone_book&a1){
	if (a1.size && a1.size==size){
		int ch=0;
		for (size_t i=0; i<size; i++){
			if (spisok[i]==a1.spisok[i]) ch++;
		}
		if (ch==size) return true;
		else return false;
	}
	else return false;
}
bool phone_book::operator!=(phone_book&a1){
	return  !(*this == a1);
}
