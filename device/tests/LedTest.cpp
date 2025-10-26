#include <lame/Led.h>

#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>


TEST_GROUP(EventTests) {

LAME_Led led;

void setup()
{
}

void teardown()
{
}

};

TEST(EventTests, clearAfterCreate)
{
    CHECK_TRUE(false);
}

int main(int argc, char **argv)
{
    printf("\nLed test1");
    return RUN_ALL_TESTS(argc, argv);
}
