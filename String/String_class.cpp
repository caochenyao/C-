#include<iostream>
#include<windows.h>
#include<assert.h>
using namespace std;

class String
{
public:
	String(const char* str = "")
	{
		int len = strlen(str);
		_size = len;
		_capacity = len + 1;
		_str = new char[_capacity];
		memcpy(_str, str, _capacity);
	}
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = NULL;
		}
	}
	void _Swap(String& s)
	{
		swap(_str,s._str);
		swap(_size,s._size);
		swap(_capacity,s._capacity);
	}
	void Display()
	{
		cout << _str << endl;
	}
	//尾插
	void PushBack(char ch)
	{
		Checkcapacity(_size + 2);
		_str[_size++] = ch;
		_str[_size] = '\0';
	}
	//在指定位置插入字符
	void Insert(size_t pos,char ch)
	{
		assert(pos>=0 && pos <= _size);
		Checkcapacity(_size + 2);
		int end = _size + 1;
		while (end > pos)
		{
			_str[end + 1] = _str[end];
			--end;
		}
		_str[pos] = ch;
		_size++;
	}
	//在指定位置插入字符串
	void Insert(size_t pos,char* str)
	{
		assert(pos >= 0 && pos <= _size);
		Checkcapacity(_size + strlen(str) + 1);
		int end = _size + 1;
		while (end > pos)
		{
			_str[end + strlen(str)] = _str[end];
			--end;
		}
		while (*str)
		{
			_str[pos++] = *(str++);
		}
		_size += strlen(str);
	}
	//查找某字符返回位置下标
	int Find(char ch)
	{
		char* str = _str;
		int begin = 0;
		while (begin <= _size)
		{
			if (str[begin] == ch)
			{
				return begin;
			}
			begin++;
		}
		cout << "There is no data!" << endl;
		return -1;
	}
	//查找字符串返回其第一个字符下标
	int Find(const char* str)
	{
		char* _first = _str;
		const char* str1 = str;
		int flag = 1;
		int pos = 0;
		while (*_first)
		{
			if (flag == 1 && *str1 == '\0')
			{
				return (pos - strlen(str));
			}
			if (*_first == *str1)
			{
				flag = 1;
				pos++;
				_first++;
				str1++;
			}
			else
			{
				if (flag == 1)
				{
					flag = 0;
					str1 = str;
				}
				else
				{
					pos++;
					_first++;
					str1 = str;
				}
			}
		}
		return -1;
	}
	//删除指定位置的字符
	void Earse(size_t pos)
	{
		Earse(pos,1);
	}
	//删除指定位置的字符及其之后的n-1个字符
	void Earse(size_t pos,size_t n)
	{
		assert(pos>=0 && pos <=_size-1);
		if (n >= _size - pos)
		{
			_str[pos] = '\0';
		}
		else
		{
			while (_str[pos])
			{
				_str[pos] = _str[pos + n];
				pos++;
			}
		}
	}
	char& operator[](size_t index)
	{
		return _str[index];
	}
private:
	//检查容量,容量不足则增容
	void Checkcapacity(size_t size)
	{
		if (size > _capacity)
		{
			int newcapacity = size > 2 * _capacity ? size : 2 * _capacity;
		    _str = (char*)realloc(_str,newcapacity);
		}
	}
private:
	char* _str;
	size_t _size;
	size_t _capacity;
};
//PushBack
void Test1()
{
	String s("Hello worl");
	s.Display();

	s.PushBack('d');
	s.Display();
}
//Insert
void Test2()
{
	String s("Hello orld");
	s.Display();

	s.Insert(6,'w');
	s.Display();
}
//Insert(,*)
void Test3()
{
	String s("Hello ld");
	s.Display();

	s.Insert(6, "wor");
	s.Display();
}
//Find
void Test4()
{
	String s("Hello world");
	s.Display();

	int num = s.Find('a');
	cout << "The location is:" << num << endl;
}
//Find(*)
void Test5()
{
	String s("Hello wowoworld");
	s.Display();

	int num = s.Find("wor");
	cout << "The location is:" << num << endl;

	num = s.Find("abc");
	cout << "The location is:" << num << endl;
}
//Earse
void Test6()
{
	String s("Hello world");
	s.Display();

	s.Earse(3);
	s.Display();
}
//Earse(,)
void Test7()
{
	String s("Hello world");
	s.Display();

	s.Earse(6,3);
	s.Display();
}

int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	Test5();
	//Test6();
	//Test7();
	system("pause");
	return 0;
}