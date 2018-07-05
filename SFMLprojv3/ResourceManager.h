#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

class ResourceManager
{
	Texture cube_texture, killcube_texture, killcube2_texture, tlo_texture, player_texture, bggame_texture;
	//Font font1_font;
	string txt_path;
	enum {base, cube, killcube, killcube2, tlo, player, bggame};
	int whatID(string name);
	void loadTexture();
	void loadFonts();

public:
	ResourceManager();
	Texture *getTexture(string name);
	void loadAll();
};
