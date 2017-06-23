#pragma once
#include "Shape.h"
class Circle : public Shape
{
private:
	int cx;
	int cy;
	int r;
	String fill;
	void  DeserializeHelper(String attName, String attValue) override;
public:
	Circle(int cx = 0, int cy = 0, int r = 0);
	void Serialize(std::ostream& os) const override;
	void Translate(int dx, int dy) override;
	String ToString() const override;
	String GetType() const override;
	void SetCx(int cx);
	void SetCy(int cy);
	void SetR(int r);
	void SetFill(String fill);

};
