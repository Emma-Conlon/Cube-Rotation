#include "Vector3.h"


Vector3::Vector3()//1st constructor
{
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
}

Vector3::Vector3(float x1, float y1, float z1)//2nd constrctor
{
	this->x = x1;
	this->y = y1;
	this->z = z1;
}

/// <summary>
/// gets the lengh of a vector 
/// </summary>
/// <returns></returns>
float Vector3::length()
{
	return static_cast<double>(sqrt(this->x * this->x + this->y * this->y + this->z * this->z));
}

float Vector3::lengthSquared()
{
	return (this->x * this->x + this->y * this->y + this->z * this->z);
}

void Vector3::normalise()
{
	if (this->length() > 0.0)
	{
		double magnit = this->length();
		this->x /= magnit;
		this->y /= magnit;
		this->z /= magnit;
	}

}


void Vector3::setX(double value)
{
	x = value;
}

float Vector3::getX()
{
	return x;
}



void Vector3::setY(double value)
{
	y = value;
}

float Vector3::getY()
{
	return y;
}


void Vector3::setZ(double value)
{
	z = value;
}

float Vector3::getZ()
{
	return z;
}

Vector3 Vector3::operator+(Vector3 V1)
{
	return { V1.x + x,V1.y + y,V1.z + z };
}

Vector3 Vector3::operator-(Vector3 V1)
{
	return{V1.x - x, V1.y - y, V1.z - z};
}

Vector3 Vector3::operator-()
{
	
	return {-x,-y,-z};
}

double Vector3::operator*(Vector3 V1)
{
	
	return { V1.x * x + V1.y * y + V1.z * z };
}

Vector3 Vector3::operator*(double k)
{
	
	return  { x * (float)k, y * (float)k, z * (float)k };
}

Vector3 Vector3::operator*(float k)
{

	return  { x * k, y * k, z * k };
}


Vector3 Vector3::operator^(Vector3 V1)
{

	return { V1.y * z - V1.z * y, V1.z * x - V1.x * z, V1.x * y - V1.y * x };
}


std::string Vector3::toString()
{
	return "{ " + std::to_string(x) + "f, " + std::to_string(y) + "f, " + std::to_string(z) + "f }";
}

