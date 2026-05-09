#include "StringUtils.h"
#include <algorithm>

std::string StringUtils::toLower(const std::string &str)
{
    std::string lower = str;
    std::transform(lower.begin(), lower.end(), lower.begin(), [](unsigned char c)
                   { return std::tolower(c); });
    return lower;
}