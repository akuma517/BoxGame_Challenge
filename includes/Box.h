#ifndef BOX_H
#define BOX_H

#include <memory>
#include <vector>

class Box {
 private:
    std::vector<double> inputWeightTracker; 

 protected:
  double weight_;

 public:
  explicit Box(double initial_weight);
  static std::unique_ptr<Box> makeGreenBox(double initial_weight);
  static std::unique_ptr<Box> makeBlueBox(double initial_weight);
  bool operator<(const Box& rhs) const;
  double get_weight() const;
  // update the weight of each box after absorbing
  void update_box_weight(const double newBoxWeight);
  // Pure Virtual Functions
  virtual double generateScore(const std::vector<double>& weights) = 0;
  //track the weights absorbed by the boxes in each iteration
  const std::vector<double> updateInputWeightTracker(const double inputWeight);
};


#endif // BOX_H