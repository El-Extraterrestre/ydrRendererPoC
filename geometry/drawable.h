#ifndef DRAWABLE_H_
#define DRAWABLE_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "../util/kaitai/kaitaistruct.h"
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 11000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.11 or later is required"
#endif

class drawable_t : public kaitai::kstruct {

public:
    class embedded_t;
    class uv_t;
    class vertex_t;
    class float_list_t;
    class model_t;
    class shader_list_t;
    class rgba_t;
    class vertex_data_t;
    class c_buffer_data_t;
    class normal_list_t;
    class vertex_layout_t;
    class bounds_t;
    class hash_t;
    class shader_group_t;
    class normals_t;
    class xyz_t;
    class model_ptr_t;
    class models_t;
    class texture_info_t;
    class texture_dict_t;
    class shader_t;
    class ptr_t;
    class textures_t;
    class indicies_data_t;
    class sampler_data_t;
    class byte_list_t;
    class texture_t;
    class geometry_t;
    class texture_data_t;
    class geometry_ptr_t;

    enum hash_value_t {
        HASH_VALUE_NONE = 0,
        HASH_VALUE_SOOTROUGHNESS = 1645599,
        HASH_VALUE_STANDARD_EMISSIVE = 11660460,
        HASH_VALUE_USEWORLDSPACENORMALS = 20205766,
        HASH_VALUE_CALCBYAMBIENTCOL = 32240534,
        HASH_VALUE_CURRENTINSCATTERRM2 = 33091988,
        HASH_VALUE_ENGRAVINGSELFSHADOWAMT = 55466338,
        HASH_VALUE_HBBRANGEBIAS1234 = 58018546,
        HASH_VALUE_LYR1HEIGHTSCALE = 58180409,
        HASH_VALUE_POLLENLAYERPLACEMENT = 59264303,
        HASH_VALUE_LYR0HEIGHTSCALE = 62513279,
        HASH_VALUE_HASPUDDLESWITCH = 69897081,
        HASH_VALUE_STIPPLETEXTURE = 79199190,
        HASH_VALUE_HASCLOTHSWITCH = 82766863,
        HASH_VALUE_DETAILSETTINGS2 = 122736797,
        HASH_VALUE_PUSHSPHERES = 122915836,
        HASH_VALUE_BLOODFLOWMASK = 135571452,
        HASH_VALUE_WRINKLEFADEINSTART = 137025871,
        HASH_VALUE_LYR0TRANSLUCENCY = 143321130,
        HASH_VALUE_USEFAKECUTOUT = 154006575,
        HASH_VALUE_DIRTUVSET = 184113396,
        HASH_VALUE_SPLATNMRTEX = 194346710,
        HASH_VALUE_DECALBLENDOPACITYGBUFFER0 = 197184856,
        HASH_VALUE_WRINKLEBASEFADEOUTEND = 204581194,
        HASH_VALUE_DETAILTEXARRAYN = 215119715,
        HASH_VALUE_MATERIALMAPATEXTURE_LAYER2 = 215357343,
        HASH_VALUE_GBUFFERTEXTURE1 = 222547405,
        HASH_VALUE_DIFFUSETEX2 = 234123336,
        HASH_VALUE_CONTROLTILEAMOUNT = 235774679,
        HASH_VALUE_FINLAYERCOMPENSATION0 = 238042404,
        HASH_VALUE_PARALLAXSELFSHADOWAMOUNT = 242286661,
        HASH_VALUE_LYR0FRESNEL = 252618358,
        HASH_VALUE_MAXMUDINTENSITY = 255565141,
        HASH_VALUE_COMBOHEIGHTTEXTUREFUR23 = 271608383,
        HASH_VALUE_FURALPHACLIP03 = 290288684,
        HASH_VALUE_HEIGHTBIAS = 330974467,
        HASH_VALUE_UMPEDWINDEXPONENT0 = 346607874,
        HASH_VALUE_UMWINDEXPONENT0 = 365150233,
        HASH_VALUE_RUSTNOISETEX = 406089282,
        HASH_VALUE_TRILINEARCLAMP = 407719239,
        HASH_VALUE_DETAILSETTINGS1 = 411202304,
        HASH_VALUE_OCCLUSIONTEX = 411625335,
        HASH_VALUE_POLLENEXISTENCE = 413008638,
        HASH_VALUE_POLLENLAYER2 = 436233943,
        HASH_VALUE_TINTBUMPTEXTURE = 436300926,
        HASH_VALUE_PBRDETAIL_SHEEN = 439599085,
        HASH_VALUE_COMPUTEDATABUFFER = 448000612,
        HASH_VALUE_PBRTWEAK_DETAIL = 458921302,
        HASH_VALUE_PBRTWEAK_DETAILINDEX_ = 471519116,
        HASH_VALUE_TINTBLENDAMOUNT = 481228442,
        HASH_VALUE_TEXTURESAMP = 485865047,
        HASH_VALUE_CRACKEDGEBUMPTILESCALE = 492538267,
        HASH_VALUE_ENGRAVINGSECONDAYTEXTURE = 492581387,
        HASH_VALUE_ANISOTROPICSPECULAREXPONENT = 499953092,
        HASH_VALUE_FIXEDGATHEREDLIGHTTEX = 507472626,
        HASH_VALUE_BUMPTEX = 511164236,
        HASH_VALUE_BATCHCOMPUTEPARAMSBUFFER = 520133525,
        HASH_VALUE_ENGRAVINGSHOWMATERIAL = 533406348,
        HASH_VALUE_BLENDAMTINTENSITY = 566042502,
        HASH_VALUE_WRINKLEBUMPSCALE = 586351397,
        HASH_VALUE_GCSMSHADOWTEXTURESAMP = 616934151,
        HASH_VALUE_BLENDAMTCOL = 619958586,
        HASH_VALUE_FADEEXPONENT = 630787129,
        HASH_VALUE_LYR1TILEAMOUNT = 639082818,
        HASH_VALUE_ROUGHNESSBASEDONALBEDO = 650714319,
        HASH_VALUE_DETAILSETTINGS0 = 650940308,
        HASH_VALUE_ONOFFTIMES = 654026674,
        HASH_VALUE_MAXSHOWSPLATTERTEX = 660963196,
        HASH_VALUE_BUMPTEXTURE_LAYER0 = 668717758,
        HASH_VALUE_PLACEMENTEXTENTS = 670745868,
        HASH_VALUE_FINLAYERINC0 = 682892795,
        HASH_VALUE_REGIONTINTAMOUNT = 693985334,
        HASH_VALUE_WRINKLETEXTURE = 711032720,
        HASH_VALUE_FURSHADOW47 = 711397225,
        HASH_VALUE_OILTHICKNESS = 716825857,
        HASH_VALUE_CRACKDECALBUMPTILESCALE = 730767419,
        HASH_VALUE_LYR0MATERIALATEX = 733146600,
        HASH_VALUE_DECALBLENDOPACITYGBUFFER2 = 736464373,
        HASH_VALUE_TINTPALETTETEX = 747467138,
        HASH_VALUE_SNOWMELT = 762174312,
        HASH_VALUE_MATERIALMAPATEXTURE_LAYER0 = 807591480,
        HASH_VALUE_USEOVERLAYBLEND = 813000954,
        HASH_VALUE_TATTOOALBEDO = 820178567,
        HASH_VALUE_DIFFUSETEXTURE_LAYER2 = 851042057,
        HASH_VALUE_WETNESSMULTIPLIER = 853385205,
        HASH_VALUE_BROKENDIFFUSECOLOR = 878330249,
        HASH_VALUE_LYR0DIFFUSETEX = 878941418,
        HASH_VALUE_FURUVSCALES = 897751165,
        HASH_VALUE_PBRTWEAK_TRANSLUCENCY = 923928177,
        HASH_VALUE_ALPHASCALE = 931055822,
        HASH_VALUE_CONTROLFILTERC = 939459754,
        HASH_VALUE_TRANSLUCENCYASTINTMASK = 941201907,
        HASH_VALUE_HEIGHTSCALE = 947222050,
        HASH_VALUE_CONTROLTEXTURETEX = 954977715,
        HASH_VALUE_DECALBLENDOPACITYGBUFFER3 = 957818968,
        HASH_VALUE_PBRTWEAK_FRESNEL = 960660013,
        HASH_VALUE_FURTIPTRANSLUCENCYADJ0 = 998363354,
        HASH_VALUE_LYR0MATERIALBTEX = 1011545044,
        HASH_VALUE_HORSESHEENTEXTURE = 1021016477,
        HASH_VALUE_DIFFUSETEXTURE_LAYER3 = 1024521143,
        HASH_VALUE_BUSEHARDLIGHT = 1027530335,
        HASH_VALUE_ENGRAVINGCREATEBUMP = 1040047153,
        HASH_VALUE_FOLIAGEBRANCHBENDPIVOT0 = 1045458432,
        HASH_VALUE_DIRTDECALMASK = 1050016400,
        HASH_VALUE_PBRTWEAK_ROUGHNESS = 1050543455,
        HASH_VALUE_MATERIALMAPATEXTURE_LAYER3 = 1050901305,
        HASH_VALUE_DIRTFACTOR = 1055718996,
        HASH_VALUE_LYR0UVSET = 1061907810,
        HASH_VALUE_TINTTEXTURE = 1068996175,
        HASH_VALUE_DIFFUSECOLORMULTIPLIER = 1071425236,
        HASH_VALUE_GLODFADETILESCALE = 1082098581,
        HASH_VALUE_FURSHADOW03 = 1104745269,
        HASH_VALUE_UMWINDNOISESCALEMINMAX0 = 1105026694,
        HASH_VALUE_MATERIALMAPATEXTURE_LAYER1 = 1108410900,
        HASH_VALUE_WINDAMOUNT = 1120306653,
        HASH_VALUE_FURLAYERPARAMS = 1122745807,
        HASH_VALUE_FURSTIFFNESS0 = 1141195635,
        HASH_VALUE_DIRTCOLOR = 1146381126,
        HASH_VALUE_LYR0ROUGHNESSMODIFIER = 1148441751,
        HASH_VALUE_DIRTBLEND = 1166021596,
        HASH_VALUE_USETESSELLATION = 1176544093,
        HASH_VALUE_BUMPSAMPLER = 1186448975,
        HASH_VALUE_ENGRAVINGSAMPLEOFFSET = 1209392373,
        HASH_VALUE_PBRCAVITYRANGE = 1219007173,
        HASH_VALUE_PBRDETAIL_METALLIC = 1221060395,
        HASH_VALUE_FURGRAVITYWINDBLEND0 = 1232146506,
        HASH_VALUE_LIVERYCONTROLTEX = 1238404010,
        HASH_VALUE_UMPEDWINDNOISESCALEMINMAX0 = 1251846857,
        HASH_VALUE_CURRENTINSCATTERRM0 = 1253573325,
        HASH_VALUE_LYR1BUMPINESS = 1256924129,
        HASH_VALUE_FOGANDOPACITYOVERRIDE = 1272198568,
        HASH_VALUE_BUMPTEXTURE_LAYER2 = 1282776049,
        HASH_VALUE_LYR0MAXWETNESS = 1285681986,
        HASH_VALUE_SHADOWFALLOFF = 1293272419,
        HASH_VALUE_LYR1MATERIALATEX = 1297537022,
        HASH_VALUE_LIVERYPALSELECTOR = 1314035101,
        HASH_VALUE_CULLSPHERES = 1333498079,
        HASH_VALUE_SCALE = 1342385372,
        HASH_VALUE_ENGRAVINGCAVITYAMT = 1349086241,
        HASH_VALUE_AOMAPINTENSITY0 = 1354056794,
        HASH_VALUE_LYR1TRANSLUCENCY = 1356335453,
        HASH_VALUE_BROKENSPECULARCOLOR = 1359397883,
        HASH_VALUE_STANDARD_DIRT = 1361655733,
        HASH_VALUE_GBUFFERTEXTURE0 = 1370576551,
        HASH_VALUE_LYR0TINT = 1389929828,
        HASH_VALUE_BUMPTEXTURE2 = 1415752640,
        HASH_VALUE_COMBOHEIGHTTEXTUREFUR45 = 1426092430,
        HASH_VALUE_ANISOTROPIC16XWRAP = 1426400711,
        HASH_VALUE_LOOKINGGLASSDISTORTIONCENTER1 = 1427866940,
        HASH_VALUE_PXMBIASES1234 = 1428361675,
        HASH_VALUE_PROCEDURALTHRESHOLD = 1448939298,
        HASH_VALUE_LYR0CAVITY = 1469897323,
        HASH_VALUE_LYR1NORMALTEX = 1488381703,
        HASH_VALUE_PROCEDURALDIR = 1499522907,
        HASH_VALUE_CONTROLFILTER = 1508578757,
        HASH_VALUE_BUSEPROCEDURALBLEND = 1516698410,
        HASH_VALUE_FURGLOBALPARAMS1 = 1552667691,
        HASH_VALUE_USEPAINTEDWETNESS = 1558819192,
        HASH_VALUE_CABLEDIFFUSE = 1576594654,
        HASH_VALUE_PXMENABLED = 1588765741,
        HASH_VALUE_SHELLFURBLUR0 = 1590637540,
        HASH_VALUE_HEIGHTUVSET = 1591167099,
        HASH_VALUE_EMISSIVEMULTIPLIER = 1592520008,
        HASH_VALUE_LYR0DETAILSETTINGS = 1612841611,
        HASH_VALUE_ORDERNUMBER = 1617153586,
        HASH_VALUE_SPECSAMPLER = 1619499462,
        HASH_VALUE_SCSVERTEXINPUTATTRIBUTES = 1632174034,
        HASH_VALUE_CLIPPINGPLANE = 1632555383,
        HASH_VALUE_ENABLESPEC = 1632567966,
        HASH_VALUE_TREEHORIZONTALBENDUPPERBOUND0 = 1647605406,
        HASH_VALUE_WRINKLEMASKTEXTURE = 1647927630,
        HASH_VALUE_NOISETEXTURE = 1661149109,
        HASH_VALUE_ANISOTROPICSPECULARCOLOUR = 1673722929,
        HASH_VALUE_CONTROLTEXTURETEXB = 1677791686,
        HASH_VALUE_SLODCOLORS = 1680157154,
        HASH_VALUE_DEBUGSHOWLIVERY = 1686031885,
        HASH_VALUE_DEFERREDLIGHTPARAMS = 1690620309,
        HASH_VALUE_COMBOHEIGHTSAMPLERFUR01 = 1709265783,
        HASH_VALUE_POROSITY = 1711496342,
        HASH_VALUE_DIRTROUGHNESS = 1739815921,
        HASH_VALUE_FURPERVTXSCRIPTEDSTIFFNESS0 = 1746079191,
        HASH_VALUE_ENGRAVINGEDGESMOOTHNESS = 1749313704,
        HASH_VALUE_BACKLIGHTCOLOR = 1758860699,
        HASH_VALUE_USETRANSLUCENCY = 1763587379,
        HASH_VALUE_TARGETPOSITIONSPACKED = 1784283362,
        HASH_VALUE_ENGRAVINGBUMPINESS = 1791779654,
        HASH_VALUE_RADIUSSCALE = 1797014322,
        HASH_VALUE_SHELLCOMPRESSION0 = 1817113835,
        HASH_VALUE_CALCBYSUNCOL = 1846551914,
        HASH_VALUE_ONOFFFADES = 1852645038,
        HASH_VALUE_LYR1TINT = 1862790865,
        HASH_VALUE_TARGETSIZE = 1880392259,
        HASH_VALUE_UMWINDNOISERATIO0 = 1887738696,
        HASH_VALUE_UVSET = 1917578645,
        HASH_VALUE_ALPHAUVSET = 1925348515,
        HASH_VALUE_LYR1UVSET = 1934014514,
        HASH_VALUE_TESSELLATIONMULTIPLIER = 1934793340,
        HASH_VALUE_MIPLINEARWRAP = 1938598145,
        HASH_VALUE_SPECULARTEX2 = 1939750157,
        HASH_VALUE_SCATTERINGLUTTEX = 1939998127,
        HASH_VALUE_DIRTDIFFUSETEX = 1954929403,
        HASH_VALUE_POINTCLAMP = 2009732703,
        HASH_VALUE_STANDARD_2LYR = 2010688295,
        HASH_VALUE_MANUALDEPTHTEST = 2024632841,
        HASH_VALUE_SKINNEDVERTEXDEF = 2027764059,
        HASH_VALUE_MIPLINEARCLAMP = 2030326599,
        HASH_VALUE_VEHTINTPALETTETEX = 2065804479,
        HASH_VALUE_TREEHORIZONTALBENDSTARTRATIO0 = 2080381737,
        HASH_VALUE_DETAILTEXARRAYD = 2080396729,
        HASH_VALUE_ALBEDOOVERRIDETEX = 2098012853,
        HASH_VALUE_LYR1DIFFUSETEX = 2102334178,
        HASH_VALUE_MAXSPLATTERSTART = 2106519094,
        HASH_VALUE_FURSHELLOPACITYADJUST0 = 2107455958,
        HASH_VALUE_FURNOISEUVSCALE0 = 2108220918,
        HASH_VALUE_BUMPTEXTURE_LAYER1 = 2115993412,
        HASH_VALUE_DIRTINTENSITY = 2116737363,
        HASH_VALUE_DEFERREDLIGHTVOLUMEPARAMS = 2130744975,
        HASH_VALUE_LOOKINGGLASSBLURTEXTURE = 2138654758,
        HASH_VALUE_CRACKDECALBUMPAMOUNT = 2155296103UL,
        HASH_VALUE_MAXVERTPUSHSTART = 2167301913UL,
        HASH_VALUE_CABLEEMISSIVE = 2175781911UL,
        HASH_VALUE_PARALLAXSCALEBIAS = 2178632789UL,
        HASH_VALUE_SLODINFOBUFFER = 2179172300UL,
        HASH_VALUE_MAXSHOWDIRTTEX = 2180162927UL,
        HASH_VALUE_ENGRAVINGDIFFUSEAMT = 2201369534UL,
        HASH_VALUE_FRESNELSELECTOR = 2206689093UL,
        HASH_VALUE_GALPHATEST = 2215224122UL,
        HASH_VALUE_LYR0NORMALTEX = 2227606352UL,
        HASH_VALUE_FOGTEXTURE = 2233864217UL,
        HASH_VALUE_LOOKINGGLASSDISTORTIONCENTER2 = 2262427832UL,
        HASH_VALUE_BACKLIGHTOFFSET = 2275349744UL,
        HASH_VALUE_HEIGHTTEXTUREX = 2276859567UL,
        HASH_VALUE_LYR0NORMALUVSET = 2326891334UL,
        HASH_VALUE_RAINTEXTURESAMPLERGLOBAL = 2344790251UL,
        HASH_VALUE_OILPARAMS = 2352157118UL,
        HASH_VALUE_ANISONOISESPECTEXTURE = 2369505941UL,
        HASH_VALUE_TREEVERTICALBENDUPPERBOUND0 = 2371302786UL,
        HASH_VALUE_MATERIALBTEXTURE2 = 2394198925UL,
        HASH_VALUE_LYR0METALNESSMODIFIER = 2398628923UL,
        HASH_VALUE_FURWETSTIFFNESS0 = 2407386199UL,
        HASH_VALUE_FLOWTEXTURE = 2412090912UL,
        HASH_VALUE_ANGLESNEARFAR = 2427286931UL,
        HASH_VALUE_IMPOSTERTEXARRAY1 = 2437093279UL,
        HASH_VALUE_OILSPANANDWIBBLE = 2439094753UL,
        HASH_VALUE_GLODTRANSITIONRANGE = 2451630214UL,
        HASH_VALUE_PBRGLASSINESS = 2482046719UL,
        HASH_VALUE_ENGRAVINGMATERIALTHRESHOLD = 2485956779UL,
        HASH_VALUE_FURDIRTSTIFFNESS0 = 2510522494UL,
        HASH_VALUE_RAWINSTANCEBUFFER = 2533822745UL,
        HASH_VALUE_AOTEXTURETEX = 2548737682UL,
        HASH_VALUE_GWINDBENDSCALEVAR = 2552738797UL,
        HASH_VALUE_FURGLOBALPARAMS0 = 2556054471UL,
        HASH_VALUE_PBRDETAIL_TRANSLUCENCY = 2556539516UL,
        HASH_VALUE_MIRRORREFLECTION = 2558058036UL,
        HASH_VALUE_WRINKLEBASEFADEOUTAMOUNT = 2584689035UL,
        HASH_VALUE_MAXVERTPUSHEND = 2592893013UL,
        HASH_VALUE_DIRTALPHACHANNEL = 2605062274UL,
        HASH_VALUE_SUNDIRECTION = 2607379178UL,
        HASH_VALUE_MAXDIRTINTENSITY = 2613663888UL,
        HASH_VALUE_TREEVERTICALBENDEXP0 = 2620760603UL,
        HASH_VALUE_LYR0HEIGHTBIAS = 2623961562UL,
        HASH_VALUE_DECALBLENDOPACITYGBUFFER1 = 2645848465UL,
        HASH_VALUE_SPECULARTEXTURE = 2654413540UL,
        HASH_VALUE_PBRTWEAK_METALLIC = 2682647218UL,
        HASH_VALUE_FURLENGTHJITTER0 = 2686582638UL,
        HASH_VALUE_UMPEDWINDNOISERATIO0 = 2694557597UL,
        HASH_VALUE_PBRDETAIL_ROUGHNESS = 2697288857UL,
        HASH_VALUE_UMPEDWINDSCALE0 = 2711177267UL,
        HASH_VALUE_SPECULAR = 2717254793UL,
        HASH_VALUE_IMPOSTERTEXARRAY2 = 2733456115UL,
        HASH_VALUE_ENGRAVINGMASKWIDTH = 2739498843UL,
        HASH_VALUE_SHELLLAYERSTART0 = 2743761755UL,
        HASH_VALUE_TRANSMITTANCELUTTEX = 2750529125UL,
        HASH_VALUE_WETNESS = 2772381270UL,
        HASH_VALUE_CONTROLFILTERA = 2778488803UL,
        HASH_VALUE_NEWFURSOFTEN0 = 2794467134UL,
        HASH_VALUE_MARKTAAGHOSTINGBIT = 2794671126UL,
        HASH_VALUE_RIVERFOAMTEXTURESCALE = 2803983290UL,
        HASH_VALUE_PXMSCALES1234 = 2818023055UL,
        HASH_VALUE_LYR1UVSCALE = 2827983715UL,
        HASH_VALUE_SPECULARCOLOR = 2844664387UL,
        HASH_VALUE_FURAOFURDEPTH0 = 2854249836UL,
        HASH_VALUE_LIVERYMATSELECTOR = 2873276402UL,
        HASH_VALUE_CONTROLFILTERB = 2917298287UL,
        HASH_VALUE_FURATTENCOEF0 = 2930156216UL,
        HASH_VALUE_DISTORTIONPARAMS = 2957679312UL,
        HASH_VALUE_SKINNEDTANGENTSDEF = 2962597709UL,
        HASH_VALUE_FURMINLAYERS0 = 2963734346UL,
        HASH_VALUE_MAXSPLATTEREND = 2966453587UL,
        HASH_VALUE_STANDARD_2LYR_PXM = 2987897443UL,
        HASH_VALUE_HBBRANGESCALE1234 = 2989726316UL,
        HASH_VALUE_LYR1FRESNEL = 2994468915UL,
        HASH_VALUE_ENGRAVINGINVERT = 3004929221UL,
        HASH_VALUE_COMBOHEIGHTTEXTUREFUR67 = 3024924133UL,
        HASH_VALUE_DETAILSETTINGS = 3038654095UL,
        HASH_VALUE_FURMAXLAYERS0 = 3051890872UL,
        HASH_VALUE_FRESNEL = 3053337291UL,
        HASH_VALUE_CALCBYSUNINTENSITY = 3072551032UL,
        HASH_VALUE_DECALTINT = 3092072610UL,
        HASH_VALUE_RIPPLEBUMPINESS = 3108440880UL,
        HASH_VALUE_LYR1MAXWETNESS = 3113086900UL,
        HASH_VALUE_CONTROLTEXTURETEXA = 3119824300UL,
        HASH_VALUE_FURAOBLEND0 = 3127197572UL,
        HASH_VALUE_FINFURBLUR0 = 3128352909UL,
        HASH_VALUE_CABLEAMBIENT = 3136851829UL,
        HASH_VALUE_LYR1POROSITY = 3151603165UL,
        HASH_VALUE_TREEHORIZONTALBENDEXP0 = 3157391136UL,
        HASH_VALUE_STANDARD = 3169861569UL,
        HASH_VALUE_STIPPLESAMPLER = 3178703610UL,
        HASH_VALUE_SMALLHDRCUBETEX = 3186294309UL,
        HASH_VALUE_ALBEDOPALETTETEX = 3218917814UL,
        HASH_VALUE_LOOKUPTEXTURE = 3228957110UL,
        HASH_VALUE_NIGHTONLY = 3232816545UL,
        HASH_VALUE_FURFINOPACITYADJUST0 = 3248130451UL,
        HASH_VALUE_WRINKLEAOSCALE = 3258382975UL,
        HASH_VALUE_TREEMMSCALE0 = 3259929556UL,
        HASH_VALUE_CALCBYAMBIENTINTENSITY = 3260732528UL,
        HASH_VALUE_BACKLIGHTINTENSITIES = 3273478655UL,
        HASH_VALUE_FURBENDWINDINFLUENCE0 = 3277953348UL,
        HASH_VALUE_FURPERVTXHACKLESSTIFFNESS0 = 3278413776UL,
        HASH_VALUE_PUSHSPHERESPREVIOUSFRAME = 3282958335UL,
        HASH_VALUE_PBRDETAIL_AO = 3300382745UL,
        HASH_VALUE_FURSELFSHADOWMIN0 = 3300543207UL,
        HASH_VALUE_SPECULARTEX = 3337907833UL,
        HASH_VALUE_CRACKDECALBUMPALPHATHRESHOLD = 3343925161UL,
        HASH_VALUE_LYR0ALBEDOMODIFIER = 3350066331UL,
        HASH_VALUE_PUSHPIVOTBUFFER = 3354152488UL,
        HASH_VALUE_SPECULARTEXTURE2 = 3354938678UL,
        HASH_VALUE_HEIGHTFILTER = 3356686918UL,
        HASH_VALUE_DIFFUSE2MODSPEC = 3361745559UL,
        HASH_VALUE_ENGRAVINGTEXTURETEX = 3366316709UL,
        HASH_VALUE_UVSCALEBIAS = 3368873060UL,
        HASH_VALUE_DIFFUSETEX = 3370697346UL,
        HASH_VALUE_DETAILSAMPLER = 3393362404UL,
        HASH_VALUE_TREEHORIZONTALBENDSCALE0 = 3398333057UL,
        HASH_VALUE_LYR0POROSITY = 3414224287UL,
        HASH_VALUE_BLENDSOFTNESS = 3418801587UL,
        HASH_VALUE_CRACKEDGEBUMPAMOUNT = 3420190257UL,
        HASH_VALUE_DIRTNOISETEX = 3423952715UL,
        HASH_VALUE_DETAILINDEXOVERRIDE = 3425693070UL,
        HASH_VALUE_DIRTVERTPUSHSCALE = 3429790123UL,
        HASH_VALUE_NEWFURFLUFFUP = 3430034301UL,
        HASH_VALUE_COMPUTEINSTANCEBUFFER = 3437639969UL,
        HASH_VALUE_TINYHDRTEX = 3456327479UL,
        HASH_VALUE_DIFFUSETEXTURE_LAYER0 = 3464205966UL,
        HASH_VALUE_DIRTTINTCHANNEL = 3481328283UL,
        HASH_VALUE_MOONDIRECTION = 3484629706UL,
        HASH_VALUE_WRINKLEMULTIPLIER = 3488678637UL,
        HASH_VALUE_NUMTARGETS = 3496712772UL,
        HASH_VALUE_HASWRINKLESWITCH = 3511370795UL,
        HASH_VALUE_AERIALPERSPECTIVESLICEDISTR = 3512658893UL,
        HASH_VALUE_FINCOMPRESSION0 = 3520970157UL,
        HASH_VALUE_POLLENLAYER = 3535034824UL,
        HASH_VALUE_GRASSNOISETILESCALE = 3547723408UL,
        HASH_VALUE_RIPPLESCALE = 3553443429UL,
        HASH_VALUE_STANDARD_DECAL_BLEND = 3558726851UL,
        HASH_VALUE_LYR0BUMPINESS = 3559851176UL,
        HASH_VALUE_ENABLENEARCAMERAFADE = 3576883040UL,
        HASH_VALUE_DAMAGESAMPLER = 3579349756UL,
        HASH_VALUE_EXPOSURETEXTURE = 3585646845UL,
        HASH_VALUE_PBRTWEAK_SHEEN = 3596981284UL,
        HASH_VALUE_FURBENDWINDMAXSPEEDCLAMP0 = 3612080476UL,
        HASH_VALUE_BUMPTEXTURE = 3619914305UL,
        HASH_VALUE_TRILINEARBORDERBLACK = 3627498220UL,
        HASH_VALUE_SOOTCOLOR = 3627506524UL,
        HASH_VALUE_CONTROLTEXTURETEXC = 3631741618UL,
        HASH_VALUE_PUDDLEHEIGHTBIAS = 3631959881UL,
        HASH_VALUE_DIFFUSETEXTURE_LAYER1 = 3632507550UL,
        HASH_VALUE_OPACITY = 3644411688UL,
        HASH_VALUE_PROJDECALTEXARRAYSAMPLER = 3650584368UL,
        HASH_VALUE_ENGRAVINGSHOW = 3650889374UL,
        HASH_VALUE_ENVEFFTEXTILEUV = 3670603239UL,
        HASH_VALUE_MAXWETNESS = 3676323074UL,
        HASH_VALUE_TINTINTENSITY = 3676759262UL,
        HASH_VALUE_TERRAINFRESNEL = 3678270110UL,
        HASH_VALUE_UMWINDSCALE0 = 3682298415UL,
        HASH_VALUE_DIRTUVSCALE = 3696288267UL,
        HASH_VALUE_BUMPTEXTURE_LAYER3 = 3733241873UL,
        HASH_VALUE_DISTORTIONTEXTURE = 3761808965UL,
        HASH_VALUE_FURFINLENGTHADJUST0 = 3769318642UL,
        HASH_VALUE_POLLENLAYER1 = 3773002910UL,
        HASH_VALUE_SUMGATHEREDLIGHTTEX = 3782896639UL,
        HASH_VALUE_LOOKINGGLASSDISTORTIONPARAMS = 3798180799UL,
        HASH_VALUE_SVERTSIN = 3811418824UL,
        HASH_VALUE_WINDMINMAXTHRESHHOLDS0 = 3828006041UL,
        HASH_VALUE_TRILINEARWRAP = 3829829819UL,
        HASH_VALUE_FINSTARTPOSITION0 = 3831314553UL,
        HASH_VALUE_COMBOHEIGHTTEXTUREFUR01 = 3838743980UL,
        HASH_VALUE_SPECSAMPLER2 = 3842658400UL,
        HASH_VALUE_FURBASETRANSLUCENCYADJ0 = 3845603062UL,
        HASH_VALUE_LYR1CAVITY = 3849620999UL,
        HASH_VALUE_PBRTWEAK_AO = 3884260641UL,
        HASH_VALUE_HARDALPHABLEND = 3913511942UL,
        HASH_VALUE_FOGCOLOR = 3922291195UL,
        HASH_VALUE_DIRTTILESCALE = 3923322695UL,
        HASH_VALUE_SPLATDIFFUSETEX = 3941437104UL,
        HASH_VALUE_CLAMPLOOKUPTEXTURE = 3945627717UL,
        HASH_VALUE_POLLENLAYER3 = 3963489107UL,
        HASH_VALUE_BLOOMMOD = 4001696098UL,
        HASH_VALUE_INTENSITY = 4023228733UL,
        HASH_VALUE_LYR1DETAILSETTINGS = 4026476543UL,
        HASH_VALUE_TINTOVERRIDE = 4035335077UL,
        HASH_VALUE_ASPECTRATIOS = 4036610552UL,
        HASH_VALUE_BATCHDISABLEDBITFIELD = 4038488897UL,
        HASH_VALUE_DIFFUSESAMPLER = 4059966321UL,
        HASH_VALUE_INVCONTROL = 4060669422UL,
        HASH_VALUE_LOOKUPUVSET = 4082432150UL,
        HASH_VALUE_DEPTHTEXTURE = 4088842947UL,
        HASH_VALUE_DETAILINDICES = 4092362441UL,
        HASH_VALUE_TREEVERTICALBENDSCALE0 = 4098862397UL,
        HASH_VALUE_CABLEDIFFUSE2 = 4100660380UL,
        HASH_VALUE_CONTROLUVSET = 4110446796UL,
        HASH_VALUE_MIXAMTCOL = 4129466014UL,
        HASH_VALUE_NEWFURALPHA0 = 4130512081UL,
        HASH_VALUE_FURPERVTXSTIFFNESS0 = 4133671217UL,
        HASH_VALUE_BUMPINESS = 4134611841UL,
        HASH_VALUE_FURALPHADISTANCE = 4141869331UL,
        HASH_VALUE_PLACEMENTTEXTURE = 4146843000UL,
        HASH_VALUE_HEIGHTTEXTURE = 4152773162UL,
        HASH_VALUE_CURRENTINSCATTERRM1 = 4166377038UL,
        HASH_VALUE_DETAILSETTINGS3 = 4180489302UL,
        HASH_VALUE_LYR1MATERIALBTEX = 4194584263UL,
        HASH_VALUE_FURLENGTH0 = 4194724638UL,
        HASH_VALUE_PUDDLEMASKSCALE = 4214762791UL,
        HASH_VALUE_FURMASKUSINGBLUETINT0 = 4229939749UL,
        HASH_VALUE_TREEMMSPEED0 = 4250925815UL,
        HASH_VALUE_TINTPALETTESELECTOR = 4258764495UL,
        HASH_VALUE_SPECMAPINTMASK = 4279333149UL,
        HASH_VALUE_FURALPHACLIP47 = 4280570754UL,
        HASH_VALUE_MATERIALBTEXTURE = 4289957077UL,
        HASH_VALUE_LYR1HEIGHTBIAS = 4292687236UL
    };

