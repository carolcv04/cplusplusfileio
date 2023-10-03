#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main (int argc, char*argv[]){
    //setting the variables
    string file, line;
    file = argv[1];

    // try to execute the program, catches error if the file
    // does not exist.
    try{
        ofstream fout;
        ifstream fin;

        //opens the main text
        fin.open("text.txt", ios::in);

        //if the file does not exist error will be thrown
        if(!fin){
            throw string("File does not exist.\n");
        }
        else {
            //opens the new file to rewrite the text
            char x;
            fout.open(file, ios::out);
            //loops through each line of the original text
            while (getline(fin, line)) {
                fout << endl;
                // loops through each character of the strig char by char
                for(int i=0; i < line.size(); i++){
                    x = line[i];

                    //converts lower to upper vice versa.
                    // if it is a special char or space, they are added as is.
                    if (isupper(x)){
                        x = tolower(x);
                        fout << x;
                    } else if (islower(x)) {
                        x = toupper(x);
                        fout << x;
                    } else if (!isalpha(x)) {
                        fout << x;
                    } else {
                        fout << " ";
                    }
                }

            }
            fout.close(); 
        }
        fin.close();
    //error is executed/printed here 
    }
    catch (string error){
        cout << error;
    }
    return 0;
}