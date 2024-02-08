#include "pch.h"
#include "Ellips.h"

void Ellips::Calculate() {
	this->x = r1 * cos(t * PI / 180.0);
	this->y = r2 * sin(t * PI / 180.0);
	this->derivative = -r2 * cos(t * PI / 180.0) / r1 * sin(t * PI / 180.0);
	this->Info = { x, y, z, derivative };
}
Ellips::Ellips(double r1, double r2) {
	this->r1 = r1;
	this->r2 = r2;
	this->x = 0;
	this->y = 0;
	this->derivative = 0;
	this->typeName = "Ellips";
}