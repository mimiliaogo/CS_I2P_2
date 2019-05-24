#include "IObject.hpp"
#include "IControl.hpp"
#include <allegro5/allegro.h>
#include "IScene.hpp"

namespace Engine {
	void IScene::addObject(bool shouldDelete, IObject* obj) {
		objects.emplace_back(shouldDelete, obj);
		obj->objectIterator = objects.end()--;
	}
	void IScene::addControl(bool shouldDelete, IControl* ctrl) {
		controls.emplace_back(shouldDelete, ctrl);
		ctrl->controlIterator = controls.end()--;
	}
	void IScene::insertObject(bool shouldDelete, IObject* obj, std::list<std::pair<bool, IObject*>>::iterator it) {
		objects.emplace(it, shouldDelete, obj);
		obj->objectIterator = objects.end()--;
	}
	void IScene::Terminate() {
		for (auto& it : objects) {
			if (it.first) delete it.second;
		}
		for (auto& it : controls) {
			if (it.first) delete it.second;
		}
	}
	void IScene::Update(float deltaTime) {
		for (auto& it : objects) {
			if (it.second->Visible)
				it.second->Update(deltaTime);
		}
	}
	void IScene::Draw() const {
		al_clear_to_color(al_map_rgb(0, 0, 0));
		for (auto& it : objects) {
			if (it.second->Visible)
				it.second->Draw();
		}
	}
	void IScene::OnKeyDown(int keyCode) {
		for (auto& it : controls)
			it.second->OnKeyDown(keyCode);
	}
	void IScene::OnKeyUp(int keyCode) {
		for (auto& it : controls)
			it.second->OnKeyUp(keyCode);
	}
	void IScene::OnMouseDown(int button, int mx, int my) {
		for (auto& it : controls)
			it.second->OnMouseDown(button, mx, my);
	}
	void IScene::OnMouseUp(int button, int mx, int my) {
		for (auto& it : controls)
			it.second->OnMouseUp(button, mx, my);
	}
	void IScene::OnMouseMove(int mx, int my) {
		for (auto& it : controls)
			it.second->OnMouseMove(mx, my);
	}
	void IScene::OnMouseScroll(int mx, int my, int delta) {
		for (auto& it : controls)
			it.second->OnMouseScroll(mx, my, delta);
	}
	void IScene::RemoveObject(std::list<std::pair<bool, IObject*>>::iterator it) {
		if (it->first) delete it->second;
		objects.erase(it);
	}
	void IScene::RemoveControl(std::list<std::pair<bool, IControl*>>::iterator it) {
		if (it->first) delete it->second;
		controls.erase(it);
	}
	void IScene::RemoveControlObject(std::list<std::pair<bool, IControl*>>::iterator ctrlIt, std::list<std::pair<bool, IObject*>>::iterator objIt) {
		RemoveControl(ctrlIt);
		RemoveObject(objIt);
	}
	void IScene::AddNewObject(IObject* obj) {
		addObject(true, obj);
	}
	void IScene::InsertNewObject(IObject* obj, std::list<std::pair<bool, IObject*>>::iterator it) {
		insertObject(true, obj, it);
	}
	void IScene::AddNewControl(IControl* ctrl) {
		addControl(true, ctrl);
	}
	void IScene::AddNewControlObject(IControl* ctrl) {
		if (!dynamic_cast<IObject*>(ctrl))
			throw std::invalid_argument("The control must inherit both IObject and IControl.");
		addObject(false, dynamic_cast<IObject*>(ctrl));
		addControl(true, ctrl);
	}
	void IScene::AddRefObject(IObject& obj) {
		addObject(false, &obj);
	}
	void IScene::InsertRefObject(IObject& obj, std::list<std::pair<bool, IObject*>>::iterator it) {
		insertObject(false, &obj, it);
	}
	void IScene::AddRefControl(IControl& ctrl) {
		addControl(false, &ctrl);
	}
	void IScene::AddRefControlObject(IControl& ctrl) {
		if (!dynamic_cast<IObject*>(&ctrl))
			throw std::invalid_argument("The control must inherit both IObject and IControl.");
		addObject(false, dynamic_cast<IObject*>(&ctrl));
		addControl(false, &ctrl);
	}
}
