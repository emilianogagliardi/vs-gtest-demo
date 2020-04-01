#pragma once

#include <gmock/gmock.h>
#include "moduleC/simple_mock_example.h"

class InterfaceMock : public InterfaceToMock {
public:
    MOCK_METHOD(void, doA, (), (override));
    MOCK_METHOD(void, doB, (int), (override));
    MOCK_METHOD(int, getC, (), (override));
};