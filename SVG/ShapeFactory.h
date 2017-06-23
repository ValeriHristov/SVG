#pragma once
#include "Shape.h"

class ShapeFactory
{
public:
	Shape* CreateShape(String type) const;
};