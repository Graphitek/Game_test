#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player : public Drawable
{
	float WindowX, WindowY;
	bool inAir;
	float V, rightSpeed, leftSpeed;
	Vector2f size, pos, Vjump, Vmove;
	RectangleShape shape;
	FloatRect boundingbox;

	//float Top_Cube, Left_Cube, Right_Cube, Bottom_Cube;

public:

	Player(float WindowX, float WindowY);
	float SgravityForce, SjumpForce;
	float gravityForce, jumpForce;
	float Vstart;
	void jump();
	void move();
	void gravity();
	void update();
	Vector2f top();
	Vector2f bottom();
	Vector2f left();
	Vector2f right();
	void resetmovespeed();
	void moveLeft();
	void moveRight();

	void setInAir(bool set);
	void setsize(Vector2f size);
	void setpos(Vector2f pos);
	void setstartgravityforce(float force);
	void setgravityforce(float force);
	void setstartjumpforce(float force);
	void setstartspeed(float speed);
	void setcolor(Color test);
	void setTexture(Texture &texture); //txt test
	void setFrame(float width, Color color);
	void setHorizontalSpeed(float speed);
	void setVerticalSpeed(float speed);
	void setLeftSpeed(float speed);
	void setRightSpeed(float speed);

	Vector2f getpos();
	Vector2f getspeed();
	FloatRect getBoundingBox();

	void draw(RenderTarget &target, RenderStates state)const override;

	/*void setTop_Cube();
	void resetTop_Cube();
	void setLeft_Cube();
	void resetLeft_Cube();
	void setRight_Cube();
	void resetRight_Cube();
	void setBottom_Cube();
	void resetBottom_Cube();*/
};