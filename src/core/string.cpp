module;

import carbon.core.types;

module carbon.core.string;

namespace carbon::core {

    namespace detail {
        constexpr usize strlen(const char* string) noexcept {
            usize i = 0;
            while (string[i] != '\0') ++i;
            return i;
        }
    }

    // ----- StringView definitions -----

    constexpr StringView::StringView() noexcept = default;
    constexpr StringView::StringView(const char* string) noexcept
        : data_{string}, size_{detail::strlen(string)} {}
    constexpr StringView::StringView(const char* string, usize size) noexcept
        : data_{string}, size_{size} {}

    constexpr const char* StringView::data() const noexcept { return data_; }
    constexpr usize StringView::size()       const noexcept { return size_; }
    constexpr bool  StringView::empty()      const noexcept { return size_ == 0; }

    constexpr char StringView::operator[](usize index) const noexcept { return data_[index]; }

    constexpr const char* StringView::begin() const noexcept { return data_; }
    constexpr const char* StringView::end()   const noexcept { return data_ + size_; }
}