#include<iostream>
#include<windows.h>
using namespace std;

class String
{
public:
	String(const char* str = "")
		:_str(new char[strlen(str) + 5])
	{
		_str += 4;
		memcpy(_str, str, strlen(str) + 1);
		_GetCount(_str) = 1;

	}
	~String()
	{
		_Release();
	}
	String(const String& s)
	{
		if (_str != s._str)
		{
			_str = s._str;
			++_GetCount(_str);
		}
	}
	String& operator=(const String& s)
	{
		if (_str != s._str)
		{
			_Release();
			_str = s._str;
			++_GetCount(_str);
		}
		return *this;
	}
	char& operator[](size_t pos)
	{
		String s(_str);
		*this = s;
		return _str[pos];
	}
private:
	int& _GetCount(char* _ptr)
	{
		return *(int*)(_ptr - 4);
	}
	void _Release()
	{
		if (--_GetCount(_str) == 0)
		{
			_str -= 4;
			delete[] _str;
			cout << "~String()" << endl;
		}
	}
private:
	char* _str;
};

void Test1()
{
	String s1("aaaaaaaaaaaaaaa");
	String s2(s1);
	String s3(s2);

	String s4("bbbbbbbbbb");
	String s5(s4);

	s3 = s4;

	s3[5] = 'c';
}

int main()
{
	Test1();

	system("pause");
	return 0;
}