    enum vertex_layout_type_t {
        VERTEX_LAYOUT_TYPE_NONE = 0,
        VERTEX_LAYOUT_TYPE_POSITION = 6,
        VERTEX_LAYOUT_TYPE_TEXTURE = 16,
        VERTEX_LAYOUT_TYPE_NORMAL = 24,
        VERTEX_LAYOUT_TYPE_COLOR = 28
    };

    drawable_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, drawable_t* p__root = 0);

private:
    void _read();
    void _clean_up();

public:
    ~drawable_t();

    class embedded_t : public kaitai::kstruct {

    public:

        embedded_t(kaitai::kstream* p__io, drawable_t::texture_dict_t* p__parent = 0, drawable_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~embedded_t();

    private:
        uint32_t m_unk;
        std::string m_unk0;
        drawable_t* m__root;
        drawable_t::texture_dict_t* m__parent;

    public:
        uint32_t unk() const { return m_unk; }
        std::string unk0() const { return m_unk0; }
        drawable_t* _root() const { return m__root; }
        drawable_t::texture_dict_t* _parent() const { return m__parent; }
    };

    class uv_t : public kaitai::kstruct {

    public:

        uv_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, drawable_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~uv_t();

    private:
        float m_u;
        float m_v;
        drawable_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        float u() const { return m_u; }
        float v() const { return m_v; }
        drawable_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class vertex_t : public kaitai::kstruct {

    public:

        vertex_t(int32_t p_i, kaitai::kstream* p__io, drawable_t::vertex_data_t* p__parent = 0, drawable_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~vertex_t();

    private:
        bool f_type;
        vertex_layout_type_t m_type;

    public:
        vertex_layout_type_t type();

    private:
        bool f_data;
        kaitai::kstruct* m_data;
        bool n_data;

    public:
        bool _is_null_data() { data(); return n_data; };

    private:

    public:
        kaitai::kstruct* data();

    private:
        int32_t m_i;
        drawable_t* m__root;
        drawable_t::vertex_data_t* m__parent;
        std::string m__raw_data;
        bool n__raw_data;

    public:
        bool _is_null__raw_data() { _raw_data(); return n__raw_data; };

    private:
        kaitai::kstream* m__io__raw_data;

    public:
        int32_t i() const { return m_i; }
        drawable_t* _root() const { return m__root; }
        drawable_t::vertex_data_t* _parent() const { return m__parent; }
        std::string _raw_data() const { return m__raw_data; }
        kaitai::kstream* _io__raw_data() const { return m__io__raw_data; }
    };

    class float_list_t : public kaitai::kstruct {

    public:

        float_list_t(kaitai::kstream* p__io, drawable_t::vertex_t* p__parent = 0, drawable_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~float_list_t();

    private:
        std::vector<float>* m_data;
        drawable_t* m__root;
        drawable_t::vertex_t* m__parent;

    public:
        std::vector<float>* data() const { return m_data; }
        drawable_t* _root() const { return m__root; }
        drawable_t::vertex_t* _parent() const { return m__parent; }
    };

    class model_t : public kaitai::kstruct {

    public:

        model_t(kaitai::kstream* p__io, drawable_t::model_ptr_t* p__parent = 0, drawable_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~model_t();

    private:
        bool f_bound_count;
        int32_t m_bound_count;

    public:
        int32_t bound_count();

    private:
        bool f_geometry_list;
        std::vector<geometry_ptr_t*>* m_geometry_list;

    public:
        std::vector<geometry_ptr_t*>* geometry_list();

    private:
        bool f_bounds_list;
        std::vector<bounds_t*>* m_bounds_list;

    public:
        std::vector<bounds_t*>* bounds_list();

    private:
        bool f_shader_id;
        std::vector<uint16_t>* m_shader_id;

    public:
        std::vector<uint16_t>* shader_id();

    private:
        std::string m_unk0;
        ptr_t* m_loc_geometry_list;
        uint16_t m_geometry_count;
        uint16_t m_bound_count_raw;
        std::string m_unk1;
        ptr_t* m_loc_bounds_list;
        ptr_t* m_loc_shader_id;
        std::string m_unk2;
        drawable_t* m__root;
        drawable_t::model_ptr_t* m__parent;

    public:
        std::string unk0() const { return m_unk0; }
        ptr_t* loc_geometry_list() const { return m_loc_geometry_list; }
        uint16_t geometry_count() const { return m_geometry_count; }
        uint16_t bound_count_raw() const { return m_bound_count_raw; }
        std::string unk1() const { return m_unk1; }
        ptr_t* loc_bounds_list() const { return m_loc_bounds_list; }
        ptr_t* loc_shader_id() const { return m_loc_shader_id; }
        std::string unk2() const { return m_unk2; }
        drawable_t* _root() const { return m__root; }
        drawable_t::model_ptr_t* _parent() const { return m__parent; }
    };

    class shader_list_t : public kaitai::kstruct {

    public:

        shader_list_t(kaitai::kstream* p__io, drawable_t::shader_group_t* p__parent = 0, drawable_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~shader_list_t();

    private:
        bool f_shader;
        shader_t* m_shader;

    public:
        shader_t* shader();

    private:
        ptr_t* m_loc_shader;
        drawable_t* m__root;
        drawable_t::shader_group_t* m__parent;

    public:
        ptr_t* loc_shader() const { return m_loc_shader; }
        drawable_t* _root() const { return m__root; }
        drawable_t::shader_group_t* _parent() const { return m__parent; }
    };

    class rgba_t : public kaitai::kstruct {

    public:

        rgba_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, drawable_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~rgba_t();

    private:
        uint8_t m_r;
        uint8_t m_g;
        uint8_t m_b;
        uint8_t m_a;
        drawable_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        uint8_t r() const { return m_r; }
        uint8_t g() const { return m_g; }
        uint8_t b() const { return m_b; }
        uint8_t a() const { return m_a; }
        drawable_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class vertex_data_t : public kaitai::kstruct {

    public:

        vertex_data_t(kaitai::kstream* p__io, drawable_t::geometry_t* p__parent = 0, drawable_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~vertex_data_t();

    private:
        bool f_unknown_seq0;
        std::string m_unknown_seq0;

    public:
        std::string unknown_seq0();

    private:
        bool f_vertex_layout;
        vertex_layout_t* m_vertex_layout;

    public:
        vertex_layout_t* vertex_layout();

    private:
        bool f_verticies;
        std::vector<vertex_t*>* m_verticies;

    public:
        std::vector<vertex_t*>* verticies();

    private:
        std::string m_unk0;
        uint32_t m_vertex_count;
        std::string m_unk1;
        ptr_t* m_loc_vertecies;
        std::string m_unk2;
        ptr_t* m_unknown_ptr;
        ptr_t* m_loc_vertex_layout;
        drawable_t* m__root;
        drawable_t::geometry_t* m__parent;

    public:
        std::string unk0() const { return m_unk0; }
        uint32_t vertex_count() const { return m_vertex_count; }
        std::string unk1() const { return m_unk1; }
        ptr_t* loc_vertecies() const { return m_loc_vertecies; }
        std::string unk2() const { return m_unk2; }
        ptr_t* unknown_ptr() const { return m_unknown_ptr; }
        ptr_t* loc_vertex_layout() const { return m_loc_vertex_layout; }
        drawable_t* _root() const { return m__root; }
        drawable_t::geometry_t* _parent() const { return m__parent; }
    };

    class c_buffer_data_t : public kaitai::kstruct {

    public:

        c_buffer_data_t(kaitai::kstream* p__io, drawable_t::texture_info_t* p__parent = 0, drawable_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~c_buffer_data_t();

    private:
        bool f_loc_data;
        ptr_t* m_loc_data;

    public:
        ptr_t* loc_data();

    private:
        bool f_data;
        std::vector<float>* m_data;

    public:
        std::vector<float>* data();

    private:
        hash_t* m_hash;
        uint64_t m_flags;
        uint64_t m_buffer_id;
        uint64_t m_offset;
        uint64_t m_length;
        drawable_t* m__root;
        drawable_t::texture_info_t* m__parent;

    public:
        hash_t* hash() const { return m_hash; }
        uint64_t flags() const { return m_flags; }
        uint64_t buffer_id() const { return m_buffer_id; }
        uint64_t offset() const { return m_offset; }
        uint64_t length() const { return m_length; }
        drawable_t* _root() const { return m__root; }
        drawable_t::texture_info_t* _parent() const { return m__parent; }
    };

    class normal_list_t : public kaitai::kstruct {

    public:

        normal_list_t(kaitai::kstream* p__io, drawable_t::vertex_t* p__parent = 0, drawable_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~normal_list_t();

    private:
        std::vector<normals_t*>* m_data;
        drawable_t* m__root;
        drawable_t::vertex_t* m__parent;

    public:
        std::vector<normals_t*>* data() const { return m_data; }
        drawable_t* _root() const { return m__root; }
        drawable_t::vertex_t* _parent() const { return m__parent; }
    };

    class vertex_layout_t : public kaitai::kstruct {

    public:

        vertex_layout_t(kaitai::kstream* p__io, drawable_t::vertex_data_t* p__parent = 0, drawable_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~vertex_layout_t();

    private:
        std::vector<uint32_t>* m_offsets;
        std::vector<uint8_t>* m_size;
        std::vector<vertex_layout_type_t>* m_type;
        std::string m_unk0;
        drawable_t* m__root;
        drawable_t::vertex_data_t* m__parent;

    public:
        std::vector<uint32_t>* offsets() const { return m_offsets; }
        std::vector<uint8_t>* size() const { return m_size; }
        std::vector<vertex_layout_type_t>* type() const { return m_type; }
        std::string unk0() const { return m_unk0; }
        drawable_t* _root() const { return m__root; }
        drawable_t::vertex_data_t* _parent() const { return m__parent; }
    };

    class bounds_t : public kaitai::kstruct {

    public:

        bounds_t(kaitai::kstream* p__io, drawable_t::model_t* p__parent = 0, drawable_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~bounds_t();

    private:
        xyz_t* m_bb_min;
        std::string m_unk0;
        xyz_t* m_bb_max;
        std::string m_unk1;
        drawable_t* m__root;
        drawable_t::model_t* m__parent;

    public:
        xyz_t* bb_min() const { return m_bb_min; }
        std::string unk0() const { return m_unk0; }
        xyz_t* bb_max() const { return m_bb_max; }
        std::string unk1() const { return m_unk1; }
        drawable_t* _root() const { return m__root; }
        drawable_t::model_t* _parent() const { return m__parent; }
    };

    class hash_t : public kaitai::kstruct {

    public:

        hash_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, drawable_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~hash_t();

    private:
        hash_value_t m_hash_value;
        drawable_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        hash_value_t hash_value() const { return m_hash_value; }
        drawable_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class shader_group_t : public kaitai::kstruct {

    public:

        shader_group_t(kaitai::kstream* p__io, drawable_t* p__parent = 0, drawable_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~shader_group_t();

    private:
        bool f_texture_dict;
        texture_dict_t* m_texture_dict;
        bool n_texture_dict;

    public:
        bool _is_null_texture_dict() { texture_dict(); return n_texture_dict; };

    private:

    public:
        texture_dict_t* texture_dict();

    private:
        bool f_shader_list;
        std::vector<shader_list_t*>* m_shader_list;

    public:
        std::vector<shader_list_t*>* shader_list();

    private:
        std::string m_unk0;
        ptr_t* m_loc_texture_dict;
        ptr_t* m_loc_shader_list;
        uint16_t m_shader_count;
        uint16_t m_count_0;
        std::string m_unk1;
        drawable_t* m__root;
        drawable_t* m__parent;

    public:
        std::string unk0() const { return m_unk0; }
        ptr_t* loc_texture_dict() const { return m_loc_texture_dict; }
        ptr_t* loc_shader_list() const { return m_loc_shader_list; }
        uint16_t shader_count() const { return m_shader_count; }
        uint16_t count_0() const { return m_count_0; }
        std::string unk1() const { return m_unk1; }
        drawable_t* _root() const { return m__root; }
        drawable_t* _parent() const { return m__parent; }
    };

    class normals_t : public kaitai::kstruct {

    public:

        normals_t(kaitai::kstream* p__io, drawable_t::normal_list_t* p__parent = 0, drawable_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~normals_t();

    private:
        bool f_x;
        double m_x;

    public:
        double x();

    private:
        bool f_y;
        double m_y;

    public:
        double y();

    private:
        bool f_y_real;
        double m_y_real;

    public:
        double y_real();

    private:
        bool f_x_real;
        double m_x_real;

    public:
        double x_real();

    private:
        bool f_z;
        double m_z;

    public:
        double z();

    private:
        bool f_z_real;
        double m_z_real;

    public:
        double z_real();

    private:
        uint64_t m_x_raw;
        uint64_t m_y_raw;
        uint64_t m_z_raw;
        uint64_t m_w;
        drawable_t* m__root;
        drawable_t::normal_list_t* m__parent;

    public:
        uint64_t x_raw() const { return m_x_raw; }
        uint64_t y_raw() const { return m_y_raw; }
        uint64_t z_raw() const { return m_z_raw; }
        uint64_t w() const { return m_w; }
        drawable_t* _root() const { return m__root; }
        drawable_t::normal_list_t* _parent() const { return m__parent; }
    };

    class xyz_t : public kaitai::kstruct {

    public:

        xyz_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, drawable_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~xyz_t();

    private:
        float m_x;
        float m_y;
        float m_z;
        drawable_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        float x() const { return m_x; }
        float y() const { return m_y; }
        float z() const { return m_z; }
        drawable_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class model_ptr_t : public kaitai::kstruct {

    public:

        model_ptr_t(kaitai::kstream* p__io, drawable_t::models_t* p__parent = 0, drawable_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~model_ptr_t();

    private:
        bool f_model;
        model_t* m_model;

    public:
        model_t* model();

    private:
        ptr_t* m_loc_model;
        drawable_t* m__root;
        drawable_t::models_t* m__parent;

    public:
        ptr_t* loc_model() const { return m_loc_model; }
        drawable_t* _root() const { return m__root; }
        drawable_t::models_t* _parent() const { return m__parent; }
    };

    class models_t : public kaitai::kstruct {

    public:

        models_t(kaitai::kstream* p__io, drawable_t* p__parent = 0, drawable_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~models_t();

    private:
        bool f_model_list;
        std::vector<model_ptr_t*>* m_model_list;

    public:
        std::vector<model_ptr_t*>* model_list();

    private:
        ptr_t* m_loc_model_list;
        uint16_t m_model_count;
        uint16_t m_count_0;
        std::string m_unk0;
        drawable_t* m__root;
        drawable_t* m__parent;

    public:
        ptr_t* loc_model_list() const { return m_loc_model_list; }
        uint16_t model_count() const { return m_model_count; }
        uint16_t count_0() const { return m_count_0; }
        std::string unk0() const { return m_unk0; }
        drawable_t* _root() const { return m__root; }
        drawable_t* _parent() const { return m__parent; }
    };

    class texture_info_t : public kaitai::kstruct {

    public:

        texture_info_t(kaitai::kstream* p__io, drawable_t::shader_t* p__parent = 0, drawable_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~texture_info_t();

    private:
        uint8_t m_unk0;
        uint8_t m_texture_count;
        uint8_t m_unk1;
        uint8_t m_sampler_count;
        uint32_t m_all_count;
        std::vector<texture_data_t*>* m_texture_data;
        std::vector<sampler_data_t*>* m_sampler_data;
        std::vector<c_buffer_data_t*>* m_c_buffer_data;
        drawable_t* m__root;
        drawable_t::shader_t* m__parent;

    public:
        uint8_t unk0() const { return m_unk0; }
        uint8_t texture_count() const { return m_texture_count; }
        uint8_t unk1() const { return m_unk1; }
        uint8_t sampler_count() const { return m_sampler_count; }
        uint32_t all_count() const { return m_all_count; }
        std::vector<texture_data_t*>* texture_data() const { return m_texture_data; }
        std::vector<sampler_data_t*>* sampler_data() const { return m_sampler_data; }
        std::vector<c_buffer_data_t*>* c_buffer_data() const { return m_c_buffer_data; }
        drawable_t* _root() const { return m__root; }
        drawable_t::shader_t* _parent() const { return m__parent; }
    };

    class texture_dict_t : public kaitai::kstruct {

    public:

        texture_dict_t(kaitai::kstream* p__io, drawable_t::shader_group_t* p__parent = 0, drawable_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~texture_dict_t();

    private:
        bool f_embedded;
        embedded_t* m_embedded;
        bool n_embedded;

    public:
        bool _is_null_embedded() { embedded(); return n_embedded; };

    private:

    public:
        embedded_t* embedded();

    private:
        bool f_textures;
        std::vector<textures_t*>* m_textures;
        bool n_textures;

    public:
        bool _is_null_textures() { textures(); return n_textures; };

    private:

    public:
        std::vector<textures_t*>* textures();

    private:
        std::string m_unk0;
        ptr_t* m_loc_embedded;
        uint16_t m_count_0;
        uint16_t m_count_1;
        std::string m_unk1;
        ptr_t* m_loc_textures;
        uint16_t m_texture_count;
        uint16_t m_count_3;
        drawable_t* m__root;
        drawable_t::shader_group_t* m__parent;

    public:
        std::string unk0() const { return m_unk0; }
        ptr_t* loc_embedded() const { return m_loc_embedded; }
        uint16_t count_0() const { return m_count_0; }
        uint16_t count_1() const { return m_count_1; }
        std::string unk1() const { return m_unk1; }
        ptr_t* loc_textures() const { return m_loc_textures; }
        uint16_t texture_count() const { return m_texture_count; }
        uint16_t count_3() const { return m_count_3; }
        drawable_t* _root() const { return m__root; }
        drawable_t::shader_group_t* _parent() const { return m__parent; }
    };

    class shader_t : public kaitai::kstruct {

    public:

        shader_t(kaitai::kstream* p__io, drawable_t::shader_list_t* p__parent = 0, drawable_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~shader_t();

    private:
        bool f_texture_info;
        texture_info_t* m_texture_info;

    public:
        texture_info_t* texture_info();

    private:
        hash_t* m_shader_type;
        std::string m_unk0;
        ptr_t* m_loc_c_buffer;
        ptr_t* m_loc_textures;
        std::string m_unk1;
        ptr_t* m_loc_sampler;
        std::string m_unk2;
        std::string m_unk3;
        drawable_t* m__root;
        drawable_t::shader_list_t* m__parent;

    public:
        hash_t* shader_type() const { return m_shader_type; }
        std::string unk0() const { return m_unk0; }
        ptr_t* loc_c_buffer() const { return m_loc_c_buffer; }
        ptr_t* loc_textures() const { return m_loc_textures; }
        std::string unk1() const { return m_unk1; }
        ptr_t* loc_sampler() const { return m_loc_sampler; }
        std::string unk2() const { return m_unk2; }
        std::string unk3() const { return m_unk3; }
        drawable_t* _root() const { return m__root; }
        drawable_t::shader_list_t* _parent() const { return m__parent; }
    };

    class ptr_t : public kaitai::kstruct {

    public:

        ptr_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, drawable_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~ptr_t();

    private:
        bool f_addr;
        int32_t m_addr;

    public:
        int32_t addr();

    private:
        uint8_t m_byte0;
        uint8_t m_byte1;
        uint8_t m_byte2;
        uint8_t m_byte0x50;
        uint32_t m_reserved;
        drawable_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        uint8_t byte0() const { return m_byte0; }
        uint8_t byte1() const { return m_byte1; }
        uint8_t byte2() const { return m_byte2; }
        uint8_t byte0x50() const { return m_byte0x50; }
        uint32_t reserved() const { return m_reserved; }
        drawable_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class textures_t : public kaitai::kstruct {

    public:

        textures_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, drawable_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~textures_t();

    private:
        bool f_texture;
        texture_t* m_texture;
        bool n_texture;

    public:
        bool _is_null_texture() { texture(); return n_texture; };

    private:

    public:
        texture_t* texture();

    private:
        ptr_t* m_loc_texture;
        drawable_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        ptr_t* loc_texture() const { return m_loc_texture; }
        drawable_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class indicies_data_t : public kaitai::kstruct {

    public:

        indicies_data_t(kaitai::kstream* p__io, drawable_t::geometry_t* p__parent = 0, drawable_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~indicies_data_t();

    private:
        bool f_indicies;
        std::vector<uint16_t>* m_indicies;

    public:
        std::vector<uint16_t>* indicies();

    private:
        bool f_unknown_seq0;
        std::string m_unknown_seq0;

    public:
        std::string unknown_seq0();

    private:
        std::string m_unk0;
        uint32_t m_indecies_count;
        std::string m_unk1;
        ptr_t* m_loc_indicies;
        std::string m_unk2;
        ptr_t* m_loc_p1;
        std::string m_unk3;
        drawable_t* m__root;
        drawable_t::geometry_t* m__parent;

    public:
        std::string unk0() const { return m_unk0; }
        uint32_t indecies_count() const { return m_indecies_count; }
        std::string unk1() const { return m_unk1; }
        ptr_t* loc_indicies() const { return m_loc_indicies; }
        std::string unk2() const { return m_unk2; }
        ptr_t* loc_p1() const { return m_loc_p1; }
        std::string unk3() const { return m_unk3; }
        drawable_t* _root() const { return m__root; }
        drawable_t::geometry_t* _parent() const { return m__parent; }
    };

    class sampler_data_t : public kaitai::kstruct {

    public:

        sampler_data_t(int32_t p_i, kaitai::kstream* p__io, drawable_t::texture_info_t* p__parent = 0, drawable_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~sampler_data_t();

    private:
        bool f_sampler_id;
        uint8_t m_sampler_id;

    public:
        uint8_t sampler_id();

    private:
        hash_t* m_hash;
        uint64_t m_flag;
        uint64_t m_index;
        int32_t m_i;
        drawable_t* m__root;
        drawable_t::texture_info_t* m__parent;

    public:
        hash_t* hash() const { return m_hash; }
        uint64_t flag() const { return m_flag; }
        uint64_t index() const { return m_index; }
        int32_t i() const { return m_i; }
        drawable_t* _root() const { return m__root; }
        drawable_t::texture_info_t* _parent() const { return m__parent; }
    };

    class byte_list_t : public kaitai::kstruct {

    public:

        byte_list_t(kaitai::kstream* p__io, drawable_t::vertex_t* p__parent = 0, drawable_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~byte_list_t();

    private:
        std::vector<uint8_t>* m_data;
        drawable_t* m__root;
        drawable_t::vertex_t* m__parent;

    public:
        std::vector<uint8_t>* data() const { return m_data; }
        drawable_t* _root() const { return m__root; }
        drawable_t::vertex_t* _parent() const { return m__parent; }
    };

    class texture_t : public kaitai::kstruct {

    public:

        texture_t(kaitai::kstream* p__io, drawable_t::textures_t* p__parent = 0, drawable_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~texture_t();

    private:
        bool f_name;
        std::string m_name;

    public:
        std::string name();

    private:
        bool f_l1;
        std::string m_l1;
        bool n_l1;

    public:
        bool _is_null_l1() { l1(); return n_l1; };

    private:

    public:
        std::string l1();

    private:
        std::string m_unk0;
        uint32_t m_flag;
        std::string m_unk1;
        ptr_t* m_loc_name;
        ptr_t* m_loc_unk2;
        drawable_t* m__root;
        drawable_t::textures_t* m__parent;

    public:
        std::string unk0() const { return m_unk0; }
        uint32_t flag() const { return m_flag; }
        std::string unk1() const { return m_unk1; }
        ptr_t* loc_name() const { return m_loc_name; }
        ptr_t* loc_unk2() const { return m_loc_unk2; }
        drawable_t* _root() const { return m__root; }
        drawable_t::textures_t* _parent() const { return m__parent; }
    };

    class geometry_t : public kaitai::kstruct {

    public:

        geometry_t(kaitai::kstream* p__io, drawable_t::geometry_ptr_t* p__parent = 0, drawable_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~geometry_t();

    private:
        bool f_vertex_data;
        vertex_data_t* m_vertex_data;

    public:
        vertex_data_t* vertex_data();

    private:
        bool f_indicies_data;
        indicies_data_t* m_indicies_data;

    public:
        indicies_data_t* indicies_data();

    private:
        std::string m_unk0;
        ptr_t* m_loc_vertex_data;
        ptr_t* m_loc_indicies_data;
        std::string m_unk1;
        drawable_t* m__root;
        drawable_t::geometry_ptr_t* m__parent;

    public:
        std::string unk0() const { return m_unk0; }
        ptr_t* loc_vertex_data() const { return m_loc_vertex_data; }
        ptr_t* loc_indicies_data() const { return m_loc_indicies_data; }
        std::string unk1() const { return m_unk1; }
        drawable_t* _root() const { return m__root; }
        drawable_t::geometry_ptr_t* _parent() const { return m__parent; }
    };

    class texture_data_t : public kaitai::kstruct {

    public:

        texture_data_t(kaitai::kstream* p__io, drawable_t::texture_info_t* p__parent = 0, drawable_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~texture_data_t();

    private:
        bool f_textures;
        textures_t* m_textures;

    public:
        textures_t* textures();

    private:
        hash_t* m_hash;
        uint64_t m_flag;
        uint64_t m_index;
        drawable_t* m__root;
        drawable_t::texture_info_t* m__parent;

    public:
        hash_t* hash() const { return m_hash; }
        uint64_t flag() const { return m_flag; }
        uint64_t index() const { return m_index; }
        drawable_t* _root() const { return m__root; }
        drawable_t::texture_info_t* _parent() const { return m__parent; }
    };

    class geometry_ptr_t : public kaitai::kstruct {

    public:

        geometry_ptr_t(kaitai::kstream* p__io, drawable_t::model_t* p__parent = 0, drawable_t* p__root = 0);

    private:
        void _read();
        void _clean_up();

    public:
        ~geometry_ptr_t();

    private:
        bool f_geometry;
        geometry_t* m_geometry;

    public:
        geometry_t* geometry();

    private:
        ptr_t* m_loc_geometry;
        drawable_t* m__root;
        drawable_t::model_t* m__parent;

    public:
        ptr_t* loc_geometry() const { return m_loc_geometry; }
        drawable_t* _root() const { return m__root; }
        drawable_t::model_t* _parent() const { return m__parent; }
    };

private:
    bool f_lod_h;
    models_t* m_lod_h;
    bool n_lod_h;

public:
    bool _is_null_lod_h() { lod_h(); return n_lod_h; };

private:

public:
    models_t* lod_h();

private:
    bool f_lod_v;
    models_t* m_lod_v;
    bool n_lod_v;

public:
    bool _is_null_lod_v() { lod_v(); return n_lod_v; };

private:

public:
    models_t* lod_v();

private:
    bool f_ptr_some;
    std::string m_ptr_some;

public:
    std::string ptr_some();

private:
    bool f_lod_m;
    models_t* m_lod_m;
    bool n_lod_m;

public:
    bool _is_null_lod_m() { lod_m(); return n_lod_m; };

private:

public:
    models_t* lod_m();

private:
    bool f_name;
    std::string m_name;

public:
    std::string name();

private:
    bool f_shader_group;
    shader_group_t* m_shader_group;

public:
    shader_group_t* shader_group();

private:
    bool f_lod_l;
    models_t* m_lod_l;
    bool n_lod_l;

public:
    bool _is_null_lod_l() { lod_l(); return n_lod_l; };

private:

public:
    models_t* lod_l();

private:
    std::string m_unknown0;
    ptr_t* m_loc_some;
    ptr_t* m_loc_shader_group;
    std::string m_unknown1;
    xyz_t* m_bounding_sphere_center;
    float m_bounding_sphere_radius;
    xyz_t* m_bounding_box_min;
    std::string m_unknown2;
    xyz_t* m_bounding_box_max;
    std::string m_unknown3;
    ptr_t* m_loc_lod_h;
    ptr_t* m_loc_lod_m;
    ptr_t* m_loc_lod_l;
    ptr_t* m_loc_lod_v;
    std::vector<uint32_t>* m_lod_distance;
    std::vector<uint32_t>* m_lod_flags;
    std::string m_unknown4;
    ptr_t* m_loc_name;
    std::string m_unknown5;
    drawable_t* m__root;
    kaitai::kstruct* m__parent;

public:
    std::string unknown0() const { return m_unknown0; }
    ptr_t* loc_some() const { return m_loc_some; }
    ptr_t* loc_shader_group() const { return m_loc_shader_group; }
    std::string unknown1() const { return m_unknown1; }
    xyz_t* bounding_sphere_center() const { return m_bounding_sphere_center; }
    float bounding_sphere_radius() const { return m_bounding_sphere_radius; }
    xyz_t* bounding_box_min() const { return m_bounding_box_min; }
    std::string unknown2() const { return m_unknown2; }
    xyz_t* bounding_box_max() const { return m_bounding_box_max; }
    std::string unknown3() const { return m_unknown3; }
    ptr_t* loc_lod_h() const { return m_loc_lod_h; }
    ptr_t* loc_lod_m() const { return m_loc_lod_m; }
    ptr_t* loc_lod_l() const { return m_loc_lod_l; }
    ptr_t* loc_lod_v() const { return m_loc_lod_v; }
    std::vector<uint32_t>* lod_distance() const { return m_lod_distance; }
    std::vector<uint32_t>* lod_flags() const { return m_lod_flags; }
    std::string unknown4() const { return m_unknown4; }
    ptr_t* loc_name() const { return m_loc_name; }
    std::string unknown5() const { return m_unknown5; }
    drawable_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // DRAWABLE_H_
