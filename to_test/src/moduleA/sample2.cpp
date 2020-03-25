#include "moduleA/sample1.h"
#include "moduleA/sample2.h"

bool operator==(const CoolClass& l, const CoolClass& r)
{
    return l.status == r.status;
}

void CoolClass::inc()
{
    status = add(1, status);
}

void CoolClass::dec()
{
    status = sub(status, 1);
}
