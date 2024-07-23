vi v = {5,1,6,4,3,2};
    make_heap(v.begin(),v.end());//Converts given range to a heap.
    v.push_back(10);
    push_heap(v.begin(),v.end());//Arrange the heap after insertion at the end.
    pop_heap(v.begin(),v.end());//Moves the max element at the end for deletion.
    sort_heap(v.begin(),v.end());//Sort the elements of the max_heap to ascending order.
    cout<<is_heap(v.begin(),v.end());//Checks if the given range is max_heap.
    auto it = is_heap_until(v.begin(),v.end());
    for(auto it1=v.begin();it1!=it;it1++)
        cout<<*it1;