template<class char, class traits = char_traits<charT>, class Allocator = allocator<charT> >
class basic_string
{
public:
// types:
    typedef traits traits_type;
    typedef typename traits_type::char_type value_type;
    typedef Allocator allocator_type;
    typedef typename allocator_type::size_type size_type;
    typedef typename allocator_type::difference_type difference_type;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;
    typedef implementation-defined iterator;
    typedef implementation-defined const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

    static const size_type npos = -1;

    basic_string()
        noexcept(is_nothrow_default_constructible<allocator_type>::value);
    explicit basic_string(const allocator_type& a);
    basic_string(const basic_string& str);
    basic_string(basic_string&& str)
        noexcept(is_nothrow_move_constructible<allocator_type>::value);
    basic_string(const basic_string& str, size_type pos,
                 const allocator_type& a = allocator_type());
    basic_string(const basic_string& str, size_type pos, size_type n,
                 const Allocator& a = Allocator());
    template<class T>
        basic_string(const T& t, size_type pos, size_type n, const Allocator& a = Allocator()); // C++17
    template <class T>
        explicit basic_string(const T& t, const Allocator& a = Allocator()); // C++17
    basic_string(const value_type* s, const allocator_type& a = allocator_type());
    basic_string(const value_type* s, size_type n, const allocator_type& a = allocator_type());
    basic_string(nullptr_t) = delete; // C++2b
    basic_string(size_type n, value_type c, const allocator_type& a = allocator_type());
    template<class InputIterator>
        basic_string(InputIterator begin, InputIterator end,
                     const allocator_type& a = allocator_type());
    basic_string(initializer_list<value_type>, const Allocator& = Allocator());
    basic_string(const basic_string&, const Allocator&);
    basic_string(basic_string&&, const Allocator&);

    ~basic_string();

    operator basic_string_view<charT, traits>() const noexcept;

    basic_string& operator=(const basic_string& str);
    template <class T>
        basic_string& operator=(const T& t); // C++17
    basic_string& operator=(basic_string&& str)
        noexcept(
             allocator_type::propagate_on_container_move_assignment::value ||
             allocator_type::is_always_equal::value ); // C++17
    basic_string& operator=(const value_type* s);
    basic_string& operator=(nullptr_t) = delete; // C++2b
    basic_string& operator=(value_type c);
    basic_string& operator=(initializer_list<value_type>);

    iterator       begin() noexcept;
    const_iterator begin() const noexcept;
    iterator       end() noexcept;
    const_iterator end() const noexcept;

    reverse_iterator       rbegin() noexcept;
    const_reverse_iterator rbegin() const noexcept;
    reverse_iterator       rend() noexcept;
    const_reverse_iterator rend() const noexcept;

    const_iterator         cbegin() const noexcept;
    const_iterator         cend() const noexcept;
    const_reverse_iterator crbegin() const noexcept;
    const_reverse_iterator crend() const noexcept;

    size_type size() const noexcept;
    size_type length() const noexcept;
    size_type max_size() const noexcept;
    size_type capacity() const noexcept;

    void resize(size_type n, value_type c);
    void resize(size_type n);

    void reserve(size_type res_arg);
    void reserve(); // deprecated in C++20
    void shrink_to_fit();
    void clear() noexcept;
    bool empty() const noexcept;

    const_reference operator[](size_type pos) const;
    reference       operator[](size_type pos);

    const_reference at(size_type n) const;
    reference       at(size_type n);

    basic_string& operator+=(const basic_string& str);
    template <class T>
        basic_string& operator+=(const T& t);              // C++17
    basic_string& operator+=(const value_type* s);
    basic_string& operator+=(value_type c);
    basic_string& operator+=(initializer_list<value_type>);

    basic_string& append(const basic_string& str);
    template <class T>
        basic_string& append(const T& t);                 // C++17
    basic_string& append(const basic_string& str, size_type pos, size_type n=npos); //C++14
    template <class T>
        basic_string& append(const T& t, size_type pos, size_type n=npos); // C++17
    basic_string& append(const value_type* s, size_type n);
    basic_string& append(const value_type* s);
    basic_string& append(size_type n, value_type c);
    template<class InputIterator>
        basic_string& append(InputIterator first, InputIterator last);
    basic_string& append(initializer_list<value_type>);

