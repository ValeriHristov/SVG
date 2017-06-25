#pragma once
#include "ShapeFactory.h"
#include <vector>
class ConsoleInterface
{
private:
	String XMLHeader = "<?xml version=\"1.0\" standalone=\"no\"?>\n<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"\n/\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n";
	String SVGOpenTag = "<svg>\n";
	String SVGCloseTag = "</svg>\n";
	String currentFileName;
	std::vector<Shape*> shapes;
	void Clear();
	void Open(String& fileName);
	void Read(std::istream& is = std::cin);
	void Print()const;
	void Create(std::vector<String> parameters);
	void Erase(int index);
	void Translate(std::vector<String> parameters);
	void Save();
	void SaveAs(String filename);
	void Close();
	void Within(std::vector<String> params);
	void PrintHelp();
	void PrintWelcome();
public:
	void Run();
	
};
