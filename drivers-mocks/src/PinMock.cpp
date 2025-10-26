#include "PinMock.hpp"

#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>

struct LAME_Pin_Impl {
};

extern "C" {

void LAME_Pin_SetActive(LAME_Pin self, bool state)
{
    (void) self;
    (void) state;
}

bool LAME_Pin_GetActive(const LAME_Pin self)
{
    (void) self;
    return true;
}

void LAME_Pin_Toggle(LAME_Pin self)
{
    (void) self;

}
}

void PinMock_ExceptWrite(LAME_Pin self, bool state)
{
    (void) self;
    (void) state;
}
