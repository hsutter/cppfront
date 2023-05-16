
#define CPP2_USE_MODULES         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"


#line 2 "pure2-types-ordering-via-meta-functions.cpp2"
class my_integer;
    

#line 7 "pure2-types-ordering-via-meta-functions.cpp2"
class case_insensitive_string;
    

#line 12 "pure2-types-ordering-via-meta-functions.cpp2"
class person_in_family_tree;
    

#line 17 "pure2-types-ordering-via-meta-functions.cpp2"
class mystruct;
    

//=== Cpp2 type definitions and function declarations ===========================


#line 2 "pure2-types-ordering-via-meta-functions.cpp2"
class my_integer {
    private: int v; 
    public: explicit my_integer(cpp2::in<int> val);
#line 4 "pure2-types-ordering-via-meta-functions.cpp2"
    public: auto operator=(cpp2::in<int> val) -> my_integer& ;

public: [[nodiscard]] auto operator<=>(my_integer const& that) const -> std::strong_ordering = default;

    public: my_integer(my_integer const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(my_integer const&) -> void = delete;
#line 5 "pure2-types-ordering-via-meta-functions.cpp2"
};

class case_insensitive_string {
    private: std::string v; // case insensitive
    public: explicit case_insensitive_string(cpp2::in<std::string> val);
#line 9 "pure2-types-ordering-via-meta-functions.cpp2"
    public: auto operator=(cpp2::in<std::string> val) -> case_insensitive_string& ;

public: [[nodiscard]] auto operator<=>(case_insensitive_string const& that) const -> std::weak_ordering = default;

    public: case_insensitive_string(case_insensitive_string const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(case_insensitive_string const&) -> void = delete;
#line 10 "pure2-types-ordering-via-meta-functions.cpp2"
};

class person_in_family_tree {
    private: int dummy_data; 
    public: explicit person_in_family_tree(cpp2::in<int> parents);
#line 14 "pure2-types-ordering-via-meta-functions.cpp2"
    public: auto operator=(cpp2::in<int> parents) -> person_in_family_tree& ;

public: [[nodiscard]] auto operator<=>(person_in_family_tree const& that) const -> std::partial_ordering = default;

    public: person_in_family_tree(person_in_family_tree const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(person_in_family_tree const&) -> void = delete;
#line 15 "pure2-types-ordering-via-meta-functions.cpp2"
};

class mystruct {
    public: int val {0}; 
    public: mystruct(mystruct const& that);

public: auto operator=(mystruct const& that) -> mystruct& ;
public: mystruct(mystruct&& that) noexcept;
public: auto operator=(mystruct&& that) noexcept -> mystruct& ;
public: explicit mystruct();

#line 19 "pure2-types-ordering-via-meta-functions.cpp2"
};

auto main() -> int;
    

//=== Cpp2 function definitions =================================================


#line 4 "pure2-types-ordering-via-meta-functions.cpp2"
    my_integer::my_integer(cpp2::in<int> val)
                                        : v{ val }
#line 4 "pure2-types-ordering-via-meta-functions.cpp2"
    {}
#line 4 "pure2-types-ordering-via-meta-functions.cpp2"
    auto my_integer::operator=(cpp2::in<int> val) -> my_integer& {
                                        v = val;
                                        return *this;
#line 4 "pure2-types-ordering-via-meta-functions.cpp2"
    }


#line 9 "pure2-types-ordering-via-meta-functions.cpp2"
    case_insensitive_string::case_insensitive_string(cpp2::in<std::string> val)
                                                : v{ val }
#line 9 "pure2-types-ordering-via-meta-functions.cpp2"
    {}
#line 9 "pure2-types-ordering-via-meta-functions.cpp2"
    auto case_insensitive_string::operator=(cpp2::in<std::string> val) -> case_insensitive_string& {
                                                v = val;
                                                return *this;
#line 9 "pure2-types-ordering-via-meta-functions.cpp2"
    }


#line 14 "pure2-types-ordering-via-meta-functions.cpp2"
    person_in_family_tree::person_in_family_tree(cpp2::in<int> parents)
                                            : dummy_data{ parents }
#line 14 "pure2-types-ordering-via-meta-functions.cpp2"
    {}
#line 14 "pure2-types-ordering-via-meta-functions.cpp2"
    auto person_in_family_tree::operator=(cpp2::in<int> parents) -> person_in_family_tree& {
                                            dummy_data = parents;
                                            return *this;
#line 14 "pure2-types-ordering-via-meta-functions.cpp2"
    }


    mystruct::mystruct(mystruct const& that)
                                : val{ that.val }{}

auto mystruct::operator=(mystruct const& that) -> mystruct& {
                                val = that.val;
                                return *this;}
mystruct::mystruct(mystruct&& that) noexcept
                                : val{ std::move(that).val }{}
auto mystruct::operator=(mystruct&& that) noexcept -> mystruct& {
                                val = std::move(that).val;
                                return *this;}
mystruct::mystruct(){}
#line 21 "pure2-types-ordering-via-meta-functions.cpp2"
auto main() -> int{
    my_integer a {1}; 
    my_integer b {2}; 
    if (cpp2::cmp_less(std::move(a),std::move(b))) {
        std::cout << "less ";
    }
    else {
        std::cout << "more ";
    }

    case_insensitive_string c {"def"}; 
    case_insensitive_string d {"abc"}; 
    if (cpp2::cmp_less(std::move(c),std::move(d))) {
        std::cout << "less ";
    }
    else {
        std::cout << "more ";
    }

    person_in_family_tree e {20}; 
    person_in_family_tree f {23}; 
    if (cpp2::cmp_less(std::move(e),std::move(f))) {
        std::cout << "less\n";
    }
    else {
        std::cout << "more\n";
    }

    mystruct s {}; 
}

