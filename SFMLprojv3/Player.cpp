#include "stdafx.h"

Player::Player(float WindowX, float WindowY) :
	inAir(1)
	//Top_Cube(WindowY)
{
	this->WindowX = WindowX;
	this->WindowY = WindowY;
}

void Player::setstartgravityforce(float force)
{
	SgravityForce = force;
	gravityForce = SgravityForce;
}

void Player::setstartjumpforce(float force)
{
	SjumpForce = force;
	jumpForce = SjumpForce;
}

void Player::setstartspeed(float speed)
{
	Vstart = speed;
	V = Vstart;
}

void Player::setsize(Vector2f size)
{
	this->size = size;
	shape.setSize(size);
	shape.setOrigin(size.x / 2, size.y / 2);
}

void Player::setpos(Vector2f pos)
{
	this->pos = pos;
	shape.setPosition(pos);
}

void Player::setcolor(Color color)
{
	shape.setFillColor(color);
}

void Player::setTexture(Texture &texture)
{
	shape.setTexture(&texture);
}

void Player::setFrame(float width, Color color)
{
	shape.setOutlineThickness(width);
	shape.setOutlineColor(color);
}

void Player::setHorizontalSpeed(float speed)
{
	V = speed;
	leftSpeed = -V;
	rightSpeed = V;
	//Vmove.x = speed;
}

void Player::setVerticalSpeed(float speed)
{
	Vjump.y = speed;
}

void Player::setInAir(bool set)
{
	inAir = set;
}

void Player::setgravityforce(float force)
{
	gravityForce = force;
}

void Player::setLeftSpeed(float speed)
{
	leftSpeed = speed;
}

void Player::setRightSpeed(float speed)
{
	rightSpeed = speed;
}

/*void Player::setTop_Cube()
{
	Top_Cube = shape.getPosition().y + size.y/2;
}

void Player::resetTop_Cube()
{
	Top_Cube = WindowY - shape.getSize().y;
}

void Player::setLeft_Cube()
{
	Left_Cube = shape.getPosition().x + size.x / 2;
}

void Player::resetLeft_Cube()
{
	Left_Cube = WindowX;
}

void Player::setRight_Cube()
{
	Right_Cube = shape.getPosition().x - size.x / 2;
}

void Player::resetRight_Cube()
{
	Right_Cube = 0;
}

void Player::setBottom_Cube()
{
	Bottom_Cube = shape.getPosition().y - size.y / 2;
}

void Player::resetBottom_Cube()
{
	Bottom_Cube = 0;
}*/

Vector2f Player::getpos()
{
	
	return shape.getPosition();
}

Vector2f Player::getspeed()
{
	return Vmove;
}

FloatRect Player::getBoundingBox()
{
	boundingbox = shape.getGlobalBounds();
	/*boundingbox.left = boundingbox.left - 4;
	boundingbox.width = boundingbox.width + 4;*/
	return boundingbox;
	//return shape.getGlobalBounds();
}

Vector2f Player::bottom() 
{ 
	Vector2f temp;
	temp.x = shape.getPosition().x;
	temp.y = shape.getPosition().y + size.y / 2;
	return temp;
}

Vector2f Player::left()
{
	Vector2f temp;
	temp.x = shape.getPosition().x - size.x / 2;
	temp.y = shape.getPosition().y;
	return temp;
}

void Player::gravity()
{
	if ((bottom().y < WindowY)) // tu by³o	if ((bottom().y + size.y < WindowY))
	{
		Vjump.y += gravityForce;
		shape.move(Vjump);
	}
	else
	{
		inAir = 0;
	}
	
}

void Player::jump()
{	
	if (inAir != 1)
	{
		Vjump.y = 0;
		Vjump.y -= jumpForce;
		shape.move(Vjump);
		inAir = 1;
	}
}

void Player::moveLeft()
{
	Vmove.x = leftSpeed;
}

void Player::moveRight()
{
	Vmove.x = rightSpeed;
}

void Player::move()
{
	if (Keyboard::isKeyPressed(Keyboard::A) | Keyboard::isKeyPressed(Keyboard::Left))
	{
		moveLeft();
	}
	else if (Keyboard::isKeyPressed(Keyboard::D) | Keyboard::isKeyPressed(Keyboard::Right))
	{
		moveRight();
	}
	shape.move(Vmove);
}

void Player::update()
{
	if (Keyboard::isKeyPressed(Keyboard::W) | Keyboard::isKeyPressed(Keyboard::Space) | Keyboard::isKeyPressed(Keyboard::Up))
	{
		jump();
	}
	if (Keyboard::isKeyPressed(Keyboard::D) | Keyboard::isKeyPressed(Keyboard::A) | Keyboard::isKeyPressed(Keyboard::Left) | Keyboard::isKeyPressed(Keyboard::Right))
	{
		move();
	}
	if (Keyboard::isKeyPressed(Keyboard::S) | Keyboard::isKeyPressed(Keyboard::Down))
	{
		gravityForce *= 3;
	}
	//shape.move(Vjump);
	gravity();
}

void Player::resetmovespeed()
{
	Vmove.x = 0;
	Vmove.y = 0;
	Vjump.x = 0;
	Vjump.y = 0;
}

void Player::draw(RenderTarget &target, RenderStates state)const
{
	target.draw(this->shape, state);
}