#include "Box.h"
#include "GreenBox.h"
#include "BlueBox.h"

Box::Box(double initial_weight) : weight_(initial_weight) {}

std::unique_ptr<Box> Box::makeGreenBox(double initial_weight) {
    return std::make_unique<GreenBox>(initial_weight);
}

std::unique_ptr<Box> Box::makeBlueBox(double initial_weight) {
    return std::make_unique<BlueBox>(initial_weight);
}

bool Box::operator<(const Box& rhs) const {
     return weight_ < rhs.weight_; 
    }


double Box::getWeight() const{
        return weight_;
        }

// update the weight of each box after absorbing
void Box::updateBoxWeight(const double new_box_weight) {
      weight_ = new_box_weight;
    }


//track the weights absorbed by the boxes in each iteration
const std::vector<double> Box::updateInputWeightTracker(const double input_weight){
              inputWeightTracker_.push_back(input_weight);
              return inputWeightTracker_;
    }

