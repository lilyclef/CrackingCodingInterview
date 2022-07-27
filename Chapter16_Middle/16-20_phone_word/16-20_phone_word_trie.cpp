#include<iostream>
#include<vector>

using namespace std;


class TrieNode {
public:
    char character;
    vector<TrieNode*> children;
    bool is_terminated;

    TrieNode() {
        is_terminated = false;
        children = vector<TrieNode*>(26);
    }
    TrieNode(char c) : character(c) {
        TrieNode();
    }
    char getChar() {
        return character;
    }
    
    void addWord(string word) {
        if (word == "") return;
        char first_char = word[0];
        TrieNode* child = getChild(first_char);
        if (!child) {
            child = new TrieNode(first_char);
            children[first_char - 'a'] = child;
            return;
        }
        
        if (word.size() == 1) {
            child->setTerminates(true);
            return;
        }
        addWord(word.substr(1));

    }
    void setTerminates(bool is_terminated) {
        this->is_terminated = is_terminated;
    }
    TrieNode* getChild(char c) {
        return children[c - 'a'];
    }

};

class Trie {
public:
    Trie(vector<string> list) {
        root = new TrieNode();
        for (string& word : list) {
            root->addWord(word);
        }
    }
    bool __contains(string prefix, bool exact) {
        TrieNode* last = root;
        int i = 0;
        for (i = 0; i < prefix.size(); i++) {
            last = last->getChild(prefix[i]);
            if (!last) return false;
        }
        return !exact || last->is_terminated;
    }
    bool contains(string prefix) {
        return __contains(prefix, false);
    }
    TrieNode* getRoot() {
        return root;
    }
private:
    TrieNode* root;
};


vector<vector<char>> phoneletters = {{}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
vector<char> getPhoneChars(char digit) {
    if (digit - '0' >= 0 && digit - '0' <= 9) return phoneletters[digit - '0'];
    return {};
}

void getValidWords(string number, int index, string prefix, TrieNode* trieNode, vector<string>& results) {
    if (index == number.size()) {
        if (trieNode->is_terminated) {
            results.push_back(prefix);
        }
        return;
    }

    char digit = number[index];
    vector<char> letters = getPhoneChars(digit);
        for (char letter : letters) {
            TrieNode* child = trieNode->getChild(letter);
            if (child) getValidWords(number, index + 1, prefix + letter, child, results);
        }
}
vector<string> getValidPhoneWords(string number, Trie* trie) {
    vector<string> results;
    getValidWords(number, 0, "", trie->getRoot(), results);
    return results;
}
int main() {

}