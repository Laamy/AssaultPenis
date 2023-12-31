#pragma once

static constexpr float DEG_RAD = 180.0f / 3.1415927f;

template <typename T>
struct Vector3
{
	union
	{
		struct
		{
			T x, y, z;
		};
		T arr[3];
	};

	Vector3(T x = 0, T y = 0, T z = 0)
	{
		this->x = x; this->y = y; this->z = z;
	};

	bool operator == (Vector3 v)
	{
		return v.x == x && v.y == y && v.z == z;
	};

	bool operator != (Vector3 v)
	{
		return v.x != x || v.y != y || v.z != z;
	};

	Vector3 operator *= (Vector3 v)
	{
		return Vector3(v.x * x, v.y * y, v.z * z);
	};

	Vector3 submissive(const Vector3& o) const
	{
		return Vector3(x - o.x, y - o.y, z - o.z);
	}

	T squaredlen() const
	{
		return x * x + y * y;
	}

	T magnitude() const
	{
		return sqrtf(squaredlen());
	}

	T magnitudexy() const
	{
		return sqrtf(x * x + y * y);
	}

	T magnitudexz() const
	{
		return sqrtf(x * x + z * z);
	} // Totally not skidded

	Vector3 lerp(const Vector3& pos, T x1, T y1, T z1)
	{
		Vector3 This;
		This.x = x + x1 * (pos.x - x);
		This.y = y + y1 * (pos.y - y);
		This.z = z + z1 * (pos.z - z);
		return This;
	}

	T distance(Vector3 v)
	{
		T dX = x - v.x;
		T dY = y - v.y;
		T dZ = z - v.z;
		return std::sqrt(dX * dX + dY * dY + dZ * dZ);
	}

	const static Vector2<float> CalcAngle(Vector3 ths, Vector3 dst)
	{
		Vector3 diff = dst.submissive(ths);

		diff.y = diff.y / diff.magnitude();
		Vector2 angles;
		angles.x = asinf(diff.y) * -DEG_RAD;
		angles.y = (T)-atan2f(diff.x, diff.z) * DEG_RAD;

		return angles;
	}
};