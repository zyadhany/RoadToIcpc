~ not
(a<<b)=a*(2^b)
(a>>b)=a/(2^b)

even last digit in bin = 0
lastbit= a&1 -->1 odd  -->0 even


pow of two just have 1 only
n&(n-1)&&(n!=0) --> 0   n power of 2


 int n = 10;
 bitset<32> s(n);
 00000000000000000000000000001010
 s.to_ullong() -->> to decimal value
 s.set(3);   // Set bit at position 3 to 1
 s.reset(7); // Set bit at position 7 to 0
 bool bit3 = s.test(3);  // Check bit at position 3



count 1 in bin
while(n)
{
if(n&1==1)cnt++;
n=n>>1;
}
// Faster

// numper of set bits
x = __builtin_popcount(n);



// Finding possible probabilities

vi T;
void rec(int n)
{
    if (T.size() == n)
    {
        for (int i = 0; i < T.size(); i++)
        {
            cout << T[i] << ' ';
        }cout << '\n';
        return;
    }
    T.push_back(0);
    rec(n);
    T.pop_back();
    T.push_back(1);
    rec(n);
    T.pop_back();
}

1 0 1 0 1


-------------------------------------------
every thing sorted
multiset<int> numbers;


functions

bool Even_Or_Odd(int x)
{
    return (x & 1);
}
void to_binary(int x)
{
    while (x)
    {
        cout << (x & 1);
        x >>= 1;
    }
    return;
}
int count_bits_1(int x)
{
    int counter = 0;
    while (x)
    {
        counter += (x & 1);
        x >>= 1;
    }
    return counter;
}
int Get_bit(int x, int  indx)
{
    return ((x >> indx) & 1);
}
int Convert_bit_To_1(int x, int  indx)
{
    x |= (1 << indx);
    return x;
}
int Convert_bit_To_0(int x, int  indx)
{
    x &= (~(1 << indx));
    return x;
}
int Flip(int x, int indx)
{
    x ^= (1 << indx);
    return x;
}
int How_many_bits(int x)
{
    int counter = 0;
    while (x)
    {
        x >>= 1;
        counter++;
    }
    return counter;
}
bool if_power_of_two(int x)
{
    return (x & (x - 1)) == 0;
}
int first_power_of_two(int x)
{
    if (if_power_of_two(x))
        return x;
    else
        return 1 << How_many_bits(x);
}
int flip_first_one_from_right(int x)
{
    x &= (x - 1);
    return x;
}
int flip_first_zero_from_right(int x)
{
 
    x |= (x + 1);
    return x;
}
int get_value_of_first_one(int x)
{
    return x - (x & (x - 1));
}



value of first bit from right
x & ~(x-1)



The difference between the current digit and the previous one equals 1
int grayCode(int i)
{
	return(i ^ (i>>1));
}

print all subset of set bits but reversed
ex: 6 -->110
011-->110
001-->100
01 --> 10

void getAllSubmasks(int mask)
{
    for (int i = mask; i ; i=(i-1)&mask) {
        to_binary(i);
        cout<<endl;
    }
}

to print it reversed
void getAllSubmasks(int mask)
{
     for (int i = mask; i ; i=(i-1)&mask) {
        to_binary((i^mask));
        if (i!=mask)cout<<endl;
    }
    to_binary((mask));
}



// num systems
int converted = stoi(dec , nullptr, 16); //to decimal from any base

//to bin
int decimalNumber = 10;
    bitset<8> binaryNumber(decimalNumber);
    cout << "Binary: " << binaryNumber.to_string() << endl;

// Function to convert decimal to any base
void decimalToBase(int num, int base) {
    int rem = 0;
    string baseNum = "";
    while (num > 0) {
        rem = num % base;
        if (rem < 10) {
            baseNum = char(rem + '0') + baseNum;
        } else {
            baseNum = char(rem - 10 + 'A') + baseNum;
        }
        num = num / base;
    }
    cout << baseNum << endl;
}