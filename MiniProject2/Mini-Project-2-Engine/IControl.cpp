#include "IControl.hpp"

namespace Engine {
	void IControl::OnKeyDown(int keyCode) {}
	void IControl::OnKeyUp(int keyCode) {}
	void IControl::OnMouseDown(int button, int mx, int my) {}
	void IControl::OnMouseUp(int button, int mx, int my) {}
	void IControl::OnMouseMove(int mx, int my) {}
	void IControl::OnMouseScroll(int mx, int my, int delta) {}
}
