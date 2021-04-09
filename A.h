#pragma once
#include <iostream>
class A
{
protected:
	int a_value;

public:
	A()
	{
		a_value = 0;
		std::cout << "Object A created!" << std::endl;
	}
	A(int value_input) : a_value{ value_input }
	{
		std::cout << "Object A created!" << std::endl;
	}
};

