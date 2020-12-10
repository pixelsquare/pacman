#include "Vector3.h"

using namespace Vector3Lib::Library;

Vector3::Vector3()
{
	this->X = 0.0f;
	this->Y = 0.0f;
	this->Z = 0.0f;

	this->Zero = Vector3(0.0f, 0.0f, 0.0f);			this->Forward = Vector3(0.0f, 0.0f, 1.0f);
	this->One = Vector3(1.0f, 1.0f, 1.0f);			this->Back = Vector3(0.0f, 0.0f, -1.0f);
	this->Up = Vector3(0.0f, 1.0f, 0.0f);			this->Left = Vector3(-1.0f, 0.0f, 0.0f);
	this->Down = Vector3(0.0f, -1.0f, 0.0f);		this->Right = Vector3(1.0f, 0.0f, 0.0f);

	this->MoveUp += Vector3(0.0f, 1.0f, 0.0f);		this->MoveDown += Vector3(0.0f, -1.0f, 0.0f);
	this->MoveLeft += Vector3(-1.0f, 0.0f, 0.0f);	this->MoveRight += Vector3(1.0f, 0.0f, 0.0f);
	this->MoveForward += Vector3(0.0f, 0.0f, 1.0f); this->MoveBack += Vector3(0.0f, 0.0f, -1.0f);

	this->tmpTime = 0;
}

Vector3::Vector3(float x, float y, float z)
{
	this->X = x;
	this->Y = y;
	this->Z = z;
}

Vector3::~Vector3() { 
	this->X = 0.0f;
	this->Y = 0.0f;
	this->Z = 0.0f;
	this->tmpTime = 0.0f;
}

Vector3 &Vector3::operator=(const Vector3 &rhs)
{
	this->X = rhs.X;
	this->Y = rhs.Y;
	this->Z = rhs.Z;

	return *this;
}

Vector3 &Vector3::operator+=(const Vector3 &rhs)
{
	this->X += rhs.X;
	this->Y += rhs.Y;
	this->Z += rhs.Z;

	return *this;
}

Vector3 Vector3::operator+(const Vector3 &op)
{
	Vector3 rhs;
	rhs.X = this->X + op.X;
	rhs.Y = this->Y + op.Y;
	rhs.Z = this->Z + op.Z;

	return rhs;
}

Vector3 &Vector3::operator-=(const Vector3 &rhs)
{
	this->X -= rhs.X;
	this->Y -= rhs.Y;
	this->Z -= rhs.Z;

	return *this;
}

Vector3 Vector3::operator-(const Vector3 &op)
{
	Vector3 rhs;
	rhs.X = this->X - op.X;
	rhs.Y = this->Y - op.Y;
	rhs.Z = this->Z - op.Z;

	return rhs;
}

Vector3 &Vector3::operator*=(const float scalar)
{
	this->X *= scalar;
	this->Y *= scalar;
	this->Z *= scalar;

	return *this;
}

Vector3 Vector3::operator*(const float scalar)
{
	Vector3 rhs;
	rhs.X = this->X * scalar;
	rhs.Y = this->Y * scalar;
	rhs.Z = this->Z * scalar;

	return rhs;
}

Vector3 &Vector3::operator*=(const Vector3 &rhs)
{
	this->X *= rhs.X;
	this->Y *= rhs.Y;
	this->Z *= rhs.Z;

	return *this;
}

Vector3 Vector3::operator*(const Vector3 &op)
{
	Vector3 rhs;
	rhs.X = this->X * op.X;
	rhs.Y = this->Y * op.Y;
	rhs.Z = this->Z * op.Z;

	return rhs;
}



// Same as Magnitude
float Vector3::GetLength()
{
	float d = sqrt(this->X * this->X +
				this->Y * this->Y +
				this->Z * this->Z);

	return d;
}

void Vector3::Normalize()
{
	float length = this->GetLength();
	this->X /= length;
	this->Y /= length;
	this->Z /= length;

	return;
}

