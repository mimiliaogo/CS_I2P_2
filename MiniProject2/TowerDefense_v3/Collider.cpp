#include <allegro5/color.h>
#include <memory>

#include "Collider.hpp"
#include "Point.hpp"

namespace Engine {
	bool Collider::IsPointInBitmap(Point pnt, const std::shared_ptr<ALLEGRO_BITMAP>& bmp) {
		return al_get_pixel(bmp.get(), static_cast<int>(pnt.x), static_cast<int>(pnt.y)).a != 0;
	}
	bool Collider::IsPointInRect(Point pnt, Point rectPos, Point rectSize) {
		return (rectPos.x <= pnt.x && pnt.x < rectPos.x + rectSize.x && rectPos.y <= pnt.y && pnt.y < rectPos.y + rectSize.y);
	}
	bool Collider::IsRectOverlap(Point r1Min, Point r1Max, Point r2Min, Point r2Max) {
		return (r1Max.x > r2Min.x && r2Max.x > r1Min.x && r1Max.y > r2Min.y && r2Max.y > r1Min.y);
	}
	bool Collider::IsCircleOverlap(Point c1, float r1, Point c2, float r2) {
		return (c1 - c2).Magnitude() < r1 + r2;
	}
}
