#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    inf.readDouble(7, 10'000'000'000'000'000, "n");
    inf.readSpace();
    inf.readDouble(1, 10'000, "m");
    inf.readSpace();
    inf.readDouble(1, 10'000, "r");
    inf.readEoln();
    inf.readEof();
}
