#pragma once

#include <cstdint>
#include <iostream>
#include <limits>
#include <math.h>
#include <algorithm>


namespace scarlett {

	template<typename T, size_t SizeOfArray>
	constexpr size_t ElementCount(T(&)[SizeOfArray]) { return SizeOfArray; }

	template <typename T>
	struct Vector2Type {
		union {
			T data[2];
			struct { T x, y; };
			struct { T r, g; };
			struct { T u, v; };
		};

		Vector2Type<T>() {};
		Vector2Type<T>(const T& _v) : x(_v), y(_v) {};
		Vector2Type<T>(const T& _x, const T& _y) : x(_x), y(_y) {};

		operator T*() { return data; };
		operator const T*() const { return static_cast<const T*>(data); };
	};

	typedef Vector2Type<float> Vector2f;


	template <typename T>
	struct Vector3Type {
		union {
			T data[3];
			struct { T x, y, z; };
			struct { T r, g, b; };
		};

		Vector3Type<T>() {};
		Vector3Type<T>(const T& _v) : x(_v), y(_v), z(_v) {};
		Vector3Type<T>(const T& _x, const T& _y, const T& _z) : x(_x), y(_y), z(_z) {};

		operator T*() { return data; };
		operator const T*() const { return static_cast<const T*>(data); };

		Vector3Type<T> operator+(const Vector3Type<T>& rhs){
			Vector3Type<T> res;
			res.x = x + rhs.x;
			res.y = y + rhs.y;
			res.z = z + rhs.z;
			return res;
		}

		Vector3Type<T> operator-(const Vector3Type<T>& rhs) {
			Vector3Type<T> res;
			res.x = x - rhs.x;
			res.y = y - rhs.y;
			res.z = z - rhs.z;
			return res;
		}

		Vector3Type<T> operator*(T scale) {
			Vector3Type<T> res;
			res.x = x * scale;
			res.y = y * scale;
			res.z = z * scale;
			return res;
		}

		T length2()
		{
			return x * x + y * y + z * z;
		}

		T length()
		{
			return sqrt(length2());
		}

	};

	typedef Vector3Type<float> Vector3f;


	template <typename T>
	struct Vector4Type {
		union {
			T data[4];
			struct { T x, y, z, w; };
			struct { T r, g, b, a; };
		};

		Vector4Type<T>() {};
		Vector4Type<T>(const T& _v) : x(_v), y(_v), z(_v), w(_v) {};
		Vector4Type<T>(const T& _x, const T& _y, const T& _z, const T& _w) : x(_x), y(_y), z(_z), w(_w) {};
		Vector4Type<T>(const Vector3Type<T>& v3) : x(v3.x), y(v3.y), z(v3.z), w(1.0f) {};
		Vector4Type<T>(const Vector3Type<T>& v3, const T& _w) : x(v3.x), y(v3.y), z(v3.z), w(_w) {};

		operator T*() { return data; };
		operator const T*() const { return static_cast<const T*>(data); };
		Vector4Type& operator=(const T* f) {
			memcpy(data, f, sizeof(T) * 4);
			return *this;
		};

		Vector4Type<T> operator+(const Vector4Type<T>& rhs) {
			Vector4Type<T> res;
			res.x = x + rhs.x;
			res.y = y + rhs.y;
			res.z = z + rhs.z;
			res.w = w + rhs.w;
			return res;
		}

		Vector4Type<T> operator-(const Vector4Type<T>& rhs) {
			Vector4Type<T> res;
			res.x = x - rhs.x;
			res.y = y - rhs.y;
			res.z = z - rhs.z;
			res.w = w - rhs.w;
			return res;
		}

	};

	typedef Vector4Type<float> Vector4f;
	typedef Vector4Type<float> Quaternion;
	typedef Vector4Type<uint8_t> R8G8B8A8Unorm;
	typedef Vector4Type<uint8_t> Vector4i;
	typedef Vector4Type<float> Color;

