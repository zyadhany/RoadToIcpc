multiset<int,greater<int>>s;

// custom multiset compare

// Define a custom comparator lambda function 
    auto customComparator = [](const int& a, const int& b) 
    { return a > b; }; 
  
    // Create a multiset with the custom comparator 
    multiset<int, decltype(customComparator)> 
    customSet(customComparator); 