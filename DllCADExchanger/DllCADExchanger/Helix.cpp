#include "pch.h"
#include "Helix.h"

void Helix::Calculate() {
	this->x = r * cos(t * PI / 180.0);
	this->y = r * sin(t * PI / 180.0);
	this->z = step * (t * PI / 180.0);
	this->derivative = -(step * (sin(t * PI / 180.0) + cos(t * PI / 180.0))) / (r * sin(t * PI / 180.0) * cos(t * PI / 180.0));
	this->Info = { x, y, z, derivative };
}

Helix::Helix(double r, double step) {
	this->r = r;
	this->step = step;
	this->z = 0;
	this->typeName = "Helix ";
}