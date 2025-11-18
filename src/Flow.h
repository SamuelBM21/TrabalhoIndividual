#ifndef FLOW_H_
#define FLOW_H_

#include "System.h"
#include <string>

class Flow {
    protected:
        std::string name;
        System* source;
        System* target;

    public:
        Flow();
        Flow(const std::string& name, System* source = nullptr, System* target = nullptr);
        Flow(const Flow& flow);
        
        virtual ~Flow();
        Flow& operator= (const Flow&);

        const std::string& getName() const;   
        void setName(const std::string& n);  

        bool setSource(System* s);
        System* getSource() const;

        bool setTarget(System* t);
        System* getTarget() const;

        virtual double execute() = 0;
    };

#endif // FLOW_H_