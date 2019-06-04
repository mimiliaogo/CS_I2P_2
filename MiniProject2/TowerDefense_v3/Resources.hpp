#ifndef RESOURCES_HPP
#define RESOURCES_HPP
#include <allegro5/bitmap.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <memory>
#include <unordered_map>
#include <string>


namespace Engine {
	/// <summary>
	/// The one and only Resources for the entire program. Responsible for low-level resource loading and destroying.
	/// It acts like a smart caching helper class.
	/// </summary>
	class Resources final {
	private:
		// The path prefix for loading bitmaps.
		static const std::string bitmapPathPrefix;
		// The path prefix for loading fonts.
		static const std::string fontPathPrefix;
		// The path prefix for loading samples.
		static const std::string samplePathPrefix;
		// All bitmaps are stored in hash table for easy access and management.
		// Note: std::shared_ptr is a kind of smart pointer.
		//       To put it simple, it's a pointer that will delete itself when no one has reference to it.
		//       It's very convenient, and can greatly reduce the possibility of memory leaks if used correctly.
		//       If you have heard of Garbage Collection, the concept is almost the same. However, smart pointers are faster,
		//       and only relies on reference counting and class destructor, which I think is really "smart".
		// Note (Advanced): The reason we didn't use std::weak_ptr here is to avoid the possibility of some resource
		//                  being loaded and destroyed consecutively, which could occur if a object prototype being
		//                  added, removed, added, removed, ... in the same scene (e.g. bullets).
		// Reference: Smart Pointers - std::unique_ptr, std::shared_ptr, std::weak_ptr.
		std::unordered_map<std::string, std::shared_ptr<ALLEGRO_BITMAP>> bitmaps;
		// All fonts are stored in hash table for easy access and management.
		std::unordered_map<std::string, std::shared_ptr<ALLEGRO_FONT>> fonts;
		// All samples are stored in hash table for easy access and management.
		std::unordered_map<std::string, std::shared_ptr<ALLEGRO_SAMPLE>> samples;
		/// <summary>
		/// Private constructor since this class is a Singleton.
		/// </summary>
		explicit Resources();
	public:
		/// <summary>
		/// Copy constructor is deleted, no copying allowed.
		/// </summary>
		Resources(Resources const&) = delete;
		/// <summary>
		/// Copy assignment operator is deleted, no copy assignment allowed.
		/// </summary>
		void operator=(Resources const&) = delete;
		/// <summary>
		/// Release all loaded resources.
		/// </summary>
		~Resources();
		/// <summary>
		/// Release resources that are not currently used.
		/// </summary>
		void ReleaseUnused();
		/// <summary>
		/// Get bitmap pointer by name. The file should be put under "resources/images/".
		/// </summary>
		/// <param name="name">The filename of the image. (Including extension)</param>
		/// <returns>The smart pointer of the bitmap.</returns>
		std::shared_ptr<ALLEGRO_BITMAP> GetBitmap(std::string name);
		/// <summary>
		/// Get bitmap pointer by name, and resize it. The file should be put under "resources/images/".
		/// </summary>
		/// <param name="name">The filename of the image. (Including extension)</param>
		/// <param name="width">The target width that we want the image to be resized to.</param>
		/// <param name="height">The target height that we want the image to be resized to.</param>
		/// <returns>The smart pointer of the bitmap.</returns>
		std::shared_ptr<ALLEGRO_BITMAP> GetBitmap(std::string name, int width, int height);
		/// <summary>
		/// Get font pointer by name. The file should be put under "resources/fonts/".
		/// </summary>
		/// <param name="name">The filename of the font. (Including extension)</param>
		/// <param name="size">The font size of the font.</param>
		/// <returns>The smart pointer of the font.</returns>
		std::shared_ptr<ALLEGRO_FONT> GetFont(std::string name, int fontSize);
		/// <summary>
		/// Get sample pointer by name. The file should be put under "resources/audios".
		/// </summary>
		/// <param name="name">The filename of the audio. (Including extension)</param>
		/// <returns>The smart pointer of the sample.</returns>
		std::shared_ptr<ALLEGRO_SAMPLE> GetSample(std::string name);
		/// <summary>
		/// Typical function to retrieve Singleton instance and supports lazy initialization.
		/// </summary>
		/// <returns>The Singleton instance of Resources.</returns>
		static Resources& GetInstance();
	};
}
#endif // RESOURCES_HPP
