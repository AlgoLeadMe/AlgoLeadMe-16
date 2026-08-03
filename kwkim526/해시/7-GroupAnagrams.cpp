class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;
        vector<vector<string>> answers;
        
        for(const auto& s: strs)
        {
            vector<int> alphabetCounts(26);
            for(const auto c : s)
            {
                alphabetCounts[c-'a']++;
            }
            string key;
            for(int i = 0; i < 26; i++)
            {
                key += to_string(alphabetCounts[i]) + "#";
            }
            anagramMap[key].push_back(s);
        }
        for(const auto& anagram : anagramMap)
        {
            answers.push_back(anagram.second);
        }
        return answers;
    }
};
