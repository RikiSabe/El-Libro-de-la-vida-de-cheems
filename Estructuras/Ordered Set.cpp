#define typeOfData int
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ordered_set tree<typeOfData, null_type,less<typeOfData>, rb_tree_tag,tree_order_statistics_node_update> 
using namespace __gnu_pbds;

// Finding the second smallest element 
cout << *(o_set.find_by_order(1))  << endl; 

// Finding the number of elements less than k=4 
cout << o_set.order_of_key(4) << endl; 

// Delete finding element
o_set.erase(o_set.find(4));
