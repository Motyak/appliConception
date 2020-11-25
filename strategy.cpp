
#include <iostream>


class Ai
{
  public:
    virtual void nextMove() = 0;
};

class Random : public Ai
{
  public:
    void nextMove(){std::cout<<"Random::nextMove"<<std::endl;}
};

class MinMax : public Ai
{
  public:
    void nextMove()
    {
        std::cout<<"MinMax::nextMove"<<std::endl;
        this->genTree();
        this->evalNodes();
    }
    
    virtual void genTree(){std::cout<<"MinMax::genTree"<<std::endl;}
    virtual void evalNodes(){std::cout<<"MinMax::evalNodes"<<std::endl;}
};

class MinMaxMulti : public MinMax
{
    void genTree(){std::cout<<"MinMaxMulti::genTree"<<std::endl;}
    void evalNodes(){std::cout<<"MinMaxMulti::evalNodes"<<std::endl;}
};

// g++ -o strategy strategy.cpp
int main()
{
    Ai* random = new Random();
    Ai* minMax = new MinMaxMulti();
    random->nextMove();
    minMax->nextMove();
    delete(random);
    delete(minMax);
}