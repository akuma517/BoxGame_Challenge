#ifndef GREENBOX_H
#define GREENBOX_H

#include "Box.h"

#include <algorithm>
#include <numeric>  //includes <numeric> for std::accumulate
#include <vector>   // includes <vector> for std::vector

class GreenBox : public Box{
    private:
        //compute mean using the absorbed input
        double computeMean(const std::vector<double> &temp);

    public:
        GreenBox(double initial_weight);
        //generates score for the green box
        double generateScore(const std::vector<double>& weights) override;   
        
};


#endif //GREENBOX_H