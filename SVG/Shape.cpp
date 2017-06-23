#include "Shape.h"

void Shape::Deserialize(std::istream& is)
{
	char c;
	is.get(c);
	String buf;
	while (c != '>')
	{
		buf.Append(c);
		is.get(c);
	}
	buf.Remove("\"");
	buf.Remove("\\");
	buf.Remove('/');
	buf.Remove("\n");
	auto attributePairs = buf.Split();
	for (int i = 0; i < attributePairs.size(); i++)
	{
		auto temp = attributePairs[i].Split('=');
		this->DeserializeHelper(temp[0], temp[1]);
	}
}

