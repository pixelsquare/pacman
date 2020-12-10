#include "Math.h"
using namespace Math::Library;

Mathf::Mathf() { }

Mathf::~Mathf() { }

float Mathf::Abs(float f) { return abs(f); }

float Mathf::Acos(float f) { return acos(f); }

bool Mathf::Approximately(float a, float b) { 
	if(a == b) return true;
	else return false;
}

float Mathf::Asin(float f) { return asin(f); }

float Mathf::Atan(float f) { return atan(f); }

float Mathf::Atan2(float a, float b) { return atan2(a, b); }

float Mathf::Exp(float f) { return exp(f); }

float Mathf::Cos(float f) { return cos(f); }

float Mathf::Sin(float f) { return sin(f); }

float Mathf::Tan(float f) { return tan(f); }

float Mathf::Min(float a, float b) {
	if(a < b)
		return a;
	return b;
}

float Mathf::Max(float a, float b) {
	if(a > b)
		return a;
	return b;
}

float Mathf::Log(float f) { return log(f); }

float Mathf::Sqrt(float f) { return sqrt(f); }

float Mathf::Pow(float f, float p) { return pow(f, p); }

double Mathf::Ceil(double f) { return ceil(f); }

double Mathf::Floor(double f) { return floor(f); }


float Mathf::PI = 3.14159265358979;
float Mathf::DegToRad = Mathf::PI / 180.0f;
float Mathf::RadToDeg = 180.0f / Mathf::PI;
