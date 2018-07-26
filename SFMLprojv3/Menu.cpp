#include "stdafx.h"

void MenuBase::setPos(float x)
{
	for (int i = 0; i < ileopcji; i++)
	{
		poslist.push_back(Vector2f(x, WindowY*(i + 0.5) / (ileopcji + 1)));
		text.push_back(Text());
	}
}

MenuBase::MenuBase() :
	bg(),
	tlo(),
	selectedMin(0)

{
	if (!tlo.loadFromFile(Game::txt_path + "bgmenu.jpg")) { throw Game::NoTexture; };
	bg.setOrigin(WindowX / 2, WindowY / 2);
	bg.setPosition(WindowX / 2, WindowY / 2);
	bg.setColor(Color(255, 255, 255, 200));
	bg.setTexture(tlo);
	if (!font.loadFromFile(Game::font_path + "IndieFlower.ttf")) { throw Game::NoTexture; };
}


Menu::Menu(float WindowX, float WindowY) :
	firstrun(1)
{
	this->WindowX = WindowX;
	this->WindowY = WindowY;

	iterindex = 0;
	fontsize = 40;
	bigfontsize = 60;
	ileopcji = 5;
	MenuIsOn = 1;
	startPos = WindowX / 2;
	oldpos = startPos;
	selectedMin = 0;
	selectedMax = ileopcji;

	setPos(startPos);

	text[0].setString("Play");
	text[1].setString("Top Results");
	text[2].setString("Load");
	text[3].setString("Options");
	text[4].setString("Exit");

	for (auto &txt : text)
	{
		txt.setFont(font);
		txt.setCharacterSize(fontsize);
		txt.setFillColor(Color::Yellow);
	}
	text[0].setCharacterSize(bigfontsize);
	text[0].setFillColor(Color::Red);
	for (auto &txt : text)
	{
		txt.setOrigin(txt.getGlobalBounds().width / 2, txt.getGlobalBounds().height / 2);
		txt.setPosition(poslist[iterindex]);
		iterindex++;
	}
	selected = 0;
}

void MenuBase::MoveUp()
{
	if (selected - 1 >= selectedMin)
	{
		text[selected].setFillColor(Color::Yellow);
		text[selected].setCharacterSize(fontsize);
		text[selected].setOrigin(text[selected].getGlobalBounds().width / 2, text[selected].getGlobalBounds().height / 2);
		text[selected].setPosition(poslist[selected]);

		text[selected - 1].setFillColor(Color::Red);
		text[selected - 1].setCharacterSize(bigfontsize);
		text[selected - 1].setOrigin(text[selected - 1].getGlobalBounds().width / 2, text[selected - 1].getGlobalBounds().height / 2);
		text[selected - 1].setPosition(poslist[selected - 1]);

		selected--;
	}
}

void MenuBase::MoveDown()
{
	if (selected + 1 < selectedMax)
	{
		text[selected].setFillColor(Color::Yellow);
		text[selected].setCharacterSize(fontsize);
		text[selected].setOrigin(text[selected].getGlobalBounds().width / 2, text[selected].getGlobalBounds().height / 2);
		text[selected].setPosition(poslist[selected]);

		text[selected + 1].setFillColor(Color::Red);
		text[selected + 1].setCharacterSize(bigfontsize);
		text[selected + 1].setOrigin(text[selected + 1].getGlobalBounds().width / 2, text[selected + 1].getGlobalBounds().height / 2);
		text[selected + 1].setPosition(poslist[selected + 1]);

		selected++;
	}
}

string MenuBase::do_2(double liczba)
{
		liczba = round(liczba * 100) / 100;
		czas = std::to_string(liczba);
		czas.erase(czas.end() - 4, czas.end());
		return czas;
}

string MenuBase::do_3(double liczba)
{
	liczba = round(liczba * 1000) / 1000;
	czas = std::to_string(liczba);
	czas.erase(czas.end() - 3, czas.end());
	return czas;
}

int MenuBase::whatclicked()
{
	return selected;
}

bool MenuBase::MenuState()
{
	return MenuIsOn;
}

void MenuBase::setMenuState(bool state)
{
	MenuIsOn = state;
}

void MenuBase::draw(RenderWindow &okno) 
{
	okno.draw(bg);
	for (auto &menu : text)
	{
		okno.draw(menu);
	}
}

void MenuBase::setMenuPos(float pos)
{
	if (oldpos != pos)
	{
		for (int i = 0; i < ileopcji; i++)
		{
			text[i].move(Vector2f(pos - oldpos, 0));
			poslist[i] = Vector2f(pos - WindowX/2 + startPos, poslist[i].y);
		}
		bg.move(Vector2f(pos - oldpos, 0));
		oldpos = pos;
	}
}

bool Menu::firstRun()
{
	return firstrun;
}

void Menu::setfirstRun(bool state)
{
	firstrun = state;
}

void MenuBase::setCertainString(string zawartosc, int index)
{
	text[index].setString(zawartosc);
	text[index].setOrigin(text[index].getGlobalBounds().width / 2, text[index].getGlobalBounds().height / 2);
	text[index].setPosition(poslist[index]);
}

