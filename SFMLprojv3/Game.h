#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
//#include <thread>
//#include <mutex>
#include "Player.h"
#include "Menu.h"
#include "World.h"

using namespace sf;

class Game
{
private:
	float WhereIsViewX;
	Vector2f playerStartPos;
	bool lose, win;
	RenderWindow okno;
	Player player;
	View view;
	Menu menu;
	Text pausemessage;
	Text info;
	Texture player_texture;
	Texture bggame_texture;
	RectangleShape bggame, bggame2;
	World world;

	Clock clock;
	Time rtime;

private:
	void trackview();
	void youlose();
	void youwin();
	void reset();
	void RoundTime();

	void bggamemove();

public:
	Game();
	void run();
	std::string do_2(double liczba);
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

	//void RenderThred();
	void draw();
};
