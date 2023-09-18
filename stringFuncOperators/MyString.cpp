#include "MyString.h"
#include <iostream>
using namespace std;
MyString::MyString()
{
	createdObj++;
	this->length = 81;
	this->str = new char[length];

}
MyString::MyString(int length)
{
	createdObj++;

	this->length = length;
	this->str = new char[length];
}
MyString::MyString(const char* str)
{
	createdObj++;

	this->length = strlen(str) + 1;
	this->str = new char[length];
	strcpy_s(this->str, strlen(str) + 1, str);
}
MyString::MyString(const MyString& b)
{
	this->myStrCpy(b);
	createdObj++;
}
MyString::~MyString()
{
	if (this->str != nullptr)
		delete[]this->str;
	cout << "Destructor" << endl;
}
int MyString::get_length()const
{
	return this->length;
}
void MyString::set_length(int len)
{
	this->length = len;
}
void MyString::deleteStr()
{
	if (this->str != nullptr)
		delete[]this->str;
}
void MyString::allocate(int len)
{
	this->str = new char[len + 1];
}
char MyString::get_arr_index(int index) const
{
	return this->str[index];
}

void MyString::init(const char* str)
{
	if (this->str != nullptr)
		delete[]this->str;
	this->length = strlen(str) + 1;
	this->str = new char[length];
	strcpy_s(this->str, strlen(str) + 1, str);
}
void MyString::print()const
{
	cout << str << endl;
}
void MyString::myStrCpy(const MyString& obj)
{
	if (this->str != nullptr)
		delete[]str;
	this->length = obj.length + 1;
	this->str = new char[this->length + 1];
	strcpy_s(this->str, this->length + 1, obj.str);
}
bool MyString::myStrStr(const char* str)const
{
	int i = 0, j = 0;
	while (this->str[i] != '\0')
	{
		if (this->str[i] == str[j])
		{
			while (this->str[i] == str[j])
			{
				i++;
				j++;
			}
			if (str[j] == '\0')
				return true;
		}
		else
			i++;
	}
	return false;
}
int MyString::myChr(char c)const //поиск символа в строке(индекс найденного символа, либо -1)
{
	int i = 0;
	while (this->str[i] != '\0')
	{
		if (str[i] == c)
			return i;
		i++;
	}
	return -1;
}

int MyString::myStrLen()const //return str length
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}
MyString MyString::myStrCat(MyString& b) // concatenation
{
	MyString tmp((int)this->length + b.length - 1);
	tmp.str = new char[tmp.length];
	for (int i = 0, j = 0; i < tmp.length; i++)
	{
		if (i < this->length - 1)
		{
			tmp.str[i] = this->str[i];
		}
		else
		{
			tmp.str[i] = b.str[j];
			j++;
		}
	}
	return tmp;
}
MyString MyString::myStrCat(const char* word)
{
	MyString tmp((int)this->length + strlen(word));
	tmp.str = new char[tmp.length];
	for (int i = 0, j = 0; i < tmp.length; i++)
	{
		if (word[j] == '\0')
			break;
		if (i < this->length - 1)
			tmp.str[i] = this->str[i];
		else
		{
			tmp.str[i] = word[j];
			j++;
		}
	}
	tmp.str[tmp.length - 1] = '\0';
	return tmp;
}
void MyString::myDelChr(char c) // удаляет указанный символ
{
	int i = 0, newsize = 0, j = 0;
	while (this->str[i] != '\0')
	{
		if (this->str[i] != c)
			newsize++;
		i++;
	}
	MyString tmp(newsize + 1);
	tmp.str = new char[tmp.length];
	i = 0;
	while (this->str[i] != '\0')
	{
		if (this->str[i] != c)
		{
			tmp.str[j] = this->str[i];
			j++;
		}
		i++;
	}
	tmp.str[newsize] = '\0';
	if (this->str != nullptr)
		delete[]this->str;
	this->str = new char[newsize + 1];
	i = 0;
	while (tmp.str[i] != '\0')
	{
		this->str[i] = tmp.str[i];
		i++;
	}
	this->str[newsize] = '\0';
}
int MyString::myStrCmp(MyString& b)const // сравнение строк 
{
	int i = 0;
	while (this->str[i] != '\0')
	{
		if (this->str[i] > b.str[i])
			return 1;
		else if (this->str[i] < b.str[i])
			return -1;
		i++;
	}
	return 0;
}
//MyString MyString:: operator + (MyString& b)
//{
//	MyString tmp = this->myStrCat(b);
//	return tmp;
//}
//MyString MyString:: operator + (const char* word)
//{
//	MyString tmp = this->myStrCat(word);
//	return tmp;
//}
MyString MyString::myStrCat(const char c)
{
	MyString tmp(this->length + 1);
	tmp.str = new char[tmp.length];
	int i = 0;
	while (this->str[i] != '\0')
	{
		tmp.str[i] = str[i];
		i++;
	}
	tmp.str[i] = c;
	tmp.str[i + 1] = '\0';
	return tmp;
}


