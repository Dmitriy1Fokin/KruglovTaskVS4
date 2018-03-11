#include "stdafx.h"
#include "PhoneBook.h"


PhoneBook::PhoneBook()
{
	name = "empty";
	phoneNum = "empty";
}

PhoneBook::PhoneBook(const PhoneBook &record)
{
	name = getName();
	phoneNum = getPhoneNum();
}

PhoneBook::PhoneBook(const string &nameOfRecord, const string &phonenum)
{
	name = nameOfRecord;
	phoneNum = phonenum;
}

PhoneBook::~PhoneBook()
{
}

PhoneBook &PhoneBook::operator=(const PhoneBook &record)
{
	this->setName(record.name);
	this->setPhoneNum(record.phoneNum);

	return *this;
}

string PhoneBook::getName()
{
	return name;
}

string PhoneBook::getPhoneNum()
{
	return phoneNum;
}

void PhoneBook::setName(const string &nameOfRecord)
{
	name = nameOfRecord;
}

void PhoneBook::setPhoneNum(const string &phonenum)
{
	phoneNum = phonenum;
}

string PhoneBook::ToString()
{
	return "Name: " + getName() + ". Phone number: " + getPhoneNum() + "\n";
}