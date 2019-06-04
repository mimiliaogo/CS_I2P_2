#ifndef ALLEGRO5EXCEPTION_HPP
#define ALLEGRO5EXCEPTION_HPP
#include <stdexcept>
#include <string>

namespace Engine {
	/// <summary>
	/// Exception class dedicated to Allegro5 library's exception.
	/// </summary>
	class Allegro5Exception final : public std::runtime_error {
	public:
		/// <summary>
		/// Throw Allegro5 error with char array message.
		/// </summary>
		/// <param name="message">The error message.</param>
		explicit Allegro5Exception(char const* const message) noexcept;
		/// <summary>
		/// Throw Allegro5 error with std::string message.
		/// </summary>
		/// <param name="message">The error message.</param>
		explicit Allegro5Exception(const std::string& message) noexcept;
	};
}
#endif // ALLEGRO5EXCEPTION_HPP
