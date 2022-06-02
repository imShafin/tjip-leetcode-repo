// TC: O(N*S) N is the length of searchWord string
// MC: O(S) S is sum of all strings at products
class Solution {
public:
    class Trie
    {
      public:
        string word;
        Trie* next[26];
        Trie ()
        {
          word = "";
          for(int i = 0; i < 26; i++) next[i] = NULL;
        }
    };
    Trie* generateTrie(vector<string>& products) {
      Trie* root = new Trie();
      for (auto& pro : products)
      {
        Trie* curr = root;
        for (auto& ch : pro)
        {
          int order = ch - 'a';
          if (curr->next[order] == NULL) curr->next[order] = new Trie();
          curr = curr->next[order];
        }
        curr->word = pro;
      }
      return root;
    }

    void dfs(Trie* u, vector<string>& words)
    {
      if (u == NULL || words.size() == 3) return;
      if (u->word.size() > 0 && words.size() < 3)
        words.push_back(u->word);
      for(int i = 0; i < 26; i++) dfs(u->next[i], words);
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
      Trie* root = generateTrie(products);
      vector<vector<string>> res;
      for (auto ch : searchWord)
      {
        root = root && root->next[ch - 'a'] ? root->next[ch - 'a'] : NULL;
        vector<string> words;
        dfs(root, words);
        res.push_back(words);
      }
      return res;
    }
};
