#include <stdio.h>
#include <stdlib.h>

struct KTest {
	int iAge;
	int iHp;
	int aData[4];
	int iMp;

	void SetHp(KTest* this_, int hp)
	{
		this_->iHp = hp;
	}
	void SetHp2(int hp)
	{
		this->iHp = hp;
	}
};

void SetHp(KTest* pt, int hp)
{
	pt->iHp = hp;
}

void main() {
	KTest t = { 1, 3, { 6, 7, 8, 9 }, 5 };
	SetHp(&t, 99);
	printf("%i\r\n", t.iHp);
	t.SetHp(&t, 999);
	printf("%i\r\n", t.iHp);
	t.SetHp2(9999);
	printf("%i\r\n", t.iHp);
	/*
	99
	999
	9999
	*/
}