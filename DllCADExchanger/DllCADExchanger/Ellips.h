#pragma once

#include "Circle.h"

class DECLSPEC Ellips :
	public Circle
{
protected:
	double r1, r2;

	void Calculate() override;
public:
	Ellips(double r1, double r2);
};
