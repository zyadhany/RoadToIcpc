// remove k degits to make the numper smaller

string removeKdigits(string num, int k) {
    string result = "";

    stack<char> s;

    for (char c : num) {
        while (k > 0 && !s.empty() && c < s.top()) {
            s.pop();
            k--;
        }

        if (s.empty() && c == '0') {
            continue;
        }

        s.push(c);
    }

    while (k > 0 && !s.empty()) {
        s.pop();
        k--;
    }

    while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }
    reverse(result.begin(),result.end());

    if (result.empty()) {
        return "0";
    }

    return result;
}




string int_to_roman(ll num) {
	// bool valid = (num <= (4999||3999) && int_to_roman() == roman_to_int()
    string roman[] = //Largest integer possible 4999, some people 3999
    { "","I","II","III","IV","V","VI","VII","VIII","IX"		//1,2,3,4,..
        ,"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"		//10,20,30,..
        ,"C","CC","CCC","CD","D","DC","DCC","DCCC","CM" //100,200,300
        ,"M","MM","MMM","MMMM"	//1000,2000...
    };	//2222=2000+200+20+2 = MMCCXXII // 4444=MMMMCDXLIV
 
    string roman_number = "";
    ll i, j, arr[50] = {0};
 
    for(i=0; num; i++)	//cut it to thousands, hundreds, tens..
    {
        if(num%10 != 0)	arr[i] = i*9 + (num%10);
        num /= 10;
    }
 
    for(j=0;j<i;j++)
        roman_number = roman[arr[j]] + roman_number;
 
    return roman_number;
}
 
ll toDecimal(string number, int base) {	// Watchout OVERFLOW inputs
    string decode = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    ll res = 0;
    for (int i=0;i<number.size(); ++i)
        res *= base, res += decode.find(number[i]);
    return res;
}
 
string decToBase(ll number, int base)
{
    if(number == 0)	return "0";
    string res = "", encode = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
 
    while(number) {
    	int y =  number % base;
    	number /= base;
    	if(y < 0)	y += -base, number++;	//to handle negative base
        res = encode[y] + res;
    }
 
    return res;
}