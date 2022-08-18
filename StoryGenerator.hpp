#ifndef RPSLS
#define RPSLS

#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

//Make it capital
const string fileAboutInfo = "StoryAbout.txt";
const string fileStoryData = "StoryData.txt";
const string fileSaveStoryLine = "savedStoryLines.txt";

vector<string> settingsList;
vector<string> charactersList;
vector<string> situationsList; 
string generatedLine = "";

/*
*This function is called from main() and setups the whole project.
*/
void runMenu();

/*
*Displays title.
*/
void displayTitle();

/*
*This displays the Chooser for the first time, when user runs the programme.
*/
void displayOptionChooser();

/*
*gets user choice, after asking a question
*/
char userChoice(string question);

/*
*Display the whole text of a particulare file, line by line
*/
void displayText(string fileName);


/*displays the text of any file which is passed in this function.*/
void displayChooser();

/*
    This function load the story line from the StoryData.txt file.
    First it stores whether Settings, or Situation or Character data will be loaded next.
    Then it 

*/
void createLists(string fileName);

/*  Store data accordingly to which data is getting loaded.
    0 Same group of data is getting loaded
    1 Settings data will now be loaded. so switch to settingsList list.
    2 Characters data will now be loaded. so switch to charactersList
    3 Situations data will loaded. so switch to situations list.
*/
void storeIntoList(int dataType,string data);

/*
*Decides and executes according to user decision. Breaks the loop when user select 0.
*/
void runOptionLoop();

/*
    First creates declares a seed as current time in millis which changes 
    every time when function is called.
    gets all the Random value from different list and combines them.
    combined value is saved as generatedLine.
*/
void generateStoryLine();

/*Gives a random value from value from settingsList*/
string randomDataFromSettings();


/*
*Gives a random value from value from charactersList
*/
string randomDataFromCharacters();


/*
*Gives a random value from value from situationsList
*/
string randomDataFromSituations();


/*check wether data is loaded in all the list or if any is empty. return bool val accordingly.*/
bool dataLoaded();


/*
    It check the string value, if the value is
    Setting Data:- Means after this value of Setting Data will be loaded so return 1
    Characters data:- Means after this of Characters data will be loaded so return 2
    Situations data:- Means after this Situations data will be loaded so return 3
    return 0 if the same type of previos data was getting loaded. 
    eg. if setting data is getting loaded continously, return 0.
*/
int checkString(string text);


/*
*Checks wether we have any lastGeneratedLine line. if yes then call saveStory function.
*/
void saveGeneratedStory(string fileName);


/*
*writes and saves the file.
*/
void saveStory(char userInput,string fileName);

#endif