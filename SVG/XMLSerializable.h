#pragma once
#include "Serializable.h"
class XMLSerializable : public Serializable
{
public:
	void StartSerialize(std::ostream& os)const;
	void EndSerialize(std::ostream& os)const;
	void SerializeAttribute(std::ostream& os, String attName, String attValue) const;
};
