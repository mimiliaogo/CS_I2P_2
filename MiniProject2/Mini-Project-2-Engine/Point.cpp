#include <cmath>
#include "Point.hpp"

namespace Engine {
	Point::Point() : Point(0, 0) {}
	Point::Point(float x, float y) : x(x), y(y) {}
	bool Point::operator==(const Point& rhs) const {
		return x == rhs.x && y == rhs.y;
	}
	bool Point::operator!=(const Point& rhs) const {
		return !operator==(rhs);
	}
	Point Point::operator+(const Point& rhs) const {
		return Point(x + rhs.x, y + rhs.y);
	}
	Point Point::operator-(const Point& rhs) const {
		return Point(x - rhs.x, y - rhs.y);
	}
	Point Point::operator*(const float& rhs) const {
		return Point(x * rhs, y * rhs);
	}
	Point Point::operator/(const float& rhs) const {
		return Point(x / rhs, y / rhs);
	}
	Point Point::Normalize() const {
		return Point(x, y) / magnitude();
	}
	float Point::magnitudeSquared() const {
		return x * x + y * y;
	}
	float Point::magnitude() const {
		return sqrt(magnitudeSquared());
	};
	Point operator*(const float& lhs, const Point& rhs) {
		return rhs * lhs;
	}
}
