#ifndef POINT_HPP
#define POINT_HPP

namespace Engine {
	/// <summary>
	/// Can be used as 2D coordinate point or 2D vector.
	/// </summary>
	struct Point {
		// The coordinates of the point.
		float x, y;
		/// <summary>
		/// Construct a Point with coordinate (0, 0).
		/// </summary>
		explicit Point();
		/// <summary>
		/// Construct a Point with coordinate (x, y).
		/// </summary>
		/// <param name="x">X coordinate of the point</param>
		/// <param name="y">Y coordinate of the point</param>
		explicit Point(float x, float y);
		/// <summary>
		/// Compare between Points.
		/// </summary>
		/// <returns>Determines whether the two Points have the same coordinate.</returns>
		bool operator==(const Point& rhs) const;
		/// <summary>
		/// Compare between Points.
		/// </summary>
		/// <returns>Determines whether the two Points have distinct coordinate.</returns>
		bool operator!=(const Point& rhs) const;
		/// <summary>
		/// Add points.
		/// </summary>
		/// <returns>The added result.</returns>
		Point operator+(const Point& rhs) const;
		/// <summary>
		/// Subtract points.
		/// </summary>
		/// <returns>The subtracted result.</returns>
		Point operator-(const Point& rhs) const;
		/// <summary>
		/// Multiply the point's coordinate with a scalar.
		/// </summary>
		/// <returns>The multiplied result.</returns>
		Point operator*(const float& rhs) const;
		/// <summary>
		/// Divide the point's coordinate with a scalar.
		/// </summary>
		/// <returns>The divided result.</returns>
		Point operator/(const float& rhs) const;
		/// <summary>
		/// Make point act like vector and get the normalized vector.
		/// </summary>
		/// <returns>The normalized vector.</returns>
		Point Normalize() const;
		/// <summary>
		/// Make point act like vector and get the inner product.
		/// </summary>
		/// <param name="rhs">The second vector.</param>
		/// <returns>The inner product.</returns>
		float Dot(const Point& rhs) const;
		/// <summary>
		/// Make point act like vector and get the squared magnitude.
		/// </summary>
		/// <returns>Squared magnitude of vector.</returns>
		float MagnitudeSquared() const;
		/// <summary>
		/// Make point act like vector and get the magnitude.
		/// </summary>
		/// <returns>Magnitude of vector.</returns>
		float Magnitude() const;
	};
	Point operator*(const float& lhs, const Point& rhs);
}
#endif // POINT_HPP
