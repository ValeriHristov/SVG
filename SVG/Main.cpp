#include <iostream>
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"
#include "ConsoleInterface.h"
#include <fstream>
int main()
{
	/*Rectangle a(10, 10, 5, 5);
	a.SetFill("green");
	a.Serialize(std::cout);
	Circle b(5, 5, 10);
	b.SetFill("blue");
	b.Serialize(std::cout);
	Line c(100, 300, 300, 100);
	c.SetStrokeWidth(5);
	c.Serialize(std::cout);*/
	/*Circle b;
	b.Deserialize(std::cin);
	b.Serialize(std::cout);
	std::cout << std::endl;


	std::cout << std::endl;*//*
	Line c;
	c.Deserialize(std::cin);
	c.Serialize(std::cout);*//*
	Rectangle a;
	a.Deserialize(std::cin);
	a.Serialize(std::cout);*/

	ConsoleInterface con;
	con.Run();

	return 0;
}