void Menu::setFirstString(String name)
{
	setCertainString(name, 0);
}

TopResults::TopResults(float WindowX, float WindowY) :
	resultpath(Game::path + "TopResults.txt"),
	iter(0),
	worstResult(999999),
	visibleresults(0)
{

	this->WindowX = WindowX;
	this->WindowY = WindowY;

	startPos = WindowX / 2 - WindowX / 2.3;
	iterindex = 0;
	fontsize = 32;
	bigfontsize = 48;
	ileopcji = 16;
	oldpos = WindowX/2;
	selectedMin = 1;
	selectedMax = ileopcji;
	setPos(startPos);
	text[0].setString("Leaderboards");
	text[0].setCharacterSize(bigfontsize);
	text[0].setFillColor(Color::Green);
	refreshAllLb();
}

void TopResults::saveresult(string result)
{
	top.open(resultpath, std::ios::out | std::ios::app);
	if (!top.fail())
	{
		if (stof(result) < worstResult)
		{
			top << result << "\n";
		}
		top.close();
	}
	else
	{
		throw Game::FileError;
	}

}

void TopResults::getresults()
{
	clearResults();
	top.open(resultpath, std::ios::in);
	if (!top.fail())
	{
		while(!top.eof())
		{
				getline(top, temp);
				if (temp != "")
				{
					results_s.push_back(temp);
					results_f.push_back(stof(results_s[iter]));
					iter++;
				}
		}
		sort(results_f.begin(), results_f.begin() + iter);
		if (iter >= 14)
		{
			if (results_f[14] != 0)
				worstResult = results_f[14];
		}
		iter = 0;
		for (auto &iter : results_f)
		{
			cout << iter << endl;
		}
		cout << "**************************************\n";
		top.close();
	}

}

bool TopResults::newResult(float result)
{
	if (result < worstResult)
	{
		return true;
	}

	return false;
}

void TopResults::refreshLeaderboards()
{
	getresults();
	for (auto &txt : text)
	{
			txt.setFont(font);
			if (iterindex > 0)
			{
			txt.setCharacterSize(fontsize);
			txt.setFillColor(Color::Yellow);
			if (results_f.size() > 0 && iterindex <= results_f.size())
			{
				tresc = to_string(iterindex) + ". " + do_2(results_f[iterindex - 1]);
				visibleresults++;
			}
			else
			{
				tresc = "";
			}
			txt.setString(tresc);
			}
		iterindex++;
		if (visibleresults <= 16)
		{
			selectedMax = visibleresults + 1;
		}
		else
		{
			visibleresults = 16;
		}
	}
	text[1].setCharacterSize(bigfontsize);
	text[1].setFillColor(Color::Red);
	selected = 1;
	visibleresults = 0;
	iterindex = 0;
}

void TopResults::refreshLeaderboards2()
{
	poslist[0].x = oldpos;
	for (auto &txt : text)
	{
		txt.setOrigin(txt.getGlobalBounds().width / 2, txt.getGlobalBounds().height / 2);
		txt.setPosition(poslist[iterindex]);
		iterindex++;
	}
	iterindex = 0;
}

void TopResults::refreshAllLb()
{
	refreshLeaderboards();
	refreshLeaderboards2();
}

void TopResults::clearResults()
{
	results_s.clear();
	results_f.clear();
}

//***********************************************************//

void EnterNick::dataEnter(RenderWindow &okno, Event &event)
{
	if (MenuIsOn)
	{
		switch (event.type)
		{
		case Event::TextEntered:
		{
			if (event.text.unicode < 128 && event.text.unicode > 45)
			{
				nick += static_cast<char>(event.text.unicode);
				//std::cout << nick << std::endl;
				//std::cout << "Character typed: " << static_cast<char>(event.text.unicode) << std::endl;
			}
			else if (event.text.unicode == 8 && nick.size()>0)
			{
				nick.erase(nick.end() - 1, nick.end());
			}
			std::cout << nick << std::endl;
			text[1].setString(nick);
		}

		}
	}
}

EnterNick::EnterNick(float WindowX, float WindowY) :
	nick("No_Nickname")
{
	startPos = WindowX / 2 - WindowX / 2.3;
	fontsize = 32;
	bigfontsize = 48;
	ileopcji = 2;
	oldpos = WindowX / 2;
	selectedMin = 1;
	selectedMax = 1;
	setPos(startPos);


	MenuIsOn = false;
	text[0].setString("Enter your nickname: ");
	text[0].setFont(font);
	text[0].setPosition(WindowX / 5, WindowY*0.05);
	text[0].setFillColor(Color::Red);
	text[0].setCharacterSize(bigfontsize);
	text[1].setString(nick);
	text[1].setPosition(WindowX / 5, WindowY*0.15);
	text[1].setFont(font);
	text[1].setFillColor(Color::Green);
	text[1].setCharacterSize(fontsize);
}

/*void EnterNick::set_nickState(bool x)
{
	MenuIsOn = x;
}*/