#include <bits/stdc++.h>
using namespace std;
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class graph_maker {
    unordered_map<string, vector<string>> allValues;
    unordered_map<string, string> bestPath;
    vector<string> init;
public:
    graph_maker(string filepath) {
        ifstream file(filepath);

        string word;
        while(getline(file, word, '\n'))
            init.emplace_back(word);
        
        process_init(); // O(n * 26 ^ 4)
    }

    void process_word(const string& word) {
        for(size_t i{}; i < 4; i++) {
            string cpy = word;
            for(char j{'A'}; j <= 'Z'; j++) {
                cpy[i] = j;
                auto it = allValues.find(cpy);
                if(it != allValues.end()) {
                    it->second.emplace_back(word);
                    allValues[word].emplace_back(cpy);
                }
            }
        }
        allValues[word]; // Construct if doesn't exist yet
    }

    void find_best_path() {
        queue<string> start;
        start.push("POOP");
        bestPath["POOP"] = "POOP";
        unordered_set<string> visited{"POOP"};

        while(!start.empty()) {
            string curr = start.front(); start.pop();

            for(const auto& val : allValues[curr]) {
                if(visited.find(val) == visited.end()) {
                    visited.insert(val);
                    bestPath[val] = curr;
                    start.push(val);
                }
            }
        }

        vector<string> not_connected{};
        for(const auto& [key, _] : allValues) {
            if(bestPath.find(key) == bestPath.end())
                not_connected.emplace_back(key);
        }

        cout << (not_connected.empty() ? "All nodes are connected\n" : "The keys that are not connected are:\n");

        for(auto& s : not_connected) 
            cout << s << "\n";
    }

    void process_init() {
        for(const string& word : init) {
            process_word(word);
        }
        
        // Now poop exists in our set we should find our best path
        find_best_path();
    }

    auto& get_best_path() {
        return bestPath;
    }
};

int main() {
    graph_maker g("words.txt");

    json j = g.get_best_path();

    ofstream output("saved_map.json");

    if(output.is_open()) {
        output << j.dump(4);
        output.close();
    } else {
        cout << "Failed to save\n";
    }


}