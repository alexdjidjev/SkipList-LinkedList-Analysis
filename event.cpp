#include <string>
#include "event.h"


int Event::getTime() const {
    return 60*hours + minutes;
}

std::string Event::getName() const {
    return name;
}
