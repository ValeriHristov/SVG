#pragma once
#include "Shape.h"

class Line : public Shape
{
private:
	int x1;
	int x2;
	int y1;
	int y2;
	int strokeWidth;
	void DeserializeHelper(String attName, String attValue) override;
public:
	Line(int x1=0, int y1=0, int x2=0, int y2=0);
	void Serialize(std::ostream& os) const override;
	void Translate(int dx, int dy) override;
	String ToString() const override;
	String GetType() const override;
	void SetX1(int);
	void SetX2(int);
	void SetY1(int);
	void SetY2(int);
	void SetStrokeWidth(int);
};