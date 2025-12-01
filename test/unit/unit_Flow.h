#ifndef _UNIT_FLOW_H_
#define _UNIT_FLOW_H_

#include "../../src/FlowImpl.h"

/**
 * @brief A unitary test for asserting the default constructor of FlowImpl.
*/
void unit_Flow_constructor_default();

/**
 * @brief A unitary test for asserting the constructor of FlowImpl source and target params.
*/
void unit_Flow_constructor_with_source_target();

/**
 * @brief A unitary test for asserting the copy constructor of FlowImpl.
*/
void unit_Flow_copy_constructor();

/**
 * @brief A unitary test for asserting the destructor of FlowImpl.
*/
void unit_Flow_destructor();


/**
 * @brief A unitary test for asserting the getValue method.
*/
void unit_Flow_getValue();

/**
 * @brief A unitary test for asserting the setValue method.
*/
void unit_Flow_setValue();


/**
 * @brief A unitary test for asserting the getSource method.
*/
void unit_Flow_getSource();

/**
 * @brief A unitary test for asserting the setSource method.
*/
void unit_Flow_setSource();


/**
 * @brief A unitary test for asserting the getTarget method.
*/
void unit_Flow_getTarget();

/**
 * @brief A unitary test for asserting the setTarget method.
*/
void unit_Flow_setTarget();


/**
 * @brief A unitary test for asserting the overload of the assignment(=) operator.
*/
// void unit_Flow_assignOverload();

#endif