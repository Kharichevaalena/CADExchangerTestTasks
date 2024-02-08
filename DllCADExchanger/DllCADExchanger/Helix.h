#pragma once

#include "Circle.h"

class DECLSPEC Helix :
	public Circle {
protected:
	double step, z;

	void Calculate() override;


public:
	Helix(double r, double step);
};