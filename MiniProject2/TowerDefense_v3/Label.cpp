#include <allegro5/allegro_font.h>
#include <memory>

#include "IObject.hpp"
#include "Label.hpp"
#include "Point.hpp"
#include "Resources.hpp"

namespace Engine {
	Label::Label(const std::string& text, const std::string& font, int fontSize, float x, float y, unsigned char r, unsigned char g, unsigned char b, unsigned char a, float anchorX, float anchorY) :
		IObject(x, y, 0, 0, anchorX, anchorY), font(Resources::GetInstance().GetFont(font, fontSize)), Text(text), Color(al_map_rgba(r, g, b, a)) {
	}
	void Label::Draw() const {
		al_draw_text(font.get(), Color, Position.x - Anchor.x * GetTextWidth(), Position.y - Anchor.y * GetTextHeight(), 0, Text.c_str());
	}
	int Label::GetTextWidth() const {
		return al_get_text_width(font.get(), Text.c_str());
	}
	int Label::GetTextHeight() const {
		return al_get_font_line_height(font.get());
	}
}
