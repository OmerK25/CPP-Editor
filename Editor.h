#pragma once
#include "Document.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <ctype.h>

using namespace std;

class Editor
{
public:
    Document d;

    void loop();

    //Constructor & Distructor

    Editor(string fileNameFromTerminal)
    {
        ifstream file(fileNameFromTerminal);

        if (!file)
            cout << "file doesn't opening!" << endl;

        for (string line; getline(file, line);)
        {
            d.Lines.push_back(line);
        }
        file.close();
    }

    Editor()
    {
        d.setCurrentLine(-1);
    }

    ~Editor() {}
};