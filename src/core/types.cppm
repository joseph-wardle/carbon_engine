export module carbon.core.types;

export namespace carbon {

    using i8  = signed char;
    using i16 = signed short;
    using i32 = signed int;
    using i64 = signed long long;
    using usize =  __UINTPTR_TYPE__;

    using u8  = unsigned char;
    using u16 = unsigned short;
    using u32 = unsigned int;
    using u64 = unsigned long long;
    using isize = __INTPTR_TYPE__;

    using f32 = float;
    using f64 = double;


    static_assert(sizeof(i8) == 1);
    static_assert(sizeof(i16) == 2);
    static_assert(sizeof(i32) == 4);
    static_assert(sizeof(i64) == 8);
    static_assert(sizeof(isize) == sizeof(void*));

    static_assert(sizeof(u8) == 1);
    static_assert(sizeof(u16) == 2);
    static_assert(sizeof(u32) == 4);
    static_assert(sizeof(u64) == 8);
    static_assert(sizeof(usize) == sizeof(void*));

    static_assert(sizeof(f32) == 4);
    static_assert(sizeof(f64) == 8);

    static_assert(sizeof(char) == 1);
    static_assert(sizeof(bool) == 1);

}