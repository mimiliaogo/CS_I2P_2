#ifndef SPRITE_HPP
#define SPRITE_HPP
#include <allegro5/color.h>
#include <string>

#include "Image.hpp"
#include "Point.hpp"

namespace Engine {
	/// <summary>
	/// Image that supports rotation, velocity, tint, and collision radius.
	/// </summary>
	class Sprite : public Image {
	public:
		// Rotation angle in radians.
		float Rotation;
		// Pixel in seconds.
		Point Velocity;
		// Color tint.
		ALLEGRO_COLOR Tint;
		// Assume a circle is a good approximation of the sprite's boundary.
		float CollisionRadius = 0;
		/// <summary>
		/// Construct a sprite object.
		/// </summary>
		/// <param name="img">The image path in 'resources/images/'</param>
		/// <param name="x">X-coordinate.</param>
		/// <param name="y">Y-coordinate.</param>
		/// <param name="w">Width of the image, 0 indicates original size.</param>
		/// <param name="h">Height of the image, 0 indicates original size.</param>
		/// <param name="anchorX">The centerX of the object. (0, 0) means top-left, while (1, 0) means top-right.</param>
		/// <param name="anchorY">The centerY of the object. (0, 1) means bottom-left, while (1, 1) means bottom-right.</param>
		/// <param name="rotation">Rotation in radians.</param>
		/// <param name="vx">X-Velocity.</param>
		/// <param name="vy">Y-Velocity.</param>
		/// <param name="r">Color tint red value.</param>
		/// <param name="g">Color tint green value.</param>
		/// <param name="b">Color tint blue value.</param>
		/// <param name="a">Color tint alpha value.</param>
		explicit Sprite(std::string img, float x, float y, float w = 0, float h = 0, float anchorX = 0.5f, float anchorY = 0.5f,
			float rotation = 0, float vx = 0, float vy = 0, unsigned char r = 255, unsigned char g = 255, unsigned char b = 255, unsigned char a = 255);
		/// <summary>
		/// Draw to window display.
		/// This is called when the game should redraw the window.
		/// </summary>
		void Draw() const override;
		/// <summary>
		/// Run game logic such as updating the world, checking for collision, and so on.
		/// This is called when the game should update its logic, usually 'fps' times per second.
		/// </summary>
		/// <param name="deltaTime">Time elapsed since last update, can be used to calculate value changes.</param>
		void Update(float deltaTime) override;
	};
}
#endif // SPRITE_HPP