    void push_back(value_type c);
    void pop_back();
    reference       front();
    const_reference front() const;
    reference       back();
    const_reference back() const;

    basic_string& assign(const basic_string& str);
    template <class T>
        basic_string& assign(const T& t);  // C++17
    basic_string& assign(basic_string&& str);
    basic_string& assign(const basic_string& str, size_type pos, size_type n=npos); // C++14
    template <class T>
        basic_string& assign(const T& t, size_type pos, size_type n=npos); // C++17
    basic_string& assign(const value_type* s, size_type n);
    basic_string& assign(const value_type* s);
    basic_string& assign(size_type n, value_type c);
    template<class InputIterator>
        basic_string& assign(InputIterator first, InputIterator last);
    basic_string& assign(initializer_list<value_type>);

    basic_string& insert(size_type pos1, const basic_string& str);
    template <class T>
        basic_string& insert(size_type pos1, const T& t);
    basic_string& insert(size_type pos1, const basic_string& str,
                         size_type pos2, size_type n);
    template <class T>
        basic_string& insert(size_type pos1, const T& t, size_type pos2, size_type n); // C++17
    basic_string& insert(size_type pos, const value_type* s, size_type n=npos); //C++14
    basic_string& insert(size_type pos, const value_type* s);
    basic_string& insert(size_type pos, size_type n, value_type c);
    iterator      insert(const_iterator p, value_type c);
    iterator      insert(const_iterator p, size_type n, value_type c);
    template<class InputIterator>
        iterator insert(const_iterator p, InputIterator first, InputIterator last);
    iterator      insert(const_iterator p, initializer_list<value_type>);

    basic_string& erase(size_type pos = 0, size_type n = npos);
    iterator      erase(const_iterator position);
    iterator      erase(const_iterator first, const_iterator last);

    basic_string& replace(size_type pos1, size_type n1, const basic_string& str);
    template <class T>
    basic_string& replace(size_type pos1, size_type n1, const T& t);  // C++17
    basic_string& replace(size_type pos1, size_type n1, const basic_string& str,
                          size_type pos2, size_type n2=npos); // C++14
    template <class T>
        basic_string& replace(size_type pos1, size_type n1, const T& t,
                              size_type pos2, size_type n); // C++17
    basic_string& replace(size_type pos, size_type n1, const value_type* s, size_type n2);
    basic_string& replace(size_type pos, size_type n1, const value_type* s);
    basic_string& replace(size_type pos, size_type n1, size_type n2, value_type c);
    basic_string& replace(const_iterator i1, const_iterator i2, const basic_string& str);
    template <class T>
        basic_string& replace(const_iterator i1, const_iterator i2, const T& t);  // C++17
    basic_string& replace(const_iterator i1, const_iterator i2, const value_type* s, size_type n);
    basic_string& replace(const_iterator i1, const_iterator i2, const value_type* s);
    basic_string& replace(const_iterator i1, const_iterator i2, size_type n, value_type c);
    template<class InputIterator>
        basic_string& replace(const_iterator i1, const_iterator i2, InputIterator j1, InputIterator j2);
    basic_string& replace(const_iterator i1, const_iterator i2, initializer_list<value_type>);

    size_type copy(value_type* s, size_type n, size_type pos = 0) const;
    basic_string substr(size_type pos = 0, size_type n = npos) const;

    void swap(basic_string& str)
        noexcept(allocator_traits<allocator_type>::propagate_on_container_swap::value ||
                 allocator_traits<allocator_type>::is_always_equal::value);  // C++17

    const value_type* c_str() const noexcept;
    const value_type* data() const noexcept;
          value_type* data()       noexcept;   // C++17

    allocator_type get_allocator() const noexcept;

