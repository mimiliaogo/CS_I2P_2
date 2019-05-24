#include <string>
#include <exception>
#include "Allegro5Exception.hpp"

namespace Engine {
	Allegro5Exception::Allegro5Exception(char const* const message) noexcept:
		std::exception(message) { }
	Allegro5Exception::Allegro5Exception(const std::string& message) noexcept:
		std::exception(message.c_str()) { }
}
