#pragma once

namespace _std {
    template<typename T>
    struct list {
        int field_0;

        struct node_type {
            node_type *_Next;
            node_type *_Prev;
            T _Myval;
        };

        node_type *m_head;
        uint32_t m_size;

        struct iterator {
            node_type *_Ptr;

            auto &operator*() {
                return (_Ptr->_Myval);
            }

            bool operator==(const iterator &it) const {
                return _Ptr == it._Ptr;
            }

            bool operator!=(const iterator &it) const {
                return _Ptr != it._Ptr;
            }

            void operator++() {
                this->_Ptr = this->_Ptr->_Next;
            }
        };

        auto begin() {
            return iterator {m_head->_Next}; 
        }

        auto end() {
            return iterator {m_head};
        }

    };
}
