meta:
  id: drawable
  endian: le

seq:
  - id: unknown0
    size: 8
  - id: loc_some
    type: ptr
  - id: loc_shader_group
    type: ptr
  - id: unknown1
    size: 8
  - id: bounding_sphere_center
    type: xyz
  - id: bounding_sphere_radius
    type: f4
  - id: bounding_box_min
    type: xyz
  - id: unknown2
    size: 4
  - id: bounding_box_max 
    type: xyz
  - id: unknown3
    size: 4
  - id: loc_lod_h
    type: ptr
  - id: loc_lod_m
    type: ptr
  - id: loc_lod_l
    type: ptr
  - id: loc_lod_v
    type: ptr
  - id: lod_distance
    repeat: expr
    repeat-expr: 4
    type: u4
  - id: lod_flags
    repeat: expr
    repeat-expr: 4
    type: u4
  - id: unknown4
    size: 0x18
  - id: loc_name
    type: ptr
  - id: unknown5
    size: 0x20

instances:
  ptr_some:
    pos: loc_some.addr
    size: 0x10
  shader_group:
    pos: loc_shader_group.addr
    type: shader_group
  lod_h:
    pos: loc_lod_h.addr
    type: models
    if: loc_lod_h.addr != 0
  lod_m:
    pos: loc_lod_m.addr
    type: models
    if: loc_lod_m.addr != 0
  lod_l:
    pos: loc_lod_l.addr
    type: models
    if: loc_lod_l.addr != 0
  lod_v:
    pos: loc_lod_v.addr
    type: models
    if: loc_lod_v.addr != 0
  name:
    pos: loc_name.addr
    type: str
    terminator: 0
    encoding: ascii
    
