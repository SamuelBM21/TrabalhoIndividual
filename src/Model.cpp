#include "Model.h"
#include <algorithm> 

using namespace std;

Model::Model() : systems(), flows() {}

Model::~Model() {
    // Delete all flows
    for (Flow* flow : flows) {
        delete flow;
    }
    // Delete all systems
    for (System* system : systems) {
        delete system;
    }
}

Model::Model(const Model& other) {
    name = other.name;
    systems = other.systems;
    flows = other.flows;
}

Model::Model(const string& name) :  name(name), systems(), flows(){}

Model& Model::operator=(const Model& other) {
    if (this == &other)
        return *this;

    name = other.name;
    systems = other.systems;
    flows = other.flows;
    return *this;
}

const vector<System*>& Model::getSystems() const {
    return systems;
}

const vector<Flow*>& Model::getFlows() const {
    return flows;
}


const string& Model::getName() const {
    return name;
}

void Model::setName(const string& n) {
    name = n;
}

bool Model::add(System* s) {
    systems.push_back(s);
    return true;
}

bool Model::add(Flow* f) {
    flows.push_back(f);
    return true;
}

bool Model::remove(System* s) {
    auto it = find(systems.begin(), systems.end(), s);
    if (it != systems.end()) {
        systems.erase(it);
        return true;
    }
    return false;
}

bool Model::remove(Flow* f) {
    auto it = find(flows.begin(), flows.end(), f);
    if (it != flows.end()) {
        flows.erase(it);
        return true;
    }
    return false;
}

bool Model::run(int startTime, int endTime) {
    for (int time = startTime; time < endTime; time++) {

        int n = flows.size();
        vector<double> results(n);

        for (int i = 0; i < n; i++)
            results[i] = flows[i]->execute();

        for (int i = 0; i < n; i++) {
            Flow* f = flows[i];

            if (f->getSource())
                f->getSource()->setValue(f->getSource()->getValue() - results[i]);

            if (f->getTarget())
                f->getTarget()->setValue(f->getTarget()->getValue() + results[i]);
        }
    }
    return true;
}