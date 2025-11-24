
#include "utility.hpp"

bool utility::CompileShader(GLuint shader, const char* filename) {
		std::ifstream stream(filename);
		if (stream.fail()) {
			std::cerr << "Error opening file " << filename << std::endl;
			return false;
		}
		std::string shaderSource((std::istreambuf_iterator<char>(stream)),
			std::istreambuf_iterator<char>());
		stream.close();

		const GLchar* source[]{ shaderSource.c_str() };

		glShaderSource(shader, 1, source, nullptr);
		glCompileShader(shader);

		GLint status = 0;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
		if (status == GL_FALSE) {
			GLint logSize = 0;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logSize);
			std::vector<GLchar> infoLog;
			infoLog.resize(logSize);
			glGetShaderInfoLog(shader, logSize, &logSize, &infoLog[0]);

			std::cerr << "Error compiling shader code from file " <<
				filename << ": " << std::endl;
			std::cerr << infoLog.data() << std::endl;

			return false;
		}
		return true;
	}

	bool utility::LinkShaderProgram(GLuint program) {
		GLint status = 0;
		glLinkProgram(program);
		glGetProgramiv(program, GL_LINK_STATUS, &status);
		if (status == GL_FALSE) {
			GLint logSize = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logSize);
			std::vector<GLchar> infoLog;
			infoLog.resize(logSize);
			glGetProgramInfoLog(program, logSize, &logSize, &infoLog[0]);

			std::cerr << "Error linking shader program (handle " << program << "): " << std::endl;
			std::cerr << infoLog.data() << std::endl;

			return false;
		}
		return true;
	}

	void utility::PrintOpenGLInformation() {
		std::cout << "OpenGL Vendor: " << glGetString(GL_VENDOR) << std::endl;
		std::cout << "OpenGL Renderer: " << glGetString(GL_RENDERER) << std::endl;
		std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
		std::cout << "GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
	}

    drawable_t* utility::loadYDR(std::string filename){
        std::ifstream* is = new std::ifstream(filename, std::ifstream::binary);
        kaitai::kstream* ks = new kaitai::kstream(is);
        return new drawable_t(ks);
    }

	//https://github.com/g-truc/gli/tree/master
	GLuint utility::CreateTexture(char const* Filename)
	{
		gli::texture Texture = gli::load(Filename);
		if(Texture.empty())
			return 0;

		gli::gl GL(gli::gl::PROFILE_GL33);
		gli::gl::format const Format = GL.translate(Texture.format(), Texture.swizzles());
		GLenum Target = GL.translate(Texture.target());
		assert(Texture.target() == gli::TARGET_2D);
		glm::tvec3<GLsizei> const Extent(Texture.extent());
		

		GLuint TextureName = 0;
		glGenTextures(1, &TextureName);
		glBindTexture(Target, TextureName);
		if(!gli::is_compressed(Texture.format())){
			GLuint TextureName = 0;
			glGenTextures(1, &TextureName);
			glBindTexture(Target, TextureName);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);	
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexImage2D(GL_TEXTURE_2D, 0, Format.Internal, Extent.x, Extent.y, 0, Format.External, Format.Type, Texture.data(0, 0, 0));
			return TextureName;
		}
		glTexParameteri(Target, GL_TEXTURE_BASE_LEVEL, 0);
		glTexParameteri(Target, GL_TEXTURE_MAX_LEVEL, static_cast<GLint>(Texture.levels() - 1));
		glTexParameteriv(Target, GL_TEXTURE_SWIZZLE_RGBA, &Format.Swizzles[0]);
		glTexStorage2D(Target, static_cast<GLint>(Texture.levels()), Format.Internal, Extent.x, Extent.y);
		for(std::size_t Level = 0; Level < Texture.levels(); ++Level)
		{
			glm::tvec3<GLsizei> Extent(Texture.extent(Level));
			glCompressedTexSubImage2D(
				Target, static_cast<GLint>(Level), 0, 0, Extent.x, Extent.y,
				Format.Internal, static_cast<GLsizei>(Texture.size(Level)), Texture.data(0, 0, Level));
		}

		return TextureName;
	}

