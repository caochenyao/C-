#include<iostream>
#include<windows.h>
using namespace std;

class String
{
public:
	String(char* str)
		:_str(new char[strlen(str) + 1])
	{
		memcpy(_str, str, strlen(str) + 1);
	}
	String(const String& s)
		:_str(new char[strlen(s._str) + 1])
	{
		memcpy(_str, s._str, strlen(s._str) + 1);
	}
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = NULL;
		}
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			delete[] _str;
			_str = new char[strlen(s._str) + 1];
			memcpy(_str, s._str, strlen(s._str) + 1);
		}
		return *this; 
	}
	bool operator>(const String& s)
	{
		char *this_tmp = this->_str;
		char *tmp = s._str;
		while (1)
		{
			if (*tmp == '\0' && *this_tmp == '\0')
			{
				return false;
			}
			if (*this_tmp > *tmp)
			{
				return true;
			}
			else if (*this_tmp == *tmp)
			{
				this_tmp++;
				tmp++;
			}
			else
			{
				return false;
			}
		}
	}
	bool operator==(const String& s)
	{
		char *this_tmp = this->_str;
		char *tmp = s._str;
		while (1)
		{
			if (*tmp == '\0' && *this_tmp == '\0')
			{
				return true;
			}
			if (*this_tmp == *tmp)
			{
				this_tmp++;
				tmp++;
			}
			else
			{
				return false;
			}
		}
	}
	bool operator<(const String& s)
	{
		return !((*this > s) && (*this == s));
	}
	bool operator>=(const String& s)
	{
		return (*this > s) || (*this == s);
	}
	bool operator<=(const String& s)
	{
		return (*this < s) || (*this == s);
	}
	
private:
	char* _str;
};

//operator>
void Test1()
{
	String s1("Hello World");
	String s2(s1);

	String s3("Change World");

	if (s2 > s3)
	{
		cout << ">" <<endl;
	}
}

//operator<
void Test2()
{
	String s1("Hello World");
	String s2(s1);

	String s3("Hello World!!!");

	if (s2 < s3)
	{
		cout << "<" << endl;
	}
}

//operator>=
void Test3()
{
	String s1("Hello World!!!");
	String s2(s1);

	String s3("Hello World");

	if (s2 >= s3)
	{
		cout << ">=" << endl;
	}
}

//operator<=
void Test4()
{
	String s1("Hello World");
	String s2(s1);

	String s3("Hello World!!!");

	if (s2 <= s3)
	{
		cout << "<=" << endl;
	}
}

//operator==
void Test5()
{
	String s1("Hello World");
	String s2(s1);

	String s3("Hello World");

	if (s2 == s3)
	{
		cout << "==" << endl;
	}
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	system("pause");
	return 0;
}