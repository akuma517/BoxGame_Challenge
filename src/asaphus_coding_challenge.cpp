#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
#include <list>
#include <memory>
#include <numeric>
#include <vector>
#include<iostream>

#include "Box.h"
#include "Player.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

namespace PlayGame{
  std::pair<double, double> play(const std::vector<uint32_t>& input_weights) {
    std::vector<std::unique_ptr<Box> > boxes;
    boxes.emplace_back(Box::makeGreenBox(0.0));
    boxes.emplace_back(Box::makeGreenBox(0.1));
    boxes.emplace_back(Box::makeBlueBox(0.2));
    boxes.emplace_back(Box::makeBlueBox(0.3));

    Player player_A, player_B;

    //PlayerA and PlayerB takes alternate turns. (Game starts with PlayerA)
    //Iterate over the input_weights
    std::cout << "NEW GAME "<<std::endl;
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
}

using namespace PlayGame;

//   int main() {
//     //std::vector<uint32_t> input_weights = {0}; // Example input weights
//     // TC1
//     //std::vector<uint32_t> input_weights ={1, 1, 2, 3};
//     //TC2
//     // std::vector<uint32_t> input_weights ={1, 1, 2, 3, 5, 8, 13, 21};
//     auto scores = play(input_weights);
//     std::cout << "Final Scores: Player A " << scores.first << ", Player B " << scores.second << std::endl;
//     return 0;
// } 


TEST_CASE("Final scores for first 4 Fibonacci numbers", "[fibonacci4]") {
  std::vector<uint32_t> inputs{1, 1, 2, 3};
  auto result = play(inputs);
  REQUIRE(result.first == 13.0);
  REQUIRE(result.second == 25.0);
} 

TEST_CASE("Final scores for first 8 Fibonacci numbers", "[fibonacci8]") {
  std::vector<uint32_t> inputs{1, 1, 2, 3, 5, 8, 13, 21};
  auto result = play(inputs);
  REQUIRE(result.first == 155.0);
  REQUIRE(result.second == 366.25);
}

TEST_CASE("Test absorption of green box", "[green]") {
  // TODO
  //Test:: When no weights have been absorbed by the box
  auto green_box = Box::makeGreenBox(0.1);
  const std::vector<double> weights = green_box->Box::updateInputWeightTracker(static_cast<double>(1.0));
  REQUIRE(green_box->generateScore(weights) == 1.00);

  auto updatedBoxWeight = green_box->getWeight() + static_cast<double>(1.0);
  green_box->updateBoxWeight(updatedBoxWeight);
  REQUIRE(green_box->getWeight() == 1.10);

  //Test:: A weight has been absorbed by the box
  const std::vector<double> weights_2 = green_box->Box::updateInputWeightTracker(static_cast<double>(8.0));
  REQUIRE(green_box->generateScore(weights_2) == 20.25);

  auto updatedBoxWeight_2 = green_box->getWeight() + static_cast<double>(8.0);
  green_box->updateBoxWeight(updatedBoxWeight_2);
  REQUIRE(green_box->getWeight() == 9.10);


  REQUIRE(green_box->generateScore({1,5}) == 9.00);

  }

TEST_CASE("Test absorption of blue box", "[blue]") {

  auto blue_box = Box::makeBlueBox(0.2);
  //Test:: When no weights have been absorbed by the box
  const std::vector<double> weights = blue_box->Box::updateInputWeightTracker(static_cast<double>(2.0));
  REQUIRE(blue_box->generateScore(weights) == 12.00);

  auto updatedBoxWeight = blue_box->getWeight() + static_cast<double>(2.0);
  blue_box->updateBoxWeight(updatedBoxWeight);
  REQUIRE(blue_box->getWeight() == 2.2);

  //Test:: A weight has been absorbed by the box
  const std::vector<double> weights_2 = blue_box->Box::updateInputWeightTracker(static_cast<double>(13.0));
  REQUIRE(blue_box->generateScore(weights_2) == 133.00);

  auto updatedBoxWeight_2 = blue_box->getWeight() + static_cast<double>(13.0);
  blue_box->updateBoxWeight(updatedBoxWeight_2);
  REQUIRE(blue_box->getWeight() == 15.2);

  REQUIRE(blue_box->generateScore({2}) == 12);
  REQUIRE(blue_box->generateScore({2,13}) == 133.0);
}
