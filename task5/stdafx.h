#pragma once

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include "targetver.h"
#endif

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <functional>


// boost
#include <boost\serialization\vector.hpp>
#include <boost\archive\binary_iarchive.hpp>
#include <boost\archive\binary_oarchive.hpp>
#include <boost\archive\text_oarchive.hpp>
#include <boost\archive\text_iarchive.hpp>
#include <boost\serialization\base_object.hpp>
