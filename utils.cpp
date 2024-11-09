/* Utility functions - Version 1.1.0
   Copyright (c) 2024 Samuel Lourenço

   This library is free software: you can redistribute it and/or modify it
   under the terms of the GNU Lesser General Public License as published by
   the Free Software Foundation, either version 3 of the License, or (at your
   option) any later version.

   This library is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
   FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
   License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this library.  If not, see <https://www.gnu.org/licenses/>.


   Please feel free to contact me via e-mail: samuel.fmlourenco@gmail.com */


// Includes
#include <cstring>
#include "utils.h"

// Checks if a given C string constitutes a valid integer
bool Utils::isInteger(char *value)
{
    bool retval = true;
    if (value[0] != '+' && value[0] != '-' && (value[0] < '0' || value[0] > '9')) {  // Number is not valid if the first character is not a '+', '-', nor a digit
        retval = false;
    } else {
        size_t len = strlen(value);
        for (size_t i = 1; i < len; ++i) {
            if (value[i] < '0' || value[i] > '9') {  // Number is not valid if subsequent characters are not digits
                retval = false;
                break;
            }
        }
    }
    return retval;
}

// Checks if a given string constitutes a valid integer
bool Utils::isInteger(std::string value)
{
    return isInteger(value.c_str());
}

// Checks if a given C string constitutes a valid number
bool Utils::isNumber(char *value)
{
    bool retval = true;
    if (value[0] != '+' && value[0] != '-' && value[0] != '.' && (value[0] < '0' || value[0] > '9')) {  // Number is not valid if the first character is not a '+', '-', '.', nor a digit
        retval = false;
    } else {
        bool dp_exists = false;
        if (value[0] == '.') {  // If character is a decimal point
            dp_exists = true;
        }
        size_t len = strlen(value);
        for (size_t i = 1; i < len; ++i) {
            if ((value[i] != '.' || dp_exists) && (value[i] < '0' || value[i] > '9')) {  // Number is not valid if subsequent characters are not digits or if there is more than one decimal point
                retval = false;
                break;
            }
            if (value[i] == '.') {  // As before, if character is a decimal point
                dp_exists = true;
            }
        }
    }
    return retval;
}

// Checks if a given string constitutes a valid number
bool Utils::isNumber(std::string value)
{
    return isNumber(value.c_str());
}

// Reverses the bit order of a given byte
void Utils::reverse(uint8_t &value) {
    value = static_cast<uint8_t>((value & 0xf0) >> 4 | (value & 0x0f) << 4);
    value = static_cast<uint8_t>((value & 0xcc) >> 2 | (value & 0x33) << 2);
    value = static_cast<uint8_t>((value & 0xaa) >> 1 | (value & 0x55) << 1);
}

// Reverses the bit order of a given word
void Utils::reverse(uint16_t &value) {
    value = static_cast<uint16_t>((value & 0xff00) >> 8 | (value & 0x00ff) << 8);
    value = static_cast<uint16_t>((value & 0xf0f0) >> 4 | (value & 0x0f0f) << 4);
    value = static_cast<uint16_t>((value & 0xcccc) >> 2 | (value & 0x3333) << 2);
    value = static_cast<uint16_t>((value & 0xaaaa) >> 1 | (value & 0x5555) << 1);
}

// Reverses the bit order of a given dword
void Utils::reverse(uint32_t &value) {
    value = static_cast<uint32_t>((value & 0xffff0000) >> 16 | (value & 0x0000ffff) << 16);
    value = static_cast<uint32_t>((value & 0xff00ff00) >> 8 | (value & 0x00ff00ff) << 8);
    value = static_cast<uint32_t>((value & 0xf0f0f0f0) >> 4 | (value & 0x0f0f0f0f) << 4);
    value = static_cast<uint32_t>((value & 0xcccccccc) >> 2 | (value & 0x33333333) << 2);
    value = static_cast<uint32_t>((value & 0xaaaaaaaa) >> 1 | (value & 0x55555555) << 1);
}

// Reverses the bit order of a given qword
void Utils::reverse(uint64_t &value) {
    value = static_cast<uint64_t>((value & 0xffffffff00000000) >> 32 | (value & 0x00000000ffffffff) << 32);
    value = static_cast<uint64_t>((value & 0xffff0000ffff0000) >> 16 | (value & 0x0000ffff0000ffff) << 16);
    value = static_cast<uint64_t>((value & 0xff00ff00ff00ff00) >> 8 | (value & 0x00ff00ff00ff00ff) << 8);
    value = static_cast<uint64_t>((value & 0xf0f0f0f0f0f0f0f0) >> 4 | (value & 0x0f0f0f0f0f0f0f0f) << 4);
    value = static_cast<uint64_t>((value & 0xcccccccccccccccc) >> 2 | (value & 0x3333333333333333) << 2);
    value = static_cast<uint64_t>((value & 0xaaaaaaaaaaaaaaaa) >> 1 | (value & 0x5555555555555555) << 1);
}

// Returns a byte having the bit order reversed in relation to a given byte
uint8_t Utils::reversed(uint8_t value) {
    reverse(value);
    return value;
}

// Returns a word having the bit order reversed in relation to a given word
uint16_t Utils::reversed(uint16_t value) {
    reverse(value);
    return value;
}

// Returns a dword having the bit order reversed in relation to a given dword
uint32_t Utils::reversed(uint32_t value) {
    reverse(value);
    return value;
}

// Returns a qword having the bit order reversed in relation to a given qword
uint64_t Utils::reversed(uint64_t value) {
    reverse(value);
    return value;
}
