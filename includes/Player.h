#ifndef PLAYER_H
#define PLAYER_H

#include "Box.h"
#include<cstdint>
#include<memory>
#include <vector>

class Player{
    private:
        double score_{0.0};
        std::vector<double> scores;

    public:
        void takeTurn(uint32_t input_weight, const std::vector<std::unique_ptr<Box> >& boxes);
        double getScore() const;
  

};


#endif // PLAYER_H