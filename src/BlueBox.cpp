#include "BlueBox.h"
 
BlueBox::BlueBox(double initial_weight): Box(initial_weight){}

//generates score for the blue box
double BlueBox::generateScore(const std::vector<double>& weights){
        // identify the smallest and the largest absorbed weight
        double smallest {0.0};
        double largest {0.0};

        //if only one element is absorbed by the box, the smallest and the largest element are the same
        if(weights.size() ==1){
             smallest = weights[0];
             largest = weights[0];
           
        }else{
          //find the smallest and the largest weight the box has absorbed so far
             smallest = *std::min_element(weights.begin(), weights.end());
             largest = *std::max_element(weights.begin(), weights.end());
        }
        //compute the Cantor pairing i.e. pairing(0,1) = 2, and return the score
         return 0.5 * (smallest + largest) * (smallest + largest + 1) + largest;
            
    }

