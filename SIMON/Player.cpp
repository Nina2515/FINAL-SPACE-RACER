#include <iostream>


using namespace std;

//Player's Data



class player1name {

	public:
		string player1firstname;

		int life = 3;

		float velocity = 4.5;

		


};

class player2name {

    public:

	string player2firstname;

	int life = 3;

	float velocity = 4.5; 

	cout << "Please enter a name for your second player:" << endl;

	getline(cin, player2firstname);


	ofstream outFile;
	outFile.open("CharacterData/player2firstname.txt");

	outFile << player2firstname << endl;
	outFile.close();


	ifstream inFile;

	cout << "The name is: " << player2firstname << endl;

	ifstream inputstream("player2firstname.txt");


};