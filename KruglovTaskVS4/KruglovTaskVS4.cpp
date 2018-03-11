/*Напишите программу – «телефонную книжку».
Записи(имя и телефон) должны хранится в каком - либо STL - контейнере(vector или list), причем крайне желательно, 
чтобы от типа контейнера не зависело ничего, кроме одной строки в программе – объявления этого контейнера(указание: используйте typedef).*/

#include "stdafx.h"
#include "PhoneBook.h"

using namespace std;

typedef vector<PhoneBook> PhoneBookDB;
PhoneBookDB db;
PhoneBookDB::iterator iter;

string Help()
{
	return	"help, 0 - show help.\n"
			"reset, 1 - retern to first recorn in phonebook.\n"
			"curr, 2 - show current record\n"
			"next, 3 - move to next record\n"
			"prev, 4 - move to previous record\n"
			"nextn, 5 - skip several records\n"
			"prevn, 6 - skip several records backwards\n"
			"before, 7 - insert a record before the current\n"
			"after, 8 - insert a record after the current\n"
			"back , 9 - insert a record at the end of the database\n"
			"change , 10 - change the current record\n";
}

template<class T> string ModifyRecord(T it)
{
	string name, phone;
	cout << "Enter name & phone number:";
	cin >> name >> phone;
	PhoneBook rec(name, phone);
	*it = rec;
	iter = db.begin();

	return "New val: " + rec.ToString();
}

string Reset()
{
	iter = db.begin();
	return iter->ToString();
}

string Curr()
{
	return iter->ToString();
}

string Next()
{
	if (++iter == db.end())
	{
		--iter;
		return "it was last record.\n";		
	}		
	else
		return iter->ToString();
}

string Prev()
{
	if (--iter == db.begin())
	{
		cout << "it is first record:\n";
		return iter->ToString();
		++iter;			
	}
	else
		return iter->ToString();
}

string NextN()
{
	int pos;
	cout << "\nEnter position:";
	cin >> pos;
	advance(iter, pos);
	return iter->ToString();
}

string PrevN()
{
	int pos;
	cout << "\nEnter position:";
	cin >> pos;
	advance(iter, -pos);
	return iter->ToString();
}

string ComandHandler(string cmd)
{
	try
	{
		if (cmd == "help" | cmd == "0")
			return Help();
		
		else if (cmd == "reset" || cmd == "1")
			return Reset();
		
		else if (cmd == "curr" || cmd == "2")
			return Curr();
		
		else if (cmd == "next" || cmd == "3") 
			return Next();
		
		else if (cmd == "prev" || cmd == "4") 
			return Prev();
		
		else if (cmd == "nextn" || cmd == "5") 
			return NextN();
		
		else if (cmd == "prevn" || cmd == "6") 
			return PrevN();
		
		else if (cmd == "before" || cmd == "7")
			return ModifyRecord(inserter(db, --iter));
		
		else if (cmd == "after" || cmd == "8") 
			return ModifyRecord(inserter(db, iter));
		
		else if (cmd == "back" || cmd == "9") 
			return ModifyRecord(back_inserter<PhoneBookDB>(db));
		
		else if (cmd == "change" || cmd == "10") 
			return ModifyRecord(iter);
		
		else 
			return "Invalid command! Type 'help' for a list of commands\n";
		
	}
	catch (...)
	{
		return "Past-end iterator dereferenced!\n";
	}
}

int main()
{
	string temp[2][4] = {	"qwe", "123",
							"asd", "456",
							"zxc", "789",
							"rty", "234"};

	//добавить заполнение массива

	cout << Help();
	iter = db.begin();

	transform(istream_iterator<string>(cin), istream_iterator<string>(),
		ostream_iterator<string>(cout), ComandHandler);

	_getch();
    return 0;
}

