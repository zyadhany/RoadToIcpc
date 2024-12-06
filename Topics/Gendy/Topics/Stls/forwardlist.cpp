#include <iostream>
#include <forward_list>

using namespace std;

int main() {
    // Initialize a forward list
    forward_list<long long> f{1, 2, 3};

    // Assigning new values
    f.assign(5, 7); // Changes the list to 5 elements, each with value 7
    // Alternatively, using curly braces to assign specific values
    f.assign({5, 7}); // Changes the list to contain 5 and 7

    // Adding elements to the front of the list
    f.push_front(5);  // Adds 5 to the front
    f.emplace_front(5); // Emplaces 5 to the front

    // Removing an element from the front
    f.pop_front();  // Removes the first element

    // Inserting an element after a specific position
    f.insert_after(f.begin(), 5); // Insert 5 after the first element

    // Inserting before a specific element (in this case, at the beginning)
    f.insert_after(f.before_begin(), 5);  // Insert 5 before the first element
    f.emplace_after(f.before_begin(), 1); // Emplaces 1 before the first element

    // Inserting a collection of elements
    f.insert_after(f.before_begin(), {1, 2, 3}); // Insert {1, 2, 3} at the beginning

    // Getting the next element
    auto ff = next(f.begin()); // Getting the next element after the first
    auto ff2 = next(f.begin(), 2); // Moving two steps after the first element

    // Removing elements
    f.erase_after(f.begin()); // Removes the element after the first
    f.erase_after(f.before_begin()); // Removes the element after the before_begin iterator
    auto it = next(f.begin(), 3);  // Getting the 4th element iterator
    f.erase_after(it); // Removes the 4th element

    // Removing all elements equal to 1
    f.remove(1); // Removes all occurrences of 1

    // Removing elements that satisfy a condition (greater than 4 in this case)
    f.remove_if([](long long n) { return n > 4; }); // Removes elements greater than 4

    // Merging two lists
    forward_list<long long> f2{8, 9, 10};
    f1.splice_after(f1.before_begin(), f2);  // Merges f2 into f1 and empties f2

    // Merging a specific range from f2 into f1
    f1.splice_after(f1.before_begin(), f2, f2.begin(), f2.end());

    return 0;
}
