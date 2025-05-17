# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\MebelParser_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\MebelParser_autogen.dir\\ParseCache.txt"
  "MebelParser_autogen"
  )
endif()
