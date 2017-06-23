#include "Rectangle.h"

Rectangle::Rectangle() : x(0), y(0), width(0), height(0), rx(0), ry(0){}

Rectangle::Rectangle(int width, int height, int x, int y, int rx, int ry)
	: x(x), y(y)
{
	this->SetWidth(width);
	this->SetHeight(height);
	this->SetRx(rx);
	this->SetRy(ry);
}

void Rectangle::SetX(int x)
{
	this->x = x;
}
void Rectangle::SetY(int y)
{
	this->y = y;
}
void Rectangle::SetRx(int rx)
{
	if (rx < 0)
	{
		rx = 0;
	}
	this->rx = rx;
}
void Rectangle::SetRy(int ry)
{
	if (ry < 0)
	{
		ry = 0;
	}
	this->ry = ry;
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
void Rectangle::SetFill(const String& fill)
{
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
	this->SerializeAttribute(os, "rx", rx);
	this->SerializeAttribute(os, "ry", ry);
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
	else if(attName == "y")
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
	else if (attName == "rx")
	{
		this->SetRx((int)attValue);
	}
	else if (attName == "ry")
	{
		this->SetRy((int)attValue);
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
	result.Append(this->rx);
	result.Append(" ");
	result.Append(this->ry);
	result.Append(" ");
	result.AppendLine(this->fill);
	return result;

}