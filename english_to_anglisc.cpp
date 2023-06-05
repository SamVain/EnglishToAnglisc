#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<std::pair<std::string, std::string>> transformations = {
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
    {"tch", "c"},
    {"dge", "cg"},
    {"ough", "uge"},
    {"wh", "hƿ"},
    {"qu", "cƿ"},
    {"ch", "c"},
    {"gh", "g"},
    {"ie", "ee"},
    {"le", "el"},
    {"ou", "u"},
    {"ow", "u"},
    {"th", "þ"},
    {"sh", "sc"},
    {"c", "s"},
    {"o", "u"},
    {"u", "eƿ"},
    {"v", "f"},
    {"w", "ƿ"},
    {"y", "g"},
    {"z", "s"}};

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
    std::string anglish = english;
    for (auto &pair : transformations)
    {
        replaceAll(anglish, pair.first, pair.second);
    }
    return anglish;
}

int main()
{
    std::string english_text = "This is some sample English text. Affright, anneal, ghost, island, scythe, and neighbour.";
    std::cout << "English: " << english_text << std::endl;
    std::cout << "Anglish: " << translate_to_anglish(english_text) << std::endl;

    return 0;
}
