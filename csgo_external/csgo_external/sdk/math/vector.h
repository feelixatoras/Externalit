#pragma once
#include "../sdk.h"
template <typename T>
T clip_number(const T& n, const T& lower, const T& upper)
{
	return max(lower, min(n, upper));
}
class vec3
{
public:
	vec3(void)
	{
		Invalidate();
	}
	vec3(float X, float Y, float Z)
	{
		x = X;
		y = Y;
		z = Z;
	}
	vec3(const float* clr)
	{
		x = clr[0];
		y = clr[1];
		z = clr[2];
	}

	void Init(float ix = 0.0f, float iy = 0.0f, float iz = 0.0f)
	{
		x = ix; y = iy; z = iz;
	}
	bool is_valid() const
	{
		return std::isfinite(x) && std::isfinite(y) && std::isfinite(z);
	}
	void Invalidate()
	{
		x = y = z = std::numeric_limits<float>::infinity();
	}

	float& operator[](int i)
	{
		return ((float*)this)[i];
	}
	float operator[](int i) const
	{
		return ((float*)this)[i];
	}

	bool is_zero()
	{
		return x = y = z = 0.0f;
	}

	bool operator==(const vec3& src) const
	{
		return (src.x == x) && (src.y == y) && (src.z == z);
	}
	bool operator!=(const vec3& src) const
	{
		return (src.x != x) || (src.y != y) || (src.z != z);
	}

	vec3& operator+=(const vec3& v)
	{
		x += v.x; y += v.y; z += v.z;
		return *this;
	}
	vec3& operator-=(const vec3& v)
	{
		x -= v.x; y -= v.y; z -= v.z;
		return *this;
	}
	vec3& operator*=(float fl)
	{
		x *= fl;
		y *= fl;
		z *= fl;
		return *this;
	}
	vec3& operator*=(const vec3& v)
	{
		x *= v.x;
		y *= v.y;
		z *= v.z;
		return *this;
	}
	vec3& operator/=(const vec3& v)
	{
		x /= v.x;
		y /= v.y;
		z /= v.z;
		return *this;
	}
	vec3& operator+=(float fl)
	{
		x += fl;
		y += fl;
		z += fl;
		return *this;
	}
	vec3& operator/=(float fl)
	{
		x /= fl;
		y /= fl;
		z /= fl;
		return *this;
	}
	vec3& operator-=(float fl)
	{
		x -= fl;
		y -= fl;
		z -= fl;
		return *this;
	}

	void NormalizeInPlace()
	{
		*this = Normalized();
	}
	vec3 Normalized() const
	{
		vec3 res = *this;
		float l = res.length();
		if (l != 0.0f) {
			res /= l;
		}
		else {
			res.x = res.y = res.z = 0.0f;
		}
		return res;
	}
	vec3 clamp() const
	{
		vec3 res = *this;
		res.x = clip_number(res.x, -89.0f, 89.0f);
		res.y = clip_number(std::remainder(res.y, 360.0f), -180.0f, 180.0f);
		res.z = clip_number(res.z, -50.0f, 50.0f);
		return res;
	}


	float DistTo(const vec3 &vOther) const
	{
		vec3 delta;

		delta.x = x - vOther.x;
		delta.y = y - vOther.y;
		delta.z = z - vOther.z;

		return delta.length();
	}
	float DistToSqr(const vec3 &vOther) const
	{
		vec3 delta;

		delta.x = x - vOther.x;
		delta.y = y - vOther.y;
		delta.z = z - vOther.z;

		return delta.LengthSqr();
	}
	float Dot(const vec3& vOther) const
	{
		return (x*vOther.x + y * vOther.y + z * vOther.z);
	}
	float length() const
	{
		return sqrt(x*x + y * y + z * z);
	}
	float LengthSqr(void) const
	{
		return (x*x + y * y + z * z);
	}
	float Length2D() const
	{
		return sqrt(x*x + y * y);
	}


	vec3& operator=(const vec3 &vOther)
	{
		x = vOther.x; y = vOther.y; z = vOther.z;
		return *this;
	}

	vec3 operator-(void) const
	{
		return vec3(-x, -y, -z);
	}
	vec3 operator+(const vec3& v) const
	{
		return vec3(x + v.x, y + v.y, z + v.z);
	}
	vec3 operator-(const vec3& v) const
	{
		return vec3(x - v.x, y - v.y, z - v.z);
	}
	vec3 operator*(float fl) const
	{
		return vec3(x * fl, y * fl, z * fl);
	}
	vec3 operator*(const vec3& v) const
	{
		return vec3(x * v.x, y * v.y, z * v.z);
	}
	vec3 operator/(float fl) const
	{
		return vec3(x / fl, y / fl, z / fl);
	}
	vec3 operator/(const vec3& v) const
	{
		return vec3(x / v.x, y / v.y, z / v.z);
	}

	float x, y, z;
};