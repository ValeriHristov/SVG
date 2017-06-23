#include "ConsoleInterface.h"
#include "ShapeFactory.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"
#include <fstream>

void PrintInvalidInput()
{
	std::cout << "Invalid input!\n";
}

String GetNextTagName(std::istream& is)
{

	char c;
	String s;
	s = "";
	do
	{
		c = is.get();

	} while (c != '<' && c > 0);

	c = is.get();
	while (c != ' ' && c != '>')
	{
		s.Append(c);
		c = is.get();
	}
	return s;
}

void ConsoleInterface::Open(String& fileName)
{
	std::ifstream str;
	char* file = fileName.ToCharArray();
	str.open(file, std::ifstream::out);
	delete[] file;
	if (!str.is_open())
	{
		PrintInvalidInput();
		return;
	}
	this->currentFileName = fileName;
	this->Read(str);
	std::cout << "Successfully opened " << fileName << "\n";
	str.close();
}

void ConsoleInterface::Read(std::istream& is)
{
	if (!is.good())
	{
		std::cout << "Invalid stream!\n";
		return;
	}
	String s;
	char c;
	while (GetNextTagName(is) != "svg")
	{
	}

	ShapeFactory factory;
	String tagName = GetNextTagName(is);
	while (tagName != "/svg")
	{
		Shape* shape = factory.CreateShape(tagName);
		if (shape != nullptr)
		{
			shape->Deserialize(is);
			this->shapes.push_back(shape);
		}
		tagName = GetNextTagName(is);
	}
}

void ConsoleInterface::Run()
{
	String input;
	while (true)
	{
		std::cout << "> ";
		std::cin >> input;
		auto parameters = input.Split();
		String operation = parameters[0];
		if (operation == "print")
		{
			this->Print();
		}
		else if (operation == "create")
		{
			this->Create(parameters);
		}
		else if (operation == "erase")
		{
			this->Erase((int)parameters[1]);
		}
		else if (operation == "translate")
		{
			this->Translate(parameters);
		}
		else if (operation == "save")
		{
			this->Save();
		}
		else if (operation == "open")
		{
			if (parameters.size() != 2)
			{
				PrintInvalidInput();
			}
			this->Open(parameters[1]);
		}
		else if (operation == "within")
		{

		}
		else if (operation == "exit")
		{
			std::cout << "Exit\n";
			return;
		}
		else
		{
			PrintInvalidInput();
		}
	}
}

void ConsoleInterface::Print()const
{
	for (int i = 0; i < this->shapes.size(); i++)
	{
		std::cout << i << ". " << this->shapes[i]->ToString();
	}
}

void ConsoleInterface::Create(std::vector<String> parameters)
{
	Shape* newShape;
	if (parameters[1] == "rectangle")
	{
		if (parameters.size() < 6)
		{
			PrintInvalidInput();
			return;
		}
		int x = (int)parameters[2];
		int y = (int)parameters[3];
		int width = (int)parameters[4];
		int height = (int)parameters[5];
		int rx = 0;
		int ry = 0;
		if (parameters.size() > 7)
		{
			rx = (int)parameters[6];
			ry = (int)parameters[7];
		}
		String fill;
		if (parameters.size() == 9)
		{
			fill = parameters[8];
		}
		Rectangle* rect = new Rectangle(width, height, x, y, rx, ry);
		rect->SetFill(fill);
		newShape = rect;
	}
	else if (parameters[1] == "circle")
	{
		if (parameters.size() < 5)
		{
			PrintInvalidInput();
			return;
		}
		int cx = (int)parameters[2];
		int cy = (int)parameters[3];
		int r = (int)parameters[4];

		String fill;
		if (parameters.size() > 5)
		{
			fill = parameters[5];
		} 
		Circle* circle = new Circle(cx, cy, r);
		circle->SetFill(fill);
		newShape = circle;
	}
	else if (parameters[1] == "line")
	{
		if (parameters.size() != 7)
		{
			PrintInvalidInput();
			return;
		}
		int x1 = (int)parameters[2];
		int y1 = (int)parameters[3];
		int x2 = (int)parameters[4];
		int y2 = (int)parameters[5];
		int strokeWidth = (int)parameters[6];
		Line* line = new Line(x1, y1, x2, y2);
		line->SetStrokeWidth(strokeWidth);
		newShape = line;
	}
	else
	{
		PrintInvalidInput();
		return;
	}

	this->shapes.push_back(newShape);
	std::cout << "Successfully created " << newShape->GetType() << " " << this->shapes.size() << "\n";

}

void ConsoleInterface::Erase(int index)
{
	if (index >= this->shapes.size())
	{
		std::cout << "There is no figure number " << index << "\n";
		return;
	}
	Shape* figure = this->shapes[index];
	this->shapes.erase(this->shapes.begin() + index);
	std::cout << "Erased a " << figure->GetType() << " (" << index << ")\n";
	delete figure;
}

void ConsoleInterface::Translate(std::vector<String> parameters)
{
	if (parameters.size() < 3)
	{
		PrintInvalidInput();
		return;
	}
	int dy = (int)parameters[1].Split('=')[1];
	int dx = (int)parameters[2].Split('=')[1];
	if (parameters.size() == 3)
	{
		for (int i = 0; i < this->shapes.size(); i++)
		{
			this->shapes[i]->Translate(dx, dy);
		}
		std::cout << "Translated all figures\n";
		return;
	}
	int index = (int)parameters[3];
	this->shapes[index]->Translate(dx, dy);
	std::cout << "Translated " << index << "\n";
}

void ConsoleInterface::Save()
{
	std::ofstream ofs;
	char* file = this->currentFileName.ToCharArray();
	ofs.open(file, std::ofstream::out, std::ofstream::trunc);
	delete[] file;

	ofs << this->XMLHeader << this->SVGOpenTag;

	for (int i = 0; i < this->shapes.size(); i++)
	{
		this->shapes[i]->Serialize(ofs);
	}

	ofs << this->SVGCloseTag;
	ofs.close();
	this->Clear();
}

void ConsoleInterface::Clear()
{
	this->currentFileName = "";
	for (int i = 0; i < this->shapes.size(); i++)
	{
		delete this->shapes[i];
	}
	this->shapes.clear();
}