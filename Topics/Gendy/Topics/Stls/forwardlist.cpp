تعريفه
    forward_list<ll>f{1,2,3};


تغير الليست الي 5 عناصر من القيمة 7
f.assign(5,7);

لكن لو وضعت اقواس براكيت هتتغير الليست للقيم الي جوا البراكيت
f.assign({5,7});

يمكن الاضافه من الامام فقط ولا يمكن الاضافه من الخلف
    f.push_front(5);
    f.emplace_front(5);

الحذف من الاول
    f.pop_front();


لوضع عنصر بعد العنصر في المكان المحدد مثلا في المكان رقم 2
    f.insert_after(f.begin(),5);

 لكن لوضع العنصر قبل العنصر في المكان المحدد مثلا في البداية
    f.insert_after(f.before_begin(),5);
    f.emplace_after(f.before_begin(),1);


لوضع مجموعة  
 f.insert_after(f.before_begin(),{1,2,3});

العنصر التالي
auto ff= next(f.begin());

ليتحرك خطوتين بعد العنصر الاول
    auto ff= next(f.begin(),2);

*الحذف*
  للعنصر الي بعده
  f.erase_after(f.begin());

العنصر نفسه
    f.erase_after(f.before_begin());

لحذف العنصر الرابع
auto it= next(f.begin(),3);
    f.erase_after(it);

حذف جميع العناصر التي تساوي 1
    f.remove(1);

لحذف العناصر بشرط اذا كانت اكبر من 4 مثلا
bool fun(ll n)
{
    if (n>4)return true;
    return false;
}

f.remove_if(fun);
هيمسح لو شرط الفانكشن اتحقق

او بطريقه اخري اسرع
    f.remove_if([](ll n) {return n<=2;} );


 لدمج عناصر الليست التانيه في الليست الاولي ويفضي التانيه
f1.splice_after(f1.before_begin(),f2);
في رينج معين
    f1.splice_after(f1.before_begin(),f2,f2.begin(),f2.end());



