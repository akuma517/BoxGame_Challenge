#ifndef BLUEBOX_H
#define BLUEBOX_H

#include "Box.h"
#include <algorithm> 
#include <numeric>  //includes <numeric> for std::accumulate
#include <vector>  // includes <vector> for std::vector


class BlueBox: public Box{
public:
    BlueBox(double initial_weight);
    //generates score for the blue box
    double generateScore(const std::vector<double>& weights) override;
    };

#endif  // BLUEBOX_H
