#include "stdafx.h"

void Menu::setPos()
{
	for (int i = 0; i < ileopcji; i++)
	{
		pos[i] = Vector2f(WindowX / 2, WindowY*(i + 0.5) / (ileopcji + 1));
	}
}

Menu::Menu(float WindowX, float WindowY) :
	MenuIsOn(1),
	firstrun(1),
	fontsize(40),
	bigfontsize(60),
	ileopcji(5),
	oldpos(WindowX/2),
	bg(),
	tlo()
{
	this->WindowX = WindowX;
	this->WindowY = WindowY;
	setPos();

	if (!tlo.loadFromFile(Game::txt_path + "bgmenu.jpg")) { throw Game::NoTexture; };
	bg.setOrigin(WindowX/2,WindowY/2);
	bg.setPosition(WindowX / 2, WindowY / 2);
	bg.setColor(Color(255, 255, 255, 200));
	bg.setTexture(tlo);

	if (!font.loadFromFile(Game::font_path + "IndieFlower.ttf")) { throw Game::NoTexture; };
	text[0].setFont(font);
	text[0].setString("Play");
	text[0].setCharacterSize(bigfontsize);
	text[0].setFillColor(Color::Red);
	text[0].setOrigin(text[0].getGlobalBounds().width / 2, text[0].getGlobalBounds().height / 2);
	text[0].setPosition(pos[0]);

	text[1].setFont(font);
	text[1].setString("Save");
	text[1].setCharacterSize(fontsize);
	text[1].setFillColor(Color::Yellow);
	text[1].setOrigin(text[1].getGlobalBounds().width / 2, text[1].getGlobalBounds().height / 2);
	text[1].setPosition(pos[1]);

	text[2].setFont(font);
	text[2].setString("Load");
	text[2].setCharacterSize(fontsize);
	text[2].setFillColor(Color::Yellow);
	text[2].setOrigin(text[2].getGlobalBounds().width / 2, text[2].getGlobalBounds().height / 2);
	text[2].setPosition(pos[2]);

	text[3].setFont(font);
	text[3].setString("Options");
	text[3].setCharacterSize(fontsize);
	text[3].setFillColor(Color::Yellow);
	text[3].setOrigin(text[3].getGlobalBounds().width / 2, text[3].getGlobalBounds().height / 2);
	text[3].setPosition(pos[3]);

	text[4].setFont(font);
	text[4].setString("Exit");
	text[4].setCharacterSize(fontsize);
	text[4].setFillColor(Color::Yellow);
	text[4].setOrigin(text[4].getGlobalBounds().width / 2, text[4].getGlobalBounds().height / 2);
	text[4].setPosition(pos[4]);

	selected = 0;
}

void Menu::MoveUp()
{
	if (selected - 1 >= 0)
	{
		text[selected].setFillColor(Color::Yellow);
		text[selected].setCharacterSize(fontsize);
		text[selected].setOrigin(text[selected].getGlobalBounds().width / 2, text[selected].getGlobalBounds().height / 2);
		text[selected].setPosition(pos[selected]);

		text[selected - 1].setFillColor(Color::Red);
		text[selected - 1].setCharacterSize(bigfontsize);
		text[selected - 1].setOrigin(text[selected - 1].getGlobalBounds().width / 2, text[selected - 1].getGlobalBounds().height / 2);
		text[selected - 1].setPosition(pos[selected - 1]);

		selected--;
	}
}

void Menu::MoveDown()
{
	if (selected + 1 < ileopcji)
	{
		text[selected].setFillColor(Color::Yellow);
		text[selected].setCharacterSize(fontsize);
		text[selected].setOrigin(text[selected].getGlobalBounds().width / 2, text[selected].getGlobalBounds().height / 2);
		text[selected].setPosition(pos[selected]);

		text[selected + 1].setFillColor(Color::Red);
		text[selected + 1].setCharacterSize(bigfontsize);
		text[selected + 1].setOrigin(text[selected + 1].getGlobalBounds().width / 2, text[selected + 1].getGlobalBounds().height / 2);
		text[selected + 1].setPosition(pos[selected + 1]);

		selected++;
	}
}

int Menu::whatclicked()
{
	return selected;
}

bool Menu::MenuState()
{
	return MenuIsOn;
}

void Menu::setMenuState(bool state)
{
	MenuIsOn = state;
}

void Menu::draw(RenderWindow &okno) 
{
	okno.draw(bg);
	for (auto &menu : text)
	{
		okno.draw(menu);
	}
}

void Menu::setMenuPos(float pos)
{
	if (oldpos != pos)
	{
		//for (auto &menu : text)
		for (int i = 0; i < ileopcji; i++)
		{
			//menu.move(Vector2f(pos - oldpos, 0));
			text[i].move(Vector2f(pos - oldpos, 0));
			this->pos[i] = Vector2f(pos, this->pos[i].y);//zamiast setowania zrobiæ funkcje obliczajaca boundboxa big text and small
		}
		bg.move(Vector2f(pos - oldpos, 0));
		oldpos = pos;
	}
}

bool Menu::firstRun()
{
	return firstrun;
}

void Menu::setfirstRun(bool state)
{
	firstrun = state;
}

void Menu::setFirstString(String name)
{
	text[0].setString(name);
}