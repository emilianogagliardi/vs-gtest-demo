#pragma once

class Counter {
public:
    int get() const { return x; }
    virtual void inc() = 0;
protected:
    int x = 0;
};

class PrefixCounter : public Counter {
public:
    void inc() override { ++x; }
};

class PostfixCounter : public Counter {
public:
    void inc() override { x++; }
};