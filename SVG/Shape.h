#pragma once
#include "XMLSerializable.h"

class Shape : public XMLSerializable
{
protected:
	virtual void DeserializeHelper(String attName, String attValue) = 0;
public:
	virtual void Deserialize(std::istream& is);
	virtual void Translate(int dx, int dy) = 0;
	virtual String ToString() const = 0;
};