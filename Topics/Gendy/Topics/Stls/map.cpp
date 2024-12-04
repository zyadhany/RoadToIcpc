auto it = myMap.lower_bound(keyToFind);

// Check if the key was found
if (it != myMap.end() && it->first == keyToFind)
{
    cout << "Key " << keyToFind << " found with value: " << it->second << endl;
}
else
{
    cout << "Key " << keyToFind << " not found" << endl;
}