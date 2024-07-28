#include <iostream>
#include <string>
#include "readingFile.h"
#include "levenshtain.h"
#include <vector>
using namespace std;


int main() {
    //read file
    readingFile reader("text.txt");
    if (!reader.open()) {
        return 1;
    }
    readingFile readersecond("text2.txt");
    if(!readersecond.open()){
        return 1;
    }



    string content1, content2, line, line2;
    while (reader.readLine(line)) {
        cout << line << std::endl;
        content1 += line + "\n";

    }
    cout<<endl;
    while (readersecond.readLine(line2)) {
        cout << line2 << std::endl;
        content2 += line2 + "\n";
    }

    reader.close();
    readersecond.close();


    int distance = LevenshteinDistance::calculate(content1, content2);
    double similarity = LevenshteinDistance::similarity(content1, content2);


    cout<<endl;
    cout << "Levenshtein Distance: " << distance << endl;
    cout << "Similarity: " << similarity << "%" << endl;


    return 0;
}
