int a = succ[i];
int b = succ[a];
while (a != b) {
    a = succ[a];
    b = succ[succ[b]];
}

a = i;
while (a != b) {
    a = succ[a];
    b = succ[b];
}
// here a = first point in cycle

int len = 1;
b = succ[a];
while (a != b) {
    b = succ[b];
    len++;
}
// got leanght of cycle.