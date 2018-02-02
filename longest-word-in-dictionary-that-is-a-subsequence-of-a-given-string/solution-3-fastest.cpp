
// WARNING: potential ugly code below, brace yourself.

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

typedef std::vector<std::string> Words;
typedef std::vector<std::pair<std::string, int> > TupleList;
typedef std::unordered_map<char, TupleList> WordScores;

WordScores getInitialScores(const Words& words)
{
    WordScores scores;
    for (auto w : words) {
        auto& s = scores[w[0]];
        s.push_back(std::make_pair(w, 0));
    }
    return scores;
}

void printScores(const WordScores& scores)
{
    for (auto& s : scores) {
        std::cout << s.first << " -> ";
        auto groups = s.second;
        for (auto g : groups) {
            std::cout << "(" << g.first << ", " << g.second << "), ";
        }
        std::cout << std::endl;
    }
}

std::string getBiggestSubsequence(const std::string& src, const Words& words)
{
    auto scores = getInitialScores(words);
    //printScores(scores);
    std::map<std::string, int> found; // just in case if needed all found items
    std::string max = "";
    for (const auto ch : src) {
        auto& vec = scores[ch];
        for (auto& pair : vec) {
            if (pair.first.size() == pair.second) {
                found[pair.first] = pair.first.size();
                if (pair.first.size() > max.size()) {
                    max = pair.first;
                }
            } else {
                ++pair.second;
                auto& new_vec = scores[pair.first[pair.second]];
                new_vec.push_back(pair);
            }
        }
    }
    /*
    for (auto f : found) {
        std::cout << "found: " << f.first << std::endl;
    }
    */
    return max;
}

int main() {
    std::string src_word = "abppplee";
    std::vector<std::string> words;// {"able", "ale", "apple", "bale", "kangaroo"};
    words.push_back("able");
    words.push_back("ale");
    words.push_back("apple");
    words.push_back("bale");
    words.push_back("kangaroo");

    std::cout << "longest: " << getBiggestSubsequence(src_word, words) << std::endl;
}
