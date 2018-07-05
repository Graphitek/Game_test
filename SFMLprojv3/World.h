#pragma once
#include "Blocks.h"
#include "Player.h"
#include "ResourceManager.h"
#include <iostream>

class World
{
	Texture *cube_txt, *killcube_txt, *killcube2_txt;
	std::vector <Cube> cubes;
	std::vector <WinCube> wincubes;
	std::vector <KillCube> killcubes;
	bool anytop, anybottom, anyleft, anyright, any_total;
	bool youwin, youlose;
public:
	World(String path, ResourceManager *manager);
	void draw(RenderWindow &window);
	void setCubes();
	//void colision(FloatRect otherbox);
	void colision(Player &player);
	bool YouWin();
	bool YouLose();
	void resetWin();
	void resetLose();

	float startpos;

};