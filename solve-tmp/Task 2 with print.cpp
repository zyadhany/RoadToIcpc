#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

const int maxsz = 100; // max number of equations
const int maxvar = 100; // max number of variables

int n;                          // number of equations
int numVars = 0;                // number of variables
string Vars[maxvar];            // store variables names
float coeffs[maxsz][maxvar];    // coefficients of variables
float rhs[maxsz];               // constants on RHS
const float EPS = 1e-9;

// return current index of variable or add it if doesn't exist
int indexofvar(string var) {
    for (int i = 0; i < numVars; i++)
    {
        if (Vars[i] == var) return i;
    }
    Vars[numVars++] = var;
    return numVars - 1;
}

// Parse a single equation into coeffs[] and rhs
void parse_equation(string equ, int row) {
    for (int i = 0; i < maxvar; i++) coeffs[row][i] = 0;
    rhs[row] = 0;

    string val = "";
    string var = "";
    bool righthand = 0;
    bool mun = 0;
    bool isvar = 0;

    equ += '+';
    for (auto a : equ) {
        if (a == ' ' || a == '\t') continue;
        if (a == '+' || a == '-' || a == '=') {
            if (!val.empty() || !var.empty()) {
                float f = 1;
                if (!val.empty()) f = atof(val.c_str());

                if (righthand ^ mun) f *= -1;

                if (var.empty()) {
                    rhs[row] -= f;
                } else {
                    int ind = indexofvar(var);
                    coeffs[row][ind] += f;
                }
            }

            val = var = "";
            righthand |= (a == '=');
            mun = (a == '-');
            isvar = 0;
            continue;
        }
        
        if (!isdigit(a) && a!='.') isvar = 1;
        if (isvar) var += a;
        else val += a;
    }
}

// Pretty print equation in proper form
string pretty_equation(const float coef[], float rhs) {
    string res = "";

    bool first = 1;

    for (int i = 0; i < numVars; i++)
    {
        if (abs(coef[i]) < EPS) continue;
        string sign = (coef[i] > 0 ? "+" : "-");
        if (sign == "+" && first) sign = "";
        first = false;
        string val = to_string(abs(coef[i]));
        while (!val.empty() && val.back() == '0') val.pop_back();
        if (val.back() == '.') val.pop_back();
        if (abs(coef[i]) - 1 < EPS) val = "";
        res += sign + val + Vars[i];
    }
    

    string val = to_string(rhs);

    if (abs(rhs) < EPS) val = "0";
    else {
        while (!val.empty() && val.back() == '0') val.pop_back();
        if (val.back() == '.') val.pop_back();
    }
    
    res += "=" + val;
    return res;
}

// compute determinant recursively (Laplace expansion)
float determinant(float mat[maxsz][maxvar], int sz) {
    if (sz == 1) return mat[0][0];
    if (sz == 2) return mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];

    float det = 0;
    float sub[maxsz][maxvar];
    for (int x = 0; x < sz; x++) {
        int subi = 0;
        for (int i = 1; i < sz; i++) {
            int subj = 0;
            for (int j = 0; j < sz; j++) {
                if (j == x) continue;
                sub[subi][subj] = mat[i][j];
                subj++;
            }
            subi++;
        }
        det += ( (x%2==0 ? 1 : -1) * mat[0][x] * determinant(sub, sz-1) );
    }
    return det;
}

// print coefficient matrix
void print_D() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < numVars; j++) {
            cout << coeffs[i][j];
            if (j < numVars-1) cout << " ";
        }
        cout << "\n";
    }
}

// print matrix D with replaced column col by RHS
void print_Dx(int col) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < numVars; j++) {
            if (j == col) cout << rhs[i];
            else cout << coeffs[i][j];
            if (j < numVars-1) cout << " ";
        }
        cout << "\n";
    }
}

// solve using Cramer's rule
void solve_system() {
    if (numVars != n) {
        cout << "No Solution\n";
        return;
    }

    float A[maxsz][maxvar];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < numVars; j++)
            A[i][j] = coeffs[i][j];

    float D = determinant(A, n);
    if (fabs(D) < EPS) {
        cout << "No Solution\n";
        return;
    }

    for (int v = 0; v < numVars; v++) {
        float temp[maxsz][maxvar];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < numVars; j++) {
                temp[i][j] = (j==v ? rhs[i] : coeffs[i][j]);
            }
        }
        float Di = determinant(temp, n);
        float sol = Di / D;

        cout << Vars[v] << "=" << sol << "\n";
    }
}

int main() {

    cout << "Enter the number of equations: \n";

    cin >> n;
    
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string equ;
        getline(cin, equ);
        parse_equation(equ, i);
    }

    // sort equations by alphabetically order using bubble sort
    for (int i = 0; i < numVars; i++) {
        for (int j = 0; j < numVars - 1; j++)
        {
            if (Vars[j] > Vars[j + 1]) {
                swap(Vars[j], Vars[j + 1]);
                for (int h = 0; h < n; h++) {
                    swap(coeffs[h][j], coeffs[h][j + 1]);
                }
            }
        }
    }

    string cmd;
    while (cin >> cmd) {
        if (cmd == "quit") break;
        if (cmd == "num_vars") {
            cout << numVars << "\n";
        } else if (cmd == "equation") {
            int idx; cin >> idx;
            idx--; // for 0 index
            cout << pretty_equation(coeffs[idx], rhs[idx]) << "\n";
        } else if (cmd == "add") {
            int a, b; cin >> a >> b;
            a--, b--;
            float tmp[maxvar];
            for (int i = 0; i < maxvar; i++) {
                tmp[i] = coeffs[a][i] + coeffs[b][i];
            }
            cout << pretty_equation(tmp, rhs[a] + rhs[b]) << "\n";
        } else if (cmd == "subtract") {
            int a, b; cin >> a >> b;
            a--, b--;
            float tmp[maxvar];
            for (int i = 0; i < maxvar; i++) {
                tmp[i] = coeffs[a][i] - coeffs[b][i];
            }
            cout << pretty_equation(tmp, rhs[a] - rhs[b]) << "\n";
        } else if (cmd == "D") {
            string var;
            while (cin.peek() == 32) cin.ignore();
            if (cin.peek() == '\n' || cin.peek() == EOF || cin.peek() == -1) {
                print_D();
            } else {
                cin >> var;
                int col = -1;
                for (int i = 0; i < numVars; i++) {
                    if (Vars[i] == var) col = i;
                }
                if (col != -1) print_Dx(col);
            }
        } else if (cmd == "D_value") {
            if (n != numVars) {
                cout << "Can't compute D_value\n";
                continue;
            }
            float A[maxsz][maxvar];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < numVars; j++)
                    A[i][j] = coeffs[i][j];
            cout << determinant(A, n) << "\n";
        } else if (cmd == "solve") {
            if (n != numVars) {
                cout << "Can't solve system\n";
                continue;
            }
            solve_system();
        }
    }
}
