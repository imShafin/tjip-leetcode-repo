// TC: O(26*N)
// MC: O(26*26*N)

class Trie {
public:
    bool isWord;
    Trie* next[26];
    Trie() {
        isWord = false;
        for(int i = 0; i < 26; i++)
            next[i] = NULL;
    }

    void insert(string word) {
        Trie* currNode = this;
        for (auto ch :  word) {
            int order = ch - 'a';
            if(currNode->next[order] == NULL)
                currNode->next[order] = new Trie();
            currNode = currNode->next[order];
        }
        currNode->isWord = true;
    }

    bool search(string word, bool isPrefix = false) {
        Trie* currNode = this;
        for (auto ch : word)
        {
            int order = ch - 'a';
            if (currNode->next[order] == NULL)
                return  false;
            currNode = currNode->next[order];
        }
        return currNode && (currNode->isWord || isPrefix);
    }

    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};
