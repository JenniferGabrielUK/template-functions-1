// template-functions-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>

template <typename T>
T min(T a, T b) {
	return (a < b) ? a : b;
}

template <typename T1, class T2>
void func(T1 a, T2 b) {
	std::cout << a << " -  " << b << std::endl;
}

struct Person {
	std::string name;
	int age;
	bool operator<(const Person& rhs) const {
		return this->age < rhs.age;
	}
};

std::ostream& operator<< (std::ostream& os, const Person& p) {
	os << p.name << std::endl;
	return os;
}

template <class T>
void myswap(T& a, T& b) {
	std::cout << "Calling swap function..." << std::endl;
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
	Person p1{ "Jenny", 35 };
	Person p2{"Elizabeth", 18};
	Person p3 = min(p1, p2);
	std::cout << p3.name << " is younger " << std::endl;
	std::cout << "Return less than int: " << min(1, 3) << ", parameters passed: 1,3" << std::endl;
	std::cout << "Return less than int: " << min(100.4, 35.7) << ", parameters passed: 100.4, 35.7" << std::endl;
	std::cout << "Return less than int: " << min('A', 'B') << ", parameters passed: A, B" << std::endl;
	std::cout << "Return less than int: " << min(12.5, 9.2) << ", parameters passed: 12.5, 9.2" << std::endl;
	std::cout << "Return less than int: " << min(5 + 2 * 2, 7 + 40) << ", parameters passed: 5 + 2 * 2, 7 + 40" << std::endl;
	func <int, int>(10, 20);
	func(10, 20);
	func <char, double >('A', 11.0);
	func(p1, p2);
	int x{ 100 };
	int y{ 200 };
	std::cout << x << " : " << y << std::endl;
	myswap(x, y);
	std::cout << x << " : " << y << std::endl;
	std::string name1{ "Jenny" };
	std::string name2{ "Elizabeth" };
	std::cout << name1 << " : " << name2 << std::endl;
	myswap(name1, name2);
	std::cout << name1 << " : " << name2 << std::endl;
	return 0;
}
