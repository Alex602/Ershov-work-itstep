#pragma once
#include"phone_book.h"
#include"Record.h"
#include<iostream>
#include<string>
#include<iomanip>
istream& operator >> (istream& is, Record &p);
istream& operator >> (istream& is, phone_book &p);
ostream& operator << (ostream& os, phone_book &p);