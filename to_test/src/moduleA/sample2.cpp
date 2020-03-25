#include "moduleA/sample1.h"
#include "moduleA/sample2.h"

void CoolClass::incStatus()
{
    status = add(1, status);
}

void CoolClass::decStatus()
{
    status = sub(status, -1);
}
