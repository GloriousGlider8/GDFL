#include "g1.h"

g1_t::g1_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, g1_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;
    m_avatar_id = 0;
    m_client_id = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void g1_t::_read() {
    m_invalid = m__io->read_bits_int_be(1);
    m_gender = m__io->read_bits_int_be(1);
    m_birth_month = m__io->read_bits_int_be(4);
    m_birth_day = m__io->read_bits_int_be(5);
    m_favorite_color = m__io->read_bits_int_be(4);
    m_favorite = m__io->read_bits_int_be(1);
    m__io->align_to_byte();
    m_mii_name = kaitai::kstream::bytes_to_str(m__io->read_bytes(20), std::string("utf-16be").c_str());
    m_body_height = m__io->read_u1();
    m_body_weight = m__io->read_u1();
    m_avatar_id = new std::vector<uint8_t>();
    const int l_avatar_id = 4;
    for (int i = 0; i < l_avatar_id; i++) {
        m_avatar_id->push_back(m__io->read_u1());
    }
    m_client_id = new std::vector<uint8_t>();
    const int l_client_id = 4;
    for (int i = 0; i < l_client_id; i++) {
        m_client_id->push_back(m__io->read_u1());
    }
    m_face_type = m__io->read_bits_int_be(3);
    m_face_color = m__io->read_bits_int_be(3);
    m_facial_feature = m__io->read_bits_int_be(4);
    m_unknown = m__io->read_bits_int_be(3);
    m_mingle = m__io->read_bits_int_be(1);
    m_unknown_2 = m__io->read_bits_int_be(1);
    m_downloaded = m__io->read_bits_int_be(1);
    m_hair_type = m__io->read_bits_int_be(7);
    m_hair_color = m__io->read_bits_int_be(3);
    m_hair_flip = m__io->read_bits_int_be(1);
    m_unknown_3 = m__io->read_bits_int_be(5);
    m_eyebrow_type = m__io->read_bits_int_be(5);
    m_unknown_4 = m__io->read_bits_int_be(1);
    m_eyebrow_rotation = m__io->read_bits_int_be(4);
    m_unknown_5 = m__io->read_bits_int_be(6);
    m_eyebrow_color = m__io->read_bits_int_be(3);
    m_eyebrow_size = m__io->read_bits_int_be(4);
    m_eyebrow_vertical = m__io->read_bits_int_be(5);
    m_eyebrow_horizontal = m__io->read_bits_int_be(4);
    m_eye_type = m__io->read_bits_int_be(6);
    m_unknown_6 = m__io->read_bits_int_be(2);
    m_eye_rotation = m__io->read_bits_int_be(3);
    m_eye_vertical = m__io->read_bits_int_be(5);
    m_eye_color = m__io->read_bits_int_be(3);
    m_unknown_7 = m__io->read_bits_int_be(1);
    m_eye_size = m__io->read_bits_int_be(3);
    m_eye_horizontal = m__io->read_bits_int_be(4);
    m_unknown_8 = m__io->read_bits_int_be(5);
    m_nose_type = m__io->read_bits_int_be(4);
    m_nose_size = m__io->read_bits_int_be(4);
    m_nose_vertical = m__io->read_bits_int_be(5);
    m_unknown_9 = m__io->read_bits_int_be(3);
    m_mouth_type = m__io->read_bits_int_be(5);
    m_mouth_color = m__io->read_bits_int_be(2);
    m_mouth_size = m__io->read_bits_int_be(4);
    m_mouth_vertical = m__io->read_bits_int_be(5);
    m_glasses_type = m__io->read_bits_int_be(4);
    m_glasses_color = m__io->read_bits_int_be(3);
    m_unknown_10 = m__io->read_bits_int_be(1);
    m_glasses_size = m__io->read_bits_int_be(3);
    m_glasses_vertical = m__io->read_bits_int_be(5);
    m_facial_hair_mustache = m__io->read_bits_int_be(2);
    m_facial_hair_beard = m__io->read_bits_int_be(2);
    m_facial_hair_color = m__io->read_bits_int_be(3);
    m_facial_hair_size = m__io->read_bits_int_be(4);
    m_facial_hair_vertical = m__io->read_bits_int_be(5);
    m_mole_enable = m__io->read_bits_int_be(1);
    m_mole_size = m__io->read_bits_int_be(4);
    m_mole_vertical = m__io->read_bits_int_be(5);
    m_mole_horizontal = m__io->read_bits_int_be(5);
    m_unknown_11 = m__io->read_bits_int_be(1);
    m__io->align_to_byte();
    m_creator_name = kaitai::kstream::bytes_to_str(m__io->read_bytes(20), std::string("utf-16be").c_str());
}

g1_t::~g1_t() {
    _clean_up();
}

void g1_t::_clean_up() {
    if (m_avatar_id) {
        delete m_avatar_id; m_avatar_id = 0;
    }
    if (m_client_id) {
        delete m_client_id; m_client_id = 0;
    }
}
