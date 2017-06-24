#pragma once
#include "XMLSerializable.h"

struct Point
{
	int x;
	int y;
	Point(int x = 0, int y = 0)
	{
		this->x = x;
		this->y = y;
	}
	bool operator>=(const Point& other)
	{
		return (this->x >= other.x) && (this->y >= other.y);
	}
	bool operator<=(const Point& other)
	{
		return (this->x <= other.x) && (this->y <= other.y);
	}
	double GetDistanceTo(const Point& other)
	{
		int dx = this->x - other.x;
		int dy = this->y - other.y;
		return sqrt(dx*dx + dy*dy);
	}
};

class Shape : public XMLSerializable
{
protected:
	virtual void DeserializeHelper(String attName, String attValue) = 0;
public:
	virtual void Deserialize(std::istream& is);
	virtual void Translate(int dx, int dy) = 0;
	virtual String ToString() const = 0;
	virtual Point TopPoint() const = 0;
	virtual Point BottomPoint() const = 0;
	virtual Point LeftMostPoint() const = 0;
	virtual Point RightMostPoint() const = 0;
};
