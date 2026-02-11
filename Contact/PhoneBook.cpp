#include "PhoneBook.h"
#include <iostream>
#include <fstream>

using namespace std;

void PhoneBook::AddContact(const Contact& c)
{
	contacts.push_back(c);
}

voidPhoneBook::DeleteContact(const string& name)
{
	for (auto it = contacts.begin(); it != contacts.end(); ++it)
	{
		if (name == it->GetName())
		{
			contacts.erase(it);
			cout << "Абонента видалено.\n";
			return;
		}
	}
	cout << "Абонента не знайдено.\n";
}

void PhoneBook::FindContact(const string& name) const
{
	for (const auto& c : contacts)
	{
		if (name == c.GetName())
		{
			c.Print();
			return;
		}
	}
	cout << "Абонента не знайдено.\n";
}

void PhoneBook::ShowAll() const
{
	if (contacts.empty())
	{
		cout << "Телефонна книга порожня.\n";
		return;
	}

	for (const auto& c : contacts)
	{
		c.Print();
	}
}

void PhoneBook::Save(const string& filename) const
{
	ofstream out(filename);
	if (!out)
	{
		cout << "Не вдалося відкрити файл для запису.\n";
		return;
	}

	out << contacts.size() << endl;
	for (const auto& c : contacts)
	{
		c.SaveToFile(out);
	}
}

void PhoneBook::Load(const string& filename)
{
	ifstream in(filename);
	if (!in)
	{
		cout << "Не вдалося відкрити файл для читання.\n";
		return;
	}

	size_t count;
	in >> count;
	in.ignore();

	contacts.clear();
	for (size_t i = 0; i < count; i++)
	{
		Contact c;
		c.LoadFromFile(in);
		contacts.push_back(c);
	}
}