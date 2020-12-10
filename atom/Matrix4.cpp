#include "Matrix4.h"
using namespace Matrix4Lib::Library;

Matrix4::Matrix4() 
{  
	for(int i = 0; i < 16; i++)
		this->m_elements[i] = 0.0f;
}

Matrix4::~Matrix4() {
	for(int i = 0; i < 16; i++)
		this->m_elements[i] = 0.0f;
}

Matrix4 &Matrix4::operator=(Matrix4 &rhs)
{
	if(this == &rhs) return *this;

	for(int j = 1; j <= 4; j++)
	{
		for(int i = 1; i <= 4; i++)
			this->Element(i, j) = rhs.Element(i,j);
	}

	return *this;
}

Vector3 Matrix4::operator*(const Vector3 &vector)
{
	Vector3 Result;

	Result.X = this->Element(1, 1) * vector.X + 
				this->Element(1, 2) * vector.Y + 
				this->Element(1, 3) * vector.Z;
	Result.Y = this->Element(2, 1) * vector.X + 
				this->Element(2, 2) * vector.Y + 
				this->Element(2, 3) * vector.Z;
	Result.Z = this->Element(3, 1) * vector.X + 
				this->Element(3, 2) * vector.Y + 
				this->Element(3, 3) * vector.Z;

	return Result;
}

float &Matrix4::Element(int i, int j)
{
	int Result = ((i - 1) * 4) + (j - 1);
	return this->m_elements[Result];
}

Matrix4 Matrix4::operator*(Matrix4 &matrix)
{
	Matrix4 Result;

	for(int j = 1; j <= 4; j++) // Column
	{
		for(int i = 1; i <= 4; i++) // Row
		{
			float tmp = 0.0;

			for(int k = 1; k <= 4; k++)
				tmp += this->Element(k, j) * matrix.Element(i, k);

			Result.Element(i, j) = tmp;
		}
	}

	return Result;
}

Matrix4 Matrix4::CreateRotationX(float angleDeg)
{
	Matrix4 Rot;
	Rot.Element(1, 1) = 1.0;
	Rot.Element(4, 4) = 1.0;

	float angle = angleDeg * (3.14159 / 180);
	Rot.Element(2, 2) = cos(angle);
	Rot.Element(3, 3) = cos(angle);
	Rot.Element(2, 3) = -sin(angle);
	Rot.Element(3, 2) = sin(angle);

	return Rot;
}

Matrix4 Matrix4::CreateRotationY(float angleDeg)
{
	Matrix4 Rot;
	Rot.Element(2, 2) = 1.0;
	Rot.Element(4, 4) = 1.0;

	float angle = angleDeg * (3.14159 / 180);
	Rot.Element(1, 1) = cos(angle);
	Rot.Element(3, 1) = sin(angle);
	Rot.Element(1, 3) = -sin(angle);
	Rot.Element(3, 3) = cos(angle);

	return Rot;
}

Matrix4 Matrix4::CreateRotationZ(float angleDeg)
{
	Matrix4 Rot;
	Rot.Element(3, 3) = 1.0;
	Rot.Element(4, 4) = 1.0;

	float angle = angleDeg * (3.14159 / 180);
	Rot.Element(1, 1) = cos(angle);
	Rot.Element(2, 2) = cos(angle);
	Rot.Element(1, 2) = -sin(angle);
	Rot.Element(2, 1) = sin(angle);

	return Rot;
}

Matrix4 Matrix4::CreateScaling(float x, float y, float z)
{
	Matrix4 Scale;
	Scale.Element(4, 4) = 1.0;
	Scale.Element(1, 1) = x;
	Scale.Element(2, 2) = y;
	Scale.Element(3, 3) = z;

	return Scale;
}

Matrix4 Matrix4::CreateTranslation(float x, float y, float z)
{
	Matrix4 Translate;
	Translate.Element(1, 1) = 1.0;
	Translate.Element(2, 2) = 1.0;
	Translate.Element(3, 3) = 1.0;
	Translate.Element(4, 4) = 1.0;

	Translate.Element(1, 4) = x;
	Translate.Element(2, 4) = y;
	Translate.Element(3, 4) = z;

	return Translate;
}

void Matrix4::Print()
{
	printf("\n---------------------------------------------------------\n\n");
	printf("\t%0.6f   %0.6f   %0.6f   %0.6f\n", this->m_elements[0], this->m_elements[1], this->m_elements[2], this->m_elements[3]);
	printf("\t%0.6f   %0.6f   %0.6f   %0.6f\n", this->m_elements[4], this->m_elements[5], this->m_elements[6], this->m_elements[7]);
	printf("\t%0.6f   %0.6f   %0.6f   %0.6f\n", this->m_elements[8], this->m_elements[9], this->m_elements[10], this->m_elements[11]);
	printf("\t%0.6f   %0.6f   %0.6f   %0.6f\n", this->m_elements[12], this->m_elements[13], this->m_elements[14], this->m_elements[15]);
	printf("\n---------------------------------------------------------\n\n");
}