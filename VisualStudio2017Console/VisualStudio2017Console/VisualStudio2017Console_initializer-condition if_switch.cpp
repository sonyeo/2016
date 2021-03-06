#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
#include <string>

int main()
{
	std::map<double, std::string>	m;
	m[1.0] = std::string("first");
	m.insert(std::pair<double, std::string>(3.0, std::string("third")));
	m[2.0] = std::string("second");

	// initializer-condition for 'if' and 'switch' statements
	// jintaeks on 2017-10-29_19-27
	// if( init; cond )
	//     statement1;
	// else
	//     statement2;
	if (auto it = m.find(2.0); it != m.end()) {
		//   ^ initializer     ^ condition
		std::cout << it->second << std::endl;
	}
	else {
		// 'it' can be accessed here.
	}
}
