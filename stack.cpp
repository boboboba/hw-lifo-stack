#include "stack.hpp"

#include <cstddef>

// TODO: remove me
#define UNUSED(VAR) (void)(VAR)

namespace stack
{

Handle create()
{
    return -1;
}

void destroy(const Handle handle)
{
    UNUSED(handle);
}

bool valid(const Handle handle)
{
    UNUSED(handle);
    return false;
}

std::size_t count(const Handle handle)
{
    UNUSED(handle);
    return 0u;
}

void push(const Handle handle, const void* const data, const std::size_t size)
{
    UNUSED(handle);
    UNUSED(data);
    UNUSED(size);
}

std::size_t pop(const Handle handle, void* const data, const std::size_t size)
{
    UNUSED(handle);
    UNUSED(data);
    UNUSED(size);
    return 0u;
}

} // namespace stack
