#include "testlib.h"

using namespace std;

void solve() {
    inf.readDouble(7, 10'000'000'000'000'000, "n");
    inf.readSpace();
    inf.readDouble(1, 10'000, "m");
    inf.readSpace();
    inf.readDouble(1, 10'000, "r");
    inf.readEoln();
    inf.readEof();
}

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int t;
    t = inf.readInt(1, 10'000, "t");
    inf.readEoln();
    for (int i = 1; i <= t; i++) {
        setTestCase(i);
        solve();
    }
    inf.readEof();
    return 0;
}
