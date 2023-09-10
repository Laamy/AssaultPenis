#pragma once

template <typename T>
struct Vector4
{
	union
	{
		struct
		{
			T w, x, y, z;
		};
		T arr[4];
	};

	Vector4(T w = 0, T x = 0, T y = 0, T z = 0)
	{
		this->w = w;
		this->x = x;
		this->y = y;
		this->z = z;
	};

	Vector4(Vector2<float> position, Vector2<float> size)
	{
		this->w = position.x;
		this->x = position.x + size.x;
		this->y = position.y;
		this->z = position.y + size.y;
	};

	bool operator == (Vector4 v)
	{
		return v.w == w && v.x == x && v.y == y && v.z == z;
	};

	bool operator != (Vector4 v)
	{
		return v.w != w || v.x != x || v.y != y || v.z != z;
	};
};