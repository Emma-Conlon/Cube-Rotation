#include"Matrix3.h"

Matrix3::Matrix3()
{
	this->A11 = 0.0f;
	this->A12 = 0.0f;
	this->A13 = 0.0f;
	this->A21 = 0.0f;
	this->A22 = 0.0f;
	this->A23 = 0.0f;
	this->A31 = 0.0f;
	this->A32 = 0.0f;
	this->A33 = 0.0f;
}
//2nd constructor
Matrix3::Matrix3(Vector3 Row1, Vector3 Row2, Vector3 Row3)
{
	this->A11 = Row1.getX();
	this->A12 = Row1.getY();
	this->A13 = Row1.getZ();
	this->A21 = Row2.getX();
	this->A22 = Row2.getY();
	this->A23 = Row2.getZ();
	this->A31 = Row3.getX();
	this->A32 = Row3.getY();
	this->A33 = Row3.getZ();
}

/// <summary>
/// 3rd constructor
/// </summary>
Matrix3::Matrix3(float _A11, float _A12, float _A13,
	float _A21, float _A22, float _A23,
	float _A31, float _A32, float _A33)
{
	A11 = _A11;
	A12 = _A12;
	A13 = _A13;
	A21 = _A21;
	A22 = _A22;
	A23 = _A23;
	A31 = _A31;
	A32 = _A32;
	A33 = _A33;
}

Vector3 Matrix3::operator*(Vector3 V1)
{
	
	return { A11 * V1.getX() + A12 * V1.getY() + A13 * V1.getZ(),
		A21 * V1.getX() + A22 * V1.getY() + A23 * V1.getZ(),
		A31 * V1.getX() + A32 * V1.getY() + A33 * V1.getZ() };
}

Matrix3 Matrix3::Transpose(Matrix3 M1)
{
	return Matrix3(M1.A11, M1.A21, M1.A31,
		M1.A12, M1.A22, M1.A32,
		M1.A13, M1.A23, M1.A33);
}

Matrix3 Matrix3::operator+(Matrix3 M1)
{
	
	return Matrix3(M1.A11 + A11, M1.A12 + A12, M1.A13 + A13,
		M1.A21 + A21, M1.A22 + A22, M1.A23 + A23,
		M1.A31 + A31, M1.A32 + A32, M1.A33 + A33);
}

Matrix3 Matrix3::operator-(Matrix3 M1)
{
	
	return Matrix3(M1.A11 - A11, M1.A12 - A12, M1.A13 - A13,
		M1.A21 - A21, M1.A22 - A22, M1.A23 - A23,
		M1.A31 - A31, M1.A32 - A32, M1.A33 - A33);
}

Matrix3 Matrix3::operator*(double x)
{
	
	Matrix3 answer = Matrix3();
	answer.A11 = A11 * x;
	answer.A12 = A12 * x;
	answer.A13 = A13 * x;

	answer.A21 = A21 * x;
	answer.A22 = A22 * x;
	answer.A23 = A23 * x;

	answer.A31 = A31 * x;
	answer.A32 = A32 * x;
	answer.A33 = A33 * x; 

	return answer;
}

Matrix3 Matrix3::operator*(Matrix3 M1)
{
	
	Matrix3 answer =  Matrix3();
	answer.A11 = M1.Row(0) * Column(0);
	answer.A12 = M1.Row(0) * Column(1);
	answer.A13 = M1.Row(0) * Column(2);
	answer.A21 = M1.Row(1) * Column(0);
	answer.A22 = M1.Row(1) * Column(1);
	answer.A23 = M1.Row(1) * Column(2);
	answer.A31 = M1.Row(2) * Column(0);
	answer.A32 = M1.Row(2) * Column(1);
	answer.A33 = M1.Row(2) * Column(2);
	
	return answer;
}

double Matrix3::Determinant(Matrix3 M1)
{
	return  M1.A11 * M1.A22 * M1.A33 - M1.A11 * M1.A32 * M1.A23 + M1.A21 * M1.A32 * M1.A13 - M1.A31 * M1.A22 * M1.A13 + M1.A31 * M1.A12 * M1.A23 - M1.A21 * M1.A12 * M1.A33;
}

Vector3 Matrix3::Row(int i)
{
	switch (i)
	{
	case 0:
		return  { A11, A12, A13 };
	case 1:
		return  { A21, A22, A23 };
	case 2:
	default:
		return  { A31, A32, A33 };
	}
}

Vector3 Matrix3::Column(int i)
{
	switch (i)
	{
	case 0:
		return  { A11, A21, A31 };
	case 1:
		return  { A12, A22, A32 };
	case 2:
	default:
		return  { A13, A23, A33 };
	}
}

