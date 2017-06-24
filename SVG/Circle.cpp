#include "Circle.h"

Circle::Circle(int cx, int cy, int r)
{
	this->SetCx(cx);
	this->SetCy(cy);
	this->SetR(r);
}

void Circle::SetCx(int cx)
{
	this->cx = cx;
}
void Circle::SetCy(int cy)
{
	this->cy = cy;
}
void Circle::SetR(int r)
{
	if (r < 0)
	{
		r = 0;
	}
	this->r = r;
}
void Circle::SetFill(String fill)
{
	this->fill = fill;
}
void Circle::Serialize(std::ostream& os) const
{
	this->StartSerialize(os);
	this->SerializeAttribute(os, "cx", this->cx);
	this->SerializeAttribute(os, "cy", this->cy);
	this->SerializeAttribute(os, "r", this->r);
	this->SerializeAttribute(os, "fill", this->fill);
	this->EndSerialize(os);
}
void Circle::Translate(int dx, int dy)
{
	this->SetCx(this->cx + cx);
	this->SetCy(this->cy + cy);
}
void Circle::DeserializeHelper(String attName, String attValue)
{
	if (attName == "cx")
	{
		this->SetCx((int)attValue);
	}
	else if (attName== "cy")
	{
		this->SetCy((int)attValue);
	}
	else if (attName == "r")
	{
		this->SetR((int)attValue);
	}
	else if (attName=="fill")
	{
		this->SetFill(attValue);
	}
}
String Circle::GetType() const
{
	return "circle";
}
String Circle::ToString() const
{
	String result;
	result.Append(this->GetType());
	result.Append(" ");
	result.Append(this->cx);
	result.Append(" ");
	result.Append(this->cy);
	result.Append(" ");
	result.Append(this->r);
	result.Append(" ");
	result.AppendLine(this->fill);
	return result;
}

int Circle::GetCx() const
{
	return this->cx;
}
int Circle::GetCy() const
{
	return this->cy;
}
int Circle::GetR() const
{
	return this->r;
}

Point Circle::TopPoint()const
{
	return Point(cx, cy + r);
}

Point Circle::BottomPoint()const
{
	return Point(cx, cy - r);
}

Point Circle::LeftMostPoint()const
{
	return Point(cx - r, cy);
}

Point Circle::RightMostPoint() const
{
	return Point(cx + r, cy);
}
