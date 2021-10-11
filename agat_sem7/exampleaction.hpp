#ifndef EXAMPLEACTION_HPP
#define EXAMPLEACTION_HPP

#include "action.hpp"

class ExampleAction : public Action
{
  public:
    ExampleAction();

  private:
    int position = 0;
};

#endif // EXAMPLEACTION_HPP