Matrix3 Matrix3::Inverse(Matrix3 M1)
{
	double det = Determinant(M1);
	if (det == 0)
		return  Matrix3();
	else
	{
		double scale = 1 / det;
		Matrix3 answer =  Matrix3();
		answer.A11 = scale * (M1.A22 * M1.A33 - M1.A23 * M1.A32); // ei-fh
		answer.A12 = scale * (M1.A13 * M1.A32 - M1.A12 * M1.A33); // ch-bi
		answer.A13 = scale * (M1.A12 * M1.A23 - M1.A13 * M1.A22); // ch-bi

		answer.A21 = scale * (M1.A23 * M1.A31 - M1.A21 * M1.A33); // fg-di
		answer.A22 = scale * (M1.A11 * M1.A33 - M1.A13 * M1.A31); // ai-cg
		answer.A23 = scale * (M1.A13 * M1.A21 - M1.A11 * M1.A23); // cd-af


		answer.A31 = scale * (M1.A21 * M1.A32 - M1.A22 * M1.A31); // dh-eg
		answer.A32 = scale * (M1.A12 * M1.A31 - M1.A11 * M1.A32); // bg-ah
		answer.A33 = scale * (M1.A11 * M1.A22 - M1.A12 * M1.A21); // ae-bd

		return answer;
	}

}

Matrix3 Matrix3::Rotation(int _angle)
{
	double PI{ 3.141 };
	double radians = PI / 180 * _angle;
	Matrix3 answer =  Matrix3();
	answer.A11 = cos(radians);
	answer.A12 = sin(radians);
	answer.A13 = 0;
	answer.A21 = -sin(radians);
	answer.A22 = cos(radians);
	answer.A23 = 0;
	answer.A31 = 0;
	answer.A32 = 0;
	answer.A33 = 1;

	return answer;
}

Matrix3 Matrix3::Translate(int dx, int dy)
{
	Matrix3 answer = Matrix3();
	answer.A11 = 1;
	answer.A12 = 0;
	answer.A13 = 0;
	answer.A21 = 0;
	answer.A22 = 1;
	answer.A23 = 0;
	answer.A31 = dx;
	answer.A32 = dy;
	answer.A33 = 1;

	return answer;
}

Matrix3 Matrix3::Scale(int dx, int dy)
{
	Matrix3 answer =  Matrix3();
	answer.A11 = (double)dx / 100;
	answer.A12 = 0;
	answer.A13 = 0;
	answer.A21 = 0;
	answer.A22 = (double)dy / 100;
	answer.A23 = 0;
	answer.A31 = 0;
	answer.A32 = 0;
	answer.A33 = 1;

	return answer;
}

Matrix3 Matrix3::operator-()
{

	return Matrix3{*this * -1};
}

Matrix3 Matrix3::RotationX(int _angle)
{
	double PI{ 3.141 };
	double radians = PI / 180 * _angle;
	Matrix3 answer = Matrix3();
	answer.A11 = 1;
	answer.A12 = 0;
	answer.A13 = 0;
	answer.A21 = 0;
	answer.A22 =cos(radians);
	answer.A23 =-sin(radians);
	answer.A31 = 0;
	answer.A32 =sin(radians);
	answer.A33 = cos(radians);

	return answer;
}

Matrix3 Matrix3::RotationY(int _angle)
{
	double PI{ 3.141 };
	double radians = PI / 180 * _angle;
	Matrix3 answer = Matrix3();
	answer.A11 = cos(radians);
	answer.A12 = 0;
	answer.A13 = sin(radians);
	answer.A21 = 0;
	answer.A22 = 1;
	answer.A23 = 0;
	answer.A31 = -sin(radians);
	answer.A32 = 0;
	answer.A33 = cos(radians);

	return answer;
}

Matrix3 Matrix3::RotationZ(int _angle)
{
	double PI{ 3.141 };
	double radians = PI / 180 * _angle;
	Matrix3 answer =  Matrix3();
	answer.A11 = cos(radians);
	answer.A12 = -sin(radians);
	answer.A13 = 0;
	answer.A21 = sin(radians);
	answer.A22 = cos(radians);
	answer.A23 = 0;
	answer.A31 = 0;
	answer.A32 = 0;
	answer.A33 = 1;

	return answer;
}

Matrix3 Matrix3::Scale3D(int dx)
{
	Matrix3 answer =  Matrix3();
	answer.A11 = (double)dx / 100;
	answer.A12 = 0;
	answer.A13 = 0;
	answer.A21 = 0;
	answer.A22 = (double)dx / 100;
	answer.A23 = 0;
	answer.A31 = 0;
	answer.A32 = 0;
	answer.A33 = (double)dx / 100;

	return answer;
}

std::string Matrix3::ToString()
{
	return "{ " + std::to_string(A11) + "f, " + std::to_string(A12) + "f, " + std::to_string(A13) + "f,\n"+
		 "  "+std::to_string(A21) + "f, " + std::to_string(A22) + "f, " + std::to_string(A23) + "f,\n"+
		 "  "+std::to_string(A31) + "f, " + std::to_string(A32) + "f, " + std::to_string(A33) + "f }";
}
