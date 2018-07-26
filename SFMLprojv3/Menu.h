#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace sf;
using namespace std;

class MenuBase
{
public:
	MenuBase();
	int whatclicked();
	int fontsize, bigfontsize;
	int iterindex;
	float WindowX, WindowY;
	Font font;
	void draw(RenderWindow &okno);
	void MoveUp();
	void MoveDown();
	bool MenuState();
	void setMenuState(bool state);
	void setCertainString(string zawartosc, int index);
	void setMenuPos(float pos);
	string do_2(double liczba);
	string do_3(double liczba);

protected:
	int selected, ileopcji, selectedMin, selectedMax;
	Sprite bg;
	Texture tlo;// robi siê kopia przezucic do menagera 
	void setPos(float x);
	vector<Vector2f> poslist;
	vector<Text> text;
	bool MenuIsOn;
	float oldpos;
	float startPos;
	string czas;

};

class Menu : public MenuBase
{
public:
	Menu(float WindowX, float WindowY);
	bool firstRun();
	void setfirstRun(bool state);
	void setFirstString(String name);

private:
	bool firstrun;
};

class TopResults : public MenuBase
{
	fstream top;
	std::string resultpath, tresc, temp;
	std::vector<std::string> results_s;
	std::vector <float> results_f;
	float worstResult;
	int iter, visibleresults;

public:
	TopResults(float WindowX, float WindowY);
	void saveresult(string result);
	void getresults();
	void refreshLeaderboards();
	void refreshLeaderboards2();
	void refreshAllLb();
	void clearResults();
	bool newResult(float result);
};

class EnterNick : public MenuBase
{
	string nick;

public:
	EnterNick(float WindowX, float WindowY); // raczej mo¿na zmieniæ bez windowX i y
	string getNick();
	void dataEnter(RenderWindow &okno, Event &event);
};
