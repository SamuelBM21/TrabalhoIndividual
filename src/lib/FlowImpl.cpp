#include "../include/FlowImpl.h"

// --- Implementação do FlowBody ---

FlowBody::FlowBody() : source(nullptr), target(nullptr) {}

FlowBody::~FlowBody() {}

void FlowBody::setSource(System* s) {
    source = s;
}

System* FlowBody::getSource() const {
    return source;
}

void FlowBody::setTarget(System* t) {
    target = t;
}

System* FlowBody::getTarget() const {
    return target;
}

// --- Implementação do FlowHandle ---

FlowHandle::FlowHandle() {
    // Handle cria body padrão
}

FlowHandle::FlowHandle(System* source, System* target) {
    pImpl_->detach();
    pImpl_ = new FlowBody();
    pImpl_->setSource(source);
    pImpl_->setTarget(target);
    pImpl_->attach();
}

FlowHandle::~FlowHandle() {}

bool FlowHandle::setSource(System* s) {
    pImpl_->setSource(s);
    return true;
}

System* FlowHandle::getSource() const {
    return pImpl_->getSource();
}

bool FlowHandle::setTarget(System* t) {
    pImpl_->setTarget(t);
    return true;
}

System* FlowHandle::getTarget() const {
    return pImpl_->getTarget();
}