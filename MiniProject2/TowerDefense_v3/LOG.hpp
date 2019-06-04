#ifndef LOG_HPP
#define LOG_HPP
#include <fstream>
#include <iostream>

namespace Engine {
	// Log types that will be formatted in front of the line.
	enum LogType {
		VERBOSE,
		DEBUG,
		INFO,
		WARN,
		ERROR
	};

	/// <summary>
	/// Helper log class for quick logging to console and file. Can be used like std::cout.
	/// </summary>
	class LOG final {
	private:
		// Determine if global log is enabled.
		static bool Enabled;
		// Determine whether should log verbose messages or not.
		static bool LogVerbose;
		// The file path of the log file.
		static const char* FilePath;
		/// <summary>
		/// Get the label from log type.
		/// </summary>
		/// <param name="type">Log type of a log instance.</param>
		/// <returns>Returns the string label of the type.</returns>
		static const char* getLabel(LogType type);

		// File stream to write to.
		std::ofstream ofs;
		// Determines if log is enabled.
		bool enabled;

		/// <summary>
		/// Check should we log the message.
		/// </summary>
		/// <returns>Determines whether the messages should be logged.</returns>
		bool canLog() const;
	public:
		// Determines the prefix label.
		LogType type;

		/// <summary>
		/// Start a log chain with certain type.
		/// </summary>
		/// <param name="type">The type of this log chain, default is DEBUG.</param>
		explicit LOG(LogType type = DEBUG);
		/// <summary>
		/// Add new line and close file.
		/// </summary>
		~LOG();
		/// <summary>
		/// Support logging chain that can be used in the same way as std::cout.
		/// </summary>
		template<class T>
		LOG& operator<<(const T &msg) {
			if (canLog()) {
				std::cout << msg;
				ofs << msg;
			}
			return *this;
		}
		/// <summary>
		/// Set global configuration.
		/// </summary>
		/// <param name="enabled">Determine if global log is enabled.</param>
		/// <param name="logVerbose">Determine whether should log verbose messages or not.</param>
		/// <param name="filePath">The file path of the log file.</param>
		static void SetConfig(bool enabled = false, bool logVerbose = false, const char* filePath = "log.txt");
	};
}
#endif // LOGGER_HPP
