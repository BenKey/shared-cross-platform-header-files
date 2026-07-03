#pragma once

#define DIAGNOSTIC_STRINGIZE_IMPL(x) #x
#define DIAGNOSTIC_STRINGIZE(x) DIAGNOSTIC_STRINGIZE_IMPL(x)

#if defined(_MSC_VER)
#  define DIAGNOSTIC_PUSH __pragma(warning(push))
#  define DIAGNOSTIC_POP  __pragma(warning(pop))
#  define DIAGNOSTIC_IGNORE_MSVC(id) __pragma(warning(disable : id))
#  define DIAGNOSTIC_IGNORE_GCC(w)
#  define DIAGNOSTIC_IGNORE_CLANG(w)
#elif defined(__clang__)
#  define DIAGNOSTIC_PUSH _Pragma("clang diagnostic push")
#  define DIAGNOSTIC_POP  _Pragma("clang diagnostic pop")
#  define DIAGNOSTIC_IGNORE_CLANG(w) _Pragma(DIAGNOSTIC_STRINGIZE(clang diagnostic ignored w))
#  define DIAGNOSTIC_IGNORE_GCC(w)   _Pragma(DIAGNOSTIC_STRINGIZE(GCC diagnostic ignored w))
#  define DIAGNOSTIC_IGNORE_MSVC(id)
#elif defined(__GNUC__)
#  define DIAGNOSTIC_PUSH _Pragma("GCC diagnostic push")
#  define DIAGNOSTIC_POP  _Pragma("GCC diagnostic pop")
#  define DIAGNOSTIC_IGNORE_GCC(w) _Pragma(DIAGNOSTIC_STRINGIZE(GCC diagnostic ignored w))
#  define DIAGNOSTIC_IGNORE_CLANG(w)
#  define DIAGNOSTIC_IGNORE_MSVC(id)
#else
#  define DIAGNOSTIC_PUSH
#  define DIAGNOSTIC_POP
#  define DIAGNOSTIC_IGNORE_MSVC(id)
#  define DIAGNOSTIC_IGNORE_GCC(w)
#  define DIAGNOSTIC_IGNORE_CLANG(w)
#endif

