#pragma once
class MyString
{
private:
	int length;
	char* str;
public:
	static int createdObj;
	MyString();
	MyString(int length);
	MyString(const char* str);
	MyString(const MyString& b);
	~MyString();
	void init(const char* str);
	void print()const;
	void myStrCpy(const MyString& obj);// copying strings
	bool myStrStr(const char* str)const;// searching substring in a string
	int  myChr(char c)const; // searching symbol in a string(index of a found symbol, or -1)
	int myStrLen()const;// returning str length
	void set_length(int len);
	void allocate(int len);
	void deleteStr();
	char get_arr_index(int index)const;
	MyString myStrCat(MyString& b); // concatenation
	MyString myStrCat(const char* word);//concat const char
	MyString myStrCat(const char c);
	void myDelChr(char c); // delete any symbol
	int myStrCmp(MyString& b)const; // string compare 
	int get_length()const;
	MyString& operator--(); //delete last symbol in string
	MyString operator--(int); //postfix delete last symbol in string
	MyString& operator - (char c); // delete any symbol from string
	MyString& operator +=(MyString& b);//simplified concatenation
	MyString& operator +=(const char* word);//simplified concat const char
	MyString& operator -=(char c);
	bool operator > (MyString& b); //string compare(ascii)
	bool operator < (MyString& b);
	bool operator >= (MyString& b);
	bool operator <= (MyString& b);
	bool operator == (MyString& b);
	bool operator != (MyString& b);
	char& operator [](int index);
};