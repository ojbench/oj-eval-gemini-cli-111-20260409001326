#pragma once

#undef strtok

char *strtok(char * __restrict str, const char * __restrict delim) {
    static char *p = nullptr;
    if (str != nullptr) {
        p = str;
    } else if (p == nullptr) {
        return nullptr;
    }

    bool is_delim[256] = {false};
    for (const char *d = delim; *d != '\0'; ++d) {
        is_delim[(unsigned char)*d] = true;
    }

    // Skip leading delimiters
    while (*p != '\0' && is_delim[(unsigned char)*p]) {
        ++p;
    }

    if (*p == '\0') {
        p = nullptr;
        return nullptr;
    }

    char *start = p;

    // Find the end of the token
    while (*p != '\0') {
        if (is_delim[(unsigned char)*p]) {
            *p = '\0';
            ++p;
            return start;
        }
        ++p;
    }

    // Reached the end of the string
    p = nullptr;
    return start;
}