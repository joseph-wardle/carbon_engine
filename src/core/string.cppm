module;

import carbon.core.types;

export module carbon.core.string;

namespace carbon::core {

    export class StringView {
        const char* data_ = nullptr;
        const usize size_ = 0;

    public:
        constexpr StringView() noexcept;
        constexpr StringView(const char* string) noexcept;
        constexpr StringView(const char* string, usize size) noexcept;

        constexpr const char* data() const noexcept;
        constexpr usize size() const noexcept;
        constexpr bool empty() const noexcept;

        constexpr char operator[](usize index) const noexcept;

        constexpr const char* begin() const noexcept;
        constexpr const char* end()   const noexcept;
    };


    export class String {
        char* data_     = nullptr;
        usize size_     = 0;
        usize capacity_ = 0;

        void grow_to(usize new_capacity) noexcept;

    public:
        constexpr String() noexcept;
        constexpr String(const char* string) noexcept;

        constexpr ~String() noexcept;

        String& operator=(const String& other) noexcept;
        String& operator=(String&& other) noexcept;

        usize size()       const noexcept;
        usize capacity()   const noexcept;
        const char* data() const noexcept;

        void reserve(usize new_capacity) noexcept;
        void clear() noexcept;

        char& operator[](usize index) noexcept;
        constexpr char operator[](usize index) const noexcept;
        const char* c_str() const noexcept;

        String& append(StringView string_view) noexcept;
        String& push_back(char c) noexcept;
    };
}