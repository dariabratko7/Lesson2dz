#pragma once
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


	// Конструктор перенесення (нове додала)
	String(String&& other) noexcept;

	// Оператор присвоєння перенесення(теж нове додала)

	String& operator=(String&& other) noexcept;

	~String();

	void input();
	void output() const;

	static int getObjectCount();


};