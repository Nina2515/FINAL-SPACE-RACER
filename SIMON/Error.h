#pragma once
class error
{
public:
	error(char* error1) {
		Error = error1;
	}
	~error();

	char* error;
};