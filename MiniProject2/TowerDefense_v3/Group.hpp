#ifndef GROUP_HPP
#define GROUP_HPP
#include <list>
#include <utility>

#include "IControl.hpp"
#include "IObject.hpp"

namespace Engine {
	/// <summary>
	/// A ControlObject Group that can contain other objects or controls.
	/// </summary>
	class Group: public IObject, public IControl {
	protected:
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
		/// Create an empty group.
		/// </summary>
		explicit Group() = default;
		/// <summary>
		/// Copy constructor is deleted, no copying allowed.
		/// </summary>
		Group(Group const&) = delete;
		/// <summary>
		/// Copy assignment operator is deleted, no copy assignment allowed.
		/// </summary>
		Group& operator=(Group const&) = delete;
		/// <summary>
		/// The default virtual destructor to support polymorphism destruction.
		/// </summary>
		virtual ~Group();
		/// <summary>
		/// Remove all children (objects and controls).
		/// </summary>
		void Clear();
		/// <summary>
		/// Run game logic such as updating the world, checking for collision, and so on.
		/// This is called when the game should update its logic, usually 'fps' times per second.
		/// Delegate the update event to all visible objects.
		/// </summary>
		/// <param name="deltaTime">Time elapsed since last update, can be used to calculate value changes.</param>
		void Update(float deltaTime) override;
		/// <summary>
		/// Draw to window display.
		/// This is called when the game should redraw the window.
		/// Delegate the draw event to all visible objects.
		/// </summary>
		void Draw() const override;
		/// <summary>
		/// Delegate the key down event to all controls.
		/// </summary>
		/// <param name="keyCode">The keycode of pressed key.</param>
		void OnKeyDown(int keyCode) override;
		/// <summary>
		/// Delegate the key up event to all controls.
		/// </summary>
		/// <param name="keyCode">The keycode of released key.</param>
		void OnKeyUp(int keyCode) override;
		/// <summary>
		/// Delegate the mouse key down event to all controls.
		/// </summary>
		/// <param name="button">The button pressed.</param>
		/// <param name="mx">Mouse x coordinate in window space.</param>
		/// <param name="my">Mouse y coordinate in window space.</param>
		void OnMouseDown(int button, int mx, int my) override;
		/// <summary>
		/// Delegate the mouse key up event to all controls.
		/// </summary>
		/// <param name="button">The button released.</param>
		/// <param name="mx">Mouse x coordinate in window space.</param>
		/// <param name="my">Mouse y coordinate in window space.</param>
		void OnMouseUp(int button, int mx, int my) override;
		/// <summary>
		/// Delegate the mouse move event to all controls.
		/// </summary>
		/// <param name="mx">Mouse x coordinate in window space.</param>
		/// <param name="my">Mouse y coordinate in window space.</param>
		void OnMouseMove(int mx, int my) override;
		/// <summary>
		/// Delegate the mouse scroll event to all controls.
		/// </summary>
		/// <param name="mx">Mouse x coordinate in window space.</param>
		/// <param name="my">Mouse y coordinate in window space.</param>
		/// <param name="delta">Mouse z scroll delta value.</param>
		void OnMouseScroll(int mx, int my, int delta) override;
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
		/// <summary>
		/// Get all objects.
		/// </summary>
		/// <returns>A linked-list of all objects contained.</returns>
		std::list<IObject*> GetObjects();
		/// <summary>
		/// Get all controls.
		/// </summary>
		/// <returns>A linked-list of all controls contained.</returns>
		std::list<IControl*> GetControls();
	};
}
#endif // GROUP_HPP
