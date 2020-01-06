#pragma once
#include<iostream>
#include<math.h>
#include<vector>
#include<string>




class Vector3
{


public:
	float x;
	float y;
	float z;
	Vector3();
	Vector3(float x1, float y1, float z1);

	
	float length();
	float lengthSquared();
	void normalise();
	void setX(double value);
	float getX();
	void setY(double value);
	float getY();
	void setZ(double value);
	float getZ();
	 Vector3 operator +(Vector3 V1);
	 Vector3 operator -(Vector3 V1);
	 Vector3 operator -();
	 double operator *(Vector3 V1);
	 Vector3 operator *(double k);
	 Vector3 operator *(float k );
	 Vector3 operator ^(Vector3 V1);
	 
	 std::string toString();
};