#pragma once

#include <memory>

class InterfaceToMock {
public:
    virtual void doA() = 0;
    virtual void doB(int) = 0;
    virtual int getC() = 0;
};

class ClassToTest {
public:
    
    ClassToTest() = delete;

    ClassToTest(InterfaceToMock* i) :
        dependency(i) {}
    
    void doCoolStuffA()
    {
        dependency->doA();
    }

    void doCoolStuffB(int x)
    {
        dependency->doB(x + 1);
    }

    int doCoolStuffC()
    {
        return dependency->getC() + 1;
    }

private:
    InterfaceToMock* dependency;
};