#ifndef _UNIT_SYSTEM_H_
#define _UNIT_SYSTEM_H_


#include "../../src/SystemImpl.h"

/**
 * @brief A unitary test for asserting the default constructor of SystemImpl.
*/
void unit_System_constructor_default();

/**
 * @brief A unitary test for asserting the constructor of SystemImpl with value parameter.
*/
void unit_System_constructor_with_value();

/**
 * @brief A unitary test for asserting the copy constructor of SystemImpl.
*/
void unit_system_copy_constructor();

/**
 * @brief A unitary test for asserting the destructor of SystemImpl.
*/
void unit_System_destructor();

/**
 * @brief A unitary test for asserting the getValue method.
*/
void unit_System_getValue();

/**
 * @brief A unitary test for asserting the setValue method.
*/
void unit_System_setValue();


/**
 * @brief A unitary test for asserting the overload of the assignment(=) operator.
*/
void unit_System_assignOverload();


#endif