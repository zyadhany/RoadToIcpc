#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

bool evenNum(int n) {
    return n % 2 == 0;
}

int main() {
    // Define the list
    list<int> l = {1, 2, 3};

    // Remove all occurrences of 2 from the list
    l.remove(2);

    // Get the next element using iterator
    auto it = l.begin();
    it++;  // Move iterator to the second element
    auto nextIt = next(it);  // Get the next element after `it`

    // Erase a range of elements
    it = l.begin();
    it++; // Move iterator to the second element
    l.erase(it, l.end()); // Erase from the second element to the end

    // Erase two elements starting from a specific iterator
    it = l.erase(it, next(it, 2));

    // Insert values at a specific position in the list
    it = l.begin();
    it++; // Move iterator to the second element
    l.insert(it, 2, 50); // Insert 50 twice at the second position

    // Assign the value 2 ten times to the list
    l.assign(10, 2);

    // Merge two lists (sorted) into the first one
    list<int> l1 = {1, 2, 3};
    list<int> l2 = {4, 5, 6};
    l1.merge(l2);  // Merge and sort l2 into l1 in ascending order

    // Merge l2 into l1 at the beginning without sorting
    l1.splice(l1.begin(), l2);  // Merges l2 into l1 at the start without sorting

    // Remove duplicate elements
    l1.unique();  // Removes consecutive duplicates from l1

    // Remove elements based on a condition (even numbers)
    l1.remove_if(evenNum);  // Remove all even numbers from l1

    // Sort elements in ascending order
    l1.sort();

    // Sort elements in descending order
    l1.sort(greater<int>());

    // Change the value of an element at a specific position
    it = l1.begin();
    it++;  // Move iterator to the second element
    *it = 5;  // Change the second element to 5

    return 0;
}
