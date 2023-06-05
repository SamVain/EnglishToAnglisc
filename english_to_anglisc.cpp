#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>

std::vector<std::pair<std::string, std::string>> TRANSFORMATIONS = {
    {"accursed", "acursed"},
    {"allay", "alay"},
    {"afford", "aford"},
    {"affright", "afright"},
    {"anneal", "aneal"},
    {"guess", "gess"},
    {"guest", "gest"},
    {"guild", "gild"},
    {"ache", "ake"},
    {"acre", "aker"},
    {"ghastly", "gastly"},
    {"ghost", "goast"},
    {"harbour", "harbor"},
    {"island", "iland"},
    {"liar", "lier"},
    {"lily", "lilly"},
    {"mould", "mold"},
    {"neighbour", "neigbor"},
    {"Rhine", "Rine"},
    {"rhyme", "rime"},
    {"sailor", "sailer"},
    {"scythe", "sithe"},
    {"tongue", "tung"},
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
