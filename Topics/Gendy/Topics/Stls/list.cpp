سريع في الاضافه من اي جزء

تعريفه
   list<int> l={1,2,3};

لحذف جميع ال 2 في الليست
   l.remove(2);

العنصر التالي
next(it)

لحذف رينج معين
    auto it=l.begin();
    it++;
    l.erase(it,l.end());

لحذف من مكان لعنصرين
 it=l.erase(it, next(it,2));


 اضافه قيم في مكان معين
auto it=l.begin();
    it++;
    l.insert(it,2,50);
هيضيف 50 مرتين في مكان الايتيريتور


تغيير كل العناصر الي 2 عشر مرات
    l.assign(10,2);

عمل دمج لعناصر في الاول مع تفريغ الي جوا القوس مع ترتيبهم تصاعدي
    l1.merge(l2);

عمل دمج لكن في موقع معين مع تفريغ الي في القوس دون الترتيب
    l1.splice(l1.begin(),l2);

حذف كل العناصر المكررة
    l1.unique();


للحذف عند تحقق شرط ما
  bool evenNum(ll n)
   {
    if (n%2==0)return true;
    else return false;
    }
    l1.remove_if(evenNum);
     هيسمح كل الزوجي  


الترتيب للعناصر تصاعدي
l1.sort();
تنازلي
l1.sort(greater<int>());

لتغيير قيمه عنصر
auto it=l1.begin();
    it++;
    *it=5;

