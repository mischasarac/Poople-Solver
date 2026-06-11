# Poople-Solver
I saw a funny game today called the **Poople**. It reminded me of a LeetCode problem I'd done recently, and so I was inspired to make this solver based on the connected graph components of the words available in the game.

Since it's been a few weeks since I've done anything C++ related, I wanted to just build something fun that challenged my brain a little after work, so I decided to build this. 

You can probably see my very inefficient implementation in the `graph_construct.cpp` file, but I figured I should show my implementation instead of hiding behind my constructed JSON. Yes, I do realise that my construct could be made about 25x faster if I just used tombstone values instead of iterating through all 26 letters, but that would take some data cleaning.

I was also curious to see what words aren't a part of the solvable set, so if you run the graph constructor, you will be able to see which words are impossible to solve (I think).


If you want to play the game for yourself, I'll leave a link [here](https://poople.io/)

## Usage
I wrote this code in about 30 minutes so it's certainly not the cleanest, but if you want to try the solver for yourself, just run the `solver.cpp` with
```bash
g++ -std=c++11 solver.cpp -o solver
./solver
```
