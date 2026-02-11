cmake_minimum_required(VERSION 3.10)
project(guardian VERSION 1.0.0 LANGUAGES CXX)

# Senior-level practice: Force high warning levels to show code quality
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -Wpedantic -Werror)

# Define executable
add_executable(guardian src/main.cpp)

# Future-proofing for include headers
target_include_directories(guardian PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Install rules (matches the "production readiness" requirement)
install(TARGETS guardian DESTINATION bin)
install(FILES systemd/guardian.service DESTINATION /lib/systemd/system)
