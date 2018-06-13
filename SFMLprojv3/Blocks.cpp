#include "stdafx.h"

float Blocks::wspolczynnikDoskonalosciA = 0.9; // doda³eœ to nwm po co jak coœ to usuñ
float Blocks::wspolczynnikDoskonalosciB = 1 - Cube::wspolczynnikDoskonalosciA;
//Vector2f Blocks::size = Game::playerStartSize;

void Blocks::setBasic(Texture &texture)
{
	shape.back().setSize(size);
	shape.back().setOrigin(size.x / 2, size.y / 2);
	shape.back().setTexture(&texture);
	//shape.back().setOutlineThickness(0);
	//shape.back().setOutlineColor(Color::White);
}

Blocks::Blocks() :
	size(Game::playerStartSize)
{

}

Cube::Cube()
{

}

Cube::Cube(float posX, float posY, Texture &texture, Color &color)
{
	shape.push_back(RectangleShape());
	setBasic(texture);
	shape.back().setFillColor(color);
	shape.back().setPosition(Vector2f(posX, posY));
}

Cube::Cube(int ile_width, int ile_hight, float posX, float posY, Texture &texture, Color color)

{
	for (int i = 0; i < ile_width; i++)
	{
		shape.push_back(RectangleShape());
		setBasic(texture);
		shape.back().setFillColor(color);
		shape.back().setPosition(Vector2f(posX* size.x + i * (size.x + shape.back().getOutlineThickness()), Game::WindowY - posY* size.y));

		for (int j = 0; j < ile_hight - 1; j++)
		{
			shape.push_back(RectangleShape());
			setBasic(texture);
			shape.back().setFillColor(color);
			shape.back().setPosition(Vector2f(posX* size.x + i * (size.x + shape.back().getOutlineThickness()), Game::WindowY - posY* size.y - size.y - j * (size.y + shape.back().getOutlineThickness())));
		}

	}
}

/*void Cube::setSize(int id, int width, int hight)
{
	size.x = width;
	size.y = hight;
	shape.at(id).setSize(size);
	shape.at(id).setOrigin(size.x / 2, size.y / 2);
}*/


void Blocks::getPoints()
{
	pointA.x = shape.at(0).getPosition().x - size.x / 2;
	pointA.y = shape.at(0).getPosition().y + size.y / 2;
	pointB.x = shape.back().getPosition().x + size.x / 2;
	pointB.y = shape.back().getPosition().y - size.y / 2;

	colbox.height = pointA.y - pointB.y;
	colbox.width = pointB.x - pointA.x;
	colbox.left = pointA.x;
	colbox.top = pointB.y;
	
}

FloatRect Blocks::getColBox()
{
	return colbox;
}

bool Blocks::colision_top(FloatRect otherbox)
{
	if ((colbox.top <= otherbox.top + otherbox.height) && (otherbox.top < colbox.top) &&
		(otherbox.left + wspolczynnikDoskonalosciA * otherbox.width >= colbox.left) && (otherbox.left + wspolczynnikDoskonalosciB * otherbox.width <= colbox.left + colbox.width))//top colision
	//if ((colbox.top <= otherbox.top + otherbox.height) && (otherbox.top  < colbox.top) && (otherbox.left + otherbox.width >= colbox.left) && (otherbox.left + otherbox.width <= colbox.left + colbox.width))//top colision
	{
		std::cout << "Top\n";
		//lasttop = true;
		return true;
	}
	else
	{
		//std::cout << "NieTop\n";
		//lasttop = false;
		return false;
	}
}

bool Blocks::colision_bottom(FloatRect otherbox)
{
	if ((colbox.top + colbox.height >= otherbox.top) && (otherbox.top + otherbox.height > colbox.top + colbox.height) &&
		(otherbox.left + wspolczynnikDoskonalosciA * otherbox.width >= colbox.left) && (otherbox.left + wspolczynnikDoskonalosciB * otherbox.width <= colbox.left + colbox.width))//bottom colision
	//if ((colbox.top + colbox.height >= otherbox.top) && (otherbox.top + otherbox.height > colbox.top + colbox.height) && (otherbox.left + otherbox.width >= colbox.left) && (otherbox.left + otherbox.width <= colbox.left + colbox.width))//bottom colision
	{
		std::cout << "Bottom\n";
		//lastbottom = true;
		return true;
	}
	else
	{
		//lastbottom = false;
		return false;
	}
}

bool Blocks::colision_left(FloatRect otherbox)
{
	if ((colbox.left <= otherbox.left + otherbox.width) && (otherbox.left < colbox.left) &&
		(otherbox.top <= colbox.top + wspolczynnikDoskonalosciA * colbox.height) && (otherbox.top + wspolczynnikDoskonalosciA * otherbox.height >= colbox.top))//left colision
	{
		std::cout << "Left\n";
		//lastleft = true;
		return true;
	}
	else
	{
		//lastleft = false;
		return false;
	}
}

bool Blocks::colision_right(FloatRect otherbox)
{
	if ((colbox.left + colbox.width >= otherbox.left) && (otherbox.left + otherbox.width > colbox.left + colbox.width) && //jezepi do pierwszego warunku dodamy 1 dziala ale jest przerwa 1 pix
		(otherbox.top <= colbox.top + wspolczynnikDoskonalosciA * colbox.height) && (otherbox.top + wspolczynnikDoskonalosciA * otherbox.height >= colbox.top))//right colision
	{
		std::cout << "right\n";
		//lastright = true;
		return true;
	}
	else
	{
		//lastright = false;
		return false;
	}
}

bool Blocks::colision_total(FloatRect otherbox)
{
	if (colision_bottom(otherbox) || colision_left(otherbox) || colision_right(otherbox) || colision_top(otherbox))
	{
		//lasttotal = true;
		return true;
	}
	else
	{
		//lasttotal = false;
		return false;
	}
}

WinCube::WinCube(int width, int height, float posX, float posY) :
	winshape()
{
	winshape.setSize(Vector2f(width * size.x, height * size.y));
	winshape.setOrigin(Vector2f(0, height * size.y));
	winshape.setPosition(Vector2f(posX * size.x, Game::WindowY - posY * size.y));
	colbox = winshape.getGlobalBounds();
}

KillCube::KillCube(int ile_width, int ile_hight, float posX, float posY, Texture &texture, Color color)
{
	//size = Game::playerStartSize;

	for (int i = 0; i < ile_width; i++)
	{
		shape.push_back(RectangleShape());
		setBasic(texture);
		shape.back().setFillColor(color);
		shape.back().setPosition(Vector2f(posX* size.x + i * (size.x + shape.back().getOutlineThickness()), Game::WindowY - posY * size.y));

		for (int j = 0; j < ile_hight - 1; j++)
		{
			shape.push_back(RectangleShape());
			setBasic(texture);
			shape.back().setFillColor(color);
			shape.back().setPosition(Vector2f(posX* size.x + i * (size.x + shape.back().getOutlineThickness()), Game::WindowY - posY * size.y - size.y - j * (size.y + shape.back().getOutlineThickness())));
		}
	}

}

void Cube::draw(RenderTarget &target, RenderStates state)const
{
	for (auto &cubes : shape)
	{
		target.draw(cubes, state);
	}


}