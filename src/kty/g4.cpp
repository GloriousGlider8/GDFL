// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "g4.h"

g4_t::g4_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, g4_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;
    m_unknown_data = 0;
    m_unknown_buffer = 0;
    m_unknown_buffer2 = 0;
    m_unknown_buffer3 = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void g4_t::_read() {
    m_unknown_data = new std::vector<uint8_t>();
    const int l_unknown_data = 16;
    for (int i = 0; i < l_unknown_data; i++) {
        m_unknown_data->push_back(m__io->read_u1());
    }
    m_mii_name = kaitai::kstream::bytes_to_str(m__io->read_bytes(20), std::string("utf-16le").c_str());
    m_unknown_buffer = new std::vector<uint8_t>();
    const int l_unknown_buffer = 3;
    for (int i = 0; i < l_unknown_buffer; i++) {
        m_unknown_buffer->push_back(m__io->read_u1());
    }
    m_favorite_color = m__io->read_u1();
    m_gender = m__io->read_u1();
    m_body_height = m__io->read_u1();
    m_body_weight = m__io->read_u1();
    m_unknown_buffer2 = new std::vector<uint8_t>();
    const int l_unknown_buffer2 = 2;
    for (int i = 0; i < l_unknown_buffer2; i++) {
        m_unknown_buffer2->push_back(m__io->read_u1());
    }
    m_face_type = m__io->read_u1();
    m_face_color = m__io->read_u1();
    m_face_wrinkles = m__io->read_u1();
    m_face_makeup = m__io->read_u1();
    m_hair_type = m__io->read_u1();
    m_hair_color = m__io->read_u1();
    m_hair_flip = m__io->read_u1();
    m_eye_type = m__io->read_u1();
    m_eye_color = m__io->read_u1();
    m_eye_size = m__io->read_u1();
    m_eye_stretch = m__io->read_u1();
    m_eye_rotation = m__io->read_u1();
    m_eye_horizontal = m__io->read_u1();
    m_eye_vertical = m__io->read_u1();
    m_eyebrow_type = m__io->read_u1();
    m_eyebrow_color = m__io->read_u1();
    m_eyebrow_size = m__io->read_u1();
    m_eyebrow_stretch = m__io->read_u1();
    m_eyebrow_rotation = m__io->read_u1();
    m_eyebrow_horizontal = m__io->read_u1();
    m_eyebrow_vertical = m__io->read_u1();
    m_nose_type = m__io->read_u1();
    m_nose_size = m__io->read_u1();
    m_nose_vertical = m__io->read_u1();
    m_mouth_type = m__io->read_u1();
    m_mouth_color = m__io->read_u1();
    m_mouth_size = m__io->read_u1();
    m_mouth_stretch = m__io->read_u1();
    m_mouth_vertical = m__io->read_u1();
    m_facial_hair_color = m__io->read_u1();
    m_facial_hair_beard = m__io->read_u1();
    m_facial_hair_mustache = m__io->read_u1();
    m_facial_hair_size = m__io->read_u1();
    m_facial_hair_vertical = m__io->read_u1();
    m_glasses_type = m__io->read_u1();
    m_glasses_color = m__io->read_u1();
    m_glasses_size = m__io->read_u1();
    m_glasses_vertical = m__io->read_u1();
    m_mole_enable = m__io->read_u1();
    m_mole_size = m__io->read_u1();
    m_mole_horizontal = m__io->read_u1();
    m_mole_vertical = m__io->read_u1();
    m_unknown_buffer3 = new std::vector<uint8_t>();
    const int l_unknown_buffer3 = 1;
    for (int i = 0; i < l_unknown_buffer3; i++) {
        m_unknown_buffer3->push_back(m__io->read_u1());
    }
}

g4_t::~g4_t() {
    _clean_up();
}

void g4_t::_clean_up() {
    if (m_unknown_data) {
        delete m_unknown_data; m_unknown_data = 0;
    }
    if (m_unknown_buffer) {
        delete m_unknown_buffer; m_unknown_buffer = 0;
    }
    if (m_unknown_buffer2) {
        delete m_unknown_buffer2; m_unknown_buffer2 = 0;
    }
    if (m_unknown_buffer3) {
        delete m_unknown_buffer3; m_unknown_buffer3 = 0;
    }
}