Vector3 Vector3::Normalized()
{
	Vector3 normalized(0.0f, 0.0f, 0.0f);
	normalized.X = this->X;
	normalized.Y = this->Y;
	normalized.Z = this->Z;
	float length = this->GetLength();
	normalized.X /= length;
	normalized.Y /= length;
	normalized.Z /= length;

	return normalized;
}

float Vector3::Dot(const Vector3 &other) {
	return this->X * other.X + this->Y * other.Y + this->Z * other.Z;
}

Vector3 Vector3::Cross(Vector3 &other) {
	return Vector3(this->Y * other.Z - this->Z * other.Y,
				   this->Z * other.X - this->X * other.Z,
				   this->X * other.Y - this->Y * other.X);
}

void Vector3::PrintLine()
{
	printf("X:%f, Y:%f, Z:%f\n", this->X, this->Y, this->Z);
	return;
}

float Vector3::Dot(Vector3 lhs, Vector3 rhs) {

	Vector3 tmpVec = Vector3(lhs.X * rhs.X, lhs.Y * rhs.Y, lhs.Z * rhs.Z);
	float result = tmpVec.X + tmpVec.Y + tmpVec.Z;

	return result;
}

Vector3 Vector3::Cross(Vector3 lhs, Vector3 rhs) {
	return Vector3(lhs.Y * rhs.Z - lhs.Z * rhs.Y,
				   lhs.Z * rhs.X - lhs.X * rhs.Z,
				   lhs.X * rhs.Y - lhs.Y * rhs.X);
}

float Vector3::AngleBetweenVectors(Vector3 lhs, Vector3 rhs) {
	float lhsMagnitude = lhs.GetLength();
	float rhsMagnitude = rhs.GetLength();
	int res = 2 * (lhsMagnitude + rhsMagnitude);
	float result = acos(res / (lhsMagnitude * rhsMagnitude));

	return result * Mathf::RadToDeg;
}

float Vector3::GetDistance(Vector3 pt1, Vector3 pt2) {
	float result = 0;
	float cSqr = (Mathf::Pow((pt2.X - pt1.X), 2) + Mathf::Pow((pt2.Y - pt1.Y), 2));

	result = Mathf::Sqrt(cSqr);
	return result;
}

Vector3 Vector3::SineWave(float amplitude, Vector3 direction) {
	Vector3 wave;
	this->tmpTime++;

	if(direction.X == 1.0f && direction.Y == 0.0f && direction.Z == 0.0f) {
		wave.X += (amplitude / 50) * Mathf::Sin(this->tmpTime++ * Mathf::DegToRad);
	}
	else if(direction.X == 0.0f && direction.Y == 1.0f && direction.Z == 0.0f) {
		wave.Y += (amplitude / 50) * Mathf::Sin(this->tmpTime++ * Mathf::DegToRad);
	}
	else if(direction.X == 0.0f && direction.Y == 0.0f && direction.Z == 1.0f) {
		wave.Z += (amplitude / 50) * Mathf::Sin(this->tmpTime++ * Mathf::DegToRad);
	}

	return wave;
}

Vector3 Vector3::Zero;			Vector3 Vector3::Forward;
Vector3 Vector3::One;			Vector3 Vector3::Back;
Vector3 Vector3::Up;			Vector3 Vector3::Left;
Vector3 Vector3::Down;			Vector3 Vector3::Right;

Vector3 Vector3::MoveUp;		Vector3 Vector3::MoveDown;
Vector3 Vector3::MoveLeft;		Vector3 Vector3::MoveRight;
Vector3 Vector3::MoveForward;	Vector3 Vector3::MoveBack;

//int tmpTime = 0;
//float Vector3::MoveSine(float amplitude) {
//	tmpTime += 1 % 360;
//	return amplitude * Mathf::Sin(tmpTime * Mathf::DegToRad);
//}
//
//float Vector3::MoveSine(int t, float amplitude) {
//	return amplitude * Mathf::Sin(t * Mathf::DegToRad);
//}