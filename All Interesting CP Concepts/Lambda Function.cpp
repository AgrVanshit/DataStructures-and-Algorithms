/*Lambda functions in C++ are a convenient way to define anonymous functions directly
  within the code where they are used. They are particularly useful for short functions 
  that are only used in one place and do not need a full function definition elsewhere 
  in the code. Lambda functions are defined using the syntax:


*****Ex : 1*****
#include <iostream>

int main() {
    auto add = [](int a, int b) -> int {
        return a + b;
    };

    cout << add(2, 3) << endl; // Output: 5
    return 0;
}


*****Ex : 2*****
#include <iostream>

int main() {
    int x = 10;
    auto printX = [=]() {
        cout << x << endl;
    };

    x = 20; // Changing x after capture
    printX(); // Output: 10
    return 0;
}


*****Ex : 3*****
#include <iostream>

int main() {
    int x = 10;
    auto printX = [&]() {
        cout << x << endl;
    };

    x = 20; // Changing x after capture
    printX(); // Output: 20
    return 0;
}


*****Ex : 4*****
//Using Lambda Functions with "sort" function:

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    vector<int> nums = {1, 3, 2, 4, 6, 5};

    sort(nums.begin(), nums.end(), [](int a, int b) {
        return a > b; // Sort in descending order
    });

    for (int num : nums) {
        cout << num << " "; // Output: 6 5 4 3 2 1
    }

    return 0;
}


*****Ex : 5*****
//If you need to use a any data structure inside the comparator, you can capture that by reference:
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    vector<int> nums = {1, 3, 2, 4, 6, 5};
    map<int, int> valuePriority = {{1, 2}, {2, 1}, {3, 3}, {4, 1}, {5, 2}, {6, 3}};

    std::sort(nums.begin(), nums.end(), [&](int a, int b) {
        return valuePriority[a] < valuePriority[b];
    });

    for (int num : nums) {
        cout << num << " "; // Output will depend on valuePriority map
    }

    return 0;
}


Capture Clause:
The capture clause specifies how variables from the surrounding scope are used inside 
the lambda. The options include:

[ ]: No variables are captured.
[=]: Capture all variables from the surrounding scope by value.
[&]: Capture all variables from the surrounding scope by reference.
[x, &y]: Capture x by value and y by reference.


//*****Related Questions:*****
https://leetcode.com/problems/sort-the-jumbled-numbers/description/
