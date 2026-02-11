#pragma once
#include<vector>
#include"Contact.h"

using namespace std;

class PhoneBook
{
private:
	vector<Contact> contacts;

public:
	void AddContact(const Contact& c);
	void DeleteContact(const string& name);
	void FindContact(const string& name) const;
	void ShowAll() const;

	void Save(const string& filename) const;
	void Load(const string& filetime);

};
