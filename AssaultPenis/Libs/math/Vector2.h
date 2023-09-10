#pragma once

template <typename T>
struct Vector2
{
	union
	{
		struct
		{
			T x, y;
		};
		T arr[2];
	};

	Vector2(T x = 0, T y = 0)
	{
		this->x = x; this->y = y;
	};

	bool operator == (Vector2 v)
	{
		return v.x == x && v.y == y;
	};

	bool operator != (Vector2 v)
	{
		return v.x != x || v.y != y;
	};

	Vector2 operator *= (Vector2 v)
	{
		return Vector2(v.x * x, v.y * y);
	};
};