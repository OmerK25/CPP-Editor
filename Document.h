#pragma once
#include <vector>
#include <string>
#include <stdio.h>
#include <iterator>
#include <fstream>
#include <iostream>

using namespace std;

class Document
{
public:
    vector<string> Lines;
    int currentLine = 1;

    //Constructor & Distructor
    ~Document() {}

    //Getters & Setters
    vector<string> getLines()
    {
        return Lines;
    }
    void setLines(vector<string> newLines)
    {
        Lines = newLines;
    }
    int getCurrentLine()
    {
        return currentLine;
    }
    void setCurrentLine(int newCurrentLine)
    {
        currentLine = newCurrentLine;
    }

    //Functions:
    void minus();

    void plus();

    void moveTo(int moveToLine);

    void addTextAfter();

    void addTextBefore();

    void swichTextLines();

    void removeLine();

    void moveToLastLine();

    void search();

    void switchOldWordWithNew();

    void connectLines();

    void writeToFile();

    void quitTheEditor();
};