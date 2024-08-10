
#define CPP2_IMPORT_STD          Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "pure2-is-with-polymorphic-types.cpp2"
class A;
#line 2 "pure2-is-with-polymorphic-types.cpp2"

template<int I> class VA;

class VC;
    

#line 10 "pure2-is-with-polymorphic-types.cpp2"
class VD;
    

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "pure2-is-with-polymorphic-types.cpp2"
class A {
      public: A() = default;
      public: A(A const&) = delete; /* No 'that' constructor, suppress copy */
      public: auto operator=(A const&) -> void = delete;
};
#line 2 "pure2-is-with-polymorphic-types.cpp2"

template<int I> class VA {
public: virtual ~VA() noexcept;

      public: VA() = default;
      public: VA(VA const&) = delete; /* No 'that' constructor, suppress copy */
      public: auto operator=(VA const&) -> void = delete;
};
#line 4 "pure2-is-with-polymorphic-types.cpp2"

class VC: public VA<0>, public VA<1> {
    public: VC() = default;
    public: VC(VC const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(VC const&) -> void = delete;


#line 8 "pure2-is-with-polymorphic-types.cpp2"
};

class VD: public VA<0> {
    public: VD() = default;
    public: VD(VD const&) = delete; /* No 'that' constructor, suppress copy */
    public: auto operator=(VD const&) -> void = delete;


#line 12 "pure2-is-with-polymorphic-types.cpp2"
};

auto fun(auto const& v, auto const& name) -> void;

#line 29 "pure2-is-with-polymorphic-types.cpp2"
auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "pure2-is-with-polymorphic-types.cpp2"


template <int I> VA<I>::~VA() noexcept{}
#line 14 "pure2-is-with-polymorphic-types.cpp2"
auto fun(auto const& v, auto const& name) -> void{
    std::cout << "" + cpp2::to_string(name) + " is";
    if (cpp2::impl::is<VC>(v)) {std::cout << " VC";}
    if (cpp2::impl::is<VA<0>>(v)) {std::cout << " VA<0>";}
    if (cpp2::impl::is<VA<1>>(v)) {std::cout << " VA<1>";}
    if (cpp2::impl::is<VD>(v)) {std::cout << " VD";}
    if (cpp2::impl::is<VC*>(v)) {std::cout << " *VC";}
    if (cpp2::impl::is<VA<0>*>(v)) {std::cout << " *VA<0>";}
    if (cpp2::impl::is<VA<1>*>(v)) {std::cout << " *VA<1>";}
    if (cpp2::impl::is<VD*>(v)) {std::cout << " *VD";}
    if (cpp2::impl::is<void>(v)) {std::cout << " empty";}
    if (cpp2::impl::is<A>(v)) {std::cout << " A";}
    std::cout << std::endl;
}

#line 29 "pure2-is-with-polymorphic-types.cpp2"
auto main() -> int{

    VC vc {}; 
    VA<0>* p0 {&vc}; 
    VA<1>* p1 {&vc}; 

    fun(vc, "vc");
    fun(*cpp2::impl::assert_not_null(p0), "p0*");
    fun(*cpp2::impl::assert_not_null(p1), "p1*");

    fun(&vc, "vc&");
    fun(cpp2::move(p0), "p0");
    fun(cpp2::move(p1), "p1");

    fun(nullptr, "nullptr");
    fun(A(), "A");
}

