// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "drawable.h"

drawable_t::drawable_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, drawable_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;
    m_loc_some = 0;
    m_loc_shader_group = 0;
    m_bounding_sphere_center = 0;
    m_bounding_box_min = 0;
    m_bounding_box_max = 0;
    m_loc_lod_h = 0;
    m_loc_lod_m = 0;
    m_loc_lod_l = 0;
    m_loc_lod_v = 0;
    m_lod_distance = 0;
    m_lod_flags = 0;
    m_loc_name = 0;
    m_lod_h = 0;
    m_lod_v = 0;
    m_lod_m = 0;
    m_shader_group = 0;
    m_lod_l = 0;
    f_lod_h = false;
    f_lod_v = false;
    f_ptr_some = false;
    f_lod_m = false;
    f_name = false;
    f_shader_group = false;
    f_lod_l = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void drawable_t::_read() {
    m_unknown0 = m__io->read_bytes(8);
    m_loc_some = new ptr_t(m__io, this, m__root);
    m_loc_shader_group = new ptr_t(m__io, this, m__root);
    m_unknown1 = m__io->read_bytes(8);
    m_bounding_sphere_center = new xyz_t(m__io, this, m__root);
    m_bounding_sphere_radius = m__io->read_f4le();
    m_bounding_box_min = new xyz_t(m__io, this, m__root);
    m_unknown2 = m__io->read_bytes(4);
    m_bounding_box_max = new xyz_t(m__io, this, m__root);
    m_unknown3 = m__io->read_bytes(4);
    m_loc_lod_h = new ptr_t(m__io, this, m__root);
    m_loc_lod_m = new ptr_t(m__io, this, m__root);
    m_loc_lod_l = new ptr_t(m__io, this, m__root);
    m_loc_lod_v = new ptr_t(m__io, this, m__root);
    m_lod_distance = new std::vector<uint32_t>();
    const int l_lod_distance = 4;
    for (int i = 0; i < l_lod_distance; i++) {
        m_lod_distance->push_back(m__io->read_u4le());
    }
    m_lod_flags = new std::vector<uint32_t>();
    const int l_lod_flags = 4;
    for (int i = 0; i < l_lod_flags; i++) {
        m_lod_flags->push_back(m__io->read_u4le());
    }
    m_unknown4 = m__io->read_bytes(24);
    m_loc_name = new ptr_t(m__io, this, m__root);
    m_unknown5 = m__io->read_bytes(32);
}

drawable_t::~drawable_t() {
    _clean_up();
}

void drawable_t::_clean_up() {
    if (m_loc_some) {
        delete m_loc_some; m_loc_some = 0;
    }
    if (m_loc_shader_group) {
        delete m_loc_shader_group; m_loc_shader_group = 0;
    }
    if (m_bounding_sphere_center) {
        delete m_bounding_sphere_center; m_bounding_sphere_center = 0;
    }
    if (m_bounding_box_min) {
        delete m_bounding_box_min; m_bounding_box_min = 0;
    }
    if (m_bounding_box_max) {
        delete m_bounding_box_max; m_bounding_box_max = 0;
    }
    if (m_loc_lod_h) {
        delete m_loc_lod_h; m_loc_lod_h = 0;
    }
    if (m_loc_lod_m) {
        delete m_loc_lod_m; m_loc_lod_m = 0;
    }
    if (m_loc_lod_l) {
        delete m_loc_lod_l; m_loc_lod_l = 0;
    }
    if (m_loc_lod_v) {
        delete m_loc_lod_v; m_loc_lod_v = 0;
    }
    if (m_lod_distance) {
        delete m_lod_distance; m_lod_distance = 0;
    }
    if (m_lod_flags) {
        delete m_lod_flags; m_lod_flags = 0;
    }
    if (m_loc_name) {
        delete m_loc_name; m_loc_name = 0;
    }
    if (f_lod_h && !n_lod_h) {
        if (m_lod_h) {
            delete m_lod_h; m_lod_h = 0;
        }
    }
    if (f_lod_v && !n_lod_v) {
        if (m_lod_v) {
            delete m_lod_v; m_lod_v = 0;
        }
    }
    if (f_ptr_some) {
    }
    if (f_lod_m && !n_lod_m) {
        if (m_lod_m) {
            delete m_lod_m; m_lod_m = 0;
        }
    }
    if (f_name) {
    }
    if (f_shader_group) {
        if (m_shader_group) {
            delete m_shader_group; m_shader_group = 0;
        }
    }
    if (f_lod_l && !n_lod_l) {
        if (m_lod_l) {
            delete m_lod_l; m_lod_l = 0;
        }
    }
}

