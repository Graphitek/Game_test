// SFMLprojv3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	try 
	{
		Game game;
		game.run();
	}
	catch(std::string error)
	{
		std::cout << error;
		system("PAUSE");
	}
    return 0;
}

