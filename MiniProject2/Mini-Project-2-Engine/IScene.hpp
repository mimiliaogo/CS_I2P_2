#ifndef ISCENE_HPP
#define ISCENE_HPP
#include <list>
#include "IObject.hpp"
#include "IControl.hpp"

namespace Engine {
	/// <summary>
	/// This class should be inherited whenever you want to define a new scene.
	/// Responsible for delegating draw, update, events to the objects and controls in scene.
	/// Acts like a prototype, so all initialize and terminate shouldn't be put in constructor or destructor.
	/// </summary>
	class IScene {
	private:
		// Stores all object pointers in the scene.
		// The first boolean indicates whether the scene should delete it.
		std::list<std::pair<bool, IObject*>> objects;
		// Stores all control pointers in the scene.
		// The first boolean indicates whether the scene should delete it.
		std::list<std::pair<bool, IControl*>> controls;
		// Note: Using linked-list and inline-new might cause some serious cache misses,
		//       however this implementation brings us more convenience than the impact
		//       on performance. Trying to deal with cache misses requires complicated code,
		//       so we'll just ignore it for simplicity.
	protected:
		/// <summary>
		/// The interface cannot be instantiated directly, must be inherited.
		/// </summary>
		explicit IScene() = default;
		/// <summary>
		/// Add Object to scene.
		/// </summary>
		/// <param name="shouldDelete">Indicates whether the scene handle the Object deletion for you.</param>
		/// <param name="obj">The Object to add.</param>
		void addObject(bool shouldDelete, IObject* obj);
		/// <summary>
		/// Add Control to scene.
		/// </summary>
		/// <param name="shouldDelete">Indicates whether the scene handle the Control deletion for you.</param>
		/// <param name="ctrl">The Control to add.</param>
		void addControl(bool shouldDelete, IControl* ctrl);
		/// <summary>
		/// Insert Object to scene before the iterator.
		/// </summary>
		/// <param name="shouldDelete">Indicates whether the scene handle the deletion for you.</param>
		/// <param name="obj">The Object to insert.</param>
		/// <param name="it">The iterator that the object should insert before.</param>
		void insertObject(bool shouldDelete, IObject* obj, std::list<std::pair<bool, IObject*>>::iterator it);
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
		/// Run game logic such as updating the world, checking for collision, and so on.
		/// This is called when the game should update its logic, usually 'fps' times per second.
		/// Delegate the update event to all visible objects.
		/// </summary>
		/// <param name="deltaTime">Time elapsed since last update, can be used to calculate value changes.</param>
		virtual void Update(float deltaTime);
		/// <summary>
		/// Draw to window display.
		/// This is called when the game should redraw the window.
		/// Delegate the draw event to all visible objects.
		/// </summary>
		virtual void Draw() const;
		/// <summary>
		/// Delegate the key down event to all controls.
		/// </summary>
		/// <param name="keyCode">The keycode of pressed key.</param>
		virtual void OnKeyDown(int keyCode);
		/// <summary>
		/// Delegate the key up event to all controls.
		/// </summary>
		/// <param name="keyCode">The keycode of released key.</param>
		virtual void OnKeyUp(int keyCode);
		/// <summary>
		/// Delegate the mouse key down event to all controls.
		/// </summary>
		/// <param name="button">The button pressed.</param>
		/// <param name="mx">Mouse x coordinate in window space.</param>
		/// <param name="my">Mouse y coordinate in window space.</param>
		virtual void OnMouseDown(int button, int mx, int my);
		/// <summary>
		/// Delegate the mouse key up event to all controls.
		/// </summary>
		/// <param name="button">The button released.</param>
		/// <param name="mx">Mouse x coordinate in window space.</param>
		/// <param name="my">Mouse y coordinate in window space.</param>
		virtual void OnMouseUp(int button, int mx, int my);
		/// <summary>
		/// Delegate the mouse move event to all controls.
		/// </summary>
		/// <param name="mx">Mouse x coordinate in window space.</param>
		/// <param name="my">Mouse y coordinate in window space.</param>
		virtual void OnMouseMove(int mx, int my);
		/// <summary>
		/// Delegate the mouse scroll event to all controls.
		/// </summary>
		/// <param name="mx">Mouse x coordinate in window space.</param>
		/// <param name="my">Mouse y coordinate in window space.</param>
		/// <param name="delta">Mouse z scroll delta value.</param>
		virtual void OnMouseScroll(int mx, int my, int delta);
		/// <summary>
		/// Remove the Object from this scene.
		/// </summary>
		/// <param name="it">The iterator of the Object.</param>
		void RemoveObject(std::list<std::pair<bool, IObject*>>::iterator it);
		/// <summary>
		/// Remove the Control from this scene.
		/// </summary>
		/// <param name="it">The iterator of the Control.</param>
		void RemoveControl(std::list<std::pair<bool, IControl*>>::iterator it);
		/// <summary>
		/// Remove the ControlObject from this scene.
		/// </summary>
		/// <param name="ctrlIt">The iterator of the Control.</param>
		/// <param name="objIt">The iterator of the Object.</param>
		void RemoveControlObject(std::list<std::pair<bool, IControl*>>::iterator ctrlIt, std::list<std::pair<bool, IObject*>>::iterator objIt);
		/// <summary>
		/// Add Object to scene.
		/// Use inline-new when adding Object in order to support polymorphism,
		/// The added objects will be deleted by Scene at remove or terminate.
		/// </summary>
		/// <param name="obj">The Object to add.</param>
		void AddNewObject(IObject* obj);
		/// <summary>
		/// Insert Object to scene before the iterator.
		/// Use inline-new when adding Object in order to support polymorphism,
		/// The added objects will be deleted by Scene at remove or terminate.
		/// </summary>
		/// <param name="obj">The Object to insert.</param>
		/// <param name="it">The iterator that the object should insert before.</param>
		void InsertNewObject(IObject* obj, std::list<std::pair<bool, IObject*>>::iterator it);
		/// <summary>
		/// Add Control to scene.
		/// Use inline-new when adding Control in order to support polymorphism,
		/// The added controls will be deleted by Scene at remove or terminate.
		/// </summary>
		/// <param name="ctrl">The Control to add.</param>
		void AddNewControl(IControl* ctrl);
		/// <summary>
		/// Add ControlObject to scene.
		/// Use inline-new when adding ControlObject in order to support polymorphism,
		/// ControlObject means classes that inherit both Control and Object. (e.g. buttons)
		/// </summary>
		/// <param name="ctrl">The ControlObject to add.</param>
		void AddNewControlObject(IControl* ctrl);
		/// <summary>
		/// Add Object to scene.
		/// Use reference when adding Object. Make sure it won't be deconstructed due to out-of-scope.
		/// The added objects will not be deleted by Scene at remove or terminate.
		/// </summary>
		/// <param name="obj">The Object to add.</param>
		void AddRefObject(IObject& obj);
		/// <summary>
		/// Insert Object to scene before the iterator.
		/// Use reference when adding Object. Make sure it won't be deconstructed due to out-of-scope.
		/// The added objects will not be deleted by Scene at remove or terminate.
		/// </summary>
		/// <param name="obj">The Object to insert.</param>
		/// <param name="it">The iterator that the object should insert before.</param>
		void InsertRefObject(IObject& obj, std::list<std::pair<bool, IObject*>>::iterator it);
		/// <summary>
		/// Add Control to scene.
		/// Use reference when adding Control. Make sure it won't be deconstructed due to out-of-scope.
		/// The added controls will not be deleted by Scene at remove or terminate.
		/// </summary>
		/// <param name="ctrl">The Control to add.</param>
		void AddRefControl(IControl& ctrl);
		/// <summary>
		/// Add ControlObject to scene.
		/// Use reference when adding ControlObject. Make sure it won't be deconstructed due to out-of-scope.
		/// The added ControlObjects will not be deleted by Scene at remove or terminate.
		/// </summary>
		/// <param name="ctrl">The ControlObject to add.</param>
		void AddRefControlObject(IControl& ctrl);
	};
}
#endif // ISCENE_HPP
