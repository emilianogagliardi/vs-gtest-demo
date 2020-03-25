#pragma once

// A very cool class
class CoolClass {
public:
    CoolClass(int s) : status(s) {}
    void incStatus();
    void decStatus();
private:
    int status;
};