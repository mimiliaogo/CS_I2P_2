#ifndef ISCENE_HPP
#define ISCENE_HPP

#include "Group.hpp"

namespace Engine {
	/// <summary>
	/// This class should be inherited whenever you want to define a new scene.
	/// Responsible for delegating draw, update, events to the objects and controls in scene.
	/// Acts like a prototype, so all initialize and terminate shouldn't be put in constructor or destructor.
	/// </summary>
	class IScene: public Group {
	protected:
		/// <summary>
		/// The interface cannot be instantiated directly, must be inherited.
		/// </summary>
		explicit IScene() = default;
	public:
		/// <summary>
		/// Copy constructor is deleted, no copying allowed.
		/// </summary>
		IScene(IScene const&) = delete;
		/// <summary>
		/// Copy assignment operator is deleted, no copy assignment allowed.
		/// </summary>
		IScene& operator=(IScene const&) = delete;
		/// <summary>
		/// The default virtual destructor to support polymorphism destruction.
		/// </summary>
		virtual ~IScene() = default;
		/// <summary>
		/// Put all initialize code here instead of constructor to make change scene more simple.
		/// </summary>
		virtual void Initialize() = 0;
		/// <summary>
		/// Put all terminate code here instead of destructor to make change scene more simple.
		/// </summary>
		virtual void Terminate();
		/// <summary>
		/// Draw to window display.
		/// This is called when the game should redraw the window.
		/// Delegate the draw event to all visible objects.
		/// </summary>
		void Draw() const override;
	};
}
#endif // ISCENE_HPP
