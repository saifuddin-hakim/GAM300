#include "Input.h"

namespace TDS
{
	Input::keyboardInputMap Input::keyboard;
	Input::mouseInputMap	Input::mouse;

	Input::keyState Input::GetKeyState(uint32_t keycode)
	{
		return keyboard.keys[keycode];
	}
	bool Input::isKeyPressed(uint32_t keycode)
	{
		return keyboard.keys[keycode].isDown;
	}
	bool Input::isKeyReleased(uint32_t keycode)
	{
		return !keyboard.keys[keycode].isDown;
	}
	bool Input::isMouseScrollUp()
	{
		return mouse.buttons[TDS_MOUSE_SCROLL].isScrollUp;
	}
	bool Input::isMouseScrollDown()
	{
		return mouse.buttons[TDS_MOUSE_SCROLL].isScrollDown;
	}
	bool Input::wasKeyHit(uint32_t keycode) //check if key has just been pressed
	{
		return (!keyboard.keys[keycode].wasDown) && keyboard.keys[keycode].isDown;
	}

	void Input::processKeyboardInput(uint32_t VKcode, bool wasDown, bool isDown)
	{
		if (wasDown != isDown) // if there is a change in state of keys
		{
			if (VKcode >= 'A' && VKcode <= 'Z')
			{
				uint32_t TDCkeycode = VKcode - 'A';
				keyboard.keys[TDCkeycode].isDown = isDown;
				keyboard.keys[TDCkeycode].wasDown = wasDown;
			}

			else if (VKcode == VK_UP)
			{
				keyboard.keys[TDS_UP].isDown = isDown;
				keyboard.keys[TDS_UP].wasDown = wasDown;
			}

			else if (VKcode == VK_DOWN)
			{
				keyboard.keys[TDS_DOWN].isDown = isDown;
				keyboard.keys[TDS_DOWN].wasDown = wasDown;
			}

			else if (VKcode == VK_LEFT)
			{
				keyboard.keys[TDS_LEFT].isDown = isDown;
				keyboard.keys[TDS_LEFT].wasDown = wasDown;
			}

			else if (VKcode == VK_RIGHT)
			{
				keyboard.keys[TDS_RIGHT].isDown = isDown;
				keyboard.keys[TDS_RIGHT].wasDown = wasDown;
			}

			else if (VKcode >= '0' && VKcode <= '9')
			{
				uint32_t TDS_keycode = VKcode - '0' + TDS_0;
				keyboard.keys[TDS_keycode].isDown = isDown;
				keyboard.keys[TDS_keycode].wasDown = wasDown;
			}

			else if (VKcode == VK_OEM_MINUS)
			{
				keyboard.keys[TDS_MINUS].isDown = isDown;
				keyboard.keys[TDS_MINUS].wasDown = wasDown;
			}

			else if (VKcode == VK_OEM_PLUS)
			{
				keyboard.keys[TDS_PLUS].isDown = isDown;
				keyboard.keys[TDS_PLUS].wasDown = wasDown;
			}

			else if (VKcode == VK_SHIFT)
			{
				keyboard.keys[TDS_SHIFT].isDown = isDown;
				keyboard.keys[TDS_SHIFT].wasDown = wasDown;
			}

			else if (VKcode == VK_CONTROL)
			{
				keyboard.keys[TDS_CONTROL].isDown = isDown;
				keyboard.keys[TDS_CONTROL].wasDown = wasDown;
			}

			else if (VKcode == VK_MENU)
			{
				keyboard.keys[TDS_ALT].isDown = isDown;
				keyboard.keys[TDS_ALT].wasDown = wasDown;
			}

			else if (VKcode == VK_SPACE)
			{
				keyboard.keys[TDS_SPACE].isDown = isDown;
				keyboard.keys[TDS_SPACE].wasDown = wasDown;
			}

			else if (VKcode == VK_ESCAPE)
			{
				keyboard.keys[TDS_ESCAPE].isDown = isDown;
				keyboard.keys[TDS_ESCAPE].wasDown = wasDown;
			}

			else if (VKcode == VK_CAPITAL)
			{
				keyboard.keys[TDS_CAPSLOCK].isDown = isDown;
				keyboard.keys[TDS_CAPSLOCK].wasDown = wasDown;
			}

			else if (VKcode == VK_TAB)
			{
				keyboard.keys[TDS_TAB].isDown = isDown;
				keyboard.keys[TDS_TAB].wasDown = wasDown;
			}

			else if (VKcode == VK_RETURN)
			{
				keyboard.keys[TDS_ENTER].isDown = isDown;
				keyboard.keys[TDS_ENTER].wasDown = wasDown;
			}

			else if (VKcode == VK_BACK)
			{
				keyboard.keys[TDS_BACKSPACE].isDown = isDown;
				keyboard.keys[TDS_BACKSPACE].wasDown = wasDown;
			}

			else if (VKcode == VK_OEM_3)
			{
				keyboard.keys[TDS_TILDE].isDown = isDown;
				keyboard.keys[TDS_TILDE].wasDown = wasDown;
			}

			else if (VKcode == VK_OEM_COMMA)
			{
				keyboard.keys[TDS_COMMA].isDown = isDown;
				keyboard.keys[TDS_COMMA].wasDown = wasDown;
			}

			else if (VKcode == VK_OEM_PERIOD)
			{
				keyboard.keys[TDS_PERIOD].isDown = isDown;
				keyboard.keys[TDS_PERIOD].wasDown = wasDown;
			}

			else if (VKcode == VK_OEM_2)
			{
				keyboard.keys[TDS_SLASH].isDown = isDown;
				keyboard.keys[TDS_SLASH].wasDown = wasDown;
			}

			else if (VKcode == VK_OEM_1)
			{
				keyboard.keys[TDS_SEMICOLON].isDown = isDown;
				keyboard.keys[TDS_SEMICOLON].wasDown = wasDown;
			}

		}
	}

