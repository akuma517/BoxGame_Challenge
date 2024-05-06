#include "GreenBox.h"

GreenBox::GreenBox(double initial_weight) : Box(initial_weight){}

double GreenBox::computeMean(const std::vector<double> &temp){
        if (temp.empty()) {
            return 0;
        }
        // if the elements are less than 3 take all of them, else take the last three weights
        if(temp.size()<3){
            return std::accumulate(temp.begin(), temp.end(), 0.0) / temp.size();
        }else{
          //compute the mean of the 3 recently absorbed weights
            return std::accumulate(temp.end()-3, temp.end(), 0.0) / 3;
        }
    }

//generates score for the green box
double GreenBox::generateScore(const std::vector<double>& weights){
        auto mean =computeMean(weights);
        return mean*mean;
    }

    
