/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#ifndef _THRIFT_WINDOWS_CONFIG_H_
#define _THRIFT_WINDOWS_CONFIG_H_ 1

#if defined(_MSC_VER) && (_MSC_VER > 1200)
#pragma once
#endif // _MSC_VER

#ifndef _WIN32
#error This is a MSVC header only.
#endif

// use std::thread in MSVC11 (2012) or newer
#if _MSC_VER >= 1700
#  define USE_STD_THREAD 1
// otherwise use boost threads
#else
#  define USE_BOOST_THREAD 1
#endif

#ifndef TARGET_WIN_XP
#  define TARGET_WIN_XP 1
#endif

#if TARGET_WIN_XP
#  ifndef WINVER
#    define WINVER 0x0501
#  endif
#  ifndef _WIN32_WINNT
#    define _WIN32_WINNT 0x0501
#  endif
#endif

#ifndef _WIN32_WINNT
#  define _WIN32_WINNT 0x0601
#endif

#pragma warning(disable: 4996) // Deprecated posix name.

#define VERSION "1.0.0-dev"
#define HAVE_GETTIMEOFDAY 1
#define HAVE_SYS_STAT_H 1

#ifdef HAVE_STDINT_H
#  include <stdint.h>

using std::int64_t;
using std::uint64_t;
using std::int32_t;
using std::uint32_t;
using std::int16_t;
using std::uint16_t;
using std::int8_t;
using std::uint8_t;

//typedef std::int64_t    int64_t;
//typedef std::uint64_t  uint64_t;
//typedef std::int32_t    int32_t;
//typedef std::uint32_t  uint32_t;
//typedef std::int16_t    int16_t;
//typedef std::uint16_t  uint16_t;
//typedef std::int8_t      int8_t;
//typedef std::uint8_t    uint8_t;

#else
#  include <boost/cstdint.hpp>

//改成使用using
using boost::int64_t;
using boost::uint64_t;
using boost::int32_t;
using boost::uint32_t;
using boost::int16_t;
using boost::uint16_t;
using boost::int8_t;
using boost::uint8_t;

#if !defined(__cplusplus) || defined(__STDC_LIMIT_MACROS) // [   See footnote 220 at page 257 and footnote 221 at page 259

// 7.18.2.1 Limits of exact-width integer types
#define INT8_MIN     ((int8_t)_I8_MIN)
#define INT8_MAX     _I8_MAX
#define INT16_MIN    ((int16_t)_I16_MIN)
#define INT16_MAX    _I16_MAX
#define INT32_MIN    ((int32_t)_I32_MIN)
#define INT32_MAX    _I32_MAX
#define INT64_MIN    ((int64_t)_I64_MIN)
#define INT64_MAX    _I64_MAX
#define UINT8_MAX    _UI8_MAX
#define UINT16_MAX   _UI16_MAX
#define UINT32_MAX   _UI32_MAX
#define UINT64_MAX   _UI64_MAX

// 7.18.2.2 Limits of minimum-width integer types
#define INT_LEAST8_MIN    INT8_MIN
#define INT_LEAST8_MAX    INT8_MAX
#define INT_LEAST16_MIN   INT16_MIN
#define INT_LEAST16_MAX   INT16_MAX
#define INT_LEAST32_MIN   INT32_MIN
#define INT_LEAST32_MAX   INT32_MAX
#define INT_LEAST64_MIN   INT64_MIN
#define INT_LEAST64_MAX   INT64_MAX
#define UINT_LEAST8_MAX   UINT8_MAX
#define UINT_LEAST16_MAX  UINT16_MAX
#define UINT_LEAST32_MAX  UINT32_MAX
#define UINT_LEAST64_MAX  UINT64_MAX

// 7.18.2.3 Limits of fastest minimum-width integer types
#define INT_FAST8_MIN    INT8_MIN
#define INT_FAST8_MAX    INT8_MAX
#define INT_FAST16_MIN   INT16_MIN
#define INT_FAST16_MAX   INT16_MAX
#define INT_FAST32_MIN   INT32_MIN
#define INT_FAST32_MAX   INT32_MAX
#define INT_FAST64_MIN   INT64_MIN
#define INT_FAST64_MAX   INT64_MAX
#define UINT_FAST8_MAX   UINT8_MAX
#define UINT_FAST16_MAX  UINT16_MAX
#define UINT_FAST32_MAX  UINT32_MAX
#define UINT_FAST64_MAX  UINT64_MAX

// 7.18.2.4 Limits of integer types capable of holding object pointers
#ifdef _WIN64 // [
#  define INTPTR_MIN   INT64_MIN
#  define INTPTR_MAX   INT64_MAX
#  define UINTPTR_MAX  UINT64_MAX
#else // _WIN64 ][
#  define INTPTR_MIN   INT32_MIN
#  define INTPTR_MAX   INT32_MAX
#  define UINTPTR_MAX  UINT32_MAX
#endif // _WIN64 ]

// 7.18.2.5 Limits of greatest-width integer types
#define INTMAX_MIN   INT64_MIN
#define INTMAX_MAX   INT64_MAX
#define UINTMAX_MAX  UINT64_MAX

// 7.18.3 Limits of other integer types

#ifdef _WIN64 // [
#  define PTRDIFF_MIN  _I64_MIN
#  define PTRDIFF_MAX  _I64_MAX
#else  // _WIN64 ][
#  define PTRDIFF_MIN  _I32_MIN
#  define PTRDIFF_MAX  _I32_MAX
#endif  // _WIN64 ]

#define SIG_ATOMIC_MIN  INT_MIN
#define SIG_ATOMIC_MAX  INT_MAX

#ifndef SIZE_MAX // [
#  ifdef _WIN64 // [
#     define SIZE_MAX  _UI64_MAX
#  else // _WIN64 ][
#     define SIZE_MAX  _UI32_MAX
#  endif // _WIN64 ]
#endif // SIZE_MAX ]

// WCHAR_MIN and WCHAR_MAX are also defined in <wchar.h>
#ifndef WCHAR_MIN // [
#  define WCHAR_MIN  0
#endif  // WCHAR_MIN ]
#ifndef WCHAR_MAX // [
#  define WCHAR_MAX  _UI16_MAX
#endif  // WCHAR_MAX ]

#define WINT_MIN  0
#define WINT_MAX  _UI16_MAX

#endif // __STDC_LIMIT_MACROS ]

//vc2008编译器并不能正确识别这种语法
//typedef boost::int64_t    int64_t;
//typedef boost::uint64_t  uint64_t;
//typedef boost::int32_t    int32_t;
//typedef boost::uint32_t  uint32_t;
//typedef boost::int16_t    int16_t;
//typedef boost::uint16_t  uint16_t;
//typedef boost::int8_t      int8_t;
//typedef boost::uint8_t    uint8_t;
#endif

#include <thrift/transport/PlatformSocket.h>
#include <thrift/windows/GetTimeOfDay.h>
#include <thrift/windows/Operators.h>
#include <thrift/windows/TWinsockSingleton.h>
#include <thrift/windows/WinFcntl.h>
#include <thrift/windows/SocketPair.h>

// windows
#include <Winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "advapi32.lib") //For security APIs in TPipeServer

#endif // _THRIFT_WINDOWS_CONFIG_H_
