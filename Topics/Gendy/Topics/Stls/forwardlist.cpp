    forward_list<ll>f{1,2,3};


f.assign(5,7);

f.assign({5,7});

    f.push_front(5);
    f.emplace_front(5);

    f.pop_front();


    f.insert_after(f.begin(),5);

    f.insert_after(f.before_begin(),5);
    f.emplace_after(f.before_begin(),1);


 f.insert_after(f.before_begin(),{1,2,3});

auto ff= next(f.begin());

    auto ff= next(f.begin(),2);

  f.erase_after(f.begin());

    f.erase_after(f.before_begin());

auto it= next(f.begin(),3);
    f.erase_after(it);

    f.remove(1);

bool fun(ll n)
{
    if (n>4)return true;
    return false;
}

f.remove_if(fun);

    f.remove_if([](ll n) {return n<=2;} );


f1.splice_after(f1.before_begin(),f2);
    f1.splice_after(f1.before_begin(),f2,f2.begin(),f2.end());



