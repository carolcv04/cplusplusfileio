#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main (int argc, char*argv[]){
    string file, line;
    file = argv[1];

    try{
        fstream text;
        text.open('"' + file + '"', ios::in);

        if(!text){
            throw string("File does not exist.\n");
        }
    }
    catch (string error){
        cout << error;
    }
}