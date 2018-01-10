#include <string>
#include <vector>
#include <iostream>

// silly solution :unamused:

int getScoreFor(const std::string& src_word, const std::string& sub_word) {
    if (src_word.size() < sub_word.size()) return 0;
    int outer_index = 0;
    bool exists = false;
    for (int ix = 0; ix < sub_word.size(); ++ix) {
        exists = false;
        for (int jx = outer_index; jx < src_word.size(); ++jx) {
            if (src_word[jx] == sub_word[ix]) {
                exists = true;
                outer_index = jx;
                break;
            }
        }
        if (!exists) return 0;
    }
    return sub_word.size();
}

std::string getBiggestSubsequence(const std::string& src_word, const std::vector<std::string>& words) {
    if (src_word.empty() || words.size() == 0) {
        return "";
    }
    std::vector<int> score;
    for (auto elem : words) {
        score.push_back(getScoreFor(src_word, elem));
    }
    /*
    for (auto s : score) {
        std::cout << "score i = " << s << std::endl;
    }
    */
    int max_value = score[0];
    int max_index = 0;
    for (int ix = 0; ix < score.size(); ++ix) {
        if (max_value < score[ix]) {
            max_value = score[ix];
            max_index = ix;
        }
    }
    return words[max_index];
}

int main() {
    std::string src_word = "abppplee";
    std::vector<std::string> words;// {"able", "ale", "apple", "bale", "kangaroo"};
    words.push_back("able");
    words.push_back("ale");
    words.push_back("apple");
    words.push_back("bale");
    words.push_back("kangaroo");

    std::cout << getBiggestSubsequence(src_word, words) << std::endl;
}
