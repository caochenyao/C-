#include<iostream>
#include<windows.h>
using namespace std;

class String
{
public:
	String(const char* str = "")
		:_str(new char[strlen(str) + 5])
	{
		//写实拷贝,多开辟四个字节的空间,前四个字节作为int整形用来计数
		_str += 4;
		memcpy(_str, str, strlen(str) + 1);
		//初始化计数为1
		_GetCount(_str) = 1; 

	}
	~String()
	{
		_Release();
	}
	//拷贝构造,指向要拷贝对象所指的的空间,计数加一
	String(const String& s)
	{
		if (_str != s._str)
		{
			_str = s._str;
			++_GetCount(_str);
		}
	}
	//赋值运算符重载,先释放自己所指的空间,之后与拷贝构造一样
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
	//重载[]
	char& operator[](size_t pos)
	{
		String s(_str);
		*this = s;
		return _str[pos];
	}
private:
	//得到前四个字节的计数,要用引用
	int& _GetCount(char* _ptr)
	{
		return *(int*)(_ptr - 4);
	}
	//释放空间
	void _Release()
	{
		//计数不为1时,计数减一,否则将指向的空间释放
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