drawable_t::embedded_t::embedded_t(kaitai::kstream* p__io, drawable_t::texture_dict_t* p__parent, drawable_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void drawable_t::embedded_t::_read() {
    m_unk = m__io->read_u4le();
    m_unk0 = m__io->read_bytes(16);
}

drawable_t::embedded_t::~embedded_t() {
    _clean_up();
}

void drawable_t::embedded_t::_clean_up() {
}

drawable_t::uv_t::uv_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, drawable_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void drawable_t::uv_t::_read() {
    m_u = m__io->read_f4le();
    m_v = m__io->read_f4le();
}

drawable_t::uv_t::~uv_t() {
    _clean_up();
}

void drawable_t::uv_t::_clean_up() {
}

drawable_t::vertex_t::vertex_t(int32_t p_i, kaitai::kstream* p__io, drawable_t::vertex_data_t* p__parent, drawable_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_i = p_i;
    m__io__raw_data = 0;
    f_type = false;
    f_data = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void drawable_t::vertex_t::_read() {
}

drawable_t::vertex_t::~vertex_t() {
    _clean_up();
}

void drawable_t::vertex_t::_clean_up() {
    if (f_data && !n_data) {
        if (m__io__raw_data) {
            delete m__io__raw_data; m__io__raw_data = 0;
        }
        if (m_data) {
            delete m_data; m_data = 0;
        }
    }
}

drawable_t::vertex_layout_type_t drawable_t::vertex_t::type() {
    if (f_type)
        return m_type;
    m_type = _parent()->vertex_layout()->type()->at(i());
    f_type = true;
    return m_type;
}

kaitai::kstruct* drawable_t::vertex_t::data() {
    if (f_data)
        return m_data;
    n_data = true;
    if (_parent()->vertex_layout()->size()->at(i()) != 0) {
        n_data = false;
        std::streampos _pos = m__io->pos();
        m__io->seek((_parent()->loc_vertecies()->addr() + _parent()->vertex_layout()->offsets()->at(i())));
        n_data = true;
        switch (type()) {
        case drawable_t::VERTEX_LAYOUT_TYPE_TEXTURE: {
            n_data = false;
            m__raw_data = m__io->read_bytes((_parent()->vertex_layout()->size()->at(i()) * _parent()->vertex_count()));
            m__io__raw_data = new kaitai::kstream(m__raw_data);
            m_data = new float_list_t(m__io__raw_data, this, m__root);
            break;
        }
        case drawable_t::VERTEX_LAYOUT_TYPE_NORMAL: {
            n_data = false;
            m__raw_data = m__io->read_bytes((_parent()->vertex_layout()->size()->at(i()) * _parent()->vertex_count()));
            m__io__raw_data = new kaitai::kstream(m__raw_data);
            m_data = new normal_list_t(m__io__raw_data, this, m__root);
            break;
        }
        case drawable_t::VERTEX_LAYOUT_TYPE_POSITION: {
            n_data = false;
            m__raw_data = m__io->read_bytes((_parent()->vertex_layout()->size()->at(i()) * _parent()->vertex_count()));
            m__io__raw_data = new kaitai::kstream(m__raw_data);
            m_data = new float_list_t(m__io__raw_data, this, m__root);
            break;
        }
        case drawable_t::VERTEX_LAYOUT_TYPE_COLOR: {
            n_data = false;
            m__raw_data = m__io->read_bytes((_parent()->vertex_layout()->size()->at(i()) * _parent()->vertex_count()));
            m__io__raw_data = new kaitai::kstream(m__raw_data);
            m_data = new byte_list_t(m__io__raw_data, this, m__root);
            break;
        }
        default: {
            m__raw_data = m__io->read_bytes((_parent()->vertex_layout()->size()->at(i()) * _parent()->vertex_count()));
            break;
        }
        }
        m__io->seek(_pos);
        f_data = true;
    }
    return m_data;
}

drawable_t::float_list_t::float_list_t(kaitai::kstream* p__io, drawable_t::vertex_t* p__parent, drawable_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_data = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void drawable_t::float_list_t::_read() {
    m_data = new std::vector<float>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_data->push_back(m__io->read_f4le());
            i++;
        }
    }
}

drawable_t::float_list_t::~float_list_t() {
    _clean_up();
}

void drawable_t::float_list_t::_clean_up() {
    if (m_data) {
        delete m_data; m_data = 0;
    }
}

drawable_t::model_t::model_t(kaitai::kstream* p__io, drawable_t::model_ptr_t* p__parent, drawable_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_loc_geometry_list = 0;
    m_loc_bounds_list = 0;
    m_loc_shader_id = 0;
    m_geometry_list = 0;
    m_bounds_list = 0;
    m_shader_id = 0;
    f_bound_count = false;
    f_geometry_list = false;
    f_bounds_list = false;
    f_shader_id = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void drawable_t::model_t::_read() {
    m_unk0 = m__io->read_bytes(8);
    m_loc_geometry_list = new ptr_t(m__io, this, m__root);
    m_geometry_count = m__io->read_u2le();
    m_bound_count_raw = m__io->read_u2le();
    m_unk1 = m__io->read_bytes(4);
    m_loc_bounds_list = new ptr_t(m__io, this, m__root);
    m_loc_shader_id = new ptr_t(m__io, this, m__root);
    m_unk2 = m__io->read_bytes(24);
}

drawable_t::model_t::~model_t() {
    _clean_up();
}

void drawable_t::model_t::_clean_up() {
    if (m_loc_geometry_list) {
        delete m_loc_geometry_list; m_loc_geometry_list = 0;
    }
    if (m_loc_bounds_list) {
        delete m_loc_bounds_list; m_loc_bounds_list = 0;
    }
    if (m_loc_shader_id) {
        delete m_loc_shader_id; m_loc_shader_id = 0;
    }
    if (f_geometry_list) {
        if (m_geometry_list) {
            for (std::vector<geometry_ptr_t*>::iterator it = m_geometry_list->begin(); it != m_geometry_list->end(); ++it) {
                delete *it;
            }
            delete m_geometry_list; m_geometry_list = 0;
        }
    }
    if (f_bounds_list) {
        if (m_bounds_list) {
            for (std::vector<bounds_t*>::iterator it = m_bounds_list->begin(); it != m_bounds_list->end(); ++it) {
                delete *it;
            }
            delete m_bounds_list; m_bounds_list = 0;
        }
    }
    if (f_shader_id) {
        if (m_shader_id) {
            delete m_shader_id; m_shader_id = 0;
        }
    }
}

int32_t drawable_t::model_t::bound_count() {
    if (f_bound_count)
        return m_bound_count;
    m_bound_count = ((bound_count_raw() == 1) ? (bound_count_raw()) : ((bound_count_raw() + 1)));
    f_bound_count = true;
    return m_bound_count;
}

std::vector<drawable_t::geometry_ptr_t*>* drawable_t::model_t::geometry_list() {
    if (f_geometry_list)
        return m_geometry_list;
    std::streampos _pos = m__io->pos();
    m__io->seek(loc_geometry_list()->addr());
    m_geometry_list = new std::vector<geometry_ptr_t*>();
    const int l_geometry_list = geometry_count();
    for (int i = 0; i < l_geometry_list; i++) {
        m_geometry_list->push_back(new geometry_ptr_t(m__io, this, m__root));
    }
    m__io->seek(_pos);
    f_geometry_list = true;
    return m_geometry_list;
}

std::vector<drawable_t::bounds_t*>* drawable_t::model_t::bounds_list() {
    if (f_bounds_list)
        return m_bounds_list;
    std::streampos _pos = m__io->pos();
    m__io->seek(loc_bounds_list()->addr());
    m_bounds_list = new std::vector<bounds_t*>();
    const int l_bounds_list = bound_count();
    for (int i = 0; i < l_bounds_list; i++) {
        m_bounds_list->push_back(new bounds_t(m__io, this, m__root));
    }
    m__io->seek(_pos);
    f_bounds_list = true;
    return m_bounds_list;
}

std::vector<uint16_t>* drawable_t::model_t::shader_id() {
    if (f_shader_id)
        return m_shader_id;
    std::streampos _pos = m__io->pos();
    m__io->seek(loc_shader_id()->addr());
    m_shader_id = new std::vector<uint16_t>();
    const int l_shader_id = geometry_count();
    for (int i = 0; i < l_shader_id; i++) {
        m_shader_id->push_back(m__io->read_u2le());
    }
    m__io->seek(_pos);
    f_shader_id = true;
    return m_shader_id;
}

drawable_t::shader_list_t::shader_list_t(kaitai::kstream* p__io, drawable_t::shader_group_t* p__parent, drawable_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_loc_shader = 0;
    m_shader = 0;
    f_shader = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void drawable_t::shader_list_t::_read() {
    m_loc_shader = new ptr_t(m__io, this, m__root);
}

drawable_t::shader_list_t::~shader_list_t() {
    _clean_up();
}

void drawable_t::shader_list_t::_clean_up() {
    if (m_loc_shader) {
        delete m_loc_shader; m_loc_shader = 0;
    }
    if (f_shader) {
        if (m_shader) {
            delete m_shader; m_shader = 0;
        }
    }
}

drawable_t::shader_t* drawable_t::shader_list_t::shader() {
    if (f_shader)
        return m_shader;
    std::streampos _pos = m__io->pos();
    m__io->seek(loc_shader()->addr());
    m_shader = new shader_t(m__io, this, m__root);
    m__io->seek(_pos);
    f_shader = true;
    return m_shader;
}

drawable_t::rgba_t::rgba_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, drawable_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void drawable_t::rgba_t::_read() {
    m_r = m__io->read_u1();
    m_g = m__io->read_u1();
    m_b = m__io->read_u1();
    m_a = m__io->read_u1();
}

drawable_t::rgba_t::~rgba_t() {
    _clean_up();
}

void drawable_t::rgba_t::_clean_up() {
}

drawable_t::vertex_data_t::vertex_data_t(kaitai::kstream* p__io, drawable_t::geometry_t* p__parent, drawable_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_loc_vertecies = 0;
    m_unknown_ptr = 0;
    m_loc_vertex_layout = 0;
    m_vertex_layout = 0;
    m_verticies = 0;
    f_unknown_seq0 = false;
    f_vertex_layout = false;
    f_verticies = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void drawable_t::vertex_data_t::_read() {
    m_unk0 = m__io->read_bytes(8);
    m_vertex_count = m__io->read_u4le();
    m_unk1 = m__io->read_bytes(12);
    m_loc_vertecies = new ptr_t(m__io, this, m__root);
    m_unk2 = m__io->read_bytes(16);
    m_unknown_ptr = new ptr_t(m__io, this, m__root);
    m_loc_vertex_layout = new ptr_t(m__io, this, m__root);
}

drawable_t::vertex_data_t::~vertex_data_t() {
    _clean_up();
}

void drawable_t::vertex_data_t::_clean_up() {
    if (m_loc_vertecies) {
        delete m_loc_vertecies; m_loc_vertecies = 0;
    }
    if (m_unknown_ptr) {
        delete m_unknown_ptr; m_unknown_ptr = 0;
    }
    if (m_loc_vertex_layout) {
        delete m_loc_vertex_layout; m_loc_vertex_layout = 0;
    }
    if (f_unknown_seq0) {
    }
    if (f_vertex_layout) {
        if (m_vertex_layout) {
            delete m_vertex_layout; m_vertex_layout = 0;
        }
    }
    if (f_verticies) {
        if (m_verticies) {
            for (std::vector<vertex_t*>::iterator it = m_verticies->begin(); it != m_verticies->end(); ++it) {
                delete *it;
            }
            delete m_verticies; m_verticies = 0;
        }
    }
}

std::string drawable_t::vertex_data_t::unknown_seq0() {
    if (f_unknown_seq0)
        return m_unknown_seq0;
    std::streampos _pos = m__io->pos();
    m__io->seek(unknown_ptr()->addr());
    m_unknown_seq0 = m__io->read_bytes(64);
    m__io->seek(_pos);
    f_unknown_seq0 = true;
    return m_unknown_seq0;
}

drawable_t::vertex_layout_t* drawable_t::vertex_data_t::vertex_layout() {
    if (f_vertex_layout)
        return m_vertex_layout;
    std::streampos _pos = m__io->pos();
    m__io->seek(loc_vertex_layout()->addr());
    m_vertex_layout = new vertex_layout_t(m__io, this, m__root);
    m__io->seek(_pos);
    f_vertex_layout = true;
    return m_vertex_layout;
}

std::vector<drawable_t::vertex_t*>* drawable_t::vertex_data_t::verticies() {
    if (f_verticies)
        return m_verticies;
    m_verticies = new std::vector<vertex_t*>();
    const int l_verticies = 52;
    for (int i = 0; i < l_verticies; i++) {
        m_verticies->push_back(new vertex_t(i, m__io, this, m__root));
    }
    f_verticies = true;
    return m_verticies;
}

drawable_t::c_buffer_data_t::c_buffer_data_t(kaitai::kstream* p__io, drawable_t::texture_info_t* p__parent, drawable_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_hash = 0;
    m_loc_data = 0;
    m_data = 0;
    f_loc_data = false;
    f_data = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void drawable_t::c_buffer_data_t::_read() {
    m_hash = new hash_t(m__io, this, m__root);
    m_flags = m__io->read_bits_int_le(2);
    m_buffer_id = m__io->read_bits_int_le(6);
    m_offset = m__io->read_bits_int_le(12);
    m_length = m__io->read_bits_int_le(12);
}

drawable_t::c_buffer_data_t::~c_buffer_data_t() {
    _clean_up();
}

void drawable_t::c_buffer_data_t::_clean_up() {
    if (m_hash) {
        delete m_hash; m_hash = 0;
    }
    if (f_loc_data) {
        if (m_loc_data) {
            delete m_loc_data; m_loc_data = 0;
        }
    }
    if (f_data) {
        if (m_data) {
            delete m_data; m_data = 0;
        }
    }
}

drawable_t::ptr_t* drawable_t::c_buffer_data_t::loc_data() {
    if (f_loc_data)
        return m_loc_data;
    std::streampos _pos = m__io->pos();
    m__io->seek((_parent()->_parent()->loc_c_buffer()->addr() + (buffer_id() * 8)));
    m_loc_data = new ptr_t(m__io, this, m__root);
    m__io->seek(_pos);
    f_loc_data = true;
    return m_loc_data;
}

std::vector<float>* drawable_t::c_buffer_data_t::data() {
    if (f_data)
        return m_data;
    std::streampos _pos = m__io->pos();
    m__io->seek((loc_data()->addr() + offset()));
    m_data = new std::vector<float>();
    const int l_data = (length() / 4);
    for (int i = 0; i < l_data; i++) {
        m_data->push_back(m__io->read_f4le());
    }
    m__io->seek(_pos);
    f_data = true;
    return m_data;
}

drawable_t::normal_list_t::normal_list_t(kaitai::kstream* p__io, drawable_t::vertex_t* p__parent, drawable_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_data = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void drawable_t::normal_list_t::_read() {
    m_data = new std::vector<normals_t*>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_data->push_back(new normals_t(m__io, this, m__root));
            i++;
        }
    }
}

drawable_t::normal_list_t::~normal_list_t() {
    _clean_up();
}

void drawable_t::normal_list_t::_clean_up() {
    if (m_data) {
        for (std::vector<normals_t*>::iterator it = m_data->begin(); it != m_data->end(); ++it) {
            delete *it;
        }
        delete m_data; m_data = 0;
    }
}

drawable_t::vertex_layout_t::vertex_layout_t(kaitai::kstream* p__io, drawable_t::vertex_data_t* p__parent, drawable_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_offsets = 0;
    m_size = 0;
    m_type = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void drawable_t::vertex_layout_t::_read() {
    m_offsets = new std::vector<uint32_t>();
    const int l_offsets = 52;
    for (int i = 0; i < l_offsets; i++) {
        m_offsets->push_back(m__io->read_u4le());
    }
    m_size = new std::vector<uint8_t>();
    const int l_size = 52;
    for (int i = 0; i < l_size; i++) {
        m_size->push_back(m__io->read_u1());
    }
    m_type = new std::vector<vertex_layout_type_t>();
    const int l_type = 52;
    for (int i = 0; i < l_type; i++) {
        m_type->push_back(static_cast<drawable_t::vertex_layout_type_t>(m__io->read_u1()));
    }
    m_unk0 = m__io->read_bytes(8);
}

drawable_t::vertex_layout_t::~vertex_layout_t() {
    _clean_up();
}

void drawable_t::vertex_layout_t::_clean_up() {
    if (m_offsets) {
        delete m_offsets; m_offsets = 0;
    }
    if (m_size) {
        delete m_size; m_size = 0;
    }
    if (m_type) {
        delete m_type; m_type = 0;
    }
}

drawable_t::bounds_t::bounds_t(kaitai::kstream* p__io, drawable_t::model_t* p__parent, drawable_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_bb_min = 0;
    m_bb_max = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void drawable_t::bounds_t::_read() {
    m_bb_min = new xyz_t(m__io, this, m__root);
    m_unk0 = m__io->read_bytes(4);
    m_bb_max = new xyz_t(m__io, this, m__root);
    m_unk1 = m__io->read_bytes(4);
}

drawable_t::bounds_t::~bounds_t() {
    _clean_up();
}

void drawable_t::bounds_t::_clean_up() {
    if (m_bb_min) {
        delete m_bb_min; m_bb_min = 0;
    }
    if (m_bb_max) {
        delete m_bb_max; m_bb_max = 0;
    }
}

drawable_t::hash_t::hash_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, drawable_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void drawable_t::hash_t::_read() {
    m_hash_value = static_cast<drawable_t::hash_value_t>(m__io->read_u4le());
}

drawable_t::hash_t::~hash_t() {
    _clean_up();
}

void drawable_t::hash_t::_clean_up() {
}

drawable_t::shader_group_t::shader_group_t(kaitai::kstream* p__io, drawable_t* p__parent, drawable_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_loc_texture_dict = 0;
    m_loc_shader_list = 0;
    m_texture_dict = 0;
    m_shader_list = 0;
    f_texture_dict = false;
    f_shader_list = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void drawable_t::shader_group_t::_read() {
    m_unk0 = m__io->read_bytes(8);
    m_loc_texture_dict = new ptr_t(m__io, this, m__root);
    m_loc_shader_list = new ptr_t(m__io, this, m__root);
    m_shader_count = m__io->read_u2le();
    m_count_0 = m__io->read_u2le();
    m_unk1 = m__io->read_bytes(36);
}

drawable_t::shader_group_t::~shader_group_t() {
    _clean_up();
}

void drawable_t::shader_group_t::_clean_up() {
    if (m_loc_texture_dict) {
        delete m_loc_texture_dict; m_loc_texture_dict = 0;
    }
    if (m_loc_shader_list) {
        delete m_loc_shader_list; m_loc_shader_list = 0;
    }
    if (f_texture_dict && !n_texture_dict) {
        if (m_texture_dict) {
            delete m_texture_dict; m_texture_dict = 0;
        }
    }
    if (f_shader_list) {
        if (m_shader_list) {
            for (std::vector<shader_list_t*>::iterator it = m_shader_list->begin(); it != m_shader_list->end(); ++it) {
                delete *it;
            }
            delete m_shader_list; m_shader_list = 0;
        }
    }
}

drawable_t::texture_dict_t* drawable_t::shader_group_t::texture_dict() {
    if (f_texture_dict)
        return m_texture_dict;
    n_texture_dict = true;
    if (loc_texture_dict()->addr() != 0) {
        n_texture_dict = false;
        std::streampos _pos = m__io->pos();
        m__io->seek(loc_texture_dict()->addr());
        m_texture_dict = new texture_dict_t(m__io, this, m__root);
        m__io->seek(_pos);
        f_texture_dict = true;
    }
    return m_texture_dict;
}

std::vector<drawable_t::shader_list_t*>* drawable_t::shader_group_t::shader_list() {
    if (f_shader_list)
        return m_shader_list;
    std::streampos _pos = m__io->pos();
    m__io->seek(loc_shader_list()->addr());
    m_shader_list = new std::vector<shader_list_t*>();
    const int l_shader_list = shader_count();
    for (int i = 0; i < l_shader_list; i++) {
        m_shader_list->push_back(new shader_list_t(m__io, this, m__root));
    }
    m__io->seek(_pos);
    f_shader_list = true;
    return m_shader_list;
}

drawable_t::normals_t::normals_t(kaitai::kstream* p__io, drawable_t::normal_list_t* p__parent, drawable_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    f_x = false;
    f_y = false;
    f_y_real = false;
    f_x_real = false;
    f_z = false;
    f_z_real = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void drawable_t::normals_t::_read() {
    m_x_raw = m__io->read_bits_int_le(10);
    m_y_raw = m__io->read_bits_int_le(10);
    m_z_raw = m__io->read_bits_int_le(10);
    m_w = m__io->read_bits_int_le(2);
}

drawable_t::normals_t::~normals_t() {
    _clean_up();
}

void drawable_t::normals_t::_clean_up() {
}

double drawable_t::normals_t::x() {
    if (f_x)
        return m_x;
    m_x = (static_cast<float>(((x_raw() >= 512) ? ((x_raw() - 512)) : ((x_raw() - 511)))) / 511);
    f_x = true;
    return m_x;
}

double drawable_t::normals_t::y() {
    if (f_y)
        return m_y;
    m_y = (static_cast<float>(((y_raw() >= 512) ? ((y_raw() - 512)) : ((y_raw() - 511)))) / 511);
    f_y = true;
    return m_y;
}

double drawable_t::normals_t::y_real() {
    if (f_y_real)
        return m_y_real;
    m_y_real = (static_cast<float>(((y_raw() >= 512) ? ((y_raw() - 1024)) : (y_raw()))) / 511);
    f_y_real = true;
    return m_y_real;
}

double drawable_t::normals_t::x_real() {
    if (f_x_real)
        return m_x_real;
    m_x_real = (static_cast<float>(((x_raw() >= 512) ? ((x_raw() - 1024)) : (x_raw()))) / 511);
    f_x_real = true;
    return m_x_real;
}

double drawable_t::normals_t::z() {
    if (f_z)
        return m_z;
    m_z = (static_cast<float>(((z_raw() >= 512) ? ((z_raw() - 512)) : ((z_raw() - 511)))) / 511);
    f_z = true;
    return m_z;
}

double drawable_t::normals_t::z_real() {
    if (f_z_real)
        return m_z_real;
    m_z_real = (static_cast<float>(((z_raw() >= 512) ? ((z_raw() - 1024)) : (z_raw()))) / 511);
    f_z_real = true;
    return m_z_real;
}

drawable_t::xyz_t::xyz_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, drawable_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void drawable_t::xyz_t::_read() {
    m_x = m__io->read_f4le();
    m_y = m__io->read_f4le();
    m_z = m__io->read_f4le();
}

drawable_t::xyz_t::~xyz_t() {
    _clean_up();
}

void drawable_t::xyz_t::_clean_up() {
}

drawable_t::model_ptr_t::model_ptr_t(kaitai::kstream* p__io, drawable_t::models_t* p__parent, drawable_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_loc_model = 0;
    m_model = 0;
    f_model = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void drawable_t::model_ptr_t::_read() {
    m_loc_model = new ptr_t(m__io, this, m__root);
}

drawable_t::model_ptr_t::~model_ptr_t() {
    _clean_up();
}

void drawable_t::model_ptr_t::_clean_up() {
    if (m_loc_model) {
        delete m_loc_model; m_loc_model = 0;
    }
    if (f_model) {
        if (m_model) {
            delete m_model; m_model = 0;
        }
    }
}

drawable_t::model_t* drawable_t::model_ptr_t::model() {
    if (f_model)
        return m_model;
    std::streampos _pos = m__io->pos();
    m__io->seek(loc_model()->addr());
    m_model = new model_t(m__io, this, m__root);
    m__io->seek(_pos);
    f_model = true;
    return m_model;
}

drawable_t::models_t::models_t(kaitai::kstream* p__io, drawable_t* p__parent, drawable_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_loc_model_list = 0;
    m_model_list = 0;
    f_model_list = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void drawable_t::models_t::_read() {
    m_loc_model_list = new ptr_t(m__io, this, m__root);
    m_model_count = m__io->read_u2le();
    m_count_0 = m__io->read_u2le();
    m_unk0 = m__io->read_bytes(4);
}

drawable_t::models_t::~models_t() {
    _clean_up();
}

void drawable_t::models_t::_clean_up() {
    if (m_loc_model_list) {
        delete m_loc_model_list; m_loc_model_list = 0;
    }
    if (f_model_list) {
        if (m_model_list) {
            for (std::vector<model_ptr_t*>::iterator it = m_model_list->begin(); it != m_model_list->end(); ++it) {
                delete *it;
            }
            delete m_model_list; m_model_list = 0;
        }
    }
}

std::vector<drawable_t::model_ptr_t*>* drawable_t::models_t::model_list() {
    if (f_model_list)
        return m_model_list;
    std::streampos _pos = m__io->pos();
    m__io->seek(loc_model_list()->addr());
    m_model_list = new std::vector<model_ptr_t*>();
    const int l_model_list = model_count();
    for (int i = 0; i < l_model_list; i++) {
        m_model_list->push_back(new model_ptr_t(m__io, this, m__root));
    }
    m__io->seek(_pos);
    f_model_list = true;
    return m_model_list;
}

drawable_t::texture_info_t::texture_info_t(kaitai::kstream* p__io, drawable_t::shader_t* p__parent, drawable_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_texture_data = 0;
    m_sampler_data = 0;
    m_c_buffer_data = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void drawable_t::texture_info_t::_read() {
    m_unk0 = m__io->read_u1();
    m_texture_count = m__io->read_u1();
    m_unk1 = m__io->read_u1();
    m_sampler_count = m__io->read_u1();
    m_all_count = m__io->read_u4le();
    m_texture_data = new std::vector<texture_data_t*>();
    const int l_texture_data = texture_count();
    for (int i = 0; i < l_texture_data; i++) {
        m_texture_data->push_back(new texture_data_t(m__io, this, m__root));
    }
    m_sampler_data = new std::vector<sampler_data_t*>();
    const int l_sampler_data = sampler_count();
    for (int i = 0; i < l_sampler_data; i++) {
        m_sampler_data->push_back(new sampler_data_t(i, m__io, this, m__root));
    }
    m_c_buffer_data = new std::vector<c_buffer_data_t*>();
    const int l_c_buffer_data = ((all_count() - texture_count()) - sampler_count());
    for (int i = 0; i < l_c_buffer_data; i++) {
        m_c_buffer_data->push_back(new c_buffer_data_t(m__io, this, m__root));
    }
}

drawable_t::texture_info_t::~texture_info_t() {
    _clean_up();
}

void drawable_t::texture_info_t::_clean_up() {
    if (m_texture_data) {
        for (std::vector<texture_data_t*>::iterator it = m_texture_data->begin(); it != m_texture_data->end(); ++it) {
            delete *it;
        }
        delete m_texture_data; m_texture_data = 0;
    }
    if (m_sampler_data) {
        for (std::vector<sampler_data_t*>::iterator it = m_sampler_data->begin(); it != m_sampler_data->end(); ++it) {
            delete *it;
        }
        delete m_sampler_data; m_sampler_data = 0;
    }
    if (m_c_buffer_data) {
        for (std::vector<c_buffer_data_t*>::iterator it = m_c_buffer_data->begin(); it != m_c_buffer_data->end(); ++it) {
            delete *it;
        }
        delete m_c_buffer_data; m_c_buffer_data = 0;
    }
}

drawable_t::texture_dict_t::texture_dict_t(kaitai::kstream* p__io, drawable_t::shader_group_t* p__parent, drawable_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_loc_embedded = 0;
    m_loc_textures = 0;
    m_embedded = 0;
    m_textures = 0;
    f_embedded = false;
    f_textures = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void drawable_t::texture_dict_t::_read() {
    m_unk0 = m__io->read_bytes(32);
    m_loc_embedded = new ptr_t(m__io, this, m__root);
    m_count_0 = m__io->read_u2le();
    m_count_1 = m__io->read_u2le();
    m_unk1 = m__io->read_bytes(4);
    m_loc_textures = new ptr_t(m__io, this, m__root);
    m_texture_count = m__io->read_u2le();
    m_count_3 = m__io->read_u2le();
}

drawable_t::texture_dict_t::~texture_dict_t() {
    _clean_up();
}

void drawable_t::texture_dict_t::_clean_up() {
    if (m_loc_embedded) {
        delete m_loc_embedded; m_loc_embedded = 0;
    }
    if (m_loc_textures) {
        delete m_loc_textures; m_loc_textures = 0;
    }
    if (f_embedded && !n_embedded) {
        if (m_embedded) {
            delete m_embedded; m_embedded = 0;
        }
    }
    if (f_textures && !n_textures) {
        if (m_textures) {
            for (std::vector<textures_t*>::iterator it = m_textures->begin(); it != m_textures->end(); ++it) {
                delete *it;
            }
            delete m_textures; m_textures = 0;
        }
    }
}

drawable_t::embedded_t* drawable_t::texture_dict_t::embedded() {
    if (f_embedded)
        return m_embedded;
    n_embedded = true;
    if (loc_embedded()->addr() != 0) {
        n_embedded = false;
        std::streampos _pos = m__io->pos();
        m__io->seek(loc_embedded()->addr());
        m_embedded = new embedded_t(m__io, this, m__root);
        m__io->seek(_pos);
        f_embedded = true;
    }
    return m_embedded;
}

std::vector<drawable_t::textures_t*>* drawable_t::texture_dict_t::textures() {
    if (f_textures)
        return m_textures;
    n_textures = true;
    if (loc_textures()->addr() != 0) {
        n_textures = false;
        std::streampos _pos = m__io->pos();
        m__io->seek(loc_textures()->addr());
        m_textures = new std::vector<textures_t*>();
        const int l_textures = texture_count();
        for (int i = 0; i < l_textures; i++) {
            m_textures->push_back(new textures_t(m__io, this, m__root));
        }
        m__io->seek(_pos);
        f_textures = true;
    }
    return m_textures;
}

drawable_t::shader_t::shader_t(kaitai::kstream* p__io, drawable_t::shader_list_t* p__parent, drawable_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_shader_type = 0;
    m_loc_c_buffer = 0;
    m_loc_textures = 0;
    m_loc_sampler = 0;
    m_texture_info = 0;
    f_texture_info = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void drawable_t::shader_t::_read() {
    m_shader_type = new hash_t(m__io, this, m__root);
    m_unk0 = m__io->read_bytes(4);
    m_loc_c_buffer = new ptr_t(m__io, this, m__root);
    m_loc_textures = new ptr_t(m__io, this, m__root);
    m_unk1 = m__io->read_bytes(8);
    m_loc_sampler = new ptr_t(m__io, this, m__root);
    m_unk2 = m__io->read_bytes(16);
    m_unk3 = m__io->read_bytes(8);
}

drawable_t::shader_t::~shader_t() {
    _clean_up();
}

void drawable_t::shader_t::_clean_up() {
    if (m_shader_type) {
        delete m_shader_type; m_shader_type = 0;
    }
    if (m_loc_c_buffer) {
        delete m_loc_c_buffer; m_loc_c_buffer = 0;
    }
    if (m_loc_textures) {
        delete m_loc_textures; m_loc_textures = 0;
    }
    if (m_loc_sampler) {
        delete m_loc_sampler; m_loc_sampler = 0;
    }
    if (f_texture_info) {
        if (m_texture_info) {
            delete m_texture_info; m_texture_info = 0;
        }
    }
}

drawable_t::texture_info_t* drawable_t::shader_t::texture_info() {
    if (f_texture_info)
        return m_texture_info;
    std::streampos _pos = m__io->pos();
    m__io->seek(loc_sampler()->addr());
    m_texture_info = new texture_info_t(m__io, this, m__root);
    m__io->seek(_pos);
    f_texture_info = true;
    return m_texture_info;
}

drawable_t::ptr_t::ptr_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, drawable_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    f_addr = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void drawable_t::ptr_t::_read() {
    m_byte0 = m__io->read_u1();
    m_byte1 = m__io->read_u1();
    m_byte2 = m__io->read_u1();
    m_byte0x50 = m__io->read_u1();
    m_reserved = m__io->read_u4le();
}

drawable_t::ptr_t::~ptr_t() {
    _clean_up();
}

void drawable_t::ptr_t::_clean_up() {
}

int32_t drawable_t::ptr_t::addr() {
    if (f_addr)
        return m_addr;
    m_addr = ((byte0() + (byte1() << 8)) + (byte2() << 16));
    f_addr = true;
    return m_addr;
}

drawable_t::textures_t::textures_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, drawable_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_loc_texture = 0;
    m_texture = 0;
    f_texture = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void drawable_t::textures_t::_read() {
    m_loc_texture = new ptr_t(m__io, this, m__root);
}

drawable_t::textures_t::~textures_t() {
    _clean_up();
}

void drawable_t::textures_t::_clean_up() {
    if (m_loc_texture) {
        delete m_loc_texture; m_loc_texture = 0;
    }
    if (f_texture && !n_texture) {
        if (m_texture) {
            delete m_texture; m_texture = 0;
        }
    }
}

drawable_t::texture_t* drawable_t::textures_t::texture() {
    if (f_texture)
        return m_texture;
    n_texture = true;
    if (loc_texture()->addr() != 0) {
        n_texture = false;
        std::streampos _pos = m__io->pos();
        m__io->seek(loc_texture()->addr());
        m_texture = new texture_t(m__io, this, m__root);
        m__io->seek(_pos);
        f_texture = true;
    }
    return m_texture;
}

drawable_t::indicies_data_t::indicies_data_t(kaitai::kstream* p__io, drawable_t::geometry_t* p__parent, drawable_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_loc_indicies = 0;
    m_loc_p1 = 0;
    m_indicies = 0;
    f_indicies = false;
    f_unknown_seq0 = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void drawable_t::indicies_data_t::_read() {
    m_unk0 = m__io->read_bytes(8);
    m_indecies_count = m__io->read_u4le();
    m_unk1 = m__io->read_bytes(12);
    m_loc_indicies = new ptr_t(m__io, this, m__root);
    m_unk2 = m__io->read_bytes(16);
    m_loc_p1 = new ptr_t(m__io, this, m__root);
    m_unk3 = m__io->read_bytes(8);
}

drawable_t::indicies_data_t::~indicies_data_t() {
    _clean_up();
}

void drawable_t::indicies_data_t::_clean_up() {
    if (m_loc_indicies) {
        delete m_loc_indicies; m_loc_indicies = 0;
    }
    if (m_loc_p1) {
        delete m_loc_p1; m_loc_p1 = 0;
    }
    if (f_indicies) {
        if (m_indicies) {
            delete m_indicies; m_indicies = 0;
        }
    }
    if (f_unknown_seq0) {
    }
}

std::vector<uint16_t>* drawable_t::indicies_data_t::indicies() {
    if (f_indicies)
        return m_indicies;
    std::streampos _pos = m__io->pos();
    m__io->seek(loc_indicies()->addr());
    m_indicies = new std::vector<uint16_t>();
    const int l_indicies = indecies_count();
    for (int i = 0; i < l_indicies; i++) {
        m_indicies->push_back(m__io->read_u2le());
    }
    m__io->seek(_pos);
    f_indicies = true;
    return m_indicies;
}

std::string drawable_t::indicies_data_t::unknown_seq0() {
    if (f_unknown_seq0)
        return m_unknown_seq0;
    std::streampos _pos = m__io->pos();
    m__io->seek(loc_p1()->addr());
    m_unknown_seq0 = m__io->read_bytes(64);
    m__io->seek(_pos);
    f_unknown_seq0 = true;
    return m_unknown_seq0;
}

drawable_t::sampler_data_t::sampler_data_t(int32_t p_i, kaitai::kstream* p__io, drawable_t::texture_info_t* p__parent, drawable_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_i = p_i;
    m_hash = 0;
    f_sampler_id = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void drawable_t::sampler_data_t::_read() {
    m_hash = new hash_t(m__io, this, m__root);
    m_flag = m__io->read_bits_int_le(2);
    m_index = m__io->read_bits_int_le(30);
}

drawable_t::sampler_data_t::~sampler_data_t() {
    _clean_up();
}

void drawable_t::sampler_data_t::_clean_up() {
    if (m_hash) {
        delete m_hash; m_hash = 0;
    }
    if (f_sampler_id) {
    }
}

uint8_t drawable_t::sampler_data_t::sampler_id() {
    if (f_sampler_id)
        return m_sampler_id;
    std::streampos _pos = m__io->pos();
    m__io->seek(((_parent()->_parent()->loc_textures()->addr() + (_parent()->texture_count() * 32)) + i()));
    m_sampler_id = m__io->read_u1();
    m__io->seek(_pos);
    f_sampler_id = true;
    return m_sampler_id;
}

drawable_t::byte_list_t::byte_list_t(kaitai::kstream* p__io, drawable_t::vertex_t* p__parent, drawable_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_data = 0;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void drawable_t::byte_list_t::_read() {
    m_data = new std::vector<uint8_t>();
    {
        int i = 0;
        while (!m__io->is_eof()) {
            m_data->push_back(m__io->read_u1());
            i++;
        }
    }
}

drawable_t::byte_list_t::~byte_list_t() {
    _clean_up();
}

void drawable_t::byte_list_t::_clean_up() {
    if (m_data) {
        delete m_data; m_data = 0;
    }
}

drawable_t::texture_t::texture_t(kaitai::kstream* p__io, drawable_t::textures_t* p__parent, drawable_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_loc_name = 0;
    m_loc_unk2 = 0;
    f_name = false;
    f_l1 = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void drawable_t::texture_t::_read() {
    m_unk0 = m__io->read_bytes(16);
    m_flag = m__io->read_u4le();
    m_unk1 = m__io->read_bytes(20);
    m_loc_name = new ptr_t(m__io, this, m__root);
    m_loc_unk2 = new ptr_t(m__io, this, m__root);
}

drawable_t::texture_t::~texture_t() {
    _clean_up();
}

void drawable_t::texture_t::_clean_up() {
    if (m_loc_name) {
        delete m_loc_name; m_loc_name = 0;
    }
    if (m_loc_unk2) {
        delete m_loc_unk2; m_loc_unk2 = 0;
    }
    if (f_name) {
    }
    if (f_l1 && !n_l1) {
    }
}

std::string drawable_t::texture_t::name() {
    if (f_name)
        return m_name;
    std::streampos _pos = m__io->pos();
    m__io->seek(loc_name()->addr());
    m_name = kaitai::kstream::bytes_to_str(m__io->read_bytes_term(0, false, true, true), "ASCII");
    m__io->seek(_pos);
    f_name = true;
    return m_name;
}

std::string drawable_t::texture_t::l1() {
    if (f_l1)
        return m_l1;
    n_l1 = true;
    if (loc_unk2()->addr() != 0) {
        n_l1 = false;
        std::streampos _pos = m__io->pos();
        m__io->seek(loc_unk2()->addr());
        m_l1 = m__io->read_bytes(72);
        m__io->seek(_pos);
        f_l1 = true;
    }
    return m_l1;
}

drawable_t::geometry_t::geometry_t(kaitai::kstream* p__io, drawable_t::geometry_ptr_t* p__parent, drawable_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_loc_vertex_data = 0;
    m_loc_indicies_data = 0;
    m_vertex_data = 0;
    m_indicies_data = 0;
    f_vertex_data = false;
    f_indicies_data = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void drawable_t::geometry_t::_read() {
    m_unk0 = m__io->read_bytes(8);
    m_loc_vertex_data = new ptr_t(m__io, this, m__root);
    m_loc_indicies_data = new ptr_t(m__io, this, m__root);
    m_unk1 = m__io->read_bytes(40);
}

drawable_t::geometry_t::~geometry_t() {
    _clean_up();
}

void drawable_t::geometry_t::_clean_up() {
    if (m_loc_vertex_data) {
        delete m_loc_vertex_data; m_loc_vertex_data = 0;
    }
    if (m_loc_indicies_data) {
        delete m_loc_indicies_data; m_loc_indicies_data = 0;
    }
    if (f_vertex_data) {
        if (m_vertex_data) {
            delete m_vertex_data; m_vertex_data = 0;
        }
    }
    if (f_indicies_data) {
        if (m_indicies_data) {
            delete m_indicies_data; m_indicies_data = 0;
        }
    }
}

drawable_t::vertex_data_t* drawable_t::geometry_t::vertex_data() {
    if (f_vertex_data)
        return m_vertex_data;
    std::streampos _pos = m__io->pos();
    m__io->seek(loc_vertex_data()->addr());
    m_vertex_data = new vertex_data_t(m__io, this, m__root);
    m__io->seek(_pos);
    f_vertex_data = true;
    return m_vertex_data;
}

drawable_t::indicies_data_t* drawable_t::geometry_t::indicies_data() {
    if (f_indicies_data)
        return m_indicies_data;
    std::streampos _pos = m__io->pos();
    m__io->seek(loc_indicies_data()->addr());
    m_indicies_data = new indicies_data_t(m__io, this, m__root);
    m__io->seek(_pos);
    f_indicies_data = true;
    return m_indicies_data;
}

drawable_t::texture_data_t::texture_data_t(kaitai::kstream* p__io, drawable_t::texture_info_t* p__parent, drawable_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_hash = 0;
    m_textures = 0;
    f_textures = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void drawable_t::texture_data_t::_read() {
    m_hash = new hash_t(m__io, this, m__root);
    m_flag = m__io->read_bits_int_le(2);
    m_index = m__io->read_bits_int_le(30);
}

drawable_t::texture_data_t::~texture_data_t() {
    _clean_up();
}

void drawable_t::texture_data_t::_clean_up() {
    if (m_hash) {
        delete m_hash; m_hash = 0;
    }
    if (f_textures) {
        if (m_textures) {
            delete m_textures; m_textures = 0;
        }
    }
}

drawable_t::textures_t* drawable_t::texture_data_t::textures() {
    if (f_textures)
        return m_textures;
    std::streampos _pos = m__io->pos();
    m__io->seek((_parent()->_parent()->loc_textures()->addr() + (index() * 8)));
    m_textures = new textures_t(m__io, this, m__root);
    m__io->seek(_pos);
    f_textures = true;
    return m_textures;
}

drawable_t::geometry_ptr_t::geometry_ptr_t(kaitai::kstream* p__io, drawable_t::model_t* p__parent, drawable_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
    m_loc_geometry = 0;
    m_geometry = 0;
    f_geometry = false;

    try {
        _read();
    } catch(...) {
        _clean_up();
        throw;
    }
}

void drawable_t::geometry_ptr_t::_read() {
    m_loc_geometry = new ptr_t(m__io, this, m__root);
}

drawable_t::geometry_ptr_t::~geometry_ptr_t() {
    _clean_up();
}

void drawable_t::geometry_ptr_t::_clean_up() {
    if (m_loc_geometry) {
        delete m_loc_geometry; m_loc_geometry = 0;
    }
    if (f_geometry) {
        if (m_geometry) {
            delete m_geometry; m_geometry = 0;
        }
    }
}

drawable_t::geometry_t* drawable_t::geometry_ptr_t::geometry() {
    if (f_geometry)
        return m_geometry;
    std::streampos _pos = m__io->pos();
    m__io->seek(loc_geometry()->addr());
    m_geometry = new geometry_t(m__io, this, m__root);
    m__io->seek(_pos);
    f_geometry = true;
    return m_geometry;
}

drawable_t::models_t* drawable_t::lod_h() {
    if (f_lod_h)
        return m_lod_h;
    n_lod_h = true;
    if (loc_lod_h()->addr() != 0) {
        n_lod_h = false;
        std::streampos _pos = m__io->pos();
        m__io->seek(loc_lod_h()->addr());
        m_lod_h = new models_t(m__io, this, m__root);
        m__io->seek(_pos);
        f_lod_h = true;
    }
    return m_lod_h;
}

drawable_t::models_t* drawable_t::lod_v() {
    if (f_lod_v)
        return m_lod_v;
    n_lod_v = true;
    if (loc_lod_v()->addr() != 0) {
        n_lod_v = false;
        std::streampos _pos = m__io->pos();
        m__io->seek(loc_lod_v()->addr());
        m_lod_v = new models_t(m__io, this, m__root);
        m__io->seek(_pos);
        f_lod_v = true;
    }
    return m_lod_v;
}

std::string drawable_t::ptr_some() {
    if (f_ptr_some)
        return m_ptr_some;
    std::streampos _pos = m__io->pos();
    m__io->seek(loc_some()->addr());
    m_ptr_some = m__io->read_bytes(16);
    m__io->seek(_pos);
    f_ptr_some = true;
    return m_ptr_some;
}

drawable_t::models_t* drawable_t::lod_m() {
    if (f_lod_m)
        return m_lod_m;
    n_lod_m = true;
    if (loc_lod_m()->addr() != 0) {
        n_lod_m = false;
        std::streampos _pos = m__io->pos();
        m__io->seek(loc_lod_m()->addr());
        m_lod_m = new models_t(m__io, this, m__root);
        m__io->seek(_pos);
        f_lod_m = true;
    }
    return m_lod_m;
}

std::string drawable_t::name() {
    if (f_name)
        return m_name;
    std::streampos _pos = m__io->pos();
    m__io->seek(loc_name()->addr());
    m_name = kaitai::kstream::bytes_to_str(m__io->read_bytes_term(0, false, true, true), "ASCII");
    m__io->seek(_pos);
    f_name = true;
    return m_name;
}

drawable_t::shader_group_t* drawable_t::shader_group() {
    if (f_shader_group)
        return m_shader_group;
    std::streampos _pos = m__io->pos();
    m__io->seek(loc_shader_group()->addr());
    m_shader_group = new shader_group_t(m__io, this, m__root);
    m__io->seek(_pos);
    f_shader_group = true;
    return m_shader_group;
}

drawable_t::models_t* drawable_t::lod_l() {
    if (f_lod_l)
        return m_lod_l;
    n_lod_l = true;
    if (loc_lod_l()->addr() != 0) {
        n_lod_l = false;
        std::streampos _pos = m__io->pos();
        m__io->seek(loc_lod_l()->addr());
        m_lod_l = new models_t(m__io, this, m__root);
        m__io->seek(_pos);
        f_lod_l = true;
    }
    return m_lod_l;
}
