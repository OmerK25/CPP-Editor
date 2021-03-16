#include "Editor.h"

void Editor::loop()
{
    while (1)
    {
        char c = getchar();
        if (isdigit(c))
        {
            int to = c - '0';
            d.moveTo(to - 1);
        }

        switch (c)
        {
        case '+':
            d.plus();
            break;

        case '-':
            d.minus();
            break;

        case 'a':
            d.addTextAfter();
            break;

        case 'i':
            d.addTextBefore();
            break;

        case '$':
            d.moveToLastLine();
            break;

        case 'c':
            d.swichTextLines();
            break;

        case 'd':
            d.removeLine();
            break;

        case '/':
            d.search();
            break;

        case 'j':
            d.connectLines();
            break;

        case 's':
            d.switchOldWordWithNew();
            break;

        case 'w':
            d.writeToFile();
            break;

        case 'q':
            exit(1);
            break;

        default:
            if (c != '\n')
                std::cout << "?" << std::endl;
            break;
        }
    }
}