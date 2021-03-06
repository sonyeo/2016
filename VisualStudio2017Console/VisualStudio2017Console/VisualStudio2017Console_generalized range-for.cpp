#include <iostream>
#include <string>

// a struct to get the first word of a string

struct FirstWord {
    std::string data;

    // declare a predicate to make ' ' a string ender

    struct EndOfString {
        bool operator()(std::string::iterator it) { return (*it) != '\0' && (*it) != ' '; }
    };

    std::string::iterator begin() { return data.begin(); }
    //EndOfString end() { return EndOfString(); }
    std::string::iterator end() { return data.end(); }
};

// declare the comparison operator

bool operator!=(std::string::iterator it, FirstWord::EndOfString p) { return p(it); }

// test

int main() {
    for (auto c : { "Hello World !!!" })
        std::cout << c;
    std::cout << std::endl; // print "Hello World !!!"

    for (auto c : FirstWord{ "Hello World !!!" }) // works with gcc with C++17 enabled
        std::cout << c;
    std::cout << std::endl; // print "Hello"
}