    size_type find(const basic_string& str, size_type pos = 0) const noexcept;
    template <class T>
        size_type find(const T& t, size_type pos = 0) const noexcept; // C++17, noexcept as an extension
    size_type find(const value_type* s, size_type pos, size_type n) const noexcept;
    size_type find(const value_type* s, size_type pos = 0) const noexcept;
    size_type find(value_type c, size_type pos = 0) const noexcept;

    size_type rfind(const basic_string& str, size_type pos = npos) const noexcept;
    template <class T>
        size_type rfind(const T& t, size_type pos = npos) const noexcept; // C++17, noexcept as an extension
    size_type rfind(const value_type* s, size_type pos, size_type n) const noexcept;
    size_type rfind(const value_type* s, size_type pos = npos) const noexcept;
    size_type rfind(value_type c, size_type pos = npos) const noexcept;

    size_type find_first_of(const basic_string& str, size_type pos = 0) const noexcept;
    template <class T>
        size_type find_first_of(const T& t, size_type pos = 0) const noexcept; // C++17, noexcept as an extension
    size_type find_first_of(const value_type* s, size_type pos, size_type n) const noexcept;
    size_type find_first_of(const value_type* s, size_type pos = 0) const noexcept;
    size_type find_first_of(value_type c, size_type pos = 0) const noexcept;

    size_type find_last_of(const basic_string& str, size_type pos = npos) const noexcept;
    template <class T>
        size_type find_last_of(const T& t, size_type pos = npos) const noexcept noexcept; // C++17, noexcept as an extension
    size_type find_last_of(const value_type* s, size_type pos, size_type n) const noexcept;
    size_type find_last_of(const value_type* s, size_type pos = npos) const noexcept;
    size_type find_last_of(value_type c, size_type pos = npos) const noexcept;

    size_type find_first_not_of(const basic_string& str, size_type pos = 0) const noexcept;
    template <class T>
        size_type find_first_not_of(const T& t, size_type pos = 0) const noexcept; // C++17, noexcept as an extension
    size_type find_first_not_of(const value_type* s, size_type pos, size_type n) const noexcept;
    size_type find_first_not_of(const value_type* s, size_type pos = 0) const noexcept;
    size_type find_first_not_of(value_type c, size_type pos = 0) const noexcept;

    size_type find_last_not_of(const basic_string& str, size_type pos = npos) const noexcept;
    template <class T>
        size_type find_last_not_of(const T& t, size_type pos = npos) const noexcept; // C++17, noexcept as an extension
    size_type find_last_not_of(const value_type* s, size_type pos, size_type n) const noexcept;
    size_type find_last_not_of(const value_type* s, size_type pos = npos) const noexcept;
    size_type find_last_not_of(value_type c, size_type pos = npos) const noexcept;

    int compare(const basic_string& str) const noexcept;
    template <class T>
        int compare(const T& t) const noexcept;  // C++17, noexcept as an extension
    int compare(size_type pos1, size_type n1, const basic_string& str) const;
    template <class T>
        int compare(size_type pos1, size_type n1, const T& t) const;  // C++17
    int compare(size_type pos1, size_type n1, const basic_string& str,
                size_type pos2, size_type n2=npos) const; // C++14
    template <class T>
        int compare(size_type pos1, size_type n1, const T& t,
                    size_type pos2, size_type n2=npos) const; // C++17
    int compare(const value_type* s) const noexcept;
    int compare(size_type pos1, size_type n1, const value_type* s) const;
    int compare(size_type pos1, size_type n1, const value_type* s, size_type n2) const;

    bool starts_with(basic_string_view<charT, traits> sv) const noexcept; // C++20
    bool starts_with(charT c) const noexcept;                             // C++20
    bool starts_with(const charT* s) const;                               // C++20
    bool ends_with(basic_string_view<charT, traits> sv) const noexcept;   // C++20
    bool ends_with(charT c) const noexcept;                               // C++20
    bool ends_with(const charT* s) const;                                 // C++20

    constexpr bool contains(basic_string_view<charT, traits> sv) const noexcept; // C++2b
    constexpr bool contains(charT c) const noexcept;                             // C++2b
    constexpr bool contains(const charT* s) const;                               // C++2b

    bool __invariants() const;
};