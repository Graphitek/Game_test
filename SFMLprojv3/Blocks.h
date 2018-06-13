#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Blocks
{

public:
	bool colision_top(FloatRect otherbox);
	bool colision_bottom(FloatRect otherbox);
	bool colision_left(FloatRect otherbox);
	bool colision_right(FloatRect otherbox);
	bool colision_total(FloatRect otherbox);
	void getPoints();
	//bool lasttop, lastbottom, lastleft, lastright, lasttotal; //testujemy any w blocks (teraz last) // doda³eœ do kolizji ale nie wytestowa³eœ w world
	Blocks();
	//void draw(RenderTarget &target, RenderStates state)const override;

protected:
	Vector2f size;
	Vector2f pointA, pointB;
	std::vector <RectangleShape> shape;
	FloatRect colbox;
	void setBasic(Texture &texture);
	static float wspolczynnikDoskonalosciA;
	static float wspolczynnikDoskonalosciB;

public:
	FloatRect getColBox();
};

class Cube : public Blocks, public Drawable
{
protected:
public:
	Cube();
	Cube(float posX, float posY, Texture &texture, Color &color);
	Cube(int ile_width, int ile_hight, float posX, float posY, Texture &texture, Color color);

	//void setSize(int id, int width, int hight);

	void draw(RenderTarget &target, RenderStates state)const override;
};

class WinCube : public Blocks
{
	RectangleShape winshape;

public:
	//WinCube();
	WinCube(int width, int height, float posX, float posY);
};

class KillCube : public Cube
{
public:
	//KillCube();
	KillCube(int ile_width, int ile_hight, float posX, float posY, Texture &texture, Color color);
};

