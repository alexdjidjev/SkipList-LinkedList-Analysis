#include <iostream>
#include <string>
#include "event.h"


// Constructors
Event::Event(const std::string& name, const int hours, const int minutes) {
    (*this).name = name;
    (*this).hours = hours;
    (*this).minutes = minutes;
}

Event::Event(const std::string& name, int minuteTimeStamp) {
    minuteTimeStamp = (minuteTimeStamp > 1439) ? (1439) : (minuteTimeStamp);
    (*this).name = name;
    (*this).hours = minuteTimeStamp / 60;
    (*this).minutes = minuteTimeStamp % 60;
}

int Event::getTimestamp() const {
    return 60*hours + minutes;
}

void Event::setTime(const int minuteTimeStamp) {
    (*this).hours = minuteTimeStamp / 60;
    (*this).minutes = minuteTimeStamp % 60; 
}

int Event::getHours() const {
    return hours;
}

int Event::getMinutes() const {
    return minutes;
}

std::string Event::getName() const {
    return name;
}

void Event::setName(const std::string name) {
    (*this).name = name;
}

void Event::printDetails() const {
    int minuteTensDigit = (minutes < 10) ? (0) : (minutes/10);
    int minuteOnesDigit = minutes % 10;

    std::cout << "Name: " << name << ", Time: " << hours << ":" 
    << std::to_string(minuteTensDigit) << std::to_string(minuteOnesDigit) << std::endl;
}

bool Event::operator<(const Event& rhs) const {
    return this->getTimestamp() < rhs.getTimestamp();
}

bool Event::operator>(const Event& rhs) const {
    return this->getTimestamp() > rhs.getTimestamp();
}

std::ostream& operator<<(std::ostream& os, const Event& evnt) {
    os << evnt.getName() << ", "
       << evnt.getTimestamp();
    return os;
}

std::istream& operator>>(std::istream& is, Event& evnt) {
    std::string extractedName;
    std::string extractedTimestamp;

    if (std::getline(is, extractedName, ',') &&
        std::getline(is, extractedTimestamp)) 
    {
        evnt.setName(extractedName);
        evnt.setTime(std::stoi(extractedTimestamp));
    }
    return is;
}