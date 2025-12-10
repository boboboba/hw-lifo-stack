#include "stack.hpp"

#include <cstddef>
#include <unordered_map>
#include <vector>
#include <cstring>

namespace stack
{
std::unordered_map<Handle, std::vector<char>> stacks;
std::unordered_map<Handle, int> stack_counts;

Handle pointer = 0;
Handle create()
{
    stacks[pointer];
    return pointer++;
}

void destroy(const Handle handle)
{
    stacks.erase(handle);
}

bool valid(const Handle handle)
{
    return stacks.find(handle) != stacks.end();
}

std::size_t count(const Handle handle)
{
    if (!valid(handle))
        return 0;
    return stack_counts[handle];
}

void push(const Handle handle, const void* const data, const std::size_t size)
{
    if (!valid(handle) || data == nullptr || size == 0)
        return;
    const char* char_data = static_cast<const char*>(data);
    std::vector<char>& stack = stacks[handle];
    for (std::size_t i = 0; i < size; i++)
    {
        stack.push_back(char_data[i]);
    }
    stack_counts[handle]++;
}

std::size_t pop(const Handle handle, void* const data, const std::size_t size)
{
    if (!valid(handle) || stack_counts[handle] == 0)
        return 0;
    std::vector<char>& stack = stacks[handle];
    const std::size_t stack_size = stack.size();
    const char* stack_data = stack.data();

    const std::size_t actual_size = std::min(size, stack_size);
    const char* start = stack_data + stack_size - actual_size;

    std::memcpy(data, start, actual_size);
    stack.erase(
        stack.begin() + static_cast<long>(stack_size - actual_size),
        stack.end());
    stack_counts[handle]--;
    return actual_size;
}

} // namespace stack