types:
  ptr:
    seq:
      - id: byte0
        type: u1
      - id: byte1
        type: u1
      - id: byte2
        type: u1
      - id: byte0x50
        type: u1
      - id: reserved
        type: u4
    instances:
      addr:
        value: 'byte0 + (byte1 << 8) + (byte2 << 16)'
        
  hash:
    seq:
      - id: hash_value
        type: u4
        enum: hash_value
        
  xyz:
    seq:
      - id: x
        type: f4
      - id: y
        type: f4
      - id: z
        type: f4
        
  normals:
    meta:
      bit-endian: le
    seq:
      - id: x_raw
        type: b10
      - id: y_raw
        type: b10
      - id: z_raw
        type: b10
      - id: w
        type: b2
    instances:
      x:
        value: '(x_raw >= 512 ? (x_raw-512) : x_raw-511).as<f4>/511'
      y:
        value: '(y_raw >= 512 ? (y_raw-512) : y_raw-511).as<f4>/511'
      z:
        value: '(z_raw >= 512 ? (z_raw-512) : z_raw-511).as<f4>/511'
      x_real:
        value: '(x_raw >= 512 ? (x_raw-1024) : x_raw).as<f4>/511'
      y_real:
        value: '(y_raw >= 512 ? (y_raw-1024) : y_raw).as<f4>/511'
      z_real:
        value: '(z_raw >= 512 ? (z_raw-1024) : z_raw).as<f4>/511'
        
  rgba:
    seq:
      - id: r
        type: u1
      - id: g
        type: u1
      - id: b
        type: u1
      - id: a
        type: u1
        
  uv:
    seq:
      - id: u
        type: f4
      - id: v
        type: f4
  
  float_list:
    seq:
      - id: data
        type: f4
        repeat: eos
        
  byte_list:
    seq:
      - id: data
        type: u1
        repeat: eos
        
  normal_list:
    seq:
      - id: data
        type: normals
        repeat: eos
  
  models:
    seq:
      - id: loc_model_list
        type: ptr
      - id: model_count
        type: u2
      - id: count_0
        type: u2
      - id: unk0
        size: 4
        
    instances:
      model_list:
        pos: loc_model_list.addr
        repeat: expr
        repeat-expr: model_count
        type: model_ptr
        
  model_ptr:
    seq:
      - id: loc_model
        type: ptr
        
    instances:
      model:
        pos: loc_model.addr
        type: model
        
  model:
    seq:
      - id: unk0
        size: 8
      - id: loc_geometry_list
        type: ptr
      - id: geometry_count
        type: u2
      - id: bound_count_raw
        type: u2
      - id: unk1
        size: 4
      - id: loc_bounds_list
        type: ptr
      - id: loc_shader_id
        type: ptr
      - id: unk2
        size: 0x18
      
    instances:
      bound_count:
        value: 'bound_count_raw == 1 ? bound_count_raw : bound_count_raw + 1'
      geometry_list:
        pos: loc_geometry_list.addr
        repeat: expr
        repeat-expr: geometry_count
        type: geometry_ptr
      bounds_list:
        pos: loc_bounds_list.addr
        repeat: expr
        repeat-expr: bound_count
        type: bounds
      shader_id:
        pos: loc_shader_id.addr
        repeat: expr
        repeat-expr: geometry_count
        type: u2
      
  geometry_ptr:
    seq:
      - id: loc_geometry
        type: ptr
        
    instances:
      geometry:
        pos: loc_geometry.addr
        type: geometry
  
  geometry:
    seq:
      - id: unk0
        size: 8
      - id: loc_vertex_data
        type: ptr
      - id: loc_indicies_data
        type: ptr
      - id: unk1
        size: 0x28
        
    instances:
      vertex_data:
        pos: loc_vertex_data.addr
        type: vertex_data
      indicies_data:
        pos: loc_indicies_data.addr
        type: indicies_data
        
  vertex_data:
    seq:
      - id: unk0
        size: 0x8
      - id: vertex_count
        type: u4
      - id: unk1
        size: 0xc
      - id: loc_vertecies
        type: ptr
      - id: unk2
        size: 0x10
      - id: unknown_ptr
        type: ptr
      - id: loc_vertex_layout
        type: ptr
    
    instances:
      unknown_seq0:
        pos: unknown_ptr.addr
        size: 0x40
      vertex_layout:
        pos: loc_vertex_layout.addr
        type: vertex_layout
      verticies:
        type: vertex(_index)
        repeat: expr
        repeat-expr: 52
        
  vertex:
    params:
      - id: i
        type: s4
    instances:
      type:
        value: _parent.vertex_layout.type[i]
      data:
        pos: _parent.loc_vertecies.addr + _parent.vertex_layout.offsets[i]
        size: _parent.vertex_layout.size[i] * _parent.vertex_count
        type:
          switch-on: type
          cases:
            vertex_layout_type::position: float_list
            vertex_layout_type::normal: normal_list
            vertex_layout_type::color: byte_list
            vertex_layout_type::texture: float_list
        if: _parent.vertex_layout.size[i] != 0
        
  vertex_layout:
    seq:
      - id: offsets
        repeat: expr
        repeat-expr: 52
        type: u4
      - id: size
        repeat: expr
        repeat-expr: 52
        type: u1
      - id: type
        type: u1
        repeat: expr
        repeat-expr: 52
        enum: vertex_layout_type
      - id: unk0
        size: 8
    
  
  indicies_data:
    seq:
      - id: unk0
        size: 0x8
      - id: indecies_count
        type: u4
      - id: unk1
        size: 0xc
      - id: loc_indicies
        type: ptr
      - id: unk2
        size: 0x10
      - id: loc_p1
        type: ptr
      - id: unk3
        size: 0x8
        
    instances:
      indicies:
        pos: loc_indicies.addr
        repeat: expr
        repeat-expr: indecies_count
        type: u2
      unknown_seq0:
        pos: loc_p1.addr
        size: 0x40
        
  bounds:
    seq:
      - id: bb_min
        type: xyz
      - id: unk0
        size: 4
      - id: bb_max
        type: xyz
      - id: unk1
        size: 4
  
  
  #Shader
  shader_group:
    seq:
      - id: unk0
        size: 8
      - id: loc_texture_dict
        type: ptr
      - id: loc_shader_list
        type: ptr
      - id: shader_count
        type: u2
      - id: count_0
        type: u2
      - id: unk1
        size: 0x24
    
    instances:
      texture_dict:
        pos: loc_texture_dict.addr
        type: texture_dict
        if: loc_texture_dict.addr != 0
      shader_list:
        pos: loc_shader_list.addr
        repeat: expr
        repeat-expr: shader_count
        type: shader_list
      
  texture_dict:
    seq:
      - id: unk0
        size: 0x20
      - id: loc_embedded
        type: ptr
      - id: count_0
        type: u2
      - id: count_1
        type: u2
      - id: unk1
        size: 0x4
      - id: loc_textures
        type: ptr
      - id: texture_count
        type: u2
      - id: count_3
        type: u2
    
    instances:
      embedded:
        pos: loc_embedded.addr
        type: embedded
        if: loc_embedded.addr != 0
      textures:
        pos: loc_textures.addr
        type: textures
        if: loc_textures.addr != 0
        repeat: expr
        repeat-expr: texture_count
        
  embedded:
    seq:
      - id: unk
        type: u4
      - id: unk0
        size: 0x10
      #- id: data
      #  size: 0x1000
      
      
  shader_list:
    seq:
      - id: loc_shader
        type: ptr
            
    instances:
      shader:
        pos: loc_shader.addr
        type: shader
        
  shader:
    seq:
      - id: shader_type
        type: hash
      - id: unk0
        size: 4
      - id: loc_c_buffer
        type: ptr
      - id: loc_textures
        type: ptr
      - id: unk1
        size: 8
      - id: loc_sampler
        type: ptr
      - id: unk2
        size: 0x10
      - id: unk3
        size: 8
    instances:
      texture_info:
        pos: loc_sampler.addr
        type: texture_info
        
  textures:
    seq:
      - id: loc_texture
        type: ptr
    instances:
      texture:
        pos: loc_texture.addr
        type: texture
        if: loc_texture.addr != 0
        
  texture:
    seq:
      - id: unk0
        size: 0x10
      - id: flag
        type: u4
      - id: unk1
        size: 0x14
      - id: loc_name
        type: ptr
      - id: loc_unk2
        type: ptr
    instances:
      name:
        pos: loc_name.addr
        type: str
        terminator: 0
        encoding: ascii
      l1:
        pos: loc_unk2.addr
        size: 0x48
        if: loc_unk2.addr != 0
        
  texture_info:
    seq:
      - id: unk0
        type: u1
      - id: texture_count
        type: u1
      - id: unk1
        type: u1
      - id: sampler_count
        type: u1
      - id: all_count
        type: u4
      - id: texture_data
        type: texture_data
        repeat: expr
        repeat-expr: texture_count
      - id: sampler_data
        type: sampler_data(_index)
        repeat: expr
        repeat-expr: sampler_count
      - id: c_buffer_data
        type: c_buffer_data
        repeat: expr
        repeat-expr: all_count - texture_count - sampler_count
      
  texture_data:
    meta:
      bit-endian: le
    seq:
      - id: hash
        type: hash
      - id: flag
        type: b2
      - id: index
        type: b30
    instances:
      textures:
        pos: _parent._parent.loc_textures.addr + index * 8
        type: textures
        
  sampler_data:
    meta:
      bit-endian: le
    params:
      - id: i
        type: s4
    seq:
      - id: hash
        type: hash
      - id: flag
        type: b2
      - id: index
        type: b30
    instances:
      sampler_id:
        pos: _parent._parent.loc_textures.addr + _parent.texture_count * 0x20 + i
        type: u1
            
  c_buffer_data:
    meta:
      bit-endian: le
    seq:
      - id: hash
        type: hash
      - id: flags
        type: b2
      - id: buffer_id
        type: b6
      - id: offset
        type: b12
      - id: length
        type: b12
    instances:
      loc_data:
        pos: _parent._parent.loc_c_buffer.addr + buffer_id * 0x8
        type: ptr
      data:
        pos: loc_data.addr + offset
        type: f4
        repeat: expr
        repeat-expr: length/4
        
