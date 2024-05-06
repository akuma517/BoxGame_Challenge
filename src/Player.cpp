#include "Player.h"
#include "Box.h"
#include<algorithm>

struct BoxCompare {
    bool operator()(const std::unique_ptr<Box>& box1, const std::unique_ptr<Box>& box2) const {
        return box1->get_weight() < box2->get_weight();
    }
};

void Player::takeTurn(uint32_t input_weight, const std::vector<std::unique_ptr<Box> >& boxes) {
     
      // choose the box with minimum weight
      auto& selectedBox = *std::min_element(boxes.begin(), boxes.end(), BoxCompare());
      //add the input weight to the absorbed weight tracker; 
      // the absorbed weights are used to generate scores for blue and green boxes
      const std::vector<double> weights = selectedBox->updateInputWeightTracker(static_cast<double>(input_weight));

      //use the generate score mechanism based on the box selected (Blue or Green) with the updated absorbed weights vector
      double current_score = selectedBox->generateScore(weights);
      scores.push_back(current_score);

      //update the weight of the selected box; The box absorbs the input weight and add it to its own total weight
      auto newTotalBoxWeight = selectedBox->get_weight() + static_cast<double>(input_weight);
      selectedBox->update_box_weight(newTotalBoxWeight);

      //add current score to obtain the final score
      score_ += scores.back();

  }

double Player::getScore() const { 
        return score_; 
    }
  