#pragma once
#ifdef DllCADExchanger_Lib
#define DECLSPEC __declspec(dllexport)
#else
#define DECLSPEC __declspec(dllimport)
#endif

#include <vector>
#include <string>

#define PI 3.14159265
using namespace std;

class DECLSPEC Circle {
protected:
	string typeName;
	double r, t, derivative, x, y, z = 0;
	vector <double> Info;

	virtual void Calculate();

	virtual ~Circle() {}

public:
	Circle();
	Circle(double r);
	vector <double> GetInfo();

	string GetTypeName();

	double GetRadius() const;
	void SetT(double t) ;

};
