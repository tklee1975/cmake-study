//
//  TestHelper.h
//  011_testcpp
//
//  Created by kenlee on 26/3/2021.
//

#pragma once

//#define PRINT_TYPE(_var_)   printf("%s: type=%s", "x", typeid(_var_).name)    // ken: not working?
#define PRINT_SIMPLE_TYPE(_var_)   std::cout << #_var_ << ": type: " << typeid(_var_).name() << "\n"

#define PRINT_TYPE(_var_)   std::cout << #_var_ << ": type= [" << type_name<decltype(_var_)>() << "]\n"

#define PRINT_SEP           std::cout << "---------------------------------\n"



#include <iostream>
#include <string_view>

template <typename T>
constexpr auto type_name() noexcept {
  std::string_view name, prefix, suffix;
#ifdef __clang__
  name = __PRETTY_FUNCTION__;
  prefix = "auto type_name() [T = ";
  suffix = "]";
#elif defined(__GNUC__)
  name = __PRETTY_FUNCTION__;
  prefix = "constexpr auto type_name() [with T = ";
  suffix = "]";
#elif defined(_MSC_VER)
  name = __FUNCSIG__;
  prefix = "auto __cdecl type_name<";
  suffix = ">(void) noexcept";
#endif
  name.remove_prefix(prefix.size());
  name.remove_suffix(suffix.size());
  return name;
}

//#define 