	template <template <typename> class TT, typename T>
	std::ostream& operator<<(std::ostream& out, TT<T> vector) {
		out << "( ";
		for (uint32_t i = 0; i < ElementCount(vector.data); i++) {
			out << vector.data[i] << ((i == ElementCount(vector.data) - 1) ? ' ' : ',');
		}
		out << ")";

		return out;
	}

	template <template <typename> class TT, typename T>
	TT<T> VectorScale(const TT<T>& v, float scale) {
		size_t count = ElementCount(v.data);
		TT<T> result;
		for (size_t i = 0; i < count; ++i) {
			result[i] = v[i]*scale;
		}
		return result;
	}

	template <template<typename> class TT, typename T>
	void VectorAdd(TT<T>& result, const TT<T>& vec1, const TT<T>& vec2) {
		size_t count = ElementCount(result.data);
		for (size_t i = 0; i < count; ++i) {
			result[i] = vec1[i] + vec2[i];
		}
	}


	template <template<typename>class TT, typename T>
	void VectorSub(TT<T>& result, const TT<T>& vec1, const TT<T>& vec2) {
		size_t count = ElementCount(result.data);
		for (size_t i = 0; i < count; ++i) {
			result[i] = vec1[i] - vec2[i];
		}
	}


	template <template<typename> class TT, typename T>
	inline void CrossProduct(TT<T>& result, const TT<T>& vec1, const TT<T>& vec2) {
		result[0] = vec1[1] * vec2[2] - vec1[2] * vec2[1];
		result[1] = vec1[2] * vec2[0] - vec1[0] * vec2[2];
		result[2] = vec1[0] * vec2[1] - vec1[1] * vec2[0];
	}

	template <template<typename> class TT, typename T>
	inline TT<T>  CrossProduct(const TT<T>& vec1, const TT<T>& vec2) {
		TT<T> result;
		result[0] = vec1[1] * vec2[2] - vec1[2] * vec2[1];
		result[1] = vec1[2] * vec2[0] - vec1[0] * vec2[2];
		result[2] = vec1[0] * vec2[1] - vec1[1] * vec2[0];
		return result;
	}

	template <template<typename> class TT, typename T>
	inline T DotProduct(const TT<T>& vec1, const TT<T>& vec2) {
		size_t count = ElementCount(vec1.data);
		T result = 0;
		for (size_t i = 0; i < count; ++i) {
			result += vec1[i] * vec2[i];
		}
		return result;
	}

	template <template<typename>class TT, typename T>
	inline void Normalize(TT<T>& result)
	{
		T length;
		size_t count = ElementCount(result.data);
		length = DotProduct(result, result);
		length = 1.0f / sqrt(length);
		for (size_t i = 0; i < count; ++i) {
			result[i] = result[i] * length;
		}
	}

	template <template<typename> class TT, typename T>
	inline T Distance(const TT<T>& vec1, const TT<T>& vec2) {
		T dis = 0;
		size_t count = ElementCount(vec1.data);
		for (size_t i = 0; i < count; ++i) {
			dis += (vec1[i] - vec2[i]) * (vec1[i] - vec2[i]);
		}
		
		return sqrtf(dis);
	}

	template <template<typename> class TT, typename T>
	inline T VectorLength(const TT<T>& vec1)
	{
		T dis = 0;
		size_t count = ElementCount(vec1.data);
		for (size_t i = 0; i < count; ++i) {
			dis += (vec1[i]) * (vec1[i]);
		}

		return sqrtf(dis);
	}

	inline Quaternion operator*(const Quaternion q1, const Quaternion q2)
	{
		
		Vector3f v1(q1.x, q1.y, q1.z);
		Vector3f v2(q2.x, q2.y, q2.z);

		Vector3f v1v2 = CrossProduct(v1, v2) + v1 * q2.w + v2 * q1.w;
		float real = q1.w*q2.w - DotProduct(v1, v2);

		Quaternion ret(v1v2.x, v1v2.y, v1v2.z, real);
		return ret;

	}

}