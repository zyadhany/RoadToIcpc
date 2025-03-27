// Header files, namespaces, 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

// macros to define set 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
/**
 * int : It is the type of the data (KEY).
 * null_type : mapped policy. null for set, int for map.
 * less : compare function.
*/

/**
 * function to use:
 * find_by_order(k): It returns to an iterator to the kth element.
 * order_of_key(k) : It returns to the number of items that are strictly smaller than our item k.
*/

// show how to use it in vector.
ordered_set orderedSet(vi X) {
    int re;
    ordered_set ord;
    for (auto a : X) ord.insert(a);

    for (int i = 0; i < X.size(); i++)
    {
        re = *ord.find_by_order(i);
        cout << re << " at: " << ord.order_of_key(re) << '\n';
    }
    
    return (ord);
}

// ord1.swap(ord2) --> for O(1) swap.

/**
 * to make it multiset:
 * cahnge compare value to less_equal.
 * earse will no longer work.
 * lower & uppwer_bound function will exange theire function.
 * another approach to make pair in set so every value in uniqe.
*/
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> 

// this function inserts one more occurrence of (x) into the set.
void Insert(ordered_set &s,int x) { 
    s.insert(x);
}
 
// this function checks weather the value (x) exists in the set or not.
bool Exist(ordered_set &s,int x) { 
    if ((s.upper_bound(x))==s.end()) return (0);
    return ((*s.upper_bound(x))==x);
}
 
// this function erases one occurrence of the value (x).
void Erase(ordered_set &s,int x) { 
     if (Exist(s,x)) s.erase(s.upper_bound(x));
}