	Input::mousePosition Input::getMousePosition()
	{
		return mouse.position;
	}

	bool Input::isMouseButtonPressed(unsigned int buttonCode)
	{
		return mouse.buttons[buttonCode].isDown;
	}

	bool Input::isMouseButtonReleased(unsigned int buttonCode)
	{
		return !mouse.buttons[buttonCode].isDown;
	}

	bool Input::wasMouseButtonHit(unsigned int buttonCode)
	{
		return (!mouse.buttons[buttonCode].wasDown) && mouse.buttons[buttonCode].isDown;
	}

	void Input::processMouseInput(WPARAM wParam, LPARAM lParam)
	{
		mouse.buttons[TDS_MOUSE_LEFT].wasDown = mouse.buttons[TDS_MOUSE_LEFT].isDown;
		mouse.buttons[TDS_MOUSE_RIGHT].wasDown = mouse.buttons[TDS_MOUSE_RIGHT].isDown;
		mouse.buttons[TDS_MOUSE_MIDDLE].wasDown = mouse.buttons[TDS_MOUSE_MIDDLE].isDown;
		mouse.buttons[TDS_MOUSE_X1].wasDown = mouse.buttons[TDS_MOUSE_X1].isDown;
		mouse.buttons[TDS_MOUSE_X2].wasDown = mouse.buttons[TDS_MOUSE_X2].isDown;

		mouse.buttons[TDS_MOUSE_LEFT].isDown = wParam & MK_LBUTTON;
		mouse.buttons[TDS_MOUSE_RIGHT].isDown = wParam & MK_RBUTTON;
		mouse.buttons[TDS_MOUSE_MIDDLE].isDown = wParam & MK_MBUTTON;
		mouse.buttons[TDS_MOUSE_X1].isDown = wParam & MK_XBUTTON1;
		mouse.buttons[TDS_MOUSE_X2].isDown = wParam & MK_XBUTTON2;
		
		updateMousePosition(lParam);

	}

	void Input::processMouseScroll(WPARAM _wParam)
	{
		if (GET_WHEEL_DELTA_WPARAM(_wParam) > 0)
		{
			mouse.buttons[TDS_MOUSE_SCROLL].isScrollUp = true;
			mouse.buttons[TDS_MOUSE_SCROLL].isScrollDown = false;
		}
		else
		{
			mouse.buttons[TDS_MOUSE_SCROLL].isScrollDown = true;
			mouse.buttons[TDS_MOUSE_SCROLL].isScrollUp = false;
		}
	}

	void Input::updateMousePosition(LPARAM lParam)
	{
		//macros that return current position of the cursor relative to the application
		mouse.position.x = GET_X_LPARAM(lParam);
		mouse.position.y = GET_Y_LPARAM(lParam);
	}

	void Input::scrollStop()
	{
	
		mouse.buttons[TDS_MOUSE_SCROLL].isScrollDown = false;
		mouse.buttons[TDS_MOUSE_SCROLL].isScrollUp = false;
	}



} //end of namespace