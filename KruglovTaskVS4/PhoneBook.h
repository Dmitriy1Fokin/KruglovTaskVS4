#pragma once
#include "stdafx.h"

using namespace std;


class PhoneBook
{
private:
	string name, phoneNum;
public:
	PhoneBook();
	PhoneBook(const PhoneBook &record);
	PhoneBook(const string &nameOfRecord, const string &phonenum);
	~PhoneBook();

	PhoneBook& operator=(const PhoneBook &record);

	string getName();
	string getPhoneNum();
	void setName(const string &nameOfRecord);
	void setPhoneNum(const string &phonenum);
	string ToString();
};

