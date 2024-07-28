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
        return 1; // Exit if the file cannot be opened
    }
    readingFile readersecond("text2.txt");
    if(!readersecond.open()){
        return 1;
    }
    //output that file

// Concatenate entire file content into single strings
    string content1, content2, line, line2;
    while (reader.readLine(line)) {
        cout << line << std::endl; // Print each line
        content1 += line + "\n"; // Add newline character to preserve line breaks

    }
    cout<<endl;
    while (readersecond.readLine(line2)) {
        cout << line2 << std::endl; // Print each line
        content2 += line2 + "\n"; // Add newline character to preserve line breaks
    }
    // Close the files
    reader.close();
    readersecond.close();

    // Calculate Levenshtein Distance and Similarity
    int distance = LevenshteinDistance::calculate(content1, content2);
    double similarity = LevenshteinDistance::similarity(content1, content2);

    // Output the results
    cout<<endl;
    cout << "Levenshtein Distance: " << distance << endl;
    cout << "Similarity: " << similarity << "%" << endl;


    return 0;
}
