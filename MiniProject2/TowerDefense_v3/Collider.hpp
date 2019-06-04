#ifndef COLLIDER_HPP
#define COLLIDER_HPP
#include <allegro5/bitmap.h>
#include <memory>

namespace Engine {
	struct Point;
	/// <summary>
	/// Helper class for calculating physical collision, overlap, point in region.
	/// Note: Implementing a physical engine is an overkill in this game, helper class is much simpler.
	/// </summary>
	struct Collider final {
		explicit Collider() = delete;
		/// <summary>
		/// Check if the bitmap pixel is opaque. (non-transparent)
		/// </summary>
		/// <param name="pnt">The pixel coordinate.</param>
		/// <param name="bmp">The target bitmap.</param>
		/// <returns>Determines whether the pixel of the bitmap is opaque.</returns>
		static bool IsPointInBitmap(Point pnt, const std::shared_ptr<ALLEGRO_BITMAP>& bmp);
		/// <summary>
		/// Check if point is within rectangle region.
		/// </summary>
		/// <param name="pnt">The point we want to detect.</param>
		/// <param name="rectPos">The rectangle left-upper position.</param>
		/// <param name="rectSize">The rectangle size. (width, height)</param>
		/// <returns>Determines whether the pixel is in the rectangle.</returns>
		static bool IsPointInRect(Point pnt, Point rectPos, Point rectSize);
		/// <summary>
		/// Check if two rectangle overlaps.
		/// </summary>
		/// <param name="rect1p1">Top-Left coordinate of the first rectangle.</param>
		/// <param name="rect1p2">Bottom-Right coordinate of the first rectangle.</param>
		/// <param name="rect2p1">Top-Left coordinate of the second rectangle.</param>
		/// <param name="rect2p2">Bottom-Right coordinate of the second rectangle.</param>
		/// <returns>Determines whether the two rectangles overlaps.</returns>
		static bool IsRectOverlap(Point rect1p1, Point rect1p2, Point rect2p1, Point rect2p2);
		/// <summary>
		/// Check if two circle overlaps.
		/// </summary>
		/// <param name="c1">The center coordinate of the first circle.</param>
		/// <param name="r1">The radius of the first circle.</param>
		/// <param name="c2">The center coordinate of the second circle.</param>
		/// <param name="r2">The radius of the second circle.</param>
		/// <returns>Determines whether the two circles overlaps.</returns>
		static bool IsCircleOverlap(Point c1, float r1, Point c2, float r2);
	};
}
#endif // COLLIDER_HPP
