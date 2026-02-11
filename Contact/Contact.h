  #pragma once 
#include <string>
using namespace std;

class Contact
{
private:
	char* fullName;
	string homePhone;
	string workPhone;
	string mobilePhone;
	string info;

public:
	Contact();
	Contact(const char* name, const string& home, const string& work,
		const string& mobile, const string& info);

	Contact(const Contact& other);
	Contact& operator=(const Contact& other);

	~Contact();

	inline const char* GetName() const { return fullName; }
	void Print() const;

	void SaveToFile(ofstream& out) const;
	void LoadFromFile(ifstream& in);



};