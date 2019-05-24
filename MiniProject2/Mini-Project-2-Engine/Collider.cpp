#include <memory>
#include <allegro5/bitmap.h>
#include "Point.hpp"
#include "Collider.hpp"

namespace Engine {
	bool Collider::IsPointInBitmap(Point pnt, const std::shared_ptr<ALLEGRO_BITMAP>& bmp) {
		return al_get_pixel(bmp.get(), static_cast<int>(pnt.x), static_cast<int>(pnt.y)).a != 0;
	}
	bool Collider::IsPointInRect(Point pnt, Point rectPos, Point rectSize) {
		return (rectPos.x <= pnt.x && pnt.x < rectPos.x + rectSize.x && rectPos.y <= pnt.y && pnt.y < rectPos.y + rectSize.y);
	}
	bool Collider::IsCircleOverlap(Point c1, float r1, Point c2, float r2) {
		return (c1 - c2).magnitude() < r1 + r2;
	}
}
