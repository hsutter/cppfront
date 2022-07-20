
//  Copyright (c) Herb Sutter
//  SPDX-License-Identifier: CC-BY-NC-ND-4.0


//===========================================================================
//  Cpp2 utilities:
//      Language support implementations
//      #include'd by generated Cpp1 code
//===========================================================================

#include <cassert>


//-----------------------------------------------------------------------
// 
//  deferred_init: For deferred-initialized local or member variable
// 
//-----------------------------------------------------------------------
//
template<typename T>
class deferred_init {
    bool init = false;
    union { 
        int i;
        T t;
    };

public:
    deferred_init() noexcept       : i {0} { }
   ~deferred_init() noexcept       { if (init) t.~T(); }
    auto value()    noexcept -> T& { assert(init);  return t; }

    auto construct     (auto ...args) -> void { assert(!init);  new (&t) T(args...);  init = true; }
    auto construct_list(auto ...args) -> void { assert(!init);  new (&t) T{args...};  init = true; }
};




//#include <vector>
//#include <iostream>
//#include <cstdlib>
//using namespace std;
//
//int main() {
//    srand(unsigned(time(NULL)));
//    deferred_init<vector<int>> s;
//    if (rand() %2) {
//        s.construct(10, 50);
//    }
//    else {
//        s.construct_list(10, 50);
//    }
//    cout << s.value().size();
//}
