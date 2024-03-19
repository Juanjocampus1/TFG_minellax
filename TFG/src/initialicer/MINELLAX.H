//this file is used to initialize the minellax libs, first we include the opengl libraries and then we include standard libraries
#define GLM_ENABLE_EXPERIMENTAL

// opengl libraries
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <assimp/Importer.hpp>

// glm libraries
#include <glm/glm.hpp>
#include <glm/gtc/integer.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>


// std libraries
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cerrno>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <optional>
#include <random>
#include <set>
#include <span>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>
#include <functional>
#include <type_traits>

using namespace std;


template<typename T>
using Ref = shared_ptr<T>;

template<typename T>
using WeakRef = weak_ptr<T>;

template<typename T>
using Scoped = unique_ptr<T>;
