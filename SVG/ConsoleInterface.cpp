#include "ConsoleInterface.h"
#include "ShapeFactory.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"
#include <fstream>

bool ContainedInRectangle(const Rectangle& rect, const Shape* shape)
{
	return rect.LeftMostPoint() <= shape->LeftMostPoint() &&
		rect.LeftMostPoint() <= shape->BottomPoint() &&
		rect.RightMostPoint() >= shape->RightMostPoint() &&
		rect.RightMostPoint() >= shape->TopPoint();
}

bool ContainedInCircle(const Circle& circle, const Shape* shape)
{
	Point centre(circle.GetCx(), circle.GetCy());
	int r = circle.GetR();
	bool contained = true;
	if (centre.GetDistanceTo(shape->BottomPoint()) > r ||
		centre.GetDistanceTo(shape->LeftMostPoint()) > r ||
		centre.GetDistanceTo(shape->RightMostPoint()) > r ||
		centre.GetDistanceTo(shape->TopPoint()) > r)
	{
		contained = false;
	}
	return contained;
}

Circle* CreateCircle(std::vector<String> parameters)
{
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
	return circle;
}

Line* CreateLine(std::vector<String> parameters)
{
	int x1 = (int)parameters[2];
	int y1 = (int)parameters[3];
	int x2 = (int)parameters[4];
	int y2 = (int)parameters[5];
	int strokeWidth = (int)parameters[6];
	Line* line = new Line(x1, y1, x2, y2);
	line->SetStrokeWidth(strokeWidth);
	return line;
}

Rectangle* CreateRectangle(std::vector<String> parameters)
{
	int x = (int)parameters[2];
	int y = (int)parameters[3];
	int width = (int)parameters[4];
	int height = (int)parameters[5];

	String fill;
	if (parameters.size() == 7)
	{
		fill = parameters[6];
	}
	Rectangle* rect = new Rectangle(width, height, x, y);
	rect->SetFill(fill);
	return rect;
}

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
		else if (operation == "saveas")
		{
			this->SaveAs(parameters[1]);
		}
		else if (operation == "open")
		{
			if (parameters.size() != 2)
			{
				PrintInvalidInput();
				return;
			}
			this->Open(parameters[1]);
		}
		else if (operation == "within")
		{
			if (parameters.size() < 5)
			{
				PrintInvalidInput();
				return;
			}
			this->Within(parameters);
		}
		else if (operation == "exit")
		{
			std::cout << "Exit\n";
			this->Clear();
			return;
		}
		else if (operation == "close")
		{
			this->Clear();
			std::cout << "Closed current file\n";
		}
		else
		{
			PrintInvalidInput();
		}
	}
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
	this->Clear();
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

void ConsoleInterface::Print()const
{
	for (int i = 0; i < this->shapes.size(); i++)
	{
		std::cout << i + 1 << ". " << this->shapes[i]->ToString();
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

		newShape = CreateRectangle(parameters);
	}
	else if (parameters[1] == "circle")
	{
		if (parameters.size() < 5)
		{
			PrintInvalidInput();
			return;
		}
		newShape = CreateCircle(parameters);
	}
	else if (parameters[1] == "line")
	{
		if (parameters.size() != 7)
		{
			PrintInvalidInput();
			return;
		}
		newShape = CreateLine(parameters);
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
	Shape* figure = this->shapes[index - 1];
	this->shapes.erase(this->shapes.begin() + index - 1);
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
	this->SaveAs(this->currentFileName);
}

void ConsoleInterface::SaveAs(String filename)
{
	std::ofstream ofs;
	char* file = filename.ToCharArray();
	ofs.open(file, std::ofstream::out, std::ofstream::trunc);

	if (!ofs.is_open())
	{
		PrintInvalidInput();
		return;
	}
	ofs << this->XMLHeader << this->SVGOpenTag;

	for (int i = 0; i < this->shapes.size(); i++)
	{
		this->shapes[i]->Serialize(ofs);
	}

	ofs << this->SVGCloseTag;
	ofs.close();
	std::cout << "Successfully saved to " << file << " \n";
	delete[] file;
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

void ConsoleInterface::Within(std::vector<String> params)
{
	std::vector<int> indexes;
	if (params.size() == 5)
	{
		Circle* circle = CreateCircle(params);
		for (int i = 0; i < this->shapes.size(); i++)
		{
			if (ContainedInCircle(*circle, this->shapes[i]))
			{
				indexes.push_back(i);
			}
		}
		delete circle;
	}
	else if (params.size() == 6)
	{
		Rectangle* rect = CreateRectangle(params);
		for (int i = 0; i < this->shapes.size(); i++)
		{
			if (ContainedInRectangle(*rect, this->shapes[i]))
			{
				indexes.push_back(i);
			}
		}
		delete rect;
	}
	else
	{
		PrintInvalidInput();
		return;
	}
	if (indexes.size() == 0)
	{
		std::cout << "No shapes are located within ";
		for (int i = 1; i < params.size(); i++)
		{
			std::cout << params[i] << " ";
		}
		std::cout << "\n";
		return;
	}
	for (int i = 0; i < indexes.size(); i++)
	{
		std::cout << i + 1 << ". " << this->shapes[indexes[i]]->ToString();
	}
}