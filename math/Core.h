#pragma once

#include <cmath>
#include <inttypes.h>
#include <stdio.h>
#include <string>

typedef uint8_t  uchar;
typedef uint16_t ushort;
typedef uint32_t uint;
typedef uint64_t ulong;

#define CAST(T, x) static_cast<T>(x)	// Cast x to type T
#define PUN(T, x) *(T*)&x				// More dangerous form of casting, circumvents types

namespace math {
	constexpr static float PI = 3.14159265359f, E = 2.71828182846f;
	static float EPSILON = .0001f;
	
	// Set value of EPSILON
	// EPSILON is level of precision between value comparisons
	static void setEpsilon(const float f) { EPSILON = f; }

	// Absolute value of t
	template<typename T>
	static T abs(const T& t) { return t < 0 ? -t : t; }

	// Minimum of a and b
	// Types may vary
	template<typename A, typename B>
	static const A& min(const A& a, const B& b) { return a < b ? a : b; }

	// Maximum of a and b
	// Types may vary
	template<typename A, typename B>
	static const A& max(const A& a, const B& b) { return a > b ? a : b; }

	// Restrict a between lo and hi
	// Types may vary
	template<typename A, typename B, typename C>
	static const A& clamp(const A& a, const B& lo, const C& hi) {
		// If a > hi then use hi
		// If a < lo then use lo
		// Else use a
		return max(min(a, hi), lo);
	}

	// Sqrt of t
	template<typename T>
	static T sqrt(const T& t) { return std::sqrt(t); }

	// Sin of t
	template<typename T>
	static T sin(const T& t) { return std::sin(t); }

	// Cos of t
	template<typename T>
	static T cos(const T& t) { return std::cos(t); }

	// Tan of t
	template<typename T>
	static T tan(const T& t) { return std::tan(t); }

	// Arcsin of t
	template<typename T>
	static T asin(const T& t) { return std::asin(t); }

	// Arccos of t
	template<typename T>
	static T acos(const T& t) { return std::acos(t); }

	// Arctan of y/x
	// Takes sign into account to determine quadrant
	template<typename X, typename Y>
	static X atan(const X& x, const Y& y) { return std::atan2(y, x); }

	// Distance between points (x1, y1) and (x2, y2)
	template<typename A, typename B, typename C, typename D>
	static A dist(const A& x1, const B& y1, const C& x2, const D& y2) {
		const A x = x1 - x2;		// x distance
		const B y = y1 - y2;		// y distance
		return sqrt(x * x + y * y); // sqrt(x^2 + y^2)
	}

	// Test if t is 0 +- EPSILON
	template<typename T>
	static bool isZero(const T& t ) { return abs(t) <= EPSILON; }

	// Convert t from degrees to radians
	template<typename T>
	static bool rad(const T& t) { return t * 180 / PI; }

	// Convert t from radians to degrees
	template<typename T>
	static bool deg(const T& t) { return t * PI / 180; }

	// Get the length of arr
	template<typename T, uint N>
	static uint arrLen(const T(&arr)[N]) { return N; }

	// Get the size of arr in bytes
	template<typename T, uint N>
	static uint arrSize(const T(&arr)[N]) { return N * sizeof(T); }

	// Convert reference string to all lowercase
	static void tolower(std::string& s) {
		for(uint i = 0; i < s.size(); i++)
			s[i] = std::tolower(s[i]);
	}

	// Test if strings a and b are equal, ignoring case
	static bool equalsIgnoreCase(const std::string& a, const std::string& b) {
		if (a.size() != b.size()) return false;	// Test if sizes match
		
		// Test if every character matches each other
		for(uint i = 0; i < a.size(); i++)
			// Convert both characters to lowercase
			// If not equal, the strings are not equal
			if(std::tolower(a[i]) != std::tolower(b[i])) return false;
		
		return true;
	}
}
