#ifndef _UNIT_MODEL_H_
#define _UNIT_MODEL_H_

#include "../../src/FlowImpl.h"

/**
 * @brief A unitary test for asserting the default constructor of Model.
*/
void unit_Model_constructor_default();

/**
 * @brief A unitary test for asserting the destructor of Model.
*/
void unit_Model_destructor();


/**
 * @brief A unitary test for asserting the getClock method.
*/
void unit_Model_getClock();

/**
 * @brief A unitary test for asserting the add method with the System* overload.
*/
// void unit_Model_add_System();

/**
 * @brief A unitary test for asserting the add method with the Flow* overload.
*/
// void unit_Model_add_Flow();

/**
 * @brief A unitary test for asserting the removeSystem method.
*/
void unit_Model_removeSystem();

/**
 * @brief A unitary test for asserting the removeFlow method.
*/
void unit_Model_removeFlow();

/**
 * @brief A unitary test for asserting the run method.
*/
// void unit_Model_run();

/**
 * @brief A unitary test for asserting the systemsBegin method.
*/
void unit_Model_systemsBegin();

/**
 * @brief A unitary test for asserting the systemsEnd method.
*/
void unit_Model_systemsEnd();

/**
 * @brief A unitary test for asserting the systemsSize method.
*/
// void unit_Model_systemsSize();

/**
 * @brief A unitary test for asserting the flowsBegin method.
*/
void unit_Model_flowsBegin();

/**
 * @brief A unitary test for asserting the flowsEnd method.
*/
void unit_Model_flowsEnd();

/**
 * @brief A unitary test for asserting the flowsSize method.
*/
// void unit_Model_flowsSize();

/**
 * @brief A unitary test for asserting the overload of the assignment(=) operator.
*/
void unit_Model_assignOverload();

#endif