#ifndef LABEL_HPP
#define LABEL_HPP
#include <allegro5/allegro_font.h>
#include <allegro5/color.h>
#include <memory>
#include <string>

#include "IObject.hpp"

namespace Engine {
	/// <summary>
	/// A simple static text object.
	/// </summary>
	class Label : public IObject {
	protected:
		// Smart pointer to font.
		std::shared_ptr<ALLEGRO_FONT> font;
	public:
		// Text to draw.
		std::string Text;
		// Text's color.
		ALLEGRO_COLOR Color;
		/// <summary>
		/// Construct a label object.
		/// </summary>
		/// <param name="text">Text to draw.</param>
		/// <param name="font">Font to draw in.</param>
		/// <param name="fontSize">Text's font size.</param>
		/// <param name="x">X-coordinate.</param>
		/// <param name="y">Y-coordinate.</param>
		/// <param name="r">Color's red value.</param>
		/// <param name="g">Color's green value.</param>
		/// <param name="b">Color's blue value.</param>
		/// <param name="a">Color's alpha value.</param>
		/// <param name="anchorX">The centerX of the object. (0, 0) means top-left, while (1, 0) means top-right.</param>
		/// <param name="anchorY">The centerY of the object. (0, 1) means bottom-left, while (1, 1) means bottom-right.</param>
		explicit Label(const std::string& text, const std::string& font, int fontSize, float x, float y, unsigned char r = 0, unsigned char g = 0, unsigned char b = 0, unsigned char a = 255, float anchorX = 0, float anchorY = 0);
		/// <summary>
		/// Draw text with loaded font.
		/// </summary>
		void Draw() const override;
		/// <summary>
		/// Return text width.
		/// </summary>
		/// <returns>Width of the text.</returns>
		int GetTextWidth() const;
		/// <summary>
		/// Return text height.
		/// </summary>
		/// <returns>Height of the text.</returns>
		int GetTextHeight() const;
	};
}

#endif // LABEL_HPP
