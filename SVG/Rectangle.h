#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
private:
	int x;
	int y;
	int width;
	int height;
	int rx;
	int ry;
	String fill;
protected:
	void DeserializeHelper(String attName, String attValue) override;
public:
	Rectangle();
	Rectangle(int width, int height, int x = 0, int y = 0, int rx = 0, int ry = 0);

	void Translate(int dx, int dy);
	void Serialize(std::ostream& os)const override;
	String ToString() const override;
	String GetType() const;
	int GetX()const;
	int GetY()const;
	int GetRx() const;
	int GetRy() const;
	void SetX(int x);
	void SetY(int y);
	void SetRx(int rx);
	void SetRy(int ry);
	void SetWidth(int width);
	void SetHeight(int height);
	void SetFill(const String& fill);
};