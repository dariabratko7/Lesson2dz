#ifndef STRING_H
#define STRING_H

#include <iostream>

class String {
private:
	char* str;
	size_t length;
	size_t capacity;
	static int objectCount;

public:
	String();
	String(size_t size);
	String(const char* input);

	~String();

	void input();
	void output() const;

	static int getObjectCount();
};

#endif