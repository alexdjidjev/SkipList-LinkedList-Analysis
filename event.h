#ifndef EVENT_H
#define EVENT_H
#include <string>


class Event {
    public:
        int getTime() const;
        std::string getName() const;

    private:
        std::string name;
        int hours;
        int minutes;
};

#endif
