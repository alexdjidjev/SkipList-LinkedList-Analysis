#ifndef EVENT_H
#define EVENT_H
#include <string>


class Event {
    public:

        // Constructors
        Event() {};
        Event(const std::string& name, const int hours, const int minutes);
        Event(const std::string& name, int minuteTimeStamp);

        // Desc: Returns hours member variable.
        int getHours() const;

        // Desc: Returns minutes member variable.
        int getMinutes() const;

        // Desc: Returns the Event object's timestamp in minutes.
        int getTimestamp() const;

        // Desc: Sets the hours and minutes member vars according to minute timestamp.
        void setTime(const int minuteTimeStamp);

        // Desc: Returns the Event object's name. 
        std::string getName() const;

        // Desc: Sets name member variable to 'name'.
        void setName(const std::string name);

        // Desc: Prints name, hours, and minutes member vars to standard output.
        void printDetails() const;

        // Less-than Operator Overload
        // Desc: Returns true if current object's timestamp is less than rhs's timestamp.
        bool operator<(const Event& rhs) const;
        
        // Greater-than Operator Overload
        // Desc: Returns true if current object's timestamp is greater than rhs's timestamp.
        bool operator>(const Event& rhs) const;

        // Logical Equals Operator Overload
        // Desc: Returns true if current object's time vars is equal to rhs's time.
        // Converts hours and minutes vars to a minute timestamp and compares that value. 
        bool operator==(const Event& rhs) const; 

    private:
        std::string name;
        int hours;
        int minutes;
};

// Insertion Operator Overload
std::ostream& operator<<(std::ostream& os, const Event& evnt);

// Extraction Operator Overload
std::istream& operator>>(std::istream& is, Event& evnt);



#endif
