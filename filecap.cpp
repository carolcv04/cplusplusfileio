#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main (int argc, char*argv[]){
    string file, line;
    file = argv[1];

    try{
        ofstream fout;
        ifstream fin;
        fin.open("text.txt", ios::in);

        if(!fin){
            throw string("File does not exist.\n");
        }
        else {
            char x;
            fout.open(file, ios::out);
            while (getline(fin, line)) {
                fout << endl;
                for(int i=0; i < line.size(); i++){
                    x = line[i];

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
    }
    catch (string error){
        cout << error;
    }
    return 0;
}