std::map<drawable_t::hash_value_t, std::string> utility::hashToString = {
	{drawable_t::hash_value_t::HASH_VALUE_SOOTROUGHNESS, "SOOTROUGHNESS"},
	{drawable_t::hash_value_t::HASH_VALUE_STANDARD_EMISSIVE, "STANDARD_EMISSIVE"},
	{drawable_t::hash_value_t::HASH_VALUE_USEWORLDSPACENORMALS, "USEWORLDSPACENORMALS"},
	{drawable_t::hash_value_t::HASH_VALUE_CALCBYAMBIENTCOL, "CALCBYAMBIENTCOL"},
	{drawable_t::hash_value_t::HASH_VALUE_CURRENTINSCATTERRM2, "CURRENTINSCATTERRM2"},
	{drawable_t::hash_value_t::HASH_VALUE_ENGRAVINGSELFSHADOWAMT, "ENGRAVINGSELFSHADOWAMT"},
	{drawable_t::hash_value_t::HASH_VALUE_HBBRANGEBIAS1234, "HBBRANGEBIAS1234"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR1HEIGHTSCALE, "LYR1HEIGHTSCALE"},
	{drawable_t::hash_value_t::HASH_VALUE_POLLENLAYERPLACEMENT, "POLLENLAYERPLACEMENT"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR0HEIGHTSCALE, "LYR0HEIGHTSCALE"},
	{drawable_t::hash_value_t::HASH_VALUE_HASPUDDLESWITCH, "HASPUDDLESWITCH"},
	{drawable_t::hash_value_t::HASH_VALUE_STIPPLETEXTURE, "STIPPLETEXTURE"},
	{drawable_t::hash_value_t::HASH_VALUE_HASCLOTHSWITCH, "HASCLOTHSWITCH"},
	{drawable_t::hash_value_t::HASH_VALUE_DETAILSETTINGS2, "DETAILSETTINGS2"},
	{drawable_t::hash_value_t::HASH_VALUE_PUSHSPHERES, "PUSHSPHERES"},
	{drawable_t::hash_value_t::HASH_VALUE_BLOODFLOWMASK, "BLOODFLOWMASK"},
	{drawable_t::hash_value_t::HASH_VALUE_WRINKLEFADEINSTART, "WRINKLEFADEINSTART"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR0TRANSLUCENCY, "LYR0TRANSLUCENCY"},
	{drawable_t::hash_value_t::HASH_VALUE_USEFAKECUTOUT, "USEFAKECUTOUT"},
	{drawable_t::hash_value_t::HASH_VALUE_DIRTUVSET, "DIRTUVSET"},
	{drawable_t::hash_value_t::HASH_VALUE_SPLATNMRTEX, "SPLATNMRTEX"},
	{drawable_t::hash_value_t::HASH_VALUE_DECALBLENDOPACITYGBUFFER0, "DECALBLENDOPACITYGBUFFER0"},
	{drawable_t::hash_value_t::HASH_VALUE_WRINKLEBASEFADEOUTEND, "WRINKLEBASEFADEOUTEND"},
	{drawable_t::hash_value_t::HASH_VALUE_DETAILTEXARRAYN, "DETAILTEXARRAYN"},
	{drawable_t::hash_value_t::HASH_VALUE_MATERIALMAPATEXTURE_LAYER2, "MATERIALMAPATEXTURE_LAYER2"},
	{drawable_t::hash_value_t::HASH_VALUE_GBUFFERTEXTURE1, "GBUFFERTEXTURE1"},
	{drawable_t::hash_value_t::HASH_VALUE_DIFFUSETEX2, "DIFFUSETEX2"},
	{drawable_t::hash_value_t::HASH_VALUE_CONTROLTILEAMOUNT, "CONTROLTILEAMOUNT"},
	{drawable_t::hash_value_t::HASH_VALUE_FINLAYERCOMPENSATION0, "FINLAYERCOMPENSATION0"},
	{drawable_t::hash_value_t::HASH_VALUE_PARALLAXSELFSHADOWAMOUNT, "PARALLAXSELFSHADOWAMOUNT"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR0FRESNEL, "LYR0FRESNEL"},
	{drawable_t::hash_value_t::HASH_VALUE_MAXMUDINTENSITY, "MAXMUDINTENSITY"},
	{drawable_t::hash_value_t::HASH_VALUE_COMBOHEIGHTTEXTUREFUR23, "COMBOHEIGHTTEXTUREFUR23"},
	{drawable_t::hash_value_t::HASH_VALUE_FURALPHACLIP03, "FURALPHACLIP03"},
	{drawable_t::hash_value_t::HASH_VALUE_HEIGHTBIAS, "HEIGHTBIAS"},
	{drawable_t::hash_value_t::HASH_VALUE_UMPEDWINDEXPONENT0, "UMPEDWINDEXPONENT0"},
	{drawable_t::hash_value_t::HASH_VALUE_UMWINDEXPONENT0, "UMWINDEXPONENT0"},
	{drawable_t::hash_value_t::HASH_VALUE_RUSTNOISETEX, "RUSTNOISETEX"},
	{drawable_t::hash_value_t::HASH_VALUE_TRILINEARCLAMP, "TRILINEARCLAMP"},
	{drawable_t::hash_value_t::HASH_VALUE_DETAILSETTINGS1, "DETAILSETTINGS1"},
	{drawable_t::hash_value_t::HASH_VALUE_OCCLUSIONTEX, "OCCLUSIONTEX"},
	{drawable_t::hash_value_t::HASH_VALUE_POLLENEXISTENCE, "POLLENEXISTENCE"},
	{drawable_t::hash_value_t::HASH_VALUE_POLLENLAYER2, "POLLENLAYER2"},
	{drawable_t::hash_value_t::HASH_VALUE_TINTBUMPTEXTURE, "TINTBUMPTEXTURE"},
	{drawable_t::hash_value_t::HASH_VALUE_PBRDETAIL_SHEEN, "PBRDETAIL_SHEEN"},
	{drawable_t::hash_value_t::HASH_VALUE_COMPUTEDATABUFFER, "COMPUTEDATABUFFER"},
	{drawable_t::hash_value_t::HASH_VALUE_PBRTWEAK_DETAIL, "PBRTWEAK_DETAIL"},
	{drawable_t::hash_value_t::HASH_VALUE_PBRTWEAK_DETAILINDEX_, "PBRTWEAK_DETAILINDEX_"},
	{drawable_t::hash_value_t::HASH_VALUE_TINTBLENDAMOUNT, "TINTBLENDAMOUNT"},
	{drawable_t::hash_value_t::HASH_VALUE_TEXTURESAMP, "TEXTURESAMP"},
	{drawable_t::hash_value_t::HASH_VALUE_CRACKEDGEBUMPTILESCALE, "CRACKEDGEBUMPTILESCALE"},
	{drawable_t::hash_value_t::HASH_VALUE_ENGRAVINGSECONDAYTEXTURE, "ENGRAVINGSECONDAYTEXTURE"},
	{drawable_t::hash_value_t::HASH_VALUE_ANISOTROPICSPECULAREXPONENT, "ANISOTROPICSPECULAREXPONENT"},
	{drawable_t::hash_value_t::HASH_VALUE_FIXEDGATHEREDLIGHTTEX, "FIXEDGATHEREDLIGHTTEX"},
	{drawable_t::hash_value_t::HASH_VALUE_BUMPTEX, "BUMPTEX"},
	{drawable_t::hash_value_t::HASH_VALUE_BATCHCOMPUTEPARAMSBUFFER, "BATCHCOMPUTEPARAMSBUFFER"},
	{drawable_t::hash_value_t::HASH_VALUE_ENGRAVINGSHOWMATERIAL, "ENGRAVINGSHOWMATERIAL"},
	{drawable_t::hash_value_t::HASH_VALUE_BLENDAMTINTENSITY, "BLENDAMTINTENSITY"},
	{drawable_t::hash_value_t::HASH_VALUE_WRINKLEBUMPSCALE, "WRINKLEBUMPSCALE"},
	{drawable_t::hash_value_t::HASH_VALUE_GCSMSHADOWTEXTURESAMP, "GCSMSHADOWTEXTURESAMP"},
	{drawable_t::hash_value_t::HASH_VALUE_BLENDAMTCOL, "BLENDAMTCOL"},
	{drawable_t::hash_value_t::HASH_VALUE_FADEEXPONENT, "FADEEXPONENT"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR1TILEAMOUNT, "LYR1TILEAMOUNT"},
	{drawable_t::hash_value_t::HASH_VALUE_ROUGHNESSBASEDONALBEDO, "ROUGHNESSBASEDONALBEDO"},
	{drawable_t::hash_value_t::HASH_VALUE_DETAILSETTINGS0, "DETAILSETTINGS0"},
	{drawable_t::hash_value_t::HASH_VALUE_ONOFFTIMES, "ONOFFTIMES"},
	{drawable_t::hash_value_t::HASH_VALUE_MAXSHOWSPLATTERTEX, "MAXSHOWSPLATTERTEX"},
	{drawable_t::hash_value_t::HASH_VALUE_BUMPTEXTURE_LAYER0, "BUMPTEXTURE_LAYER0"},
	{drawable_t::hash_value_t::HASH_VALUE_PLACEMENTEXTENTS, "PLACEMENTEXTENTS"},
	{drawable_t::hash_value_t::HASH_VALUE_FINLAYERINC0, "FINLAYERINC0"},
	{drawable_t::hash_value_t::HASH_VALUE_REGIONTINTAMOUNT, "REGIONTINTAMOUNT"},
	{drawable_t::hash_value_t::HASH_VALUE_WRINKLETEXTURE, "WRINKLETEXTURE"},
	{drawable_t::hash_value_t::HASH_VALUE_FURSHADOW47, "FURSHADOW47"},
	{drawable_t::hash_value_t::HASH_VALUE_OILTHICKNESS, "OILTHICKNESS"},
	{drawable_t::hash_value_t::HASH_VALUE_CRACKDECALBUMPTILESCALE, "CRACKDECALBUMPTILESCALE"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR0MATERIALATEX, "LYR0MATERIALATEX"},
	{drawable_t::hash_value_t::HASH_VALUE_DECALBLENDOPACITYGBUFFER2, "DECALBLENDOPACITYGBUFFER2"},
	{drawable_t::hash_value_t::HASH_VALUE_TINTPALETTETEX, "TINTPALETTETEX"},
	{drawable_t::hash_value_t::HASH_VALUE_SNOWMELT, "SNOWMELT"},
	{drawable_t::hash_value_t::HASH_VALUE_MATERIALMAPATEXTURE_LAYER0, "MATERIALMAPATEXTURE_LAYER0"},
	{drawable_t::hash_value_t::HASH_VALUE_USEOVERLAYBLEND, "USEOVERLAYBLEND"},
	{drawable_t::hash_value_t::HASH_VALUE_TATTOOALBEDO, "TATTOOALBEDO"},
	{drawable_t::hash_value_t::HASH_VALUE_DIFFUSETEXTURE_LAYER2, "DIFFUSETEXTURE_LAYER2"},
	{drawable_t::hash_value_t::HASH_VALUE_WETNESSMULTIPLIER, "WETNESSMULTIPLIER"},
	{drawable_t::hash_value_t::HASH_VALUE_BROKENDIFFUSECOLOR, "BROKENDIFFUSECOLOR"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR0DIFFUSETEX, "LYR0DIFFUSETEX"},
	{drawable_t::hash_value_t::HASH_VALUE_FURUVSCALES, "FURUVSCALES"},
	{drawable_t::hash_value_t::HASH_VALUE_PBRTWEAK_TRANSLUCENCY, "PBRTWEAK_TRANSLUCENCY"},
	{drawable_t::hash_value_t::HASH_VALUE_ALPHASCALE, "ALPHASCALE"},
	{drawable_t::hash_value_t::HASH_VALUE_CONTROLFILTERC, "CONTROLFILTERC"},
	{drawable_t::hash_value_t::HASH_VALUE_TRANSLUCENCYASTINTMASK, "TRANSLUCENCYASTINTMASK"},
	{drawable_t::hash_value_t::HASH_VALUE_HEIGHTSCALE, "HEIGHTSCALE"},
	{drawable_t::hash_value_t::HASH_VALUE_CONTROLTEXTURETEX, "CONTROLTEXTURETEX"},
	{drawable_t::hash_value_t::HASH_VALUE_DECALBLENDOPACITYGBUFFER3, "DECALBLENDOPACITYGBUFFER3"},
	{drawable_t::hash_value_t::HASH_VALUE_PBRTWEAK_FRESNEL, "PBRTWEAK_FRESNEL"},
	{drawable_t::hash_value_t::HASH_VALUE_FURTIPTRANSLUCENCYADJ0, "FURTIPTRANSLUCENCYADJ0"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR0MATERIALBTEX, "LYR0MATERIALBTEX"},
	{drawable_t::hash_value_t::HASH_VALUE_HORSESHEENTEXTURE, "HORSESHEENTEXTURE"},
	{drawable_t::hash_value_t::HASH_VALUE_DIFFUSETEXTURE_LAYER3, "DIFFUSETEXTURE_LAYER3"},
	{drawable_t::hash_value_t::HASH_VALUE_BUSEHARDLIGHT, "BUSEHARDLIGHT"},
	{drawable_t::hash_value_t::HASH_VALUE_ENGRAVINGCREATEBUMP, "ENGRAVINGCREATEBUMP"},
	{drawable_t::hash_value_t::HASH_VALUE_FOLIAGEBRANCHBENDPIVOT0, "FOLIAGEBRANCHBENDPIVOT0"},
	{drawable_t::hash_value_t::HASH_VALUE_DIRTDECALMASK, "DIRTDECALMASK"},
	{drawable_t::hash_value_t::HASH_VALUE_PBRTWEAK_ROUGHNESS, "PBRTWEAK_ROUGHNESS"},
	{drawable_t::hash_value_t::HASH_VALUE_MATERIALMAPATEXTURE_LAYER3, "MATERIALMAPATEXTURE_LAYER3"},
	{drawable_t::hash_value_t::HASH_VALUE_DIRTFACTOR, "DIRTFACTOR"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR0UVSET, "LYR0UVSET"},
	{drawable_t::hash_value_t::HASH_VALUE_TINTTEXTURE, "TINTTEXTURE"},
	{drawable_t::hash_value_t::HASH_VALUE_DIFFUSECOLORMULTIPLIER, "DIFFUSECOLORMULTIPLIER"},
	{drawable_t::hash_value_t::HASH_VALUE_GLODFADETILESCALE, "GLODFADETILESCALE"},
	{drawable_t::hash_value_t::HASH_VALUE_FURSHADOW03, "FURSHADOW03"},
	{drawable_t::hash_value_t::HASH_VALUE_UMWINDNOISESCALEMINMAX0, "UMWINDNOISESCALEMINMAX0"},
	{drawable_t::hash_value_t::HASH_VALUE_MATERIALMAPATEXTURE_LAYER1, "MATERIALMAPATEXTURE_LAYER1"},
	{drawable_t::hash_value_t::HASH_VALUE_WINDAMOUNT, "WINDAMOUNT"},
	{drawable_t::hash_value_t::HASH_VALUE_FURLAYERPARAMS, "FURLAYERPARAMS"},
	{drawable_t::hash_value_t::HASH_VALUE_FURSTIFFNESS0, "FURSTIFFNESS0"},
	{drawable_t::hash_value_t::HASH_VALUE_DIRTCOLOR, "DIRTCOLOR"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR0ROUGHNESSMODIFIER, "LYR0ROUGHNESSMODIFIER"},
	{drawable_t::hash_value_t::HASH_VALUE_DIRTBLEND, "DIRTBLEND"},
	{drawable_t::hash_value_t::HASH_VALUE_USETESSELLATION, "USETESSELLATION"},
	{drawable_t::hash_value_t::HASH_VALUE_BUMPSAMPLER, "BUMPSAMPLER"},
	{drawable_t::hash_value_t::HASH_VALUE_ENGRAVINGSAMPLEOFFSET, "ENGRAVINGSAMPLEOFFSET"},
	{drawable_t::hash_value_t::HASH_VALUE_PBRCAVITYRANGE, "PBRCAVITYRANGE"},
	{drawable_t::hash_value_t::HASH_VALUE_PBRDETAIL_METALLIC, "PBRDETAIL_METALLIC"},
	{drawable_t::hash_value_t::HASH_VALUE_FURGRAVITYWINDBLEND0, "FURGRAVITYWINDBLEND0"},
	{drawable_t::hash_value_t::HASH_VALUE_LIVERYCONTROLTEX, "LIVERYCONTROLTEX"},
	{drawable_t::hash_value_t::HASH_VALUE_UMPEDWINDNOISESCALEMINMAX0, "UMPEDWINDNOISESCALEMINMAX0"},
	{drawable_t::hash_value_t::HASH_VALUE_CURRENTINSCATTERRM0, "CURRENTINSCATTERRM0"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR1BUMPINESS, "LYR1BUMPINESS"},
	{drawable_t::hash_value_t::HASH_VALUE_FOGANDOPACITYOVERRIDE, "FOGANDOPACITYOVERRIDE"},
	{drawable_t::hash_value_t::HASH_VALUE_BUMPTEXTURE_LAYER2, "BUMPTEXTURE_LAYER2"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR0MAXWETNESS, "LYR0MAXWETNESS"},
	{drawable_t::hash_value_t::HASH_VALUE_SHADOWFALLOFF, "SHADOWFALLOFF"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR1MATERIALATEX, "LYR1MATERIALATEX"},
	{drawable_t::hash_value_t::HASH_VALUE_LIVERYPALSELECTOR, "LIVERYPALSELECTOR"},
	{drawable_t::hash_value_t::HASH_VALUE_CULLSPHERES, "CULLSPHERES"},
	{drawable_t::hash_value_t::HASH_VALUE_SCALE, "SCALE"},
	{drawable_t::hash_value_t::HASH_VALUE_ENGRAVINGCAVITYAMT, "ENGRAVINGCAVITYAMT"},
	{drawable_t::hash_value_t::HASH_VALUE_AOMAPINTENSITY0, "AOMAPINTENSITY0"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR1TRANSLUCENCY, "LYR1TRANSLUCENCY"},
	{drawable_t::hash_value_t::HASH_VALUE_BROKENSPECULARCOLOR, "BROKENSPECULARCOLOR"},
	{drawable_t::hash_value_t::HASH_VALUE_STANDARD_DIRT, "STANDARD_DIRT"},
	{drawable_t::hash_value_t::HASH_VALUE_GBUFFERTEXTURE0, "GBUFFERTEXTURE0"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR0TINT, "LYR0TINT"},
	{drawable_t::hash_value_t::HASH_VALUE_BUMPTEXTURE2, "BUMPTEXTURE2"},
	{drawable_t::hash_value_t::HASH_VALUE_COMBOHEIGHTTEXTUREFUR45, "COMBOHEIGHTTEXTUREFUR45"},
	{drawable_t::hash_value_t::HASH_VALUE_ANISOTROPIC16XWRAP, "ANISOTROPIC16XWRAP"},
	{drawable_t::hash_value_t::HASH_VALUE_LOOKINGGLASSDISTORTIONCENTER1, "LOOKINGGLASSDISTORTIONCENTER1"},
	{drawable_t::hash_value_t::HASH_VALUE_PXMBIASES1234, "PXMBIASES1234"},
	{drawable_t::hash_value_t::HASH_VALUE_PROCEDURALTHRESHOLD, "PROCEDURALTHRESHOLD"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR0CAVITY, "LYR0CAVITY"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR1NORMALTEX, "LYR1NORMALTEX"},
	{drawable_t::hash_value_t::HASH_VALUE_PROCEDURALDIR, "PROCEDURALDIR"},
	{drawable_t::hash_value_t::HASH_VALUE_CONTROLFILTER, "CONTROLFILTER"},
	{drawable_t::hash_value_t::HASH_VALUE_BUSEPROCEDURALBLEND, "BUSEPROCEDURALBLEND"},
	{drawable_t::hash_value_t::HASH_VALUE_FURGLOBALPARAMS1, "FURGLOBALPARAMS1"},
	{drawable_t::hash_value_t::HASH_VALUE_USEPAINTEDWETNESS, "USEPAINTEDWETNESS"},
	{drawable_t::hash_value_t::HASH_VALUE_CABLEDIFFUSE, "CABLEDIFFUSE"},
	{drawable_t::hash_value_t::HASH_VALUE_PXMENABLED, "PXMENABLED"},
	{drawable_t::hash_value_t::HASH_VALUE_SHELLFURBLUR0, "SHELLFURBLUR0"},
	{drawable_t::hash_value_t::HASH_VALUE_HEIGHTUVSET, "HEIGHTUVSET"},
	{drawable_t::hash_value_t::HASH_VALUE_EMISSIVEMULTIPLIER, "EMISSIVEMULTIPLIER"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR0DETAILSETTINGS, "LYR0DETAILSETTINGS"},
	{drawable_t::hash_value_t::HASH_VALUE_ORDERNUMBER, "ORDERNUMBER"},
	{drawable_t::hash_value_t::HASH_VALUE_SPECSAMPLER, "SPECSAMPLER"},
	{drawable_t::hash_value_t::HASH_VALUE_SCSVERTEXINPUTATTRIBUTES, "SCSVERTEXINPUTATTRIBUTES"},
	{drawable_t::hash_value_t::HASH_VALUE_CLIPPINGPLANE, "CLIPPINGPLANE"},
	{drawable_t::hash_value_t::HASH_VALUE_ENABLESPEC, "ENABLESPEC"},
	{drawable_t::hash_value_t::HASH_VALUE_TREEHORIZONTALBENDUPPERBOUND0, "TREEHORIZONTALBENDUPPERBOUND0"},
	{drawable_t::hash_value_t::HASH_VALUE_WRINKLEMASKTEXTURE, "WRINKLEMASKTEXTURE"},
	{drawable_t::hash_value_t::HASH_VALUE_NOISETEXTURE, "NOISETEXTURE"},
	{drawable_t::hash_value_t::HASH_VALUE_ANISOTROPICSPECULARCOLOUR, "ANISOTROPICSPECULARCOLOUR"},
	{drawable_t::hash_value_t::HASH_VALUE_CONTROLTEXTURETEXB, "CONTROLTEXTURETEXB"},
	{drawable_t::hash_value_t::HASH_VALUE_SLODCOLORS, "SLODCOLORS"},
	{drawable_t::hash_value_t::HASH_VALUE_DEBUGSHOWLIVERY, "DEBUGSHOWLIVERY"},
	{drawable_t::hash_value_t::HASH_VALUE_DEFERREDLIGHTPARAMS, "DEFERREDLIGHTPARAMS"},
	{drawable_t::hash_value_t::HASH_VALUE_COMBOHEIGHTSAMPLERFUR01, "COMBOHEIGHTSAMPLERFUR01"},
	{drawable_t::hash_value_t::HASH_VALUE_POROSITY, "POROSITY"},
	{drawable_t::hash_value_t::HASH_VALUE_DIRTROUGHNESS, "DIRTROUGHNESS"},
	{drawable_t::hash_value_t::HASH_VALUE_FURPERVTXSCRIPTEDSTIFFNESS0, "FURPERVTXSCRIPTEDSTIFFNESS0"},
	{drawable_t::hash_value_t::HASH_VALUE_ENGRAVINGEDGESMOOTHNESS, "ENGRAVINGEDGESMOOTHNESS"},
	{drawable_t::hash_value_t::HASH_VALUE_BACKLIGHTCOLOR, "BACKLIGHTCOLOR"},
	{drawable_t::hash_value_t::HASH_VALUE_USETRANSLUCENCY, "USETRANSLUCENCY"},
	{drawable_t::hash_value_t::HASH_VALUE_TARGETPOSITIONSPACKED, "TARGETPOSITIONSPACKED"},
	{drawable_t::hash_value_t::HASH_VALUE_ENGRAVINGBUMPINESS, "ENGRAVINGBUMPINESS"},
	{drawable_t::hash_value_t::HASH_VALUE_RADIUSSCALE, "RADIUSSCALE"},
	{drawable_t::hash_value_t::HASH_VALUE_SHELLCOMPRESSION0, "SHELLCOMPRESSION0"},
	{drawable_t::hash_value_t::HASH_VALUE_CALCBYSUNCOL, "CALCBYSUNCOL"},
	{drawable_t::hash_value_t::HASH_VALUE_ONOFFFADES, "ONOFFFADES"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR1TINT, "LYR1TINT"},
	{drawable_t::hash_value_t::HASH_VALUE_TARGETSIZE, "TARGETSIZE"},
	{drawable_t::hash_value_t::HASH_VALUE_UMWINDNOISERATIO0, "UMWINDNOISERATIO0"},
	{drawable_t::hash_value_t::HASH_VALUE_UVSET, "UVSET"},
	{drawable_t::hash_value_t::HASH_VALUE_ALPHAUVSET, "ALPHAUVSET"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR1UVSET, "LYR1UVSET"},
	{drawable_t::hash_value_t::HASH_VALUE_TESSELLATIONMULTIPLIER, "TESSELLATIONMULTIPLIER"},
	{drawable_t::hash_value_t::HASH_VALUE_MIPLINEARWRAP, "MIPLINEARWRAP"},
	{drawable_t::hash_value_t::HASH_VALUE_SPECULARTEX2, "SPECULARTEX2"},
	{drawable_t::hash_value_t::HASH_VALUE_SCATTERINGLUTTEX, "SCATTERINGLUTTEX"},
	{drawable_t::hash_value_t::HASH_VALUE_DIRTDIFFUSETEX, "DIRTDIFFUSETEX"},
	{drawable_t::hash_value_t::HASH_VALUE_POINTCLAMP, "POINTCLAMP"},
	{drawable_t::hash_value_t::HASH_VALUE_STANDARD_2LYR, "STANDARD_2LYR"},
	{drawable_t::hash_value_t::HASH_VALUE_MANUALDEPTHTEST, "MANUALDEPTHTEST"},
	{drawable_t::hash_value_t::HASH_VALUE_SKINNEDVERTEXDEF, "SKINNEDVERTEXDEF"},
	{drawable_t::hash_value_t::HASH_VALUE_MIPLINEARCLAMP, "MIPLINEARCLAMP"},
	{drawable_t::hash_value_t::HASH_VALUE_VEHTINTPALETTETEX, "VEHTINTPALETTETEX"},
	{drawable_t::hash_value_t::HASH_VALUE_TREEHORIZONTALBENDSTARTRATIO0, "TREEHORIZONTALBENDSTARTRATIO0"},
	{drawable_t::hash_value_t::HASH_VALUE_DETAILTEXARRAYD, "DETAILTEXARRAYD"},
	{drawable_t::hash_value_t::HASH_VALUE_ALBEDOOVERRIDETEX, "ALBEDOOVERRIDETEX"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR1DIFFUSETEX, "LYR1DIFFUSETEX"},
	{drawable_t::hash_value_t::HASH_VALUE_MAXSPLATTERSTART, "MAXSPLATTERSTART"},
	{drawable_t::hash_value_t::HASH_VALUE_FURSHELLOPACITYADJUST0, "FURSHELLOPACITYADJUST0"},
	{drawable_t::hash_value_t::HASH_VALUE_FURNOISEUVSCALE0, "FURNOISEUVSCALE0"},
	{drawable_t::hash_value_t::HASH_VALUE_BUMPTEXTURE_LAYER1, "BUMPTEXTURE_LAYER1"},
	{drawable_t::hash_value_t::HASH_VALUE_DIRTINTENSITY, "DIRTINTENSITY"},
	{drawable_t::hash_value_t::HASH_VALUE_DEFERREDLIGHTVOLUMEPARAMS, "DEFERREDLIGHTVOLUMEPARAMS"},
	{drawable_t::hash_value_t::HASH_VALUE_LOOKINGGLASSBLURTEXTURE, "LOOKINGGLASSBLURTEXTURE"},
	{drawable_t::hash_value_t::HASH_VALUE_CRACKDECALBUMPAMOUNT, "CRACKDECALBUMPAMOUNT"},
	{drawable_t::hash_value_t::HASH_VALUE_MAXVERTPUSHSTART, "MAXVERTPUSHSTART"},
	{drawable_t::hash_value_t::HASH_VALUE_CABLEEMISSIVE, "CABLEEMISSIVE"},
	{drawable_t::hash_value_t::HASH_VALUE_PARALLAXSCALEBIAS, "PARALLAXSCALEBIAS"},
	{drawable_t::hash_value_t::HASH_VALUE_SLODINFOBUFFER, "SLODINFOBUFFER"},
	{drawable_t::hash_value_t::HASH_VALUE_MAXSHOWDIRTTEX, "MAXSHOWDIRTTEX"},
	{drawable_t::hash_value_t::HASH_VALUE_ENGRAVINGDIFFUSEAMT, "ENGRAVINGDIFFUSEAMT"},
	{drawable_t::hash_value_t::HASH_VALUE_FRESNELSELECTOR, "FRESNELSELECTOR"},
	{drawable_t::hash_value_t::HASH_VALUE_GALPHATEST, "GALPHATEST"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR0NORMALTEX, "LYR0NORMALTEX"},
	{drawable_t::hash_value_t::HASH_VALUE_FOGTEXTURE, "FOGTEXTURE"},
	{drawable_t::hash_value_t::HASH_VALUE_LOOKINGGLASSDISTORTIONCENTER2, "LOOKINGGLASSDISTORTIONCENTER2"},
	{drawable_t::hash_value_t::HASH_VALUE_BACKLIGHTOFFSET, "BACKLIGHTOFFSET"},
	{drawable_t::hash_value_t::HASH_VALUE_HEIGHTTEXTUREX, "HEIGHTTEXTUREX"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR0NORMALUVSET, "LYR0NORMALUVSET"},
	{drawable_t::hash_value_t::HASH_VALUE_RAINTEXTURESAMPLERGLOBAL, "RAINTEXTURESAMPLERGLOBAL"},
	{drawable_t::hash_value_t::HASH_VALUE_OILPARAMS, "OILPARAMS"},
	{drawable_t::hash_value_t::HASH_VALUE_ANISONOISESPECTEXTURE, "ANISONOISESPECTEXTURE"},
	{drawable_t::hash_value_t::HASH_VALUE_TREEVERTICALBENDUPPERBOUND0, "TREEVERTICALBENDUPPERBOUND0"},
	{drawable_t::hash_value_t::HASH_VALUE_MATERIALBTEXTURE2, "MATERIALBTEXTURE2"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR0METALNESSMODIFIER, "LYR0METALNESSMODIFIER"},
	{drawable_t::hash_value_t::HASH_VALUE_FURWETSTIFFNESS0, "FURWETSTIFFNESS0"},
	{drawable_t::hash_value_t::HASH_VALUE_FLOWTEXTURE, "FLOWTEXTURE"},
	{drawable_t::hash_value_t::HASH_VALUE_ANGLESNEARFAR, "ANGLESNEARFAR"},
	{drawable_t::hash_value_t::HASH_VALUE_IMPOSTERTEXARRAY1, "IMPOSTERTEXARRAY1"},
	{drawable_t::hash_value_t::HASH_VALUE_OILSPANANDWIBBLE, "OILSPANANDWIBBLE"},
	{drawable_t::hash_value_t::HASH_VALUE_GLODTRANSITIONRANGE, "GLODTRANSITIONRANGE"},
	{drawable_t::hash_value_t::HASH_VALUE_PBRGLASSINESS, "PBRGLASSINESS"},
	{drawable_t::hash_value_t::HASH_VALUE_ENGRAVINGMATERIALTHRESHOLD, "ENGRAVINGMATERIALTHRESHOLD"},
	{drawable_t::hash_value_t::HASH_VALUE_FURDIRTSTIFFNESS0, "FURDIRTSTIFFNESS0"},
	{drawable_t::hash_value_t::HASH_VALUE_RAWINSTANCEBUFFER, "RAWINSTANCEBUFFER"},
	{drawable_t::hash_value_t::HASH_VALUE_AOTEXTURETEX, "AOTEXTURETEX"},
	{drawable_t::hash_value_t::HASH_VALUE_GWINDBENDSCALEVAR, "GWINDBENDSCALEVAR"},
	{drawable_t::hash_value_t::HASH_VALUE_FURGLOBALPARAMS0, "FURGLOBALPARAMS0"},
	{drawable_t::hash_value_t::HASH_VALUE_PBRDETAIL_TRANSLUCENCY, "PBRDETAIL_TRANSLUCENCY"},
	{drawable_t::hash_value_t::HASH_VALUE_MIRRORREFLECTION, "MIRRORREFLECTION"},
	{drawable_t::hash_value_t::HASH_VALUE_WRINKLEBASEFADEOUTAMOUNT, "WRINKLEBASEFADEOUTAMOUNT"},
	{drawable_t::hash_value_t::HASH_VALUE_MAXVERTPUSHEND, "MAXVERTPUSHEND"},
	{drawable_t::hash_value_t::HASH_VALUE_DIRTALPHACHANNEL, "DIRTALPHACHANNEL"},
	{drawable_t::hash_value_t::HASH_VALUE_SUNDIRECTION, "SUNDIRECTION"},
	{drawable_t::hash_value_t::HASH_VALUE_MAXDIRTINTENSITY, "MAXDIRTINTENSITY"},
	{drawable_t::hash_value_t::HASH_VALUE_TREEVERTICALBENDEXP0, "TREEVERTICALBENDEXP0"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR0HEIGHTBIAS, "LYR0HEIGHTBIAS"},
	{drawable_t::hash_value_t::HASH_VALUE_DECALBLENDOPACITYGBUFFER1, "DECALBLENDOPACITYGBUFFER1"},
	{drawable_t::hash_value_t::HASH_VALUE_SPECULARTEXTURE, "SPECULARTEXTURE"},
	{drawable_t::hash_value_t::HASH_VALUE_PBRTWEAK_METALLIC, "PBRTWEAK_METALLIC"},
	{drawable_t::hash_value_t::HASH_VALUE_FURLENGTHJITTER0, "FURLENGTHJITTER0"},
	{drawable_t::hash_value_t::HASH_VALUE_UMPEDWINDNOISERATIO0, "UMPEDWINDNOISERATIO0"},
	{drawable_t::hash_value_t::HASH_VALUE_PBRDETAIL_ROUGHNESS, "PBRDETAIL_ROUGHNESS"},
	{drawable_t::hash_value_t::HASH_VALUE_UMPEDWINDSCALE0, "UMPEDWINDSCALE0"},
	{drawable_t::hash_value_t::HASH_VALUE_SPECULAR, "SPECULAR"},
	{drawable_t::hash_value_t::HASH_VALUE_IMPOSTERTEXARRAY2, "IMPOSTERTEXARRAY2"},
	{drawable_t::hash_value_t::HASH_VALUE_ENGRAVINGMASKWIDTH, "ENGRAVINGMASKWIDTH"},
	{drawable_t::hash_value_t::HASH_VALUE_SHELLLAYERSTART0, "SHELLLAYERSTART0"},
	{drawable_t::hash_value_t::HASH_VALUE_TRANSMITTANCELUTTEX, "TRANSMITTANCELUTTEX"},
	{drawable_t::hash_value_t::HASH_VALUE_WETNESS, "WETNESS"},
	{drawable_t::hash_value_t::HASH_VALUE_CONTROLFILTERA, "CONTROLFILTERA"},
	{drawable_t::hash_value_t::HASH_VALUE_NEWFURSOFTEN0, "NEWFURSOFTEN0"},
	{drawable_t::hash_value_t::HASH_VALUE_MARKTAAGHOSTINGBIT, "MARKTAAGHOSTINGBIT"},
	{drawable_t::hash_value_t::HASH_VALUE_RIVERFOAMTEXTURESCALE, "RIVERFOAMTEXTURESCALE"},
	{drawable_t::hash_value_t::HASH_VALUE_PXMSCALES1234, "PXMSCALES1234"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR1UVSCALE, "LYR1UVSCALE"},
	{drawable_t::hash_value_t::HASH_VALUE_SPECULARCOLOR, "SPECULARCOLOR"},
	{drawable_t::hash_value_t::HASH_VALUE_FURAOFURDEPTH0, "FURAOFURDEPTH0"},
	{drawable_t::hash_value_t::HASH_VALUE_LIVERYMATSELECTOR, "LIVERYMATSELECTOR"},
	{drawable_t::hash_value_t::HASH_VALUE_CONTROLFILTERB, "CONTROLFILTERB"},
	{drawable_t::hash_value_t::HASH_VALUE_FURATTENCOEF0, "FURATTENCOEF0"},
	{drawable_t::hash_value_t::HASH_VALUE_DISTORTIONPARAMS, "DISTORTIONPARAMS"},
	{drawable_t::hash_value_t::HASH_VALUE_SKINNEDTANGENTSDEF, "SKINNEDTANGENTSDEF"},
	{drawable_t::hash_value_t::HASH_VALUE_FURMINLAYERS0, "FURMINLAYERS0"},
	{drawable_t::hash_value_t::HASH_VALUE_MAXSPLATTEREND, "MAXSPLATTEREND"},
	{drawable_t::hash_value_t::HASH_VALUE_STANDARD_2LYR_PXM, "STANDARD_2LYR_PXM"},
	{drawable_t::hash_value_t::HASH_VALUE_HBBRANGESCALE1234, "HBBRANGESCALE1234"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR1FRESNEL, "LYR1FRESNEL"},
	{drawable_t::hash_value_t::HASH_VALUE_ENGRAVINGINVERT, "ENGRAVINGINVERT"},
	{drawable_t::hash_value_t::HASH_VALUE_COMBOHEIGHTTEXTUREFUR67, "COMBOHEIGHTTEXTUREFUR67"},
	{drawable_t::hash_value_t::HASH_VALUE_DETAILSETTINGS, "DETAILSETTINGS"},
	{drawable_t::hash_value_t::HASH_VALUE_FURMAXLAYERS0, "FURMAXLAYERS0"},
	{drawable_t::hash_value_t::HASH_VALUE_FRESNEL, "FRESNEL"},
	{drawable_t::hash_value_t::HASH_VALUE_CALCBYSUNINTENSITY, "CALCBYSUNINTENSITY"},
	{drawable_t::hash_value_t::HASH_VALUE_DECALTINT, "DECALTINT"},
	{drawable_t::hash_value_t::HASH_VALUE_RIPPLEBUMPINESS, "RIPPLEBUMPINESS"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR1MAXWETNESS, "LYR1MAXWETNESS"},
	{drawable_t::hash_value_t::HASH_VALUE_CONTROLTEXTURETEXA, "CONTROLTEXTURETEXA"},
	{drawable_t::hash_value_t::HASH_VALUE_FURAOBLEND0, "FURAOBLEND0"},
	{drawable_t::hash_value_t::HASH_VALUE_FINFURBLUR0, "FINFURBLUR0"},
	{drawable_t::hash_value_t::HASH_VALUE_CABLEAMBIENT, "CABLEAMBIENT"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR1POROSITY, "LYR1POROSITY"},
	{drawable_t::hash_value_t::HASH_VALUE_TREEHORIZONTALBENDEXP0, "TREEHORIZONTALBENDEXP0"},
	{drawable_t::hash_value_t::HASH_VALUE_STANDARD, "STANDARD"},
	{drawable_t::hash_value_t::HASH_VALUE_STIPPLESAMPLER, "STIPPLESAMPLER"},
	{drawable_t::hash_value_t::HASH_VALUE_SMALLHDRCUBETEX, "SMALLHDRCUBETEX"},
	{drawable_t::hash_value_t::HASH_VALUE_ALBEDOPALETTETEX, "ALBEDOPALETTETEX"},
	{drawable_t::hash_value_t::HASH_VALUE_LOOKUPTEXTURE, "LOOKUPTEXTURE"},
	{drawable_t::hash_value_t::HASH_VALUE_NIGHTONLY, "NIGHTONLY"},
	{drawable_t::hash_value_t::HASH_VALUE_FURFINOPACITYADJUST0, "FURFINOPACITYADJUST0"},
	{drawable_t::hash_value_t::HASH_VALUE_WRINKLEAOSCALE, "WRINKLEAOSCALE"},
	{drawable_t::hash_value_t::HASH_VALUE_TREEMMSCALE0, "TREEMMSCALE0"},
	{drawable_t::hash_value_t::HASH_VALUE_CALCBYAMBIENTINTENSITY, "CALCBYAMBIENTINTENSITY"},
	{drawable_t::hash_value_t::HASH_VALUE_BACKLIGHTINTENSITIES, "BACKLIGHTINTENSITIES"},
	{drawable_t::hash_value_t::HASH_VALUE_FURBENDWINDINFLUENCE0, "FURBENDWINDINFLUENCE0"},
	{drawable_t::hash_value_t::HASH_VALUE_FURPERVTXHACKLESSTIFFNESS0, "FURPERVTXHACKLESSTIFFNESS0"},
	{drawable_t::hash_value_t::HASH_VALUE_PUSHSPHERESPREVIOUSFRAME, "PUSHSPHERESPREVIOUSFRAME"},
	{drawable_t::hash_value_t::HASH_VALUE_PBRDETAIL_AO, "PBRDETAIL_AO"},
	{drawable_t::hash_value_t::HASH_VALUE_FURSELFSHADOWMIN0, "FURSELFSHADOWMIN0"},
	{drawable_t::hash_value_t::HASH_VALUE_SPECULARTEX, "SPECULARTEX"},
	{drawable_t::hash_value_t::HASH_VALUE_CRACKDECALBUMPALPHATHRESHOLD, "CRACKDECALBUMPALPHATHRESHOLD"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR0ALBEDOMODIFIER, "LYR0ALBEDOMODIFIER"},
	{drawable_t::hash_value_t::HASH_VALUE_PUSHPIVOTBUFFER, "PUSHPIVOTBUFFER"},
	{drawable_t::hash_value_t::HASH_VALUE_SPECULARTEXTURE2, "SPECULARTEXTURE2"},
	{drawable_t::hash_value_t::HASH_VALUE_HEIGHTFILTER, "HEIGHTFILTER"},
	{drawable_t::hash_value_t::HASH_VALUE_DIFFUSE2MODSPEC, "DIFFUSE2MODSPEC"},
	{drawable_t::hash_value_t::HASH_VALUE_ENGRAVINGTEXTURETEX, "ENGRAVINGTEXTURETEX"},
	{drawable_t::hash_value_t::HASH_VALUE_UVSCALEBIAS, "UVSCALEBIAS"},
	{drawable_t::hash_value_t::HASH_VALUE_DIFFUSETEX, "DIFFUSETEX"},
	{drawable_t::hash_value_t::HASH_VALUE_DETAILSAMPLER, "DETAILSAMPLER"},
	{drawable_t::hash_value_t::HASH_VALUE_TREEHORIZONTALBENDSCALE0, "TREEHORIZONTALBENDSCALE0"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR0POROSITY, "LYR0POROSITY"},
	{drawable_t::hash_value_t::HASH_VALUE_BLENDSOFTNESS, "BLENDSOFTNESS"},
	{drawable_t::hash_value_t::HASH_VALUE_CRACKEDGEBUMPAMOUNT, "CRACKEDGEBUMPAMOUNT"},
	{drawable_t::hash_value_t::HASH_VALUE_DIRTNOISETEX, "DIRTNOISETEX"},
	{drawable_t::hash_value_t::HASH_VALUE_DETAILINDEXOVERRIDE, "DETAILINDEXOVERRIDE"},
	{drawable_t::hash_value_t::HASH_VALUE_DIRTVERTPUSHSCALE, "DIRTVERTPUSHSCALE"},
	{drawable_t::hash_value_t::HASH_VALUE_NEWFURFLUFFUP, "NEWFURFLUFFUP"},
	{drawable_t::hash_value_t::HASH_VALUE_COMPUTEINSTANCEBUFFER, "COMPUTEINSTANCEBUFFER"},
	{drawable_t::hash_value_t::HASH_VALUE_TINYHDRTEX, "TINYHDRTEX"},
	{drawable_t::hash_value_t::HASH_VALUE_DIFFUSETEXTURE_LAYER0, "DIFFUSETEXTURE_LAYER0"},
	{drawable_t::hash_value_t::HASH_VALUE_DIRTTINTCHANNEL, "DIRTTINTCHANNEL"},
	{drawable_t::hash_value_t::HASH_VALUE_MOONDIRECTION, "MOONDIRECTION"},
	{drawable_t::hash_value_t::HASH_VALUE_WRINKLEMULTIPLIER, "WRINKLEMULTIPLIER"},
	{drawable_t::hash_value_t::HASH_VALUE_NUMTARGETS, "NUMTARGETS"},
	{drawable_t::hash_value_t::HASH_VALUE_HASWRINKLESWITCH, "HASWRINKLESWITCH"},
	{drawable_t::hash_value_t::HASH_VALUE_AERIALPERSPECTIVESLICEDISTR, "AERIALPERSPECTIVESLICEDISTR"},
	{drawable_t::hash_value_t::HASH_VALUE_FINCOMPRESSION0, "FINCOMPRESSION0"},
	{drawable_t::hash_value_t::HASH_VALUE_POLLENLAYER, "POLLENLAYER"},
	{drawable_t::hash_value_t::HASH_VALUE_GRASSNOISETILESCALE, "GRASSNOISETILESCALE"},
	{drawable_t::hash_value_t::HASH_VALUE_RIPPLESCALE, "RIPPLESCALE"},
	{drawable_t::hash_value_t::HASH_VALUE_STANDARD_DECAL_BLEND, "STANDARD_DECAL_BLEND"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR0BUMPINESS, "LYR0BUMPINESS"},
	{drawable_t::hash_value_t::HASH_VALUE_ENABLENEARCAMERAFADE, "ENABLENEARCAMERAFADE"},
	{drawable_t::hash_value_t::HASH_VALUE_DAMAGESAMPLER, "DAMAGESAMPLER"},
	{drawable_t::hash_value_t::HASH_VALUE_EXPOSURETEXTURE, "EXPOSURETEXTURE"},
	{drawable_t::hash_value_t::HASH_VALUE_PBRTWEAK_SHEEN, "PBRTWEAK_SHEEN"},
	{drawable_t::hash_value_t::HASH_VALUE_FURBENDWINDMAXSPEEDCLAMP0, "FURBENDWINDMAXSPEEDCLAMP0"},
	{drawable_t::hash_value_t::HASH_VALUE_BUMPTEXTURE, "BUMPTEXTURE"},
	{drawable_t::hash_value_t::HASH_VALUE_TRILINEARBORDERBLACK, "TRILINEARBORDERBLACK"},
	{drawable_t::hash_value_t::HASH_VALUE_SOOTCOLOR, "SOOTCOLOR"},
	{drawable_t::hash_value_t::HASH_VALUE_CONTROLTEXTURETEXC, "CONTROLTEXTURETEXC"},
	{drawable_t::hash_value_t::HASH_VALUE_PUDDLEHEIGHTBIAS, "PUDDLEHEIGHTBIAS"},
	{drawable_t::hash_value_t::HASH_VALUE_DIFFUSETEXTURE_LAYER1, "DIFFUSETEXTURE_LAYER1"},
	{drawable_t::hash_value_t::HASH_VALUE_OPACITY, "OPACITY"},
	{drawable_t::hash_value_t::HASH_VALUE_PROJDECALTEXARRAYSAMPLER, "PROJDECALTEXARRAYSAMPLER"},
	{drawable_t::hash_value_t::HASH_VALUE_ENGRAVINGSHOW, "ENGRAVINGSHOW"},
	{drawable_t::hash_value_t::HASH_VALUE_ENVEFFTEXTILEUV, "ENVEFFTEXTILEUV"},
	{drawable_t::hash_value_t::HASH_VALUE_MAXWETNESS, "MAXWETNESS"},
	{drawable_t::hash_value_t::HASH_VALUE_TINTINTENSITY, "TINTINTENSITY"},
	{drawable_t::hash_value_t::HASH_VALUE_TERRAINFRESNEL, "TERRAINFRESNEL"},
	{drawable_t::hash_value_t::HASH_VALUE_UMWINDSCALE0, "UMWINDSCALE0"},
	{drawable_t::hash_value_t::HASH_VALUE_DIRTUVSCALE, "DIRTUVSCALE"},
	{drawable_t::hash_value_t::HASH_VALUE_BUMPTEXTURE_LAYER3, "BUMPTEXTURE_LAYER3"},
	{drawable_t::hash_value_t::HASH_VALUE_DISTORTIONTEXTURE, "DISTORTIONTEXTURE"},
	{drawable_t::hash_value_t::HASH_VALUE_FURFINLENGTHADJUST0, "FURFINLENGTHADJUST0"},
	{drawable_t::hash_value_t::HASH_VALUE_POLLENLAYER1, "POLLENLAYER1"},
	{drawable_t::hash_value_t::HASH_VALUE_SUMGATHEREDLIGHTTEX, "SUMGATHEREDLIGHTTEX"},
	{drawable_t::hash_value_t::HASH_VALUE_LOOKINGGLASSDISTORTIONPARAMS, "LOOKINGGLASSDISTORTIONPARAMS"},
	{drawable_t::hash_value_t::HASH_VALUE_SVERTSIN, "SVERTSIN"},
	{drawable_t::hash_value_t::HASH_VALUE_WINDMINMAXTHRESHHOLDS0, "WINDMINMAXTHRESHHOLDS0"},
	{drawable_t::hash_value_t::HASH_VALUE_TRILINEARWRAP, "TRILINEARWRAP"},
	{drawable_t::hash_value_t::HASH_VALUE_FINSTARTPOSITION0, "FINSTARTPOSITION0"},
	{drawable_t::hash_value_t::HASH_VALUE_COMBOHEIGHTTEXTUREFUR01, "COMBOHEIGHTTEXTUREFUR01"},
	{drawable_t::hash_value_t::HASH_VALUE_SPECSAMPLER2, "SPECSAMPLER2"},
	{drawable_t::hash_value_t::HASH_VALUE_FURBASETRANSLUCENCYADJ0, "FURBASETRANSLUCENCYADJ0"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR1CAVITY, "LYR1CAVITY"},
	{drawable_t::hash_value_t::HASH_VALUE_PBRTWEAK_AO, "PBRTWEAK_AO"},
	{drawable_t::hash_value_t::HASH_VALUE_HARDALPHABLEND, "HARDALPHABLEND"},
	{drawable_t::hash_value_t::HASH_VALUE_FOGCOLOR, "FOGCOLOR"},
	{drawable_t::hash_value_t::HASH_VALUE_DIRTTILESCALE, "DIRTTILESCALE"},
	{drawable_t::hash_value_t::HASH_VALUE_SPLATDIFFUSETEX, "SPLATDIFFUSETEX"},
	{drawable_t::hash_value_t::HASH_VALUE_CLAMPLOOKUPTEXTURE, "CLAMPLOOKUPTEXTURE"},
	{drawable_t::hash_value_t::HASH_VALUE_POLLENLAYER3, "POLLENLAYER3"},
	{drawable_t::hash_value_t::HASH_VALUE_BLOOMMOD, "BLOOMMOD"},
	{drawable_t::hash_value_t::HASH_VALUE_INTENSITY, "INTENSITY"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR1DETAILSETTINGS, "LYR1DETAILSETTINGS"},
	{drawable_t::hash_value_t::HASH_VALUE_TINTOVERRIDE, "TINTOVERRIDE"},
	{drawable_t::hash_value_t::HASH_VALUE_ASPECTRATIOS, "ASPECTRATIOS"},
	{drawable_t::hash_value_t::HASH_VALUE_BATCHDISABLEDBITFIELD, "BATCHDISABLEDBITFIELD"},
	{drawable_t::hash_value_t::HASH_VALUE_DIFFUSESAMPLER, "DIFFUSESAMPLER"},
	{drawable_t::hash_value_t::HASH_VALUE_INVCONTROL, "INVCONTROL"},
	{drawable_t::hash_value_t::HASH_VALUE_LOOKUPUVSET, "LOOKUPUVSET"},
	{drawable_t::hash_value_t::HASH_VALUE_DEPTHTEXTURE, "DEPTHTEXTURE"},
	{drawable_t::hash_value_t::HASH_VALUE_DETAILINDICES, "DETAILINDICES"},
	{drawable_t::hash_value_t::HASH_VALUE_TREEVERTICALBENDSCALE0, "TREEVERTICALBENDSCALE0"},
	{drawable_t::hash_value_t::HASH_VALUE_CABLEDIFFUSE2, "CABLEDIFFUSE2"},
	{drawable_t::hash_value_t::HASH_VALUE_CONTROLUVSET, "CONTROLUVSET"},
	{drawable_t::hash_value_t::HASH_VALUE_MIXAMTCOL, "MIXAMTCOL"},
	{drawable_t::hash_value_t::HASH_VALUE_NEWFURALPHA0, "NEWFURALPHA0"},
	{drawable_t::hash_value_t::HASH_VALUE_FURPERVTXSTIFFNESS0, "FURPERVTXSTIFFNESS0"},
	{drawable_t::hash_value_t::HASH_VALUE_BUMPINESS, "BUMPINESS"},
	{drawable_t::hash_value_t::HASH_VALUE_FURALPHADISTANCE, "FURALPHADISTANCE"},
	{drawable_t::hash_value_t::HASH_VALUE_PLACEMENTTEXTURE, "PLACEMENTTEXTURE"},
	{drawable_t::hash_value_t::HASH_VALUE_HEIGHTTEXTURE, "HEIGHTTEXTURE"},
	{drawable_t::hash_value_t::HASH_VALUE_CURRENTINSCATTERRM1, "CURRENTINSCATTERRM1"},
	{drawable_t::hash_value_t::HASH_VALUE_DETAILSETTINGS3, "DETAILSETTINGS3"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR1MATERIALBTEX, "LYR1MATERIALBTEX"},
	{drawable_t::hash_value_t::HASH_VALUE_FURLENGTH0, "FURLENGTH0"},
	{drawable_t::hash_value_t::HASH_VALUE_PUDDLEMASKSCALE, "PUDDLEMASKSCALE"},
	{drawable_t::hash_value_t::HASH_VALUE_FURMASKUSINGBLUETINT0, "FURMASKUSINGBLUETINT0"},
	{drawable_t::hash_value_t::HASH_VALUE_TREEMMSPEED0, "TREEMMSPEED0"},
	{drawable_t::hash_value_t::HASH_VALUE_TINTPALETTESELECTOR, "TINTPALETTESELECTOR"},
	{drawable_t::hash_value_t::HASH_VALUE_SPECMAPINTMASK, "SPECMAPINTMASK"},
	{drawable_t::hash_value_t::HASH_VALUE_FURALPHACLIP47, "FURALPHACLIP47"},
	{drawable_t::hash_value_t::HASH_VALUE_MATERIALBTEXTURE, "MATERIALBTEXTURE"},
	{drawable_t::hash_value_t::HASH_VALUE_LYR1HEIGHTBIAS, "LYR1HEIGHTBIAS"}};
