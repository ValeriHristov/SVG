#include "Rectangle.h"

Rectangle::Rectangle() : x(0), y(0), width(0), height(0){}

Rectangle::Rectangle(int width, int height, int x, int y)
	: x(x), y(y)
{
	this->SetWidth(width);
	this->SetHeight(height);
}

void Rectangle::SetX(int x)
{
	this->x = x;
}
void Rectangle::SetY(int y)
{
	this->y = y;
}
void Rectangle::SetWidth(int width)
{
	if (width < 0)
	{
		width = 0;
	}
	this->width = width;
}
void Rectangle::SetHeight(int height)
{
	if (height < 0)
	{
		height = 0;
	}
	this->height = height;
}
void Rectangle::SetFill(String& fill)
{
	if (fill == "")
	{
		fill = "none";
	}
	this->fill = fill;
}
String Rectangle::GetType() const
{
	return "rect";
}
void Rectangle::Serialize(std::ostream& os) const
{
	this->StartSerialize(os);
	this->SerializeAttribute(os, "x", x);
	this->SerializeAttribute(os, "y", y);
	this->SerializeAttribute(os, "width", width);
	this->SerializeAttribute(os, "height", height);
	this->SerializeAttribute(os, "fill", fill);
	this->EndSerialize(os);
}
void  Rectangle::Translate(int dx, int dy)
{
	this->SetX(this->x + dx);
	this->SetY(this->y + dy);
}

void Rectangle::DeserializeHelper(String attName, String attValue)
{
	if (attName == "x")
	{
		this->SetX((int)attValue);
	}
	else if (attName == "y")
	{
		this->SetY((int)attValue);
	}
	else if (attName == "width")
	{
		this->SetWidth((int)attValue);
	}
	else if (attName == "height")
	{
		this->SetHeight((int)attValue);
	}
	else if (attName == "fill")
	{
		this->SetFill(attValue);
	}
}

String Rectangle::ToString() const
{
	String result;
	result.Append(this->GetType());
	result.Append(" ");
	result.Append(this->x);
	result.Append(" ");
	result.Append(this->y);
	result.Append(" ");
	result.Append(this->width);
	result.Append(" ");
	result.Append(this->height);
	result.Append(" ");
	result.AppendLine(this->fill);
	return result;
}

//Left top corner
Point Rectangle::TopPoint()const
{
	return Point(x,y+height);
}
//Right bottom corner
Point Rectangle::BottomPoint()const
{
	return Point(x+width,y);
}
//Left bottom corner
Point Rectangle::LeftMostPoint()const
{
	return Point(x,y);
}
//Right top corner
Point Rectangle::RightMostPoint() const
{
	return Point(x+width,y+height);
}
