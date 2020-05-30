#include <bits/stdc++.h>

using namespace std;

const int ALPHABET_SIZE = 26;

class TrieNode
{
private:
    bool isLeaf;
    TrieNode *links[26];
    int size;

public:
    TrieNode()
    {
        this->isLeaf = false;
        this->size = 0;
        fill_n(this->links, 26, nullptr);
    }
    bool containsKey(char ch)
    {
        return this->links[ch - 'a'] != nullptr;
    }
    TrieNode *get(char ch)
    {
        return this->links[ch - 'a'];
    }
    void put(char ch, TrieNode *node)
    {
        this->links[ch - 'a'] = node;
        this->size++;
    }
    void setLeafNode()
    {
        this->isLeaf = true;
        return;
    }
    bool isLeafNode()
    {
        return this->isLeaf;
    }
    int getLinks(){
        return this->size;
    }
};

class Trie
{
private:
    TrieNode *root;

    TrieNode *searchPrefix(string word)
    {
        TrieNode *curr = this->root;
        for (int i = 0; i < word.length(); i++)
        {
            char currChar = word[i];
            if (curr->containsKey(currChar))
            {
                curr = curr->get(currChar);
            }
            else
            {
                return nullptr;
            }
        }
        return curr;
    }

public:
    Trie()
    {
        this->root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *curr = this->root;
        for (int i = 0; i < word.length(); i++)
        {
            char currChar = word[i];
            if (!curr->containsKey(currChar))
            {
                curr->put(currChar, new TrieNode());
            }
            curr = curr->get(currChar);
        }
        curr->setLeafNode();
    }

    //search function searchPrefix and make sure that the last node is the leaf node.
    bool search(string word)
    {
        TrieNode *curr = this->searchPrefix(word);
        return curr != nullptr && curr->isLeafNode();
    }

    //starsWith function searches the word and it does not consider whether the last node is the leaf node or not.
    bool startsWith(string word) {
        TrieNode* curr = searchPrefix(word);
        return curr != nullptr;
    }

    //returns longest common prefix
    string searchLongestPrefix(string word) {
        TrieNode* curr = this->root;
        int i;
        for(i=0;i<word.length();i++){
            char currChar = word[i];
            if(curr->containsKey(currChar) && (curr->getLinks() == 1) && (!curr->isLeafNode())){
                curr = curr->get(currChar);
            }else {
                break;
            }
        }
        return word.substr(0,i);
    }
};

string longestCommonPrefix(vector<string>& strs){
    if(strs.size() == 0)
        return "";
    if(strs.size() == 1)
        return strs[0];
    Trie* trie = new Trie();
    for(auto e:strs){
        trie->insert(e);
    }
    return trie->searchLongestPrefix(strs[0]);
}

main()
{
    vector<string> arr = {"flower","flow","flight"};
    cout << longestCommonPrefix(arr);
}