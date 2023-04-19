// processing events
#include "EventHandler.h"
#include <ctime>
// creating a basic gameobject
#include "Objects/ColourBlock.h"
#include "../GameError.h"
#include "../Graphics.h"
#include <iostream>



// GameState
bool GameRunning = true;



//Recursion

int GetNumMeteors(Meteor* meteor, int NumMeteor = 200) {

	int TotalMeteors = 200;

	if (meteor->M != nullptr) {

		TotalMeteors += GetNumMeteors(meteor->M);
		TotalMeteors += meteor + TotalMeteors; 
	}

	return TotalMeteors;

}

// argc and argv here are command line parameters passed to the program when running the program. 
// we won't actually use them but our 2D Graphics Library requires the main setup like this.
// Argc: the number of arguments pass
// argv[] : a char array of each of the params passed in ( each space is a new param)



// Data of the first player 
int names() {
	cout << "Please enter a name for your first character:" << endl;

	string player1firstname;
	getline(cin, player1firstname);


	ofstream outFile;
	outFile.open("CharacterData/player1firstname.txt");

	outFile << player1firstname << endl;
	outFile.close();


	ifstream inFile;

	cout << "The name is: " << player1firstname << endl;


	string player1Lastname;

	ifstream input("CharacterData/palyer1lastname.txt");
	getline(input, player1Lastname, '\n');

	ofstream oFile("CharacterData/player1Fullname.txt");
	oFile << player1firstname << " " << player1Lastname << endl;

	oFile.close();

	ifstream onFile;

	cout << "The lastname is: " << player1Lastname << endl;

	player1firstname.append(player1Lastname);

	//========================================

	// Data of the second player 

	cout << "Please enter a name for your second character:" << endl;

	string player2firstname;
	getline(cin, player2firstname);


	ofstream outFile;
	outFile.open("CharacterData/player2firstname.txt");

	outFile << player2firstname << endl;
	outFile.close();


	ifstream inFile;

	cout << "The name is: " << player2firstname << endl;


	string player2Lastname;

	ifstream input("CharacterData/player2lastname.txt");
	getline(input, player2Lastname, '\n');

	ofstream oFile("CharacterData/playere2Fullname.txt");
	oFile << player2firstname << " " << player2Lastname << endl;

	oFile.close();

	ifstream onFile;

	cout << "The lastname is: " << player2Lastname << endl;

	player2firstname.append(player2Lastname);


	return(0);

}

//Exception

int GameError(string player1, string player2) {

	if (player1 == "" || player2 == "") {
		throw "Game error";
	}

	return(0);
}


int main(int argc, char* argv[])
{


	cout << "Put players position ";

	string players[2];
	cin >> players[0] >> players[1];

	try {

		GameError(players[0], players[1]);
	}
	catch (string) {

		cout << "There was an error, the game will close\n\n";
	}

	catch (const char* error) {

		cout << error << "\n\n";
	}
	catch (error GamesError) {

		cout << GamesError.Error << "\n\n";
	}




	srand(time(NULL));

	

	if (!Graphics::Init())
	{
		return false;
	}

	

	

	// 2D array
	

	// where in the animation or entry is the current index
	int currentPatternIndex = 0;
	bool isAnimating = true;
	bool isBlankFrame = true;
	int currentPatternSize = 4;

	// Main game loop
	while (GameRunning) 
	{
		Graphics::StartRender();

		// handle button events
		GameRunning = EventHandler::Update();
		
		Graphics::DrawText("FINAL - Space Racer", 200,0, 200, 50);
			
		

		// apply the changes to the screen 
		Graphics::EndRender();
		// toggle the blank frame on
		isBlankFrame = !isBlankFrame;

		SDL_Delay(500);

		
		
	}
	

	close off the SDL window
	SDL_Quit();

	return true;
}
