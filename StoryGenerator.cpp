#include"StoryGenerator.hpp"

int main(){
    runMenu();
    return 0;
}


void runMenu(){
    displayTitle();
    displayChooser();
    runOptionLoop();
}

void displayTitle(){
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;        
    cout<<"          The Amazing Story Generator"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;   
}


void displayChooser(){
    cout<<"[0] End Testing the Program"<<endl;
    cout<<"[1] Display \"ABOUT\" Information"<<endl;
    cout<<"[2] Read and store data from file"<<endl;
    cout<<"[3] Generate a random Story Line"<<endl;
    cout<<"[4] Save a Story Line to a file"<<endl;
    cout<<"[5] Display saved Story Lines from file"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;       
}

char userChoice(string question){
    cout<<"\n"<<question;
    char userChoice;
    cin>>userChoice;
    return userChoice;
}


void runOptionLoop(){
    bool quitLoop = false;
    while(!quitLoop){
        char userInput = userChoice("Which option would you line (0-5): ");
        switch(userInput){
            case '0':        
                quitLoop = true;
                break;
            case '1':
                displayText(fileAboutInfo);
                break;
            case '2':
                createLists(fileStoryData);
                break;
            case '3':        
                generateStoryLine();
                break;
            case '4':
                saveGeneratedStory(fileSaveStoryLine);
                break;
            case '5':
                displayText(fileSaveStoryLine);
                break;
            default:
                cout<<"Select Approproate Option.."<<endl;
        }
    }
}


void displayText(string fileName){
    ifstream fileToRead;
    fileToRead.open(fileName);
    if(fileToRead.is_open()){
        string line = "";
        cout<<endl;
        while(!fileToRead.eof()){
            getline(fileToRead,line);
            cout<<line<<endl;
        }
    }else{
        cout<<"\n Sorry can't run this at the moment. \n";
    }
}


bool dataLoaded(){
    if(settingsList.size()==0||charactersList.size()==0||situationsList.size()==0){
        return false;
    }else{
        return true;
    }
}



void createLists(string fileName){
    cout<<"Data loading from "<<fileName<<endl;

    if(dataLoaded()){
        cout<<"Data is already present"<<endl;
        return;
    }

    ifstream fileToRead;
    fileToRead.open(fileName);

    int dataType = 1;

    if(fileToRead.is_open()){
        string line = "";
        while(!fileToRead.eof()){
            getline(fileToRead,line,';');
           int streamType = checkString(line);
            if(streamType!=0){
                dataType = streamType;
            }else{
                storeIntoList(dataType,line);
            }

        }
        fileToRead.close();
    }else{
        cout<<"\n Sorry can't run this at the moment. \n";
    }
}

void storeIntoList(int dataType,string data){
    switch(dataType){
        case 1:
            settingsList.push_back(data);
            break;
        case 2:
            charactersList.push_back(data);
            break;
        case 3:
            situationsList.push_back(data);
            break;
    }    
}


int checkString(string text){
    if(text=="Settings Data"){
        return 1;
    }else if(text=="\nCharacters Data"){
        return 2;
    }else if(text=="\nSituations Data"){
        return 3;
    }else{
        //cout<<text<<endl;
        return 0;
    }
}


string randomDataFromSettings(){
    int listSize = settingsList.size();
    int randomIndex = rand()%listSize;
    return settingsList.at(randomIndex);
}

string randomDataFromCharacters(){
    int listSize = charactersList.size();
    int randomIndex = rand()%listSize;
    return charactersList.at(randomIndex);
}

string randomDataFromSituations(){
    int listSize = situationsList.size();
    int randomIndex = rand()%listSize;
    return situationsList.at(randomIndex);
}

void generateStoryLine(){
    if(!dataLoaded()){
        createLists(fileStoryData);
    }
    srand(unsigned(time(NULL)));
    string settingsRandom = randomDataFromSettings();
    string characterRandom = randomDataFromCharacters();
    string situationRandom = randomDataFromSituations();
    generatedLine =  settingsRandom+"\n"+characterRandom+"\n"+situationRandom+"\n";
    cout<<endl<<generatedLine<<endl;
}

void saveGeneratedStory(string fileName){
    if(generatedLine==""){
        cout<<"Please generate a story line first..."<<endl;
        return;
    }

    cout<<endl<<generatedLine<<endl;
    char userInput = userChoice("Do you want to save the story line? (y/n): ");
    saveStory(userInput,fileName);

}

void saveStory(char userInput,string fileName){
    if(userInput=='y'||userInput=='Y'){
        ofstream fileToWrite;
        fileToWrite.open(fileName,ios_base::app);
        if(fileToWrite.is_open()){
            fileToWrite<<generatedLine+"\n";
            fileToWrite.close();
        } 
    }
}