#include "Flow.h"
#include "System.h"

using namespace std;

Flow::Flow() : name(""), source(nullptr), target(nullptr) {}

Flow::Flow(const std::string& name, System* source, System* target)
    : name(name), source(source), target(target) {}

Flow::~Flow(){};

Flow::Flow(const Flow &flow){
    if(this == &flow) return;

    name = flow.getName();
    source = flow.getSource();
    target = flow.getTarget();
}

// Source / Target
bool Flow::setSource(System* s) {
    source = s;
    return true;
}

System* Flow::getSource() const {
    return source;
}

bool Flow::setTarget(System* t) {
    target = t;
    return true;
}

System* Flow::getTarget() const {
    return target;
}

const string& Flow::getName() const {
    return name;
}

void Flow::setName(const string& n) {
    name = n;
}


Flow& Flow::operator= (const Flow &flow){

    if(this == &flow)
        return *this;

    name = flow.getName();
    source = flow.getSource();
    target = flow.getTarget();

    return *this;
}
