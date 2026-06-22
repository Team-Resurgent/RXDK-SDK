#pragma once

#if defined(_XBOX)

#include <streambuf>

template <class _Traits>
inline basic_ostream<char, _Traits>& xdk_ostream_insert_cstr(
    basic_ostream<char, _Traits>& _Ostr, const char* _Val) {
    if (!_Val) {
        _Val = "";
    }

    const streamsize _Count = static_cast<streamsize>(_Traits::length(_Val));

    if (!_Ostr.good()) {
        _Ostr.setstate(ios_base::badbit);
        return _Ostr;
    }

    basic_streambuf<char, _Traits>* _Rb = _Ostr.rdbuf();
    if (!_Rb) {
        _Ostr.setstate(ios_base::badbit);
        return _Ostr;
    }

    _Rb->_Lock();

    ios_base::iostate _State = ios_base::goodbit;
    if (_Rb->sputn(_Val, _Count) != _Count) {
        _State |= ios_base::badbit;
    }

    _Rb->_Unlock();

    _Ostr.width(0);
    _Ostr.setstate(_State);
    return _Ostr;
}

template <class _Elem, class _Traits, class _SizeT>
inline basic_ostream<_Elem, _Traits>& xdk_ostream_insert_string(
    basic_ostream<_Elem, _Traits>& _Ostr, const _Elem* const _Data, const _SizeT _Size) {
    if (!_Ostr.good()) {
        _Ostr.setstate(ios_base::badbit);
        return _Ostr;
    }

    basic_streambuf<_Elem, _Traits>* _Rb = _Ostr.rdbuf();
    if (!_Rb || !_Data) {
        _Ostr.setstate(ios_base::badbit);
        return _Ostr;
    }

    _Rb->_Lock();

    ios_base::iostate _State = ios_base::goodbit;
    if (_Rb->sputn(_Data, static_cast<streamsize>(_Size)) != static_cast<streamsize>(_Size)) {
        _State |= ios_base::badbit;
    }

    _Rb->_Unlock();
    _Ostr.width(0);
    _Ostr.setstate(_State);
    return _Ostr;
}

template <class _Elem, class _Traits>
inline basic_ostream<_Elem, _Traits>& xdk_ostream_flush(basic_ostream<_Elem, _Traits>& _Ostr) {
    if (!_Ostr.good()) {
        return _Ostr;
    }

    basic_ostream<_Elem, _Traits>* _Tied = _Ostr.tie();
    if (_Tied && _Tied != &_Ostr) {
        (void)xdk_ostream_flush(*_Tied);
    }

    basic_streambuf<_Elem, _Traits>* _Rb = _Ostr.rdbuf();
    if (!_Rb) {
        _Ostr.setstate(ios_base::badbit);
        return _Ostr;
    }

    _Rb->_Lock();
    if (_Rb->pubsync() == -1) {
        _Ostr.setstate(ios_base::badbit);
    }
    _Rb->_Unlock();

    return _Ostr;
}

template <class _Traits>
inline basic_ostream<char, _Traits>& xdk_ostream_put_char(basic_ostream<char, _Traits>& _Ostr, char _Ch) {
    if (!_Ostr.good()) {
        _Ostr.setstate(ios_base::badbit);
        return _Ostr;
    }

    basic_streambuf<char, _Traits>* _Rb = _Ostr.rdbuf();
    if (!_Rb) {
        _Ostr.setstate(ios_base::badbit);
        return _Ostr;
    }

    _Rb->_Lock();
    if (_Traits::eq_int_type(_Traits::eof(), _Rb->sputc(_Ch))) {
        _Ostr.setstate(ios_base::badbit);
    }
    _Rb->_Unlock();

    return _Ostr;
}

#endif
