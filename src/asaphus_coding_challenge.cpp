/**
 * @file asaphus_coding_challenge.cpp
 * @version 1.1
 * @copyright Copyright (c) 2022 Asaphus Vision GmbH
 *
 * The goal is to implement the mechanics of a simple game and write test cases for them.
 * The rules of the game are:
 * - There are two types of boxes, green and blue. 
 * - Both can absorb tokens of a given weight, which they add to their own total weight. 
 * - Both are initialized with a given initial weight.
 * - After a box absorbs a token weight, it outputs a score. 
 * - Green and blue boxes calculate the score in different ways:
 * - A green box calculates the score as the square of the mean of the 3 weights that it most recently absorbed (square of mean of all absorbed weights if there are fewer than 3).
 * - A blue box calculates the score as Cantor's pairing function of the smallest and largest weight that it has absorbed so far, i.e. pairing(smallest, largest), where pairing(0, 1) = 2
 * - The game is played with two green boxes with initial weights 0.0 and 0.1, and two blue boxes with initial weights 0.2 and 0.3.
 * - There is a list of input token weights. Each gets used in one turn.
 * - There are two players, A and B. Both start with a score of 0. 
 * - The players take turns alternatingly. Player A starts.
 * - In each turn, the current player selects one of the boxes with the currently smallest weight, and lets it absorb the next input token weight. Each input weight gets only used once.
 * - The result of the absorption gets added to the current player's score.
 * - When all input token weights have been used up, the game ends, and the player with highest score wins.
 *
 * Task:
 * - Create a git repo for the implementation. Use the git repository to have a commit history.
 * - Implement all missing parts, marked with "TODO", including the test cases.
 * - Split the work in reasonable commits (not just one commit).
 * - Make sure the test cases succeed.
 * - Produce clean, readable code.
 *
 * Notes:
 * - Building and running the executable: g++ --std=c++14 asaphus_coding_challenge.cpp -o challenge && ./challenge
 * - Feel free to add a build system like CMake, meson, etc.
 * - Feel free to add more test cases, if you would like to test more.
 * - This file includes the header-only test framework Catch v2.13.9.
 * - A main function is not required, as it is provided by the test framework.
 */

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
#include <list>
#include <memory>
#include <numeric>
#include <vector>

#define CATCH_CONFIG_MAIN
#include "includes/catch.hpp"

class Box {
 public:
  explicit Box(double initial_weight) : weight_(initial_weight) {}
  static std::unique_ptr<Box> makeGreenBox(double initial_weight);
  static std::unique_ptr<Box> makeBlueBox(double initial_weight);
  bool operator<(const Box& rhs) const { return weight_ < rhs.weight_; }

  // TODO
  double get_weight() const{
        return weight_;
        }


  // Pure Virtual Functions
  virtual double generateScore(const std::vector<double>& weights) = 0;

 protected:
  double weight_;
};

// TODO
class GreenBox : public Box{
public:
    using Box::Box;
    
    //compute mean using the absorbed input
    double computeMean(const std::vector<double> &temp){
        if (temp.empty()) {
            return 0;
        }
        // if the elements are less than 3 take all of them, else take the last three weights
        if(temp.size()<3){
            return std::accumulate(temp.begin(), temp.end(), 0.0) / temp.size();
        }else{
            return std::accumulate(temp.end()-3, temp.end(), 0.0) / 3;
        }
    }

    //generates score for the green box
    double generateScore(const std::vector<double>& weights) override{
        auto mean =computeMean(weights);
        return mean*mean;
        }
      
 
    };

class BlueBox:public Box{
public:
    using Box::Box;

    //generates score for the blue box
    double generateScore(const std::vector<double>& weights) override{
        // identify the smallest and the largest absorbed weight
        double smallest {0.0};
        double largest {0.0};
        //if only one element is absorbed by the box, the smallest and the largest element are the same
        if(weights.size() ==1){
             smallest = weights[0];
             largest = weights[0];
           
        }else{
             smallest = *std::min_element(weights.begin(), weights.end());
             largest = *std::max_element(weights.begin(), weights.end());
        }
        //compute the Cantor pairing and return the score
         return 0.5 * (smallest + largest) * (smallest + largest + 1) + largest;
            
    }
    
    };

std::unique_ptr<Box> Box::makeGreenBox(double initial_weight) {
    return std::make_unique<GreenBox>(initial_weight);
}

std::unique_ptr<Box> Box::makeBlueBox(double initial_weight) {
    return std::make_unique<BlueBox>(initial_weight);
}



class Player {
 public:
  void takeTurn(uint32_t input_weight,
                const std::vector<std::unique_ptr<Box> >& boxes) {
    // TODO
  }
  double getScore() const { return score_; }

 private:
  double score_{0.0};
};

std::pair<double, double> play(const std::vector<uint32_t>& input_weights) {
  std::vector<std::unique_ptr<Box> > boxes;
  boxes.emplace_back(Box::makeGreenBox(0.0));
  boxes.emplace_back(Box::makeGreenBox(0.1));
  boxes.emplace_back(Box::makeBlueBox(0.2));
  boxes.emplace_back(Box::makeBlueBox(0.3));

  // TODO
  Player player_A, player_B;

  //PlayerA and PlayerB takes alternate turns. (Game starts with PlayerA)
  //Iterate over the input_weights
   for(size_t i=0 ; i<input_weights.size() ;i++){

          if (i%2 == 0){
              player_A.takeTurn(input_weights[i], boxes);
            }else{
              player_B.takeTurn(input_weights[i], boxes);
            }

  std::cout << "Scores: player A " << player_A.getScore() << ", player B " << player_B.getScore() << std::endl;
   }
    return std::make_pair(player_A.getScore(), player_B.getScore());
  }

/* 
TEST_CASE("Final scores for first 4 Fibonacci numbers", "[fibonacci4]") {
  std::vector<uint32_t> inputs{1, 1, 2, 3};
  auto result = play(inputs);
  REQUIRE(result.first == 13.0);
  REQUIRE(result.second == 25.0);
} */

/* TEST_CASE("Final scores for first 8 Fibonacci numbers", "[fibonacci8]") {
  std::vector<uint32_t> inputs{1, 1, 2, 3, 5, 8, 13, 21};
  auto result = play(inputs);
  REQUIRE(result.first == 155.0);
  REQUIRE(result.second == 366.25);
}
 */

TEST_CASE("Test absorption of green box", "[green]") {
  // TODO
  auto greenBox = Box::makeGreenBox(0.0);
  REQUIRE(greenBox->generateScore({1}) == 1.00);
  REQUIRE(greenBox->generateScore({1,5}) == 9.00);
}

TEST_CASE("Test absorption of blue box", "[blue]") {
  // TODO
  auto bluebox = Box::makeBlueBox(0.2);
  REQUIRE(bluebox->generateScore({2}) == 12);
  REQUIRE(bluebox->generateScore({2,13}) == 133.0);
}
