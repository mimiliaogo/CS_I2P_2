#ifndef IMAGE_HPP
#define IMAGE_HPP
#include <allegro5/bitmap.h>
#include <memory>
#include <string>

#include "IObject.hpp"

namespace Engine {
	/// <summary>
	/// A simple static image object.
	/// </summary>
	class Image : public IObject {
	public:
		// Smart pointer to bitmap.
		std::shared_ptr<ALLEGRO_BITMAP> bmp;
		/// <summary>
		/// Construct a image object.
		/// </summary>
		/// <param name="img">The image path in 'resources/images/'</param>
		/// <param name="x">X-coordinate.</param>
		/// <param name="y">Y-coordinate.</param>
		/// <param name="w">Width of the image, 0 indicates original size.</param>
		/// <param name="h">Height of the image, 0 indicates original size.</param>
		/// <param name="anchorX">The centerX of the object. (0, 0) means top-left, while (1, 0) means top-right.</param>
		/// <param name="anchorY">The centerY of the object. (0, 1) means bottom-left, while (1, 1) means bottom-right.</param>
		explicit Image(std::string img, float x, float y, float w = 0, float h = 0, float anchorX = 0, float anchorY = 0);
		/// <summary>
		/// Draw the loaded image.
		/// </summary>
		void Draw() const override;
		/// <summary>
		/// Return bitmap width.
		/// </summary>
		/// <returns>Width of the original or scaled bitmap.</returns>
		int GetBitmapWidth() const;
		/// <summary>
		/// Return bitmap height.
		/// </summary>
		/// <returns>Height of the original or scaled bitmap.</returns>
		int GetBitmapHeight() const;
	};
}
#endif // IMAGE_HPP
