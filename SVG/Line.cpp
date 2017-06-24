#include "Line.h"

Line::Line(int x1, int y1, int x2, int y2)
{
	this->SetX1(x1);
	this->SetY1(y1);
	this->SetX2(x2);
	this->SetY2(y2);
}

void Line::Serialize(std::ostream& os) const
{
	this->StartSerialize(os);
	this->SerializeAttribute(os, "x1", this->x1);
	this->SerializeAttribute(os, "y1", this->y1);
	this->SerializeAttribute(os, "x2", this->x2);
	this->SerializeAttribute(os, "y2", this->y2);
	this->SerializeAttribute(os, "stroke-width", this->strokeWidth);
	this->EndSerialize(os);
}
void Line::Translate(int dx, int dy)
{
	this->SetX1(this->x1 + dx);
	this->SetX2(this->x2 + dx);
	this->SetY1(this->y1 + dy);
	this->SetY2(this->y2 + dy);
}
void Line::DeserializeHelper(String attName, String attValue)
{
	if (attName== "x1")
	{
		this->SetX1((int)attValue);
	}
	else if (attName=="x2")
	{
		this->SetX2((int)attValue);
	}
	else if (attName == "y1")
	{
		this->SetY1((int)attValue);
	}
	else if (attName == "y2")
	{
		this->SetY2((int)attValue);
	}
	else if (attName=="stroke-width")
	{
		this->SetStrokeWidth((int)attValue);
	}
}
String Line::GetType() const
{
	return "line";
}
void Line::SetX1(int x1)
{
	this->x1 = x1;
}
void Line::SetX2(int x2)
{
	this->x2 = x2;
}
void Line::SetY1(int y1)
{
	this->y1 = y1;
}
void Line::SetY2(int y2)
{
	this->y2 = y2;
}
void Line::SetStrokeWidth(int value)
{
	if (value<0)
	{
		value = 0;
	}
	this->strokeWidth = value;
}
String Line::ToString() const
{
	String result;
	result.Append(this->GetType());
	result.Append(" ");
	result.Append(this->x1);
	result.Append(" ");
	result.Append(this->y1);
	result.Append(" ");
	result.Append(this->x2);
	result.Append(" ");
	result.Append(this->y2);
	result.Append(" ");
	result.AppendLine(this->strokeWidth);
	return result;
}

Point Line::TopPoint()const
{
	return Point(x2, y2);
}
	  
Point Line::BottomPoint()const
{
	return Point(x1,y1);
}
	  
Point Line::LeftMostPoint()const
{
	return Point(x1,y1);
}
	  
Point Line::RightMostPoint() const
{
	return Point(x2,y2);
}
