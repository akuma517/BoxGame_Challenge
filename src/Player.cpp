#include "Player.h"
#include "Box.h"
#include<algorithm>

struct BoxCompare {
    bool operator()(const std::unique_ptr<Box>& box1, const std::unique_ptr<Box>& box2) const {
        return box1->getWeight() < box2->getWeight();
    }
};

void Player::takeTurn(uint32_t input_weight, const std::vector<std::unique_ptr<Box> >& boxes) {
     
      // choose the box with minimum weight
      auto& selected_box = *std::min_element(boxes.begin(), boxes.end(), BoxCompare());
      //add the input weight to the absorbed weight tracker; 
      // the absorbed weights are used to generate scores for blue and green boxes
      const std::vector<double> weights = selected_box->updateInputWeightTracker(static_cast<double>(input_weight));

      //use the generate score mechanism based on the box selected (Blue or Green) with the updated absorbed weights vector
      double current_score = selected_box->generateScore(weights);
      scores_.push_back(current_score);

      //update the weight of the selected box; The box absorbs the input weight and add it to its own total weight
      auto new_total_box_weight = selected_box->getWeight() + static_cast<double>(input_weight);
      selected_box->updateBoxWeight(new_total_box_weight);

      //add current score to obtain the final score
      score_ += scores_.back();

  }

double Player::getScore() const { 
        return score_; 
    }
  