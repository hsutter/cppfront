
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-hashable.cpp2"
class base;
#line 2 "pure2-hashable.cpp2"
    

#line 5 "pure2-hashable.cpp2"
class mystruct;
    

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-hashable.cpp2"
class base {
#line 2 "pure2-hashable.cpp2"
    public: cpp2::i32 h; 
    public: base(auto&& h_)
CPP2_REQUIRES_ (std::is_convertible_v<CPP2_TYPEOF(h_), std::add_const_t<cpp2::i32>&>) ;

public: auto operator=(auto&& h_) -> base& 
CPP2_REQUIRES_ (std::is_convertible_v<CPP2_TYPEOF(h_), std::add_const_t<cpp2::i32>&>) ;
public: [[nodiscard]] auto hash() const& -> size_t;

#line 3 "pure2-hashable.cpp2"
};

class mystruct: public base {

    public: cpp2::i32 i; 
    public: std::string j; 
    public: cpp2::u64 k; 
    public: mystruct(auto&& i_, auto&& j_, auto&& k_)
CPP2_REQUIRES_ (std::is_convertible_v<CPP2_TYPEOF(i_), std::add_const_t<cpp2::i32>&> && std::is_convertible_v<CPP2_TYPEOF(j_), std::add_const_t<std::string>&> && std::is_convertible_v<CPP2_TYPEOF(k_), std::add_const_t<cpp2::u64>&>) ;
public: [[nodiscard]] auto hash() const& -> size_t;

#line 10 "pure2-hashable.cpp2"
};

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-hashable.cpp2"


base::base(auto&& h_)
requires (std::is_convertible_v<CPP2_TYPEOF(h_), std::add_const_t<cpp2::i32>&>) 
                                                           : h{ CPP2_FORWARD(h_) }{}
auto base::operator=(auto&& h_) -> base& 
requires (std::is_convertible_v<CPP2_TYPEOF(h_), std::add_const_t<cpp2::i32>&>) {
                                                           h = CPP2_FORWARD(h_);
                                                           return *this;}
[[nodiscard]] auto base::hash() const& -> size_t{

size_t ret {0}; 
cpp2::hash_combine(ret, std::hash<cpp2::i32>()(h));
return ret; 
}

mystruct::mystruct(auto&& i_, auto&& j_, auto&& k_)
requires (std::is_convertible_v<CPP2_TYPEOF(i_), std::add_const_t<cpp2::i32>&> && std::is_convertible_v<CPP2_TYPEOF(j_), std::add_const_t<std::string>&> && std::is_convertible_v<CPP2_TYPEOF(k_), std::add_const_t<cpp2::u64>&>) 
                                                                                                       : base{ (1) }
                                                                                                       , i{ CPP2_FORWARD(i_) }
                                                                                                       , j{ CPP2_FORWARD(j_) }
                                                                                                       , k{ CPP2_FORWARD(k_) }{}
[[nodiscard]] auto mystruct::hash() const& -> size_t{

size_t ret {0}; 
cpp2::hash_combine(ret, base::hash());
cpp2::hash_combine(ret, std::hash<cpp2::i32>()(i));
cpp2::hash_combine(ret, std::hash<std::string>()(j));
cpp2::hash_combine(ret, std::hash<cpp2::u64>()(k));
return ret; 
}
#line 12 "pure2-hashable.cpp2"
auto main() -> int{
    mystruct x {2, "three", 4u}; 
    std::cout << CPP2_UFCS(hash)(cpp2::move(x));
}

