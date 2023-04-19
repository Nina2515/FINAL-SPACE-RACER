#pragma once
#include <exception>

class GameError
{
public:
	GameError(char* error1) {
		Error = error1;
	}
	~GameError() {};

	char* Error;
};
