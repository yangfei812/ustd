#pragma once

#include "ustd/core/option.h"
#include "ustd/core/slice.h"

namespace ustd
{

struct Type
{
    char _type;
    u16  _size;
    str  _desc;

    pub fn fullname()   const noexcept->str;
    pub fn name()       const noexcept->str;
    pub fn mod()        const noexcept->str;
    pub fn to_str()     const noexcept->str;
};

class Formatter;
pub fn trait_sfmt(Formatter& fmt, const Type& type) noexcept -> void;

template<typename T>
fn typeof() noexcept -> Type {
    let type = trait<T>::$sint ? 'i' : trait<T>::$uint ? 'u' : trait<T>::$float ? 'f' : '?';
    let size = u16(sizeof(T));
    let desc = str(__PRETTY_FUNCTION__);
    return { type, size, desc };
}

template<>
inline fn typeof<void>() noexcept -> Type {
    let desc = str(__PRETTY_FUNCTION__);
    return { '?', 0,  desc };
}

}
