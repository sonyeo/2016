// ConsoleApplicationVs2017.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <iostream>
#include <algorithm>

class KData
{
private:
    char*   buffer;
    int     iData;

public:
    static int iConstructor;
    static int iCopyConstructor;
    static int iDestructor;

public:
    KData(int d_ = 0)
    {
        std::cout << "constructor" << std::endl;
        iData = d_;
        ++iConstructor;
        buffer = new char[100];
    }
    KData(const KData& rhs_)
    {
        std::cout << "copy constructor" << std::endl;
        ++iCopyConstructor;
        buffer = new char[100];
        memcpy(buffer, rhs_.buffer, sizeof(char) * 100);
    }
    ~KData()
    {
        std::cout << "destructor" << std::endl;
        ++iDestructor;
        delete[] buffer;
        buffer = nullptr;
    }
    void SetInt(int d_)
    {
        iData = d_;
    }
};

int KData::iConstructor = 0;
int KData::iCopyConstructor = 0;
int KData::iDestructor = 0;

int main()
{
    {
        std::vector<KData>  v;
        v.reserve(100);
        for (int i = 0; i < 100; ++i)
        {
            KData d(i);
            //d.SetInt(i);
            v.push_back(d);
        }
    }

    std::cout << KData::iConstructor << std::endl;
    std::cout << KData::iCopyConstructor << std::endl;
    std::cout << KData::iDestructor << std::endl;

    return 0;
}

