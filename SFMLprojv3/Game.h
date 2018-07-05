#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <string>
//#include <thread>
//#include <mutex>
#include "ResourceManager.h"
#include "Player.h"
#include "Menu.h"
#include "World.h"

using namespace sf;

class Game
{
private:
	float WhereIsViewX;
	std::string result;
	Vector2f playerStartPos;
	bool lose, win;
	RenderWindow okno;
	Player player;
	View view;
	Menu menu;
	Text pausemessage;
	Text info;
	RectangleShape bggame, bggame2;
	World world;
	TopResults results;
	ResourceManager manager;

	Clock clock;
	Time rtime;

private:
	void trackview();
	void youlose();
	void youwin();
	void reset();
	void RoundTime();
	void gamerunning();
	void bggamemove();
	void moveMenus();

public:
	Game();
	void run();
	std::string do_2(double liczba);
	std::string do_3(double liczba);
	std::string czas;

	static Vector2f playerStartSize;
	static Vector2f totalplayerStartSize;
	static float playerFrameSize , playerXsize,playerYsize;
	static String path;
	static String txt_path;
	static String font_path;
	static float WindowX, WindowY;
	static float startSpeed, startGravityforce, startJumpforce;
	static float framelimit;
	static int frameMultiplayer;
	static std::string NoTexture;
	static std::string FileError;

	//void RenderThred();
};
