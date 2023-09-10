#pragma once

template<typename T>
struct AABB
{
	union
	{
		struct {
			Vector3<T> lower, upper;
		};
		Vector3<T> arr[2]{};
	};

	AABB(Vector3<T> position, Vector3<T> size)
	{
		this->upper.x = position.x;
		this->lower.x = position.x + size.x;
		this->upper.y = position.y;
		this->lower.y = position.y + size.y;
		this->upper.z = position.z;
		this->lower.z = position.z + size.z;
	};
};