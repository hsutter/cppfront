
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-types-ordering-via-meta-functions.cpp2"

#line 2 "pure2-types-ordering-via-meta-functions.cpp2"
class my_integer;
    

#line 7 "pure2-types-ordering-via-meta-functions.cpp2"
class case_insensitive_string;
    

#line 12 "pure2-types-ordering-via-meta-functions.cpp2"
class person_in_family_tree;
    

#line 17 "pure2-types-ordering-via-meta-functions.cpp2"
class mystruct;
    

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-types-ordering-via-meta-functions.cpp2"

#line 2 "pure2-types-ordering-via-meta-functions.cpp2"
class my_integer {
    private: int v; 
    public: explicit my_integer(cpp2::impl::in<int> val);
#line 4 "pure2-types-ordering-via-meta-functions.cpp2"
    public: auto operator=(cpp2::impl::in<int> val) -> my_integer& ;
    public: [[nodiscard]] auto operator<=>(my_integer const& that) const& -> std::strong_ordering = default;

    public: my_integer(my_integer const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(my_integer const&) -> void = delete;

#line 5 "pure2-types-ordering-via-meta-functions.cpp2"
};

class case_insensitive_string {
    private: std::string v; // case insensitive
    public: explicit case_insensitive_string(cpp2::impl::in<std::string> val);
#line 9 "pure2-types-ordering-via-meta-functions.cpp2"
    public: auto operator=(cpp2::impl::in<std::string> val) -> case_insensitive_string& ;
    public: [[nodiscard]] auto operator<=>(case_insensitive_string const& that) const& -> std::weak_ordering = default;

    public: case_insensitive_string(case_insensitive_string const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(case_insensitive_string const&) -> void = delete;

#line 10 "pure2-types-ordering-via-meta-functions.cpp2"
};

class person_in_family_tree {
    private: int dummy_data; 
    public: explicit person_in_family_tree(cpp2::impl::in<int> parents);
#line 14 "pure2-types-ordering-via-meta-functions.cpp2"
    public: auto operator=(cpp2::impl::in<int> parents) -> person_in_family_tree& ;
    public: [[nodiscard]] auto operator<=>(person_in_family_tree const& that) const& -> std::partial_ordering = default;

    public: person_in_family_tree(person_in_family_tree const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(person_in_family_tree const&) -> void = delete;

#line 15 "pure2-types-ordering-via-meta-functions.cpp2"
};

class mystruct {
    public: int val {0}; 
    public: mystruct(auto&& val_)
CPP2_REQUIRES_ (std::is_convertible_v<CPP2_TYPEOF(val_), std::add_const_t<int>&>) ;

public: auto operator=(auto&& val_) -> mystruct& 
CPP2_REQUIRES_ (std::is_convertible_v<CPP2_TYPEOF(val_), std::add_const_t<int>&>) ;
public: mystruct();

#line 19 "pure2-types-ordering-via-meta-functions.cpp2"
};

auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-types-ordering-via-meta-functions.cpp2"

#line 4 "pure2-types-ordering-via-meta-functions.cpp2"
    my_integer::my_integer(cpp2::impl::in<int> val)
                                        : v{ val }{}
#line 4 "pure2-types-ordering-via-meta-functions.cpp2"
    auto my_integer::operator=(cpp2::impl::in<int> val) -> my_integer& {
                                        v = val;
                                        return *this; }


#line 9 "pure2-types-ordering-via-meta-functions.cpp2"
    case_insensitive_string::case_insensitive_string(cpp2::impl::in<std::string> val)
                                                : v{ val }{}
#line 9 "pure2-types-ordering-via-meta-functions.cpp2"
    auto case_insensitive_string::operator=(cpp2::impl::in<std::string> val) -> case_insensitive_string& {
                                                v = val;
                                                return *this; }


#line 14 "pure2-types-ordering-via-meta-functions.cpp2"
    person_in_family_tree::person_in_family_tree(cpp2::impl::in<int> parents)
                                            : dummy_data{ parents }{}
#line 14 "pure2-types-ordering-via-meta-functions.cpp2"
    auto person_in_family_tree::operator=(cpp2::impl::in<int> parents) -> person_in_family_tree& {
                                            dummy_data = parents;
                                            return *this; }


    mystruct::mystruct(auto&& val_)
requires (std::is_convertible_v<CPP2_TYPEOF(val_), std::add_const_t<int>&>) 
                                                             : val{ CPP2_FORWARD(val_) }{}

auto mystruct::operator=(auto&& val_) -> mystruct& 
requires (std::is_convertible_v<CPP2_TYPEOF(val_), std::add_const_t<int>&>) {
                                                             val = CPP2_FORWARD(val_);
                                                             return *this;}
mystruct::mystruct(){}
#line 21 "pure2-types-ordering-via-meta-functions.cpp2"
auto main() -> int{
    my_integer a {1}; 
    my_integer b {2}; 
    if (cpp2::impl::cmp_less(cpp2::move(a),cpp2::move(b))) {
        std::cout << "less ";
    }
    else {
        std::cout << "more ";
    }

    case_insensitive_string c {"def"}; 
    case_insensitive_string d {"abc"}; 
    if (cpp2::impl::cmp_less(cpp2::move(c),cpp2::move(d))) {
        std::cout << "less ";
    }
    else {
        std::cout << "more ";
    }

    person_in_family_tree e {20}; 
    person_in_family_tree f {23}; 
    if (cpp2::impl::cmp_less(cpp2::move(e),cpp2::move(f))) {
        std::cout << "less\n";
    }
    else {
        std::cout << "more\n";
    }

    mystruct auto_1 {}; 
}

