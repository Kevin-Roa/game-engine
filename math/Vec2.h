#pragma once

namespace math {
	template<typename T>
	class Vec2 {
	public:
		T x, y;
		
	public:
		//  Constructors
		Vec2(const T& _x, const T& _y) : x(_x), y(_y) {}
        Vec2(const Vec2<T>& other) { operator = (other); }
		Vec2(Vec2<T>&& other) { operator = (other); }
		
		//  Override == operator
		bool operator == (const Vec2<T>& other) const {
			return isZero(x - other.x) && isZero(y - other.y);
		}
		
		//  Override != operator
		bool operator != (const Vec2<T>& other) const {
			return !isZero(x - other.x) || !isZero(y - other.y);
		}
		
		//  Override = operator
		Vec2<T>& operator = (const Vec2<T>& other) {
			x = other.x;
			y = other.y;
			return *this;
		}
		
		//  Override + operator
		Vec2<T> operator + (const T& t) const {
			return { x + t, y + t };
		}
		
		//  Override + operator
		Vec2<T> operator + (const Vec2<T>& other) const {
			return { x + other.x, y + other.y };
		}
		
		//  Override += operator
		Vec2<T>& operator += (const T& t) {
			x += t;
			y += t;
			return *this;
		}
		
		//  Override += operator
		Vec2<T> operator += (const Vec2<T>& other) {
			x += other.x;
			y += other.y;
			return *this;
		}
		
		//  Override - operator
		Vec2<T> operator - (const T& t) const {
			return { x - t, y - t };
		}
		
		//  Override - operator
		Vec2<T> operator - (const Vec2<T>& other) const {
			return { x - other.x, y - other.y };
		}
		
		//  Override -= operator
		Vec2<T>& operator -= (const T& t) {
			x -= t;
			y -= t;
			return *this;
		}
		
		//  Override -= operator
		Vec2<T> operator -= (const Vec2<T>& other) {
			x -= other.x;
			y -= other.y;
			return *this;
		}
		
		//  Override * operator
		Vec2<T> operator * (const T& t) const {
			return { x * t, y * t };
		}
		
		//  Override * operator
		Vec2<T> operator * (const Vec2<T>& other) const {
			return { x * other.x, y * other.y };
		}
		
		//  Override *= operator
		Vec2<T>& operator *= (const T& t) {
			x *= t;
			y *= t;
			return *this;
		}
		
		//  Override *= operator
		Vec2<T> operator *= (const Vec2<T>& other) {
			x *= other.x;
			y *= other.y;
			return *this;
		}
		
		//  Override / operator
		Vec2<T> operator / (const T& t) const {
			return { x / t, y / t };
		}
		
		//  Override / operator
		Vec2<T> operator / (const Vec2<T>& other) const {
			return { x / other.x, y / other.y };
		}
		
		//  Override /= operator
		Vec2<T>& operator /= (const T& t) {
			x /= t;
			y /= t;
			return *this;
		}
		
		//  Override /= operator
		Vec2<T> operator /= (const Vec2<T>& other) {
			x /= other.x;
			y /= other.y;
			return *this;
		}
		
		//  Length of the vector
		T Magnitude() const { return dist(0.f, 0.f, x, y); }
		
		//  Get vector of length 1 in same direction
		Vec2<T> Normalized() const { return operator / (Magnitude()); }
		
		//  Get vector of length 1 in same direction
		Vec2<T>& Normalize() { return operator /= (Magnitude()); }
		
		//  Dot product of this and other vector
		T Dot(const Vec2<T>& other) const { return x * other.x + y * other.y; }
		
		//  Angle of vector
		T Angle() const { return atan(x, y); }
		
        // Angle between this and other vector
        T AngleBetween(const Vec2<T>& other) const {
            // Optimization of abs(Angle() - other.Angle())
            return acos(Dot(other) / (Magnitude() * other.Magnitude()));
        }
	};
}
