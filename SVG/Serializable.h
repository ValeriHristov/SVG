#pragma once
#include <iostream>
#include "String.h"
class Serializable
{
public:
	virtual void Serialize(std::ostream& os) const = 0;
	virtual void Deserialize(std::istream& is) = 0;
	virtual String GetType() const = 0;
};
