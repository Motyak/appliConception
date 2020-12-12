#include "Ihm.h"

#include "Controller.h"
#include "Model.h"

Ihm::Ihm()
{
    this->ctrl = std::make_unique<Controller>(this);
}