MyString& MyString::operator--()
{
	MyString tmp(this->length - 1);
	tmp.length = this->length - 1;
	tmp.str = new char[tmp.length];
	int i = 0;
	while (this->str[i + 1] != '\0')
	{
		tmp.str[i] = this->str[i];
		i++;
	}
	tmp.str[i] = '\0';
	i = 0;
	if (this->str != nullptr)
		delete[] this->str;
	this->length = tmp.length;
	this->str = new char[this->length];
	while (tmp.str[i] != '\0')
	{
		this->str[i] = tmp.str[i];
		i++;
	}
	this->str[i] = '\0';
	return *this;
}
//MyString MyString:: operator++(int) // postfix увеличение размера строки на 1
//{
//	MyString retObj(this->str);
//	MyString tmp(this->length + 1);
//	tmp.str = new char[tmp.length];
//	int i = 0;
//	while (str[i] != '\0')
//	{
//		tmp.str[i] = str[i];
//		i++;
//	}
//	tmp.str[i] = '\0';
//	i = 0;
//	this->length++;
//	if (this->str != nullptr)
//		delete[]this->str;
//	this->str = new char[this->length];
//	while (tmp.str[i] != '\0')
//	{
//		str[i] = tmp.str[i];
//		i++;
//	}
//	str[i] = ' ';
//	str[length - 1] = '\0';
//	return retObj;
//}
MyString MyString::operator--(int) //postfix удаление последнего символа строки
{
	MyString retObj(this->str);
	MyString tmp(this->length - 1);
	tmp.length = this->length - 1;
	tmp.str = new char[tmp.length];
	int i = 0;
	while (this->str[i + 1] != '\0')
	{
		tmp.str[i] = this->str[i];
		i++;
	}
	tmp.str[i] = '\0';
	i = 0;
	if (this->str != nullptr)
		delete[] this->str;
	this->length = tmp.length;
	this->str = new char[this->length];
	while (tmp.str[i] != '\0')
	{
		this->str[i] = tmp.str[i];
		i++;
	}
	this->str[i] = '\0';
	return retObj;
}
MyString& MyString:: operator - (char c) // удаление символа из строки
{
	this->myDelChr(c);
	return *this;
}
MyString& MyString:: operator +=(MyString& b)//simplified concatenation
{
	MyString tmp = this->myStrCat(b);
	if (this->str != nullptr)
		delete[]this->str;
	this->length = tmp.length;
	this->str = new char[this->length];
	int i = 0, j = 0;
	while (tmp.str[i] != '\0')
	{
		this->str[i] = tmp.str[i];
		i++;
	}
	this->str[i] = '\0';
	return *this;
}
MyString& MyString:: operator +=(const char* word)//simplified concatenation
{
	MyString tmp = this->myStrCat(word);
	if (this->str != nullptr)
		delete[]this->str;
	this->length = tmp.length;
	this->str = new char[this->length];
	int i = 0, j = 0;
	while (tmp.str[i] != '\0')
	{
		this->str[i] = tmp.str[i];
		i++;
	}
	this->str[i] = '\0';
	return *this;
}
MyString& MyString::operator -=(char c)
{
	this->myDelChr(c);
	return *this;
}

bool MyString:: operator > (MyString& b) //сравнение строк(по таблице ascii)
{
	int i = 0;
	while (str[i] != '\0' && b.str[i] != '\0')
	{
		if (str[i] > b.str[i])
			return true;
		else if (str[i] < b.str[i])
			return false;
	}
	return false;
}
bool MyString:: operator < (MyString& b)
{
	int i = 0;
	while (str[i] != '\0' && b.str[i] != '\0')
	{
		if (str[i] > b.str[i])
			return false;
		else if (str[i] < b.str[i])
			return true;
		i++;

	}
	return false;
}
bool MyString:: operator >= (MyString& b)
{
	int i = 0;
	bool flag = 0;
	while (str[i] != '\0' && b.str[i] != '\0')
	{
		if (str[i] > b.str[i])
			return true;
		else if (str[i] < b.str[i])
			return false;
		i++;

	}
	return true;
}
bool MyString:: operator <= (MyString& b)
{
	int i = 0;
	bool flag = 0;
	while (str[i] != '\0' && b.str[i] != '\0')
	{
		if (str[i] < b.str[i])
			return true;
		else if (str[i] > b.str[i])
			return false;
		i++;

	}
	return true;
}
bool MyString:: operator == (MyString& b)
{
	int i = 0;
	while (str[i] != '\0' && b.str[i] != '\0')
	{
		if (str[i] != b.str[i])
			return false;
		i++;

	}
	return true;
}
bool MyString:: operator != (MyString& b)
{
	int i = 0;
	while (str[i] != '\0' && b.str[i] != '\0')
	{
		if (str[i] != b.str[i])
			return true;
		i++;

	}
	return true;
}
char& MyString::operator [](int index)
{
	if (index >= 0 && index <= this->length)
		return str[index];
	return str[0];
}
void MyString :: operator ()(const char*word)
{
	if (this->str != nullptr)
		delete[]str;
	str = new char[strlen(word) + 1];
	strcpy_s(str, strlen(word) + 1, word);
}
