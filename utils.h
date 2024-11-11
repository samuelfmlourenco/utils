/* Utility functions - Version 1.1.0
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


#ifndef UTILS_H
#define UTILS_H

// Includes
#include <cstdint>
#include <string>

namespace Utils
{
bool isInteger(char *value);
bool isInteger(std::string value);
bool isNumber(char *value);
bool isNumber(std::string value);
void reverse(uint8_t &value);
void reverse(uint16_t &value);
void reverse(uint32_t &value);
void reverse(uint64_t &value);
uint8_t reversed(uint8_t value);
uint16_t reversed(uint16_t value);
uint32_t reversed(uint32_t value);
uint64_t reversed(uint64_t value);
}

#endif  // UTILS_H
