#include <memory>
#include <functional>
#include <allegro5/allegro.h>
#include "IControl.hpp"
#include "Image.hpp"
#include "Collider.hpp"
#include "GameEngine.hpp"
#include "Resources.hpp"
#include "ImageButton.hpp"

namespace Engine {
	ImageButton::ImageButton(std::string img, std::string imgIn, float x, float y, float w, float h, float anchorX, float anchorY) :
		Image(img, x, y, w, h, anchorX, anchorY), imgOut(Resources::GetInstance().GetBitmap(img)), imgIn(Resources::GetInstance().GetBitmap(imgIn)) {
		Point mouse = GameEngine::GetInstance().GetMousePosition();
		mouseIn = Collider::IsPointInBitmap(Point(mouse.x - Position.x - Anchor.x * GetBitmapWidth(), mouse.y - Position.y - Anchor.y * GetBitmapHeight()), bmp);
		if (!mouseIn) bmp = imgOut;
		else bmp = this->imgIn;
	}
	void ImageButton::SetOnClickCallback(std::function<void(void)> onClickCallback) {
		OnClickCallback = onClickCallback;
	}
	void ImageButton::OnMouseDown(int button, int mx, int my) {
		if ((button & 1) && mouseIn) {
			if (OnClickCallback)
				OnClickCallback();
		}
	}
	void ImageButton::OnMouseMove(int mx, int my) {
		mouseIn = Collider::IsPointInBitmap(Point(mx - Position.x - Anchor.x * GetBitmapWidth(), my - Position.y - Anchor.y * GetBitmapHeight()), bmp);
		if (!mouseIn) bmp = imgOut;
		else bmp = imgIn;
	}
}
