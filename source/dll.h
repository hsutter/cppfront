
//  Copyright (c) Herb Sutter
//  SPDX-License-Identifier: CC-BY-NC-ND-4.0

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

//===========================================================================
//  Dynamic Library Loading
//===========================================================================

#ifndef CPP2_DLL_H
#define CPP2_DLL_H

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>
#else
#include <dlfcn.h>
#endif // _WIN32

namespace cpp2 {

class dll
{
    void* handle = {};
public:
    dll(std::string const& path)
    {
#ifdef _WIN32
        handle = static_cast<void*>(LoadLibraryA(path.c_str()));
#else
        handle = static_cast<void*>(dlopen(path.c_str(), RTLD_NOW|RTLD_LOCAL));
#endif // _WIN32
    }

    ~dll() noexcept
    {
        if(handle != nullptr)
        {
#ifdef _WIN32
            FreeLibrary(static_cast<HMODULE>(handle));
#else
            dlclose(handle);
#endif // _WIN32
        }
    }

    // Uncopyable
    dll(dll&) = delete;
    dll(dll const&) = delete;
    auto operator=(dll const&) -> dll& = delete;
    // Movable
    dll(dll&& from) noexcept
    {
        handle = from.handle;
        from.handle = nullptr;
    }
    auto operator=(dll&& from) noexcept -> dll&
    {
        handle = from.handle;
        from.handle = nullptr;
        return *this;
    }

    auto is_open() noexcept -> bool { return handle != nullptr; }

    static auto get_last_error() noexcept -> std::string {
#ifdef _WIN32
        DWORD error_msg_id = GetLastError();
        if(error_msg_id == 0)
            return {}; // No error message has been recorded
        LPSTR msg_buffer = nullptr;
        auto size = FormatMessageA(
            FORMAT_MESSAGE_ALLOCATE_BUFFER|FORMAT_MESSAGE_FROM_SYSTEM|FORMAT_MESSAGE_IGNORE_INSERTS,
            nullptr,
            error_msg_id,
            MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US),
            &msg_buffer,
            0,
            nullptr
        );
        std::string message(msg_buffer, static_cast<size_t>(size));
        LocalFree(msg_buffer);
        return message;
#else
        return std::string{dlerror()};
#endif // _WIN32
    }

    template<typename T>
    auto get_alias(std::string const& name) noexcept -> T*
    {
#ifdef _WIN32
        auto symbol = GetProcAddress(static_cast<HMODULE>(handle), name.c_str());
#else
        auto symbol = dlsym(handle, name.c_str());
        if(symbol == nullptr)
        {
            // Some platforms export with additional underscore, so try that.
            auto const us_name = "_" + name;
            symbol = dlsym(handle, us_name.c_str());
        }
#endif // _WIN32
        return function_cast_<T*>(symbol);
    }
private:

    template<typename T>
    static auto function_cast_(auto ptr) noexcept -> T {
        using generic_function_ptr = void (*)(void);
        return reinterpret_cast<T>(reinterpret_cast<generic_function_ptr>(ptr));
    }
};

}

#endif // CPP2_DLL_H
