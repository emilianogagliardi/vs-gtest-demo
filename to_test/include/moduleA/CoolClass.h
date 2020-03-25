#pragma once

class CoolClass;

bool operator==(const CoolClass&, const CoolClass&);

// A very cool class
class CoolClass {
    friend bool operator==(const CoolClass&, const CoolClass&);
public:
    CoolClass(int s) : status(s) {}
    void inc();
    void dec();
    int get() { return status; }
private:
    int status;
};