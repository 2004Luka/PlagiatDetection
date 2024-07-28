//
// Created by luka on 7/28/24.
//

#ifndef CPPCODES_READINGFILE_H
#define CPPCODES_READINGFILE_H
#include <string>
#include <fstream>
#include <iostream>

using namespace std;
class readingFile{
private:
    string filename;
    ifstream input;
public:
    readingFile(const string& file):filename(file){}
    //opening file
    bool open(){
        input.open(filename);
        if(!input){
            cout << "error opening file "<<filename<<endl;
            return false;
        }
        return true;
    }

    bool readLine(string& line){
        if(getline(input,line)){
            return true;
        }
        return false;
    }


    void close(){
        if(input.is_open()){
            input.close();
        }
    }

    //destructor
    ~readingFile(){
        close();
    }
};


#endif //CPPCODES_READINGFILE_H
