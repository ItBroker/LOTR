#pragma once
using namespace std;
#include <iostream>

struct  Vector2D
{
	float x, y;

	Vector2D() 
	{
		x = 0;
		y = 0;
	}
	Vector2D(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	Vector2D& Add(const Vector2D& vec)
	{
		this->x += vec.x;
		this->y += vec.y;
		return *this;
	}
	Vector2D& Subtract(const Vector2D & vec)
	{
		this->x -= vec.x;
		this->y -= vec.y;
		return *this;
	}
	Vector2D & Multiply(const Vector2D & vec)
	{
		this->x *= vec.x;
		this->y *= vec.y;
		return *this;
	}
	Vector2D & Divide(const Vector2D & vec)
	{
		this->x /= vec.x;
		this->y /= vec.y;
		return *this;
	}



	inline friend Vector2D  operator+(Vector2D & v1, const Vector2D & v2)
	{
		return v1.Add(v2);
	}
	inline friend Vector2D  operator-(Vector2D & v1, const Vector2D & v2)
	{
		return v1.Subtract(v2);
	}
	inline friend Vector2D  operator*(Vector2D & v1, const Vector2D & v2)
	{
		return v1.Multiply(v2);
	}
	inline friend Vector2D  operator/(Vector2D & v1, const Vector2D & v2)
	{
		return v1.Divide(v2);
	}



	inline  Vector2D & operator+=(const Vector2D & vec)
	{
		return this->Add(vec);
	}
	inline  Vector2D & operator-=(const Vector2D & vec)
	{
		return this->Subtract(vec);
	}
	inline  Vector2D & operator*=(const Vector2D & vec)
	{
		return this->Multiply(vec);
	}
	 inline Vector2D & operator/=(const Vector2D & vec)
	{
		return this->Divide(vec);
	}
	inline Vector2D&zero()
	{
		this->x = 0;
		this->y = 0;
		return *this;
	}
	inline Vector2D & ones()
	{
		this->x = 1;
		this->y = 1;
		return *this;
	}
	inline friend ostream& operator<<(ostream& stream, const Vector2D & vec)
	{
		stream << "(" << vec.x << "," << vec.y << ")" << endl;
		return stream;
	}
};
