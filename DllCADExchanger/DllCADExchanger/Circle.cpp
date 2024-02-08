#include "pch.h"
#include "Circle.h"


void Circle::Calculate() {
	this->x = r * cos(t * PI / 180.0);
	this->y = r * sin(t * PI / 180.0);
	this->derivative = -cos(t * PI / 180.0) / sin(t * PI / 180.0);
	this->Info = { x, y, z, derivative };
}

Circle::Circle() {
	this->r = 0;
	this->t = 0;
	this->x = 0;
	this->y = 0;
	this->derivative = 0;
}
Circle::Circle(double r) {
	this->r = r;
	this->t = 0;
	this->x = 0;
	this->y = 0;
	this->derivative = 0;
	this->typeName = "Circle";
}
vector <double> Circle::GetInfo() {
	Calculate();
	return Info;
}

string Circle::GetTypeName() {
	return typeName;
}

double Circle::GetRadius() const {
	return r;
}
void Circle::SetT(double t) {
	this->t = t / PI * 180;
}