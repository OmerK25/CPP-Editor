#include "Document.h"

void Document::moveTo(int moveToLine)
{
    currentLine = moveToLine;
}

void Document::minus()
{
    string line;
    getline(cin, line);
    if (!line.empty())
    {
        currentLine -= stoi(line);
    }
}

void Document::plus()
{
    string line;
    getline(cin, line);
    if (!line.empty())
    {
        currentLine += stoi(line);
    }
}

void Document::addTextAfter()
{
    for (string line; getline(cin, line);)
    {
        if (!line.empty())
        {
            if (line != ".")
            {
                Lines.emplace(Lines.begin() + (currentLine + 1), line);
                currentLine++;
            }
            else
            {
                return;
            }
        }
    }
}

void Document::addTextBefore()
{

    for (string line; getline(cin, line);)
        if (!line.empty())
        {
            {
                if (line != ".")
                {
                    Lines.emplace(Lines.begin() + (currentLine), line);
                    currentLine++;
                }
                else
                {
                    currentLine--;
                    return;
                }
            }
        }
}

void Document::moveToLastLine()
{
    currentLine = Lines.size() - 1;
    cout << currentLine << endl;
}

void Document::swichTextLines()
{
    Lines.erase(Lines.begin() + currentLine);
    for (string line; getline(cin, line);)
    {
        if (!line.empty())
        {
            if (line != ".")
            {
                Lines.emplace(Lines.begin() + currentLine, line);
            }
            else
            {
                return;
            }
        }
    }
}

void Document::removeLine()
{
    Lines.erase(Lines.begin() + currentLine);
}

void Document::search() // /text/
{
    string line;
    getline(cin, line);
    int original = currentLine;
    if (!line.empty())
    {
        line = line.substr(0, line.size() - 1);
        while (currentLine < Lines.size() - 1)
        {
            size_t found = Lines.at(currentLine + 1).find(line);
            currentLine++;
            if (found != string::npos)
            {
                return;
            }
        }
        currentLine = -1;
        while (currentLine != original)
        {
            size_t found = Lines.at(currentLine + 1).find(line);
            currentLine++;

            if (found != string::npos)
            {
                return;
            }
        }
    }
}

void Document::switchOldWordWithNew()
{
    string oldNew;
    getline(cin, oldNew);
    if (!oldNew.empty())
    {

        if (oldNew.at(0) != '/' || oldNew.at(oldNew.length() - 1) != '/')
        {
            cout << "?" << endl;
            return;
        }
        oldNew = oldNew.substr(1, oldNew.size() - 2);
        try
        {
            string old = oldNew.substr(0, oldNew.find("/"));
            string neword = oldNew.substr(oldNew.find("/") + 1, oldNew.size() - 1);

            Lines.at(currentLine).replace(Lines.at(currentLine).find(old), old.size(), neword);
        }
        catch (out_of_range)
        {
            cout << "?" << endl;
        }
    }
}

void Document::connectLines()
{
    Lines.at(currentLine) += (Lines.at(currentLine + 1));
    Lines.erase(Lines.begin() + currentLine + 1);
}

void Document::writeToFile()
{
    string line;
    getline(cin, line);

    if (!line.empty())
    {
        line = line.substr(1, line.size()); //delete enter

        ofstream output_file(line);
        ostream_iterator<string> output_iterator(output_file, "\n");
        copy(Lines.begin(), Lines.end(), output_iterator);
    }
}
