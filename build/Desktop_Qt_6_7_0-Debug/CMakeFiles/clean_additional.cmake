# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "AirStrike_Game_autogen"
  "CMakeFiles/AirStrike_Game_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/AirStrike_Game_autogen.dir/ParseCache.txt"
  )
endif()
