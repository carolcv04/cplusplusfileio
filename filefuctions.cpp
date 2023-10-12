#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//fuction that capitalizes all the characters in the line
void all_capital(ofstream &write, string &line){
    char x;
    for(int i = 0; i < line.size(); i++){
        x = line[i];
        x = toupper(x);
        write << x;
    }
}
//fuction that lowers all the characters within a line
void all_lower(ofstream &write, string &line){
    char x;
    for(int i = 0; i < line.size(); i++){
        x = line[i];
        x = tolower(x);
        write << x;
    }
}
//fuction that removes all the special characters & numbers on a line
void remove_num_specialchars(ofstream &write, string &line){
    char x;
    for(int i = 0; i < line.size(); i++){
        if (isalpha(line[i]) || (line[i]) == ' '){
            x = line[i];
            write << x;
        }
    }
}
//fuction that displays the user menu and returns the slected number input
char menu(){
    char input = '4';
    //prints the menu until input eqquals 1,2,3
    while(input != '1' && input != '2' && input != '3'){
        try{
            //my menu
            cout << "-----------MENU-----------" << endl;
            cout << "select a number (1,2,3):" << endl;
            cout << "1. capitalize the entire line" << endl;
            cout << "2. lowercase the entire line" << endl;
            cout << "3. remove all puctuation/numbers" << endl;
            cout << "INPUT: ";
            cin >> input;

            //checks if input is a num 1-3, if not error is thrown
            if(input != '1' && input != '2' && input != '3'){
                input = '0';
                //asking for common sense
                throw string("ERROR: Please.. input a number 1-3\n");
            }
        } catch (string letter){
            cout << letter;
        }
    }
    return input;
}

int main(){
    try{
        //declaring variables
        ofstream write;
        ifstream read;
        string line;
        int num_line = 0;

        //opening the input and output files
        //input
        read.open("input.txt", ios::in);
        //output
        write.open("output.txt", ios::out);

        //if the file does not open. error is thrown
        if(!read || !write){
            throw string("File does not exist/could not be opened\n");
        }

        //reads each lines of the file
        while(getline(read, line)){
            cout << "YOU ARE EDITING LINE: " << num_line++ << endl;
            char input = menu();
            //depending on the input, case is selected
            switch(input){
                //capitalizes the whole line 
                case '1':
                    all_capital(write, line);
                    break;
                //lowers the whole line
                case '2':
                    all_lower(write, line);
                    break;
                //removes all the numbers and special chars from a line
                case '3':
                    remove_num_specialchars(write, line);
                    break;
            }
            //starts a new line
            write << endl;
        }
        //closes the input and output file
        write.close();
        read.close();

    } catch (string error){
        cout << error;
    }
    return 0;
}