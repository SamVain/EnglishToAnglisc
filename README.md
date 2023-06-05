# English to Anglish Translator (C++)

This is a basic program that translates English text into Anglish. Anglish is a form of English linguistic purism, which favours words of native (Germanic) origin over those of foreign (mainly Latin and Greek) origin.

The project is written in C++ and uses simple string replacement operations to make the translations.

## Code

Here's a simplified snippet of the main logic in the translator:

```cpp
#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>

std::vector<std::pair<std::string, std::string>> TRANSFORMATIONS = {
    // Your transformations here...
};

void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}

std::string translate_to_anglish(const std::string& english) {
    std::istringstream ss(english);
    std::string anglish = "";
    std::string word;
    while (ss >> word) {
        for(auto const& pair: TRANSFORMATIONS) {
            replaceAll(word, pair.first, pair.second);
        }
        anglish += word + " ";
    }
    return anglish;
}

int main() {
    std::string english_text = "This is some sample English text.";
    std::cout << "English: " << english_text << std::endl;
    std::string anglish_text = translate_to_anglish(english_text);
    std::cout << "Anglish: " << anglish_text << std::endl;

    return 0;
}
```

## Examples
Given the input text: "This is some sample English text." The output would be: "Þis is sum sampel Englisc text."

Please note that the actual output will depend on the transformations that you have defined in your code.

## Limitations
This translator performs simple string replacements based on the transformations defined in the TRANSFORMATIONS vector. It doesn't take into account the context in which a word is used, which can lead to incorrect or nonsensical translations for certain words or sentences.