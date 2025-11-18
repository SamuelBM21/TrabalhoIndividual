#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <string>

class System {
private:
    std::string name;
    double value;

public:
    System();
    System(double value);
    System(const System& other);
    System& operator=(const System& other);
    virtual ~System();

    bool setValue(double v);
    double getValue() const;
    const std::string& getName() const;   
    void setName(const std::string& n);  

};

#endif // SYSTEM_H_