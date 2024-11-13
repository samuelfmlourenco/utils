/* Utility functions - Version 1.1.1
   Copyright (c) 2022-2024 Samuel Lourenço

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
        bool dpExists = false;
        if (value[0] == '.') {  // If character is a decimal point
            dpExists = true;
        }
        size_t len = strlen(value);
        for (size_t i = 1; i < len; ++i) {
            if ((value[i] != '.' || dpExists) && (value[i] < '0' || value[i] > '9')) {  // Number is not valid if subsequent characters are not digits or if there is more than one decimal point
                retval = false;
                break;
            }
            if (value[i] == '.') {  // As before, if character is a decimal point
                dpExists = true;
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
    value = static_cast<uint8_t>((0xf0 & value) >> 4 | (0x0f & value) << 4);
    value = static_cast<uint8_t>((0xcc & value) >> 2 | (0x33 & value) << 2);
    value = static_cast<uint8_t>((0xaa & value) >> 1 | (0x55 & value) << 1);
}

// Reverses the bit order of a given word
void Utils::reverse(uint16_t &value) {
    value = static_cast<uint16_t>((0xff00 & value) >> 8 | (0x00ff & value) << 8);
    value = static_cast<uint16_t>((0xf0f0 & value) >> 4 | (0x0f0f & value) << 4);
    value = static_cast<uint16_t>((0xcccc & value) >> 2 | (0x3333 & value) << 2);
    value = static_cast<uint16_t>((0xaaaa & value) >> 1 | (0x5555 & value) << 1);
}

// Reverses the bit order of a given dword
void Utils::reverse(uint32_t &value) {
    value = static_cast<uint32_t>((0xffff0000 & value) >> 16 | (0x0000ffff & value) << 16);
    value = static_cast<uint32_t>((0xff00ff00 & value) >> 8 | (0x00ff00ff & value) << 8);
    value = static_cast<uint32_t>((0xf0f0f0f0 & value) >> 4 | (0x0f0f0f0f & value) << 4);
    value = static_cast<uint32_t>((0xcccccccc & value) >> 2 | (0x33333333 & value) << 2);
    value = static_cast<uint32_t>((0xaaaaaaaa & value) >> 1 | (0x55555555 & value) << 1);
}

// Reverses the bit order of a given qword
void Utils::reverse(uint64_t &value) {
    value = static_cast<uint64_t>((0xffffffff00000000 & value) >> 32 | (0x00000000ffffffff & value) << 32);
    value = static_cast<uint64_t>((0xffff0000ffff0000 & value) >> 16 | (0x0000ffff0000ffff & value) << 16);
    value = static_cast<uint64_t>((0xff00ff00ff00ff00 & value) >> 8 | (0x00ff00ff00ff00ff & value) << 8);
    value = static_cast<uint64_t>((0xf0f0f0f0f0f0f0f0 & value) >> 4 | (0x0f0f0f0f0f0f0f0f & value) << 4);
    value = static_cast<uint64_t>((0xcccccccccccccccc & value) >> 2 | (0x3333333333333333 & value) << 2);
    value = static_cast<uint64_t>((0xaaaaaaaaaaaaaaaa & value) >> 1 | (0x5555555555555555 & value) << 1);
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
