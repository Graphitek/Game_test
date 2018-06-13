#pragma once
#include "SFML\Graphics.hpp"

using namespace sf;

class Menu
{
public:
	int fontsize, bigfontsize;
	float WindowX, WindowY;
	Font font;
	int whatclicked();
	Menu(float WindowX, float WindowY);
	void draw(RenderWindow &okno);
	void MoveUp();
	void MoveDown();
	bool MenuState();
	void setMenuState(bool state);
	void setMenuPos(float pos);
	bool firstRun();
	void setfirstRun(bool state);
	void setFirstString(String name);

protected:
	int selected, ileopcji;
	float oldpos;
	Sprite bg;
	Texture tlo;
	void setPos();
private:

	bool MenuIsOn, firstrun;

	Vector2f pos[5];
	//float lpos;

	Text text[5];
};

/*class TopResults : public Menu
{

};
*/