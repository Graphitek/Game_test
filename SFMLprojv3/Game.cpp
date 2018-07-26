#include "stdafx.h"

String Game::path = "resources/";
String Game::txt_path = path + "textures/";
String Game::font_path = path + "fonts/";

std::string Game::NoTexture = "Texture load error\nDid you add resources folder to exe file directory ?\n";
std::string Game::FileError = "Error during opening/creating leaderboards file\n";

float Game::playerXsize = 30;
float Game::playerYsize = 30;
Vector2f Game::playerStartSize(Game::playerXsize, Game::playerYsize);
float Game::playerFrameSize = 2;
Vector2f Game::totalplayerStartSize(Game::playerXsize + Game::playerFrameSize*2, Game::playerYsize + Game::playerFrameSize*2);

float Game::WindowX = 1280;
float Game::WindowY = 720;
//standard 60 fps 1 gravity 15 jump 5 speed
int Game::frameMultiplayer = 1;
float Game::framelimit = 60;
//float Game::startSpeed = Game::framelimit / (12 * Game::frameMultiplayer);
float Game::startSpeed = 5;
float Game::startJumpforce = 15;
float Game::startGravityforce = 1;

Game::Game() :
	WhereIsViewX(WindowX / 2),
	playerStartPos(WindowX / 10, WindowY / 2),
	player(WindowX, WindowY),
	menu(WindowX, WindowY),
	pausemessage(),
	info(),
	view(Vector2f(WindowX / 2, WindowY / 2), Vector2f(WindowX, WindowY)),
	okno(VideoMode(WindowX, WindowY), "name123", Style::Close | Style::Titlebar),
	bggame(Vector2f(WindowX, WindowY)),
	bggame2(Vector2f(WindowX, WindowY)),
	world(path, &manager),
	clock(),
	rtime(),
	results(WindowX, WindowY),
	manager(),
	nickname(WindowX, WindowY)
{
	okno.setFramerateLimit(frameMultiplayer * framelimit);
	//okno.setView(view);
	player.setsize(playerStartSize);
	player.setpos(playerStartPos);
	//player.setcolor(Color::Green);
	player.setstartgravityforce(startGravityforce);
	player.setstartjumpforce(startJumpforce);
	player.setstartspeed(startSpeed);
	pausemessage.setFont(menu.font);
	pausemessage.setString("Pause");
	pausemessage.setCharacterSize(90);
	pausemessage.setFillColor(Color::Magenta);
	pausemessage.setPosition(Vector2f(WindowX / 8, WindowY / 3));

	info.setFont(menu.font);
	info.setCharacterSize(30);
	info.setFillColor(Color::White);
	info.setPosition(Vector2f(20, 20));

	player.setTexture(*manager.getTexture("square.jpg"));
	player.setFrame(playerFrameSize, Color::Black); 
	bggame.setTexture(manager.getTexture("bggamefinal.png"));
	bggame2.setTexture(manager.getTexture("bggamefinal.png"));

	bggame.setOrigin(bggame.getSize().x / 2, bggame.getSize().y / 2);
	bggame.setPosition(WindowX / 2, WindowY / 2);
	bggame2.setOrigin(bggame2.getSize().x / 2, bggame2.getSize().y / 2);
	bggame2.setPosition(bggame.getPosition().x + bggame.getSize().x, WindowY / 2);
	//view.zoom(3); //temp

	world.setCubes();

	clock.restart();
}



void Game::trackview()
{
	if (player.getpos().x > WhereIsViewX - 0.20*WindowX)
	{
		view.move(abs(player.getspeed().x), 0);
		WhereIsViewX += abs(player.getspeed().x);

		bggame.move(abs(player.getspeed().x / 2), 0);
		bggame2.move(abs(player.getspeed().x / 2), 0);

	}
	else if (WhereIsViewX > WindowX / 2)
	{
		view.move(abs(startSpeed/2), 0);
		WhereIsViewX += abs(startSpeed /2);

		bggame.move(abs(startSpeed / 4), 0);
		bggame2.move(abs(startSpeed / 4), 0);

	}

	//std::cout << WhereIsViewX << std::endl;

	//std::cout << player.getpos().x << " " << player.getpos().y << std::endl;
	//std::cout << WhereIsViewX << std::endl;

}

void Game::bggamemove()
{
	if (WhereIsViewX - WindowX / 2 > bggame.getPosition().x - WindowX / 2)
	{
		bggame2.setPosition(bggame.getPosition().x + WindowX, WindowY / 2);
	}
	if (WhereIsViewX - WindowX / 2 > bggame2.getPosition().x - WindowX / 2)
	{
		bggame.setPosition(bggame2.getPosition().x + WindowX, WindowY / 2);
	}

}

void Game::moveMenus()
{
	menu.setMenuPos(WhereIsViewX);
	results.setMenuPos(WhereIsViewX);
	nickname.setMenuPos(WhereIsViewX);
}

void Game::youlose()
{
	if (world.YouLose() || (player.left().x <= WhereIsViewX - WindowX / 2) || (player.bottom().y >= WindowY + playerStartSize.y))
	{
			//std::cout << "You lose\n";
			lose = true;
			pausemessage.setString("You LOST !");
			menu.setFirstString("Play again");
			moveMenus();
			pausemessage.setPosition(Vector2f(WhereIsViewX - 0.85*WindowX / 2, WindowY / 3));
			menu.setMenuState(1);
	}
}

void Game::youwin()
{
	if (world.YouWin() && lose == false)
	{
		win = true;
		result = do_2(rtime.asSeconds());
		pausemessage.setString("You WON !\nTime: " + result + " s");
		menu.setFirstString("Play again");
		moveMenus();
		pausemessage.setPosition(Vector2f(WhereIsViewX - 0.85*WindowX / 2, WindowY / 4));
		if (results.newResult(stof(result)))
		{
			nickname.setMenuState(true);
		}
		else
		{
			menu.setMenuState(1);
		}
		results.saveresult(result);
		results.refreshAllLb();
	}
}

