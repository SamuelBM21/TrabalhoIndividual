#ifndef MODEL_H_
#define MODEL_H_

#include <iostream>
#include <vector>
#include <string>
#include "System.h"
#include "Flow.h"

class Model {
protected:
    std::string name;
    std::vector<System*> systems;
    std::vector<Flow*> flows;

public:
    Model();
    Model(const std::string& name);
    Model(const Model& other);

    Model& operator=(const Model& other);
    ~Model();
    
    // Getters
    const std::vector<System*>& getSystems() const;
    const std::vector<Flow*>& getFlows() const;

    const std::string& getName() const;   
    void setName(const std::string& n);  

    // Modifiers
    bool add(System* s);
    bool add(Flow* f);

    bool remove(System* s);
    bool remove(Flow* f);

    // Execution
    bool run(int startTime, int endTime);
};

#endif