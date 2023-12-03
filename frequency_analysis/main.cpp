#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

std::string encypt(std::string& str) {
    //caesar encrypt

    srand(unsigned int(time(NULL)));
    std::string cipher_text;

    // use a random from 0-25, anything higher repeats the encrpytion
    int key = rand() % 26;
    for (int i = 0; i < str.length(); i++) {
        if (isalpha(str[i])) {
            cipher_text += (((toupper(str[i]) - 65) + key) % 26 + 65);

        }
        // leave spaces as is
        //else {
            //cipher_text += str[i];
        //}
    }
    //std::cout << "key used: " << key << std::endl;
    return cipher_text;
}

bool compare(std::pair<char, int>& a, std::pair<char, int>& b) {
    return a.second > b.second;
}

int main()
{

    std::string plain_text;
    std::string cipher_text;

    std::cout << "Enter text: ";
    std::getline(std::cin, plain_text);

    cipher_text = encypt(plain_text);
    std::cout << cipher_text << std::endl;


    //---frequency---//
    // store key value pair
    std::unordered_map<char, int> mp;
    for (int i = 0; i < cipher_text.length(); i++) {
        char key = cipher_text[i];
        mp[key]++;
    }

    for (auto it = mp.begin(); it != mp.end(); it++) {
        std::cout << it->first << " : " << it->second << std::endl;
    }


    // arrange hashmap by value in descending order in a vector
    // compare ascii of value with the highest key to 'E'
    // take the difference

    std::vector<std::pair<char, int>> v;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        v.push_back(std::make_pair(it->first, it->second));
    }
    sort(v.begin(), v.end(), compare);

    for (auto it = v.begin(); it != v.end(); it++) {
        std::cout << it->first << " " << it->second << std::endl;
    }

    int key_used = v[0].first - 'E';
    std::cout << "key_used: " << key_used << std::endl;
}