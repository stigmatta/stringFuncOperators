#include <iostream>
#include "MyString.h"
using namespace std;
int MyString::createdObj = 0;
MyString operator + (MyString& a, MyString& b) // string concatenation 
{
	MyString tmp = a.myStrCat(b);
	return tmp;
}
MyString operator++(MyString& a, int) // postfix str len +1
{
	MyString tmp(a.get_length());
	tmp.allocate(tmp.get_length());
	int i = 0;
	while (a[i] != '\0')
	{
		tmp[i] = a[i];
		i++;
	}
	tmp[i] = '\0';
	i = 0;
	a.set_length(a.get_length() + 1);
	a.deleteStr();
	a.allocate(a.get_length());
	while (tmp[i] != '\0')
	{
		a[i] = tmp[i];
		i++;
	}
	a[i] = ' ';
	a[i+1] = '\0';
	return tmp;
}
MyString& operator++(MyString&a) // str len +1
{
	MyString tmp(a.get_length());
	tmp.allocate(tmp.get_length());
	int i = 0;
	while (a[i] != '\0')
	{
		tmp[i] = a[i];
		i++;
	}
	tmp[i] = '\0';
	i = 0;
	a.set_length(a.get_length() + 1);
	a.deleteStr();
	a.allocate(a.get_length());
	while (tmp[i] != '\0')
	{
		a[i] = tmp[i];
		i++;
	}
	a[i] = ' ';
	a[i+1] = '\0';
	return a;
}

MyString operator + (MyString& a, const char* word)
{
	MyString tmp = a.myStrCat(word);
	return tmp;
}
MyString operator + (MyString& a, char c)
{
	MyString tmp = a.myStrCat(c);
	return tmp;
}
MyString& operator +(MyString& a, int elements)
{
	MyString tmp(a.get_length() + elements);
	tmp.allocate(tmp.get_length());
	int i = 0;
	while (a.get_arr_index(i) != '\0')
	{
		tmp[i] = a[i];
		i++;
	}
	for (int j = 0; j < elements; j++)
	{
		tmp[i] = ' ';
		i++;
	}
	tmp[i] = '\0';
	i = 0;
	a.set_length(tmp.get_length());
	a.deleteStr();
	a.allocate(a.get_length());
	while (tmp[i] != '\0')
	{
		a[i] = tmp[i];
		i++;
	}
	a[i] = '\0';
	return a;
}
MyString& operator +(int elements, MyString& a)
{
	MyString tmp(a.get_length() + elements);
	tmp.allocate(tmp.get_length());
	int i = 0;
	while (a.get_arr_index(i) != '\0')
	{
		tmp[i] = a[i];
		i++;
	}
	for (int j = 0; j < elements; j++)
	{
		tmp[i] = '_';
		i++;
	}
	tmp[i] = '\0';
	i = 0;
	a.set_length(tmp.get_length());
	a.deleteStr();
	a.allocate(a.get_length());
	while (tmp[i] != '\0')
	{
		a[i] = tmp[i];
		i++;
	}
	a[i] = '\0';
	return a;
}
ostream& operator<<(ostream& os, const MyString& a)
{
	os << a.get_str(); // Используем аксессор, чтобы получить данные
	return os;
}
istream& operator>> (istream& is, MyString& a)
{
	char buff[100];
	is >> buff;
	char* tmp = new char[strlen(buff) + 1];
	int len = (strlen(buff) + 1);
	int i;
	for (i = 0; i < len; i++)
	{
		tmp[i] = buff[i];
	}
	tmp[i] = '\0';
	a.init(tmp);
	a.set_length(len);
	return is;
}
int main()
{
	system("chcp 1251");
	MyString a("hello");
	a.print();
	MyString b = move(a);
	b.print();
	a.print();
	/*MyString b = a++;
	b.print();
	a.print();
	MyString c = ++b;
	b.print();
	c.print();
	c("privet");
	c.print();
	MyString d;
	d = a;
	d.print();
	cout << d << endl;
	cin >> d;
	cout << d << endl;*/
	/*MyString a("warsaw");
	a.print();
	MyString b("Kyiv");
	a += b;
	a.print();
	a += "haha";
	a.print();
	a -= 'a';
	a.print();*/
	/*MyString c = a + b;
	c.print();*/
	/*b.myStrCat(a);
	b.print();
	cout << a.myStrStr("Warsak")<<endl;
	cout << b.myChr('p') << endl;
	cout << a.myStrCmp(b) << endl;
	a.myDelChr('w');
	a.print();*/
	/*a = a + b;
	a.print();*/
	/*MyString d = a + "Kyiv";
	d.print();
	--a;
	++a;
	a.print();*/
	/*MyString d = a - 'w';
	d.print();*/
	/*bool test1 = a > b;
	cout << test1 << endl;
	bool test2 = a < b;
	cout << test2 << endl;
	bool test3 = a == b;
	cout << test3<< endl;
	bool test4 = a != b;
	cout << test4 << endl;
	bool test5 = a >= a;
	cout << test5 << endl;
	bool test6 = a >= b;
	cout << test6 << endl;
	bool test7 = a <= a;
	cout << test7 << endl;
	bool test8 = a <= b;
	cout << test8 << endl;*/
	return 0;
}
