#include"Contact.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

Contact::Contact()
{
	fullName = nullptr;

}

Contact::Contact(const char* name, const string& home,
	const string& work, const string& mobile,
	const string& info) :
	homePhone(home), workPhone(work), mobilePhone(mobile), info(info)

{
	fullName = new char[strlen(name) + 1];
	strcpy_s(fullName, strlen(name) + 1, name);
}

Contact::Contact(const Contact& other)
{
	fullName = new char[strlen(other.fullName) + 1];
	strcpy_s(fullName, strlen(other.fullName) + 1, other.fullName);

	homePhone = other.homePhone;
	workPhone = other.workPhone;
	mobilePhone = other.mobilePhone;
	info = other.info;
}

Contact& Contact::operator=(const Contact& other)
{
	if (this != &other)
	{
		delete[] fullName;

		fullName = new char[strlen(other.fullName) = +1];
		strcpy_s(fullName, strlen(other.fullName) + 1, other.fullName);

		homePhone = other.homePhone;
		workPhone = other.workPhone;
		mobilePhone = other.mobilePhone;
		info = other.info;
	}
	return *this;
}

Contact::~Contact()
{
	delete[] fullName;
}

void Contact::Print() const
{
	cout << "ФІО:" << fullName << endl;
	cout << "Домашній:" << homePhone << endl;
	cout << "Робочий:" << workPhone << endl;
	cout << "Мобільний:" << mobilePhone << endl;
	cout << "Інфо:" << info << endl;
	cout << "----------------------------" << endl;
}

void Contact::SaveToFile(ofstream& out) const
{
	out << fullName << endl
		<< homePhone << endl
		<< workPhone << endl
		<< mobilePhone << endl
		<< info << endl;

}

void Contact::LoadFromFile(ifstream& in)
{
	string temp;

	getline(in, temp);
	fullName = new char[temp.size() + 1];
	strcpy_s(fullName, temp.size() + 1, temp.c_str());

	getline(in, homePhone);
	getline(in, workPhone);
	getline(in, mobilePhone);
	getline(in, info);

}