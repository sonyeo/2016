#include <stdio.h>
#include <string>

class KInt
{
public:
	int _i;
	KInt(int i = 0)
	{
		_i = i + 10;
		printf("%s\r\n", __FUNCTION__);
	}
	KInt(const KInt& rhs)
	{
		_i = rhs._i + 20;
		printf("copy %s\r\n", __FUNCTION__);
	}
};

class KTest
{
public:
	std::string _name;
	KInt _i;

	KTest() = default;
	KTest(const KTest&) = default; // = delete;
};

void Test(KTest t)
{
	printf("%i\r\n", t._i._i);
}

void main()
{
	KTest t;
	Test(t);
	printf("%i\r\n", t._i._i);
}
/*	output:
	KInt::KInt
	copy KInt::KInt
	30
	10
*/
