#include "ShapeFactory.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"
Shape* ShapeFactory::CreateShape(String type) const
{
	if (type == "rect")
	{
		return new Rectangle();
	}
	else if (type == "circle")
	{
		return new Circle();
	}
	else if (type == "line")
	{
		return new Line();
	}
	return nullptr;
}