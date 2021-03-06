#ifndef __IQM_H__
#define __IQM_H__

#define IQM_MAGIC "INTERQUAKEMODEL"
#define IQM_VERSION 2

struct iqmheader
{
	char magic[16];
	unsigned int version;
	unsigned int filesize;
	unsigned int flags;
	unsigned int num_text, ofs_text;
	unsigned int num_meshes, ofs_meshes;
	unsigned int num_vertexarrays, num_vertexes, ofs_vertexarrays;
	unsigned int num_triangles, ofs_triangles, ofs_adjacency;
	unsigned int num_joints, ofs_joints;
	unsigned int num_poses, ofs_poses;
	unsigned int num_anims, ofs_anims;
	unsigned int num_frames, num_framechannels, ofs_frames, ofs_bounds;
	unsigned int num_comment, ofs_comment;
	unsigned int num_materials, ofs_materials;
	unsigned int num_extensions, ofs_extensions;
};

struct iqmmesh
{
	unsigned int name;
	unsigned int material;
	int materialindex;
	unsigned int first_vertex, num_vertexes;
	unsigned int first_triangle, num_triangles;
};

enum
{
	IQM_POSITION = 0,
	IQM_TEXCOORD = 1,
	IQM_NORMAL = 2,
	IQM_TANGENT = 3,
	IQM_BLENDINDEXES = 4,
	IQM_BLENDWEIGHTS = 5,
	IQM_COLOR = 6,
	IQM_CUSTOM = 0x10
};

enum
{
	IQM_BYTE = 0,
	IQM_UBYTE = 1,
	IQM_SHORT = 2,
	IQM_USHORT = 3,
	IQM_INT = 4,
	IQM_UINT = 5,
	IQM_HALF = 6,
	IQM_FLOAT = 7,
	IQM_DOUBLE = 8
};

enum
{
	IQM_TEXTURE_TYPE_DIFFUSE	  = 0x00,
	IQM_TEXTURE_TYPE_SPECULAR	  = 0x01,
	IQM_TEXTURE_TYPE_AMBIENT	  = 0x02,
	IQM_TEXTURE_TYPE_EMISSIVE	  = 0x03,
	IQM_TEXTURE_TYPE_HEIGHT		  = 0x04,
	IQM_TEXTURE_TYPE_NORMALS	  = 0x05,
	IQM_TEXTURE_TYPE_SHININESS	  = 0x06,
	IQM_TEXTURE_TYPE_OPACITY	  = 0x07,
	IQM_TEXTURE_TYPE_DISPLACEMENT = 0x08,
	IQM_TEXTURE_TYPE_LIGHTMAP	  = 0x09,
	IQM_TEXTURE_TYPE_REFLECTION	  = 0x0A,
	IQM_TEXTURE_TYPE_COUNT	      = 0x0B,
	IQM_TEXTURE_TYPE_NONE		  = 0xFF,
};

struct iqmtriangle
{
	unsigned int vertex[3];
};

struct iqmadjacency
{
	unsigned int triangle[3];
};

struct iqmjointv1
{
	unsigned int name;
	int parent;
	float translate[3], rotate[3], scale[3];
};

struct iqmjoint
{
	unsigned int name;
	int parent;
	float translate[3], rotate[4], scale[3];
};

struct iqmposev1
{
	int parent;
	unsigned int mask;
	float channeloffset[9];
	float channelscale[9];
};

struct iqmpose
{
	int parent;
	unsigned int mask;
	float channeloffset[10];
	float channelscale[10];
};

struct iqmanim
{
	unsigned int name;
	unsigned int first_frame, num_frames;
	float framerate;
	unsigned int flags;
};

enum
{
	IQM_LOOP = 1 << 0
};

struct iqmvertexarray
{
	unsigned int type;
	unsigned int flags;
	unsigned int format;
	unsigned int size;
	unsigned int offset;
};

struct iqmbounds
{
	float bbmin[3], bbmax[3];
	float xyradius, radius;
};

struct iqmmaterial
{
	unsigned int name;
	unsigned int texture_diffuse;
	unsigned int texture_specular; 
	unsigned int texture_height;	
	unsigned int texture_opacity;	
};

struct iqmextension
{
	unsigned int name;
	unsigned int num_data, ofs_data;
	unsigned int ofs_extensions; // pointer to next extension
};

#endif

