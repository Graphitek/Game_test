#include "stdafx.h"

World::World(String path, ResourceManager *manager) :
	youwin(false),
	startpos(10 * Game::playerStartSize.x)
{
	cube_txt = manager->getTexture("gradientblackv2.png");
	killcube2_txt = manager->getTexture("killgradientblackv2.png");
	killcube_txt = manager->getTexture("killgradientblackv6.png");
}

void World::setCubes()
{
	//win cubes
	wincubes.push_back(WinCube(3, 6, 141, 15));

	//map cubes
	cubes.push_back(Cube(12, 1, 0, 1, *cube_txt, Color(203, 0, 255, 255))); // 12 length dla testu

	cubes.push_back(Cube(1, 4, 6, 2, *cube_txt, Color(255, 145, 20, 255))); // test 2 colision // 1 2 6 2
	cubes.push_back(Cube(1, 4, 10, 2, *cube_txt, Color(255, 145, 20, 255))); // test 2 colision// 1 2 10 2
	
	cubes.push_back(Cube(3, 2, 7, 4, *cube_txt, Color(255, 145, 20, 255))); // 5 2 6 4
	cubes.push_back(Cube(5, 1, 6, 9, *cube_txt, Color(255, 145, 20, 255)));
	cubes.push_back(Cube(3, 1, 16, 9, *cube_txt, Color(255, 145, 20, 255)));
	cubes.push_back(Cube(3, 1, 23, 3, *cube_txt, Color(255, 145, 20, 255)));
	cubes.push_back(Cube(1, 6, 29, 0.5, *cube_txt, Color(255, 145, 20, 255)));
	cubes.push_back(Cube(1, 8, 33.5, 0.5, *cube_txt, Color(255, 145, 20, 255)));
	cubes.push_back(Cube(1, 10, 38, 0.5, *cube_txt, Color(255, 145, 20, 255)));
	cubes.push_back(Cube(1, 13, 42.5, 0.5, *cube_txt, Color(255, 145, 20, 255)));
	cubes.push_back(Cube(5, 13, 47, 0.5, *cube_txt, Color(0, 255, 0, 255)));
	cubes.push_back(Cube(3, 1, 52.5, 15, *cube_txt, Color(0, 255, 0, 100)));
	cubes.push_back(Cube(1, 21, 56.5, 0.5, *cube_txt, Color(0, 255, 0, 100)));
	cubes.push_back(Cube(3, 1, 48, 17, *cube_txt, Color(0, 255, 0, 100)));
	cubes.push_back(Cube(3, 1, 51, 21, *cube_txt, Color(0, 255, 0, 100)));
	cubes.push_back(Cube(6, 2, 58, 14, *cube_txt, Color(203, 0, 255, 255)));
	cubes.push_back(Cube(6, 2, 68, 4, *cube_txt, Color(203, 0, 255, 255)));
	cubes.push_back(Cube(2, 1, 78, 7, *cube_txt, Color(0, 0, 0, 120)));
	cubes.push_back(Cube(2, 1, 84, 10, *cube_txt, Color(0, 0, 0, 120)));
	cubes.push_back(Cube(2, 1, 90, 13, *cube_txt, Color(0, 0, 0, 120)));
	cubes.push_back(Cube(15, 1, 96, 13, *cube_txt, Color(0, 0, 0, 120)));
	cubes.push_back(Cube(4, 1, 100, 17, *cube_txt, Color(0, 0, 0, 120)));
	cubes.push_back(Cube(21, 1, 115, 15, *cube_txt, Color(203, 0, 255, 255)));

	cubes.push_back(Cube(1, 10, 115, 20, *cube_txt, Color(255, 0, 0, 180)));
	cubes.push_back(Cube(1, 10, 116, 20, *cube_txt, Color(255, 114, 0, 180)));
	cubes.push_back(Cube(1, 10, 117, 20, *cube_txt, Color(255, 229, 0, 180)));
	cubes.push_back(Cube(1, 10, 118, 20, *cube_txt, Color(0, 255, 0, 180)));
	cubes.push_back(Cube(1, 10, 119, 20, *cube_txt, Color(0, 212, 255, 180)));
	cubes.push_back(Cube(1, 10, 120, 20, *cube_txt, Color(0, 0, 255, 180)));
	cubes.push_back(Cube(1, 10, 121, 20, *cube_txt, Color(135, 0, 255, 180)));
	cubes.push_back(Cube(1, 10, 122, 20, *cube_txt, Color(255, 0, 0, 180)));
	cubes.push_back(Cube(1, 10, 123, 20, *cube_txt, Color(255, 114, 0, 180)));
	cubes.push_back(Cube(1, 10, 124, 20, *cube_txt, Color(255, 229, 0, 180)));
	cubes.push_back(Cube(1, 10, 125, 20, *cube_txt, Color(0, 255, 0, 180)));
	cubes.push_back(Cube(1, 10, 126, 20, *cube_txt, Color(0, 212, 255, 180)));
	cubes.push_back(Cube(1, 10, 127, 20, *cube_txt, Color(0, 0, 255, 180)));
	cubes.push_back(Cube(1, 10, 128, 20, *cube_txt, Color(135, 0, 255, 180)));
	cubes.push_back(Cube(1, 10, 129, 20, *cube_txt, Color(255, 0, 0, 180)));
	cubes.push_back(Cube(1, 10, 130, 20, *cube_txt, Color(255, 114, 0, 180)));
	cubes.push_back(Cube(1, 10, 131, 20, *cube_txt, Color(255, 229, 0, 180)));
	cubes.push_back(Cube(1, 10, 132, 20, *cube_txt, Color(0, 255, 0, 180)));
	cubes.push_back(Cube(1, 10, 133, 20, *cube_txt, Color(0, 212, 255, 180)));
	cubes.push_back(Cube(1, 10, 134, 20, *cube_txt, Color(0, 0, 255, 180)));
	cubes.push_back(Cube(1, 10, 135, 20, *cube_txt, Color(135, 0, 255, 180)));

	cubes.push_back(Cube(6, 1, 139, 14, *cube_txt, Color(255, 0, 0, 255)));
	cubes.push_back(Cube(6, 1, 139, 23, *cube_txt, Color(255, 0, 0, 255)));
	cubes.push_back(Cube(1, 8, 145, 15, *cube_txt, Color(255, 0, 0, 255)));

	cubes.push_back(Cube(1, 1, 139, 15, *cube_txt, Color(255, 0, 0, 255)));
	cubes.push_back(Cube(1, 1, 139, 22, *cube_txt, Color(255, 0, 0, 255)));
	cubes.push_back(Cube(1, 1, 144, 21, *cube_txt, Color(0, 0, 0, 120)));
	cubes.push_back(Cube(2, 1, 143, 16, *cube_txt, Color(0, 0, 0, 120)));
	cubes.push_back(Cube(1, 1, 142, 17, *cube_txt, Color(0, 0, 0, 120)));

	//kill cubes
	killcubes.push_back(KillCube(1, 1, 56.5, 21.5, *killcube2_txt, Color(83, 0, 135, 255)));
	killcubes.push_back(KillCube(6, 1, 99, 14, *killcube2_txt, Color(83, 0, 135, 255)));
	//killcubes.push_back(KillCube(1, 1, 139, 16, *killcube2_txt, Color(83, 0, 135, 255)));
	killcubes.push_back(KillCube(36, 1, 11, 0.5, *killcube_txt, Color(83, 0, 135, 255)));
	killcubes.push_back(KillCube(5, 1, 47, 0.5, *killcube_txt, Color(83, 0, 135, 255)));
	killcubes.push_back(KillCube(5, 1, 52, 0.5, *killcube_txt, Color(83, 0, 135, 255)));
	killcubes.push_back(KillCube(23, 1, 57, 0.5, *killcube_txt, Color(83, 0, 135, 255)));
	killcubes.push_back(KillCube(20, 1, 80, 0.5, *killcube_txt, Color(83, 0, 135, 255)));
	killcubes.push_back(KillCube(20, 1, 100, 0.5, *killcube_txt, Color(83, 0, 135, 255)));
	killcubes.push_back(KillCube(20, 1, 120, 0.5, *killcube_txt, Color(83, 0, 135, 255)));
	killcubes.push_back(KillCube(20, 1, 140, 0.5, *killcube_txt, Color(83, 0, 135, 255)));


}

