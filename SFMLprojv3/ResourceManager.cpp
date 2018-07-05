#include "stdafx.h"

ResourceManager::ResourceManager() :
	txt_path(Game::txt_path)
{
	loadAll();
}

void ResourceManager::loadTexture()
{
	if (cube_texture.loadFromFile(txt_path + "gradientblackv2.png")) { cout << "Zaladowano\n"; };
	if (killcube2_texture.loadFromFile(txt_path + "killgradientblackv2.png")) { cout << "Zaladowano\n"; };
	if (killcube_texture.loadFromFile(txt_path + "killgradientblackv6.png")) { cout << "Zaladowano\n"; };
	//if (tlo_texture.loadFromFile(txt_path + "bgmenu.jpg")) { cout << "Zaladowano\n"; };
	if (player_texture.loadFromFile(txt_path + "square.jpg")) { cout << "Zaladowano\n"; };
	if (bggame_texture.loadFromFile(txt_path + "bggamefinal.png")) { cout << "Zaladowano\n"; };

}

void ResourceManager::loadFonts()
{
	//if (font1_font.loadFromFile(Game::font_path + "IndieFlower.ttf"));
}

void ResourceManager::loadAll()
{
	loadTexture();
	loadFonts();
}

int ResourceManager::whatID(string name)
{
	if (name == "gradientblackv2.png")
	{
		return 1;
	}
	if (name == "killgradientblackv2.png")
	{
		return 2;
	}
	if (name == "killgradientblackv6.png")
	{
		return 3;
	}
	/*if (name == "bgmenu.jpg")
	{
		return 4;
	}*/
	if (name == "square.jpg")
	{
		return 5;
	}
	if (name == "bggamefinal.png")
	{
		return 6;
	}
	return 0;
}

Texture *ResourceManager::getTexture(string name)
{
	switch (whatID(name))
	{
	case base:
		throw Game::NoTexture;
	case cube:
		return &cube_texture;
	case killcube:
		return &killcube_texture;
	case killcube2:
		return &killcube2_texture;
	case tlo:
		return &tlo_texture;
	case player:
		return &player_texture;
	case bggame:
		return &bggame_texture;
	}
}