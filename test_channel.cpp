#line 2 "test_channel.cpp2"
#include <queue>
#include <optional>


//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "test_channel.cpp2"

#line 6 "test_channel.cpp2"
template<typename T> class channel;
    

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "test_channel.cpp2"
// Minimal test for channel metaclass

#line 5 "test_channel.cpp2"
// @channel - Kotlin's Channel<T> equivalent for CSP-style concurrency
#line 6 "test_channel.cpp2"
template<typename T> class channel {
    private: std::queue<T> buffer {}; 
    private: int capacity {0}; // 0 = unbuffered, >0 = buffered
    private: bool is_closed {false}; 

    // Send operation (would be suspend in real Kotlin)
    public: [[nodiscard]] auto send(cpp2::impl::in<T> value) & -> bool;

#line 23 "test_channel.cpp2"
    // Receive operation (would be suspend in real Kotlin)
    public: [[nodiscard]] auto receive() & -> std::optional<T>;

#line 36 "test_channel.cpp2"
    public: auto close() & -> void;
    public: [[nodiscard]] auto operator<=>(channel const& that) const& -> std::strong_ordering = default;
public: channel(channel const& that);

public: auto operator=(channel const& that) -> channel& ;
public: channel(channel&& that) noexcept;
public: auto operator=(channel&& that) noexcept -> channel& ;
public: explicit channel();

#line 39 "test_channel.cpp2"
};

[[nodiscard]] auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "test_channel.cpp2"

#line 12 "test_channel.cpp2"
    template <typename T> [[nodiscard]] auto channel<T>::send(cpp2::impl::in<T> value) & -> bool{
        if (is_closed) {
            return false; 
        }
        if (capacity == 0 || cpp2::impl::cmp_less(CPP2_UFCS(size)(buffer),capacity)) {
            CPP2_UFCS(push)(buffer, value);
            return true; 
        }
        return false;  // Would suspend in real implementation
    }

#line 24 "test_channel.cpp2"
    template <typename T> [[nodiscard]] auto channel<T>::receive() & -> std::optional<T>{
        if (!(CPP2_UFCS(empty)(buffer))) {
            T value {CPP2_UFCS(front)(buffer)}; 
            CPP2_UFCS(pop)(buffer);
            return value; 
        }
        if (is_closed) {
            return std::nullopt; 
        }
        return std::nullopt;  // Would suspend in real implementation
    }

#line 36 "test_channel.cpp2"
    template <typename T> auto channel<T>::close() & -> void{
        is_closed = true;
    }


    template <typename T> channel<T>::channel(channel const& that)
                                : buffer{ that.buffer }
                                , capacity{ that.capacity }
                                , is_closed{ that.is_closed }{}

template <typename T> auto channel<T>::operator=(channel const& that) -> channel& {
                                buffer = that.buffer;
                                capacity = that.capacity;
                                is_closed = that.is_closed;
                                return *this;}
template <typename T> channel<T>::channel(channel&& that) noexcept
                                : buffer{ std::move(that).buffer }
                                , capacity{ std::move(that).capacity }
                                , is_closed{ std::move(that).is_closed }{}
template <typename T> auto channel<T>::operator=(channel&& that) noexcept -> channel& {
                                buffer = std::move(that).buffer;
                                capacity = std::move(that).capacity;
                                is_closed = std::move(that).is_closed;
                                return *this;}
template <typename T> channel<T>::channel(){}
#line 41 "test_channel.cpp2"
[[nodiscard]] auto main() -> int{
    channel<std::string> ch {10}; 
    return 0; 
}

