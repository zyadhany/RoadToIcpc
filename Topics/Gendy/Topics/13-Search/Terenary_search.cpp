ll st = 2, end = 999;
    while(st <= end){
        ll mid1 = st + (end-st)/3;
        ll mid2 = end - (end-st)/3;
        cout<<"? "<<mid1 <<' '<<mid2<<endl;
        ll ans;cin>>ans;
        if (ans == (mid1 * mid2))
        {
            st = mid2+1;
        }
        else if (ans == mid1 * (mid2+1))
        {
            st = mid1+1;
            end = mid2-1;
        }
        else
        {
            end = mid1-1;
        }
    }
    cout<<"! "<<st<<endl;



// another one not sure

ll st = 0, end = 999;
    while(st < end){
        ll a = (2*st+end)/3;
        ll b = (st+2*end)/3;
        cout<<"? "<<a<<' '<<b<<endl;
        ll ans;cin>>ans;
        if (ans == (a*b)) // iam sure first 2 parts correct
        {
            st = b;
        }
        else if (ans == a*(b+1)) // mediam is wrong
        {
            st = a, end = b;
        }
        else // last is wrong
        {
            end = a;
        }
    }
    cout<<"! "<<end<<endl;