bool World::YouWin()
{
	return youwin;
}

bool World::YouLose()
{
	return youlose;
}

void World::resetWin()
{
	youwin = false;
}

void World::resetLose()
{
	youlose = false;
}

void World::colision(Player &player)
{
	anytop = 0;
	anybottom = 0;
	anyleft = 0;
	anyright = 0;
	any_total = 0;
	for (auto &bloczki : cubes) //map cubes colision
	{
		bloczki.getPoints();
		if ((bloczki.getColBox().left - (player.getpos().x + player.getBoundingBox().width) < 0) && (player.getpos().x - (bloczki.getColBox().left + bloczki.getColBox().width + player.getBoundingBox().width) < 0))
		{
			if (bloczki.colision_top(player.getBoundingBox()))
			{
				player.setgravityforce(0);
				player.setVerticalSpeed(0);
				player.setInAir(false);
				player.setpos(Vector2f(player.getpos().x, bloczki.getColBox().top - player.getBoundingBox().height / 2));
				//std::cout << "Bloczki top: " << bloczki.getColBox().top << "\nPlayer x: " << player.getpos().x << std::endl;
				player.setInAir(0); // test blokady skoku przy spadaniu z bloczka //dziala
				anytop = 1;
			}
			else if (anytop != 1)
			{
				player.setgravityforce(player.SgravityForce);
				player.setInAir(1); //test blokady
			}

			if (bloczki.colision_bottom(player.getBoundingBox()))
			{
				player.setVerticalSpeed(0);
				player.setpos(Vector2f(player.getpos().x, bloczki.getColBox().top + bloczki.getColBox().height + player.getBoundingBox().height / 2));
			}
			else
			{

			}
			//std::cout << player.getspeed().x << std::endl;
			if (bloczki.colision_right(player.getBoundingBox()))
			{
				player.setLeftSpeed(0);
				player.setpos(Vector2f(bloczki.getColBox().left + bloczki.getColBox().width +player.getBoundingBox().width / 2, player.getpos().y)); //coœ dalej nie tak check colision lewa git
				anyright = 1;
			}
			else if (anyright != 1 && anyleft != 1)
			{
				//player.setHorizontalSpeed(player.Vstart);
				player.setLeftSpeed(-player.Vstart);
			}
			if (bloczki.colision_left(player.getBoundingBox())) // tu doda³eœ && player.getspeed().x > 0
			{

				player.setRightSpeed(0);
				player.setpos(Vector2f(bloczki.getColBox().left - player.getBoundingBox().width / 2, player.getpos().y));
				anyleft = 1;
			}
			else if (anyleft != 1 && anyright != 1)
			{
				player.setRightSpeed(player.Vstart);
			}


			/*if (bloczki.colision_total(player.getBoundingBox()))
			{
			//cos co sie robi jezeli jest jaka kolwiek kolizja
			player.setInAir(0);
			any_total = 1; // je¿eli =0 i na dole != 0 to dziwna rzecz mozna wspianc sie po scianach
			}
			else if (any_total != 1)
			{
			player.setInAir(1);
			}*/
		}
	}
	for (auto &win : wincubes) //win cubes colision
	{
		if (win.colision_total(player.getBoundingBox()))
		{
			youwin = true;
			//std::cout << "YOU WIN\n";;
		}
	}

	for (auto &kill : killcubes)
	{
		kill.getPoints();
		if (kill.colision_total(player.getBoundingBox()))
		{
			//std::cout << "DIE IDIOT\n";
			youlose = true;
		}
	}

}

void World::draw(RenderWindow &window)
{

	for (auto &bloczki : cubes)
		window.draw(bloczki);
	for (auto &bloczki : killcubes)
		window.draw(bloczki);

}
