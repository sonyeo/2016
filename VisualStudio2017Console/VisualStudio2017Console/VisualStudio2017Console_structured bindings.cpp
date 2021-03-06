#include <stdio.h>
#include <iostream>
#include <tuple>
#include <algorithm>
#include <utility>
#include <map>
#include <string>

struct KPoint3D
{
	double x;
	double y;
	double z;
};

int main()
{
	std::tuple<double, double, double>	t{1.0, 2.3, 4.5};
	std::cout << std::get<1>(t) << std::endl;
	double x, y, z;
	std::tie(x, y, z) = t;
	std::cout << x << ", " << y << ", " << z << ", " << std::endl;

	// structured bindings
	// auto[a,b, ...] = obj;
	//
	auto[x2, y2, z2] = t;
	std::cout << x2 << ", " << y2 << ", " << z2 << ", " << std::endl;
	KPoint3D	p;
	p.x = 2.1;
	p.y = 3.1;
	p.z = 4.1;
	auto[x3, y3, z3] = p;
	std::cout << x3 << ", " << y3 << ", " << z3 << ", " << std::endl;

	std::map<double, std::string>	m;
	m[1.0] = std::string("first");
	m.insert( std::pair<double,std::string>(3.0, std::string("third")));
	m[2.0] = std::string("second");
	for (auto[key, value] : m) {
		std::cout << key << ", " << value << std::endl;
	}
	return 0;
}
