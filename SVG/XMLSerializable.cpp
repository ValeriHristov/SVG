#include "XMLSerializable.h"

void XMLSerializable::StartSerialize(std::ostream& os) const
{
	os << "<";
	os << this->GetType();
	os << " ";
}

void XMLSerializable::EndSerialize(std::ostream& os) const
{
	os << "/>\n";
}

void XMLSerializable::SerializeAttribute(std::ostream& os, String attName, String attValue) const
{
	os << attName;
	os << "=\"";
	os << attValue;
	os << "\" ";
}