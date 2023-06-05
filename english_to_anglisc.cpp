#include <iostream>
#include <unordered_map>
#include <map>
#include <sstream>

std::unordered_map<std::string, std::string> TRANSFORMATIONS = {
    {"c", "s"},
    {"ch", "c"},
    {"tch", "c"},
    {"dge", "cg"},
    {"gh", "g"},
    {"ie", "ee"},
    {"le", "el"},
    {"o", "u"},
    {"ou", "u"},
    {"ow", "u"},
    {"ough", "uge"},
    {"qu", "cƿ"},
    {"sh", "sc"},
    {"th", "þ"},
    {"u", "eƿ"},
    {"v", "f"},
    {"w", "ƿ"},
    {"wh", "hƿ"},
    {"y", "g"},
    {"z", "s"},
};

std::map<char, char> translation_map = {
    {'a', 'A'},
    {'b', 'B'},
    {'c', 'C'},
    {'d', 'D'},
    {'e', 'E'},
    {'f', 'F'},
    {'g', 'G'},
    {'h', 'H'},
    {'i', 'I'},
    {'j', 'J'},
    {'k', 'K'},
    {'l', 'L'},
    {'m', 'M'},
    {'n', 'N'},
    {'o', 'O'},
    {'p', 'P'},
    {'q', 'Q'},
    {'r', 'R'},
    {'s', 'S'},
    {'t', 'T'},
    {'u', 'U'},
    {'v', 'V'},
    {'w', 'W'},
    {'x', 'X'},
    {'y', 'Y'},
    {'z', 'Z'},
    {'\xc6', '\x7F'},
    {'\xc8', '\x80'}};

void replaceAll(std::string &str, const std::string &from, const std::string &to)
{
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}

std::string translate_to_anglish(const std::string &english)
{
    std::istringstream ss(english);
    std::string anglish = "";
    std::string word;
    while (ss >> word)
    {
        for (auto const &pair : TRANSFORMATIONS)
        {
            replaceAll(word, pair.first, pair.second);
        }
        for (char &c : word)
        {
            if (translation_map.find(c) != translation_map.end())
            {
                c = translation_map[c];
            }
        }
        anglish += word + " ";
    }
    return anglish;
}

int main()
{
    std::string english_text = "This is some sample English text.";
    std::cout << "English: " << english_text << std::endl;
    std::string anglish_text = translate_to_anglish(english_text);
    std::cout << "Anglish: " << anglish_text << std::endl;

    return 0;
}
