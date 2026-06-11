#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <stdexcept>

#include <nlohmann/json.hpp>

using json = nlohmann::json;
using smap = std::unordered_map<std::string, std::string>;

std::vector<std::string> solve_path(const std::string& start, smap& tree) {
    std::vector<std::string> path{start};
    std::string curr = start;
    auto it = tree.find(curr);
    while(it != tree.end() && curr != "POOP") {
        curr = it->second;
        path.emplace_back(curr);
        it = tree.find(curr);
    }

    return path;
}

smap get_tree(std::string path) {
    std::ifstream file(path);
    if(!file.is_open()) {
        std::cerr << "Failed to open file.\n";
        throw 404;
    }

    json data = json::parse(file);

    return data.get<smap>();

}

int main() {
    std::string startingWord;
    std::cout << "Enter your starting word: ";
    std::cin >> startingWord;

    smap tree = get_tree("saved_map.json");

    std::vector<std::string> solN = solve_path(startingWord, tree);

    std::cout << "Best solution is: \n";

    for(auto& s : solN) {
        std::cout << s << "\n";
    }

}