enums:
  hash_value:
    0x0: none
    0xbcf03fc1: standard
    0x77d8ab27: standard_2lyr
    0xb217b263: standard_2lyr_pxm
    0x512937b5: standard_dirt
    0xd41ddcc3: standard_decal_blend
    0xb1ecac: standard_emissive
    0x3cdb799d: horsesheentexture
    0x41d91335: furshadow03
    0x3e506e00: foliagebranchbendpivot0
    0xa38a7b5b: shelllayerstart0
    0x6234769e: treehorizontalbendupperbound0
    0x4ca1f342: lyr0maxwetness
    0xa6902f3e: newfursoften0
    0x551b853c: lookingglassdistortioncenter1
    0xf3b6cac3: depthtexture
    0x37120671: pbrtweak_translucency
    0x44546346: dirtcolor
    0x65e15377: comboheightsamplerfur01
    0xdb3df29e: terrainfresnel
    0x42a8b79: haspuddleswitch
    0xc4ba4ae7: furselfshadowmin0
    0x4ab802cd: currentinscatterrm0
    0xa88f9b63: lyr1uvscale
    0x8ef82c3b: lyr0metalnessmodifier
    0xa0c55c99: pbrdetail_roughness
    0xf7864a2a: heighttexture
    0x3f4b6d62: lyr0uvset
    0x70148243: targetsize
    0x114d742c: furalphaclip03
    0x79045347: miplinearclamp
    0x95a3887e: furdirtstiffness0
    0x9a8c6855: maxvertpushend
    0x42c685dd: windamount
    0xec3e0b53: pollenlayer3
    0x3eecfe54: dirtfactor
    0xe9437406: hardalphablend
    0x738ca901: miplinearwrap
    0xfb382d27: puddlemaskscale
    0xcc2fed8e: detailindexoverride
    0x24c5ab07: gcsmshadowtexturesamp
    0xfa0446c7: lyr1materialbtex
    0xb5e828b8: furmaxlayers0
    0xd5588afc: damagesampler
    0x84c69350: lyr0normaltex
    0xa6934c16: marktaaghostingbit
    0xb04a9ad0: distortionparams
    0x1fcb228c: engravingshowmaterial
    0x28b41dfb: finlayerinc0
    0x9c6679da: lyr0heightbias
    0xe303d24: finlayercompensation0
    0x9b6972ea: sundirection
    0xc3689fd0: furpervtxhacklesstiffness0
    0xa59c5fe3: controlfiltera
    0x579cda6b: lyr0cavity
    0xc6f46e79: speculartex
    0x9a0f398b: wrinklebasefadeoutamount
    0x3884d2f: pollenlayerplacement
    0xfc1fc225: furmaskusingbluetint0
    0x67b37bf1: dirtroughness
    0x1e3f6af2: fixedgatheredlighttex
    0x550525c7: anisotropic16xwrap
    0xdac8f5e7: envefftextileuv
    0x50d8095d: lyr1translucency
    0xd1ddbdad: fincompression0
    0x458013dc: dirtblend
    0x63c2fc31: anisotropicspecularcolour
    0x92df42f: usefakecutout
    0x4bd435a8: fogandopacityoverride
    0xd883aa9e: diffusetexture_layer1
    0xc4b7d819: pbrdetail_ao
    0xfa066b1e: furlength0
    0xf6dfe913: furalphadistance
    0xd06b9a44: numtargets
    0x46b7c64f: bumpsampler
    0x9fe5f2b2: pbrtweak_metallic
    0xe038a645: distortiontexture
    0x9878de34: mirrorreflection
    0x9db47191: decalblendopacitygbuffer1
    0x2be58df5: decalblendopacitygbuffer2
    0x27dbd2be: bumptexture_layer0
    0xe0e3749e: pollenlayer1
    0xd15eebcd: aerialperspectiveslicedistr
    0xca4299e4: detailsampler
    0x6239614e: wrinklemasktexture
    0xffdd3584: lyr1heightbias
    0xce7b968e: diffusetexture_layer0
    0x7f794826: lookingglassblurtexture
    0xce035f37: tinyhdrtex
    0x3582987d: furuvscales
    0xe32da2c8: svertsin
    0x1ebf396: calcbyambientcol
    0x4eeec0f: hasclothswitch
    0x3d3ede5f: busehardlight
    0x3e95fa90: dirtdecalmask
    0x5eebed48: emissivemultiplier
    0x4b87bd6: stippletexture
    0xe9d92747: dirttilescale
    0xc8e8c282: diffusetex
    0x27657f7c: maxshowsplattertex
    0x63031fb5: noisetexture
    0x4e52959d: liverypalselector
    0xff245382: furalphaclip47
    0x814a7fc: bloodflowmask
    0x1dccadc4: anisotropicspecularexponent
    0x7485dafb: dirtdiffusetex
    0x985a4bc7: furglobalparams0
    0xb0a6ff4a: furminlayers0
    0xcc6e71ab: dirtvertpushscale
    0x22f30325: wrinklebumpscale
    0xc7ec4e28: pushpivotbuffer
    0x3c4af3d4: lyr0materialbtex
    0x3b9e07f: lyr0heightscale
    0x1a016c7e: tintbumptexture
    0xbd772afa: stipplesampler
    0x4f7b90df: cullspheres
    0x1caef69a: tintblendamount
    0xc31d51ff: backlightintensities
    0x52d8a564: lyr0tint
    0xb095a74d: skinnedtangentsdef
    0x5960e75b: proceduraldir
    0x812e6719: maxvertpushstart
    0x97071119: rawinstancebuffer
    0x6e6d1eae: onofffades
    0xcff102ed: wrinklemultiplier
    0x37ff04aa: controlfilterc
    0x642529e2: slodcolors
    0x7e1f7f44: bumptexture_layer1
    0xcbc6c5b3: blendsoftness
    0x691e3533: usetranslucency
    0x8eb4938d: materialbtexture2
    0xe710045: parallaxselfshadowamount
    0xd375f690: grassnoisetilescale
    0x32dd9ff5: wetnessmultiplier
    0xe50a5060: specsampler2
    0x50b5445a: aomapintensity0
    0xeaed8eb0: splatdiffusetex
    0x4aeb23e1: lyr1bumpiness
    0x565d0f22: proceduralthreshold
    0xe263a3bf: lookingglassdistortionparams
    0xc0b0dda1: nightonly
    0x13450c6: useworldspacenormals
    0x15c3c019: umwindexponent0
    0x942cb0ab: engravingmaterialthreshold
    0x88ae82a: lyr0translucency
    0x614ed177: clippingplane
    0x5ed7487b: heightuvset
    0x26cc8f94: detailsettings0
    0x38757622: heightscale
    0x25990c39: fadeexponent
    0x184d4d47: trilinearclamp
    0xcd27763: detailtexarrayn
    0x2b8ea03b: crackdecalbumptilescale
    0x68130dd7: furpervtxscriptedstiffness0
    0x7b21acbf: vehtintpalettetex
    0xb31b94c5: engravinginvert
    0x14a8d102: umpedwindexponent0
    0xc7503fa9: crackdecalbumpalphathreshold
    0x42110214: materialmapatexture_layer1
    0x80773567: crackdecalbumpamount
    0xcfb33aca: moondirection
    0xcb80ed9f: lyr0porosity
    0x1ab3f264: computedatabuffer
    0x4a9daac9: umpedwindnoisescaleminmax0
    0x68d6159b: backlightcolor
    0x42ebbdcf: furlayerparams
    0x8f7dcc57: furwetstiffness0
    0x2a617f90: wrinkletexture
    0x48c7e72b: pbrdetail_metallic
    0xc25ad470: calcbyambientintensity
    0x6c4ef4eb: shellcompression0
    0x18827300: detailsettings1
    0xf6329cd1: newfuralpha0
    0xdb7b6a2f: umwindscale0
    0x1d5b899b: crackedgebumptilescale
    0x608799c6: specsampler
    0x5106c3fb: brokenspecularcolor
    0x7c0055b9: detailtexarrayd
    0xb0d07d53: maxsplatterend
    0x3ea37b39: materialmapatexture_layer3
    0xf855de4e: currentinscatterrm1
    0x81afcc17: cableemissive
    0xee850962: bloommod
    0x5ecf33e4: shellfurblur0
    0x78ad7209: manualdepthtest
    0xcc722b7d: newfurfluffup
    0x9e3722e4: speculartexture
    0x83876745: fresnelselector
    0xbaf88f75: cableambient
    0xbfdcc9b6: albedopalettetex
    0x1f8f194: currentinscatterrm2
    0x4d56d7fe: lyr1materialatex
    0x86d9e8b8: lookingglassdistortioncenter2
    0x73529a7c: tessellationmultiplier
    0x3fb7964f: tinttexture
    0x4815dcf5: engravingsampleoffset
    0x5ce9b178: usepaintedwetness
    0xe17a6bff: sumgatheredlighttex
    0xe0da2d7: controltileamount
    0x9220e886: glodtransitionrange
    0x1a33bfed: pbrdetail_sheen
    0xd3cd3e65: ripplescale
    0xb7236878: calcbysunintensity
    0xd74bf95c: furbendwindmaxspeedclamp0
    0x3b81d0da: furtiptranslucencyadj0
    0xdb203d02: maxwetness
    0xcce63921: computeinstancebuffer
    0xc7adf49b: lyr0albedomodifier
    0xa09baf9d: umpedwindnoiseratio0
    0x4473d497: lyr0roughnessmodifier
    0x5eb2a42d: pxmenabled
    0x41dd5e86: umwindnoisescaleminmax0
    0x85261019: fogtexture
    0x81e387cc: slodinfobuffer
    0x3942822d: pbrtweak_fresnel
    0xa7f79e8f: pxmscales1234
    0x7c001b29: treehorizontalbendstartratio0
    0x3e9e055f: pbrtweak_roughness
    0x5462abc0: bumptexture2
    0xc8a5eaa5: engravingtexturetex
    0x7d0d22b5: albedooverridetex
    0x1e77bf4c: bumptex
    0x59eb15c5: controlfilter
    0x87b61eaf: heighttexturex
    0xaf958f4: dirtuvset
    0xd43cdcd: gbuffertexture1
    0x6f07eed1: lyr1tint
    0x647ece0d: debugshowlivery
    0x739e3d0d: speculartex2
    0x6063ce32: ordernumber
    0x1d5c320b: engravingsecondaytexture
    0x8fc59620: flowtexture
    0xa1994833: umpedwindscale0
    0xe45d3879: finstartposition0
    0x5df8ecde: cablediffuse
    0x2d6ddb68: snowmelt
    0x44054373: furstiffness0
    0x377ec8ce: alphascale
    0x27fac50c: placementextents
    0x345a4189: brokendiffusecolor
    0x307568fa: useoverlayblend
    0x64c4d195: deferredlightparams
    0xc24e93d4: treemmscale0
    0x6acc6346: engravingbumpiness
    0x58b6e707: lyr1normaltex
    0xcc155f4b: dirtnoisetex
    0x18346e42: rustnoisetex
    0x1c1acf8c: pbrtweak_detailindex_
    0xa021ff6e: furlengthjitter0
    0xe4ce95ac: comboheighttexturefur01
    0x684468a8: engravingedgesmoothness
    0x32b9df09: diffusetexture_layer2
    0x9c35a21b: treeverticalbendexp0
    0x51b156a7: gbuffertexture0
    0x2bb2ede8: lyr0materialatex
    0x8d573582: treeverticalbendupperbound0
    0x1f009b95: batchcomputeparamsbuffer
    0x750d09d: detailsettings2
    0xefff27ff: lyr1detailsettings
    0x13ba4503: heightbias
    0xf208e5ee: invcontrol
    0xd8373aec: trilinearborderblack
    0x8d3bca95: anisonoisespectexture
    0xa3496f5b: engravingmaskwidth
    0xba76e08d: finfurblur0
    0xe7851d21: pbrtweak_ao
    0x38ebcdb3: controltexturetex
    0xb84d48a2: decaltint
    0xc8602a97: diffuse2modspec
    0x30e2ee87: tattooalbedo
    0x2a670f69: furshadow47
    0xca8e7281: treehorizontalbendscale0
    0xb9f4bdac: controltexturetexa
    0xdb26e4de: tintintensity
    0x78dd395b: skinnedvertexdef
    0xc075f9b6: lookuptexture
    0x6148ffd2: scsvertexinputattributes
    0x10306a3f: comboheighttexturefur23
    0x5a66fb2a: buseproceduralblend
    0xd532e760: enablenearcamerafade
    0x7d8eee36: maxsplatterstart
    0x77ca165f: pointclamp
    0x1b5a9556: pbrtweak_detail
    0xc8ccec64: uvscalebias
    0xfd5ffaf7: treemmspeed0
    0xaea6a2b8: furattencoef0
    0x81f2a56f: maxshowdirttex
    0x1888e777: occlusiontex
    0x8ab18b46: lyr0normaluvset
    0x9b461882: dirtalphachannel
    0x39172858: decalblendopacitygbuffer3
    0xcbdbf631: crackedgebumpamount
    0x66035c96: porosity
    0x2617a142: lyr1tileamount
    0xf099c9f8: aspectratios
    0xe42abc99: windminmaxthreshholds0
    0x1a0066d7: pollenlayer2
    0xf662d131: furpervtxstiffness0
    0xa1f60489: specular
    0x50032cdc: scale
    0xefcd993d: intensity
    0x26c91ccf: roughnessbasedonalbedo
    0xab42b7f2: liverymatselector
    0xf3b9d55: maxmudintensity
    0x614f029e: enablespec
    0x9143179f: impostertexarray1
    0x90ad7593: anglesnearfar
    0x83363bbe: engravingdiffuseamt
    0x34e5962: engravingselfshadowamt
    0xd5b8a0fd: exposuretexture
    0xb9470b30: ripplebumpiness
    0x7d9d39d6: furshellopacityadjust0
    0xde84c011: bumptexture_layer3
    0xd7c38241: bumptexture
    0x377c339: lyr1heightscale
    0x4c759bf1: bumptexture_layer2
    0xd877fab2: controltexturetexc
    0xdc50e20b: dirtuvscale
    0x640111c6: controltexturetexb
    0xbc31f720: treehorizontalbendexp0
    0x381999f3: translucencyastintmask
    0x1cf5b657: texturesamp
    0xd14b442b: haswrinkleswitch
    0x4620a35d: usetessellation
    0xd99c269e: engravingshow
    0xa53f2e56: wetness
    0xc7f84d36: speculartexture2
    0xd42f04a8: lyr0bumpiness
    0x6b1c4332: radiusscale
    0xb44cade5: comboheighttexturefur67
    0xdf47048: diffusetex2
    0x6a5a00e2: targetpositionspacked
    0x3fdca6d4: diffusecolormultiplier
    0x73a205af: scatteringluttex
    0xe5373ef6: furbasetranslucencyadj0
    0x9827b3ed: gwindbendscalevar
    0xbc0cd58: decalblendopacitygbuffer0
    0x5500718e: comboheighttexturefur45
    0xfdd796cf: tintpaletteselector
    0xade2706f: controlfilterb
    0xd2b459c8: pollenlayer
    0x6022028b: lyr0detailsettings
    0xc19a8993: furfinopacityadjust0
    0xb51e2e8f: detailsettings
    0xd8375b5c: sootcolor
    0xe5748e07: lyr1cavity
    0x191c1f: sootroughness
    0x2c8d7182: tintpalettetex
    0xf72bcd78: placementtexture
    0xe0ab3cf2: furfinlengthadjust0
    0x8409a33a: galphatest
    0x879f14f0: backlightoffset
    0xa72163ba: riverfoamtexturescale
    0x346394ea: lyr0diffusetex
    0xe9c969fb: fogcolor
    0x5c8bd42b: furglobalparams1
    0x7f00968f: deferredlightvolumeparams
    0x3d10f3b7: diffusetexture_layer3
    0x48a892c5: pbrcavityrange
    0xb2339a6c: hbbrangescale1234
    0x9161a1e1: oilspanandwibble
    0x552311cb: pxmbiases1234
    0xa98e2243: specularcolor
    0x7d4f12e2: lyr1diffusetex
    0x7538bfc: pushspheres
    0xb5fe3acb: fresnel
    0xc31a94a: wrinklebasefadeoutend
    0xaa20656c: furaofurdepth0
    0xcf80da9b: dirttintchannel
    0x4d15c563: shadowfalloff
    0xd9977f30: projdecaltexarraysampler
    0x8bc2a8eb: raintexturesamplerglobal
    0x93f106ff: pbrglassiness
    0xf50070cc: controluvset
    0xd6659424: pbrtweak_sheen
    0x81db4c55: parallaxscalebias
    0xe44690bb: trilinearwrap
    0x26fba7b2: onofftimes
    0x189e02fe: pollenexistence
    0x50696c21: engravingcavityamt
    0xc3619944: furbendwindinfluence0
    0xa2ed3af3: impostertexarray2
    0x7346b832: lyr1uvset
    0x407f8395: glodfadetilescale
    0xf3ec7ec9: detailindices
    0xf44fad3d: treeverticalbendscale0
    0xff11711d: specmapintmask
    0x82ad94f: wrinklefadeinstart
    0x295d6036: regiontintamount
    0x3754af2: hbbrangebias1234
    0xd9394f28: opacity
    0xf0b67341: batchdisabledbitfield
    0xf08653a5: tintoverride
    0x49d08baa: liverycontroltex
    0x3dfddc31: engravingcreatebump
    0xa3f1be65: transmittanceluttex
    0xf1fe2b71: diffusesampler
    0x72c27ca3: alphauvset
    0xcd6179f: materialmapatexture_layer2
    0xf0ea676: lyr0fresnel
    0x9bc95890: maxdirtintensity
    0x2ab9e501: oilthickness
    0x7da8e5f6: furnoiseuvscale0
    0xf92d3456: detailsettings3
    0x24f3d13a: blendamtcol
    0xbdeafe25: smallhdrcubetex
    0xb98defb4: lyr1maxwetness
    0x3022de38: materialmapatexture_layer0
    0x8c3311be: oilparams
    0xba653f84: furaoblend0
    0xf622a69e: mixamtcol
    0x70849b48: umwindnoiseratio0
    0xc236fa7f: wrinkleaoscale
    0xf6712b81: bumpiness
    0x9861b27c: pbrdetail_translucency
    0x21bd1f86: blendamtintensity
    0xf46b1c9c: cablediffuse2
    0xd87b4f49: puddleheightbias
    0xc3adf7ff: pushspherespreviousframe
    0xb27bf833: lyr1fresnel
    0x4971104a: furgravitywindblend0
    0x7e2ad953: dirtintensity
    0x724bed95: uvset
    0xeb2d8045: clamplookuptexture
    0xbbd9a5dd: lyr1porosity
    0xc812fa46: heightfilter
    0x6e10256a: calcbysuncol
    0x97eaa692: aotexturetex
    0xb957ed6: splatnmrtex
    0xf354f896: lookupuvset
    0xffb38cd5: materialbtexture

    
  vertex_layout_type:
    0: none
    6: position
    24: normal
    28: color
    16: texture
