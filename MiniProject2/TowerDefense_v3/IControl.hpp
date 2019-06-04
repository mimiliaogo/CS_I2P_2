#ifndef ICONTROL_HPP
#define ICONTROL_HPP
#include <list>
#include <utility>

namespace Engine {
	/// <summary>
	/// The base interface class for controls that needs to process event callbacks.
	/// </summary>
	class IControl {
		friend class Group;
	protected:
		// The iterator of controls linked-list when added to scene.
		// Can make removing controls faster.
		std::list<std::pair<bool, IControl*>>::iterator controlIterator{};
		/// <summary>
		/// The interface cannot be instantiated directly, must be inherited.
		/// </summary>
		explicit IControl() = default;
	public:
		/// <summary>
		/// The default virtual destructor to support polymorphism destruction.
		/// </summary>
		virtual ~IControl() = default;
		/// <summary>
		/// Copy constructor does not add a new instance to scene, they are still the same object.
		/// </summary>
		IControl(const IControl& other) = default;
		/// <summary>
		/// Copy assignment operator does not add a new instance to scene, they are still the same object.
		/// </summary>
		IControl& operator=(IControl const&) = default;
		/// <summary>
		/// Delegated from scene when keyboard key down.
		/// </summary>
		/// <param name="keyCode">The keycode of pressed key.</param>
		virtual void OnKeyDown(int keyCode);
		/// <summary>
		/// Delegated from scene when keyboard key up.
		/// </summary>
		/// <param name="keyCode">The keycode of released key.</param>
		virtual void OnKeyUp(int keyCode);
		/// <summary>
		/// Delegated from scene when mouse button down.
		/// </summary>
		/// <param name="button">The button pressed.</param>
		/// <param name="mx">Mouse x coordinate in window space.</param>
		/// <param name="my">Mouse y coordinate in window space.</param>
		virtual void OnMouseDown(int button, int mx, int my);
		/// <summary>
		/// Delegated from scene when mouse button up.
		/// </summary>
		/// <param name="button">The button released.</param>
		/// <param name="mx">Mouse x coordinate in window space.</param>
		/// <param name="my">Mouse y coordinate in window space.</param>
		virtual void OnMouseUp(int button, int mx, int my);
		/// <summary>
		/// Delegated from scene when mouse move.
		/// </summary>
		/// <param name="mx">Mouse x coordinate in window space.</param>
		/// <param name="my">Mouse y coordinate in window space.</param>
		virtual void OnMouseMove(int mx, int my);
		/// <summary>
		/// Delegated from scene when mouse scroll.
		/// </summary>
		/// <param name="mx">Mouse x coordinate in window space.</param>
		/// <param name="my">Mouse y coordinate in window space.</param>
		/// <param name="delta">Mouse z scroll delta value.</param>
		virtual void OnMouseScroll(int mx, int my, int delta);
	};
}
#endif // ICONTROL_HPP
