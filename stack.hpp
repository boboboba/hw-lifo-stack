#pragma once

#include <cstddef>

namespace stack {

using Handle = int;

// manage stacks lifetimes
Handle create();
void destroy(const Handle handle);

// stack metadata
bool valid(const Handle handle);
std::size_t count(const Handle handle);

// data operations
void push(const Handle handle, const void* const data, const std::size_t size);
std::size_t pop(const Handle handle, void* const data, const std::size_t size);

}