void Game::reset()
{
	lose = 0;
	view.setCenter(WindowX / 2, WindowY / 2);
	WhereIsViewX = WindowX / 2;
	player.setpos(playerStartPos);
	player.resetmovespeed();
	player.setInAir(true);
	world.colision(player);
	world.resetWin();
	world.resetLose();
	pausemessage.setString("Pause");
	bggame.setPosition(WindowX / 2, WindowY / 2);
	clock.restart();
	info.setString("");
}

std::string Game::do_2(double liczba)
{
	liczba = round(liczba * 100) / 100;
	czas = std::to_string(liczba);
	czas.erase(czas.end() - 4, czas.end());
	return czas;
}

std::string Game::do_3(double liczba)
{
	liczba = round(liczba * 1000) / 1000;
	czas = std::to_string(liczba);
	czas.erase(czas.end() - 3, czas.end());
	return czas;
}



void Game::RoundTime()
{
	if (player.getpos().x > world.startpos)
	{
		rtime = clock.getElapsedTime();
		info.setString(do_2(rtime.asSeconds()) + " s");
	}
	else
	{
		clock.restart();
	}

}

void Game::gamerunning()
{
	/*okno.draw(bggame);
	okno.draw(bggame2);
	bggamemove();
	world.draw(okno);
	world.colision(player);
	okno.draw(player);
	okno.setView(view);
	player.update();
	trackview();
	youlose();
	youwin();
	RoundTime();
	info.setPosition(WhereIsViewX - WindowX / 2 + 20, 20);
	okno.draw(info);*/

	okno.draw(bggame);
	okno.draw(bggame2);
	bggamemove();
	world.draw(okno);
	okno.draw(player);
	okno.setView(view);
	player.update();
	world.colision(player);
	trackview();
	youlose();
	youwin();
	RoundTime();
	info.setPosition(WhereIsViewX - WindowX / 2 + 20, 20);
	okno.draw(info);
}

void Game::run()
{
	while (okno.isOpen())
	{
		while (okno.pollEvent(event))
		{
			if(nickname.MenuState())
			nickname.dataEnter(okno, event);
			switch (event.type)
			{
			case Event::Closed:
				okno.close();
				break;


			case Event::KeyReleased:
				switch (event.key.code)
				{
				case Keyboard::S:
				case Keyboard::Down:
					{
					if (menu.MenuState() == 1)
					{
						menu.MoveDown();
					}
					else
					{
						player.gravityForce = player.SgravityForce;
					}
					if (results.MenuState() == 1)
					{
						results.MoveDown();
					}
					}
					break;
				case Keyboard::W:
				case Keyboard::Up:
					if (menu.MenuState() == 1)
					{
						menu.MoveUp();
					}
					if (results.MenuState() == 1)
					{
						results.MoveUp();
					}
					break;
				case Keyboard::Return:
					if (menu.MenuState() == 1)
					{
						switch (menu.whatclicked())
						{
						case 0:
							if (lose == 1 || win == 1) { reset(); }
							menu.setfirstRun(false);
							menu.setMenuState(false);
							break;
						case 1:
							results.setMenuState(true);
							menu.setMenuState(false);
							break;
						case 2:
							break;
						case 3:
							break;
						case 4:
							menu.setMenuState(false);
							return;
							break;
						}
					}
					if (nickname.MenuState() == 1)
					{
						nickname.setMenuState(false);
						menu.setMenuState(true);
					}

					if (results.MenuState() == 1)
					{
						switch (results.whatclicked())
						{
							//warunki przy klikaniu na wyniki
						}
					}
					break;
				case Keyboard::BackSpace:
				case Keyboard::Escape:
					if (menu.MenuState() != 1 && results.MenuState() != 1 && nickname.MenuState() != 1)
					{
						menu.setFirstString("Resume");
						menu.setMenuState(true);
						pausemessage.setPosition(Vector2f(WhereIsViewX - 0.75*WindowX / 2, WindowY / 3));
						moveMenus();
					}
					else if (menu.firstRun() == 0 && lose != 1)
					{
						menu.setMenuState(false);
					}

					if (results.MenuState() == 1)
					{
						menu.setMenuState(true);
						results.setMenuState(false);
					}
						break;
				}
			case Event::KeyPressed:
				switch (event.key.code)
				{
					if (menu.MenuState() == 1)
					{
				case (Keyboard::S | Keyboard::Down):
					menu.MoveDown();
					break;
				case (Keyboard::W | Keyboard::Up):
					menu.MoveUp();
					break;
					}
				}
			}
				
		}
		okno.clear(Color::Black);
		if (menu.MenuState() == 1)
		{
			menu.draw(okno);
			//nickname.draw(okno); // test draw nickname
			if (menu.firstRun() != 1) { okno.draw(pausemessage); }
		}
		if (results.MenuState() == 1)
		{
			results.draw(okno);
		}
		if (nickname.MenuState() == 1)
		{
			nickname.draw(okno);
			okno.draw(pausemessage);
		}
		if (menu.MenuState() != 1 && results.MenuState() != 1 && nickname.MenuState() != 1)
		{
			//Time time = clock.getElapsedTime();
			//std::cout << 1.0f / time.asSeconds() << std::endl;
			//clock.restart().asSeconds();
			//info.setString(std::to_string((int)player.getpos().x));//test
			//info.setString(std::to_string((int)1.0f / time.asSeconds()));
			gamerunning();
		}
		okno.display();

	}
}